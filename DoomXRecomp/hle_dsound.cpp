// ============================================================================
// HLE DirectSound Backend -- stubs for the Xbox DSound library functions.
//
// Every function in the DSOUND segment of the XBE is stubbed here so that
// calls are logged and the recompiled binary does not execute the original
// hardware-touching code.  Each stub logs its name and returns S_OK (0)
// where a return value is expected.
//
// Calling-convention: Xbox DSound functions are __stdcall (callee-cleanup,
// args on stack).  The argument size from the IDA function table is used
// for GuestStackCleanup.
// ============================================================================

#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include "kernel/heap.h"
#include <SDL.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <mutex>

// Suppress repeated log spam: set to true to print only once per function.
static bool g_dsound_quiet = true;

// ============================================================================
// HLE DSound state tracking
//
// Based on Cxbx-Reloaded DSBUFFER_S / XbHybridDSBuffer / EmuDirectSoundBuffer.
//
// The original Xbox DSBUFFER_S layout:
//   0x00: VMT ptr           (CUnknownTemplate)
//   0x04: ref_count
//   0x08: dsb_c.unknown_08
//   0x0C: dsb_c.p_CMcpxVoiceClient
//   0x10: dsb_c.p_CDSVoice
//   0x14: dsb_c.p_unknown_14
//   0x18: dsb_c.p_unknown_18
//   0x1C: dsb_i.p_CDSVoice         <- IDirectSoundBuffer* points HERE
//   0x20: dsb_i.p_CMcpxVoiceClient
//   0x24: dsb_i.p_unknown_24
//   0x28: dsb_i.p_unknown_28
//   0x2C: dsb_i.unknown_2C
//   0x30: dsb_i.unknown_30
// Total DSBUFFER_S = 0x34 bytes
//
// The IDirectSoundBuffer COM interface pointer the game uses points to
// offset 0x1C inside the full DSBUFFER_S.  To recover the base from the
// interface pointer:  base_ptr = pThis - 0x1C.
//
// For Lock/Unlock we maintain a host-side audio buffer cache per buffer.
// ============================================================================

static constexpr uint32_t DSBUFFER_S_SIZE            = 0x34;
static constexpr uint32_t DSBUFFER_I_OFFSET          = 0x1C; // IDirectSoundBuffer*
static constexpr uint32_t DSVOICE_SIZE               = 0x308; // CDirectSoundVoice
static constexpr uint32_t MCPX_VOICE_CLIENT_SIZE     = 0x300; // CMcpxVoiceClient

// X_DSBUFFERDESC (guest layout, matching Cxbx XbDSoundTypes.h)
static constexpr uint32_t XDSBUFFERDESC_dwSize           = 0x00;
static constexpr uint32_t XDSBUFFERDESC_dwFlags          = 0x04;
static constexpr uint32_t XDSBUFFERDESC_dwBufferBytes    = 0x08;
static constexpr uint32_t XDSBUFFERDESC_lpwfxFormat      = 0x0C;
static constexpr uint32_t XDSBUFFERDESC_mixBinsOutput    = 0x10;
static constexpr uint32_t XDSBUFFERDESC_dwInputMixBin    = 0x14;

// Guest WAVEFORMATEX layout
static constexpr uint32_t XWAVEFORMATEX_wFormatTag       = 0x00;
static constexpr uint32_t XWAVEFORMATEX_nChannels        = 0x02;
static constexpr uint32_t XWAVEFORMATEX_nSamplesPerSec   = 0x04;
static constexpr uint32_t XWAVEFORMATEX_nAvgBytesPerSec  = 0x08;
static constexpr uint32_t XWAVEFORMATEX_nBlockAlign      = 0x0C;
static constexpr uint32_t XWAVEFORMATEX_wBitsPerSample   = 0x0E;
static constexpr uint32_t XWAVEFORMATEX_cbSize           = 0x10;

// Host-side per-buffer tracking (not stored in guest memory).
struct HLE_DSBuffer {
    uint32_t guestObjAddr;      // Guest addr of DSBUFFER_S (full object)
    uint32_t guestIFaceAddr;    // Guest addr of DSBUFFER_I (= guestObjAddr + 0x1C)
    uint32_t bufferCacheAddr;   // Guest addr of audio buffer cache (X_BufferCache)
    uint32_t bufferCacheSize;   // Size in bytes of the audio buffer
    uint32_t dwFlags;           // DSBCAPS_* flags from X_DSBUFFERDESC
    uint16_t wFormatTag;
    uint16_t nChannels;
    uint32_t nSamplesPerSec;
    uint16_t wBitsPerSample;
    uint16_t nBlockAlign;
    uint32_t refCount;
    bool     isPlaying;
    uint32_t playFlags;     // X_DSBPLAY_LOOPING etc.
    uint32_t playCursor;    // Current play position in the buffer cache (bytes)
    float    volume;        // Linear volume [0.0 .. 1.0]
};

static std::vector<HLE_DSBuffer*> g_dsBuffers;

// Find HLE_DSBuffer by its IDirectSoundBuffer* (interface) guest address.
static HLE_DSBuffer* HLE_FindDSBuffer(uint32_t guestIFace)
{
    for (auto* b : g_dsBuffers) {
        if (b->guestIFaceAddr == guestIFace) return b;
    }
    // Also accept the full object address (some internal calls pass that).
    for (auto* b : g_dsBuffers) {
        if (b->guestObjAddr == guestIFace) return b;
    }
    return nullptr;
}

// ============================================================================
// SDL2 Audio Backend
//
// We open an SDL audio device at a fixed output rate (48 kHz, stereo, S16).
// An audio callback mixes all currently-playing HLE_DSBuffers into the
// output stream.  Mono sources are upmixed to stereo.  Basic nearest-
// neighbour sample-rate conversion is used when a buffer's native rate
// differs from the output rate.
// ============================================================================

static constexpr int  HLE_AUDIO_RATE     = 48000;
static constexpr int  HLE_AUDIO_CHANNELS = 2;
static constexpr int  HLE_AUDIO_SAMPLES  = 1024; // callback buffer size (frames)

static SDL_AudioDeviceID g_sdlAudioDev = 0;
static std::mutex        g_audioMutex;
static bool              g_audioInited = false;
static uint8_t*          g_audioBase   = nullptr; // cached guest base pointer

// SDL audio callback -- runs on a dedicated audio thread.
// Must hold g_audioMutex when touching g_dsBuffers / HLE_DSBuffer fields.
static void HLE_AudioCallback(void* /*userdata*/, Uint8* stream, int len)
{
    std::lock_guard<std::mutex> lk(g_audioMutex);

    int16_t* out     = reinterpret_cast<int16_t*>(stream);
    int      outFrames = len / (HLE_AUDIO_CHANNELS * sizeof(int16_t));

    // Zero the output (silence).
    memset(stream, 0, len);

    if (!g_audioBase) return;

    // First pass: count playing buffers
    int playingCount = 0;
    for (auto* buf : g_dsBuffers) {
        if (buf->isPlaying) playingCount++;
    }

    for (auto* buf : g_dsBuffers) {
        if (!buf->isPlaying) continue;
        if (!buf->bufferCacheAddr || buf->bufferCacheSize == 0) continue;
        if (buf->wBitsPerSample != 8 && buf->wBitsPerSample != 16) continue;

        uint8_t* cache = g_audioBase + buf->bufferCacheAddr;
        uint32_t cacheBytes = buf->bufferCacheSize;

        uint32_t srcRate    = buf->nSamplesPerSec ? buf->nSamplesPerSec : HLE_AUDIO_RATE;
        uint16_t srcCh      = buf->nChannels ? buf->nChannels : 1;
        uint16_t srcBps     = buf->wBitsPerSample;
        uint32_t srcAlign   = buf->nBlockAlign ? buf->nBlockAlign : (srcCh * (srcBps / 8));
        uint32_t srcFrames  = cacheBytes / srcAlign;
        if (srcFrames == 0) continue;

        // Volume scaling (linear).  Xbox uses millibels (0 = full, -10000 = silent).
        // For now: full volume (1.0).
        float volume = buf->volume;

        for (int i = 0; i < outFrames; i++) {
            // Map output frame index to source frame via sample-rate ratio.
            double srcPos = (double)i * srcRate / HLE_AUDIO_RATE;
            uint32_t srcIdx = (uint32_t)srcPos;
            uint32_t absIdx = buf->playCursor / srcAlign + srcIdx;

            // Handle end-of-buffer / looping.
            if (absIdx >= srcFrames) {
                if (buf->playFlags & 0x01) { // LOOPING
                    absIdx = absIdx % srcFrames;
                } else {
                    // Non-looping buffer has finished.
                    buf->isPlaying  = false;
                    buf->playCursor = 0;
                    break;
                }
            }

            // Read one source frame.
            int32_t left = 0, right = 0;
            uint32_t byteOff = absIdx * srcAlign;
            if (srcBps == 16) {
                int16_t* s = reinterpret_cast<int16_t*>(cache + byteOff);
                left = s[0];
                right = (srcCh >= 2) ? s[1] : s[0]; // mono -> duplicate
            } else { // 8-bit unsigned PCM
                uint8_t* s = cache + byteOff;
                left  = ((int32_t)s[0] - 128) << 8;
                right = (srcCh >= 2) ? (((int32_t)s[1] - 128) << 8) : left;
            }

            // Apply volume and mix (additive with clamp).
            int32_t mL = (int32_t)(left  * volume) + (int32_t)out[i * 2 + 0];
            int32_t mR = (int32_t)(right * volume) + (int32_t)out[i * 2 + 1];
            if (mL >  32767) mL =  32767; if (mL < -32768) mL = -32768;
            if (mR >  32767) mR =  32767; if (mR < -32768) mR = -32768;
            out[i * 2 + 0] = (int16_t)mL;
            out[i * 2 + 1] = (int16_t)mR;
        }

        // Advance the play cursor by the number of source bytes consumed.
        if (buf->isPlaying) {
            uint32_t srcFramesConsumed = (uint32_t)((double)outFrames * srcRate / HLE_AUDIO_RATE);
            uint32_t bytesConsumed = srcFramesConsumed * srcAlign;
            buf->playCursor += bytesConsumed;
            if (buf->playCursor >= cacheBytes) {
                if (buf->playFlags & 0x01) { // LOOPING
                    buf->playCursor %= cacheBytes;
                } else {
                    buf->isPlaying  = false;
                    buf->playCursor = 0;
                }
            }
        }
    }
}

// Lazy-init SDL audio.  Call with g_audioMutex NOT held.
static void HLE_EnsureAudioInit(uint8_t* base)
{
    if (g_audioInited) return;

    g_audioBase = base;

    if (SDL_WasInit(SDL_INIT_AUDIO) == 0) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            fprintf(stderr, "[HLE-DS] SDL_InitSubSystem(AUDIO) failed: %s\n", SDL_GetError());
            return;
        }
    }

    SDL_AudioSpec desired{}, obtained{};
    desired.freq     = HLE_AUDIO_RATE;
    desired.format   = AUDIO_S16SYS;
    desired.channels = HLE_AUDIO_CHANNELS;
    desired.samples  = HLE_AUDIO_SAMPLES;
    desired.callback = HLE_AudioCallback;
    desired.userdata = nullptr;

    g_sdlAudioDev = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
    if (!g_sdlAudioDev) {
        fprintf(stderr, "[HLE-DS] SDL_OpenAudioDevice failed: %s\n", SDL_GetError());
        return;
    }

    fprintf(stderr, "[HLE-DS] SDL audio opened: %d Hz, %d ch, %d samples\n",
            obtained.freq, obtained.channels, obtained.samples);

    // Unpause -- SDL devices start paused by default.
    SDL_PauseAudioDevice(g_sdlAudioDev, 0);
    g_audioInited = true;
}

// ============================================================================
// Shared buffer creation logic.
// Called by DirectSoundCreateBuffer, IDirectSound_CreateSoundBuffer, and
// CDirectSound_CreateSoundBuffer.  Returns an HRESULT (0 = DS_OK).
// ============================================================================
static uint32_t HLE_CreateSoundBufferImpl(uint8_t* base, uint32_t pDesc, uint32_t ppBuffer)
{
    // Read the buffer descriptor from guest memory.
    uint32_t dwFlags       = 0;
    uint32_t dwBufferBytes = 0;
    uint32_t lpwfxFormat   = 0;
    if (pDesc) {
        dwFlags       = X86_MEM_READ_u32(base, pDesc + XDSBUFFERDESC_dwFlags);
        dwBufferBytes = X86_MEM_READ_u32(base, pDesc + XDSBUFFERDESC_dwBufferBytes);
        lpwfxFormat   = X86_MEM_READ_u32(base, pDesc + XDSBUFFERDESC_lpwfxFormat);
    }

    // Read WAVEFORMATEX if present.
    uint16_t wFormatTag     = 1; // PCM default
    uint16_t nChannels      = 2;
    uint32_t nSamplesPerSec = 48000;
    uint16_t wBitsPerSample = 16;
    uint16_t nBlockAlign    = 4;
    if (lpwfxFormat) {
        wFormatTag     = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_wFormatTag);
        nChannels      = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_nChannels);
        nSamplesPerSec = X86_MEM_READ_u32(base, lpwfxFormat + XWAVEFORMATEX_nSamplesPerSec);
        nBlockAlign    = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_nBlockAlign);
        wBitsPerSample = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_wBitsPerSample);
    }

    fprintf(stderr, "[HLE-DS] HLE_CreateSoundBufferImpl(pDesc=0x%08X, ppBuffer=0x%08X)\n"
                    "         flags=0x%X, bytes=%u, fmt=%u, ch=%u, rate=%u, bits=%u\n",
            pDesc, ppBuffer, dwFlags, dwBufferBytes,
            wFormatTag, nChannels, nSamplesPerSec, wBitsPerSample);

    // If no buffer size given, use a sensible default (1 second of audio).
    if (dwBufferBytes == 0) {
        dwBufferBytes = nSamplesPerSec * nChannels * (wBitsPerSample / 8);
        if (dwBufferBytes == 0) dwBufferBytes = 48000 * 2 * 2; // fallback
    }

    // ---------- Allocate the guest DSBUFFER_S structure ----------
    uint32_t guestObj = g_heap.AllocGuestAligned(DSBUFFER_S_SIZE, 16);
    if (!guestObj) {
        fprintf(stderr, "[HLE-DS]   FAILED: out of guest memory for DSBUFFER_S\n");
        if (ppBuffer) X86_MEM_WRITE_u32(base, ppBuffer, 0);
        return 0x8007000E; // DSERR_OUTOFMEMORY
    }
    memset(base + guestObj, 0, DSBUFFER_S_SIZE);

    // Allocate CMcpxVoiceClient (0x300 bytes).
    uint32_t guestMcpx = g_heap.AllocGuestAligned(MCPX_VOICE_CLIENT_SIZE, 16);
    if (guestMcpx) memset(base + guestMcpx, 0, MCPX_VOICE_CLIENT_SIZE);

    // Allocate CDirectSoundVoice (0x308 bytes).
    uint32_t guestVoice = g_heap.AllocGuestAligned(DSVOICE_SIZE, 16);
    if (guestVoice) {
        memset(base + guestVoice, 0, DSVOICE_SIZE);
        X86_MEM_WRITE_u32(base, guestVoice + 0x04, 1); // ref_count = 1
    }

    // Allocate the audio buffer cache (X_BufferCache) in guest memory.
    uint32_t guestBufCache = g_heap.AllocGuestAligned(dwBufferBytes, 16);
    if (guestBufCache) memset(base + guestBufCache, 0, dwBufferBytes);

    // --- Fill the DSBUFFER_S structure (mimics Xbox internal layout) ---
    X86_MEM_WRITE_u32(base, guestObj + 0x04, 1); // ref_count = 1
    X86_MEM_WRITE_u32(base, guestObj + 0x0C, guestMcpx);
    X86_MEM_WRITE_u32(base, guestObj + 0x10, guestVoice);
    X86_MEM_WRITE_u32(base, guestObj + 0x14, guestObj + 0x18);
    X86_MEM_WRITE_u32(base, guestObj + 0x18, guestObj + 0x14);
    X86_MEM_WRITE_u32(base, guestObj + 0x1C, guestVoice);
    X86_MEM_WRITE_u32(base, guestObj + 0x20, guestMcpx);

    uint32_t guestIFace = guestObj + DSBUFFER_I_OFFSET;

    if (guestVoice) {
        X86_MEM_WRITE_u16(base, guestVoice + 0x08 + 0x04, wFormatTag);
        X86_MEM_WRITE_u32(base, guestVoice + 0x08 + 0x08, nSamplesPerSec);
    }

    HLE_EnsureAudioInit(base);

    // --- Create host-side tracking ---
    HLE_DSBuffer* hleBuf = new HLE_DSBuffer{};
    hleBuf->guestObjAddr    = guestObj;
    hleBuf->guestIFaceAddr  = guestIFace;
    hleBuf->bufferCacheAddr = guestBufCache;
    hleBuf->bufferCacheSize = dwBufferBytes;
    hleBuf->dwFlags         = dwFlags;
    hleBuf->wFormatTag      = wFormatTag;
    hleBuf->nChannels       = nChannels;
    hleBuf->nSamplesPerSec  = nSamplesPerSec;
    hleBuf->wBitsPerSample  = wBitsPerSample;
    hleBuf->nBlockAlign     = nBlockAlign;
    hleBuf->refCount        = 1;
    hleBuf->volume          = 1.0f;
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        g_dsBuffers.push_back(hleBuf);
    }

    if (ppBuffer)
        X86_MEM_WRITE_u32(base, ppBuffer, guestIFace);

    //fprintf(stderr, "[HLE-DS]   -> obj=0x%08X iface=0x%08X bufCache=0x%08X (%u bytes)\n",
    //        guestObj, guestIFace, guestBufCache, dwBufferBytes);

    return 0; // DS_OK
}

// ============================================================================
// Named DSound functions
// ============================================================================

// DSound_CRefCount_AddRef  (0xC620C) -- args=4
void DSound_CRefCount_AddRef(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] DSound_CRefCount_AddRef()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// DSound_CRefCount_Release  (0xC622A) -- args=4
void DSound_CRefCount_Release(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] DSound_CRefCount_Release()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// DirectSoundEnterCriticalSection  (0xC6395) -- args=0
void DirectSoundEnterCriticalSection(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] DirectSoundEnterCriticalSection()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// IDirectSound_Release  (0xC63B3) -- args=4
void IDirectSound_Release(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSound_Release()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// IDirectSoundBuffer_Unlock  (0xC63C9) -- args=20
//
// Based on Cxbx-Reloaded's EMUPATCH(IDirectSoundBuffer_Unlock).
// On the original Xbox, Unlock is a no-op that just returns DS_OK.
// The Xbox DirectSound doesn't require locking buffers -- the Lock/Unlock
// API only exists for compatibility with the PC DirectSound API.
void IDirectSoundBuffer_Unlock(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t pvAudioPtr1 = GuestArg32(ctx, base, 1);
    uint32_t dwAudioLen1 = GuestArg32(ctx, base, 2);
    uint32_t pvAudioPtr2 = GuestArg32(ctx, base, 3);
    uint32_t dwAudioLen2 = GuestArg32(ctx, base, 4);

    { static int _unlockLog = 0;
      // Always check for non-zero data in the music buffer (44100Hz, large)
      bool hasData = false;
      if (pvAudioPtr1 && dwAudioLen1 > 0) {
          uint8_t* p = base + pvAudioPtr1;
          for (uint32_t k = 0; k < std::min(dwAudioLen1, (uint32_t)512); k++) {
              if (p[k] != 0) { hasData = true; break; }
          }
      }
      // Log first 20 always, PLUS any unlock where music buffer has data
      if (_unlockLog < 20 || hasData) {
        //fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Unlock(this=0x%08X ptr1=0x%08X len1=%u ptr2=0x%08X len2=%u hasData=%d)\n",
        //        pThis, pvAudioPtr1, dwAudioLen1, pvAudioPtr2, dwAudioLen2, hasData ? 1 : 0);
        _unlockLog++;
    }}

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSoundBuffer_Release  (0xC63CE) -- args=4
void IDirectSoundBuffer_Release(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Release()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// XAudioCalculatePitch  (0xC63E4) -- args=4
void XAudioCalculatePitch(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] XAudioCalculatePitch()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSound_GetOutputLevels  (0xC64A7) -- args=12
void CDirectSound_GetOutputLevels(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSound_GetOutputLevels()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_DoWork  (0xC64ED) -- args=4
void CDirectSound_DoWork(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSound_DoWork()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundVoice_SetVolume  (0xC65D9) -- args=8
void CDirectSoundVoice_SetVolume(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetVolume()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_CommitDeferredSettings  (0xC65F5) -- args=4
void CDirectSoundVoice_CommitDeferredSettings(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundVoice_CommitDeferredSettings()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundBuffer_Play  (0xC679F) -- args=16
void CDirectSoundBuffer_Play(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_Play()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// CDirectSoundBuffer_Stop  (0xC67F0) -- args=4
void CDirectSoundBuffer_Stop(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_Stop()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundBuffer_GetStatus  (0xC683F) -- args=8
void CDirectSoundBuffer_GetStatus(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_GetStatus()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetLoopRegion  (0xC6890) -- args=12
void CDirectSoundBuffer_SetLoopRegion(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetLoopRegion()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundBuffer_GetCurrentPosition  (0xC6915) -- args=12
void CDirectSoundBuffer_GetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_GetCurrentPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundBuffer_Lock  (0xC696A) -- args=32
void CDirectSoundBuffer_Lock(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_Lock()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// CDirectSoundBuffer_SetCurrentPosition  (0xC6A4C) -- args=8
void CDirectSoundBuffer_SetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetCurrentPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSound3DCalculator_GetVoiceData  (0xC6A9D) -- args=20
void CDirectSound3DCalculator_GetVoiceData(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSound3DCalculator_GetVoiceData()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSoundBuffer_SetVolume  (0xC6D93) -- args=8
void CDirectSoundBuffer_SetVolume(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetVolume()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSound_GetOutputLevels  (0xC6DE1) -- args=12
void IDirectSound_GetOutputLevels(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSound_GetOutputLevels()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSoundBuffer_SetVolume  (0xC6E01) -- args=8
// Xbox volume is in millibels: 0 = full volume, -10000 = silence.
void IDirectSoundBuffer_SetVolume(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    int32_t  lVolume = (int32_t)GuestArg32(ctx, base, 1); // millibels

    // Convert millibels to linear: 10^(mB / 2000)
    float linear = 1.0f;
    if (lVolume <= -10000) {
        linear = 0.0f;
    } else if (lVolume < 0) {
        linear = powf(10.0f, (float)lVolume / 2000.0f);
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetVolume(this=0x%08X, vol=%d mB -> %.4f)\n",
                pThis, lVolume, linear);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) hleBuf->volume = linear;
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_Play  (0xC6E1D) -- args=16
//
// Based on Cxbx-Reloaded's EMUPATCH(IDirectSoundBuffer_Play).
// Signature: HRESULT IDirectSoundBuffer_Play(pThis, dwReserved1, dwReserved2, dwFlags)
// Flags: X_DSBPLAY_LOOPING (0x01), X_DSBPLAY_FROMSTART (0x02), X_DSBPLAY_SYNCHPLAYBACK (0x20)
//
// Since we don't output audio, we just track the playing/looping state so that
// GetStatus and Stop behave correctly.
void IDirectSoundBuffer_Play(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0);
    uint32_t dwReserved1 = GuestArg32(ctx, base, 1);
    uint32_t dwReserved2 = GuestArg32(ctx, base, 2);
    uint32_t dwFlags     = GuestArg32(ctx, base, 3);

    // fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Play(this=0x%08X, flags=0x%X)%s%s\n",
    //         pThis, dwFlags,
    //         (dwFlags & 0x01) ? " LOOPING" : "",
    //         (dwFlags & 0x02) ? " FROMSTART" : "");

    HLE_EnsureAudioInit(base);

    // Find host-side tracking and record play state.
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->isPlaying = true;
            hleBuf->playFlags = dwFlags & ~0x02u; // strip FROMSTART, keep LOOPING
            if (dwFlags & 0x02) { // FROMSTART — reset play cursor
                hleBuf->playCursor = 0;
            }
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 16);
}

// IDirectSoundBuffer_Stop  (0xC6E41) -- args=4
void IDirectSoundBuffer_Stop(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Stop(this=0x%08X)\n", pThis);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->isPlaying = false;
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 4);
}

// IDirectSoundBuffer_SetLoopRegion  (0xC6E59) -- args=12
void IDirectSoundBuffer_SetLoopRegion(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetLoopRegion()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSoundBuffer_GetStatus  (0xC6E79) -- args=8
// Returns DSBSTATUS flags: PLAYING (0x01), LOOPING (0x04).
void IDirectSoundBuffer_GetStatus(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t pdwFlags = GuestArg32(ctx, base, 1);

    uint32_t status = 0;
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf && hleBuf->isPlaying) {
            status |= 0x01; // DSBSTATUS_PLAYING
            if (hleBuf->playFlags & 0x01) // looping
                status |= 0x04; // DSBSTATUS_LOOPING
        }
    }

    if (pdwFlags) X86_MEM_WRITE_u32(base, pdwFlags, status);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_GetCurrentPosition  (0xC6E95) -- args=12
// Returns play and write cursor positions.
void IDirectSoundBuffer_GetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0);
    uint32_t pdwPlayPos  = GuestArg32(ctx, base, 1);
    uint32_t pdwWritePos = GuestArg32(ctx, base, 2);

    uint32_t playPos = 0;
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) playPos = hleBuf->playCursor;
    }

    // Write position is typically a small lead ahead of play.
    if (pdwPlayPos)  X86_MEM_WRITE_u32(base, pdwPlayPos, playPos);
    if (pdwWritePos) X86_MEM_WRITE_u32(base, pdwWritePos, playPos);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSoundBuffer_SetCurrentPosition  (0xC6EB5) -- args=8
void IDirectSoundBuffer_SetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis  = GuestArg32(ctx, base, 0);
    uint32_t dwPos  = GuestArg32(ctx, base, 1);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetCurrentPosition(this=0x%08X, pos=%u)\n",
                pThis, dwPos);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) hleBuf->playCursor = dwPos;
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_Lock  (0xC6ED1) -- args=32
//
// Based on Cxbx-Reloaded's EMUPATCH(IDirectSoundBuffer_Lock).
// On Xbox, Lock doesn't actually lock anything -- it simply returns pointers
// into the buffer's audio cache so the game can write PCM data directly.
// If the requested region wraps around the buffer end, two segments are
// returned (ppvAudioPtr1 up to the end, ppvAudioPtr2 from the start).
void IDirectSoundBuffer_Lock(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0); // IDirectSoundBuffer*
    uint32_t dwOffset    = GuestArg32(ctx, base, 1);
    uint32_t dwBytes     = GuestArg32(ctx, base, 2);
    uint32_t ppAudioPtr1 = GuestArg32(ctx, base, 3);
    uint32_t pAudioLen1  = GuestArg32(ctx, base, 4);
    uint32_t ppAudioPtr2 = GuestArg32(ctx, base, 5);
    uint32_t pAudioLen2  = GuestArg32(ctx, base, 6);
    uint32_t dwFlags     = GuestArg32(ctx, base, 7);

    //fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Lock(this=0x%08X, off=%u, bytes=%u, flags=0x%X)\n",
    //        pThis, dwOffset, dwBytes, dwFlags);
    { static int _lockLog = 0; if (_lockLog < 20) {
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Lock(this=0x%08X, off=%u, bytes=%u, flags=0x%X)\n",
                pThis, dwOffset, dwBytes, dwFlags);
        _lockLog++;
    }}

    // Find our host-side tracking for this buffer.
    HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
    if (!hleBuf) {
        // Fallback: look up by converting IFace -> object base.
        // IDirectSoundBuffer_Lock passes the IFace directly; some internal
        // CDirectSoundBuffer_Lock variants pass object + offset.
        if (pThis >= DSBUFFER_I_OFFSET)
            hleBuf = HLE_FindDSBuffer(pThis - DSBUFFER_I_OFFSET);
    }

    if (hleBuf && hleBuf->bufferCacheAddr && hleBuf->bufferCacheSize > 0) {
        uint32_t cacheAddr = hleBuf->bufferCacheAddr;
        uint32_t cacheSize = hleBuf->bufferCacheSize;

        // Clamp offset to buffer size.
        if (dwOffset >= cacheSize) dwOffset = dwOffset % cacheSize;

        // DSBLOCK_ENTIREBUFFER (flag 0x2): lock the whole buffer.
        if (dwFlags & 0x00000002) {
            dwBytes = cacheSize;
        }
        if (dwBytes == 0) dwBytes = cacheSize;

        if (dwOffset + dwBytes <= cacheSize) {
            // Single contiguous region.
            if (ppAudioPtr1) X86_MEM_WRITE_u32(base, ppAudioPtr1, cacheAddr + dwOffset);
            if (pAudioLen1)  X86_MEM_WRITE_u32(base, pAudioLen1, dwBytes);
            if (ppAudioPtr2) X86_MEM_WRITE_u32(base, ppAudioPtr2, 0);
            if (pAudioLen2)  X86_MEM_WRITE_u32(base, pAudioLen2, 0);
        } else {
            // Wrapping: first region goes to end, second region from start.
            uint32_t bytes1 = cacheSize - dwOffset;
            uint32_t bytes2 = dwBytes - bytes1;
            if (ppAudioPtr1) X86_MEM_WRITE_u32(base, ppAudioPtr1, cacheAddr + dwOffset);
            if (pAudioLen1)  X86_MEM_WRITE_u32(base, pAudioLen1, bytes1);
            if (ppAudioPtr2) X86_MEM_WRITE_u32(base, ppAudioPtr2, cacheAddr);
            if (pAudioLen2)  X86_MEM_WRITE_u32(base, pAudioLen2, bytes2);
        }

        { static int _lockDetail = 0; if (_lockDetail < 20) {
            fprintf(stderr, "[HLE-DS]   Lock -> cacheAddr=0x%08X, off=%u, bytes=%u, ptr1=0x%08X\n",
                    cacheAddr, dwOffset, dwBytes, cacheAddr + dwOffset);
            _lockDetail++;
        }}
    } else {
        // No tracked buffer: use a static scratch area so the game doesn't crash.
        // Using a static buffer avoids heap allocation which may fail with OOM,
        // which would otherwise cause the game to loop calling Lock indefinitely.
        fprintf(stderr, "[HLE-DS]   WARNING: buffer 0x%08X not tracked, using static scratch\n", pThis);
        static uint32_t s_scratchGuest = 0;
        static constexpr uint32_t kScratchSize = 65536; // 64 KB static scratch
        if (s_scratchGuest == 0) {
            s_scratchGuest = g_heap.AllocGuestAligned(kScratchSize, 16);
            if (s_scratchGuest) memset(base + s_scratchGuest, 0, kScratchSize);
        }
        uint32_t clampedBytes = (dwBytes == 0) ? kScratchSize : std::min(dwBytes, kScratchSize);
        if (ppAudioPtr1) X86_MEM_WRITE_u32(base, ppAudioPtr1, s_scratchGuest);
        if (pAudioLen1)  X86_MEM_WRITE_u32(base, pAudioLen1, clampedBytes);
        if (ppAudioPtr2) X86_MEM_WRITE_u32(base, ppAudioPtr2, 0);
        if (pAudioLen2)  X86_MEM_WRITE_u32(base, pAudioLen2, 0);
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 32);
}

// CDirectSoundVoice_SetPosition  (0xC7196) -- args=20
void CDirectSoundVoice_SetPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSoundVoice_SetVelocity  (0xC71E8) -- args=20
void CDirectSoundVoice_SetVelocity(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetVelocity()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSoundBuffer_SetPlayRegion  (0xC7291) -- args=12
void CDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetPlayRegion()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundBuffer_SetPosition  (0xC7311) -- args=20
void CDirectSoundBuffer_SetPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSoundBuffer_SetVelocity  (0xC7378) -- args=20
void CDirectSoundBuffer_SetVelocity(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetVelocity()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSoundBuffer_SetPosition  (0xC73DF) -- args=20
void IDirectSoundBuffer_SetPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSoundBuffer_SetVelocity  (0xC7414) -- args=20
void IDirectSoundBuffer_SetVelocity(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetVelocity()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSoundBuffer_SetPlayRegion  (0xC7449) -- args=12
void IDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetPlayRegion()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundVoice_SetFormat  (0xC7605) -- args=8
void CDirectSoundVoice_SetFormat(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetFormat()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBufferSettings_SetBufferData  (0xC7649) -- args=8
void CDirectSoundBufferSettings_SetBufferData(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBufferSettings_SetBufferData()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetBufferData  (0xC76D5) -- args=12
// Xbox signature: HRESULT CDirectSoundBuffer_SetBufferData(pThis, pvBufferData, dwBufferBytes)
void CDirectSoundBuffer_SetBufferData(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t pvBufferData = GuestArg32(ctx, base, 1);
    uint32_t dwBufferBytes= GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetBufferData(this=0x%08X, data=0x%08X, bytes=%u)\n",
            pThis, pvBufferData, dwBufferBytes);

    HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
    if (!hleBuf && pThis >= DSBUFFER_I_OFFSET)
        hleBuf = HLE_FindDSBuffer(pThis - DSBUFFER_I_OFFSET);

    if (hleBuf) {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        hleBuf->bufferCacheAddr = pvBufferData;
        hleBuf->bufferCacheSize = dwBufferBytes;
        hleBuf->playCursor = 0;
    }

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound3DCalculator_Calculate3D  (0xC7783) -- args=8
void CDirectSound3DCalculator_Calculate3D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSound3DCalculator_Calculate3D()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetFormat  (0xC79C3) -- args=8
void CDirectSoundBuffer_SetFormat(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetFormat()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetFormat  (0xC7A11) -- args=8
void IDirectSoundBuffer_SetFormat(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetFormat()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetBufferData  (0xC7A2D) -- args=12
// Updates the buffer's audio data pointer and size.
// Xbox signature: HRESULT IDirectSoundBuffer_SetBufferData(pThis, pvBufferData, dwBufferBytes)
void IDirectSoundBuffer_SetBufferData(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t pvBufferData = GuestArg32(ctx, base, 1);
    uint32_t dwBufferBytes= GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetBufferData(this=0x%08X, data=0x%08X, bytes=%u)\n",
            pThis, pvBufferData, dwBufferBytes);

    HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
    if (!hleBuf && pThis >= DSBUFFER_I_OFFSET)
        hleBuf = HLE_FindDSBuffer(pThis - DSBUFFER_I_OFFSET);

    if (hleBuf) {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        hleBuf->bufferCacheAddr = pvBufferData;
        hleBuf->bufferCacheSize = dwBufferBytes;
        hleBuf->playCursor = 0;
    }

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_CreateSoundBuffer  (0xC7D86) -- args=16
// Signature: HRESULT CDirectSound_CreateSoundBuffer(pThis, pdsbd, ppBuffer, unknown)
// Forwards to the shared buffer creation helper (pThis and unknown are ignored).
void CDirectSound_CreateSoundBuffer(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t pdsbd    = GuestArg32(ctx, base, 1);
    uint32_t ppBuffer = GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] CDirectSound_CreateSoundBuffer(pThis=0x%08X) -> forwarding\n", pThis);

    uint32_t hr = HLE_CreateSoundBufferImpl(base, pdsbd, ppBuffer);
    GuestReturn32(ctx, hr);
    GuestStackCleanup(ctx, 16);
}

// IDirectSound_CreateSoundBuffer  (0xC7E3D) -- args=16
// Signature: HRESULT IDirectSound_CreateSoundBuffer(pThis, pdsbd, ppBuffer, unknown)
// Forwards to the shared buffer creation helper.
void IDirectSound_CreateSoundBuffer(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t pdsbd    = GuestArg32(ctx, base, 1);
    uint32_t ppBuffer = GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] IDirectSound_CreateSoundBuffer(pThis=0x%08X) -> forwarding\n", pThis);

    uint32_t hr = HLE_CreateSoundBufferImpl(base, pdsbd, ppBuffer);
    GuestReturn32(ctx, hr);
    GuestStackCleanup(ctx, 16);
}

// DirectSoundCreate  (0xC8007) -- args=12
void DirectSoundCreate(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] DirectSoundCreate()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// DirectSoundCreateBuffer  (0xC804E) -- args=8
//
// Based on Cxbx-Reloaded's EMUPATCH(DirectSoundCreateBuffer).
// Allocates a guest DSBUFFER_S object with CDirectSoundVoice and
// CMcpxVoiceClient sub-objects, plus an audio buffer cache.
// Returns the IDirectSoundBuffer* (points to DSBUFFER_S + 0x1C).
void DirectSoundCreateBuffer(X86Context& ctx, uint8_t* base)
{
    uint32_t pDesc    = GuestArg32(ctx, base, 0); // X_DSBUFFERDESC*
    uint32_t ppBuffer = GuestArg32(ctx, base, 1); // IDirectSoundBuffer**

    uint32_t hr = HLE_CreateSoundBufferImpl(base, pDesc, ppBuffer);
    GuestReturn32(ctx, hr);
    GuestStackCleanup(ctx, 8);
}

// DSound_CMemoryManager_PoolAlloc  (0xC80A5) -- args=12
void DSound_CMemoryManager_PoolAlloc(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] DSound_CMemoryManager_PoolAlloc()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CMcpxAPU_ServiceDeferredCommandsLow  (0xC8928) -- args=0
void CMcpxAPU_ServiceDeferredCommandsLow(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxAPU_ServiceDeferredCommandsLow()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxAPU_SetMixBinHeadroom  (0xC89F1) -- args=4
void CMcpxAPU_SetMixBinHeadroom(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxAPU_SetMixBinHeadroom()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxVoiceClient_SetFilter  (0xCA188) -- args=4
void CMcpxVoiceClient_SetFilter(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxVoiceClient_SetFilter()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxVoiceClient_SetMixBins  (0xCA50C) -- args=0
void CMcpxVoiceClient_SetMixBins(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxVoiceClient_SetMixBins()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxVoiceClient_SetVolume  (0xCA5CD) -- args=0
void CMcpxVoiceClient_SetVolume(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxVoiceClient_SetVolume()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxVoiceClient_SetPitch  (0xCA665) -- args=0
void CMcpxVoiceClient_SetPitch(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxVoiceClient_SetPitch()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxVoiceClient_Commit3dSettings  (0xCA91B) -- args=0
void CMcpxVoiceClient_Commit3dSettings(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxVoiceClient_Commit3dSettings()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxBuffer_Pause  (0xCB03B) -- args=4
void CMcpxBuffer_Pause(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_Pause()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxBuffer_GetStatus  (0xCB0AE) -- args=4
void CMcpxBuffer_GetStatus(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_GetStatus()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxBuffer_GetCurrentPosition  (0xCB0F0) -- args=8
void CMcpxBuffer_GetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_GetCurrentPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CMcpxBuffer_Play  (0xCB4FA) -- args=4
void CMcpxBuffer_Play(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_Play()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxBuffer_Stop  (0xCB613) -- args=4
void CMcpxBuffer_Stop(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_Stop()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxBuffer_SetCurrentPosition  (0xCB6A3) -- args=4
void CMcpxBuffer_SetCurrentPosition(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_SetCurrentPosition()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxBuffer_SetBufferData  (0xCB7BD) -- args=0
void CMcpxBuffer_SetBufferData(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] CMcpxBuffer_SetBufferData()\n");
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Unnamed DSound internal functions (sub_XXXXX)
// ============================================================================

// sub_C6160  (0xC6160) -- args=4
void sub_C6160(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6160()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C617F  (0xC617F) -- args=4
void sub_C617F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C617F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6190  (0xC6190) -- args=0
void sub_C6190(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6190()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C61B2  (0xC61B2) -- args=0
void sub_C61B2(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C61B2()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C61C9  (0xC61C9) -- args=0
void sub_C61C9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C61C9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C61EE  (0xC61EE) -- args=0
void sub_C61EE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C61EE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C6219  (0xC6219) -- args=4
void sub_C6219(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6219()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C624B  (0xC624B) -- args=4
void sub_C624B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C624B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6294  (0xC6294) -- args=0
void sub_C6294(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6294()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C6298  (0xC6298) -- args=32
void sub_C6298(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6298()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 32);
}

// sub_C62C1  (0xC62C1) -- args=32
void sub_C62C1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C62C1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 32);
}

// sub_C62F8  (0xC62F8) -- args=20
void sub_C62F8(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C62F8()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 20);
}

// sub_C6318  (0xC6318) -- args=28
void sub_C6318(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6318()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 28);
}

// sub_C634C  (0xC634C) -- args=16
void sub_C634C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C634C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C636E  (0xC636E) -- args=16
void sub_C636E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C636E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C642E  (0xC642E) -- args=4
void sub_C642E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C642E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6450  (0xC6450) -- args=0
void sub_C6450(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6450()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C646D  (0xC646D) -- args=0
void sub_C646D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C646D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C651E  (0xC651E) -- args=4
void sub_C651E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C651E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C658C  (0xC658C) -- args=0
void sub_C658C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C658C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C6606  (0xC6606) -- args=8
void sub_C6606(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6606()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C66DB  (0xC66DB) -- args=0
void sub_C66DB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C66DB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C670E  (0xC670E) -- args=4
void sub_C670E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C670E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6755  (0xC6755) -- args=4
void sub_C6755(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6755()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6D7E  (0xC6D7E) -- args=4
void sub_C6D7E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6D7E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6F01  (0xC6F01) -- args=4
void sub_C6F01(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6F01()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6F1C  (0xC6F1C) -- args=4
void sub_C6F1C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6F1C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C6FE7  (0xC6FE7) -- args=4
void sub_C6FE7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C6FE7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C70BA  (0xC70BA) -- args=4
void sub_C70BA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C70BA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C70E4  (0xC70E4) -- args=4
void sub_C70E4(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C70E4()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C70FF  (0xC70FF) -- args=12
void sub_C70FF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C70FF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C723A  (0xC723A) -- args=8
void sub_C723A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C723A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C725E  (0xC725E) -- args=4
void sub_C725E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C725E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7276  (0xC7276) -- args=4
void sub_C7276(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7276()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7469  (0xC7469) -- args=4
void sub_C7469(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7469()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7532  (0xC7532) -- args=0
void sub_C7532(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7532()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C757F  (0xC757F) -- args=8
void sub_C757F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C757F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C7A4D  (0xC7A4D) -- args=0
void sub_C7A4D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7A4D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C7ADC  (0xC7ADC) -- args=4
void sub_C7ADC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7ADC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7AF8  (0xC7AF8) -- args=4
void sub_C7AF8(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7AF8()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7B13  (0xC7B13) -- args=12
void sub_C7B13(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7B13()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C7C15  (0xC7C15) -- args=0
void sub_C7C15(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7C15()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C7C3A  (0xC7C3A) -- args=4
void sub_C7C3A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7C3A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7C9F  (0xC7C9F) -- args=8
void sub_C7C9F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7C9F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C7E22  (0xC7E22) -- args=4
void sub_C7E22(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7E22()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7E61  (0xC7E61) -- args=4
void sub_C7E61(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7E61()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C7F9A  (0xC7F9A) -- args=4
void sub_C7F9A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C7F9A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C80EC  (0xC80EC) -- args=4
void sub_C80EC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C80EC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8104  (0xC8104) -- args=16
void sub_C8104(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8104()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C8153  (0xC8153) -- args=4
void sub_C8153(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8153()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C816B  (0xC816B) -- args=12
void sub_C816B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C816B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C81D3  (0xC81D3) -- args=4
void sub_C81D3(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C81D3()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8207  (0xC8207) -- args=8
void sub_C8207(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8207()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C8230  (0xC8230) -- args=8
void sub_C8230(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8230()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C8257  (0xC8257) -- args=8
void sub_C8257(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8257()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C82A0  (0xC82A0) -- args=8
void sub_C82A0(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C82A0()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C82E3  (0xC82E3) -- args=0
// DSP image pointer init: dword_CDF78 = &dword_CD8A0
// Sets the global MCPX AC97 DSP image pointer. We write the address of the
// (empty) DSP image slot so downstream code sees a non-null pointer.
void sub_C82E3(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE-DS] sub_C82E3() -- CMcpxAPU AC97 DSP image init\n");
    X86_MEM_WRITE_u32(base, 0xCDF78, 0xCD8A0);
    GuestStackCleanup(ctx, 0);
}

// sub_C82EE  (0xC82EE) -- args=0
// DSP image pointer init: dword_CDF74 = &dword_CD8A4
// Sets the global MCPX GP DSP image pointer.
void sub_C82EE(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE-DS] sub_C82EE() -- CMcpxAPU GP DSP image init\n");
    X86_MEM_WRITE_u32(base, 0xCDF74, 0xCD8A4);
    GuestStackCleanup(ctx, 0);
}

// sub_C82F9  (0xC82F9) -- args=12
void sub_C82F9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C82F9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C8336  (0xC8336) -- args=0
void sub_C8336(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8336()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8355  (0xC8355) -- args=0
void sub_C8355(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8355()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C83CA  (0xC83CA) -- args=8
void sub_C83CA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C83CA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C83DE  (0xC83DE) -- args=8
void sub_C83DE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C83DE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C83F5  (0xC83F5) -- args=0
void sub_C83F5(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C83F5()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8436  (0xC8436) -- args=8
void sub_C8436(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8436()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C8460  (0xC8460) -- args=4
void sub_C8460(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8460()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C84F8  (0xC84F8) -- args=0
void sub_C84F8(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C84F8()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C855B  (0xC855B) -- args=4
void sub_C855B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C855B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C85EC  (0xC85EC) -- args=4
void sub_C85EC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C85EC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8659  (0xC8659) -- args=0
void sub_C8659(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8659()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C86BC  (0xC86BC) -- args=0
void sub_C86BC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C86BC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8735  (0xC8735) -- args=4
void sub_C8735(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8735()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8761  (0xC8761) -- args=0
void sub_C8761(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8761()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C87CF  (0xC87CF) -- args=4
void sub_C87CF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C87CF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C881F  (0xC881F) -- args=4
void sub_C881F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C881F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8844  (0xC8844) -- args=4
void sub_C8844(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8844()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C88A6  (0xC88A6) -- args=0
void sub_C88A6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C88A6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C89BA  (0xC89BA) -- args=4
void sub_C89BA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C89BA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8A36  (0xC8A36) -- args=4
void sub_C8A36(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8A36()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8A5D  (0xC8A5D) -- args=4
void sub_C8A5D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8A5D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8A6E  (0xC8A6E) -- args=16
void sub_C8A6E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8A6E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C8A7A  (0xC8A7A) -- args=4
void sub_C8A7A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8A7A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8A96  (0xC8A96) -- args=0
void sub_C8A96(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8A96()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8B41  (0xC8B41) -- args=0
void sub_C8B41(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8B41()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8B83  (0xC8B83) -- args=8
void sub_C8B83(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8B83()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C8B99  (0xC8B99) -- args=4
void sub_C8B99(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8B99()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8BDD  (0xC8BDD) -- args=16
void sub_C8BDD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8BDD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C8BE9  (0xC8BE9) -- args=0
void sub_C8BE9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8BE9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8C04  (0xC8C04) -- args=0
void sub_C8C04(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8C04()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8C4B  (0xC8C4B) -- args=4
void sub_C8C4B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8C4B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8D21  (0xC8D21) -- args=0
void sub_C8D21(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8D21()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8D76  (0xC8D76) -- args=4
void sub_C8D76(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8D76()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8DBD  (0xC8DBD) -- args=8
void sub_C8DBD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8DBD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C8DC9  (0xC8DC9) -- args=0
void sub_C8DC9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8DC9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8EBB  (0xC8EBB) -- args=4
void sub_C8EBB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8EBB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8ED9  (0xC8ED9) -- args=4
void sub_C8ED9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8ED9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8EF2  (0xC8EF2) -- args=4
void sub_C8EF2(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8EF2()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8F14  (0xC8F14) -- args=4
void sub_C8F14(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8F14()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C8F32  (0xC8F32) -- args=16
void sub_C8F32(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8F32()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C8F68  (0xC8F68) -- args=12
void sub_C8F68(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8F68()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C8F8F  (0xC8F8F) -- args=0
void sub_C8F8F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8F8F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8FAF  (0xC8FAF) -- args=0
void sub_C8FAF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8FAF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C8FD1  (0xC8FD1) -- args=4
void sub_C8FD1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C8FD1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C905C  (0xC905C) -- args=8
void sub_C905C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C905C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C912D  (0xC912D) -- args=8
void sub_C912D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C912D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C914E  (0xC914E) -- args=12
void sub_C914E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C914E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C91BB  (0xC91BB) -- args=8
void sub_C91BB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C91BB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C91D2  (0xC91D2) -- args=0
void sub_C91D2(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C91D2()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C91F7  (0xC91F7) -- args=0
void sub_C91F7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C91F7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9258  (0xC9258) -- args=12
void sub_C9258(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9258()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_C92DC  (0xC92DC) -- args=4
void sub_C92DC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C92DC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C93BD  (0xC93BD) -- args=8
void sub_C93BD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C93BD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C93D8  (0xC93D8) -- args=4
void sub_C93D8(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C93D8()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C93F3  (0xC93F3) -- args=8
void sub_C93F3(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C93F3()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C9482  (0xC9482) -- args=4
void sub_C9482(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9482()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C94DE  (0xC94DE) -- args=4
void sub_C94DE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C94DE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C94F9  (0xC94F9) -- args=4
void sub_C94F9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C94F9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C9592  (0xC9592) -- args=4
void sub_C9592(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9592()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C95DD  (0xC95DD) -- args=0
// CMcpxStream vtable init: dword_CE01C = &dword_CD8A8
void sub_C95DD(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE-DS] sub_C95DD() -- CMcpxStream vtable init\n");
    X86_MEM_WRITE_u32(base, 0xCE01C, 0xCD8A8);
    GuestStackCleanup(ctx, 0);
}

// sub_C95E8  (0xC95E8) -- args=0
// CMcpxStream vtable init: dword_CE018 = &dword_CD8AC
void sub_C95E8(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE-DS] sub_C95E8() -- CMcpxStream vtable init\n");
    X86_MEM_WRITE_u32(base, 0xCE018, 0xCD8AC);
    GuestStackCleanup(ctx, 0);
}

// sub_C95F3  (0xC95F3) -- args=0
void sub_C95F3(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C95F3()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C95F7  (0xC95F7) -- args=0
void sub_C95F7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C95F7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C95FB  (0xC95FB) -- args=16
void sub_C95FB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C95FB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_C961D  (0xC961D) -- args=0
void sub_C961D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C961D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9639  (0xC9639) -- args=4
void sub_C9639(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9639()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C9684  (0xC9684) -- args=0
void sub_C9684(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9684()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9797  (0xC9797) -- args=0
void sub_C9797(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9797()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C981F  (0xC981F) -- args=8
void sub_C981F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C981F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C98D0  (0xC98D0) -- args=4
void sub_C98D0(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C98D0()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C9B24  (0xC9B24) -- args=4
void sub_C9B24(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9B24()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C9BA6  (0xC9BA6) -- args=8
void sub_C9BA6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9BA6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_C9C1A  (0xC9C1A) -- args=4
void sub_C9C1A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9C1A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_C9DF6  (0xC9DF6) -- args=0
void sub_C9DF6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9DF6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9E5B  (0xC9E5B) -- args=0
void sub_C9E5B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9E5B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9EDF  (0xC9EDF) -- args=0
void sub_C9EDF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9EDF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_C9F33  (0xC9F33) -- args=4
void sub_C9F33(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_C9F33()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CA019  (0xCA019) -- args=8
void sub_CA019(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA019()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CA2D2  (0xCA2D2) -- args=0
void sub_CA2D2(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA2D2()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CA35D  (0xCA35D) -- args=8
void sub_CA35D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA35D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CA37B  (0xCA37B) -- args=4
void sub_CA37B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA37B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CA392  (0xCA392) -- args=0
void sub_CA392(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA392()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CA6F7  (0xCA6F7) -- args=0
void sub_CA6F7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA6F7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CA713  (0xCA713) -- args=0
void sub_CA713(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA713()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CA77C  (0xCA77C) -- args=8
void sub_CA77C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA77C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CA7E1  (0xCA7E1) -- args=4
void sub_CA7E1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA7E1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CA9A0  (0xCA9A0) -- args=0
void sub_CA9A0(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CA9A0()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CAAA7  (0xCAAA7) -- args=0
void sub_CAAA7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CAAA7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CAADF  (0xCAADF) -- args=0
void sub_CAADF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CAADF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CACAB  (0xCACAB) -- args=4
void sub_CACAB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CACAB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CACC6  (0xCACC6) -- args=4
void sub_CACC6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CACC6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CAD38  (0xCAD38) -- args=0
void sub_CAD38(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CAD38()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CAD7B  (0xCAD7B) -- args=4
void sub_CAD7B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CAD7B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CAEBC  (0xCAEBC) -- args=8
void sub_CAEBC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CAEBC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CB1CF  (0xCB1CF) -- args=0
void sub_CB1CF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB1CF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB216  (0xCB216) -- args=8
void sub_CB216(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB216()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CB277  (0xCB277) -- args=0
void sub_CB277(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB277()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB2B1  (0xCB2B1) -- args=16
void sub_CB2B1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB2B1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_CB2E0  (0xCB2E0) -- args=4
void sub_CB2E0(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB2E0()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CB2FA  (0xCB2FA) -- args=8
void sub_CB2FA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB2FA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CB356  (0xCB356) -- args=0
void sub_CB356(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB356()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB3BB  (0xCB3BB) -- args=0
void sub_CB3BB(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB3BB()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB40D  (0xCB40D) -- args=0
void sub_CB40D(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB40D()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB4AC  (0xCB4AC) -- args=0
void sub_CB4AC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB4AC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB5AA  (0xCB5AA) -- args=0
void sub_CB5AA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB5AA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB5F5  (0xCB5F5) -- args=0
void sub_CB5F5(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB5F5()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB799  (0xCB799) -- args=0
void sub_CB799(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB799()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB7D7  (0xCB7D7) -- args=0
void sub_CB7D7(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB7D7()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB824  (0xCB824) -- args=0
void sub_CB824(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB824()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB87C  (0xCB87C) -- args=0
void sub_CB87C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB87C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB897  (0xCB897) -- args=0
void sub_CB897(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB897()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CB8D4  (0xCB8D4) -- args=4
void sub_CB8D4(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB8D4()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CB905  (0xCB905) -- args=8
void sub_CB905(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB905()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CB954  (0xCB954) -- args=4
void sub_CB954(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB954()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CB96F  (0xCB96F) -- args=4
void sub_CB96F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB96F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CB978  (0xCB978) -- args=4
void sub_CB978(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB978()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CB9C6  (0xCB9C6) -- args=16
void sub_CB9C6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CB9C6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_CBA52  (0xCBA52) -- args=32
void sub_CBA52(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBA52()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 32);
}

// sub_CBB81  (0xCBB81) -- args=4
void sub_CBB81(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBB81()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CBB9B  (0xCBB9B) -- args=0
void sub_CBB9B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBB9B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CBBC9  (0xCBBC9) -- args=4
void sub_CBBC9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBBC9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CBC7C  (0xCBC7C) -- args=12
void sub_CBC7C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBC7C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CBCCE  (0xCBCCE) -- args=12
void sub_CBCCE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBCCE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CBCF6  (0xCBCF6) -- args=0
void sub_CBCF6(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBCF6()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CBDC9  (0xCBDC9) -- args=0
void sub_CBDC9(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBDC9()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CBF08  (0xCBF08) -- args=0
void sub_CBF08(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CBF08()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC0AC  (0xCC0AC) -- args=0
void sub_CC0AC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC0AC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC165  (0xCC165) -- args=4
void sub_CC165(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC165()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC19C  (0xCC19C) -- args=4
void sub_CC19C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC19C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC1D3  (0xCC1D3) -- args=4
void sub_CC1D3(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC1D3()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC22E  (0xCC22E) -- args=4
void sub_CC22E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC22E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC290  (0xCC290) -- args=16
void sub_CC290(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC290()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_CC307  (0xCC307) -- args=12
void sub_CC307(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC307()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CC344  (0xCC344) -- args=12
void sub_CC344(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC344()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CC383  (0xCC383) -- args=0
void sub_CC383(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC383()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC3FD  (0xCC3FD) -- args=0
void sub_CC3FD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC3FD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC429  (0xCC429) -- args=4
void sub_CC429(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC429()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC44C  (0xCC44C) -- args=0
void sub_CC44C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC44C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC4F1  (0xCC4F1) -- args=0
void sub_CC4F1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC4F1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC5BE  (0xCC5BE) -- args=0
void sub_CC5BE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC5BE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC73E  (0xCC73E) -- args=4
void sub_CC73E(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC73E()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC81B  (0xCC81B) -- args=4
void sub_CC81B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC81B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CC836  (0xCC836) -- args=0
void sub_CC836(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC836()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC8B3  (0xCC8B3) -- args=0
void sub_CC8B3(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC8B3()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC91F  (0xCC91F) -- args=0
void sub_CC91F(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC91F()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC927  (0xCC927) -- args=0
void sub_CC927(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC927()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC954  (0xCC954) -- args=0
void sub_CC954(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC954()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC9A4  (0xCC9A4) -- args=0
void sub_CC9A4(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC9A4()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC9B8  (0xCC9B8) -- args=8
void sub_CC9B8(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC9B8()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CC9D5  (0xCC9D5) -- args=0
void sub_CC9D5(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC9D5()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CC9ED  (0xCC9ED) -- args=0
void sub_CC9ED(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CC9ED()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCA1C  (0xCCA1C) -- args=16
void sub_CCA1C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCA1C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_CCAAC  (0xCCAAC) -- args=4
void sub_CCAAC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCAAC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCADD  (0xCCADD) -- args=4
void sub_CCADD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCADD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCB0B  (0xCCB0B) -- args=4
void sub_CCB0B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCB0B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCB19  (0xCCB19) -- args=8
void sub_CCB19(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCB19()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CCB81  (0xCCB81) -- args=8
void sub_CCB81(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCB81()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CCC12  (0xCCC12) -- args=0
void sub_CCC12(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCC12()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCC84  (0xCCC84) -- args=4
void sub_CCC84(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCC84()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCCD2  (0xCCCD2) -- args=4
void sub_CCCD2(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCCD2()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCD2C  (0xCCD2C) -- args=12
void sub_CCD2C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCD2C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CCDCE  (0xCCDCE) -- args=0
void sub_CCDCE(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCDCE()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCE1C  (0xCCE1C) -- args=0
void sub_CCE1C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCE1C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCE73  (0xCCE73) -- args=0
void sub_CCE73(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCE73()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCF47  (0xCCF47) -- args=0
void sub_CCF47(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCF47()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CCFA0  (0xCCFA0) -- args=8
void sub_CCFA0(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCFA0()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CCFB1  (0xCCFB1) -- args=16
void sub_CCFB1(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCFB1()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// sub_CCFBD  (0xCCFBD) -- args=4
void sub_CCFBD(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCFBD()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CCFFC  (0xCCFFC) -- args=0
void sub_CCFFC(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CCFFC()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD06B  (0xCD06B) -- args=4
void sub_CD06B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD06B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CD07A  (0xCD07A) -- args=0
void sub_CD07A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD07A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD087  (0xCD087) -- args=4
void sub_CD087(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD087()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CD166  (0xCD166) -- args=0
void sub_CD166(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD166()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD16C  (0xCD16C) -- args=12
void sub_CD16C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD16C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// sub_CD20A  (0xCD20A) -- args=0
void sub_CD20A(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD20A()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD217  (0xCD217) -- args=0
void sub_CD217(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD217()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD21B  (0xCD21B) -- args=4
void sub_CD21B(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD21B()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// sub_CD292  (0xCD292) -- args=8
void sub_CD292(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD292()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CD2BA  (0xCD2BA) -- args=8
void sub_CD2BA(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD2BA()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// sub_CD2FF  (0xCD2FF) -- args=0
void sub_CD2FF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD2FF()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// sub_CD31C  (0xCD31C) -- args=4
void sub_CD31C(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet) fprintf(stderr, "[HLE-DS] sub_CD31C()\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}
