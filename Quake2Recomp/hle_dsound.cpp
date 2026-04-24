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
#include "kernel/memory.h"
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
// DSOUND internal sub-function stubs (auto-generated from dsound.txt)
// ============================================================================

void sub_CC8C0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC8C0 (0x000CC8C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CC8DF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC8DF (0x000CC8DF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CC8F0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC8F0 (0x000CC8F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CC912(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC912 (0x000CC912) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CC929(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC929 (0x000CC929) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CC94E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC94E (0x000CC94E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CC979(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC979 (0x000CC979) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CC9AB(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC9AB (0x000CC9AB) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CC9B4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC9B4 (0x000CC9B4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CC9FD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CC9FD (0x000CC9FD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CCA01(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCA01 (0x000CCA01) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}
void sub_CCA2A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCA2A (0x000CCA2A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}
void sub_CCA61(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCA61 (0x000CCA61) called\n"); logged = true; }
    GuestStackCleanup(ctx, 20);
}
void sub_CCA81(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCA81 (0x000CCA81) called\n"); logged = true; }
    GuestStackCleanup(ctx, 28);
}
void sub_CCAB5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCAB5 (0x000CCAB5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CCAD7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCAD7 (0x000CCAD7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CCB97(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCB97 (0x000CCB97) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CCBB9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCBB9 (0x000CCBB9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CCBD6(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCBD6 (0x000CCBD6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CCC41(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCC41 (0x000CCC41) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CCCAF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCCAF (0x000CCCAF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CCD18(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCD18 (0x000CCD18) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CCDED(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCDED (0x000CCDED) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CCE20(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCE20 (0x000CCE20) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CCE67(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CCE67 (0x000CCE67) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD5DE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD5DE (0x000CD5DE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD5F9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD5F9 (0x000CD5F9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD6C4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD6C4 (0x000CD6C4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD797(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD797 (0x000CD797) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD7C1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD7C1 (0x000CD7C1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD7DC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD7DC (0x000CD7DC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CD873(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD873 (0x000CD873) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CD897(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD897 (0x000CD897) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD8AF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD8AF (0x000CD8AF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CD96A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CD96A (0x000CD96A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CDA33(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CDA33 (0x000CDA33) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CDA80(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CDA80 (0x000CDA80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CDF4E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CDF4E (0x000CDF4E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CDFDD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CDFDD (0x000CDFDD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE014(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE014 (0x000CE014) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CE116(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE116 (0x000CE116) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE13B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE13B (0x000CE13B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE1A0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE1A0 (0x000CE1A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE323(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE323 (0x000CE323) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE362(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE362 (0x000CE362) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE49B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE49B (0x000CE49B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE596(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE596 (0x000CE596) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE5AE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE5AE (0x000CE5AE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CE5FD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE5FD (0x000CE5FD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE615(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE615 (0x000CE615) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CE67D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE67D (0x000CE67D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE6B1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE6B1 (0x000CE6B1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE6DA(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE6DA (0x000CE6DA) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE701(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE701 (0x000CE701) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE74A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE74A (0x000CE74A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE78D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE78D (0x000CE78D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE798(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE798 (0x000CE798) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE7A3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE7A3 (0x000CE7A3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CE7E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE7E0 (0x000CE7E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE7FF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE7FF (0x000CE7FF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE874(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE874 (0x000CE874) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE888(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE888 (0x000CE888) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE89F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE89F (0x000CE89F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CE8E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE8E0 (0x000CE8E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CE90A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE90A (0x000CE90A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CE9A2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CE9A2 (0x000CE9A2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEA05(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEA05 (0x000CEA05) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEA96(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEA96 (0x000CEA96) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEB03(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEB03 (0x000CEB03) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEB66(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEB66 (0x000CEB66) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEBDF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEBDF (0x000CEBDF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEC0B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEC0B (0x000CEC0B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEC79(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEC79 (0x000CEC79) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CECC9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CECC9 (0x000CECC9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CECEE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CECEE (0x000CECEE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CED50(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CED50 (0x000CED50) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEE64(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEE64 (0x000CEE64) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEEE0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEEE0 (0x000CEEE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEF07(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEF07 (0x000CEF07) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEF18(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEF18 (0x000CEF18) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CEF24(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEF24 (0x000CEF24) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CEF40(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEF40 (0x000CEF40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CEFEB(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CEFEB (0x000CEFEB) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF02D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF02D (0x000CF02D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF043(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF043 (0x000CF043) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF087(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF087 (0x000CF087) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CF0AE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF0AE (0x000CF0AE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF0F5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF0F5 (0x000CF0F5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF1CB(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF1CB (0x000CF1CB) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF220(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF220 (0x000CF220) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF267(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF267 (0x000CF267) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF273(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF273 (0x000CF273) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF365(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF365 (0x000CF365) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF383(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF383 (0x000CF383) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF39C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF39C (0x000CF39C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF3BE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF3BE (0x000CF3BE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF3DC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF3DC (0x000CF3DC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CF412(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF412 (0x000CF412) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CF439(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF439 (0x000CF439) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF459(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF459 (0x000CF459) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF47B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF47B (0x000CF47B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF506(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF506 (0x000CF506) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF5D7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF5D7 (0x000CF5D7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF5F8(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF5F8 (0x000CF5F8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CF665(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF665 (0x000CF665) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF67C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF67C (0x000CF67C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF6A1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF6A1 (0x000CF6A1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CF702(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF702 (0x000CF702) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_CF786(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF786 (0x000CF786) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF867(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF867 (0x000CF867) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF882(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF882 (0x000CF882) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF89D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF89D (0x000CF89D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CF92C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF92C (0x000CF92C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF988(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF988 (0x000CF988) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CF9A3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CF9A3 (0x000CF9A3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CFA3C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFA3C (0x000CFA3C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CFA87(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFA87 (0x000CFA87) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFA92(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFA92 (0x000CFA92) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFA9D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFA9D (0x000CFA9D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFAA1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFAA1 (0x000CFAA1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFAA5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFAA5 (0x000CFAA5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_CFAC7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFAC7 (0x000CFAC7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFAE3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFAE3 (0x000CFAE3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CFB2E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFB2E (0x000CFB2E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFC41(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFC41 (0x000CFC41) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_CFCC9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFCC9 (0x000CFCC9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_CFD7A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFD7A (0x000CFD7A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_CFFCE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_CFFCE (0x000CFFCE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D0050(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0050 (0x000D0050) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D00C4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D00C4 (0x000D00C4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D02A0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D02A0 (0x000D02A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0305(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0305 (0x000D0305) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0389(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0389 (0x000D0389) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D03DD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D03DD (0x000D03DD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D04C3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D04C3 (0x000D04C3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D077C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D077C (0x000D077C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0807(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0807 (0x000D0807) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D0825(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0825 (0x000D0825) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D083C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D083C (0x000D083C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0BA1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0BA1 (0x000D0BA1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0BBD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0BBD (0x000D0BBD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0C26(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0C26 (0x000D0C26) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D0C8B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0C8B (0x000D0C8B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D0E4A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0E4A (0x000D0E4A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0F51(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0F51 (0x000D0F51) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D0F89(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D0F89 (0x000D0F89) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1155(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1155 (0x000D1155) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D1170(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1170 (0x000D1170) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D11E2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D11E2 (0x000D11E2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1225(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1225 (0x000D1225) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D1366(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1366 (0x000D1366) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D1679(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1679 (0x000D1679) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D16C0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D16C0 (0x000D16C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D1721(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1721 (0x000D1721) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D175B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D175B (0x000D175B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_D178A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D178A (0x000D178A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D17A4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D17A4 (0x000D17A4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D17B9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D17B9 (0x000D17B9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D1815(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1815 (0x000D1815) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D187A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D187A (0x000D187A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D18CC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D18CC (0x000D18CC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D196B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D196B (0x000D196B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1A69(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1A69 (0x000D1A69) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1AB4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1AB4 (0x000D1AB4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1C58(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1C58 (0x000D1C58) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1C96(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1C96 (0x000D1C96) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1CE3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1CE3 (0x000D1CE3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1D3B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1D3B (0x000D1D3B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1D56(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1D56 (0x000D1D56) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D1D93(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1D93 (0x000D1D93) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D1DC4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1DC4 (0x000D1DC4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D1E2E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1E2E (0x000D1E2E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D1E7C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1E7C (0x000D1E7C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_D1F08(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D1F08 (0x000D1F08) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}
void sub_D2037(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2037 (0x000D2037) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2051(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2051 (0x000D2051) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D207F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D207F (0x000D207F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2132(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2132 (0x000D2132) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D2184(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2184 (0x000D2184) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D21AC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D21AC (0x000D21AC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D227F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D227F (0x000D227F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D23BE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D23BE (0x000D23BE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2562(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2562 (0x000D2562) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D261B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D261B (0x000D261B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2652(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2652 (0x000D2652) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2689(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2689 (0x000D2689) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D26E4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D26E4 (0x000D26E4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2746(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2746 (0x000D2746) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_D27BD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D27BD (0x000D27BD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D27FA(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D27FA (0x000D27FA) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D2839(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2839 (0x000D2839) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D28B3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D28B3 (0x000D28B3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D28DF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D28DF (0x000D28DF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2902(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2902 (0x000D2902) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D29A7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D29A7 (0x000D29A7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2A74(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2A74 (0x000D2A74) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2BF4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2BF4 (0x000D2BF4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2CD1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2CD1 (0x000D2CD1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2CEC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2CEC (0x000D2CEC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2D69(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2D69 (0x000D2D69) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2DD5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2DD5 (0x000D2DD5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2DDD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2DDD (0x000D2DDD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2E0A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2E0A (0x000D2E0A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2E5A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2E5A (0x000D2E5A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2E6E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2E6E (0x000D2E6E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D2E8B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2E8B (0x000D2E8B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2EA3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2EA3 (0x000D2EA3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D2ED2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2ED2 (0x000D2ED2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}
void sub_D2F62(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2F62 (0x000D2F62) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2F93(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2F93 (0x000D2F93) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2FC1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2FC1 (0x000D2FC1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D2FCF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D2FCF (0x000D2FCF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D3037(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3037 (0x000D3037) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D30C8(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D30C8 (0x000D30C8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D313A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D313A (0x000D313A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D3188(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3188 (0x000D3188) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D31E2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D31E2 (0x000D31E2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D3284(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3284 (0x000D3284) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D32D2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D32D2 (0x000D32D2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D3329(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3329 (0x000D3329) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D33FD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D33FD (0x000D33FD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D3473(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3473 (0x000D3473) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D34B2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D34B2 (0x000D34B2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D3521(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3521 (0x000D3521) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D353D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D353D (0x000D353D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D361C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D361C (0x000D361C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D3622(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3622 (0x000D3622) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}
void sub_D36C0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D36C0 (0x000D36C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D36CD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D36CD (0x000D36CD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D36D1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D36D1 (0x000D36D1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}
void sub_D3748(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3748 (0x000D3748) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D3770(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D3770 (0x000D3770) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}
void sub_D37B5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D37B5 (0x000D37B5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}
void sub_D37D2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_D37D2 (0x000D37D2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// HLE: Xbox DirectSound internal streaming thread (sub_9F100)
// ---------------------------------------------------------------------------
// This is the Xbox DSound playback/streaming thread created by
// PsCreateSystemThreadEx from within the DSound library.  It loops reading
// audio buffers, running format-conversion callbacks, and writing to the APU.
//
// Since we handle all audio output through the SDL2 audio callback (see the
// HLE_DSBuffer / SDL_OpenAudioDevice path above), this thread has nothing
// useful to do.  Worse, the conversion-callback pointers in the DSound buffer
// structures are never initialised by the HLE stubs, so the thread crashes
// trying to call through garbage pointers (e.g. 0x1474146D).
//
// Fix: replace the entire thread function with a no-op that returns 0.
// The cdecl signature is:  int __cdecl sub_9F100(int dsoundBufferObj)
// ---------------------------------------------------------------------------
void sub_9F100(X86Context& ctx, uint8_t* base) {
    fprintf(stderr, "[HLE-DS] sub_9F100: Xbox DSound streaming thread — no-op (SDL2 handles audio)\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// HLE SDL Audio layer
//
// The Quake 2 Xbox port uses SDL audio internally (SDL_OpenAudio etc.) which
// in the original XBE wraps DirectSound.  Instead of letting the recompiled
// Xbox SDL code try to talk to DSound → APU, we intercept at the SDL level
// and open a real host SDL audio device.
//
// The game's audio callback (sub_89200) is a cdecl function:
//   void callback(void* userdata, uint8_t* stream, int len)
// It sets dma->buffer = stream, then calls S_PaintChannels to mix audio.
//
// We call the guest callback from the host SDL audio thread using a dedicated
// X86Context and a pre-allocated guest-memory stream buffer.
// ============================================================================

// Guest SDL_AudioSpec layout (matches Xbox SDL):
//   +0x00  int     freq
//   +0x04  uint16  format
//   +0x06  uint8   channels
//   +0x07  uint8   silence
//   +0x08  uint16  samples
//   +0x0A  uint16  padding
//   +0x0C  uint32  size         (calculated: samples * channels * bytesPerSample)
//   +0x10  void*   callback
//   +0x14  void*   userdata

static SDL_AudioDeviceID g_sdlGuestAudioDev = 0;
static uint32_t g_guestCallbackAddr = 0;   // Guest address of the audio callback
static uint32_t g_guestUserdata     = 0;   // Guest userdata pointer
static uint32_t g_guestStreamBuf    = 0;   // Guest-allocated stream buffer address
static uint32_t g_guestStreamSize   = 0;   // Size of the stream buffer in bytes
static std::mutex g_guestAudioMutex;

// Host SDL audio callback — runs on the SDL audio thread.
// Sets up a temporary X86Context and calls the guest callback.
static void HLE_GuestAudioCallback(void* /*userdata*/, Uint8* hostStream, int hostLen)
{
    std::lock_guard<std::mutex> lk(g_guestAudioMutex);

    uint8_t* base = g_memory.base;
    if (!base || !g_guestCallbackAddr || !g_guestStreamBuf) {
        memset(hostStream, 0, hostLen);
        return;
    }

    // Clamp to our pre-allocated guest buffer size.
    uint32_t len = (uint32_t)hostLen;
    if (len > g_guestStreamSize) len = g_guestStreamSize;

    // Zero the guest stream buffer before calling the callback.
    memset(base + g_guestStreamBuf, 0, len);

    // Set up a temporary X86Context for the audio thread.
    X86Context ctx{};
    memset(&ctx, 0, sizeof(ctx));

    // Use a small area at the top of the guest stream buffer region as stack.
    // The guest callback is lightweight (sets a pointer, calls S_PaintChannels).
    // Allocate 4KB of stack space above the stream buffer.
    static uint32_t s_audioStack = 0;
    if (!s_audioStack) {
        s_audioStack = g_heap.AllocGuestAligned(4096, 16);
    }
    ctx.esp = s_audioStack + 4096 - 16;
    ctx.ebp = ctx.esp;
    ctx.fp_control = 0x037F;

    // Push cdecl arguments: callback(userdata, stream, len)
    // Stack layout: [esp+0] = dummy return addr, [esp+4] = userdata,
    //               [esp+8] = stream, [esp+12] = len
    ctx.esp -= 4;
    X86_MEM_WRITE_u32(base, ctx.esp, len);                    // arg2: len
    ctx.esp -= 4;
    X86_MEM_WRITE_u32(base, ctx.esp, g_guestStreamBuf);       // arg1: stream
    ctx.esp -= 4;
    X86_MEM_WRITE_u32(base, ctx.esp, g_guestUserdata);        // arg0: userdata
    ctx.esp -= 4;
    X86_MEM_WRITE_u32(base, ctx.esp, 0);                      // dummy return addr

    // Look up and call the guest callback.
    auto it = g_funcMap.find(g_guestCallbackAddr);
    if (it != g_funcMap.end()) {
        it->second(ctx, base);
    }

    // Copy the mixed audio from guest memory to the host output stream.
    memcpy(hostStream, base + g_guestStreamBuf, len);

    // Zero any remaining host bytes if hostLen > len.
    if ((uint32_t)hostLen > len) {
        memset(hostStream + len, 0, hostLen - len);
    }
}

// ---------------------------------------------------------------------------
// sub_9F530 — SDL_OpenAudio(desired, obtained)
//
// cdecl: int SDL_OpenAudio(SDL_AudioSpec* desired, SDL_AudioSpec* obtained)
// Returns 0 on success, -1 on failure.
// ---------------------------------------------------------------------------
void sub_9F530(X86Context& ctx, uint8_t* base) {
    uint32_t pDesired  = GuestArg32(ctx, base, 0);
    uint32_t pObtained = GuestArg32(ctx, base, 1);

    // Read the desired AudioSpec from guest memory.
    uint32_t freq     = X86_MEM_READ_u32(base, pDesired + 0x00);
    uint16_t format   = X86_MEM_READ_u16(base, pDesired + 0x04);
    uint8_t  channels = X86_MEM_READ_u8(base, pDesired + 0x06);
    uint16_t samples  = X86_MEM_READ_u16(base, pDesired + 0x08);
    uint32_t callback = X86_MEM_READ_u32(base, pDesired + 0x10);
    uint32_t userdata = X86_MEM_READ_u32(base, pDesired + 0x14);

    fprintf(stderr, "[HLE-SDL] SDL_OpenAudio(freq=%u, fmt=0x%04X, ch=%u, samples=%u, cb=0x%08X, ud=0x%08X)\n",
            freq, format, channels, samples, callback, userdata);

    // Map Xbox SDL audio format to host SDL format.
    SDL_AudioFormat hostFmt;
    int bytesPerSample;
    switch (format) {
        case 0x0008: hostFmt = AUDIO_U8;  bytesPerSample = 1; break;
        case 0x8008: hostFmt = AUDIO_S8;  bytesPerSample = 1; break;
        case 0x8010: hostFmt = AUDIO_S16SYS; bytesPerSample = 2; break;
        default:     hostFmt = AUDIO_S16SYS; bytesPerSample = 2; break;
    }

    // Save guest callback info.
    g_guestCallbackAddr = callback;
    g_guestUserdata     = userdata;

    // Calculate stream buffer size and allocate in guest memory.
    g_guestStreamSize = samples * channels * bytesPerSample;
    g_guestStreamBuf  = g_heap.AllocGuestAligned(g_guestStreamSize, 16);
    memset(base + g_guestStreamBuf, 0, g_guestStreamSize);

    fprintf(stderr, "[HLE-SDL]   Guest stream buffer: 0x%08X (%u bytes)\n",
            g_guestStreamBuf, g_guestStreamSize);

    // Ensure SDL audio subsystem is initialized.
    if (SDL_WasInit(SDL_INIT_AUDIO) == 0) {
        if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
            fprintf(stderr, "[HLE-SDL]   SDL_InitSubSystem(AUDIO) failed: %s\n", SDL_GetError());
            ctx.eax = (uint32_t)-1;
            return;
        }
    }

    // Open a real host SDL audio device.
    SDL_AudioSpec desired{}, obtained{};
    desired.freq     = (int)freq;
    desired.format   = hostFmt;
    desired.channels = channels;
    desired.samples  = samples;
    desired.callback = HLE_GuestAudioCallback;
    desired.userdata = nullptr;

    g_sdlGuestAudioDev = SDL_OpenAudioDevice(nullptr, 0, &desired, &obtained, 0);
    if (!g_sdlGuestAudioDev) {
        fprintf(stderr, "[HLE-SDL]   SDL_OpenAudioDevice failed: %s\n", SDL_GetError());
        ctx.eax = (uint32_t)-1;
        return;
    }

    fprintf(stderr, "[HLE-SDL]   Opened audio device: %d Hz, %d ch, %d samples\n",
            obtained.freq, obtained.channels, obtained.samples);

    // If obtained differs, write back to the obtained spec (if provided).
    if (pObtained) {
        X86_MEM_WRITE_u32(base, pObtained + 0x00, (uint32_t)obtained.freq);
        X86_MEM_WRITE_u16(base, pObtained + 0x04, format);  // keep guest format code
        X86_MEM_WRITE_u8(base, pObtained + 0x06, obtained.channels);
        X86_MEM_WRITE_u8(base, pObtained + 0x07, 0); // silence
        X86_MEM_WRITE_u16(base, pObtained + 0x08, obtained.samples);
        X86_MEM_WRITE_u16(base, pObtained + 0x0A, 0); // padding
        uint32_t obtSize = obtained.samples * obtained.channels * bytesPerSample;
        X86_MEM_WRITE_u32(base, pObtained + 0x0C, obtSize);
        X86_MEM_WRITE_u32(base, pObtained + 0x10, callback);
        X86_MEM_WRITE_u32(base, pObtained + 0x14, userdata);
    }

    // Return 0 (success).  The audio device starts paused.
    ctx.eax = 0;
}

// ---------------------------------------------------------------------------
// sub_9F2F0 — SDL_PauseAudio(pause_on)
// cdecl: void SDL_PauseAudio(int pause_on)
// ---------------------------------------------------------------------------
void sub_9F2F0(X86Context& ctx, uint8_t* base) {
    uint32_t pauseOn = GuestArg32(ctx, base, 0);

    fprintf(stderr, "[HLE-SDL] SDL_PauseAudio(%u)\n", pauseOn);

    if (g_sdlGuestAudioDev) {
        SDL_PauseAudioDevice(g_sdlGuestAudioDev, pauseOn ? 1 : 0);
    }
}

// ---------------------------------------------------------------------------
// sub_9F310 — SDL_CloseAudio()
// cdecl: void SDL_CloseAudio(void)
// ---------------------------------------------------------------------------
void sub_9F310(X86Context& ctx, uint8_t* base) {
    fprintf(stderr, "[HLE-SDL] SDL_CloseAudio()\n");

    if (g_sdlGuestAudioDev) {
        SDL_CloseAudioDevice(g_sdlGuestAudioDev);
        g_sdlGuestAudioDev = 0;
    }
    g_guestCallbackAddr = 0;
}
