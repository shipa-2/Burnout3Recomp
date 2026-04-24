// ============================================================================
// HLE WMADEC (WMA Decoder) Backend — placeholder stubs.
//
// This file provides High Level Emulation stubs for the Xbox WMADEC library
// functions used by Burnout 3.  The WMADEC library decodes WMA audio streams
// for playback through DirectSound buffers.
//
// All functions are currently stubbed.  The five public API entry points
// return failure / zero so the game falls back to silence gracefully.
// Internal helper functions are no-ops.
//
// Calling-convention notes:
//   All WMADEC functions are __stdcall (callee-cleanup, args on stack).
//   Functions with no "Arguments" column in the IDA export are cdecl or
//   leaf functions that use plain ret (0 bytes cleanup).
// ============================================================================

#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include "kernel/heap.h"
#include "kernel/memory.h"
#include <atomic>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <thread>
#include <unordered_map>
#include <vector>

#ifdef _WIN32
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <Windows.h>
#include <objbase.h>
#include <mmreg.h>     /* WAVEFORMATEX, WAVE_FORMAT_PCM */
#include <mediaobj.h>  /* IMediaObject, IMediaBuffer, DMO_MEDIA_TYPE, DMO_OUTPUT_DATA_BUFFER */
#include <mfapi.h>
#include <mfidl.h>
#include <mfreadwrite.h>
#include <mferror.h>
#include <Shlwapi.h>
#pragma comment(lib, "ole32")
#pragma comment(lib, "msdmo")
#pragma comment(lib, "mfplat")
#pragma comment(lib, "mfreadwrite")
#pragma comment(lib, "mfuuid")
#pragma comment(lib, "shlwapi")
#endif

#if 1

// ============================================================================
// WMA in-memory decoder — host-side state
//
// WmaCreateInMemoryDecoderEx is a 9-byte JMP forwarding to
// WmaCreateInMemoryDecoder (same 5 args, same semantics).
//
// The decoder object returned to the guest has an XMEDIAOBJECT vtable:
//   [0x00] AddRef(pThis)              → sub_3011BB
//   [0x04] Release(pThis)             → sub_301618
//   [0x08] GetInfo(pThis,XMEDIAINFO*) → sub_300FFF
//   [0x0C] GetStatus(pThis,DWORD*)    → sub_301067
//   [0x10] Process(pThis,in*,out*)    → sub_3010D3  ← WMA→PCM decode
//   [0x14] Discontinuity(pThis)       → sub_3011B8
// ============================================================================

#ifdef _WIN32
namespace {

// ---- GUIDs (defined locally to avoid needing dmoguids.lib/strmiids.lib) ----

// IID_IUnknown  {00000000-0000-0000-C000-000000000046}
static const IID  kIID_IUnknown       = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
// IID_IMediaBuffer  {59eff8b9-938c-4a26-82f2-95cb84cdc837}
static const IID  kIID_IMediaBuffer   = {0x59eff8b9,0x938c,0x4a26,{0x82,0xf2,0x95,0xcb,0x84,0xcd,0xc8,0x37}};
// IID_IMediaObject  {d8ad0f58-5494-4102-97c5-ec798e59bcf4}
static const IID  kIID_IMediaObject   = {0xd8ad0f58,0x5494,0x4102,{0x97,0xc5,0xec,0x79,0x8e,0x59,0xbc,0xf4}};
// CLSID_CWMADecMediaObject  {2eeb4adf-4578-4d10-bca7-bb955f56320a}
static const CLSID kCLSID_WMADec      = {0x2eeb4adf,0x4578,0x4d10,{0xbc,0xa7,0xbb,0x95,0x5f,0x56,0x32,0x0a}};
// MEDIATYPE_Audio  {73647561-0000-0010-8000-00aa00389b71}
static const GUID kMediaType_Audio    = {0x73647561,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x38,0x9b,0x71}};
// FORMAT_WaveFormatEx  {05589f81-c356-11ce-bf01-00aa0055595a}
static const GUID kFormat_WaveFormatEx= {0x05589f81,0xc356,0x11ce,{0xbf,0x01,0x00,0xaa,0x00,0x55,0x59,0x5a}};
// MEDIASUBTYPE_PCM  {00000001-0000-0010-8000-00aa00389b71}
static const GUID kMediaSubtype_PCM   = {0x00000001,0x0000,0x0010,{0x80,0x00,0x00,0xaa,0x00,0x38,0x9b,0x71}};

// ---- Minimal IMediaBuffer implementation wrapping a host byte buffer ----
class CMediaBuf final : public IMediaBuffer {
public:
    std::vector<BYTE> m_data;
    DWORD             m_used;
    LONG              m_ref;

    explicit CMediaBuf(DWORD capacity)
        : m_data(capacity, 0), m_used(0), m_ref(1) {}

    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override {
        if (IsEqualGUID(riid, kIID_IUnknown) ||
            IsEqualGUID(riid, kIID_IMediaBuffer)) {
            *ppv = static_cast<IMediaBuffer*>(this);
            AddRef();
            return S_OK;
        }
        *ppv = nullptr;
        return E_NOINTERFACE;
    }
    STDMETHODIMP_(ULONG) AddRef()  override { return (ULONG)InterlockedIncrement(&m_ref); }
    STDMETHODIMP_(ULONG) Release() override {
        ULONG r = (ULONG)InterlockedDecrement(&m_ref);
        if (r == 0) delete this;
        return r;
    }
    STDMETHODIMP SetLength(DWORD cb) override {
        if (cb > (DWORD)m_data.size()) return E_INVALIDARG;
        m_used = cb;
        return S_OK;
    }
    STDMETHODIMP GetMaxLength(DWORD* pcb) override {
        if (pcb) *pcb = (DWORD)m_data.size();
        return S_OK;
    }
    STDMETHODIMP GetBufferAndLength(BYTE** pp, DWORD* pcb) override {
        if (pp)  *pp  = m_data.data();
        if (pcb) *pcb = m_used;
        return S_OK;
    }
};

} // anonymous namespace
#endif // _WIN32

// ---- Host-side decoder state ----
struct HLE_WmaDec {
    uint32_t guestObjAddr;
    int32_t  refCount;
    uint32_t nChannels;
    uint32_t nSamplesPerSec;
    uint32_t nBlockAlign;        // WMA compressed bytes per input packet
    uint32_t dwSamplesPerPacket;
    uint32_t dwBytesPerPacket;   // PCM bytes per decoded packet
    bool     bReady;             // true after vtable[9] Init() is called
#ifdef _WIN32
    IMediaObject* pDMO;          // Windows WMA decoder DMO — used by sub_3010D3 (game's path)
#endif

    // Pre-loaded ring buffer of compressed WMA data (filled by the streaming state machine).
    // We self-feed it when the game's streaming pump isn't running (e.g. during XMV video).
    uint32_t inputRingBase;      // guest addr of compressed-data ring buffer
    uint32_t inputRingFill;      // bytes available in the ring (set at init)
    uint32_t inputRingRead;      // bytes consumed so far

    // Host-side decoded PCM ring (S16LE interleaved stereo, native sample rate).
    // Written by the background decode thread, drained by the SDL audio callback.
    std::vector<int16_t> pcmRing;
    uint32_t             pcmRingWrite = 0;
    uint32_t             pcmRingRead  = 0;
    std::mutex           pcmMtx;
    static constexpr uint32_t kPcmRingFrames = 48000 * 4; // 4 seconds of stereo S16

    // Mute flag — set by WmaSetAllDecodersMuted(true) when a DSStream is paused
    // (e.g. radio cut during movie playback).  WmaMixAudioFrames skips muted decoders.
    std::atomic<bool> muted{false};

    // Background decode thread
    std::atomic<bool> decodeRunning{false};
    std::thread       decodeThread;
};

// Register a WMA decoder so the SDL audio callback can mix its output.
// Declared here; defined in hle_dsound.cpp.
extern void WmaRegisterDecoder(HLE_WmaDec* dec);
extern void WmaUnregisterDecoder(HLE_WmaDec* dec);

static std::mutex g_wmaMtx;
static std::unordered_map<uint32_t, HLE_WmaDec*> g_wmaDecoders;

// Mute / unmute all WMA background decoders.  Called from the DSStream Pause handler
// (hle_dsound.cpp) so radio audio stops when a DSStream is paused for movie playback.
// When muting, the decoded PCM ring is flushed so stale audio is not replayed on resume.
void WmaSetAllDecodersMuted(bool mute)
{
    std::lock_guard<std::mutex> lk(g_wmaMtx);
    for (auto& kv : g_wmaDecoders) {
        HLE_WmaDec* dec = kv.second;
        if (!dec) continue;
        dec->muted.store(mute);
        if (mute) {
            // Flush the ring so no pre-decoded audio leaks through after resume
            std::lock_guard<std::mutex> plk(dec->pcmMtx);
            dec->pcmRingRead  = dec->pcmRingWrite;
        }
    }
}

// Drain decoded WMA PCM from background-decode threads into `outStereo`.
// Called from the SDL audio callback in hle_dsound.cpp.
void WmaMixAudioFrames(int16_t* outStereo, int frames)
{
    // Snapshot decoder list without holding g_wmaMtx (avoid deadlock with decode thread)
    std::vector<HLE_WmaDec*> decoders;
    {
        std::unique_lock<std::mutex> lk(g_wmaMtx, std::try_to_lock);
        if (!lk.owns_lock()) return;
        for (auto& kv : g_wmaDecoders)
            if (kv.second) decoders.push_back(kv.second);
    }

    for (HLE_WmaDec* dec : decoders) {
        if (dec->muted.load()) continue;
        if (dec->pcmRing.empty()) continue;
        std::unique_lock<std::mutex> plk(dec->pcmMtx, std::try_to_lock);
        if (!plk.owns_lock()) continue;

        const uint32_t ringSize = (uint32_t)dec->pcmRing.size();
        const uint32_t srcCh    = dec->nChannels ? dec->nChannels : 2;
        const uint32_t srcRate  = dec->nSamplesPerSec ? dec->nSamplesPerSec : 48000;
        constexpr uint32_t dstRate = 48000;

        // Available samples in the ring
        uint32_t avail = (dec->pcmRingWrite >= dec->pcmRingRead)
            ? dec->pcmRingWrite - dec->pcmRingRead
            : ringSize - dec->pcmRingRead + dec->pcmRingWrite;
        if (avail == 0) continue;

        uint32_t samplesConsumed = 0;
        for (int i = 0; i < frames; i++) {
            uint32_t srcFrame  = (uint32_t)((double)i * srcRate / dstRate);
            uint32_t srcSample = srcFrame * srcCh;
            if (srcSample >= avail) break;
            samplesConsumed = srcSample + srcCh;

            uint32_t ridx = (dec->pcmRingRead + srcSample) % ringSize;
            int32_t left  = dec->pcmRing[ridx];
            int32_t right = (srcCh >= 2) ? dec->pcmRing[(ridx + 1) % ringSize] : left;

            int32_t mL = (int32_t)outStereo[i * 2 + 0] + left;
            int32_t mR = (int32_t)outStereo[i * 2 + 1] + right;
            if (mL >  32767) mL =  32767; if (mL < -32768) mL = -32768;
            if (mR >  32767) mR =  32767; if (mR < -32768) mR = -32768;
            outStereo[i * 2 + 0] = (int16_t)mL;
            outStereo[i * 2 + 1] = (int16_t)mR;
        }
        if (samplesConsumed > 0)
            dec->pcmRingRead = (dec->pcmRingRead + samplesConsumed) % ringSize;
    }
}

// Vtable guest-memory block (6 entries × 4 bytes = 24 bytes, allocated once)
static uint32_t g_wmaVtblAddr = 0;

// Guest addresses used as vtable slots (each is a registered WMADEC HLE function):
// The functions are overridden below to also serve as XMEDIAOBJECT vtable methods.
static constexpr uint32_t kVtbl_AddRef        = 0x3011BB; // sub_3011BB  1 arg  0x04  [vtbl+0x00]
static constexpr uint32_t kVtbl_Release       = 0x301618; // sub_301618  1 arg  0x04  [vtbl+0x04]
static constexpr uint32_t kVtbl_GetInfo       = 0x300FFF; // sub_300FFF  2 args 0x08  [vtbl+0x08]
static constexpr uint32_t kVtbl_GetStatus     = 0x301067; // sub_301067  2 args 0x08  [vtbl+0x0C]
static constexpr uint32_t kVtbl_Process       = 0x3010D3; // sub_3010D3  3 args 0x0C  [vtbl+0x10]
static constexpr uint32_t kVtbl_Discontinuity = 0x3011B8; // sub_3011B8  1 arg  0x04  [vtbl+0x14]
static constexpr uint32_t kVtbl_Init          = 0x300D00; // sub_300D00  1 arg  0x04  [vtbl+0x24]
static constexpr uint32_t kVtbl_GetSampleRate = 0x301023; // sub_301023  2 args 0x08  [vtbl+0x28]

// Allocate (once) the vtable block in guest memory and write the slot addresses.
static uint32_t EnsureWmaVtbl(uint8_t* base)
{
    if (g_wmaVtblAddr)
        return g_wmaVtblAddr;
    g_wmaVtblAddr = g_heap.AllocGuestAligned(11 * 4, 4);
    if (!g_wmaVtblAddr) {
        fprintf(stderr, "[HLE_WMA] failed to allocate vtable in guest heap\n");
        return 0;
    }
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x00, kVtbl_AddRef);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x04, kVtbl_Release);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x08, kVtbl_GetInfo);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x0C, kVtbl_GetStatus);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x10, kVtbl_Process);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x14, kVtbl_Discontinuity);
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x18, 0u);          // slot 6: unused
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x1C, 0u);          // slot 7: unused
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x20, 0u);          // slot 8: unused
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x24, kVtbl_Init);          // slot 9: Init
    X86_MEM_WRITE_u32(base, g_wmaVtblAddr + 0x28, kVtbl_GetSampleRate); // slot 10: GetSampleRate
    return g_wmaVtblAddr;
}

// Internal creation helper — shared by WmaCreateInMemoryDecoder and
// WmaCreateInMemoryDecoderEx (the Ex variant is an identical 9-byte forward).
static uint32_t WmaCreateInMemoryDecoderImpl(X86Context& ctx, uint8_t* base)
{
    // arg0 = pfnCallback       — read callback function pointer (e.g. sub_1CE290)
    // arg1 = pContext           — streaming state object (same esi as in the caller)
    // arg2 = dwSamplesPerPkt    — number of PCM samples per decoded output packet
    // arg3 = pdwBytesPerPacket  — OUTPUT: receives decoded bytes per packet
    // arg4 = ppDecoder          — OUTPUT: receives decoder object pointer
    uint32_t pfnCallback       = GuestArg32(ctx, base, 0);
    uint32_t pContext          = GuestArg32(ctx, base, 1);
    uint32_t dwSamplesPerPkt   = GuestArg32(ctx, base, 2);
    uint32_t pdwBytesPerPacket = GuestArg32(ctx, base, 3);
    uint32_t ppDecoder         = GuestArg32(ctx, base, 4);

    if (!ppDecoder) {
        fprintf(stderr, "[HLE_WMA] WmaCreateInMemoryDecoder: null ppDecoder\n");
        return 0x80070057u; // E_INVALIDARG
    }

    // Dump the audio streaming buffer at [pContext+0x14] to find the WMA ASF header / format
    uint32_t ringbuf  = pContext ? X86_MEM_READ_u32(base, pContext + 0x250u) : 0u;
    uint32_t strmBuf  = pContext ? X86_MEM_READ_u32(base, pContext + 0x14u)  : 0u;
    uint32_t strmBuf2 = pContext ? X86_MEM_READ_u32(base, pContext + 0x18u)  : 0u;
    uint32_t strmAvail = pContext ? X86_MEM_READ_u32(base, pContext + 0x10u) : 0u;
    if (pContext) {
        fprintf(stderr,
            "[HLE_WMA] pContext=0x%08X  +0x00=%08X +0x04=%08X +0x08=%08X +0x0C=%08X\n"
            "[HLE_WMA]  +0x10(avail)=%08X +0x14(buf1)=%08X +0x18(buf2)=%08X +0x1C=%08X\n"
            "[HLE_WMA]  rb(0x250)=%08X\n",
            pContext,
            X86_MEM_READ_u32(base, pContext + 0x00u), X86_MEM_READ_u32(base, pContext + 0x04u),
            X86_MEM_READ_u32(base, pContext + 0x08u), X86_MEM_READ_u32(base, pContext + 0x0Cu),
            strmAvail, strmBuf, strmBuf2, X86_MEM_READ_u32(base, pContext + 0x1Cu),
            ringbuf);
        // Dump first 64 bytes of the audio streaming buffer (should be WMA ASF or raw WMA)
        if (strmBuf) {
            fprintf(stderr, "[HLE_WMA] strmBuf[0x00]: ");
            for (int i = 0; i < 96; i++) {
                fprintf(stderr, "%02X ", X86_MEM_READ_u8(base, strmBuf + (uint32_t)i));
                if (i == 15 || i == 31 || i == 47 || i == 63 || i == 79)
                    fprintf(stderr, "\n[HLE_WMA] strmBuf[0x%02X]: ", i+1);
            }
            fprintf(stderr, "\n");
        }
        // Also dump WBND header offsets that look format-related
        if (ringbuf) {
            uint32_t pAudioDesc = ringbuf + X86_MEM_READ_u32(base, ringbuf + 0x08u);
            fprintf(stderr, "[HLE_WMA] WBND pAudioDesc(0x%08X): ", pAudioDesc);
            for (int i = 0; i < 40; i++) fprintf(stderr, "%02X ", X86_MEM_READ_u8(base, pAudioDesc + (uint32_t)i));
            fprintf(stderr, "\n");
        }
    }

    // Parse WAVEFORMATEX from ASF Stream Properties Object in the streaming buffer.
    // ASF_Stream_Properties_Object GUID (LE u32x4): B7DC0791 11CFA9B7 C000E68E 6553200C
    // ASF_Audio_Media stream type GUID first DWORD (LE): F8699E40
    // Type-specific data (= WAVEFORMATEX) starts at object_base + 78.
    uint16_t wFormatTag      = 0x0161u;
    uint16_t nChannels       = 2u;
    uint32_t nSamplesPerSec  = 44100u;
    uint32_t nAvgBytesPerSec = 16000u;
    uint16_t nBlockAlign     = 0u;
    uint16_t wBitsPerSample  = 16u;
    uint16_t cbSize          = 0u;
    uint8_t  asfExtra[32]    = {}; // codec-specific extra bytes (up to cbSize, max 32)
    if (strmBuf && X86_MEM_READ_u32(base, strmBuf) == 0x75B22630u) {
        uint32_t hdrSize = X86_MEM_READ_u32(base, strmBuf + 0x10u);
        uint32_t pos     = strmBuf + 0x1Eu; // GUID(16)+Size(8)+NumObjs(4)+Rsvd(2)
        uint32_t endPos  = strmBuf + hdrSize;
        while (pos + 24u <= endPos) {
            uint32_t g0      = X86_MEM_READ_u32(base, pos +  0u);
            uint32_t g1      = X86_MEM_READ_u32(base, pos +  4u);
            uint32_t g2      = X86_MEM_READ_u32(base, pos +  8u);
            uint32_t g3      = X86_MEM_READ_u32(base, pos + 12u);
            uint32_t objSize = X86_MEM_READ_u32(base, pos + 16u);
            if (objSize < 24u) break;
            if (g0 == 0xB7DC0791u && g1 == 0x11CFA9B7u &&
                g2 == 0xC000E68Eu && g3 == 0x6553200Cu) {
                // Verify stream type = ASF_Audio_Media (first DWORD 0xF8699E40)
                if (X86_MEM_READ_u32(base, pos + 24u) == 0xF8699E40u) {
                    uint32_t wfxBase = pos + 78u;
                    wFormatTag      = X86_MEM_READ_u16(base, wfxBase +  0u);
                    nChannels       = X86_MEM_READ_u16(base, wfxBase +  2u);
                    nSamplesPerSec  = X86_MEM_READ_u32(base, wfxBase +  4u);
                    nAvgBytesPerSec = X86_MEM_READ_u32(base, wfxBase +  8u);
                    nBlockAlign     = X86_MEM_READ_u16(base, wfxBase + 12u);
                    wBitsPerSample  = X86_MEM_READ_u16(base, wfxBase + 14u);
                    cbSize          = X86_MEM_READ_u16(base, wfxBase + 16u);
                    uint16_t cbCopy = cbSize < (uint16_t)sizeof(asfExtra) ? cbSize : (uint16_t)sizeof(asfExtra);
                    for (uint16_t k = 0; k < cbCopy; k++)
                        asfExtra[k] = X86_MEM_READ_u8(base, wfxBase + 18u + k);
                    fprintf(stderr,
                        "[HLE_WMA] ASF WAVEFORMATEX: fmt=0x%04X ch=%u rate=%u "
                        "avgBytes=%u blockAlign=%u bits=%u cbSize=%u\n",
                        wFormatTag, nChannels, nSamplesPerSec,
                        nAvgBytesPerSec, nBlockAlign, wBitsPerSample, cbSize);
                    break;
                }
            }
            pos += objSize;
        }
    }

    // Determine whether this is movie/cutscene audio or a looping radio/music track.
    // Movie audio is identified by the WBND entry name "Movie"; radio tracks are "EATrax*".
    // Only movie audio uses the MFSourceReader bg-thread path; radio uses the DSStream path.
    // WBND audio descriptor: [u32 flags][u32 nameLen][char name[16]][...]
    char audioName[17] = {};
    if (ringbuf) {
        uint32_t pAudioDescN = ringbuf + X86_MEM_READ_u32(base, ringbuf + 0x08u);
        for (int i = 0; i < 16; i++)
            audioName[i] = (char)X86_MEM_READ_u8(base, pAudioDescN + 8u + (uint32_t)i);
    }
    const bool isMovieAudio = (strncmp(audioName, "Movie", 5) == 0);
    fprintf(stderr, "[HLE_WMA] WBND audio name: \"%s\" -> %s\n",
            audioName, isMovieAudio ? "movie/bg-thread" : "radio/DSStream");

    // PCM output: 16-bit, same channel count and sample rate
    // dwSamplesPerPkt = number of compressed WMA frames per input call.
    // WMA v2 decodes exactly 2048 PCM samples per frame, so:
    //   bytesPerPacket = dwSamplesPerPkt * 2048 * nChannels * sizeof(int16_t)
    uint16_t outBlockAlign   = (uint16_t)(nChannels * 2u);
    if (dwSamplesPerPkt == 0) dwSamplesPerPkt = 1;
    const uint32_t kWmaFrameSamples = 2048u;
    uint32_t dwBytesPerPacket = dwSamplesPerPkt * kWmaFrameSamples * (uint32_t)outBlockAlign;

    fprintf(stderr,
        "[HLE_WMA] WmaCreateInMemoryDecoder: fmt=0x%04X ch=%u rate=%u "
        "blockAlign=%u samplesPerPkt=%u bytesPerPkt=%u\n",
        wFormatTag, nChannels, nSamplesPerSec,
        nBlockAlign, dwSamplesPerPkt, dwBytesPerPacket);

    // ---- Create Windows WMA DMO ----
#ifdef _WIN32
    // Copy WAVEFORMATEX (+ extra bytes) to a host buffer for the DMO
    uint32_t wfxTotalSize = (uint32_t)sizeof(WAVEFORMATEX) + cbSize;
    std::vector<uint8_t> wfxHost(wfxTotalSize, 0);
    WAVEFORMATEX* pWfxHost = reinterpret_cast<WAVEFORMATEX*>(wfxHost.data());
    pWfxHost->wFormatTag      = wFormatTag;
    pWfxHost->nChannels       = nChannels;
    pWfxHost->nSamplesPerSec  = nSamplesPerSec;
    pWfxHost->nAvgBytesPerSec = nAvgBytesPerSec;
    pWfxHost->nBlockAlign     = nBlockAlign;
    pWfxHost->wBitsPerSample  = wBitsPerSample;
    pWfxHost->cbSize          = cbSize;
    if (cbSize > 0) {
        uint16_t cbCopy = cbSize < (uint16_t)sizeof(asfExtra) ? cbSize : (uint16_t)sizeof(asfExtra);
        memcpy(wfxHost.data() + sizeof(WAVEFORMATEX), asfExtra, cbCopy);
    }

    CoInitializeEx(nullptr, COINIT_MULTITHREADED); // idempotent; MTA allows cross-thread use

    IMediaObject* pDMO = nullptr;
    HRESULT hr = CoCreateInstance(kCLSID_WMADec, nullptr,
                                  CLSCTX_INPROC_SERVER,
                                  kIID_IMediaObject, (void**)&pDMO);
    if (SUCCEEDED(hr)) {
        // Input type: WMA format from the guest WAVEFORMATEX
        GUID wmaSubtype = {(DWORD)wFormatTag, 0x0000, 0x0010,
                           {0x80,0x00,0x00,0xaa,0x00,0x38,0x9b,0x71}};
        DMO_MEDIA_TYPE mtIn = {};
        mtIn.majortype            = kMediaType_Audio;
        mtIn.subtype              = wmaSubtype;
        mtIn.formattype           = kFormat_WaveFormatEx;
        mtIn.bFixedSizeSamples    = FALSE;
        mtIn.bTemporalCompression = TRUE;
        mtIn.cbFormat             = wfxTotalSize;
        mtIn.pbFormat             = (BYTE*)CoTaskMemAlloc(wfxTotalSize);
        if (mtIn.pbFormat) {
            memcpy(mtIn.pbFormat, pWfxHost, wfxTotalSize);
            hr = pDMO->SetInputType(0, &mtIn, 0);
            CoTaskMemFree(mtIn.pbFormat);
        }
        if (FAILED(hr)) {
            fprintf(stderr, "[HLE_WMA] SetInputType failed: 0x%08X\n", (unsigned)hr);
            pDMO->Release(); pDMO = nullptr;
        }
    }
    if (pDMO) {
        // Output type: 16-bit PCM
        WAVEFORMATEX wfxPCM = {};
        wfxPCM.wFormatTag      = WAVE_FORMAT_PCM;
        wfxPCM.nChannels       = nChannels;
        wfxPCM.nSamplesPerSec  = nSamplesPerSec;
        wfxPCM.wBitsPerSample  = 16;
        wfxPCM.nBlockAlign     = outBlockAlign;
        wfxPCM.nAvgBytesPerSec = nSamplesPerSec * outBlockAlign;
        wfxPCM.cbSize          = 0;
        DMO_MEDIA_TYPE mtOut = {};
        mtOut.majortype            = kMediaType_Audio;
        mtOut.subtype              = kMediaSubtype_PCM;
        mtOut.formattype           = kFormat_WaveFormatEx;
        mtOut.bFixedSizeSamples    = TRUE;
        mtOut.bTemporalCompression = FALSE;
        mtOut.cbFormat             = sizeof(WAVEFORMATEX);
        mtOut.pbFormat             = (BYTE*)CoTaskMemAlloc(sizeof(WAVEFORMATEX));
        if (mtOut.pbFormat) {
            memcpy(mtOut.pbFormat, &wfxPCM, sizeof(WAVEFORMATEX));
            HRESULT hr2 = pDMO->SetOutputType(0, &mtOut, 0);
            CoTaskMemFree(mtOut.pbFormat);
            if (FAILED(hr2)) {
                fprintf(stderr, "[HLE_WMA] SetOutputType failed: 0x%08X\n", (unsigned)hr2);
                pDMO->Release(); pDMO = nullptr;
            }
        }
    }
    if (pDMO) {
        HRESULT hr3 = pDMO->AllocateStreamingResources();
        if (FAILED(hr3)) {
            fprintf(stderr, "[HLE_WMA] AllocateStreamingResources failed: 0x%08X\n", (unsigned)hr3);
            pDMO->Release(); pDMO = nullptr;
        }
    }
    if (!pDMO)
        fprintf(stderr, "[HLE_WMA] WMA DMO unavailable; silence will be produced\n");
    else
        fprintf(stderr, "[HLE_WMA] WMA DMO created OK\n");
#endif

    // ---- Allocate vtable in guest memory (once) ----
    uint32_t vtblAddr = EnsureWmaVtbl(base);
    if (!vtblAddr) {
#ifdef _WIN32
        if (pDMO) pDMO->Release();
#endif
        X86_MEM_WRITE_u32(base, ppDecoder, 0);
        return 0x8007000Eu; // E_OUTOFMEMORY
    }

    // ---- Allocate the guest decoder object (8 bytes: vtable ptr + padding) ----
    uint32_t guestObj = g_heap.AllocGuestAligned(8, 4);
    if (!guestObj) {
#ifdef _WIN32
        if (pDMO) pDMO->Release();
#endif
        X86_MEM_WRITE_u32(base, ppDecoder, 0);
        return 0x8007000Eu;
    }
    memset(base + guestObj, 0, 8);
    X86_MEM_WRITE_u32(base, guestObj + 0, vtblAddr); // vtable pointer

    // ---- Register host-side state ----
    HLE_WmaDec* dec = new HLE_WmaDec{};
    dec->guestObjAddr      = guestObj;
    dec->refCount          = 1;
    dec->nChannels         = nChannels;
    dec->nSamplesPerSec    = nSamplesPerSec;
    dec->nBlockAlign       = nBlockAlign;
    dec->dwSamplesPerPacket= dwSamplesPerPkt;
    dec->dwBytesPerPacket  = dwBytesPerPacket;
    dec->bReady            = false;
#ifdef _WIN32
    dec->pDMO   = pDMO;
#endif

    // Pre-loaded ring: the streaming state machine (sub_1CE6A0) reads compressed WMA data
    // into strmBuf (pContext+0x14) before creating the decoder.  Two half-buffers of 0x20000
    // bytes are filled, giving 0x40000 = 262144 bytes of compressed WMA data.  This is
    // sufficient for the full movie.xwb / englis30.xmv 3.6-second clip (only ~73 KB needed).
    dec->inputRingBase = strmBuf;           // guest addr where the data lives
    dec->inputRingFill = (strmBuf ? 0x40000u : 0u); // assume both halves are loaded
    dec->inputRingRead = 0;

    // For movie audio: allocate decoded PCM ring (4 seconds of stereo S16 at native rate).
    // For radio/EATrax: skip the ring — audio is delivered via the game pump → DSStream path.
    if (isMovieAudio && nChannels > 0 && nSamplesPerSec > 0) {
        uint32_t ringFrames = HLE_WmaDec::kPcmRingFrames;
        dec->pcmRing.assign(ringFrames * nChannels, 0);
    }
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        g_wmaDecoders[guestObj] = dec;
    }

    // Only movie audio gets a bg-thread and is registered with the SDL WMA mixer.
    // Radio/EATrax tracks rely entirely on the game pump (sub_3010D3 → CDirectSoundStream_Process).
#ifdef _WIN32
    if (isMovieAudio && dec->inputRingBase && dec->inputRingFill > 0 && !dec->pcmRing.empty()) {
        // Mute any previously-registered decoders and flush their rings.
        // NOTE: this decoder is already in g_wmaDecoders so WmaSetAllDecodersMuted would
        // mute it too — restore it immediately after.
        WmaSetAllDecodersMuted(true);
        dec->muted.store(false);  // this is the active decoder
        // Register with SDL audio mixer (also flushes all DSStream rings).
        WmaRegisterDecoder(dec);
        dec->decodeRunning.store(true);
        dec->decodeThread = std::thread([dec, base]() {
            const uint32_t ringSize = (uint32_t)dec->pcmRing.size(); // total samples

            CoInitializeEx(nullptr, COINIT_MULTITHREADED);
            MFStartup(MF_VERSION, MFSTARTUP_LITE);

            // Wrap the in-memory ASF buffer in a COM IStream, then an IMFByteStream.
            const BYTE* asfData = reinterpret_cast<const BYTE*>(base + dec->inputRingBase);
            IStream* pMemStream = SHCreateMemStream(asfData, dec->inputRingFill);
            if (!pMemStream) { MFShutdown(); return; }

            IMFByteStream* pBs = nullptr;
            if (FAILED(MFCreateMFByteStreamOnStream(pMemStream, &pBs))) {
                pMemStream->Release();
                MFShutdown();
                return;
            }
            pMemStream->Release();

            // Create a source reader that decodes to PCM directly.
            IMFAttributes* pAttr = nullptr;
            MFCreateAttributes(&pAttr, 1);
            if (pAttr) pAttr->SetUINT32(MF_LOW_LATENCY, TRUE);

            IMFSourceReader* pReader = nullptr;
            HRESULT hr = MFCreateSourceReaderFromByteStream(pBs, pAttr, &pReader);
            pBs->Release();
            if (pAttr) pAttr->Release();
            if (FAILED(hr) || !pReader) { MFShutdown(); return; }

            // Tell the source reader to decode the first audio stream to 16-bit PCM.
            IMFMediaType* pOutType = nullptr;
            MFCreateMediaType(&pOutType);
            pOutType->SetGUID(MF_MT_MAJOR_TYPE, MFMediaType_Audio);
            pOutType->SetGUID(MF_MT_SUBTYPE,    MFAudioFormat_PCM);
            pReader->SetCurrentMediaType(MF_SOURCE_READER_FIRST_AUDIO_STREAM, nullptr, pOutType);
            pOutType->Release();

            fprintf(stderr, "[HLE_WMA] bg-thread MF reader ready, decoding...\n");

            while (dec->decodeRunning.load()) {
                DWORD  dwStreamIndex = 0, dwFlags = 0;
                LONGLONG llTimestamp = 0;
                IMFSample* pSample = nullptr;
                hr = pReader->ReadSample(MF_SOURCE_READER_FIRST_AUDIO_STREAM,
                                         0, &dwStreamIndex, &dwFlags,
                                         &llTimestamp, &pSample);
                if (FAILED(hr) || (dwFlags & MF_SOURCE_READERF_ENDOFSTREAM)) {
                    if (pSample) pSample->Release();
                    break;
                }
                if (!pSample) continue;

                IMFMediaBuffer* pBuf = nullptr;
                pSample->ConvertToContiguousBuffer(&pBuf);
                pSample->Release();
                if (!pBuf) continue;

                BYTE*  pData  = nullptr;
                DWORD  cbData = 0;
                pBuf->Lock(&pData, nullptr, &cbData);
                const uint32_t nSamples = cbData / sizeof(int16_t);
                const int16_t* s16      = reinterpret_cast<const int16_t*>(pData);

                // Write samples into the ring, waiting if it's full.
                uint32_t written = 0;
                while (written < nSamples && dec->decodeRunning.load()) {
                    bool pushed = false;
                    {
                        std::lock_guard<std::mutex> lk(dec->pcmMtx);
                        uint32_t avail = (dec->pcmRingWrite >= dec->pcmRingRead)
                            ? dec->pcmRingWrite - dec->pcmRingRead
                            : ringSize - dec->pcmRingRead + dec->pcmRingWrite;
                        uint32_t space = ringSize - avail - 1; // guard byte
                        uint32_t toPush = std::min(nSamples - written, space);
                        for (uint32_t i = 0; i < toPush; i++) {
                            dec->pcmRing[dec->pcmRingWrite] = s16[written + i];
                            dec->pcmRingWrite = (dec->pcmRingWrite + 1) % ringSize;
                        }
                        written += toPush;
                        pushed = (toPush > 0);
                    }
                    if (!pushed)
                        std::this_thread::sleep_for(std::chrono::milliseconds(5));
                }

                pBuf->Unlock();
                pBuf->Release();
            }

            pReader->Release();
            MFShutdown();
            fprintf(stderr, "[HLE_WMA] bg-thread done\n");
        });
    }
#endif

    // ---- Write outputs ----
    X86_MEM_WRITE_u32(base, ppDecoder, guestObj);
    if (pdwBytesPerPacket)
        X86_MEM_WRITE_u32(base, pdwBytesPerPacket, dwBytesPerPacket);

    fprintf(stderr,
        "[HLE_WMA] decoder guest=0x%08X vtbl=0x%08X bytesPerPkt=%u\n",
        guestObj, vtblAddr, dwBytesPerPacket);
    return 0u; // S_OK
}

// ============================================================================
// Public WMA Decoder API
// ============================================================================

// XWmaDecoderCreateMediaObject  (0x30211F) — 2 args (0x08), ret 8
void XWmaDecoderCreateMediaObject(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] XWmaDecoderCreateMediaObject()\n");
    ctx.eax = 0x80004005; // E_FAIL
    GuestStackCleanup(ctx, 0x08);
}

// WmaCreateInMemoryDecoder  (0x30217B) — 5 args (0x14)
// Creates a WMA in-memory decoder using the Windows WMA DMO.
void WmaCreateInMemoryDecoder(X86Context& ctx, uint8_t* base)
{
    ctx.eax = WmaCreateInMemoryDecoderImpl(ctx, base);
    GuestStackCleanup(ctx, 0x14);
}

// WmaCreateDecoder  (0x3021FC) — 8 args (0x20), ret 32
void WmaCreateDecoder(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] WmaCreateDecoder()\n");
    ctx.eax = 0x80004005; // E_FAIL
    GuestStackCleanup(ctx, 0x20);
}

// WmaCreateInMemoryDecoderEx  (0x302272) — 5 args (0x14)
// In the XBE this is a 9-byte JMP forwarding to WmaCreateInMemoryDecoder.
void WmaCreateInMemoryDecoderEx(X86Context& ctx, uint8_t* base)
{
    ctx.eax = WmaCreateInMemoryDecoderImpl(ctx, base);
    GuestStackCleanup(ctx, 0x14);
}

// WmaCreateDecoderEx  (0x30227B) — 8 args (0x20), ret 32
void WmaCreateDecoderEx(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] WmaCreateDecoderEx()\n");
    ctx.eax = 0x80004005; // E_FAIL
    GuestStackCleanup(ctx, 0x20);
}

// ============================================================================
// Internal WMADEC helpers — unnamed subs
// ============================================================================

// sub_300D00  (0x300D00) — 1 arg (0x04)
// Vtable[9]: Init(pThis) — called once after creation to activate the decoder.
void sub_300D00(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end())
            it->second->bReady = true;
    }
    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x04);
}

// sub_300D18  (0x300D18) — 0 args
void sub_300D18(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_300D18()\n");
    ctx.eax = 0;
}

// sub_300D5C  (0x300D5C) — 0 args, locals 0x04
void sub_300D5C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_300D5C()\n");
    ctx.eax = 0;
}

// sub_300D72  (0x300D72) — 1 arg (0x04), locals 0x14
void sub_300D72(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_300D72()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_300E7B  (0x300E7B) — 2 args (0x08), locals 0x1C
void sub_300E7B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_300E7B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_300F6B  (0x300F6B) — 4 args (0x10), locals 0x0C
void sub_300F6B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_300F6B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_300FFF  (0x300FFF) — 2 args (0x08)
// Vtable[2]: GetInfo(pThis, XMEDIAINFO*)
void sub_300FFF(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t pInfo = GuestArg32(ctx, base, 1);
    std::lock_guard<std::mutex> lk(g_wmaMtx);
    auto it = g_wmaDecoders.find(pThis);
    if (it != g_wmaDecoders.end() && pInfo) {
        HLE_WmaDec* dec = it->second;
        // XMEDIAINFO: dwFlags | dwInputSize | dwOutputSize | dwMaxLookahead
        X86_MEM_WRITE_u32(base, pInfo + 0x00, 0x00000003u); // FIXED_SAMPLE_SIZE|FIXED_PACKET_ALIGNMENT
        X86_MEM_WRITE_u32(base, pInfo + 0x04, 0u);          // variable input
        X86_MEM_WRITE_u32(base, pInfo + 0x08, dec->dwBytesPerPacket);
        X86_MEM_WRITE_u32(base, pInfo + 0x0C, 0u);
    }
    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x08);
}

// sub_301023  (0x301023) — 2 args (0x08)
// Vtable[10]: GetSampleRate(pThis, DWORD* pdwOut) — returns the PCM sample rate.
// The caller computes: 2048000 / nSamplesPerSec to derive timing values.
void sub_301023(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis  = GuestArg32(ctx, base, 0);
    uint32_t pdwOut = GuestArg32(ctx, base, 1);
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end() && pdwOut) {
            uint32_t rate = it->second->nSamplesPerSec;
            if (rate == 0) rate = 44100u; // safe fallback
            X86_MEM_WRITE_u32(base, pdwOut, rate);
        }
    }
    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x08);
}

// sub_301067  (0x301067) — 2 args (0x08)
// Vtable[3]: GetStatus(pThis, DWORD* pdwStatus)
void sub_301067(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis     = GuestArg32(ctx, base, 0);
    uint32_t pdwStatus = GuestArg32(ctx, base, 1);
    std::lock_guard<std::mutex> lk(g_wmaMtx);
    auto it = g_wmaDecoders.find(pThis);
    if (it != g_wmaDecoders.end() && pdwStatus) {
        // XMO_STATUSF_ACCEPT_DATA (0x01) always; add OFFER_DATA (0x02) once initialized.
        uint32_t status = it->second->bReady ? 0x00000003u : 0x00000001u;
        X86_MEM_WRITE_u32(base, pdwStatus, status);
    }
    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x08);
}

// sub_301083  (0x301083) — 2 args (0x08), locals 0x04
void sub_301083(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301083()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3010BD  (0x3010BD) — 4 args (0x10)
void sub_3010BD(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3010BD()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3010D3  (0x3010D3) — 3 args (0x0C), locals 0x04
// Vtable[4]: Process(pThis, XMEDIAPACKET* pInput, XMEDIAPACKET* pOutput)
void sub_3010D3(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis      = GuestArg32(ctx, base, 0);
    uint32_t pInputPkt  = GuestArg32(ctx, base, 1);
    uint32_t pOutputPkt = GuestArg32(ctx, base, 2);

    HLE_WmaDec* dec = nullptr;
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end()) dec = it->second;
    }
    if (!dec || !pInputPkt || !pOutputPkt) {
        ctx.eax = 0x80070057u; // E_INVALIDARG
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    // XMEDIAPACKET layout: pvBuffer(+0), dwMaxSize(+4), pdwCompletedSize(+8), pdwStatus(+12)
    uint32_t inBuf    = X86_MEM_READ_u32(base, pInputPkt  + 0x00);
    uint32_t inSize   = X86_MEM_READ_u32(base, pInputPkt  + 0x04);
    uint32_t inDone   = X86_MEM_READ_u32(base, pInputPkt  + 0x08);
    uint32_t inStat   = X86_MEM_READ_u32(base, pInputPkt  + 0x0C);
    uint32_t outBuf   = X86_MEM_READ_u32(base, pOutputPkt + 0x00);
    uint32_t outSize  = X86_MEM_READ_u32(base, pOutputPkt + 0x04);
    uint32_t outDone  = X86_MEM_READ_u32(base, pOutputPkt + 0x08);
    uint32_t outStat  = X86_MEM_READ_u32(base, pOutputPkt + 0x0C);

    uint32_t bytesOut = 0;

#ifdef _WIN32
    if (dec->pDMO && inBuf && inSize > 0 && outBuf && outSize > 0) {
        CMediaBuf* pInBuf = new CMediaBuf(inSize);
        memcpy(pInBuf->m_data.data(), base + inBuf, inSize);
        pInBuf->m_used = inSize;
        HRESULT hr = dec->pDMO->ProcessInput(0, pInBuf, 0, 0, 0);
        pInBuf->Release();

        if (SUCCEEDED(hr) || hr == S_FALSE) {
            // Drain all available output (loop for DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE)
            CMediaBuf* pOutBuf = new CMediaBuf(outSize);
            HRESULT hrOut;
            do {
                pOutBuf->m_used = 0;
                DMO_OUTPUT_DATA_BUFFER dmoOut = {};
                dmoOut.pBuffer = pOutBuf;
                DWORD dwSt = 0;
                hrOut = dec->pDMO->ProcessOutput(0, 1, &dmoOut, &dwSt);
                if (SUCCEEDED(hrOut) && hrOut != S_FALSE) {
                    BYTE* pData = nullptr; DWORD cbData = 0;
                    pOutBuf->GetBufferAndLength(&pData, &cbData);
                    uint32_t copy = cbData;
                    if (bytesOut + copy > outSize) copy = outSize - bytesOut;
                    if (copy > 0) {
                        memcpy(base + outBuf + bytesOut, pData, copy);
                        bytesOut += copy;
                    }
                    if (!(dmoOut.dwStatus & DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE))
                        break;
                } else {
                    break;
                }
            } while (bytesOut < outSize);
            pOutBuf->Release();
        }
    } else if (!dec->pDMO && outBuf && outSize > 0) {
        // DMO unavailable — produce silence
        memset(base + outBuf, 0, outSize);
        bytesOut = outSize;
    }
#else
    if (outBuf && outSize > 0) {
        memset(base + outBuf, 0, outSize);
        bytesOut = outSize;
    }
#endif

    if (inDone)  X86_MEM_WRITE_u32(base, inDone,  inSize);   // consumed all input
    if (inStat)  X86_MEM_WRITE_u32(base, inStat,  0u);       // XMP_STATUS_SUCCESS
    if (outDone) X86_MEM_WRITE_u32(base, outDone, bytesOut);
    if (outStat) X86_MEM_WRITE_u32(base, outStat, 0u);       // XMP_STATUS_SUCCESS

    // Diagnostic: log WMA decode throughput
    {
        static uint32_t s_wmaInTotal = 0, s_wmaOutTotal = 0;
        static int       s_wmaCalls = 0;
        static auto      s_wmaStart = std::chrono::steady_clock::now();
        s_wmaInTotal += inSize;
        s_wmaOutTotal += bytesOut;
        s_wmaCalls++;
        auto now = std::chrono::steady_clock::now();
        double elapsed = std::chrono::duration<double>(now - s_wmaStart).count();
        if (elapsed >= 2.0) {
            fprintf(stderr, "[AUDIO-DIAG] WMA_Process: %u calls in %.1fs (%.1f/s), in=%u B/s, out=%u B/s (needed=%u B/s)\n",
                    s_wmaCalls, elapsed, s_wmaCalls / elapsed,
                    (uint32_t)(s_wmaInTotal / elapsed), (uint32_t)(s_wmaOutTotal / elapsed),
                    (uint32_t)(dec->nSamplesPerSec * dec->nChannels * 2));
            s_wmaInTotal = 0; s_wmaOutTotal = 0; s_wmaCalls = 0; s_wmaStart = now;
        }
    }

    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x0C);
}

// sub_30116F  (0x30116F) — 2 args (0x08) (nullsub_25)
void sub_30116F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30116F()\n");
    GuestStackCleanup(ctx, 0x08);
}

// sub_301172  (0x301172) — 2 args (0x08), locals 0x04
void sub_301172(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301172()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3011B8  (0x3011B8) — 1 arg (0x04) (nullsub_26)
// Vtable[5]: Discontinuity(pThis)
void sub_3011B8(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end()) {
#ifdef _WIN32
            if (it->second->pDMO)
                it->second->pDMO->Discontinuity(0);
#endif
        }
    }
    ctx.eax = 0u; // S_OK
    GuestStackCleanup(ctx, 0x04);
}

// sub_3011BB  (0x3011BB) — 1 arg (0x04)
// Vtable[0]: AddRef(pThis)
void sub_3011BB(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end()) {
            ctx.eax = (uint32_t)(++it->second->refCount);
            GuestStackCleanup(ctx, 0x04);
            return;
        }
    }
    ctx.eax = 0u;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30120C  (0x30120C) — 1 arg (0x04), locals 0x18
void sub_30120C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30120C()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3012C9  (0x3012C9) — 0 args, locals 0x14
void sub_3012C9(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3012C9()\n");
    ctx.eax = 0;
}

// sub_30132D  (0x30132D) — 2 args (0x08), locals 0x14
void sub_30132D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30132D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3013F0  (0x3013F0) — 3 args (0x0C), locals 0x10
void sub_3013F0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3013F0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_301457  (0x301457) — 0 args, locals 0x1C
void sub_301457(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301457()\n");
    ctx.eax = 0;
}

// sub_30150B  (0x30150B) — 1 arg (0x04), locals 0x0C
void sub_30150B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30150B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3015DB  (0x3015DB) — 2 args (0x08), locals 0x08
void sub_3015DB(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3015DB()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_301618  (0x301618) — 1 arg (0x04)
// Vtable[1]: Release(pThis)
void sub_301618(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    HLE_WmaDec* dec = nullptr;
    {
        std::lock_guard<std::mutex> lk(g_wmaMtx);
        auto it = g_wmaDecoders.find(pThis);
        if (it != g_wmaDecoders.end()) {
            dec = it->second;
            uint32_t newRef = (uint32_t)(--dec->refCount);
            ctx.eax = newRef;
            if (newRef == 0) {
                g_wmaDecoders.erase(it);
#ifdef _WIN32
                // Stop background decode thread before destroying the DMO instance.
                dec->decodeRunning.store(false);
                if (dec->decodeThread.joinable())
                    dec->decodeThread.join();
                if (dec->pDMO) { dec->pDMO->Release(); dec->pDMO = nullptr; }
#endif
                // Remove from SDL audio mixer (decrements g_wmaStreamActive,
                // re-enabling DSStream drain once no movie decoders remain).
                WmaUnregisterDecoder(dec);
                g_heap.FreeGuest(dec->guestObjAddr);
                delete dec;
            }
            GuestStackCleanup(ctx, 0x04);
            return;
        }
    }
    ctx.eax = 0u;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30161D  (0x30161D) — 2 args (0x08), locals 0x08
void sub_30161D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30161D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_301652  (0x301652) — 2 args (0x08), locals 0x0C
void sub_301652(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301652()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30169C  (0x30169C) — 2 args (0x08), locals 0x04
void sub_30169C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30169C()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3016D6  (0x3016D6) — 4 args (0x10)
void sub_3016D6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3016D6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3016F4  (0x3016F4) — 2 args (0x08)
void sub_3016F4(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3016F4()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30173C  (0x30173C) — 2 args (0x08)
void sub_30173C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30173C()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_301755  (0x301755) — 0 args, locals 0x04
void sub_301755(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301755()\n");
    ctx.eax = 0;
}

// sub_301801  (0x301801) — 1 arg (0x04), locals 0x04
void sub_301801(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301801()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30181F  (0x30181F) — 0 args, locals 0x10
void sub_30181F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30181F()\n");
    ctx.eax = 0;
}

// sub_301955  (0x301955) — 1 arg (0x04), locals 0x04
void sub_301955(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301955()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3019B6  (0x3019B6) — 1 arg (0x04), locals 0x04
void sub_3019B6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3019B6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3019D6  (0x3019D6) — 3 args (0x0C), locals 0x0C
void sub_3019D6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3019D6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_301ACC  (0x301ACC) — 3 args (0x0C), locals 0x10
void sub_301ACC(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301ACC()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_301B8A  (0x301B8A) — 2 args (0x08), locals 0x08
void sub_301B8A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301B8A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_301BD1  (0x301BD1) — 0 args, locals 0x0C
void sub_301BD1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301BD1()\n");
    ctx.eax = 0;
}

// sub_301C3F  (0x301C3F) — 1 arg (0x04), locals 0x04
void sub_301C3F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301C3F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301C5D  (0x301C5D) — 1 arg (0x04), locals 0x0C
void sub_301C5D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301C5D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301CA1  (0x301CA1) — 1 arg (0x04), locals 0x04
void sub_301CA1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301CA1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301CC1  (0x301CC1) — 3 args (0x0C), locals 0x0C
void sub_301CC1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301CC1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_301D18  (0x301D18) — 4 args (0x10), locals 0x0C
void sub_301D18(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301D18()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_301D86  (0x301D86) — 1 arg (0x04)
void sub_301D86(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301D86()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301D90  (0x301D90) — 1 arg (0x04), locals 0x08
void sub_301D90(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301D90()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301DC6  (0x301DC6) — 5 args (0x14), locals 0x04
void sub_301DC6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301DC6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_301DEB  (0x301DEB) — 0 args, locals 0x08
void sub_301DEB(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301DEB()\n");
    ctx.eax = 0;
}

// sub_301E5F  (0x301E5F) — 1 arg (0x04), locals 0x08
void sub_301E5F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301E5F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_301E95  (0x301E95) — 0 args, locals 0x08
void sub_301E95(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301E95()\n");
    ctx.eax = 0;
}

// sub_301F36  (0x301F36) — 8 args (0x20), locals 0x14
void sub_301F36(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_301F36()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x20);
}

// sub_302284  (0x302284) — 0 args, locals 0x0C
void sub_302284(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302284()\n");
    ctx.eax = 0;
}

// sub_302441  (0x302441) — 1 arg (0x04), locals 0x10
void sub_302441(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302441()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_302528  (0x302528) — 2 args (0x08), locals 0x04
void sub_302528(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302528()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_302574  (0x302574) — 2 args (0x08)
void sub_302574(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302574()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30264F  (0x30264F) — 2 args (0x08), locals 0x10
void sub_30264F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30264F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3028AD  (0x3028AD) — 2 args (0x08), locals 0x0C
void sub_3028AD(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3028AD()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30297D  (0x30297D) — 1 arg (0x04), locals 0x0C
void sub_30297D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30297D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_302AFA  (0x302AFA) — 4 args (0x10), locals 0x0C
void sub_302AFA(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302AFA()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_302BC1  (0x302BC1) — 4 args (0x10), locals 0x18
void sub_302BC1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302BC1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_302EF3  (0x302EF3) — 1 arg (0x04), locals 0x04
void sub_302EF3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302EF3()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_302FC7  (0x302FC7) — 2 args (0x08), locals 0x10
void sub_302FC7(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_302FC7()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_303000  (0x303000) — 4 args (0x10), locals 0x08
void sub_303000(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303000()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_303073  (0x303073) — 3 args (0x0C), locals 0x08
void sub_303073(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303073()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_30312A  (0x30312A) — 2 args (0x08), locals 0x24
void sub_30312A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30312A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30321B  (0x30321B) — 3 args (0x0C), locals 0x20
void sub_30321B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30321B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_3032D4  (0x3032D4) — 3 args (0x0C), locals 0x34
void sub_3032D4(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3032D4()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_3035CB  (0x3035CB) — 2 args (0x08), locals 0x0C
void sub_3035CB(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3035CB()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3037D1  (0x3037D1) — 2 args (0x08), locals 0x08
void sub_3037D1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3037D1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_303871  (0x303871) — 2 args (0x08), locals 0x2C
void sub_303871(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303871()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_303BC3  (0x303BC3) — 2 args (0x08), locals 0x14
void sub_303BC3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303BC3()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_303CA4  (0x303CA4) — 2 args (0x08), locals 0x24
void sub_303CA4(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303CA4()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_303E0D  (0x303E0D) — 1 arg (0x04), locals 0x08
void sub_303E0D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_303E0D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_304215  (0x304215) — 1 arg (0x04), locals 0x0C
void sub_304215(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304215()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30450F  (0x30450F) — 11 args (0x2C), locals 0x08
void sub_30450F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30450F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x2C);
}

// sub_304589  (0x304589) — 1 arg (0x04), locals 0x08
void sub_304589(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304589()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3045B5  (0x3045B5) — 1 arg (0x04)
void sub_3045B5(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3045B5()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3045D3  (0x3045D3) — 1 arg (0x04)
void sub_3045D3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3045D3()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3045F1  (0x3045F1) — 1 arg (0x04), locals 0x04
void sub_3045F1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3045F1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_304616  (0x304616) — 4 args (0x10)
void sub_304616(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304616()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_304640  (0x304640) — 1 arg (0x04), locals 0x04
void sub_304640(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304640()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_304664  (0x304664) — 2 args (0x08), locals 0x04
void sub_304664(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304664()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30471D  (0x30471D) — 1 arg (0x04), locals 0x20
void sub_30471D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30471D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3048F9  (0x3048F9) — 1 arg (0x04), locals 0x04
void sub_3048F9(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3048F9()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30492D  (0x30492D) — 1 arg (0x04), locals 0x18
void sub_30492D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30492D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_304B07  (0x304B07) — 2 args (0x08), locals 0x1C
void sub_304B07(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304B07()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_304C9F  (0x304C9F) — 4 args (0x10), locals 0x04
void sub_304C9F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304C9F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_304CD0  (0x304CD0) — 2 args (0x08), locals 0x38
void sub_304CD0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304CD0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_304F39  (0x304F39) — 4 args (0x10), locals 0x08
void sub_304F39(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304F39()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_304FF6  (0x304FF6) — 2 args (0x08), locals 0x1C
void sub_304FF6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_304FF6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_3052C1  (0x3052C1) — 12 args (0x30), locals 0x10
void sub_3052C1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3052C1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x30);
}

// sub_3054D0  (0x3054D0) — 4 args (0x10), locals 0x0C
void sub_3054D0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3054D0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3055B1  (0x3055B1) — 1 arg (0x04)
void sub_3055B1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055B1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3055C9  (0x3055C9) — 0 args (3-byte function)
void sub_3055C9(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055C9()\n");
}

// sub_3055CC  (0x3055CC) — 3 args (0x0C) (nullsub_6)
void sub_3055CC(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055CC()\n");
    GuestStackCleanup(ctx, 0x0C);
}

// sub_3055CF  (0x3055CF) — 1 arg (0x04)
void sub_3055CF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055CF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3055DC  (0x3055DC) — 1 arg (0x04)
void sub_3055DC(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055DC()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3055E9  (0x3055E9) — 0 args, locals 0x04
void sub_3055E9(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3055E9()\n");
    ctx.eax = 0;
}

// sub_305889  (0x305889) — 1 arg (0x04), locals 0x0C
void sub_305889(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_305889()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30599F  (0x30599F) — 1 arg (0x04), locals 0x28
void sub_30599F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30599F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_305F3A  (0x305F3A) — 5 args (0x14), locals 0x4C
void sub_305F3A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_305F3A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_306248  (0x306248) — 1 arg (0x04), locals 0x18
void sub_306248(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306248()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3064B3  (0x3064B3) — 2 args (0x08), locals 0x04
void sub_3064B3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3064B3()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30651F  (0x30651F) — 1 arg (0x04), locals 0x04
void sub_30651F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30651F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_306590  (0x306590) — 3 args (0x0C), locals 0x04
void sub_306590(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306590()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_3065CA  (0x3065CA) — 4 args (0x10), locals 0x24
void sub_3065CA(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3065CA()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_30688A  (0x30688A) — 1 arg (0x04), locals 0x08
void sub_30688A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30688A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30690A  (0x30690A) — 4 args (0x10), locals 0x0C
void sub_30690A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30690A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_306963  (0x306963) — 4 args (0x10), locals 0x04
void sub_306963(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306963()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3069A1  (0x3069A1) — 4 args (0x10), locals 0x04
void sub_3069A1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3069A1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3069DE  (0x3069DE) — 2 args (0x08), locals 0x04
void sub_3069DE(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3069DE()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_306A1B  (0x306A1B) — 1 arg (0x04), locals 0x10
void sub_306A1B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306A1B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_306BBD  (0x306BBD) — 2 args (0x08), locals 0x20
void sub_306BBD(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306BBD()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_306E56  (0x306E56) — 4 args (0x10), locals 0x10
void sub_306E56(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306E56()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_306EA2  (0x306EA2) — 4 args (0x10), locals 0x10
void sub_306EA2(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306EA2()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_306F3A  (0x306F3A) — 9 args (0x24), locals 0x18
void sub_306F3A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_306F3A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x24);
}

// sub_307264  (0x307264) — 2 args (0x08)
void sub_307264(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_307264()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30729F  (0x30729F) — 1 arg (0x04)
void sub_30729F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30729F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3072B8  (0x3072B8) — 2 args (0x08), locals 0x18
void sub_3072B8(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3072B8()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_307444  (0x307444) — 1 arg (0x04), locals 0x0C
void sub_307444(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_307444()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_3074A3  (0x3074A3) — 3 args (0x0C), locals 0x08
void sub_3074A3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3074A3()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_307524  (0x307524) — 3 args (0x0C), locals 0x08
void sub_307524(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_307524()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_3075A8  (0x3075A8) — 2 args (0x08), locals 0x08
void sub_3075A8(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3075A8()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_307617  (0x307617) — 2 args (0x08), locals 0x08
void sub_307617(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_307617()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_307689  (0x307689) — 4 args (0x10), locals 0x10
void sub_307689(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_307689()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_30772F  (0x30772F) — 3 args (0x0C), locals 0x08
void sub_30772F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30772F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_30780D  (0x30780D) — 3 args (0x0C), locals 0xB0
void sub_30780D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30780D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_308249  (0x308249) — 5 args (0x14), locals 0xB8
void sub_308249(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_308249()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_308ECF  (0x308ECF) — 4 args (0x10), locals 0x5C
void sub_308ECF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_308ECF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_30984A  (0x30984A) — 4 args (0x10), locals 0x14
void sub_30984A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30984A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_3098B5  (0x3098B5) — 3 args (0x0C), locals 0x1C
void sub_3098B5(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_3098B5()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_309A89  (0x309A89) — 2 args (0x08), locals 0x04
void sub_309A89(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_309A89()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_309B58  (0x309B58) — 2 args (0x08), locals 0x44
void sub_309B58(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_309B58()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_309C86  (0x309C86) — 2 args (0x08), locals 0x28
void sub_309C86(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_309C86()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_309EA6  (0x309EA6) — 1 arg (0x04), locals 0x8C
void sub_309EA6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_309EA6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_309FDC  (0x309FDC) — 2 args (0x08), locals 0x24
void sub_309FDC(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_309FDC()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30A5EC  (0x30A5EC) — 1 arg (0x04)
void sub_30A5EC(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30A5EC()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30A5F5  (0x30A5F5) — 7 args (0x1C), locals 0x8C
void sub_30A5F5(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30A5F5()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_30A951  (0x30A951) — 1 arg (0x04), locals 0x1C
void sub_30A951(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30A951()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30ACD1  (0x30ACD1) — 2 args (0x08), locals 0x10
void sub_30ACD1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30ACD1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30AD65  (0x30AD65) — 3 args (0x0C), locals 0x5C
void sub_30AD65(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30AD65()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_30B33B  (0x30B33B) — 2 args (0x08), locals 0x2C
void sub_30B33B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30B33B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30B61B  (0x30B61B) — 2 args (0x08), locals 0x20
void sub_30B61B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30B61B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_30B817  (0x30B817) — 4 args (0x10), locals 0x40
void sub_30B817(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30B817()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_30BAA0  (0x30BAA0) — 5 args (0x14), locals 0x04
void sub_30BAA0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BAA0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_30BAF8  (0x30BAF8) — 7 args (0x1C), locals 0x1A0
void sub_30BAF8(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BAF8()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_30BC0B  (0x30BC0B) — 7 args (0x1C), locals 0x1A0
void sub_30BC0B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BC0B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_30BD0A  (0x30BD0A) — 5 args (0x14), locals 0x1AC
void sub_30BD0A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BD0A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_30BE30  (0x30BE30) — 4 args (0x10), locals 0x64
void sub_30BE30(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BE30()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_30BE66  (0x30BE66) — 1 arg (0x04), locals 0x08
void sub_30BE66(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BE66()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_30BEC1  (0x30BEC1) — 6 args (0x18), locals 0x10
void sub_30BEC1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30BEC1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_30C0F0  (0x30C0F0) — 3 args (0x0C), locals 0x10C
void sub_30C0F0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30C0F0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_30C891  (0x30C891) — 5 args (0x14), locals 0x08
void sub_30C891(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_WMA] sub_30C891()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

#endif