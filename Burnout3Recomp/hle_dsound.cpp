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
#include <chrono>
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
    uint32_t guestVoiceAddr;    // Guest addr of CDirectSoundVoice sub-object
    uint32_t guestMcpxAddr;     // Guest addr of CMcpxVoiceClient sub-object
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
    uint32_t playCursor;    // Current play position within the play region (bytes from playRegionStart)
    // Play region -- restricts playback to a sub-range of the buffer cache.
    // Set by IDirectSoundBuffer_SetPlayRegion / CDirectSoundBuffer_SetPlayRegion.
    // playRegionStart = byte offset within bufferCacheAddr.
    // playRegionLength = number of bytes to play; 0 means use full bufferCacheSize.
    uint32_t playRegionStart;
    uint32_t playRegionLength;
    float    volume;        // Linear volume [0.0 .. 1.0]
    int32_t  volumeMillibels; // Raw volume in millibels (0 = full, -10000 = silence)
    uint32_t headroom;       // Headroom attenuation in millibels (0-10000)
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

// Accept any known pointer that can reference a DS buffer internals.
static HLE_DSBuffer* HLE_FindDSBufferAny(uint32_t guestAddr)
{
    for (auto* b : g_dsBuffers) {
        if (b->guestIFaceAddr == guestAddr ||
            b->guestObjAddr == guestAddr ||
            b->guestVoiceAddr == guestAddr ||
            b->guestMcpxAddr == guestAddr) {
            return b;
        }
    }
    return nullptr;
}

// ============================================================================
// HLE DSound stream tracking
//
// Based on Cxbx-Reloaded X_CDirectSoundStream.  The game creates streams
// via DirectSoundCreateStream and then calls IDirectSoundStream_* methods
// on the returned pointer.  We allocate a minimal guest object and track
// stream state host-side.
// ============================================================================

// Guest X_DSSTREAMDESC layout (matching Cxbx XbDSoundTypes.h)
static constexpr uint32_t XDSSTREAMDESC_dwFlags            = 0x00;
static constexpr uint32_t XDSSTREAMDESC_dwMaxAttachedPkts  = 0x04;
static constexpr uint32_t XDSSTREAMDESC_lpwfxFormat        = 0x08;
static constexpr uint32_t XDSSTREAMDESC_lpfnCallback       = 0x0C;
static constexpr uint32_t XDSSTREAMDESC_lpvContext         = 0x10;
static constexpr uint32_t XDSSTREAMDESC_mixBinsOutput      = 0x14;

// Minimal guest stream object size (enough for vtable ptr + internal fields)
static constexpr uint32_t DSSTREAM_OBJ_SIZE = 0x40;

struct HLE_DSStream {
    uint32_t guestObjAddr;       // Guest addr of stream object
    uint32_t dwFlags;
    uint32_t dwMaxAttachedPackets;
    uint16_t wFormatTag;
    uint16_t nChannels;
    uint32_t nSamplesPerSec;
    uint16_t wBitsPerSample;
    uint16_t nBlockAlign;
    uint32_t refCount;
    float    volume;
    int32_t  volumeMillibels;
    uint32_t headroom;
    bool     isPaused;       // Set by IDirectSoundStream_Pause / CDirectSoundStream_Pause
    uint32_t pendingPackets; // Number of submitted packets not yet marked complete
    bool     discontinuity;  // Discontinuity signaled -- gap in stream

    // PCM ring buffer (raw bytes at native format, guarded by g_audioMutex)
    // Monotonic 64-bit counters: index into ring = counter % ringSize.
    // Available bytes = pcmTotalWritten - pcmTotalRead (no wrap arithmetic).
    std::vector<uint8_t> pcmRing;
    uint64_t             pcmTotalWritten = 0;
    uint64_t             pcmTotalRead    = 0;
};

static std::vector<HLE_DSStream*> g_dsStreams;
static uint32_t g_streamVtblAddr = 0;

static HLE_DSStream* HLE_FindDSStream(uint32_t guestAddr)
{
    for (auto* s : g_dsStreams) {
        if (s->guestObjAddr == guestAddr) return s;
    }
    return nullptr;
}

// 3D listener state (stored host-side, not written to hardware)
static float g_listenerDopplerFactor  = 1.0f;
static float g_listenerDistanceFactor = 1.0f;
static float g_listenerRolloffFactor  = 1.0f;
static float g_listenerPosition[3]    = {0.0f, 0.0f, 0.0f};
static float g_listenerVelocity[3]    = {0.0f, 0.0f, 0.0f};
static float g_listenerOrientFront[3] = {0.0f, 0.0f, 1.0f};
static float g_listenerOrientTop[3]   = {0.0f, 1.0f, 0.0f};

// I3DL2 reverb listener parameters (stored host-side)
struct HLE_I3DL2Listener {
    int32_t  lRoom;                // [-10000, 0]     default: -1000
    int32_t  lRoomHF;              // [-10000, 0]     default: -100
    float    flRoomRolloffFactor;  // [0.0, 10.0]     default: 0.0
    float    flDecayTime;          // [0.1, 20.0]     default: 1.49
    float    flDecayHFRatio;       // [0.1, 2.0]      default: 0.83
    int32_t  lReflections;         // [-10000, 1000]  default: -2602
    float    flReflectionsDelay;   // [0.0, 0.3]      default: 0.007
    int32_t  lReverb;              // [-10000, 2000]  default: 200
    float    flReverbDelay;        // [0.0, 0.1]      default: 0.011
    float    flDiffusion;          // [0.0, 100.0]    default: 100.0
    float    flDensity;            // [0.0, 100.0]    default: 100.0
    float    flHFReference;        // [20.0, 20000.0] default: 5000.0
};
static HLE_I3DL2Listener g_i3dl2Listener = {
    -1000, -100, 0.0f, 1.49f, 0.83f, -2602, 0.007f, 200, 0.011f, 100.0f, 100.0f, 5000.0f
};

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

// ---- WMA decoder PCM ring registration (decoders self-feed from the XWB ring buffer) ----
struct HLE_WmaDec;  // forward declaration; definition in hle_wmadec.cpp
static std::vector<HLE_WmaDec*> g_wmaDecoders;  // registered background-decode decoders
// Counts active movie bg-thread decoders. When > 0, DSStream draining is suppressed
// so radio/music PCM from the game pump doesn't mix over the movie audio.
static int g_wmaStreamActive = 0;

void WmaRegisterDecoder(HLE_WmaDec* dec)
{
    std::lock_guard<std::mutex> lk(g_audioMutex);
    // Flush all DSStream rings so any buffered radio PCM doesn't bleed in.
    for (auto* st : g_dsStreams) {
        st->pcmTotalWritten = 0;
        st->pcmTotalRead    = 0;
        st->pendingPackets  = 0;
    }
    g_wmaDecoders.push_back(dec);
    g_wmaStreamActive++;
    fprintf(stderr, "[HLE-DS] WmaRegisterDecoder: g_wmaStreamActive=%d\n", g_wmaStreamActive);
}
void WmaUnregisterDecoder(HLE_WmaDec* dec)
{
    std::lock_guard<std::mutex> lk(g_audioMutex);
    g_wmaDecoders.erase(std::remove(g_wmaDecoders.begin(), g_wmaDecoders.end(), dec), g_wmaDecoders.end());
    if (g_wmaStreamActive > 0) g_wmaStreamActive--;
    fprintf(stderr, "[HLE-DS] WmaUnregisterDecoder: g_wmaStreamActive=%d\n", g_wmaStreamActive);
}

// Forward declaration: XMV audio ring-buffer mixer (implemented in hle_xmv.cpp)
void XmvMixAudioFrames(int16_t* outStereo, int frames);

// Forward declarations: WMA background-decode ring drain and mute control (hle_wmadec.cpp)
void WmaMixAudioFrames(int16_t* outStereo, int frames);
void WmaSetAllDecodersMuted(bool mute);

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

    // Mix XMV video audio (ring buffers filled by GetNextFrame)
    XmvMixAudioFrames(out, outFrames);

    // Mix WMA decoder ring buffers (background-decode threads feed from XWB data)
    WmaMixAudioFrames(out, outFrames);

    // Mix DSStream ring buffers (e.g. WMA-decoded PCM from _EATrax1.xwb / fe.awd).
    // Suppress while a movie bg-thread decoder is active to prevent radio bleeding over movie audio.
    for (auto* st : g_dsStreams) {
        if (g_wmaStreamActive > 0) break; // movie audio playing — skip all DSStreams
        if (st->isPaused || st->pcmRing.empty()) continue;
        uint32_t ringSize       = (uint32_t)st->pcmRing.size();
        uint16_t srcCh          = st->nChannels ? st->nChannels : 2;
        uint32_t srcRate        = st->nSamplesPerSec ? st->nSamplesPerSec : HLE_AUDIO_RATE;
        uint16_t srcBps         = st->wBitsPerSample;
        if (srcBps != 8 && srcBps != 16) continue;
        uint32_t srcFrameBytes  = srcCh * (srcBps / 8u);

        uint64_t avail64     = st->pcmTotalWritten - st->pcmTotalRead;
        uint32_t avail       = avail64 > ringSize ? ringSize : (uint32_t)avail64;
        uint32_t availFrames = avail / srcFrameBytes;
        if (availFrames == 0) continue;

        // Diagnostic: log DSStream callback consumption
        {
            static int s_cbLogCount = 0;
            if (s_cbLogCount < 200) {
                fprintf(stderr, "[AUDIO-DIAG] callback: stream=0x%08X srcRate=%u avail=%u frames=%u outFrames=%d written=%llu read=%llu\n",
                        st->guestObjAddr, srcRate, avail, availFrames, outFrames,
                        (unsigned long long)st->pcmTotalWritten, (unsigned long long)st->pcmTotalRead);
                s_cbLogCount++;
            }
        }

        uint32_t rdIdx = (uint32_t)(st->pcmTotalRead % ringSize);

        uint32_t framesConsumed = 0;
        for (int i = 0; i < outFrames; i++) {
            uint32_t srcFrame = (uint32_t)((double)i * srcRate / HLE_AUDIO_RATE);
            if (srcFrame >= availFrames) break;
            framesConsumed = srcFrame + 1;

            uint32_t byteOff = srcFrame * srcFrameBytes;
            uint32_t baseIdx = (rdIdx + byteOff) % ringSize;

            int32_t left, right;
            if (srcBps == 16) {
                int16_t l = (int16_t)((uint16_t)st->pcmRing[baseIdx]
                                    | ((uint16_t)st->pcmRing[(baseIdx + 1) % ringSize] << 8));
                int16_t r = l;
                if (srcCh >= 2) {
                    r = (int16_t)((uint16_t)st->pcmRing[(baseIdx + 2) % ringSize]
                                | ((uint16_t)st->pcmRing[(baseIdx + 3) % ringSize] << 8));
                }
                left = l; right = r;
            } else { // 8-bit unsigned
                uint8_t l = st->pcmRing[baseIdx];
                uint8_t r = (srcCh >= 2) ? st->pcmRing[(baseIdx + 1) % ringSize] : l;
                left  = ((int32_t)l - 128) << 8;
                right = ((int32_t)r - 128) << 8;
            }

            int32_t mL = (int32_t)out[i * 2 + 0] + left;
            int32_t mR = (int32_t)out[i * 2 + 1] + right;
            if (mL >  32767) mL =  32767; if (mL < -32768) mL = -32768;
            if (mR >  32767) mR =  32767; if (mR < -32768) mR = -32768;
            out[i * 2 + 0] = (int16_t)mL;
            out[i * 2 + 1] = (int16_t)mR;
        }
        if (framesConsumed > 0) {
            st->pcmTotalRead += (uint64_t)framesConsumed * srcFrameBytes;
        }
    }

    // First pass: count playing buffers
    int playingCount = 0;
    for (auto* buf : g_dsBuffers) {
        if (buf->isPlaying) playingCount++;
    }

    for (auto* buf : g_dsBuffers) {
        if (!buf->isPlaying) continue;
        if (!buf->bufferCacheAddr || buf->bufferCacheSize == 0) continue;
        if (buf->wBitsPerSample != 8 && buf->wBitsPerSample != 16) continue;

        // Diagnostic: log active buffer playback parameters
        {
            static int s_bufPlayLog = 0;
            if (s_bufPlayLog < 50) {
                fprintf(stderr, "[AUDIO-CB] Playing buf=0x%08X srcRate=%u ch=%u bps=%u cursor=%u\n",
                        buf->guestIFaceAddr, buf->nSamplesPerSec, buf->nChannels, buf->wBitsPerSample,
                        buf->playCursor);
                s_bufPlayLog++;
            }
        }

        // Honour the play region: restrict to [playRegionStart, playRegionStart+playRegionLength).
        // playRegionLength == 0 means use the full buffer (no region set).
        uint32_t regionStart  = buf->playRegionStart;
        uint32_t regionLength = (buf->playRegionLength > 0)
                                    ? buf->playRegionLength
                                    : (buf->bufferCacheSize - regionStart);
        // Clamp region to buffer bounds.
        if (regionStart >= buf->bufferCacheSize) regionStart = 0;
        if (regionStart + regionLength > buf->bufferCacheSize)
            regionLength = buf->bufferCacheSize - regionStart;
        if (regionLength == 0) { buf->isPlaying = false; continue; }

        uint8_t* cache = g_audioBase + buf->bufferCacheAddr + regionStart;

        uint32_t srcRate    = buf->nSamplesPerSec ? buf->nSamplesPerSec : HLE_AUDIO_RATE;
        uint16_t srcCh      = buf->nChannels ? buf->nChannels : 1;
        uint16_t srcBps     = buf->wBitsPerSample;
        uint32_t srcAlign   = buf->nBlockAlign ? buf->nBlockAlign : (srcCh * (srcBps / 8));
        uint32_t srcFrames  = regionLength / srcAlign;
        if (srcFrames == 0) continue;

        // Volume scaling (linear).  Xbox uses millibels (0 = full, -10000 = silent).
        float volume = buf->volume;

        for (int i = 0; i < outFrames; i++) {
            // Map output frame index to source frame via sample-rate ratio.
            double srcPos = (double)i * srcRate / HLE_AUDIO_RATE;
            uint32_t srcIdx = (uint32_t)srcPos;
            uint32_t absIdx = buf->playCursor / srcAlign + srcIdx;

            // Handle end-of-region / looping.
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

        // Advance the play cursor (offset within the play region) by frames consumed.
        if (buf->isPlaying) {
            uint32_t srcFramesConsumed = (uint32_t)((double)outFrames * srcRate / HLE_AUDIO_RATE);
            uint32_t bytesConsumed = srcFramesConsumed * srcAlign;
            buf->playCursor += bytesConsumed;
            if (buf->playCursor >= regionLength) {
                if (buf->playFlags & 0x01) { // LOOPING
                    buf->playCursor %= regionLength;
                } else {
                    buf->isPlaying  = false;
                    buf->playCursor = 0;
                }
            }
        }
    }
}

// Lazy-init SDL audio.  Call with g_audioMutex NOT held.
void HLE_EnsureAudioInit(uint8_t* base)
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
    hleBuf->guestVoiceAddr  = guestVoice;
    hleBuf->guestMcpxAddr   = guestMcpx;
    hleBuf->bufferCacheAddr = guestBufCache;
    hleBuf->bufferCacheSize = dwBufferBytes;
    hleBuf->dwFlags         = dwFlags;
    hleBuf->wFormatTag      = wFormatTag;
    hleBuf->nChannels       = nChannels;
    hleBuf->nSamplesPerSec  = nSamplesPerSec;
    hleBuf->wBitsPerSample  = wBitsPerSample;
    hleBuf->nBlockAlign     = nBlockAlign;
    hleBuf->refCount        = 1;
    hleBuf->playRegionStart  = 0;
    hleBuf->playRegionLength = 0; // 0 = full buffer
    hleBuf->volume          = 1.0f;
    hleBuf->volumeMillibels = 0;
    hleBuf->headroom        = 0;
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
// Effective volume accounts for headroom: effectiveMB = volumeMB - headroom.
void IDirectSoundBuffer_SetVolume(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    int32_t  lVolume = (int32_t)GuestArg32(ctx, base, 1); // millibels

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetVolume(this=0x%08X, vol=%d mB)\n",
                pThis, lVolume);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->volumeMillibels = lVolume;
            // Effective volume = raw volume - headroom
            int32_t effectiveMB = lVolume - (int32_t)hleBuf->headroom;
            if (effectiveMB <= -10000) {
                hleBuf->volume = 0.0f;
            } else if (effectiveMB >= 0) {
                hleBuf->volume = 1.0f;
            } else {
                hleBuf->volume = powf(10.0f, (float)effectiveMB / 2000.0f);
            }
        }
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

    fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_Play(this=0x%08X, flags=0x%X)%s%s\n",
            pThis, dwFlags,
            (dwFlags & 0x01) ? " LOOPING" : "",
            (dwFlags & 0x02) ? " FROMSTART" : "");

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
            fprintf(stderr, "[HLE-DS]   -> buf found: iface=0x%08X rate=%u playing=true\n",
                    hleBuf->guestIFaceAddr, hleBuf->nSamplesPerSec);
        } else {
            fprintf(stderr, "[HLE-DS]   -> NO BUFFER FOUND for 0x%08X\n", pThis);
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
// Restricts playback to a sub-range of the buffer's audio data.
// Args: pThis, dwPlayStart (byte offset), dwPlayLength (byte count)
void CDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t dwPlayStart  = GuestArg32(ctx, base, 1);
    uint32_t dwPlayLength = GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetPlayRegion(this=0x%08X, start=%u, len=%u)\n",
            pThis, dwPlayStart, dwPlayLength);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->playRegionStart  = dwPlayStart;
            hleBuf->playRegionLength = dwPlayLength;
            hleBuf->playCursor = 0;
        }
    }

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
// Restricts playback to a sub-range of the buffer's audio data.
// Args: pThis, dwPlayStart (byte offset), dwPlayLength (byte count)
void IDirectSoundBuffer_SetPlayRegion(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t dwPlayStart  = GuestArg32(ctx, base, 1);
    uint32_t dwPlayLength = GuestArg32(ctx, base, 2);

    fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetPlayRegion(this=0x%08X, start=%u, len=%u)\n",
            pThis, dwPlayStart, dwPlayLength);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->playRegionStart  = dwPlayStart;
            hleBuf->playRegionLength = dwPlayLength;
            hleBuf->playCursor = 0;
        }
    }

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
        hleBuf->bufferCacheAddr  = pvBufferData;
        hleBuf->bufferCacheSize  = dwBufferBytes;
        hleBuf->playRegionStart  = 0;  // reset play region to full buffer
        hleBuf->playRegionLength = 0;
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
        hleBuf->bufferCacheAddr  = pvBufferData;
        hleBuf->bufferCacheSize  = dwBufferBytes;
        hleBuf->playRegionStart  = 0;  // reset play region to full buffer
        hleBuf->playRegionLength = 0;
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
//
// On the original Xbox, DirectSoundCreate allocates a CDirectSound object,
// calls its constructor and Initialize, then writes the pointer to
// *ppDirectSound.  The game later uses this as the pThis for member calls.
//
// Many recompiled game functions read internal fields of CDirectSound
// (e.g. a parent pointer at field 0x20, a uint16 refcount at offset 0x02).
// If we don't provide a real guest-side object, those reads hit stale BSS
// memory and the writes (like `inc word [parent+0x02]`) corrupt unrelated
// data -- specifically the RenderWare heap object's type_def pointer.
//
// Fix: allocate a zeroed CDirectSound in the guest HLE heap, set the
// uint16 refcount at offset 0x02 to 1, and write it to *ppDirectSound.
static constexpr uint32_t CDIRECTSOUND_SIZE = 0x100; // generous allocation
void DirectSoundCreate(X86Context& ctx, uint8_t* base)
{
    uint32_t ppDirectSound = GuestArg32(ctx, base, 1); // arg1 = ppDirectSound

    fprintf(stderr, "[HLE-DS] DirectSoundCreate(ppDirectSound=0x%08X)\n", ppDirectSound);

    uint32_t guestDS = g_heap.AllocGuestAligned(CDIRECTSOUND_SIZE, 16);
    if (guestDS) {
        memset(base + guestDS, 0, CDIRECTSOUND_SIZE);
        // Set the uint16 reference count at offset 0x02 to 1.
        X86_MEM_WRITE_u16(base, guestDS + 0x02, 1);
    } else {
        fprintf(stderr, "[HLE-DS]   FAILED: out of guest memory for CDirectSound\n");
    }

    if (ppDirectSound && guestDS)
        X86_MEM_WRITE_u32(base, ppDirectSound, guestDS);

    fprintf(stderr, "[HLE-DS]   -> CDirectSound @ 0x%08X\n", guestDS);

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
// Auto-generated stubs for missing DSOUND functions (from dsound.txt)
// ============================================================================

// sub_2F3F40  (0x002F3F40) -- args=4
void sub_2F3F40(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3F40 (0x002F3F40) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// dsound_operator_new_4  (0x002F3F5F) -- args=4
void dsound_operator_new_4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] dsound_operator_new_4 (0x002F3F5F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F3F70  (0x002F3F70) -- args=0
void sub_2F3F70(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3F70 (0x002F3F70) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F3F92  (0x002F3F92) -- args=0
void sub_2F3F92(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3F92 (0x002F3F92) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F3FA9  (0x002F3FA9) -- args=0
void sub_2F3FA9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3FA9 (0x002F3FA9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F3FCE  (0x002F3FCE) -- args=0
void sub_2F3FCE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3FCE (0x002F3FCE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F3FF9  (0x002F3FF9) -- args=4
void sub_2F3FF9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F3FF9 (0x002F3FF9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F402B  (0x002F402B) -- args=4
void sub_2F402B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F402B (0x002F402B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F4074  (0x002F4074) -- args=0
void sub_2F4074(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4074 (0x002F4074) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F4078  (0x002F4078) -- args=32
void sub_2F4078(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4078 (0x002F4078) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// sub_2F40A1  (0x002F40A1) -- args=32
void sub_2F40A1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F40A1 (0x002F40A1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// sub_2F40D8  (0x002F40D8) -- args=20
void sub_2F40D8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F40D8 (0x002F40D8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F40F8  (0x002F40F8) -- args=28
void sub_2F40F8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F40F8 (0x002F40F8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 28);
}

// sub_2F412C  (0x002F412C) -- args=16
void sub_2F412C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F412C (0x002F412C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F414E  (0x002F414E) -- args=16
void sub_2F414E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F414E (0x002F414E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F4193  (0x002F4193) -- args=12
void sub_2F4193(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4193 (0x002F4193) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F41C2  (0x002F41C2) -- args=0
void sub_2F41C2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F41C2 (0x002F41C2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// DirectSoundUseLightHRTF  (0x002F422D) -- args=0
//
// Per Cxbx-Reloaded: this is a no-op.  Titles call it before
// DirectSoundCreate to request a lightweight HRTF algorithm.
// No action needed; the function is void on Xbox.
void DirectSoundUseLightHRTF(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] DirectSoundUseLightHRTF() -- ignored\n");
    // void return, no stack args
}

// sub_2F4296  (0x002F4296) -- args=4
void sub_2F4296(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4296 (0x002F4296) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// DirectSound_CDirectSound_CDirectSound  (0x002F42B8) -- args=0
void DirectSound_CDirectSound_CDirectSound(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] DirectSound_CDirectSound_CDirectSound (0x002F42B8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F42D5  (0x002F42D5) -- args=0
void sub_2F42D5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F42D5 (0x002F42D5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CDirectSound_GetSpeakerConfig  (0x002F430F) -- args=8
void CDirectSound_GetSpeakerConfig(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_GetSpeakerConfig (0x002F430F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSound_DownloadEffectsImage  (0x002F435C) -- args=20
void CDirectSound_DownloadEffectsImage(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_DownloadEffectsImage (0x002F435C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSound_SetEffectData  (0x002F43C0) -- args=24
// DSP-relative function; not emulated (matches Cxbx LOG_NOT_SUPPORTED).
void CDirectSound_SetEffectData(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t dwEffectIndex = GuestArg32(ctx, base, 1);
    uint32_t dwOffset     = GuestArg32(ctx, base, 2);
    uint32_t pvData       = GuestArg32(ctx, base, 3);
    uint32_t dwDataSize   = GuestArg32(ctx, base, 4);
    uint32_t dwApply      = GuestArg32(ctx, base, 5);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSound_SetEffectData(this=0x%08X, idx=%u, off=%u, data=0x%08X, size=%u, apply=%u) -- DSP not supported\n",
                pThis, dwEffectIndex, dwOffset, pvData, dwDataSize, dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 24);
}

// CDirectSound_GetEffectData  (0x002F4422) -- args=20
void CDirectSound_GetEffectData(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_GetEffectData (0x002F4422) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSound_CommitEffectData  (0x002F4481) -- args=4
void CDirectSound_CommitEffectData(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_CommitEffectData (0x002F4481) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSound_SetMixBinHeadroom  (0x002F44D1) -- args=12
void CDirectSound_SetMixBinHeadroom(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetMixBinHeadroom (0x002F44D1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_SynchPlayback  (0x002F4576) -- args=4
void CDirectSound_SynchPlayback(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SynchPlayback (0x002F4576) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSound_EnableHeadphones  (0x002F45F4) -- args=8
void CDirectSound_EnableHeadphones(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_EnableHeadphones (0x002F45F4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoiceSettings_SetMixBinVolumes  (0x002F470F) -- args=4
void CDirectSoundVoiceSettings_SetMixBinVolumes(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoiceSettings_SetMixBinVolumes (0x002F470F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F4734  (0x002F4734) -- args=4
void sub_2F4734(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4734 (0x002F4734) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F47A2  (0x002F47A2) -- args=0
void sub_2F47A2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F47A2 (0x002F47A2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CDirectSoundVoice_SetPitch  (0x002F47EF) -- args=8
void CDirectSoundVoice_SetPitch(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetPitch (0x002F47EF) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_SetHeadroom  (0x002F4824) -- args=8
// Internal CDirectSoundVoice method -- headroom is a voice-level property.
// We don't track per-voice state separately, so just log and return DS_OK.
void CDirectSoundVoice_SetHeadroom(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t dwHeadroom = GuestArg32(ctx, base, 1);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetHeadroom(this=0x%08X, headroom=%u mB)\n",
                pThis, dwHeadroom);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_SetMixBinVolumes  (0x002F4847) -- args=8
void CDirectSoundVoice_SetMixBinVolumes(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetMixBinVolumes (0x002F4847) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F4875  (0x002F4875) -- args=8
void sub_2F4875(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4875 (0x002F4875) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F494A  (0x002F494A) -- args=0
void sub_2F494A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F494A (0x002F494A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F497D  (0x002F497D) -- args=4
void sub_2F497D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F497D (0x002F497D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F49C4  (0x002F49C4) -- args=4
void sub_2F49C4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F49C4 (0x002F49C4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundBuffer_StopEx  (0x002F4AAE) -- args=16
void CDirectSoundBuffer_StopEx(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_StopEx (0x002F4AAE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F4C83  (0x002F4C83) -- args=0
void sub_2F4C83(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F4C83 (0x002F4C83) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CDirectSoundStream_AddRef  (0x002F4CC1) -- args=4
void CDirectSoundStream_AddRef(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_AddRef (0x002F4CC1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundStream_Release  (0x002F4D08) -- args=4
void CDirectSoundStream_Release(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_Release (0x002F4D08) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundStream_GetInfo  (0x002F4D56) -- args=8
void CDirectSoundStream_GetInfo(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_GetInfo (0x002F4D56) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_Discontinuity  (0x002F4DBD) -- args=4
//
// Based on Cxbx-Reloaded EMUPATCH(CDirectSoundStream_Discontinuity).
// Signals a gap in the stream's audio data.  In Cxbx this marks the last
// queued packet as end-of-stream.  In our HLE we clear the pending packet
// count and set a discontinuity flag so subsequent Process calls start fresh.
void CDirectSoundStream_Discontinuity(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            hleSt->pendingPackets = 0;
            hleSt->discontinuity  = true;
        }
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundStream_Discontinuity(this=0x%08X)\n", pThis);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundStream_Flush  (0x002F4E0A) -- args=4
void CDirectSoundStream_Flush(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            hleSt->pcmTotalWritten = 0;
            hleSt->pcmTotalRead    = 0;
            hleSt->pendingPackets  = 0;
        }
    }
    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundStream_Flush(this=0x%08X)\n", pThis);
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundStream_GetStatus  (0x002F4E55) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(CDirectSoundStream_GetStatus__r2).
// Xbox stream status flags (XbDSoundTypes.h):
//   X_DSSSTATUS_READY   = 0x00000001  (packet slot(s) available)
//   X_DSSSTATUS_PLAYING = 0x00010000  (stream is actively playing)
//   X_DSSSTATUS_PAUSED  = 0x00020000  (stream is paused)
// We always report READY since we never fill the packet queue, and
// report PLAYING vs PAUSED based on the tracked pause state.
void CDirectSoundStream_GetStatus(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis     = GuestArg32(ctx, base, 0);
    uint32_t pdwStatus = GuestArg32(ctx, base, 1);

    // X_DSSSTATUS_READY: set when there is at least one free packet slot.
    // Since we complete packets immediately in Process, pendingPackets is always 0
    // (all slots available), so READY is always set.
    uint32_t status = 0x00000001; // X_DSSSTATUS_READY
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            if (hleSt->isPaused) {
                status |= 0x00020000; // X_DSSSTATUS_PAUSED
            } else {
                status |= 0x00010000; // X_DSSSTATUS_PLAYING
            }
        }
    }

    if (pdwStatus) X86_MEM_WRITE_u32(base, pdwStatus, status);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundStream_GetStatus(this=0x%08X) -> 0x%08X\n",
                pThis, status);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_Process  (0x002F4EA6) -- args=12
//
// Based on Cxbx-Reloaded EMUPATCH(CDirectSoundStream_Process).
// Signature: HRESULT CDirectSoundStream_Process(pThis, pInputBuffer, pOutputBuffer)
//
// Guest XMEDIAPACKET layout (32-bit):
//   +0x00 pvBuffer          -- guest ptr to PCM audio data
//   +0x04 dwMaxSize         -- byte count of audio data
//   +0x08 pdwCompletedSize  -- out: guest ptr to DWORD of bytes consumed (nullable)
//   +0x0C pdwStatus         -- out: guest ptr to DWORD XMP_STATUS_* (nullable)
//   +0x10 pContext          -- context pointer (ignored)
//   +0x14 prtTimestamp      -- not supported on Xbox (ignored)
//
// XMP_STATUS values (XbDSoundTypes.h):
//   XMP_STATUS_SUCCESS = 0x00000000 (S_OK)
//   XMP_STATUS_PENDING = 0x8000000A (E_PENDING)
//   XMP_STATUS_FAILURE = 0x80004005 (E_FAIL)
//
// Copy submitted PCM bytes into the stream's ring buffer so the SDL
// audio callback can drain and mix them.  Mark the packet SUCCESS
// immediately so the game can reuse its output buffer for the next block.
void CDirectSoundStream_Process(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis         = GuestArg32(ctx, base, 0);
    uint32_t pInputBuffer  = GuestArg32(ctx, base, 1);
    // pOutputBuffer (arg 2) is reserved (must be NULL on Xbox) -- ignored.

    if (!pInputBuffer) {
        GuestReturn32(ctx, 0); // DS_OK, nothing to submit
        GuestStackCleanup(ctx, 12);
        return;
    }

    // Read guest XMEDIAPACKET fields.
    uint32_t pvBuffer         = X86_MEM_READ_u32(base, pInputBuffer + 0x00);
    uint32_t dwMaxSize        = X86_MEM_READ_u32(base, pInputBuffer + 0x04);
    uint32_t pdwCompletedSize = X86_MEM_READ_u32(base, pInputBuffer + 0x08);
    uint32_t pdwStatus        = X86_MEM_READ_u32(base, pInputBuffer + 0x0C);

    uint32_t bytesAccepted = 0;
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt && !hleSt->pcmRing.empty() && pvBuffer && dwMaxSize > 0) {
            uint32_t ringSize = (uint32_t)hleSt->pcmRing.size();
            uint64_t avail64  = hleSt->pcmTotalWritten - hleSt->pcmTotalRead;
            uint32_t avail    = avail64 > ringSize ? ringSize : (uint32_t)avail64;
            uint32_t space    = ringSize - avail;
            if (space > 1) space -= 1; // 1-byte guard
            uint32_t toCopy   = (dwMaxSize < space) ? dwMaxSize : space;
            if (toCopy > 0) {
                const uint8_t* src = base + pvBuffer;
                uint32_t wrIdx = (uint32_t)(hleSt->pcmTotalWritten % ringSize);
                for (uint32_t done = 0; done < toCopy; ) {
                    uint32_t chunk = std::min(toCopy - done, ringSize - wrIdx);
                    memcpy(hleSt->pcmRing.data() + wrIdx, src + done, chunk);
                    done  += chunk;
                    wrIdx  = (wrIdx + chunk) % ringSize;
                }
                hleSt->pcmTotalWritten += toCopy;
                bytesAccepted = toCopy;
            }
        } else if (pvBuffer && dwMaxSize > 0) {
            bytesAccepted = dwMaxSize;
        }
    }

    // Mark packet SUCCESS immediately so the streaming pump keeps cycling.
    if (pdwStatus)        X86_MEM_WRITE_u32(base, pdwStatus, 0u);              // XMP_STATUS_SUCCESS
    if (pdwCompletedSize) X86_MEM_WRITE_u32(base, pdwCompletedSize, bytesAccepted);

    // Diagnostic: log DSStream throughput
    {
        static uint32_t s_streamBytes = 0;
        static int       s_streamCalls = 0;
        static auto      s_streamStart = std::chrono::steady_clock::now();
        s_streamBytes += bytesAccepted;
        s_streamCalls++;
        auto now = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(now - s_streamStart).count();
        if (elapsed >= 2.0) {
            fprintf(stderr, "[AUDIO-DIAG] DSStream_Process: %u bytes in %.1fs (%.0f B/s, %.1f calls/s) obj=0x%08X rate=%u\n",
                    s_streamBytes, elapsed, s_streamBytes / elapsed, s_streamCalls / elapsed, pThis,
                    [&]() -> uint32_t { std::lock_guard<std::mutex> lk2(g_audioMutex); auto* st = HLE_FindDSStream(pThis); return st ? st->nSamplesPerSec : 0; }());
            s_streamBytes = 0; s_streamCalls = 0; s_streamStart = now;
        }
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundStream_Process(this=0x%08X, buf=0x%08X, size=%u) -> %u bytes\n",
                pThis, pvBuffer, dwMaxSize, bytesAccepted);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundStream_Pause  (0x002F4F1D) -- args=8
// Signature: HRESULT CDirectSoundStream_Pause(pThis, dwPause)
// dwPause values: X_DSSPAUSE_RESUME=0, X_DSSPAUSE_PAUSE=1, X_DSSPAUSE_SYNCHPLAYBACK=2
void CDirectSoundStream_Pause(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    uint32_t dwPause = GuestArg32(ctx, base, 1);
    bool shouldPause = (dwPause == 0x00000001);
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            hleSt->isPaused = shouldPause;
        }
    }
    // Also mute/unmute all WMA bg-decode threads so the radio bg-thread output follows
    // the DSStream pause state (the bg thread is independent of the DSStream ring).
    WmaSetAllDecodersMuted(shouldPause);
    fprintf(stderr, "[HLE-DS] CDirectSoundStream_Pause(this=0x%08X, dwPause=0x%X) -> %s\n",
            pThis, dwPause, shouldPause ? "PAUSE" : "RESUME");
    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// Shared flush-ex implementation used by both the C and I variants.
// Args on stack: pThis(4) + rtTimestamp_lo(4) + rtTimestamp_hi(4) + dwFlags(4) = 16 bytes.
// X_DSSFLUSHEX flags (XbDSoundTypes.h):
//   X_DSSFLUSHEX_IMMEDIATE = 0x00000000  flush all pending packets now
//   X_DSSFLUSHEX_ASYNC     = 0x00000001  schedule async flush at rtTimestamp
//   X_DSSFLUSHEX_ENVELOPE  = 0x00000002  (modify async: extend by envelope release)
//   X_DSSFLUSHEX_ENVELOPE2 = 0x00000004  (modify async: envelope 2 mode)
// Based on Cxbx-Reloaded EMUPATCH(CDirectSoundStream_FlushEx):
//   IMMEDIATE -> flush now -> DS_OK
//   ASYNC     -> schedule (we flush immediately since we have no real packet queue)
//   Otherwise -> DSERR_INVALIDPARAM
static uint32_t HLE_DSStream_FlushEx(uint8_t* base, uint32_t pThis, uint32_t dwFlags)
{
    static constexpr uint32_t DSERR_INVALIDPARAM = 0x80070057;
    static constexpr uint32_t X_DSSFLUSHEX_IMMEDIATE = 0x00000000;
    static constexpr uint32_t X_DSSFLUSHEX_ASYNC     = 0x00000001;

    // Validate: must be IMMEDIATE or must include ASYNC.
    if (dwFlags != X_DSSFLUSHEX_IMMEDIATE && !(dwFlags & X_DSSFLUSHEX_ASYNC)) {
        fprintf(stderr, "[HLE-DS] FlushEx(this=0x%08X, flags=0x%X) -> DSERR_INVALIDPARAM\n",
                pThis, dwFlags);
        return DSERR_INVALIDPARAM;
    }

    // Perform flush (reset PCM ring and pending packet counter).
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            hleSt->pcmTotalWritten = 0;
            hleSt->pcmTotalRead    = 0;
            hleSt->pendingPackets  = 0;
            hleSt->discontinuity   = true; // gap introduced by flush
        }
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] FlushEx(this=0x%08X, flags=0x%X) -> %s\n",
                pThis, dwFlags,
                (dwFlags == X_DSSFLUSHEX_IMMEDIATE) ? "IMMEDIATE" : "ASYNC");
    return 0; // DS_OK
}

// CDirectSoundStream_FlushEx  (0x002F4F6E) -- args=16
void CDirectSoundStream_FlushEx(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    // rtTimestamp (REFERENCE_TIME, 64-bit) in args 1+2 -- not used in our HLE.
    uint32_t dwFlags = GuestArg32(ctx, base, 3);

    uint32_t hr = HLE_DSStream_FlushEx(base, pThis, dwFlags);
    GuestReturn32(ctx, hr);
    GuestStackCleanup(ctx, 16);
}

// sub_2F52B9  (0x002F52B9) -- args=8
void sub_2F52B9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F52B9 (0x002F52B9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F52F0  (0x002F52F0) -- args=4
void sub_2F52F0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F52F0 (0x002F52F0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F52FA  (0x002F52FA) -- args=4
void sub_2F52FA(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F52FA (0x002F52FA) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundBuffer_SetHeadroom  (0x002F536E) -- args=8
// Signature: HRESULT CDirectSoundBuffer_SetHeadroom(pThis, dwHeadroom)
void CDirectSoundBuffer_SetHeadroom(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t dwHeadroom = GuestArg32(ctx, base, 1);

    if (dwHeadroom > 10000) {
        if (!g_dsound_quiet)
            fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetHeadroom(this=0x%08X, headroom=%u) -> DSERR_INVALIDPARAM\n",
                    pThis, dwHeadroom);
        GuestReturn32(ctx, 0x88780064); // DSERR_INVALIDPARAM
        GuestStackCleanup(ctx, 8);
        return;
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetHeadroom(this=0x%08X, headroom=%u mB)\n",
                pThis, dwHeadroom);

    // CDirectSoundBuffer passes the full object pointer; derive the IFace addr.
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->headroom = dwHeadroom;
            int32_t effectiveMB = hleBuf->volumeMillibels - (int32_t)dwHeadroom;
            if (effectiveMB <= -10000) {
                hleBuf->volume = 0.0f;
            } else if (effectiveMB >= 0) {
                hleBuf->volume = 1.0f;
            } else {
                hleBuf->volume = powf(10.0f, (float)effectiveMB / 2000.0f);
            }
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetMixBinVolumes  (0x002F53BC) -- args=8
void CDirectSoundBuffer_SetMixBinVolumes(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetMixBinVolumes (0x002F53BC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_SetVolume  (0x002F540A) -- args=8
void CDirectSoundStream_SetVolume(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_SetVolume (0x002F540A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_SetHeadroom  (0x002F545C) -- args=8
void CDirectSoundStream_SetHeadroom(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_SetHeadroom (0x002F545C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_SetMixBinVolumes_8  (0x002F54AE) -- args=8
void CDirectSoundStream_SetMixBinVolumes_8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_SetMixBinVolumes_8 (0x002F54AE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSound_GetSpeakerConfig  (0x002F5500) -- args=8
void IDirectSound_GetSpeakerConfig(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSound_GetSpeakerConfig (0x002F5500) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSound_DownloadEffectsImage  (0x002F551C) -- args=20
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_DownloadEffectsImage).
// Signature: HRESULT IDirectSound_DownloadEffectsImage(
//   pThis, pvImageBuffer, dwImageSize, pImageLoc, ppImageDesc)
//
// The DSP effects image is not used since we don't emulate the MCPX APU
// DSP pipeline.  However, ppImageDesc must be written with a non-null
// pointer if provided, because some games dereference it later.
void IDirectSound_DownloadEffectsImage(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis          = GuestArg32(ctx, base, 0);
    uint32_t pvImageBuffer  = GuestArg32(ctx, base, 1);
    uint32_t dwImageSize    = GuestArg32(ctx, base, 2);
    uint32_t pImageLoc      = GuestArg32(ctx, base, 3);
    uint32_t ppImageDesc    = GuestArg32(ctx, base, 4);

    fprintf(stderr, "[HLE-DS] IDirectSound_DownloadEffectsImage(this=0x%08X, buf=0x%08X, "
                    "size=%u, loc=0x%08X, ppDesc=0x%08X)\n",
            pThis, pvImageBuffer, dwImageSize, pImageLoc, ppImageDesc);

    // Allocate a minimal DSEFFECTIMAGEDESC in guest memory.
    // Layout: { DWORD dwEffectCount; DWORD dwMixBinCount; ... }
    // We provide a zeroed-out desc so the game sees 0 effects.
    if (ppImageDesc) {
        static constexpr uint32_t DESC_SIZE = 8; // dwEffectCount + dwMixBinCount
        uint32_t descAddr = g_heap.AllocGuestAligned(DESC_SIZE, 16);
        if (descAddr) {
            memset(base + descAddr, 0, DESC_SIZE);
            X86_MEM_WRITE_u32(base, ppImageDesc, descAddr);
        } else {
            X86_MEM_WRITE_u32(base, ppImageDesc, 0);
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSound_GetEffectData  (0x002F5543) -- args=20
void IDirectSound_GetEffectData(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSound_GetEffectData (0x002F5543) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSound_SetEffectData  (0x002F556A) -- args=24
//
// Based on Cxbx-Reloaded's EMUPATCH(IDirectSound_SetEffectData).
// Signature: HRESULT IDirectSound_SetEffectData(pThis, dwEffectIndex, dwOffset, pvData, dwDataSize, dwApply)
// This is a DSP-relative function.  The Xbox DSP effects processor is not
// emulated, so we log the parameters and return DS_OK, matching Cxbx.
void IDirectSound_SetEffectData(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis        = GuestArg32(ctx, base, 0);
    uint32_t dwEffectIndex = GuestArg32(ctx, base, 1);
    uint32_t dwOffset     = GuestArg32(ctx, base, 2);
    uint32_t pvData       = GuestArg32(ctx, base, 3);
    uint32_t dwDataSize   = GuestArg32(ctx, base, 4);
    uint32_t dwApply      = GuestArg32(ctx, base, 5);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetEffectData(this=0x%08X, idx=%u, off=%u, data=0x%08X, size=%u, apply=%u) -- DSP not supported\n",
                pThis, dwEffectIndex, dwOffset, pvData, dwDataSize, dwApply);

    // NOTE: DSP effects are not emulated (matches Cxbx LOG_NOT_SUPPORTED).
    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 24);
}

// IDirectSound_CommitEffectData  (0x002F5594) -- args=4
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_CommitEffectData).
// Signature: HRESULT IDirectSound_CommitEffectData(pThis)
// This is a DSP-relative function.  On real hardware it commits pending
// effect parameter changes to the APU's GP DSP.  Since we don't emulate
// the Xbox DSP, this is a no-op that returns DS_OK.
void IDirectSound_CommitEffectData(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_CommitEffectData(this=0x%08X)\n", pThis);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 4);
}

// IDirectSound_EnableHeadphones  (0x002F55AC) -- args=8
void IDirectSound_EnableHeadphones(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSound_EnableHeadphones (0x002F55AC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSound_SetMixBinHeadroom  (0x002F55C8) -- args=12
void IDirectSound_SetMixBinHeadroom(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSound_SetMixBinHeadroom (0x002F55C8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSound_SynchPlayback  (0x002F5608) -- args=4
void IDirectSound_SynchPlayback(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSound_SynchPlayback (0x002F5608) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// IDirectSoundBuffer_SetHeadroom  (0x002F563C) -- args=8
//
// Based on Cxbx-Reloaded's EMUPATCH(IDirectSoundBuffer_SetHeadroom).
// Signature: HRESULT IDirectSoundBuffer_SetHeadroom(pThis, dwHeadroom)
// dwHeadroom is in millibels (0 = no attenuation, 10000 = max attenuation).
// The effective volume is: volumeMillibels - headroom, clamped to [-10000, 0].
void IDirectSoundBuffer_SetHeadroom(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t dwHeadroom = GuestArg32(ctx, base, 1);

    // Validate: headroom must be in [0, 10000] (DSERR_INVALIDPARAM otherwise)
    if (dwHeadroom > 10000) {
        if (!g_dsound_quiet)
            fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetHeadroom(this=0x%08X, headroom=%u) -> DSERR_INVALIDPARAM\n",
                    pThis, dwHeadroom);
        GuestReturn32(ctx, 0x88780064); // DSERR_INVALIDPARAM
        GuestStackCleanup(ctx, 8);
        return;
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetHeadroom(this=0x%08X, headroom=%u mB)\n",
                pThis, dwHeadroom);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->headroom = dwHeadroom;
            // Recalculate effective linear volume from stored millibels and headroom.
            int32_t effectiveMB = hleBuf->volumeMillibels - (int32_t)dwHeadroom;
            if (effectiveMB <= -10000) {
                hleBuf->volume = 0.0f;
            } else if (effectiveMB >= 0) {
                hleBuf->volume = 1.0f;
            } else {
                hleBuf->volume = powf(10.0f, (float)effectiveMB / 2000.0f);
            }
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetMixBinVolumes  (0x002F5658) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSoundBuffer_SetMixBinVolumes_8).
// Signature: HRESULT IDirectSoundBuffer_SetMixBinVolumes(pThis, pMixBins)
//
// pMixBins points to a guest X_DSMIXBINS struct:
//   +0x00: DWORD dwCount
//   +0x04: X_DSMIXBINVOLUMEPAIR* lpMixBinVolumePairs
// Each volume pair:
//   +0x00: DWORD dwMixBin
//   +0x04: LONG  lVolume   (millibels, 0 = full, -10000 = silence)
//
// Since we can't do per-channel mix bin routing, we pick the loudest
// (max) non-LFE volume across all bins and use that as the effective
// mix-bin volume adjustment, matching Cxbx-Reloaded's approach.
static constexpr uint32_t XDSMIXBIN_LOW_FREQUENCY = 4;
static constexpr uint32_t XDSMIXBIN_SPEAKERS_MAX  = 8;

void IDirectSoundBuffer_SetMixBinVolumes(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis     = GuestArg32(ctx, base, 0);
    uint32_t pMixBins  = GuestArg32(ctx, base, 1);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetMixBinVolumes(this=0x%08X, pMixBins=0x%08X)\n",
                pThis, pMixBins);

    if (pMixBins) {
        uint32_t dwCount = X86_MEM_READ_u32(base, pMixBins + 0x00);
        uint32_t pPairs  = X86_MEM_READ_u32(base, pMixBins + 0x04);

        // Find the loudest non-LFE speaker volume (Cxbx approach).
        int32_t maxVolume = -10000; // DSBVOLUME_MIN
        if (pPairs && dwCount > 0) {
            for (uint32_t i = 0; i < dwCount; i++) {
                uint32_t dwMixBin = X86_MEM_READ_u32(base, pPairs + i * 8 + 0x00);
                int32_t  lVolume  = (int32_t)X86_MEM_READ_u32(base, pPairs + i * 8 + 0x04);
                // Skip LFE and non-speaker bins.
                if (dwMixBin != XDSMIXBIN_LOW_FREQUENCY && dwMixBin < XDSMIXBIN_SPEAKERS_MAX) {
                    if (lVolume > maxVolume)
                        maxVolume = lVolume;
                }
            }
        }

        // Apply the dominant mix-bin volume to the buffer's effective volume.
        {
            std::lock_guard<std::mutex> lk(g_audioMutex);
            HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
            if (hleBuf) {
                // Effective = base volume - headroom + mixbin volume adjustment
                int32_t effectiveMB = hleBuf->volumeMillibels - (int32_t)hleBuf->headroom + maxVolume;
                if (effectiveMB <= -10000) {
                    hleBuf->volume = 0.0f;
                } else if (effectiveMB >= 0) {
                    hleBuf->volume = 1.0f;
                } else {
                    hleBuf->volume = powf(10.0f, (float)effectiveMB / 2000.0f);
                }
            }
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_StopEx  (0x002F56B0) -- args=16
// Signature: StopEx(pThis, rtTimeStamp:REFERENCE_TIME[8], dwFlags[4]) = 16 bytes
// rtTimeStamp==0 / dwFlags==0 means immediate stop (same as Stop).
void IDirectSoundBuffer_StopEx(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBuffer(pThis);
        if (hleBuf) {
            hleBuf->isPlaying = false;
        }
    }

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// IDirectSoundStream_SetVolume  (0x002F574C) -- args=8
// Signature: HRESULT IDirectSoundStream_SetVolume(pThis, lVolume)
void IDirectSoundStream_SetVolume(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    int32_t  lVolume = (int32_t)GuestArg32(ctx, base, 1);

    HLE_DSStream* stream = HLE_FindDSStream(pThis);
    if (stream) {
        stream->volumeMillibels = lVolume;
        // Convert millibels to linear: 10^(mB / 2000)
        if (lVolume <= -10000)
            stream->volume = 0.0f;
        else if (lVolume >= 0)
            stream->volume = 1.0f;
        else
            stream->volume = powf(10.0f, (float)lVolume / 2000.0f);
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetVolume(this=0x%08X, vol=%d mB)\n",
                pThis, lVolume);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundStream_SetHeadroom  (0x002F5751) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSoundStream_SetHeadroom).
// Signature: HRESULT IDirectSoundStream_SetHeadroom(pThis, dwHeadroom)
// Headroom is 0..10000 millibels of attenuation applied on top of volume.
void IDirectSoundStream_SetHeadroom(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t dwHeadroom = GuestArg32(ctx, base, 1);

    if (dwHeadroom > 10000) {
        if (!g_dsound_quiet)
            fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetHeadroom(this=0x%08X, headroom=%u) "
                            "-> DSERR_INVALIDPARAM\n", pThis, dwHeadroom);
        GuestReturn32(ctx, 0x88780064); // DSERR_INVALIDPARAM
        GuestStackCleanup(ctx, 8);
        return;
    }

    HLE_DSStream* stream = HLE_FindDSStream(pThis);
    if (stream)
        stream->headroom = dwHeadroom;

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetHeadroom(this=0x%08X, headroom=%u mB)\n",
                pThis, dwHeadroom);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundStream_SetMixBinVolumes  (0x002F5756) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSoundStream_SetMixBinVolumes).
// Signature: HRESULT IDirectSoundStream_SetMixBinVolumes(pThis, pMixBins)
// Mix bin volumes control per-speaker attenuation.  Since we output plain
// stereo via SDL, we accept the call and return DS_OK.
void IDirectSoundStream_SetMixBinVolumes(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t pMixBins = GuestArg32(ctx, base, 1);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetMixBinVolumes(this=0x%08X, mixBins=0x%08X)\n",
                pThis, pMixBins);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundStream_Pause  (0x002F575B) -- args=8
//
// Thin thunk forwarding to CDirectSoundStream_Pause logic.
// Signature: HRESULT IDirectSoundStream_Pause(pThis, dwPause)
// dwPause values (XbDSoundTypes.h):
//   X_DSSPAUSE_RESUME        = 0x00000000
//   X_DSSPAUSE_PAUSE         = 0x00000001
//   X_DSSPAUSE_SYNCHPLAYBACK = 0x00000002  (resume, synced)
void IDirectSoundStream_Pause(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    uint32_t dwPause = GuestArg32(ctx, base, 1);

    // X_DSSPAUSE_PAUSE (1) sets paused; all other values (RESUME/SYNCHPLAYBACK) clear it.
    bool shouldPause = (dwPause == 0x00000001);

    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
        if (hleSt) {
            hleSt->isPaused = shouldPause;
        }
    }

    // Also mute/unmute all WMA bg-decode threads so the radio bg-thread output follows
    // the DSStream pause state (the bg thread is independent of the DSStream ring).
    WmaSetAllDecodersMuted(shouldPause);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundStream_Pause(this=0x%08X, dwPause=0x%X) -> %s\n",
                pThis, dwPause, shouldPause ? "PAUSE" : "RESUME");

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundStream_FlushEx  (0x002F5760) -- args=16
// Thin thunk forwarding to CDirectSoundStream_FlushEx logic.
void IDirectSoundStream_FlushEx(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    // rtTimestamp (REFERENCE_TIME, 64-bit) in args 1+2 -- not used in our HLE.
    uint32_t dwFlags = GuestArg32(ctx, base, 3);

    uint32_t hr = HLE_DSStream_FlushEx(base, pThis, dwFlags);
    GuestReturn32(ctx, hr);
    GuestStackCleanup(ctx, 16);
}

// DirectSoundDoWork  (0x002F5778) -- args=0
//
// Based on Cxbx-Reloaded EMUPATCH(DirectSoundDoWork).
// On real hardware this processes pending buffer unlocks and advances
// stream packet processing.  In our HLE backend the SDL audio callback
// handles playback advancement, so this is effectively a no-op.
// We keep it lightweight since the game calls this every frame.
void DirectSoundDoWork(X86Context& ctx, uint8_t* base)
{
    // No-op: SDL audio callback handles buffer playback.
    // Stream packet processing would go here if we implement
    // stream callbacks in the future.
    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F57A1  (0x002F57A1) -- args=4
void sub_2F57A1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F57A1 (0x002F57A1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F57BC  (0x002F57BC) -- args=4
void sub_2F57BC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F57BC (0x002F57BC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F5887  (0x002F5887) -- args=4
void sub_2F5887(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F5887 (0x002F5887) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F595A  (0x002F595A) -- args=4
void sub_2F595A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F595A (0x002F595A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F5984  (0x002F5984) -- args=4
void sub_2F5984(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F5984 (0x002F5984) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F599F  (0x002F599F) -- args=12
void sub_2F599F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F599F (0x002F599F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundVoice_SetFrequency  (0x002F5A36) -- args=8
void CDirectSoundVoice_SetFrequency(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis  = GuestArg32(ctx, base, 0);
    uint32_t dwFreq = GuestArg32(ctx, base, 1);

    static int s_freqLogCountVoice = 0;

    if (dwFreq != 0) {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBufferAny(pThis);
        if (hleBuf) {
            hleBuf->nSamplesPerSec = dwFreq;
            if (s_freqLogCountVoice < 40) {
                fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetFrequency(this=0x%08X -> iface=0x%08X, freq=%u)\n",
                        pThis, hleBuf->guestIFaceAddr, dwFreq);
                s_freqLogCountVoice++;
            }
        } else if (s_freqLogCountVoice < 40) {
            fprintf(stderr, "[HLE-DS] CDirectSoundVoice_SetFrequency(this=0x%08X, freq=%u) -> NO MATCH\n",
                    pThis, dwFreq);
            s_freqLogCountVoice++;
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_SetOutputBuffer  (0x002F5A5A) -- args=8
void CDirectSoundVoice_SetOutputBuffer(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetOutputBuffer (0x002F5A5A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_SetMixBins  (0x002F5AAE) -- args=8
void CDirectSoundVoice_SetMixBins(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetMixBins (0x002F5AAE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundVoice_SetAllParameters  (0x002F5ACB) -- args=12
void CDirectSoundVoice_SetAllParameters(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetAllParameters (0x002F5ACB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundVoice_SetRolloffCurve  (0x002F5C03) -- args=16
void CDirectSoundVoice_SetRolloffCurve(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetRolloffCurve (0x002F5C03) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// CDirectSoundVoice_SetI3DL2Source  (0x002F5C46) -- args=12
void CDirectSoundVoice_SetI3DL2Source(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundVoice_SetI3DL2Source (0x002F5C46) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F5D10  (0x002F5D10) -- args=8
void sub_2F5D10(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F5D10 (0x002F5D10) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F5D34  (0x002F5D34) -- args=4
void sub_2F5D34(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F5D34 (0x002F5D34) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F5D4C  (0x002F5D4C) -- args=4
void sub_2F5D4C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F5D4C (0x002F5D4C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundBuffer_SetFrequency  (0x002F5E02) -- args=8
void CDirectSoundBuffer_SetFrequency(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis  = GuestArg32(ctx, base, 0);
    uint32_t dwFreq = GuestArg32(ctx, base, 1);

    static int s_freqLogCountBuffer = 0;

    if (dwFreq != 0) {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBufferAny(pThis);
        if (hleBuf) {
            hleBuf->nSamplesPerSec = dwFreq;
            if (s_freqLogCountBuffer < 40) {
                fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetFrequency(this=0x%08X -> iface=0x%08X, freq=%u)\n",
                        pThis, hleBuf->guestIFaceAddr, dwFreq);
                s_freqLogCountBuffer++;
            }
        } else if (s_freqLogCountBuffer < 40) {
            fprintf(stderr, "[HLE-DS] CDirectSoundBuffer_SetFrequency(this=0x%08X, freq=%u) -> NO MATCH\n",
                    pThis, dwFreq);
            s_freqLogCountBuffer++;
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetOutputBuffer  (0x002F5E50) -- args=8
void CDirectSoundBuffer_SetOutputBuffer(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetOutputBuffer (0x002F5E50) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetMixBins  (0x002F5E9E) -- args=8
void CDirectSoundBuffer_SetMixBins(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetMixBins (0x002F5E9E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundBuffer_SetAllParameters  (0x002F5EEC) -- args=12
void CDirectSoundBuffer_SetAllParameters(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetAllParameters (0x002F5EEC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundBuffer_SetRolloffCurve  (0x002F5F3E) -- args=16
void CDirectSoundBuffer_SetRolloffCurve(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetRolloffCurve (0x002F5F3E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// CDirectSoundBuffer_SetI3DL2Source  (0x002F5F94) -- args=12
void CDirectSoundBuffer_SetI3DL2Source(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundBuffer_SetI3DL2Source (0x002F5F94) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSoundStream_SetMixBins  (0x002F5FE6) -- args=8
void CDirectSoundStream_SetMixBins(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_SetMixBins (0x002F5FE6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetFrequency  (0x002F6038) -- args=8
void IDirectSoundBuffer_SetFrequency(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis  = GuestArg32(ctx, base, 0);
    uint32_t dwFreq = GuestArg32(ctx, base, 1);

    static int s_freqLogCountIface = 0;

    if (dwFreq != 0) {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        HLE_DSBuffer* hleBuf = HLE_FindDSBufferAny(pThis);
        if (hleBuf) {
            hleBuf->nSamplesPerSec = dwFreq;
            // All 44100Hz content in this game is stereo WMA-decoded music.
            // The buffer may be created mono from descriptor, but the actual
            // data from SetBufferData is stereo. Fix channel count here.
            if (dwFreq == 44100 && hleBuf->nChannels == 1) {
                hleBuf->nChannels = 2;
                hleBuf->nBlockAlign = 4; // 2 channels * 16-bit = 4 bytes
            }
            if (s_freqLogCountIface < 40) {
                fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetFrequency(this=0x%08X -> iface=0x%08X, freq=%u, ch=%u)\n",
                        pThis, hleBuf->guestIFaceAddr, dwFreq, hleBuf->nChannels);
                s_freqLogCountIface++;
            }
        } else if (s_freqLogCountIface < 40) {
            fprintf(stderr, "[HLE-DS] IDirectSoundBuffer_SetFrequency(this=0x%08X, freq=%u) -> NO MATCH\n",
                    pThis, dwFreq);
            s_freqLogCountIface++;
        }
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetOutputBuffer  (0x002F6054) -- args=8
//
// Routes the buffer's output through another DirectSoundBuffer (3D controller
// requirement).  Not possible in our SDL2 HLE -- returns S_OK per Cxbx
// LOG_NOT_SUPPORTED pattern.  Test case: MultiPass sample / Burnout 3.
void IDirectSoundBuffer_SetOutputBuffer(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetMixBins  (0x002F6070) -- args=8
//
// Configures which MCPX APU mix bins the buffer feeds into.  Mix-bin routing
// is Xbox-specific hardware and is not emulated in our SDL2 backend.
// Returns S_OK to match Cxbx-Reloaded HybridDirectSoundBuffer_SetMixBins
// behaviour when running without hardware APU support.
void IDirectSoundBuffer_SetMixBins(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundBuffer_SetAllParameters  (0x002F608C) -- args=12
void IDirectSoundBuffer_SetAllParameters(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSoundBuffer_SetAllParameters (0x002F608C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSoundBuffer_SetRolloffCurve  (0x002F60AC) -- args=16
void IDirectSoundBuffer_SetRolloffCurve(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSoundBuffer_SetRolloffCurve (0x002F60AC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// IDirectSoundBuffer_SetI3DL2Source  (0x002F60D0) -- args=12
void IDirectSoundBuffer_SetI3DL2Source(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] IDirectSoundBuffer_SetI3DL2Source (0x002F60D0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSoundStream_SetMixBins  (0x002F6110) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSoundStream_SetMixBins).
// Signature: HRESULT IDirectSoundStream_SetMixBins(pThis, mixBins)
// Configures which output mix bins (speakers) the stream routes to.
// Since we output plain stereo via SDL, we accept and return DS_OK.
void IDirectSoundStream_SetMixBins(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    uint32_t mixBins = GuestArg32(ctx, base, 1);

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetMixBins(this=0x%08X, mixBins=0x%08X)\n",
                pThis, mixBins);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F6115  (0x002F6115) -- args=4
void sub_2F6115(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6115 (0x002F6115) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F61DE  (0x002F61DE) -- args=0
void sub_2F61DE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F61DE (0x002F61DE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F622B  (0x002F622B) -- args=8
void sub_2F622B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F622B (0x002F622B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CDirectSoundStream_Constructor  (0x002F642F) -- args=4
void CDirectSoundStream_Constructor(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_Constructor (0x002F642F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSoundStream_SetFormat  (0x002F66E2) -- args=8
void CDirectSoundStream_SetFormat(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSoundStream_SetFormat (0x002F66E2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSoundStream_SetFormat  (0x002F6770) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSoundBuffer_SetFormat).
// Signature: HRESULT IDirectSoundStream_SetFormat(pThis, lpwfxFormat)
// Updates the stream's audio format from the supplied WAVEFORMATEX.
void IDirectSoundStream_SetFormat(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0);
    uint32_t lpwfxFormat = GuestArg32(ctx, base, 1);

    if (lpwfxFormat) {
        uint16_t wFormatTag     = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_wFormatTag);
        uint16_t nChannels      = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_nChannels);
        uint32_t nSamplesPerSec = X86_MEM_READ_u32(base, lpwfxFormat + XWAVEFORMATEX_nSamplesPerSec);
        uint16_t nBlockAlign    = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_nBlockAlign);
        uint16_t wBitsPerSample = X86_MEM_READ_u16(base, lpwfxFormat + XWAVEFORMATEX_wBitsPerSample);

        {
            std::lock_guard<std::mutex> lk(g_audioMutex);
            HLE_DSStream* hleSt = HLE_FindDSStream(pThis);
            if (hleSt) {
                hleSt->wFormatTag     = wFormatTag;
                hleSt->nChannels      = nChannels;
                hleSt->nSamplesPerSec = nSamplesPerSec;
                hleSt->nBlockAlign    = nBlockAlign;
                hleSt->wBitsPerSample = wBitsPerSample;
            }
        }

        if (!g_dsound_quiet)
            fprintf(stderr, "[HLE-DS] IDirectSoundStream_SetFormat(this=0x%08X, fmt=%u, ch=%u, rate=%u, bits=%u)\n",
                    pThis, wFormatTag, nChannels, nSamplesPerSec, wBitsPerSample);
    }

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F6775  (0x002F6775) -- args=0
void sub_2F6775(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6775 (0x002F6775) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CDirectSound_CommitDeferredSettings  (0x002F6804) -- args=4
void CDirectSound_CommitDeferredSettings(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_CommitDeferredSettings (0x002F6804) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F689E  (0x002F689E) -- args=4
void sub_2F689E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F689E (0x002F689E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F68B9  (0x002F68B9) -- args=12
void sub_2F68B9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F68B9 (0x002F68B9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F69BB  (0x002F69BB) -- args=0
void sub_2F69BB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F69BB (0x002F69BB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F69E0  (0x002F69E0) -- args=4
void sub_2F69E0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F69E0 (0x002F69E0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F6A45  (0x002F6A45) -- args=8
void sub_2F6A45(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6A45 (0x002F6A45) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F6B2C  (0x002F6B2C) -- args=4
void sub_2F6B2C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6B2C (0x002F6B2C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F6B4D  (0x002F6B4D) -- args=4
void sub_2F6B4D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6B4D (0x002F6B4D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F6B86  (0x002F6B86) -- args=8
void sub_2F6B86(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F6B86 (0x002F6B86) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// IDirectSound_CommitDeferredSettings  (0x002F6C30) -- args=4
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_CommitDeferredSettings).
// Signature: HRESULT IDirectSound_CommitDeferredSettings(pThis)
// Commits any 3D listener/buffer settings that were applied with
// DS3D_DEFERRED.  Since we store parameters immediately, this is a no-op.
void IDirectSound_CommitDeferredSettings(X86Context& ctx, uint8_t* base)
{
    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_CommitDeferredSettings(this=0x%08X)\n",
                GuestArg32(ctx, base, 0));

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 4);
}

// CDirectSound_CreateSoundStream  (0x002F6CE4) -- args=16
void CDirectSound_CreateSoundStream(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_CreateSoundStream (0x002F6CE4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// CDirectSound_SetDistanceFactor  (0x002F6D75) -- args=12
void CDirectSound_SetDistanceFactor(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetDistanceFactor (0x002F6D75) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_SetDopplerFactor  (0x002F6DD4) -- args=12
void CDirectSound_SetDopplerFactor(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetDopplerFactor (0x002F6DD4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_SetRolloffFactor  (0x002F6E33) -- args=12
void CDirectSound_SetRolloffFactor(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetRolloffFactor (0x002F6E33) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// CDirectSound_SetOrientation  (0x002F6E92) -- args=32
void CDirectSound_SetOrientation(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetOrientation (0x002F6E92) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// CDirectSound_SetPosition  (0x002F6F1F) -- args=20
void CDirectSound_SetPosition(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetPosition (0x002F6F1F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSound_SetVelocity  (0x002F6F92) -- args=20
void CDirectSound_SetVelocity(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetVelocity (0x002F6F92) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// CDirectSound_SetI3DL2Listener  (0x002F7005) -- args=12
void CDirectSound_SetI3DL2Listener(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CDirectSound_SetI3DL2Listener (0x002F7005) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F710D  (0x002F710D) -- args=4
void sub_2F710D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F710D (0x002F710D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// IDirectSound_SetDistanceFactor  (0x002F714C) -- args=12
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetDistanceFactor).
// Signature: HRESULT IDirectSound_SetDistanceFactor(pThis, fDistanceFactor, dwApply)
// fDistanceFactor is a float passed by value on the stack.
// Sets the distance factor for 3D audio calculations.
void IDirectSound_SetDistanceFactor(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t rawFloat = GuestArg32(ctx, base, 1);
    uint32_t dwApply  = GuestArg32(ctx, base, 2);
    float fDistanceFactor;
    memcpy(&fDistanceFactor, &rawFloat, sizeof(float));

    g_listenerDistanceFactor = fDistanceFactor;

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetDistanceFactor(this=0x%08X, factor=%.3f, apply=%u)\n",
                pThis, fDistanceFactor, dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSound_SetDopplerFactor  (0x002F7170) -- args=12
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetDopplerFactor).
// Signature: HRESULT IDirectSound_SetDopplerFactor(pThis, fDopplerFactor, dwApply)
// fDopplerFactor is a float passed by value on the stack.
void IDirectSound_SetDopplerFactor(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t rawFloat = GuestArg32(ctx, base, 1);
    uint32_t dwApply  = GuestArg32(ctx, base, 2);
    float fDopplerFactor;
    memcpy(&fDopplerFactor, &rawFloat, sizeof(float));

    g_listenerDopplerFactor = fDopplerFactor;

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetDopplerFactor(this=0x%08X, factor=%.3f, apply=%u)\n",
                pThis, fDopplerFactor, dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSound_SetOrientation  (0x002F7194) -- args=32
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetOrientation).
// Signature: HRESULT IDirectSound_SetOrientation(pThis,
//   xFront, yFront, zFront, xTop, yTop, zTop, dwApply)
// All float args are passed by value on the stack.
void IDirectSound_SetOrientation(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    float vals[6];
    for (int i = 0; i < 6; i++) {
        uint32_t raw = GuestArg32(ctx, base, 1 + i);
        memcpy(&vals[i], &raw, sizeof(float));
    }
    uint32_t dwApply = GuestArg32(ctx, base, 7);

    g_listenerOrientFront[0] = vals[0];
    g_listenerOrientFront[1] = vals[1];
    g_listenerOrientFront[2] = vals[2];
    g_listenerOrientTop[0]   = vals[3];
    g_listenerOrientTop[1]   = vals[4];
    g_listenerOrientTop[2]   = vals[5];

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetOrientation(this=0x%08X, "
                        "front=(%.2f,%.2f,%.2f), top=(%.2f,%.2f,%.2f), apply=%u)\n",
                pThis, vals[0], vals[1], vals[2],
                vals[3], vals[4], vals[5], dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 32);
}

// IDirectSound_SetPosition  (0x002F71DE) -- args=20
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetPosition).
// Signature: HRESULT IDirectSound_SetPosition(pThis, x, y, z, dwApply)
// All float args passed by value on the stack.
void IDirectSound_SetPosition(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    float xyz[3];
    for (int i = 0; i < 3; i++) {
        uint32_t raw = GuestArg32(ctx, base, 1 + i);
        memcpy(&xyz[i], &raw, sizeof(float));
    }
    uint32_t dwApply = GuestArg32(ctx, base, 4);

    g_listenerPosition[0] = xyz[0];
    g_listenerPosition[1] = xyz[1];
    g_listenerPosition[2] = xyz[2];

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetPosition(this=0x%08X, "
                        "pos=(%.2f,%.2f,%.2f), apply=%u)\n",
                pThis, xyz[0], xyz[1], xyz[2], dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSound_SetRolloffFactor  (0x002F7213) -- args=12
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetRolloffFactor).
// Signature: HRESULT IDirectSound_SetRolloffFactor(pThis, fRolloffFactor, dwApply)
// fRolloffFactor is a float passed by value on the stack.
// Controls how quickly sounds attenuate with distance.
void IDirectSound_SetRolloffFactor(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis    = GuestArg32(ctx, base, 0);
    uint32_t rawFloat = GuestArg32(ctx, base, 1);
    uint32_t dwApply  = GuestArg32(ctx, base, 2);
    float fRolloffFactor;
    memcpy(&fRolloffFactor, &rawFloat, sizeof(float));

    g_listenerRolloffFactor = fRolloffFactor;

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetRolloffFactor(this=0x%08X, factor=%.3f, apply=%u)\n",
                pThis, fRolloffFactor, dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// IDirectSound_SetVelocity  (0x002F7237) -- args=20
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetVelocity).
// Signature: HRESULT IDirectSound_SetVelocity(pThis, x, y, z, dwApply)
void IDirectSound_SetVelocity(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    float xyz[3];
    for (int i = 0; i < 3; i++) {
        uint32_t raw = GuestArg32(ctx, base, 1 + i);
        memcpy(&xyz[i], &raw, sizeof(float));
    }
    uint32_t dwApply = GuestArg32(ctx, base, 4);

    g_listenerVelocity[0] = xyz[0];
    g_listenerVelocity[1] = xyz[1];
    g_listenerVelocity[2] = xyz[2];

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetVelocity(this=0x%08X, "
                        "vel=(%.2f,%.2f,%.2f), apply=%u)\n",
                pThis, xyz[0], xyz[1], xyz[2], dwApply);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 20);
}

// IDirectSound_SetI3DL2Listener  (0x002F726C) -- args=12
//
// Based on Cxbx-Reloaded EMUPATCH(IDirectSound_SetI3DL2Listener).
// Signature: HRESULT IDirectSound_SetI3DL2Listener(pThis, pds3dl, dwApply)
// pds3dl points to a guest X_DSI3DL2LISTENER struct (48 bytes):
//   +0x00: LONG  lRoom
//   +0x04: LONG  lRoomHF
//   +0x08: FLOAT flRoomRolloffFactor
//   +0x0C: FLOAT flDecayTime
//   +0x10: FLOAT flDecayHFRatio
//   +0x14: LONG  lReflections
//   +0x18: FLOAT flReflectionsDelay
//   +0x1C: LONG  lReverb
//   +0x20: FLOAT flReverbDelay
//   +0x24: FLOAT flDiffusion
//   +0x28: FLOAT flDensity
//   +0x2C: FLOAT flHFReference
//
// This is DSP-relative (reverb processing).  Since we don't emulate the
// Xbox GP DSP, we store the parameters for completeness but don't apply
// reverb effects, matching Cxbx-Reloaded's LOG_NOT_SUPPORTED approach.
void IDirectSound_SetI3DL2Listener(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis   = GuestArg32(ctx, base, 0);
    uint32_t pds3dl  = GuestArg32(ctx, base, 1);
    uint32_t dwApply = GuestArg32(ctx, base, 2);

    if (pds3dl) {
        auto readFloat = [&](uint32_t off) -> float {
            uint32_t raw = X86_MEM_READ_u32(base, pds3dl + off);
            float f; memcpy(&f, &raw, sizeof(float)); return f;
        };
        g_i3dl2Listener.lRoom               = (int32_t)X86_MEM_READ_u32(base, pds3dl + 0x00);
        g_i3dl2Listener.lRoomHF             = (int32_t)X86_MEM_READ_u32(base, pds3dl + 0x04);
        g_i3dl2Listener.flRoomRolloffFactor = readFloat(0x08);
        g_i3dl2Listener.flDecayTime         = readFloat(0x0C);
        g_i3dl2Listener.flDecayHFRatio      = readFloat(0x10);
        g_i3dl2Listener.lReflections        = (int32_t)X86_MEM_READ_u32(base, pds3dl + 0x14);
        g_i3dl2Listener.flReflectionsDelay  = readFloat(0x18);
        g_i3dl2Listener.lReverb             = (int32_t)X86_MEM_READ_u32(base, pds3dl + 0x1C);
        g_i3dl2Listener.flReverbDelay       = readFloat(0x20);
        g_i3dl2Listener.flDiffusion         = readFloat(0x24);
        g_i3dl2Listener.flDensity           = readFloat(0x28);
        g_i3dl2Listener.flHFReference       = readFloat(0x2C);
    }

    if (!g_dsound_quiet)
        fprintf(stderr, "[HLE-DS] IDirectSound_SetI3DL2Listener(this=0x%08X, pds3dl=0x%08X, apply=%u) "
                        "[room=%d roomHF=%d decay=%.2f]\n",
                pThis, pds3dl, dwApply,
                g_i3dl2Listener.lRoom, g_i3dl2Listener.lRoomHF,
                g_i3dl2Listener.flDecayTime);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 12);
}

// DirectSound_CDirectSound_Initialize  (0x002F728C) -- args=4
void DirectSound_CDirectSound_Initialize(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] DirectSound_CDirectSound_Initialize (0x002F728C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F73C5  (0x002F73C5) -- args=4
void sub_2F73C5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F73C5 (0x002F73C5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// DirectSoundCreateStream  (0x002F7479) -- args=8
//
// Based on Cxbx-Reloaded EMUPATCH(DirectSoundCreateStream).
// Signature: HRESULT DirectSoundCreateStream(X_DSSTREAMDESC* pdssd,
//                                            X_CDirectSoundStream** ppStream)
// Build (once) a guest-side IDirectSoundStream vtable so that recompiled code
// that dispatches via vtable[N] lands on a valid g_funcMap entry.
static uint32_t EnsureStreamVtbl(uint8_t* base)
{
    if (g_streamVtblAddr) return g_streamVtblAddr;
    g_streamVtblAddr = g_heap.AllocGuestAligned(10 * 4, 4);
    if (!g_streamVtblAddr) {
        fprintf(stderr, "[HLE-DS] FAILED to allocate stream vtable\n");
        return 0;
    }
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x00, 0x2F4CC1u); // [0] AddRef
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x04, 0x2F4D08u); // [1] Release
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x08, 0x2F4D56u); // [2] GetInfo
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x0C, 0x2F4E55u); // [3] GetStatus
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x10, 0x2F4EA6u); // [4] Process
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x14, 0x2F4DBDu); // [5] Discontinuity
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x18, 0x2F4E0Au); // [6] Flush
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x1C, 0x2F4F6Eu); // [7] FlushEx
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x20, 0x2F4F1Du); // [8] Pause
    X86_MEM_WRITE_u32(base, g_streamVtblAddr + 0x24, 0x2F66E2u); // [9] SetFormat
    fprintf(stderr, "[HLE-DS] Stream vtable @ 0x%08X\n", g_streamVtblAddr);
    return g_streamVtblAddr;
}

//
// Allocates a guest stream object and host-side tracking structure,
// reads the audio format from the stream descriptor, and returns
// the stream pointer through ppStream.
void DirectSoundCreateStream(X86Context& ctx, uint8_t* base)
{
    uint32_t pdssd    = GuestArg32(ctx, base, 0);
    uint32_t ppStream = GuestArg32(ctx, base, 1);

    // Read stream descriptor fields
    uint32_t dwFlags   = 0;
    uint32_t dwMaxPkts = 0;
    uint32_t lpwfxFormat = 0;
    if (pdssd) {
        dwFlags    = X86_MEM_READ_u32(base, pdssd + XDSSTREAMDESC_dwFlags);
        dwMaxPkts  = X86_MEM_READ_u32(base, pdssd + XDSSTREAMDESC_dwMaxAttachedPkts);
        lpwfxFormat= X86_MEM_READ_u32(base, pdssd + XDSSTREAMDESC_lpwfxFormat);
    }

    // Read WAVEFORMATEX
    uint16_t wFormatTag     = 1; // PCM
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

    fprintf(stderr, "[HLE-DS] DirectSoundCreateStream(pdssd=0x%08X, ppStream=0x%08X)\n"
                    "         flags=0x%X, maxPkts=%u, fmt=%u, ch=%u, rate=%u, bits=%u\n",
            pdssd, ppStream, dwFlags, dwMaxPkts,
            wFormatTag, nChannels, nSamplesPerSec, wBitsPerSample);

    // Allocate a minimal guest stream object
    uint32_t guestObj = g_heap.AllocGuestAligned(DSSTREAM_OBJ_SIZE, 16);
    if (!guestObj) {
        fprintf(stderr, "[HLE-DS]   FAILED: out of guest memory for stream object\n");
        if (ppStream) X86_MEM_WRITE_u32(base, ppStream, 0);
        GuestReturn32(ctx, 0x8007000E); // DSERR_OUTOFMEMORY
        GuestStackCleanup(ctx, 8);
        return;
    }
    memset(base + guestObj, 0, DSSTREAM_OBJ_SIZE);

    // Install guest-side vtable so vtable[3] (GetStatus) dispatch doesn't miss.
    // Without this the vtable ptr is 0, causing the dispatch to read from guest
    // address 0x0000000C (fs:[0x0C] / SubSystemTib), which the Xbox CRT sets to
    // 0x879000 (a BSS address not in g_funcMap).
    uint32_t vtblAddr = EnsureStreamVtbl(base);
    if (vtblAddr)
        X86_MEM_WRITE_u32(base, guestObj + 0x00, vtblAddr);

    // Set refcount at offset 0x04 (matching DSBUFFER_S convention)
    X86_MEM_WRITE_u32(base, guestObj + 0x04, 1);

    // Create host-side tracking
    HLE_DSStream* hleStream = new HLE_DSStream{};
    hleStream->guestObjAddr       = guestObj;
    hleStream->dwFlags            = dwFlags;
    hleStream->dwMaxAttachedPackets = dwMaxPkts;
    hleStream->wFormatTag         = wFormatTag;
    hleStream->nChannels          = nChannels;
    hleStream->nSamplesPerSec     = nSamplesPerSec;
    hleStream->wBitsPerSample     = wBitsPerSample;
    hleStream->nBlockAlign        = nBlockAlign;
    hleStream->refCount           = 1;
    hleStream->volume             = 1.0f;
    hleStream->volumeMillibels    = 0;
    hleStream->headroom           = 0;

    // Allocate ring buffer: 2 seconds of audio at the stream's native PCM format
    if ((wBitsPerSample == 8 || wBitsPerSample == 16) && nSamplesPerSec > 0 && nChannels > 0) {
        uint32_t ringBytes = nSamplesPerSec * nChannels * (wBitsPerSample / 8) * 2;
        hleStream->pcmRing.assign(ringBytes, 0);
    }
    {
        std::lock_guard<std::mutex> lk(g_audioMutex);
        g_dsStreams.push_back(hleStream);
    }

    HLE_EnsureAudioInit(base);

    if (ppStream)
        X86_MEM_WRITE_u32(base, ppStream, guestObj);

    fprintf(stderr, "[HLE-DS]   -> stream obj @ 0x%08X\n", guestObj);

    GuestReturn32(ctx, 0); // DS_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F7517  (0x002F7517) -- args=4
void sub_2F7517(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7517 (0x002F7517) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F752F  (0x002F752F) -- args=16
void sub_2F752F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F752F (0x002F752F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F757E  (0x002F757E) -- args=4
void sub_2F757E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F757E (0x002F757E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F7596  (0x002F7596) -- args=12
void sub_2F7596(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7596 (0x002F7596) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F75FE  (0x002F75FE) -- args=4
void sub_2F75FE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F75FE (0x002F75FE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F7632  (0x002F7632) -- args=8
void sub_2F7632(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7632 (0x002F7632) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F765B  (0x002F765B) -- args=8
void sub_2F765B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F765B (0x002F765B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F7682  (0x002F7682) -- args=8
void sub_2F7682(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7682 (0x002F7682) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F76CB  (0x002F76CB) -- args=8
void sub_2F76CB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F76CB (0x002F76CB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F770E  (0x002F770E) -- args=0
void sub_2F770E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F770E (0x002F770E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// sub_2F7719  (0x002F7719) -- args=0
void sub_2F7719(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7719 (0x002F7719) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// sub_2F7724  (0x002F7724) -- args=4
void sub_2F7724(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7724 (0x002F7724) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F774B  (0x002F774B) -- args=4
void sub_2F774B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F774B (0x002F774B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F7782  (0x002F7782) -- args=4
void sub_2F7782(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7782 (0x002F7782) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F77CB  (0x002F77CB) -- args=12
void sub_2F77CB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F77CB (0x002F77CB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F7808  (0x002F7808) -- args=12
void sub_2F7808(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7808 (0x002F7808) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F789E  (0x002F789E) -- args=20
void sub_2F789E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F789E (0x002F789E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F78E9  (0x002F78E9) -- args=32
void sub_2F78E9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F78E9 (0x002F78E9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// sub_2F79FA  (0x002F79FA) -- args=20
void sub_2F79FA(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F79FA (0x002F79FA) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F7A8A  (0x002F7A8A) -- args=16
void sub_2F7A8A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7A8A (0x002F7A8A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F7B03  (0x002F7B03) -- args=20
void sub_2F7B03(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7B03 (0x002F7B03) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F7B3D  (0x002F7B3D) -- args=32
void sub_2F7B3D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7B3D (0x002F7B3D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// sub_2F7C25  (0x002F7C25) -- args=28
void sub_2F7C25(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7C25 (0x002F7C25) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 28);
}

// CLightHRTFSource_GetCenterVolume  (0x002F7CDC) -- args=16
void CLightHRTFSource_GetCenterVolume(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CLightHRTFSource_GetCenterVolume (0x002F7CDC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F7D45  (0x002F7D45) -- args=16
void sub_2F7D45(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7D45 (0x002F7D45) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// CHRTFSource_SetLightHRTF5Channel  (0x002F7DBF) -- args=0
void CHRTFSource_SetLightHRTF5Channel(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CHRTFSource_SetLightHRTF5Channel (0x002F7DBF) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F7E2E  (0x002F7E2E) -- args=0
void sub_2F7E2E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7E2E (0x002F7E2E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F7E4D  (0x002F7E4D) -- args=0
void sub_2F7E4D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7E4D (0x002F7E4D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F7EC2  (0x002F7EC2) -- args=4
void sub_2F7EC2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F7EC2 (0x002F7EC2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8037  (0x002F8037) -- args=8
void sub_2F8037(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8037 (0x002F8037) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F805E  (0x002F805E) -- args=8
void sub_2F805E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F805E (0x002F805E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F80C3  (0x002F80C3) -- args=8
void sub_2F80C3(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F80C3 (0x002F80C3) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F80D7  (0x002F80D7) -- args=8
void sub_2F80D7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F80D7 (0x002F80D7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F80EE  (0x002F80EE) -- args=0
void sub_2F80EE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F80EE (0x002F80EE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F812F  (0x002F812F) -- args=12
void sub_2F812F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F812F (0x002F812F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F81C8  (0x002F81C8) -- args=20
void sub_2F81C8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F81C8 (0x002F81C8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F8271  (0x002F8271) -- args=16
void sub_2F8271(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8271 (0x002F8271) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F82AB  (0x002F82AB) -- args=8
void sub_2F82AB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F82AB (0x002F82AB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F82D5  (0x002F82D5) -- args=4
void sub_2F82D5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F82D5 (0x002F82D5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F836D  (0x002F836D) -- args=0
void sub_2F836D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F836D (0x002F836D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F83D0  (0x002F83D0) -- args=4
void sub_2F83D0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F83D0 (0x002F83D0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8461  (0x002F8461) -- args=4
void sub_2F8461(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8461 (0x002F8461) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F84CE  (0x002F84CE) -- args=0
void sub_2F84CE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F84CE (0x002F84CE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8531  (0x002F8531) -- args=0
void sub_2F8531(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8531 (0x002F8531) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F85AA  (0x002F85AA) -- args=4
void sub_2F85AA(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F85AA (0x002F85AA) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F85D6  (0x002F85D6) -- args=0
void sub_2F85D6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F85D6 (0x002F85D6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8644  (0x002F8644) -- args=4
void sub_2F8644(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8644 (0x002F8644) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8694  (0x002F8694) -- args=4
void sub_2F8694(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8694 (0x002F8694) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F86B9  (0x002F86B9) -- args=4
void sub_2F86B9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F86B9 (0x002F86B9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F871B  (0x002F871B) -- args=0
void sub_2F871B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F871B (0x002F871B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F882F  (0x002F882F) -- args=4
void sub_2F882F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F882F (0x002F882F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F88AB  (0x002F88AB) -- args=0
void sub_2F88AB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F88AB (0x002F88AB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8904  (0x002F8904) -- args=4
void sub_2F8904(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8904 (0x002F8904) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F892B  (0x002F892B) -- args=4
void sub_2F892B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F892B (0x002F892B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxAPU_SynchPlayback  (0x002F893C) -- args=0
void CMcpxAPU_SynchPlayback(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxAPU_SynchPlayback (0x002F893C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8A7B  (0x002F8A7B) -- args=0
void sub_2F8A7B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8A7B (0x002F8A7B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8B32  (0x002F8B32) -- args=16
void sub_2F8B32(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8B32 (0x002F8B32) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F8B3E  (0x002F8B3E) -- args=4
void sub_2F8B3E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8B3E (0x002F8B3E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8B5A  (0x002F8B5A) -- args=0
void sub_2F8B5A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8B5A (0x002F8B5A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8C05  (0x002F8C05) -- args=0
void sub_2F8C05(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8C05 (0x002F8C05) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8C47  (0x002F8C47) -- args=8
void sub_2F8C47(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8C47 (0x002F8C47) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F8C5D  (0x002F8C5D) -- args=4
void sub_2F8C5D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8C5D (0x002F8C5D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8CA1  (0x002F8CA1) -- args=16
void sub_2F8CA1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8CA1 (0x002F8CA1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F8CC8  (0x002F8CC8) -- args=0
void sub_2F8CC8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8CC8 (0x002F8CC8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8D0F  (0x002F8D0F) -- args=4
void sub_2F8D0F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8D0F (0x002F8D0F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8DE5  (0x002F8DE5) -- args=0
void sub_2F8DE5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8DE5 (0x002F8DE5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8E3A  (0x002F8E3A) -- args=4
void sub_2F8E3A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8E3A (0x002F8E3A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8E81  (0x002F8E81) -- args=8
void sub_2F8E81(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8E81 (0x002F8E81) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F8E8D  (0x002F8E8D) -- args=0
void sub_2F8E8D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8E8D (0x002F8E8D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F8F7F  (0x002F8F7F) -- args=4
void sub_2F8F7F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8F7F (0x002F8F7F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F8F9D  (0x002F8F9D) -- args=20
void sub_2F8F9D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8F9D (0x002F8F9D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2F8FE1  (0x002F8FE1) -- args=8
void sub_2F8FE1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8FE1 (0x002F8FE1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F8FFC  (0x002F8FFC) -- args=4
void sub_2F8FFC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F8FFC (0x002F8FFC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F901A  (0x002F901A) -- args=4
void sub_2F901A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F901A (0x002F901A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9033  (0x002F9033) -- args=4
void sub_2F9033(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9033 (0x002F9033) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9055  (0x002F9055) -- args=0
void sub_2F9055(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9055 (0x002F9055) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F906D  (0x002F906D) -- args=0
void sub_2F906D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F906D (0x002F906D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxStream_Stop  (0x002F9114) -- args=4
void CMcpxStream_Stop(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_Stop (0x002F9114) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxStream_GetStatus  (0x002F9186) -- args=4
void CMcpxStream_GetStatus(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_GetStatus (0x002F9186) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F91E0  (0x002F91E0) -- args=0
void sub_2F91E0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F91E0 (0x002F91E0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F920D  (0x002F920D) -- args=8
void sub_2F920D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F920D (0x002F920D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F9370  (0x002F9370) -- args=4
void sub_2F9370(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9370 (0x002F9370) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9445  (0x002F9445) -- args=8
void sub_2F9445(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9445 (0x002F9445) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F9491  (0x002F9491) -- args=0
void sub_2F9491(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9491 (0x002F9491) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F94D1  (0x002F94D1) -- args=16
void sub_2F94D1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F94D1 (0x002F94D1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F9500  (0x002F9500) -- args=4
void sub_2F9500(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9500 (0x002F9500) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// DirectSound_AddRef_DirectSound_CDirectSound  (0x002F951A) -- args=4
void DirectSound_AddRef_DirectSound_CDirectSound(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] DirectSound_AddRef_DirectSound_CDirectSound (0x002F951A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F952F  (0x002F952F) -- args=8
void sub_2F952F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F952F (0x002F952F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CMcpxStream_Stop_Ex  (0x002F95DA) -- args=12
void CMcpxStream_Stop_Ex(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_Stop_Ex (0x002F95DA) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F9613  (0x002F9613) -- args=4
void sub_2F9613(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9613 (0x002F9613) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F967A  (0x002F967A) -- args=8
void sub_2F967A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F967A (0x002F967A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F96F0  (0x002F96F0) -- args=0
void sub_2F96F0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F96F0 (0x002F96F0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxStream_Discontinuity  (0x002F9718) -- args=0
void CMcpxStream_Discontinuity(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_Discontinuity (0x002F9718) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9745  (0x002F9745) -- args=8
void sub_2F9745(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9745 (0x002F9745) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// CMcpxStream_Flush  (0x002F9808) -- args=4
void CMcpxStream_Flush(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_Flush (0x002F9808) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F98E8  (0x002F98E8) -- args=0
void sub_2F98E8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F98E8 (0x002F98E8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F98F8  (0x002F98F8) -- args=0
void sub_2F98F8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F98F8 (0x002F98F8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F99DC  (0x002F99DC) -- args=0
void sub_2F99DC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F99DC (0x002F99DC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9A64  (0x002F9A64) -- args=0
void sub_2F9A64(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9A64 (0x002F9A64) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9AC1  (0x002F9AC1) -- args=0
void sub_2F9AC1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9AC1 (0x002F9AC1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9BB0  (0x002F9BB0) -- args=4
void sub_2F9BB0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9BB0 (0x002F9BB0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// CMcpxStream_Pause  (0x002F9C7E) -- args=4
void CMcpxStream_Pause(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxStream_Pause (0x002F9C7E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9D0C  (0x002F9D0C) -- args=8
void sub_2F9D0C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9D0C (0x002F9D0C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2F9D57  (0x002F9D57) -- args=4
void sub_2F9D57(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9D57 (0x002F9D57) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9D72  (0x002F9D72) -- args=4
void sub_2F9D72(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9D72 (0x002F9D72) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9DE9  (0x002F9DE9) -- args=4
void sub_2F9DE9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9DE9 (0x002F9DE9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9E07  (0x002F9E07) -- args=16
void sub_2F9E07(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9E07 (0x002F9E07) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2F9E3D  (0x002F9E3D) -- args=12
void sub_2F9E3D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9E3D (0x002F9E3D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2F9E64  (0x002F9E64) -- args=0
void sub_2F9E64(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9E64 (0x002F9E64) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9E84  (0x002F9E84) -- args=0
void sub_2F9E84(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9E84 (0x002F9E84) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2F9EA6  (0x002F9EA6) -- args=4
void sub_2F9EA6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9EA6 (0x002F9EA6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2F9F31  (0x002F9F31) -- args=8
void sub_2F9F31(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2F9F31 (0x002F9F31) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA002  (0x002FA002) -- args=8
void sub_2FA002(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA002 (0x002FA002) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA023  (0x002FA023) -- args=12
void sub_2FA023(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA023 (0x002FA023) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FA090  (0x002FA090) -- args=8
void sub_2FA090(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA090 (0x002FA090) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA0A7  (0x002FA0A7) -- args=0
void sub_2FA0A7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA0A7 (0x002FA0A7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA0CC  (0x002FA0CC) -- args=0
void sub_2FA0CC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA0CC (0x002FA0CC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA12D  (0x002FA12D) -- args=12
void sub_2FA12D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA12D (0x002FA12D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FA1B1  (0x002FA1B1) -- args=4
void sub_2FA1B1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA1B1 (0x002FA1B1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA292  (0x002FA292) -- args=8
void sub_2FA292(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA292 (0x002FA292) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA2AD  (0x002FA2AD) -- args=4
void sub_2FA2AD(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA2AD (0x002FA2AD) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA2C8  (0x002FA2C8) -- args=8
void sub_2FA2C8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA2C8 (0x002FA2C8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA357  (0x002FA357) -- args=4
void sub_2FA357(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA357 (0x002FA357) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA3B3  (0x002FA3B3) -- args=4
void sub_2FA3B3(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA3B3 (0x002FA3B3) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA3CE  (0x002FA3CE) -- args=4
void sub_2FA3CE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA3CE (0x002FA3CE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA467  (0x002FA467) -- args=4
void sub_2FA467(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA467 (0x002FA467) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA4B2  (0x002FA4B2) -- args=0
void sub_2FA4B2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4B2 (0x002FA4B2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// sub_2FA4BD  (0x002FA4BD) -- args=0
void sub_2FA4BD(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4BD (0x002FA4BD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// sub_2FA4C8  (0x002FA4C8) -- args=0
void sub_2FA4C8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4C8 (0x002FA4C8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA4CC  (0x002FA4CC) -- args=0
void sub_2FA4CC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4CC (0x002FA4CC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA4D0  (0x002FA4D0) -- args=16
void sub_2FA4D0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4D0 (0x002FA4D0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FA4F2  (0x002FA4F2) -- args=0
void sub_2FA4F2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA4F2 (0x002FA4F2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA50E  (0x002FA50E) -- args=4
void sub_2FA50E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA50E (0x002FA50E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA559  (0x002FA559) -- args=0
void sub_2FA559(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA559 (0x002FA559) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA66C  (0x002FA66C) -- args=0
void sub_2FA66C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA66C (0x002FA66C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FA6F4  (0x002FA6F4) -- args=8
void sub_2FA6F4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA6F4 (0x002FA6F4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FA7A5  (0x002FA7A5) -- args=4
void sub_2FA7A5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA7A5 (0x002FA7A5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FA9F9  (0x002FA9F9) -- args=4
void sub_2FA9F9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FA9F9 (0x002FA9F9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FAA7B  (0x002FAA7B) -- args=8
void sub_2FAA7B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FAA7B (0x002FAA7B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FAAEF  (0x002FAAEF) -- args=4
void sub_2FAAEF(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FAAEF (0x002FAAEF) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FACCB  (0x002FACCB) -- args=0
void sub_2FACCB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FACCB (0x002FACCB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FAD30  (0x002FAD30) -- args=0
void sub_2FAD30(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FAD30 (0x002FAD30) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FADB4  (0x002FADB4) -- args=0
void sub_2FADB4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FADB4 (0x002FADB4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FAE08  (0x002FAE08) -- args=4
void sub_2FAE08(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FAE08 (0x002FAE08) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FAEEE  (0x002FAEEE) -- args=8
void sub_2FAEEE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FAEEE (0x002FAEEE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FB1A7  (0x002FB1A7) -- args=0
void sub_2FB1A7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB1A7 (0x002FB1A7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FB232  (0x002FB232) -- args=8
void sub_2FB232(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB232 (0x002FB232) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FB250  (0x002FB250) -- args=4
void sub_2FB250(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB250 (0x002FB250) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FB267  (0x002FB267) -- args=0
void sub_2FB267(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB267 (0x002FB267) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FB5CC  (0x002FB5CC) -- args=0
void sub_2FB5CC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB5CC (0x002FB5CC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FB5E8  (0x002FB5E8) -- args=0
void sub_2FB5E8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB5E8 (0x002FB5E8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FB651  (0x002FB651) -- args=8
void sub_2FB651(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB651 (0x002FB651) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FB6B6  (0x002FB6B6) -- args=4
void sub_2FB6B6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB6B6 (0x002FB6B6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FB875  (0x002FB875) -- args=0
void sub_2FB875(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB875 (0x002FB875) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FB982  (0x002FB982) -- args=0
void sub_2FB982(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FB982 (0x002FB982) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FBA89  (0x002FBA89) -- args=0
void sub_2FBA89(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBA89 (0x002FBA89) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FBAC1  (0x002FBAC1) -- args=0
void sub_2FBAC1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBAC1 (0x002FBAC1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FBC8D  (0x002FBC8D) -- args=4
void sub_2FBC8D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBC8D (0x002FBC8D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FBCA8  (0x002FBCA8) -- args=4
void sub_2FBCA8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBCA8 (0x002FBCA8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FBD1A  (0x002FBD1A) -- args=0
void sub_2FBD1A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBD1A (0x002FBD1A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FBD5D  (0x002FBD5D) -- args=4
void sub_2FBD5D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBD5D (0x002FBD5D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FBE9E  (0x002FBE9E) -- args=8
void sub_2FBE9E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FBE9E (0x002FBE9E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FC1B1  (0x002FC1B1) -- args=0
void sub_2FC1B1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC1B1 (0x002FC1B1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC1F8  (0x002FC1F8) -- args=8
void sub_2FC1F8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC1F8 (0x002FC1F8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FC259  (0x002FC259) -- args=0
void sub_2FC259(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC259 (0x002FC259) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC293  (0x002FC293) -- args=16
void sub_2FC293(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC293 (0x002FC293) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FC2C2  (0x002FC2C2) -- args=4
void sub_2FC2C2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC2C2 (0x002FC2C2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FC2DC  (0x002FC2DC) -- args=8
void sub_2FC2DC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC2DC (0x002FC2DC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FC338  (0x002FC338) -- args=0
void sub_2FC338(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC338 (0x002FC338) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC39D  (0x002FC39D) -- args=0
void sub_2FC39D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC39D (0x002FC39D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC3EF  (0x002FC3EF) -- args=0
void sub_2FC3EF(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC3EF (0x002FC3EF) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC48E  (0x002FC48E) -- args=0
void sub_2FC48E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC48E (0x002FC48E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC58C  (0x002FC58C) -- args=0
void sub_2FC58C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC58C (0x002FC58C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC5D7  (0x002FC5D7) -- args=0
void sub_2FC5D7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC5D7 (0x002FC5D7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC77B  (0x002FC77B) -- args=0
void sub_2FC77B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC77B (0x002FC77B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC7B9  (0x002FC7B9) -- args=0
void sub_2FC7B9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC7B9 (0x002FC7B9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC806  (0x002FC806) -- args=0
void sub_2FC806(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC806 (0x002FC806) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// CMcpxBuffer_Stop_Ex  (0x002FC85E) -- args=12
void CMcpxBuffer_Stop_Ex(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] CMcpxBuffer_Stop_Ex (0x002FC85E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FC897  (0x002FC897) -- args=0
void sub_2FC897(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC897 (0x002FC897) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC8B2  (0x002FC8B2) -- args=0
void sub_2FC8B2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC8B2 (0x002FC8B2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FC8EF  (0x002FC8EF) -- args=4
void sub_2FC8EF(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC8EF (0x002FC8EF) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FC920  (0x002FC920) -- args=8
void sub_2FC920(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC920 (0x002FC920) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FC96F  (0x002FC96F) -- args=4
void sub_2FC96F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC96F (0x002FC96F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FC98A  (0x002FC98A) -- args=4
void sub_2FC98A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC98A (0x002FC98A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FC993  (0x002FC993) -- args=4
void sub_2FC993(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC993 (0x002FC993) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FC9E1  (0x002FC9E1) -- args=4
void sub_2FC9E1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FC9E1 (0x002FC9E1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCA6F  (0x002FCA6F) -- args=4
void sub_2FCA6F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCA6F (0x002FCA6F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCAA8  (0x002FCAA8) -- args=4
void sub_2FCAA8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCAA8 (0x002FCAA8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCAC6  (0x002FCAC6) -- args=4
void sub_2FCAC6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCAC6 (0x002FCAC6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCAFE  (0x002FCAFE) -- args=4
void sub_2FCAFE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCAFE (0x002FCAFE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCB98  (0x002FCB98) -- args=4
void sub_2FCB98(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCB98 (0x002FCB98) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FCC15  (0x002FCC15) -- args=0
void sub_2FCC15(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCC15 (0x002FCC15) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FCC62  (0x002FCC62) -- args=24
void sub_2FCC62(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCC62 (0x002FCC62) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 24);
}

// sub_2FCD1F  (0x002FCD1F) -- args=16
void sub_2FCD1F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCD1F (0x002FCD1F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FCDAB  (0x002FCDAB) -- args=8
void sub_2FCDAB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCDAB (0x002FCDAB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FCE0C  (0x002FCE0C) -- args=20
void sub_2FCE0C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCE0C (0x002FCE0C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2FCEB7  (0x002FCEB7) -- args=32
void sub_2FCEB7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCEB7 (0x002FCEB7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 32);
}

// sub_2FCFE6  (0x002FCFE6) -- args=12
void sub_2FCFE6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FCFE6 (0x002FCFE6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FD0D0  (0x002FD0D0) -- args=8
void sub_2FD0D0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD0D0 (0x002FD0D0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FD458  (0x002FD458) -- args=4
void sub_2FD458(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD458 (0x002FD458) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FD472  (0x002FD472) -- args=0
void sub_2FD472(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD472 (0x002FD472) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FD4A0  (0x002FD4A0) -- args=4
void sub_2FD4A0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD4A0 (0x002FD4A0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FD553  (0x002FD553) -- args=12
void sub_2FD553(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD553 (0x002FD553) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FD5A5  (0x002FD5A5) -- args=12
void sub_2FD5A5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD5A5 (0x002FD5A5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FD5CD  (0x002FD5CD) -- args=4
void sub_2FD5CD(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD5CD (0x002FD5CD) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FD6A5  (0x002FD6A5) -- args=16
void sub_2FD6A5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD6A5 (0x002FD6A5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FD71E  (0x002FD71E) -- args=4
void sub_2FD71E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD71E (0x002FD71E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FD74B  (0x002FD74B) -- args=20
void sub_2FD74B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD74B (0x002FD74B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 20);
}

// sub_2FD81A  (0x002FD81A) -- args=0
void sub_2FD81A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD81A (0x002FD81A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FD8ED  (0x002FD8ED) -- args=0
void sub_2FD8ED(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FD8ED (0x002FD8ED) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FDA2C  (0x002FDA2C) -- args=0
void sub_2FDA2C(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDA2C (0x002FDA2C) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FDBD0  (0x002FDBD0) -- args=0
void sub_2FDBD0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDBD0 (0x002FDBD0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FDC89  (0x002FDC89) -- args=4
void sub_2FDC89(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDC89 (0x002FDC89) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FDCC0  (0x002FDCC0) -- args=4
void sub_2FDCC0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDCC0 (0x002FDCC0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FDCF7  (0x002FDCF7) -- args=4
void sub_2FDCF7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDCF7 (0x002FDCF7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FDD52  (0x002FDD52) -- args=4
void sub_2FDD52(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDD52 (0x002FDD52) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FDDB4  (0x002FDDB4) -- args=16
void sub_2FDDB4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDDB4 (0x002FDDB4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FDE2B  (0x002FDE2B) -- args=12
void sub_2FDE2B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDE2B (0x002FDE2B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FDE68  (0x002FDE68) -- args=12
void sub_2FDE68(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDE68 (0x002FDE68) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FDEA7  (0x002FDEA7) -- args=0
void sub_2FDEA7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDEA7 (0x002FDEA7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FDF21  (0x002FDF21) -- args=0
void sub_2FDF21(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDF21 (0x002FDF21) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FDF4D  (0x002FDF4D) -- args=4
void sub_2FDF4D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDF4D (0x002FDF4D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FDF70  (0x002FDF70) -- args=0
void sub_2FDF70(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FDF70 (0x002FDF70) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE015  (0x002FE015) -- args=0
void sub_2FE015(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE015 (0x002FE015) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE0E2  (0x002FE0E2) -- args=0
void sub_2FE0E2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE0E2 (0x002FE0E2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE262  (0x002FE262) -- args=4
void sub_2FE262(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE262 (0x002FE262) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE33F  (0x002FE33F) -- args=4
void sub_2FE33F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE33F (0x002FE33F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE35A  (0x002FE35A) -- args=0
void sub_2FE35A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE35A (0x002FE35A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE3D7  (0x002FE3D7) -- args=0
void sub_2FE3D7(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE3D7 (0x002FE3D7) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE443  (0x002FE443) -- args=0
void sub_2FE443(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE443 (0x002FE443) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE44B  (0x002FE44B) -- args=0
void sub_2FE44B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE44B (0x002FE44B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE478  (0x002FE478) -- args=0
void sub_2FE478(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE478 (0x002FE478) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE4C8  (0x002FE4C8) -- args=0
void sub_2FE4C8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE4C8 (0x002FE4C8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE4DC  (0x002FE4DC) -- args=8
void sub_2FE4DC(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE4DC (0x002FE4DC) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FE4F9  (0x002FE4F9) -- args=0
void sub_2FE4F9(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE4F9 (0x002FE4F9) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE511  (0x002FE511) -- args=0
void sub_2FE511(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE511 (0x002FE511) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE540  (0x002FE540) -- args=16
void sub_2FE540(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE540 (0x002FE540) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FE5D0  (0x002FE5D0) -- args=4
void sub_2FE5D0(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE5D0 (0x002FE5D0) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE601  (0x002FE601) -- args=4
void sub_2FE601(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE601 (0x002FE601) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE62F  (0x002FE62F) -- args=4
void sub_2FE62F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE62F (0x002FE62F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE63D  (0x002FE63D) -- args=8
void sub_2FE63D(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE63D (0x002FE63D) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FE6A5  (0x002FE6A5) -- args=8
void sub_2FE6A5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE6A5 (0x002FE6A5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FE736  (0x002FE736) -- args=0
void sub_2FE736(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE736 (0x002FE736) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE7A8  (0x002FE7A8) -- args=4
void sub_2FE7A8(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE7A8 (0x002FE7A8) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE7F6  (0x002FE7F6) -- args=4
void sub_2FE7F6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE7F6 (0x002FE7F6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FE850  (0x002FE850) -- args=12
void sub_2FE850(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE850 (0x002FE850) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FE8F2  (0x002FE8F2) -- args=0
void sub_2FE8F2(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE8F2 (0x002FE8F2) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE940  (0x002FE940) -- args=0
void sub_2FE940(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE940 (0x002FE940) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FE997  (0x002FE997) -- args=0
void sub_2FE997(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FE997 (0x002FE997) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FEA6B  (0x002FEA6B) -- args=0
void sub_2FEA6B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEA6B (0x002FEA6B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FEAC4  (0x002FEAC4) -- args=8
void sub_2FEAC4(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEAC4 (0x002FEAC4) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FEAD5  (0x002FEAD5) -- args=16
void sub_2FEAD5(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEAD5 (0x002FEAD5) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// sub_2FEAE1  (0x002FEAE1) -- args=4
void sub_2FEAE1(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEAE1 (0x002FEAE1) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FEB20  (0x002FEB20) -- args=0
void sub_2FEB20(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEB20 (0x002FEB20) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FEB8F  (0x002FEB8F) -- args=4
void sub_2FEB8F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEB8F (0x002FEB8F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FEBAB  (0x002FEBAB) -- args=4
void sub_2FEBAB(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEBAB (0x002FEBAB) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FEC8A  (0x002FEC8A) -- args=0
void sub_2FEC8A(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEC8A (0x002FEC8A) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FEC90  (0x002FEC90) -- args=12
void sub_2FEC90(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEC90 (0x002FEC90) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 12);
}

// sub_2FED2E  (0x002FED2E) -- args=0
void sub_2FED2E(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FED2E (0x002FED2E) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FED3B  (0x002FED3B) -- args=0
void sub_2FED3B(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FED3B (0x002FED3B) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FED3F  (0x002FED3F) -- args=4
void sub_2FED3F(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FED3F (0x002FED3F) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

// sub_2FEDB6  (0x002FEDB6) -- args=8
void sub_2FEDB6(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEDB6 (0x002FEDB6) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FEDDE  (0x002FEDDE) -- args=8
void sub_2FEDDE(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEDDE (0x002FEDDE) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 8);
}

// sub_2FEE23  (0x002FEE23) -- args=0
void sub_2FEE23(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEE23 (0x002FEE23) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// sub_2FEE40  (0x002FEE40) -- args=4
void sub_2FEE40(X86Context& ctx, uint8_t* base)
{
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-DS-STUB] sub_2FEE40 (0x002FEE40) called\n"); logged = true; }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 4);
}

