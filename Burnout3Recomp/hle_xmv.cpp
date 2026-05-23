// ============================================================================
// HLE XMV (Xbox Movie Video) Backend
//
// Full implementation of the Xbox XMV decoder API used by Burnout 3.
// Parses the XMV container (Xbox-specific WMV2 + WMA wrapper), then uses the
// Windows WMVideo Decoder DMO to decode video and  the Windows WMA DMO for
// audio. Decoded BGRA pixels are written into pre-allocated guest surfaces.
//
// XMV File format (from FFmpeg libavformat/xmv.c):
//   File header (36 + audio_count*12 bytes):
//     [0x00] DWORD  (skip: redundant size)
//     [0x04] DWORD  this_packet_size (header_size + first_packet_content_size)
//     [0x08] DWORD  max_packet_size  (skip)
//     [0x0C] DWORD  "xobX" magic     (skip)
//     [0x10] DWORD  version (2 or 4)
//     [0x14] DWORD  video_width
//     [0x18] DWORD  video_height
//     [0x1C] DWORD  video_duration (ms)
//     [0x20] WORD   audio_track_count
//     [0x22] WORD   padding
//     Per audio track (12 bytes):
//       WORD  compression   (codec tag, 0x0161 = WMA2)
//       WORD  channels
//       DWORD sample_rate
//       WORD  bits_per_sample
//       WORD  flags
//   Each packet's content (after header / after previous packet):
//     [0x00] DWORD  next_packet_size
//     [0x04] DWORD  video_info: bits[22:0]=data_size, bits[30:23]=frame_count, bit31=has_extra
//     [0x08] DWORD  unknown
//     Per audio track (4 bytes):
//       DWORD  audio_info: bits[22:0]=data_size
//     [after audio headers] video data (video.data_size bytes)
//     [after video data] audio data (one block per track)
//   Each video frame within packet data:
//     DWORD  frame_hdr: bits[16:0]*4+4 = frame_size, bits[31:17] = timestamp
//     <frame_size bytes of WMV2 bitstream — XMV-specific LE format, needs byte-swap>
//
// Calling-convention notes:
//   All XMV functions are __stdcall (callee-cleanup, args on stack).
// ============================================================================

#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include "kernel/heap.h"
#include "kernel/memory.h"
#include "kernel/file_io.h"
#include <cstdio>
#include <cstring>
#include <fstream>
#include <filesystem>
#include <vector>
#include <unordered_map>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <chrono>

#ifdef _WIN32
#  ifndef WIN32_LEAN_AND_MEAN
#    define WIN32_LEAN_AND_MEAN
#  endif
#  ifndef NOMINMAX
#    define NOMINMAX
#  endif
#  include <Windows.h>
#  include <objbase.h>
#  include <mmreg.h>
#  include <mediaobj.h>
#  pragma comment(lib, "ole32")
#  pragma comment(lib, "msdmo")
#endif

// ============================================================================
// Windows DMO / GUIDs
// ============================================================================
#ifdef _WIN32
namespace {

// IID_IUnknown / IID_IMediaBuffer / IID_IMediaObject
static const IID  kIID_IUnknown2     = {0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}};
static const IID  kIID_IMediaBuffer2 = {0x59eff8b9,0x938c,0x4a26,{0x82,0xf2,0x95,0xcb,0x84,0xcd,0xc8,0x37}};

// CLSID: WMVideo Decoder DMO (handles WMV1/WMV2/WMV3)
static const CLSID kCLSID_WMVideoDMO = {0x82D353DF,0x90BD,0x4382,{0x8B,0xC2,0x3F,0x61,0x92,0xB7,0x6E,0x34}};
// CLSID: WMA Decoder DMO
static const CLSID kCLSID_WMADecDMO2 = {0x2eeb4adf,0x4578,0x4d10,{0xbc,0xa7,0xbb,0x95,0x5f,0x56,0x32,0x0a}};

// MEDIATYPE_Video {73646976-0000-0010-8000-00AA00389B71}
static const GUID kMediaType_Video2       = {0x73646976,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
// MEDIATYPE_Audio {73647561-0000-0010-8000-00AA00389B71}
static const GUID kMediaType_Audio2       = {0x73647561,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
// FORMAT_VideoInfo {05589F80-C356-11CE-BF01-00AA0055595A}
static const GUID kFORMAT_VideoInfo       = {0x05589F80,0xC356,0x11CE,{0xBF,0x01,0x00,0xAA,0x00,0x55,0x59,0x5A}};
// FORMAT_WaveFormatEx {05589F81-C356-11CE-BF01-00AA0055595A}
static const GUID kFORMAT_WaveFormatEx2   = {0x05589f81,0xc356,0x11ce,{0xbf,0x01,0x00,0xaa,0x00,0x55,0x59,0x5a}};
// MEDIASUBTYPE_WMV2  = FOURCC 'WMV2' = 0x32564D57
static const GUID kMediaSubtype_WMV2      = {0x32564D57,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};
// MEDIASUBTYPE_RGB32 {E436EB7A-524F-11CE-9F53-0020AF0BA770}
static const GUID kMediaSubtype_RGB32     = {0xE436EB7A,0x524F,0x11CE,{0x9F,0x53,0x00,0x20,0xAF,0x0B,0xA7,0x70}};
// MEDIASUBTYPE_PCM   {00000001-0000-0010-8000-00AA00389B71}
static const GUID kMediaSubtype_PCM2      = {0x00000001,0x0000,0x0010,{0x80,0x00,0x00,0xAA,0x00,0x38,0x9B,0x71}};

// Minimal VIDEOINFOHEADER (subset of DirectShow types, no <dshow.h> needed).
struct XMV_VIDEOINFOHEADER {
    RECT     rcSource;
    RECT     rcTarget;
    DWORD    dwBitRate;
    DWORD    dwBitErrorRate;
    LONGLONG AvgTimePerFrame;  // 100-ns units
    BITMAPINFOHEADER bmiHeader;
};

// Minimal IMediaBuffer implementation wrapping a host byte buffer.
class XmvMediaBuf final : public IMediaBuffer {
public:
    std::vector<BYTE> m_data;
    DWORD             m_used;
    LONG              m_ref;
    explicit XmvMediaBuf(DWORD cap) : m_data(cap, 0), m_used(0), m_ref(1) {}
    STDMETHODIMP QueryInterface(REFIID riid, void** ppv) override {
        if (IsEqualGUID(riid, kIID_IUnknown2) || IsEqualGUID(riid, kIID_IMediaBuffer2)) {
            *ppv = static_cast<IMediaBuffer*>(this); AddRef(); return S_OK;
        }
        *ppv = nullptr; return E_NOINTERFACE;
    }
    STDMETHODIMP_(ULONG) AddRef()  override { return (ULONG)InterlockedIncrement(&m_ref); }
    STDMETHODIMP_(ULONG) Release() override {
        ULONG r = (ULONG)InterlockedDecrement(&m_ref); if (!r) delete this; return r;
    }
    STDMETHODIMP SetLength(DWORD cb) override {
        if (cb > (DWORD)m_data.size()) return E_INVALIDARG; m_used = cb; return S_OK;
    }
    STDMETHODIMP GetMaxLength(DWORD* pcb) override {
        if (pcb) *pcb = (DWORD)m_data.size(); return S_OK;
    }
    STDMETHODIMP GetBufferAndLength(BYTE** pp, DWORD* pcb) override {
        if (pp)  *pp  = m_data.data();
        if (pcb) *pcb = m_used;
        return S_OK;
    }
};

} // anonymous namespace
#endif // _WIN32

// ============================================================================
// Host-side XMV decoder state
// ============================================================================
struct HLE_XmvDecoder {
    uint32_t    guestObjAddr;

    // File I/O
    std::ifstream  file;

    // Stream metadata (parsed from XMV file header)
    uint32_t    videoWidth;
    uint32_t    videoHeight;
    uint32_t    videoDuration;   // total duration in milliseconds

    struct AudioTrack {
        uint16_t compression;    // codec tag (0x0001 = PCM, 0x0161 = WMA2)
        uint16_t channels;
        uint32_t sampleRate;
        uint16_t bitsPerSample;
        uint16_t flags;
        uint32_t blockAlign;     // XMV_BLOCK_ALIGN_SIZE * channels (for ADPCM)
        bool     isPCM = false;  // raw PCM — no DMO needed

        // Per-packet decode state
        uint32_t dataSize;
        int64_t  dataOffset;
        uint32_t frameSize;

#ifdef _WIN32
        IMediaObject* pDMO = nullptr;  // WMA decoder (or null; null for PCM)
#endif
    };
    std::vector<AudioTrack> audioTracks;

    // Packet navigation
    int64_t  nextPacketOffset;   // file byte offset of next packet's content start
    uint32_t nextPacketSize;     // byte count of that content region

    // Video packet decode state
    uint32_t vidDataSize;
    int64_t  vidDataOffset;
    uint32_t vidCurrentFrame;
    uint32_t vidFrameCount;
    bool     vidHasExtra;
    uint8_t  vidExtra[4];        // transformed (BE) WMV2 extradata

#ifdef _WIN32
    IMediaObject*        pVideoDMO         = nullptr;
    bool                 vidDMOReady       = false;
    bool                 vidExtradataSet   = false;
    std::vector<uint8_t> hostPixBuf;       // host-side BGRA decode buffer
    uint32_t             hostPixBufStride  = 0;
    // Decoded PCM ring buffer (S16 interleaved stereo at 48 kHz, for all audio tracks)
    std::vector<int16_t> pcmRing;
    uint32_t             pcmRingWrite = 0;  // write index in samples
    uint32_t             pcmRingRead  = 0;  // read  index in samples
    std::mutex           pcmMtx;
    uint32_t             pcmChannels  = 0;
    uint32_t             pcmSampleRate = 0;
    static constexpr uint32_t kPcmRingFrames = 48000 * 2; // 2 seconds at 48 kHz stereo
#endif

    // Frame timing for throttle
    std::chrono::steady_clock::time_point lastFrameTime;
    double framePeriodMs = 33.333;  // video frame period (ms); retained for bg-thread pacing only
    // Display-field pacing: fire status=1 at 60 Hz (16.667 ms) regardless of video fps,
    // because on real Xbox the game loop waits for a display field (not a video frame) before
    // calling D3DDevice_Swap.  Throttling to 30 fps here causes the game's render loop to
    // swap at 30 fps instead of 60 fps.
    static constexpr double kFieldPeriodMs = 1000.0 / 60.0;  // ~16.667 ms
    bool firstFrame = true;

    bool eof        = false;
    bool terminated = false;

    // Background decode thread: pre-decodes the next video frame asynchronously
    // so GetNextFrame never stalls on DMO decode latency.
    std::thread              bgThread;
    std::mutex               bgMtx;
    std::condition_variable  bgWorkCv;    // main → bg: bgRequested was set
    bool                     bgShutdown   = false;
    bool                     bgRequested  = true;  // initial: decode first frame immediately
    bool                     bgFrameReady = false;  // bgPixBuf holds a decoded frame
    bool                     bgEof        = false;  // bg thread reached end of stream
    std::vector<uint8_t>     bgPixBuf;   // decoded BGRA frame (bg thread writes, main reads)
};

// Forward declaration: SDL audio init (implemented in hle_dsound.cpp)
void HLE_EnsureAudioInit(uint8_t* base);
// Forward declaration: D3D11 texture cache invalidation (implemented in hle_d3d.cpp)
void HLE_InvalidateTextureSRV(uint32_t texAddr);

static std::mutex                                     g_xmvMtx;
static std::unordered_map<uint32_t, HLE_XmvDecoder*> g_xmvMap; // guestObj → decoder

// Drain up to `frames` S16LE stereo frames from all active XMV decoders'
// PCM ring buffers.  Called from the SDL audio callback in hle_dsound.cpp.
void XmvMixAudioFrames(int16_t* outStereo, int frames)
{
    // Take a non-blocking snapshot of active decoders to avoid deadlock with
    // the game thread that holds g_xmvMtx while filling pcmRing.
    std::vector<HLE_XmvDecoder*> decoders;
    {
        std::unique_lock<std::mutex> lk(g_xmvMtx, std::try_to_lock);
        if (!lk.owns_lock()) return; // skip this callback if game thread has the lock
        for (auto& kv : g_xmvMap)
            if (kv.second) decoders.push_back(kv.second);
    }

    for (HLE_XmvDecoder* dec : decoders) {
#ifdef _WIN32
        std::unique_lock<std::mutex> plk(dec->pcmMtx, std::try_to_lock);
        if (!plk.owns_lock() || dec->pcmRing.empty()) continue;

        const uint32_t ringSize   = (uint32_t)dec->pcmRing.size(); // in samples
        const uint32_t srcCh      = dec->pcmChannels ? dec->pcmChannels : 2;
        const uint32_t srcRate    = dec->pcmSampleRate ? dec->pcmSampleRate : 48000;
        constexpr uint32_t dstRate = 48000;

        // How many source samples are available?
        uint32_t avail;
        if (dec->pcmRingWrite >= dec->pcmRingRead)
            avail = dec->pcmRingWrite - dec->pcmRingRead;
        else
            avail = ringSize - dec->pcmRingRead + dec->pcmRingWrite;

        if (avail == 0) continue;

        for (int i = 0; i < frames; i++) {
            uint32_t srcFrame = (uint32_t)((double)i * srcRate / dstRate);
            uint32_t srcSample = srcFrame * srcCh;
            if (srcSample >= avail) break;

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
        // Advance read cursor
        uint32_t consumed = (uint32_t)((double)frames * srcRate / dstRate) * srcCh;
        if (consumed > avail) consumed = avail;
        dec->pcmRingRead = (dec->pcmRingRead + consumed) % ringSize;
#endif
    }
}

// ============================================================================
// XMV extradata transformation (from FFmpeg xmv.c: xmv_read_extradata)
// XMV stores the WMV2 sequence header in a compact 4-byte LE word; standard
// WMV2 decoders expect it in 4-byte BE form with field ordering changed.
// ============================================================================
static void XmvTransformExtradata(const uint8_t* raw, uint8_t* out)
{
    uint32_t data = (uint32_t)raw[0]
                  | ((uint32_t)raw[1] << 8)
                  | ((uint32_t)raw[2] << 16)
                  | ((uint32_t)raw[3] << 24);

    int mspel_bit      = (data >> 0) & 1;
    int loop_filter    = (data >> 1) & 1;
    int abt_flag       = (data >> 2) & 1;
    int j_type_bit     = (data >> 3) & 1;
    int top_left_mv    = (data >> 4) & 1;
    int per_mb_rl      = (data >> 5) & 1;
    int slice_count    = (data >> 6) & 7;

    uint32_t r = 0;
    r |= ((uint32_t)mspel_bit   << 15);
    r |= ((uint32_t)loop_filter << 14);
    r |= ((uint32_t)abt_flag    << 13);
    r |= ((uint32_t)j_type_bit  << 12);
    r |= ((uint32_t)top_left_mv << 11);
    r |= ((uint32_t)per_mb_rl   << 10);
    r |= ((uint32_t)slice_count <<  7);

    // Big-endian output (WMV2 standard byte order)
    out[0] = (uint8_t)(r >> 24);
    out[1] = (uint8_t)(r >> 16);
    out[2] = (uint8_t)(r >>  8);
    out[3] = (uint8_t)(r >>  0);
}

// ============================================================================
// Parse a packet header at the current file position.
// Returns false on I/O error.
// ============================================================================
static bool XmvProcessPacketHeader(HLE_XmvDecoder& dec)
{
    auto& f = dec.file;

    // [0] DWORD: next_packet_size
    uint32_t nextPktSize = 0;
    f.read(reinterpret_cast<char*>(&nextPktSize), 4);
    if (!f) return false;
    dec.nextPacketSize = nextPktSize;

    // [4-7] DWORD + [8-11] DWORD — video info (packed: data_size | frame_count | has_extra)
    uint32_t vidWord0 = 0, vidWord1 = 0;
    f.read(reinterpret_cast<char*>(&vidWord0), 4);
    f.read(reinterpret_cast<char*>(&vidWord1), 4);
    if (!f) return false;

    dec.vidDataSize    = vidWord0 & 0x007FFFFFu;
    dec.vidCurrentFrame= 0;
    dec.vidFrameCount  = (vidWord0 >> 23) & 0xFFu;
    dec.vidHasExtra    = ((vidWord0 >> 31) & 1) != 0;

    // XMV quirk: subtract 4 bytes from video data for each audio track
    // (audio blocks borrow 4 bytes from video allocation)
    uint32_t nAudio = (uint32_t)dec.audioTracks.size();
    if (dec.vidDataSize >= nAudio * 4)
        dec.vidDataSize -= nAudio * 4;

    if (dec.vidFrameCount == 0)
        dec.vidFrameCount = 1;

    // Audio track sub-headers: one DWORD each
    for (auto& at : dec.audioTracks) {
        uint32_t aWord = 0;
        f.read(reinterpret_cast<char*>(&aWord), 4);
        if (!f) return false;
        at.dataSize  = aWord & 0x007FFFFFu;
        at.frameSize = (dec.vidFrameCount > 0)
                     ? (at.dataSize / dec.vidFrameCount) : at.dataSize;
        at.frameSize -= (at.blockAlign > 0) ? (at.frameSize % at.blockAlign) : 0;
    }

    // Data layout within this packet (relative to current file position)
    int64_t base = (int64_t)f.tellg();
    dec.vidDataOffset = base;
    int64_t cur = base + (int64_t)dec.vidDataSize;
    for (auto& at : dec.audioTracks) {
        at.dataOffset = cur;
        cur += (int64_t)at.dataSize;
    }

    // If video has extradata (4 bytes prepended to video data), consume it now
    if (dec.vidHasExtra && dec.vidDataSize >= 4) {
        uint8_t raw[4] = {};
        f.seekg(dec.vidDataOffset);
        f.read(reinterpret_cast<char*>(raw), 4);
        XmvTransformExtradata(raw, dec.vidExtra);
        dec.vidExtradataSet = true;
        dec.vidDataOffset += 4;
        dec.vidDataSize   -= 4;
    }

    return true;
}

// ============================================================================
// Advance to the next packet.  Returns false at EOF or on error.
// ============================================================================
static bool XmvFetchNextPacket(HLE_XmvDecoder& dec)
{
    if (dec.nextPacketSize == 0)
        return false;   // EOF

    // Save this packet's offset and total size, then seek and parse.
    // nextPacketOffset advances AFTER processing (mirrors FFmpeg xmv_fetch_new_packet).
    int64_t  thisOffset = dec.nextPacketOffset;
    uint32_t thisSize   = dec.nextPacketSize;

    dec.file.seekg(thisOffset);
    if (!dec.file) return false;

    dec.nextPacketSize = 0; // will be updated by XmvProcessPacketHeader
    bool ok = XmvProcessPacketHeader(dec);
    if (!ok) return false;

    dec.nextPacketOffset = thisOffset + (int64_t)thisSize;
    return true;
}

// ============================================================================
// Windows DMO helpers
// ============================================================================
#ifdef _WIN32

// Set up WMVideo DMO.  Extradata (4 bytes, transformed) is appended after
// the VIDEOINFOHEADER in the input format blob.
static bool XmvInitVideoDMO(HLE_XmvDecoder& dec)
{
    if (dec.pVideoDMO) return true;

    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    // IID_IMediaObject = {D8AD0F58-5494-4102-97C5-EC798E59BCF4}
    static const IID kIID_IMediaObject = {0xD8AD0F58,0x5494,0x4102,
        {0x97,0xC5,0xEC,0x79,0x8E,0x59,0xBC,0xF4}};

    IMediaObject* pDMO = nullptr;
    HRESULT hr = CoCreateInstance(
        reinterpret_cast<const CLSID&>(kCLSID_WMVideoDMO),
        nullptr, CLSCTX_INPROC_SERVER,
        kIID_IMediaObject,
        reinterpret_cast<void**>(&pDMO));
    if (FAILED(hr) || !pDMO) {
        fprintf(stderr, "[HLE_XMV] WMVideo DMO not available (hr=0x%08X)\n", (unsigned)hr);
        return false;
    }

    // ----- Build input format: VIDEOINFOHEADER + 4 bytes extradata -----
    static const uint32_t kExtradataBytes = 4;
    const uint32_t fmtSize = (uint32_t)sizeof(XMV_VIDEOINFOHEADER) + kExtradataBytes;
    std::vector<uint8_t> fmtBuf(fmtSize, 0);

    auto* vih = reinterpret_cast<XMV_VIDEOINFOHEADER*>(fmtBuf.data());
    vih->rcSource = { 0, 0, (LONG)dec.videoWidth, (LONG)dec.videoHeight };
    vih->rcTarget = vih->rcSource;
    vih->dwBitRate        = 0;
    vih->dwBitErrorRate   = 0;
    vih->AvgTimePerFrame  = 333333; // ~30 fps (100-ns units)
    vih->bmiHeader.biSize        = sizeof(BITMAPINFOHEADER) + kExtradataBytes;
    vih->bmiHeader.biWidth       = (LONG)dec.videoWidth;
    vih->bmiHeader.biHeight      = (LONG)dec.videoHeight;
    vih->bmiHeader.biPlanes      = 1;
    vih->bmiHeader.biBitCount    = 24;
    vih->bmiHeader.biCompression = 0x32564D57u; // 'WMV2'
    vih->bmiHeader.biSizeImage   = dec.videoWidth * dec.videoHeight * 3;
    // Append extradata (may be zero if first packet not yet processed)
    if (dec.vidExtradataSet)
        memcpy(fmtBuf.data() + sizeof(XMV_VIDEOINFOHEADER), dec.vidExtra, 4);

    DMO_MEDIA_TYPE mtIn = {};
    memcpy(&mtIn.majortype, &kMediaType_Video2,   sizeof(GUID));
    memcpy(&mtIn.subtype,   &kMediaSubtype_WMV2,  sizeof(GUID));
    memcpy(&mtIn.formattype,&kFORMAT_VideoInfo,   sizeof(GUID));
    mtIn.bFixedSizeSamples    = FALSE;
    mtIn.bTemporalCompression = TRUE;
    mtIn.cbFormat             = fmtSize;
    mtIn.pbFormat             = (BYTE*)CoTaskMemAlloc(fmtSize);
    if (mtIn.pbFormat) memcpy(mtIn.pbFormat, fmtBuf.data(), fmtSize);

    hr = pDMO->SetInputType(0, &mtIn, 0);
    CoTaskMemFree(mtIn.pbFormat);
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] WMVideo DMO: SetInputType failed 0x%08X\n", (unsigned)hr);
        pDMO->Release();
        return false;
    }

    // ----- Build output format: VIDEOINFOHEADER for RGB32 -----
    XMV_VIDEOINFOHEADER vihOut = {};
    vihOut.rcSource = { 0, 0, (LONG)dec.videoWidth, (LONG)dec.videoHeight };
    vihOut.rcTarget = vihOut.rcSource;
    vihOut.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
    vihOut.bmiHeader.biWidth       = (LONG)dec.videoWidth;
    vihOut.bmiHeader.biHeight      = -(LONG)dec.videoHeight; // top-down
    vihOut.bmiHeader.biPlanes      = 1;
    vihOut.bmiHeader.biBitCount    = 32;
    vihOut.bmiHeader.biCompression = 0;           // BI_RGB
    vihOut.bmiHeader.biSizeImage   = dec.videoWidth * dec.videoHeight * 4;

    DMO_MEDIA_TYPE mtOut = {};
    memcpy(&mtOut.majortype, &kMediaType_Video2,  sizeof(GUID));
    memcpy(&mtOut.subtype,   &kMediaSubtype_RGB32, sizeof(GUID));
    memcpy(&mtOut.formattype,&kFORMAT_VideoInfo,   sizeof(GUID));
    mtOut.bFixedSizeSamples    = TRUE;
    mtOut.bTemporalCompression = FALSE;
    mtOut.cbFormat             = sizeof(XMV_VIDEOINFOHEADER);
    mtOut.pbFormat             = (BYTE*)CoTaskMemAlloc(sizeof(XMV_VIDEOINFOHEADER));
    if (mtOut.pbFormat) memcpy(mtOut.pbFormat, &vihOut, sizeof(XMV_VIDEOINFOHEADER));

    hr = pDMO->SetOutputType(0, &mtOut, 0);
    CoTaskMemFree(mtOut.pbFormat);
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] WMVideo DMO: SetOutputType (RGB32) failed 0x%08X\n", (unsigned)hr);
        pDMO->Release();
        return false;
    }

    hr = pDMO->AllocateStreamingResources();
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] WMVideo DMO: AllocateStreamingResources failed 0x%08X\n", (unsigned)hr);
        pDMO->Release();
        return false;
    }

    dec.pVideoDMO        = pDMO;
    dec.vidDMOReady      = true;
    dec.hostPixBufStride = dec.videoWidth * 4;
    dec.hostPixBuf.assign((size_t)dec.videoWidth * dec.videoHeight * 4, 0);
    fprintf(stderr, "[HLE_XMV] WMVideo DMO ready (%ux%u, RGB32)\n",
            dec.videoWidth, dec.videoHeight);
    return true;
}

// Initialise the WMA decoder DMO for a single audio track.
static bool XmvInitAudioDMO(HLE_XmvDecoder& dec, HLE_XmvDecoder::AudioTrack& at)
{
    // PCM audio (0x0001): no DMO needed, just init the ring buffer
    if (at.compression == 0x0001) {
        at.isPCM = true;
        std::lock_guard<std::mutex> lk(dec.pcmMtx);
        if (dec.pcmRing.empty()) {
            dec.pcmChannels   = at.channels;
            dec.pcmSampleRate = at.sampleRate;
            const uint32_t ringFrames = HLE_XmvDecoder::kPcmRingFrames;
            dec.pcmRing.assign(ringFrames * at.channels, 0);
            dec.pcmRingWrite = 0;
            dec.pcmRingRead  = 0;
        }
        fprintf(stderr, "[HLE_XMV] PCM audio track ready (%u ch, %u Hz, %u bps)\n",
                at.channels, at.sampleRate, at.bitsPerSample);
        return true;
    }

    if (at.pDMO) return true;
    if (at.compression != 0x0161) {
        // Only PCM (0x0001) and WMA2 (0x0161) are supported
        fprintf(stderr, "[HLE_XMV] Unsupported audio compression 0x%04X\n", at.compression);
        return false;
    }

    CoInitializeEx(nullptr, COINIT_MULTITHREADED);

    static const IID kIID_IMediaObject = {0xD8AD0F58,0x5494,0x4102,
        {0x97,0xC5,0xEC,0x79,0x8E,0x59,0xBC,0xF4}};

    IMediaObject* pDMO = nullptr;
    HRESULT hr = CoCreateInstance(
        reinterpret_cast<const CLSID&>(kCLSID_WMADecDMO2),
        nullptr, CLSCTX_INPROC_SERVER,
        kIID_IMediaObject,
        reinterpret_cast<void**>(&pDMO));
    if (FAILED(hr) || !pDMO) {
        fprintf(stderr, "[HLE_XMV] WMA DMO not available (hr=0x%08X)\n", (unsigned)hr);
        return false;
    }

    // Build WAVEFORMATEX for WMA2 input
    const uint32_t cbSize     = 10; // WMA2 extra data size
    const uint32_t fmtBufSize = sizeof(WAVEFORMATEX) + cbSize;
    std::vector<uint8_t> fmtBuf(fmtBufSize, 0);
    auto* wfx = reinterpret_cast<WAVEFORMATEX*>(fmtBuf.data());
    wfx->wFormatTag      = at.compression;   // 0x0161
    wfx->nChannels       = at.channels;
    wfx->nSamplesPerSec  = at.sampleRate;
    wfx->wBitsPerSample  = at.bitsPerSample ? at.bitsPerSample : 16;
    wfx->nBlockAlign     = at.blockAlign ? (WORD)at.blockAlign : (wfx->nChannels * 2);
    wfx->nAvgBytesPerSec = wfx->nSamplesPerSec * wfx->nBlockAlign;
    wfx->cbSize          = (WORD)cbSize;

    DMO_MEDIA_TYPE mtIn = {};
    memcpy(&mtIn.majortype, &kMediaType_Audio2,       sizeof(GUID));
    memcpy(&mtIn.subtype,   &kMediaSubtype_PCM2,      sizeof(GUID));  // will be set by DMO
    memcpy(&mtIn.formattype,&kFORMAT_WaveFormatEx2,   sizeof(GUID));
    // Use the wFormatTag as the subtype GUID (standard audio subtype mapping)
    mtIn.subtype.Data1 = at.compression;
    mtIn.bFixedSizeSamples    = FALSE;
    mtIn.bTemporalCompression = TRUE;
    mtIn.cbFormat             = fmtBufSize;
    mtIn.pbFormat             = (BYTE*)CoTaskMemAlloc(fmtBufSize);
    if (mtIn.pbFormat) memcpy(mtIn.pbFormat, fmtBuf.data(), fmtBufSize);

    hr = pDMO->SetInputType(0, &mtIn, 0);
    CoTaskMemFree(mtIn.pbFormat);
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] WMA DMO SetInputType failed 0x%08X\n", (unsigned)hr);
        pDMO->Release();
        return false;
    }

    // Output: PCM S16
    WAVEFORMATEX wfxOut = {};
    wfxOut.wFormatTag      = WAVE_FORMAT_PCM;
    wfxOut.nChannels       = at.channels;
    wfxOut.nSamplesPerSec  = at.sampleRate;
    wfxOut.wBitsPerSample  = 16;
    wfxOut.nBlockAlign     = wfxOut.nChannels * 2;
    wfxOut.nAvgBytesPerSec = wfxOut.nSamplesPerSec * wfxOut.nBlockAlign;
    wfxOut.cbSize          = 0;

    DMO_MEDIA_TYPE mtOut = {};
    memcpy(&mtOut.majortype, &kMediaType_Audio2,      sizeof(GUID));
    memcpy(&mtOut.subtype,   &kMediaSubtype_PCM2,     sizeof(GUID));
    memcpy(&mtOut.formattype,&kFORMAT_WaveFormatEx2,  sizeof(GUID));
    mtOut.bFixedSizeSamples    = TRUE;
    mtOut.bTemporalCompression = FALSE;
    mtOut.cbFormat             = sizeof(WAVEFORMATEX);
    mtOut.pbFormat             = (BYTE*)CoTaskMemAlloc(sizeof(WAVEFORMATEX));
    if (mtOut.pbFormat) memcpy(mtOut.pbFormat, &wfxOut, sizeof(WAVEFORMATEX));

    hr = pDMO->SetOutputType(0, &mtOut, 0);
    CoTaskMemFree(mtOut.pbFormat);
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] WMA DMO SetOutputType failed 0x%08X\n", (unsigned)hr);
        pDMO->Release();
        return false;
    }

    at.pDMO = pDMO;
    fprintf(stderr, "[HLE_XMV] WMA DMO ready (%u ch, %u Hz)\n", at.channels, at.sampleRate);

    // Initialise the PCM ring buffer on the first audio track that succeeds
    std::lock_guard<std::mutex> lk(dec.pcmMtx);
    if (dec.pcmRing.empty()) {
        dec.pcmChannels   = at.channels;
        dec.pcmSampleRate = at.sampleRate;
        const uint32_t ringFrames = HLE_XmvDecoder::kPcmRingFrames;
        dec.pcmRing.assign(ringFrames * at.channels, 0);
        dec.pcmRingWrite = 0;
        dec.pcmRingRead  = 0;
    }
    return true;
}

// Decode one audio frame slice from the XMV file and push PCM into the ring buffer.
static void XmvDecodeAudioSlice(HLE_XmvDecoder& dec, HLE_XmvDecoder::AudioTrack& at,
                                 int64_t dataOffset, uint32_t dataSize)
{
    if (dataSize == 0) return;

    // PCM audio: copy raw S16 samples directly into the ring buffer
    if (at.isPCM) {
        // dataSize is in bytes; each sample is bitsPerSample/8 bytes
        const uint32_t bytesPerSample = at.bitsPerSample / 8;
        if (bytesPerSample == 0) return;
        std::vector<uint8_t> raw(dataSize);
        dec.file.seekg(dataOffset);
        dec.file.read(reinterpret_cast<char*>(raw.data()), dataSize);
        if (!dec.file) return;
        const uint32_t nSamples = dataSize / bytesPerSample;
        std::lock_guard<std::mutex> lk(dec.pcmMtx);
        if (dec.pcmRing.empty()) return;
        const uint32_t ringSize = (uint32_t)dec.pcmRing.size();
        if (bytesPerSample == 2) {
            const int16_t* pcm = reinterpret_cast<const int16_t*>(raw.data());
            for (uint32_t s = 0; s < nSamples; s++) {
                dec.pcmRing[dec.pcmRingWrite] = pcm[s];
                dec.pcmRingWrite = (dec.pcmRingWrite + 1) % ringSize;
            }
        } else if (bytesPerSample == 1) {
            // 8-bit unsigned PCM → convert to S16
            for (uint32_t s = 0; s < nSamples; s++) {
                dec.pcmRing[dec.pcmRingWrite] = (int16_t)((raw[s] - 128) << 8);
                dec.pcmRingWrite = (dec.pcmRingWrite + 1) % ringSize;
            }
        }
        return;
    }

    if (!at.pDMO) return;

    // Read compressed audio data from file
    std::vector<uint8_t> raw(dataSize);
    dec.file.seekg(dataOffset);
    dec.file.read(reinterpret_cast<char*>(raw.data()), dataSize);
    if (!dec.file) return;

    // Feed to WMA DMO
    auto* pInBuf = new XmvMediaBuf(dataSize);
    memcpy(pInBuf->m_data.data(), raw.data(), dataSize);
    pInBuf->m_used = dataSize;
    dec.pVideoDMO; // unused here
    HRESULT hr = at.pDMO->ProcessInput(0, pInBuf, 0, 0, 0);
    pInBuf->Release();
    if (FAILED(hr)) return;

    // Drain all PCM output
    constexpr uint32_t kOutBufSamples = 4096;
    const uint32_t outBufBytes = kOutBufSamples * at.channels * 2;

    for (;;) {
        auto* pOutBuf = new XmvMediaBuf(outBufBytes);
        DMO_OUTPUT_DATA_BUFFER outInfo = {};
        outInfo.pBuffer = pOutBuf;
        DWORD status = 0;
        hr = at.pDMO->ProcessOutput(0, 1, &outInfo, &status);
        if (FAILED(hr) || pOutBuf->m_used == 0) {
            pOutBuf->Release();
            break;
        }

        const int16_t* pcm = reinterpret_cast<const int16_t*>(pOutBuf->m_data.data());
        const uint32_t nSamples = pOutBuf->m_used / 2; // S16 samples

        {
            std::lock_guard<std::mutex> lk(dec.pcmMtx);
            if (!dec.pcmRing.empty()) {
                const uint32_t ringSize = (uint32_t)dec.pcmRing.size();
                for (uint32_t s = 0; s < nSamples; s++) {
                    dec.pcmRing[dec.pcmRingWrite] = pcm[s];
                    dec.pcmRingWrite = (dec.pcmRingWrite + 1) % ringSize;
                }
            }
        }
        pOutBuf->Release();
        if (!(outInfo.dwStatus & DMO_OUTPUT_DATA_BUFFERF_INCOMPLETE)) break;
    }
}

// Decode one WMV2 frame using the Windows DMO.
// rawData: XMV-encoded bytes (to be byte-swapped in place before feeding).
// Writes BGRA pixels into dec.hostPixBuf (then caller copies to guest).
static bool XmvDecodeVideoFrame(HLE_XmvDecoder& dec, std::vector<uint8_t>& rawData)
{
    if (!dec.vidDMOReady) return false;

    const uint32_t frameBytes = (uint32_t)rawData.size();

    // Byte-swap every DWORD: XMV uses inverted bit order (LE) within each word
    for (uint32_t i = 0; i + 3 < frameBytes; i += 4) {
        uint8_t tmp;
        tmp = rawData[i+0]; rawData[i+0] = rawData[i+3]; rawData[i+3] = tmp;
        tmp = rawData[i+1]; rawData[i+1] = rawData[i+2]; rawData[i+2] = tmp;
    }

    // Feed input
    auto* pInBuf = new XmvMediaBuf(frameBytes);
    memcpy(pInBuf->m_data.data(), rawData.data(), frameBytes);
    pInBuf->m_used = frameBytes;

    HRESULT hr = dec.pVideoDMO->ProcessInput(0, pInBuf, 0, 0, 0);
    pInBuf->Release();
    if (FAILED(hr)) {
        fprintf(stderr, "[HLE_XMV] ProcessInput failed 0x%08X\n", (unsigned)hr);
        return false;
    }

    // Collect output
    const uint32_t outSize = dec.videoWidth * dec.videoHeight * 4;
    auto* pOutBuf = new XmvMediaBuf(outSize);

    DMO_OUTPUT_DATA_BUFFER outInfo = {};
    outInfo.pBuffer = pOutBuf;
    DWORD status = 0;

    hr = dec.pVideoDMO->ProcessOutput(0, 1, &outInfo, &status);
    if (SUCCEEDED(hr) && pOutBuf->m_used > 0) {
        const uint32_t copy = pOutBuf->m_used < outSize ? (uint32_t)pOutBuf->m_used : outSize;
        // DMO outputs bottom-up BGRA when biHeight is positive; we requested
        // top-down (negative height), so just copy straight.
        memcpy(dec.hostPixBuf.data(), pOutBuf->m_data.data(), copy);
    } else {
        // On failure or no output yet, keep previous frame (or black)
    }
    pOutBuf->Release();
    return SUCCEEDED(hr);
}

#endif // _WIN32

// ============================================================================
// Return the pixel data address for a surface by reading the surface struct's
// Data field (+0x04), which was populated by D3D_CreateSurfaceOfTexture with
// the game's pre-allocated GPU data address (already & 0x0FFFFFFF).
// Also syncs the parent texture's Data field so SetTexture + DrawVerticesUP
// sampling always reads from the same location we decode into.
// ============================================================================
static uint32_t GetSurfaceDataAddr(uint8_t* base, uint32_t surfAddr)
{
    if (!surfAddr) return 0;
    // Surface struct layout (X_D3DSurface):  +0x00 Common, +0x04 Data, +0x14 Parent
    uint32_t dataAddr   = X86_MEM_READ_u32(base, surfAddr + 0x04);
    uint32_t parentAddr = X86_MEM_READ_u32(base, surfAddr + 0x14);
    if (parentAddr)
        X86_MEM_WRITE_u32(base, parentAddr + 0x04, dataAddr);
    return dataAddr;
}

// ============================================================================
// Public XMV Decoder API
// ============================================================================

// Forward declaration — defined below, after the helpers it calls.
static void XmvBgThread(HLE_XmvDecoder* dec);

// XMVDecoder_CreateDecoderForFile  (0x2CC30D) — 3 args (0x0C), ret 12
//
// HRESULT XMVDecoder_CreateDecoderForFile(
//     LPCSTR       szFilePath,   // arg0: Xbox-path ANSI C string
//     DWORD        dwUnknown,    // arg1: flags / context (ignored here)
//     XMVDECODER** ppDecoder     // arg2: output decoder handle
// );
//
// Opens the XMV file, parses the stream header and schedules the first
// packet.  Allocates an 8-byte guest decoder object and sets *ppDecoder.
// Returns S_OK on success, E_FAIL / E_INVALIDARG on error.
void XMVDecoder_CreateDecoderForFile(X86Context& ctx, uint8_t* base)
{
    // arg0 = flags (0x01/0x03), arg1 = path ptr (ecx), arg2 = ppDecoder
    uint32_t guestPathPtr = GuestArg32(ctx, base, 1);
    // arg1 (dwUnknown) not needed
    uint32_t ppDecoder    = GuestArg32(ctx, base, 2);

    if (!ppDecoder) {
        fprintf(stderr, "[HLE_XMV] CreateDecoderForFile: null ppDecoder\n");
        ctx.eax = 0x80070057u; // E_INVALIDARG
        GuestStackCleanup(ctx, 0x0C);
        return;
    }
    X86_MEM_WRITE_u32(base, ppDecoder, 0); // zero out first

    // Read the ANSI file path from guest memory
    const char* guestPath = guestPathPtr
        ? reinterpret_cast<const char*>(base + guestPathPtr)
        : nullptr;
    if (!guestPath || guestPath[0] == '\0') {
        fprintf(stderr, "[HLE_XMV] CreateDecoderForFile: empty path\n");
        ctx.eax = 0x80070057u;
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    // Translate Xbox path → host filesystem path
    std::filesystem::path hostPath = TranslateXboxPath(
        std::string_view(guestPath, strnlen(guestPath, 256)));
    fprintf(stderr, "[HLE_XMV] CreateDecoderForFile(\"%s\")\n", guestPath);
    fprintf(stderr, "[HLE_XMV]   host path: %s\n",
            hostPath.string().c_str());

    // Open the XMV file
    std::ifstream f(hostPath, std::ios::binary);
    if (!f) {
        fprintf(stderr, "[HLE_XMV] File not found: %s\n", hostPath.string().c_str());
        ctx.eax = 0x80004005u; // E_FAIL
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    // ---- Parse file header ----
    //  [0x00] DWORD  (skip: redundant next_pkt_size from container frame)
    //  [0x04] DWORD  this_packet_size  (= header_size + first_content_size)
    //  [0x08] DWORD  max_packet_size   (skip)
    //  [0x0C] DWORD  "xobX"            (skip)
    //  [0x10] DWORD  version
    //  [0x14] DWORD  video_width
    //  [0x18] DWORD  video_height
    //  [0x1C] DWORD  video_duration_ms
    //  [0x20] WORD   audio_track_count
    //  [0x22] WORD   padding
    //  Per audio track (12 bytes each): compression, channels, sample_rate,
    //                                   bits_per_sample, flags

    auto readU32 = [&]() -> uint32_t {
        uint32_t v = 0; f.read(reinterpret_cast<char*>(&v), 4); return v;
    };
    auto readU16 = [&]() -> uint16_t {
        uint16_t v = 0; f.read(reinterpret_cast<char*>(&v), 2); return v;
    };

    readU32(); // skip redundant first DWORD
    uint32_t thisPacketSize = readU32();
    readU32(); // max packet size
    readU32(); // "xobX" magic

    uint32_t version = readU32();
    if (version != 2 && version != 4) {
        fprintf(stderr, "[HLE_XMV] Unsupported XMV version %u\n", version);
        ctx.eax = 0x80004005u;
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    uint32_t videoWidth    = readU32();
    uint32_t videoHeight   = readU32();
    uint32_t videoDuration = readU32();
    uint16_t audioCount    = readU16();
    readU16(); // padding

    if (!f || videoWidth == 0 || videoHeight == 0) {
        fprintf(stderr, "[HLE_XMV] Header parse error\n");
        ctx.eax = 0x80004005u;
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    // ---- Allocate host-side decoder ----
    auto* dec = new HLE_XmvDecoder();
    dec->videoWidth    = videoWidth;
    dec->videoHeight   = videoHeight;
    dec->videoDuration = videoDuration;

    // Audio tracks
    for (uint16_t i = 0; i < audioCount; i++) {
        HLE_XmvDecoder::AudioTrack at;
        at.compression   = readU16();
        at.channels      = readU16();
        at.sampleRate    = readU32();
        at.bitsPerSample = readU16();
        at.flags         = readU16();
        // XMV ADPCM block alignment = 36 * channels; for WMA use its own align
        at.blockAlign = (at.flags != 0) ? (36u * at.channels) : 0u;
        at.dataSize   = 0;
        at.dataOffset = 0;
        at.frameSize  = 0;
        dec->audioTracks.push_back(std::move(at));
    }

    if (!f) {
        fprintf(stderr, "[HLE_XMV] Audio track header parse error\n");
        delete dec;
        ctx.eax = 0x80004005u;
        GuestStackCleanup(ctx, 0x0C);
        return;
    }

    // First packet content starts right after the file header
    int64_t headerEnd      = (int64_t)f.tellg();
    dec->nextPacketOffset  = headerEnd;
    // first packet's content size = thisPacketSize - headerEnd
    // (thisPacketSize = header_size + first_content_size per FFmpeg xmv.c)
    dec->nextPacketSize    = (thisPacketSize > (uint32_t)headerEnd)
                           ? (thisPacketSize - (uint32_t)headerEnd)
                           : 0u;

    dec->file = std::move(f);
    dec->eof        = false;
    dec->terminated = false;
    dec->firstFrame    = true;

    // Pre-parse the first packet so vidDataOffset / vidFrameCount are valid
    dec->file.seekg(dec->nextPacketOffset);
    if (dec->nextPacketSize > 0 && dec->file) {
        // nextPacketOffset doubles as thisPacketOffset for the first fetch
        bool ok = XmvProcessPacketHeader(*dec);
        if (!ok) {
            fprintf(stderr, "[HLE_XMV] First packet header parse failed\n");
            delete dec;
            ctx.eax = 0x80004005u;
            GuestStackCleanup(ctx, 0x0C);
            return;
        }
        // After processing, figure out where the next-next packet is:
        // next packet offset = current start + current content size.
        // Stored nextPacketSize is now the size of the *following* packet,
        // and the current size was dec->nextPacketSize before the header read.
        // We need to track differently:  save off packet boundaries.
        // Re-structure: after XmvProcessPacketHeader the member
        // dec->nextPacketSize holds the *following* packet's size (read from
        // the first 4 bytes of the packet).  Record that  and compute the
        // current packet's end.  We cannot know current size from inside the
        // packet header; we need the value we had just before calling
        // XmvProcessPacketHeader (which was dec->nextPacketSize before the
        // call, now overwritten).  Fix: save it before the call.

        // We already called XmvProcessPacketHeader and it overwrote
        // dec->nextPacketSize with the next-packet's size.
        // The first packet's offset is at headerEnd; its content
        // runs from there until headerEnd + (originalNextPacketSize).
        // But we moved nextPacketOffset up in XmvFetchNextPacket, which we
        // did NOT call here.  We called XmvProcessPacketHeader directly.
        // That means nextPacketOffset is still == headerEnd (correct for
        // position of current packet), and nextPacketSize now holds the
        // FOLLOWING packet's size.  The current packet's total content size
        // is what was stored in dec->nextPacketSize BEFORE this call —
        // which was thisPacketSize - headerEnd.  We need to advance
        // nextPacketOffset by that amount for future XmvFetchNextPacket calls.
        uint32_t firstContentSize = (thisPacketSize > (uint32_t)headerEnd)
                                  ? (thisPacketSize - (uint32_t)headerEnd)
                                  : 0u;
        dec->nextPacketOffset += (int64_t)firstContentSize;
        // dec->nextPacketSize already holds the following packet's size.
    } else {
        dec->eof = true;
    }

    fprintf(stderr, "[HLE_XMV] Opened %ux%u, %u ms, %u audio track(s)\n",
            videoWidth, videoHeight, videoDuration, audioCount);

#ifdef _WIN32
    // Try to initialise the video DMO now that we have dimensions
    XmvInitVideoDMO(*dec);
    // Initialise WMA decoder DMOs for all audio tracks
    for (auto& at : dec->audioTracks)
        XmvInitAudioDMO(*dec, at);
    // Ensure SDL audio device is open so the ring buffer gets drained
    HLE_EnsureAudioInit(base);
#endif

    // ---- Allocate guest decoder object (8 bytes: vtable=0, id) ----
    uint32_t guestObj = g_heap.AllocGuestAligned(8, 4);
    if (!guestObj) {
        delete dec;
        ctx.eax = 0x8007000Eu; // E_OUTOFMEMORY
        GuestStackCleanup(ctx, 0x0C);
        return;
    }
    memset(base + guestObj, 0, 8);
    X86_MEM_WRITE_u32(base, guestObj + 0, 0); // vtable (none needed)
    X86_MEM_WRITE_u32(base, guestObj + 4, guestObj); // self-ID

    dec->guestObjAddr = guestObj;
    {
        std::lock_guard<std::mutex> lk(g_xmvMtx);
        g_xmvMap[guestObj] = dec;
    }

    // Start background decode thread; bgRequested is already true so it will
    // immediately decode the first video frame.
    dec->bgThread = std::thread(XmvBgThread, dec);

    X86_MEM_WRITE_u32(base, ppDecoder, guestObj);
    fprintf(stderr, "[HLE_XMV] Decoder guest obj=0x%08X\n", guestObj);

    ctx.eax = 0; // S_OK
    GuestStackCleanup(ctx, 0x0C);
}

// XMVDecoder_CreateDecoderForPackets  (0x2CC53A) — 6 args (0x18), ret 24
// Creates an XMV decoder from in-memory packet data.
// Returns HRESULT in eax.  Stub returns E_FAIL.
void XMVDecoder_CreateDecoderForPackets(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE_XMV] XMVDecoder_CreateDecoderForPackets() — not implemented\n");
    ctx.eax = 0x80004005; // E_FAIL
    GuestStackCleanup(ctx, 0x18);
}

// XMVDecoder_CloseDecoder  (0x2CC851) — 1 arg (0x04), ret 4
// Closes an XMV decoder and frees resources.
void XMVDecoder_CloseDecoder(X86Context& ctx, uint8_t* base)
{
    uint32_t pDecoder = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[HLE_XMV] XMVDecoder_CloseDecoder(0x%08X)\n", pDecoder);

    std::lock_guard<std::mutex> lk(g_xmvMtx);
    auto it = g_xmvMap.find(pDecoder);
    if (it != g_xmvMap.end()) {
        HLE_XmvDecoder* dec = it->second;
        // Stop the background decode thread before releasing resources
        {
            std::lock_guard<std::mutex> blk(dec->bgMtx);
            dec->bgShutdown = true;
        }
        dec->bgWorkCv.notify_one();
        if (dec->bgThread.joinable())
            dec->bgThread.join();
#ifdef _WIN32
        if (dec->pVideoDMO) { dec->pVideoDMO->Release(); dec->pVideoDMO = nullptr; }
        for (auto& at : dec->audioTracks)
            if (at.pDMO) { at.pDMO->Release(); at.pDMO = nullptr; }
#endif
        g_heap.FreeGuest(dec->guestObjAddr);
        delete dec;
        g_xmvMap.erase(it);
    }

    ctx.eax = 0; // S_OK
    GuestStackCleanup(ctx, 0x04);
}

// XMVDecoder_GetVideoDescriptor  (0x2CC935) — 2 args (0x08), ret 8
//
// HRESULT XMVDecoder_GetVideoDescriptor(
//     XMVDECODER*         pDecoder,   // arg0
//     XMVVIDEODESCRIPTOR* pDesc       // arg1: output struct {width, height, duration}
// );
//
// Writes {videoWidth, videoHeight, videoDuration} to *pDesc.
void XMVDecoder_GetVideoDescriptor(X86Context& ctx, uint8_t* base)
{
    uint32_t pDecoder = GuestArg32(ctx, base, 0);
    uint32_t pDesc    = GuestArg32(ctx, base, 1);

    std::lock_guard<std::mutex> lk(g_xmvMtx);
    auto it = g_xmvMap.find(pDecoder);
    if (it == g_xmvMap.end() || !pDesc) {
        fprintf(stderr, "[HLE_XMV] GetVideoDescriptor: invalid decoder 0x%08X\n", pDecoder);
        ctx.eax = 0x80004005u; // E_FAIL
        GuestStackCleanup(ctx, 0x08);
        return;
    }

    HLE_XmvDecoder* dec = it->second;

    // XMVVIDEODESCRIPTOR layout (best-guess from recompiled call analysis):
    //   +0x00  DWORD width
    //   +0x04  DWORD height
    //   +0x08  DWORD duration (ms) — used as frame-period source by the game
    X86_MEM_WRITE_u32(base, pDesc + 0x00, dec->videoWidth);
    X86_MEM_WRITE_u32(base, pDesc + 0x04, dec->videoHeight);
    X86_MEM_WRITE_u32(base, pDesc + 0x08, dec->videoDuration);

    fprintf(stderr, "[HLE_XMV] GetVideoDescriptor -> %ux%u, %u ms\n",
            dec->videoWidth, dec->videoHeight, dec->videoDuration);

    ctx.eax = 0; // S_OK
    GuestStackCleanup(ctx, 0x08);
}

// XMVDecoder_TerminateImmediately  (0x2CC951) — 1 arg (0x04), ret 4
// Immediately terminates playback, flagging the decoder as done.
void XMVDecoder_TerminateImmediately(X86Context& ctx, uint8_t* base)
{
    uint32_t pDecoder = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[HLE_XMV] XMVDecoder_TerminateImmediately(0x%08X)\n", pDecoder);

    std::lock_guard<std::mutex> lk(g_xmvMtx);
    auto it = g_xmvMap.find(pDecoder);
    if (it != g_xmvMap.end()) {
        it->second->terminated = true;
        // Signal the bg thread to stop (join happens in CloseDecoder)
        {
            std::lock_guard<std::mutex> blk(it->second->bgMtx);
            it->second->bgShutdown = true;
        }
        it->second->bgWorkCv.notify_one();
    }

    ctx.eax = 0; // S_OK
    GuestStackCleanup(ctx, 0x04);
}

// ============================================================================
// Background video decode helpers
// ============================================================================

// Decode one video frame off the main thread.
// Reads from dec.file, advances packet/frame state, decodes via Windows DMO,
// and stores raw BGRA pixels into dec.hostPixBuf.
// Also decodes the accompanying audio slice into dec.pcmRing.
// Returns true on success, false on EOF or error.
// Must only be called from XmvBgThread.
static bool XmvBgDecodeOneFrame(HLE_XmvDecoder& dec)
{
    // Fetch the next packet if we have exhausted all frames in the current one
    if (dec.vidCurrentFrame >= dec.vidFrameCount) {
        bool ok = XmvFetchNextPacket(dec);
        if (!ok || dec.nextPacketSize == 0) {
            return false; // EOF
        }
#ifdef _WIN32
        if (dec.vidHasExtra && !dec.vidDMOReady)
            XmvInitVideoDMO(dec);
#endif
    }

    // Seek to the current video frame's position in the file
    dec.file.seekg(dec.vidDataOffset);
    if (!dec.file)
        return false;

    // Read frame header: bits[16:0]*4+4 = frame_size
    uint32_t frameHdr = 0;
    dec.file.read(reinterpret_cast<char*>(&frameHdr), 4);
    if (!dec.file || dec.vidDataSize < 4)
        return false;

    uint32_t frameBytes = (frameHdr & 0x1FFFFu) * 4u + 4u;
    if (frameBytes + 4u > dec.vidDataSize)
        frameBytes = dec.vidDataSize >= 4u ? dec.vidDataSize - 4u : 0u;

    dec.vidDataOffset  += (int64_t)(4 + frameBytes);
    dec.vidDataSize    -= (4 + frameBytes);
    dec.vidCurrentFrame++;

    std::vector<uint8_t> rawFrame(frameBytes, 0);
    if (frameBytes > 0)
        dec.file.read(reinterpret_cast<char*>(rawFrame.data()), frameBytes);

#ifdef _WIN32
    if (dec.vidDMOReady && frameBytes > 0)
        XmvDecodeVideoFrame(dec, rawFrame); // writes BGRA into dec.hostPixBuf
#endif

    // Decode the audio slice that accompanies this video frame
    for (auto& at : dec.audioTracks) {
        if (at.dataSize == 0) continue;
        uint32_t slice = (dec.vidCurrentFrame < dec.vidFrameCount)
                       ? at.frameSize : at.dataSize;
        if (slice > at.dataSize) slice = at.dataSize;
#ifdef _WIN32
        if (slice > 0)
            XmvDecodeAudioSlice(dec, at, at.dataOffset, slice);
#endif
        at.dataOffset += (int64_t)slice;
        at.dataSize   -= slice;
    }

    return true;
}

// Background decode thread body: waits for work requests, calls
// XmvBgDecodeOneFrame, then publishes the result in dec->bgPixBuf.
static void XmvBgThread(HLE_XmvDecoder* dec)
{
#ifdef _WIN32
    // Join the MTA so we can use the WMVideo/WMA DMO objects from this thread.
    CoInitializeEx(nullptr, COINIT_MULTITHREADED);
#endif
    while (true) {
        {
            std::unique_lock<std::mutex> lk(dec->bgMtx);
            dec->bgWorkCv.wait(lk, [dec] {
                return dec->bgRequested || dec->bgShutdown;
            });
            if (dec->bgShutdown) break;
            dec->bgRequested = false;
        }

        bool ok = XmvBgDecodeOneFrame(*dec);

        {
            std::lock_guard<std::mutex> lk(dec->bgMtx);
            if (ok && !dec->hostPixBuf.empty()) {
                // Copy decoded pixels into the published buffer (1.2 MB @ ~10 GB/s ≈ 0.12 ms)
                dec->bgPixBuf   = dec->hostPixBuf;
                dec->bgFrameReady = true;
                dec->bgEof      = false;
            } else {
                dec->bgEof      = true;
                dec->bgFrameReady = false;
            }
        }
    }
#ifdef _WIN32
    CoUninitialize();
#endif
}

// XMVDecoder_GetNextFrame  (0x2CCB1C) — 4 args (0x10), ret 16
//
// HRESULT XMVDecoder_GetNextFrame(
//     XMVDECODER* pDecoder,        // arg0
//     DWORD       pSurfaceEntry,   // arg1: pointer to [surfaceAddr] (game's frame slot)
//     DWORD*      pStatusOut,      // arg2: OUT status: 1=frame, 2=eof, 0=not ready
//     DWORD*      pAudioOut        // arg3: OUT audio info struct {ptr, size}
// );
//
// Decodes the next XMV video frame into the D3D surface referenced by
// pSurfaceEntry, writes decoded PCM into a guest buffer, and returns a
// status code indicating frame availability or end-of-stream.
//
// Status codes observed in the game's branch logic:
//   0        = no new frame yet (loop continues without advancing)
//   1        = frame decoded (game advances its double-buffer index)
//   2 or 3   = end of video / error (game sets its "video done" flag)
void XMVDecoder_GetNextFrame(X86Context& ctx, uint8_t* base)
{
    uint32_t pDecoder    = GuestArg32(ctx, base, 0);
    uint32_t surfEntry   = GuestArg32(ctx, base, 1);
    uint32_t pStatusOut  = GuestArg32(ctx, base, 2);

    // Default: no frame ready
    if (pStatusOut) X86_MEM_WRITE_u32(base, pStatusOut, 0u);

    std::lock_guard<std::mutex> lk(g_xmvMtx);
    auto it = g_xmvMap.find(pDecoder);
    if (it == g_xmvMap.end()) {
        ctx.eax = 0x80004005u;
        GuestStackCleanup(ctx, 0x10);
        return;
    }

    HLE_XmvDecoder* dec = it->second;

#ifdef _WIN32
    // Skip hotkey: pressing Enter instantly finishes the currently playing video.
    // Track the previous key state to fire only on a fresh press (not a held key).
    if (!dec->terminated && !dec->eof) {
        static bool s_enterWasDown = false;
        bool enterDown = (GetAsyncKeyState(VK_TAB) & 0x8000) != 0;
        if (enterDown && !s_enterWasDown) {
            fprintf(stderr, "[HLE_XMV] Skip hotkey (Tab) — terminating video 0x%08X\n", pDecoder);
            dec->terminated = true;
            {
                std::lock_guard<std::mutex> blk(dec->bgMtx);
                dec->bgShutdown = true;
            }
            dec->bgWorkCv.notify_one();
        }
        s_enterWasDown = enterDown;
    }
#endif

    // If already terminated or EOF, signal end-of-video
    if (dec->terminated || dec->eof) {
        if (pStatusOut) X86_MEM_WRITE_u32(base, pStatusOut, 2u);
        ctx.eax = 0;
        GuestStackCleanup(ctx, 0x10);
        return;
    }

    // Check whether the background thread has finished (EOF)
    {
        std::lock_guard<std::mutex> blk(dec->bgMtx);
        if (dec->bgEof) {
            dec->eof = true;
            if (pStatusOut) X86_MEM_WRITE_u32(base, pStatusOut, 2u);
            ctx.eax = 0;
            GuestStackCleanup(ctx, 0x10);
            return;
        }
    }

    // Display-field throttle: return "not ready" if less than one display field (~16.667ms)
    // has elapsed since the last status=1 return.  On real Xbox, D3DDevice_GetDisplayFieldStatus
    // gates video output at the display field rate (60 Hz) independently of the video's own fps,
    // so the game's render loop swaps at 60 fps even for 30 fps video.
    if (!dec->firstFrame) {
        auto now = std::chrono::steady_clock::now();
        double elapsedMs = std::chrono::duration<double, std::milli>(now - dec->lastFrameTime).count();
        if (elapsedMs < HLE_XmvDecoder::kFieldPeriodMs) {
            ctx.eax = 0;
            GuestStackCleanup(ctx, 0x10);
            return;
        }
    }

    // Resolve the target guest surface pixel address
    uint32_t guestPixAddr = 0;
    if (surfEntry && dec->videoWidth > 0 && dec->videoHeight > 0)
        guestPixAddr = GetSurfaceDataAddr(base, surfEntry);

    // Only copy pixels and kick off the next decode when a new frame is available.
    // If no new frame is ready yet, we still return status=1 (showing the previous frame)
    // so the game loop proceeds to D3DDevice_Swap at 60 fps.
    bool newFrameCopied = false;
    {
        std::lock_guard<std::mutex> blk(dec->bgMtx);
        if (dec->bgFrameReady) {
            if (guestPixAddr && !dec->bgPixBuf.empty()) {
                const uint32_t n   = dec->videoWidth * dec->videoHeight;
                const uint32_t* src = reinterpret_cast<const uint32_t*>(dec->bgPixBuf.data());
                uint32_t*       dst = reinterpret_cast<uint32_t*>(base + guestPixAddr);
                // Force alpha=0xFF (DMO leaves the X byte = 0 in BGRX output)
                for (uint32_t i = 0; i < n; i++)
                    dst[i] = src[i] | 0xFF000000u;
                newFrameCopied = true;
            }
            dec->bgFrameReady = false;
            dec->bgRequested  = true;
            dec->bgWorkCv.notify_one();
        }
    }
    // Invalidate the D3D11 texture cache entry for this video surface so the
    // next draw call re-uploads the freshly decoded pixels.  The parent Xbox
    // texture object address is stored at surfEntry+0x14 in guest memory.
    if (newFrameCopied && surfEntry) {
        uint32_t parentAddr = X86_MEM_READ_u32(base, surfEntry + 0x14);
        if (parentAddr) HLE_InvalidateTextureSRV(parentAddr);
    }

    // Update display-field timing
    if (dec->firstFrame) {
        dec->lastFrameTime = std::chrono::steady_clock::now();
        dec->firstFrame = false;
    } else {
        dec->lastFrameTime += std::chrono::duration_cast<std::chrono::steady_clock::duration>(
            std::chrono::duration<double, std::milli>(HLE_XmvDecoder::kFieldPeriodMs));
    }

    if (pStatusOut) X86_MEM_WRITE_u32(base, pStatusOut, 1u);
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// ============================================================================
// Internal XMV helpers — unnamed subs
// ============================================================================

// sub_2CC200  (0x2CC200) — 3 args (0x0C), locals 0x08
void sub_2CC200(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CC200()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2CC274  (0x2CC274) — 4 args (0x10), locals 0x04
void sub_2CC274(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CC274()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2CD199  (0x2CD199) — 0 args, locals 0x04
void sub_2CD199(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD199()\n");
    ctx.eax = 0;
}

// sub_2CD1AE  (0x2CD1AE) — 0 args
void sub_2CD1AE(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD1AE()\n");
    ctx.eax = 0;
}

// sub_2CD1C3  (0x2CD1C3) — 0 args
void sub_2CD1C3(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD1C3()\n");
    ctx.eax = 0;
}

// sub_2CD1E8  (0x2CD1E8) — 0 args
void sub_2CD1E8(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD1E8()\n");
    ctx.eax = 0;
}

// sub_2CD22D  (0x2CD22D) — 0 args
void sub_2CD22D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD22D()\n");
    ctx.eax = 0;
}

// sub_2CD277  (0x2CD277) — 7 args (0x1C), locals 0x0C
void sub_2CD277(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD277()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2CD36E  (0x2CD36E) — 9 args (0x24), locals 0x228
void sub_2CD36E(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD36E()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x24);
}

// sub_2CD4CB  (0x2CD4CB) — 7 args (0x1C), locals 0x10
void sub_2CD4CB(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD4CB()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2CD6B6  (0x2CD6B6) — 9 args (0x24), locals 0x478
void sub_2CD6B6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD6B6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x24);
}

// sub_2CD892  (0x2CD892) — 7 args (0x1C), locals 0x10
void sub_2CD892(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CD892()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2CDA91  (0x2CDA91) — 9 args (0x24), locals 0x478
void sub_2CDA91(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CDA91()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x24);
}

// sub_2CDC6D  (0x2CDC6D) — 2 args (0x08), locals 0x28
void sub_2CDC6D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CDC6D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_2CDD43  (0x2CDD43) — 15 args (0x3C), locals 0x124
void sub_2CDD43(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CDD43()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x3C);
}

// sub_2CE073  (0x2CE073) — 25 args (0x64), locals 0x1C
void sub_2CE073(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE073()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x64);
}

// sub_2CE1A0  (0x2CE1A0) — 2 args (0x08), locals 0x104
void sub_2CE1A0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE1A0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_2CE58F  (0x2CE58F) — 8 args (0x20), locals 0x10
void sub_2CE58F(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE58F()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x20);
}

// sub_2CE5F8  (0x2CE5F8) — 7 args (0x1C), locals 0x10
void sub_2CE5F8(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE5F8()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2CE734  (0x2CE734) — 7 args (0x1C), locals 0x18
void sub_2CE734(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE734()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2CE90E  (0x2CE90E) — 18 args (0x48), locals 0x1C0
void sub_2CE90E(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CE90E()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x48);
}

// sub_2CEC4B  (0x2CEC4B) — 3 args (0x0C), locals 0x04
void sub_2CEC4B(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CEC4B()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2CEC7A  (0x2CEC7A) — 1 arg (0x04), locals 0x164
void sub_2CEC7A(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CEC7A()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_2CF71D  (0x2CF71D) — 1 arg (0x04), locals 0x08
void sub_2CF71D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CF71D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_2CF788  (0x2CF788) — 3 args (0x0C), locals 0x13C
void sub_2CF788(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CF788()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2CFBF5  (0x2CFBF5) — 3 args (0x0C), locals 0xDC
void sub_2CFBF5(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2CFBF5()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2D0277  (0x2D0277) — 3 args (0x0C), locals 0x28
void sub_2D0277(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0277()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2D04EE  (0x2D04EE) — 3 args (0x0C), locals 0x3C
void sub_2D04EE(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D04EE()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2D0798  (0x2D0798) — 0 args
void sub_2D0798(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0798()\n");
    ctx.eax = 0;
}

// sub_2D07C7  (0x2D07C7) — 1 arg (0x04)
void sub_2D07C7(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D07C7()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x04);
}

// sub_2D07E5  (0x2D07E5) — 2 args (0x08), locals 0x04
void sub_2D07E5(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D07E5()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_2D084D  (0x2D084D) — 0 args
void sub_2D084D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D084D()\n");
    ctx.eax = 0;
}

// sub_2D087C  (0x2D087C) — 0 args, locals 0x0C
void sub_2D087C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D087C()\n");
    ctx.eax = 0;
}

// sub_2D0901  (0x2D0901) — 4 args (0x10), locals 0x10
void sub_2D0901(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0901()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D0ACF  (0x2D0ACF) — 4 args (0x10), locals 0x38
void sub_2D0ACF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0ACF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D0C38  (0x2D0C38) — 6 args (0x18), locals 0x08
void sub_2D0C38(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0C38()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D0CC1  (0x2D0CC1) — 6 args (0x18), locals 0x14
void sub_2D0CC1(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0CC1()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D0D7D  (0x2D0D7D) — 6 args (0x18), locals 0x1C
void sub_2D0D7D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0D7D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D0ED7  (0x2D0ED7) — 6 args (0x18), locals 0x1C
void sub_2D0ED7(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D0ED7()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D1158  (0x2D1158) — 6 args (0x18), locals 0x10
void sub_2D1158(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D1158()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D14D0  (0x2D14D0) — 7 args (0x1C), locals 0x10
void sub_2D14D0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D14D0()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2D16CF  (0x2D16CF) — 7 args (0x1C), locals 0x10
void sub_2D16CF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D16CF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2D18B4  (0x2D18B4) — 7 args (0x1C), locals 0x7C
void sub_2D18B4(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D18B4()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2D1F21  (0x2D1F21) — 8 args (0x20), locals 0x7C
void sub_2D1F21(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D1F21()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x20);
}

// sub_2D275E  (0x2D275E) — 4 args (0x10), locals 0xB0
void sub_2D275E(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D275E()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D296C  (0x2D296C) — 4 args (0x10), locals 0x10
void sub_2D296C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D296C()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D2A18  (0x2D2A18) — 5 args (0x14), locals 0x50
void sub_2D2A18(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2A18()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x14);
}

// sub_2D2D6D  (0x2D2D6D) — 4 args (0x10), locals 0x0C
void sub_2D2D6D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2D6D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D2DAA  (0x2D2DAA) — 4 args (0x10), locals 0x18
void sub_2D2DAA(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2DAA()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D2EBF  (0x2D2EBF) — 4 args (0x10), locals 0x08
void sub_2D2EBF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2EBF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D2EFD  (0x2D2EFD) — 7 args (0x1C), locals 0x14
void sub_2D2EFD(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2EFD()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x1C);
}

// sub_2D2FC2  (0x2D2FC2) — 4 args (0x10), locals 0x0C
void sub_2D2FC2(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D2FC2()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x10);
}

// sub_2D3044  (0x2D3044) — 6 args (0x18), locals 0x4C
void sub_2D3044(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D3044()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x18);
}

// sub_2D3585  (0x2D3585) — 9 args (0x24), locals 0x04
void sub_2D3585(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D3585()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x24);
}

// sub_2D361D  (0x2D361D) — 3 args (0x0C), locals 0x54
void sub_2D361D(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D361D()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2D38EF  (0x2D38EF) — 3 args (0x0C), locals 0x28
void sub_2D38EF(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D38EF()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x0C);
}

// sub_2D3B3C  (0x2D3B3C) — 15 args (0x3C), locals 0xCC
void sub_2D3B3C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D3B3C()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x3C);
}

// sub_2D43F6  (0x2D43F6) — 2 args (0x08), locals 0xF4
void sub_2D43F6(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D43F6()\n");
    ctx.eax = 0;
    GuestStackCleanup(ctx, 0x08);
}

// sub_2D7760  (0x2D7760) — 0 args (3-byte function, likely just ret)
void sub_2D7760(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D7760()\n");
}

// sub_2D7E08  (0x2D7E08) — 0 args (1-byte nop, nullsub_18)
void sub_2D7E08(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D7E08()\n");
}

// sub_2D7E0C  (0x2D7E0C) — 0 args (1-byte nop, nullsub_19)
void sub_2D7E0C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D7E0C()\n");
}

// sub_2D7EB4  (0x2D7EB4) — 0 args (9-byte function)
void sub_2D7EB4(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D7EB4()\n");
    ctx.eax = 0;
}

// sub_2D7EC0  (0x2D7EC0) — 0 args (1-byte nop, nullsub_20)
void sub_2D7EC0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D7EC0()\n");
}

// sub_2D809C  (0x2D809C) — 0 args (5-byte function)
void sub_2D809C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D809C()\n");
    ctx.eax = 0;
}

// sub_2D817C  (0x2D817C) — 0 args (1-byte nop, nullsub_21)
void sub_2D817C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D817C()\n");
}

// sub_2D8310  (0x2D8310) — 0 args (1-byte nop, nullsub_22)
void sub_2D8310(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D8310()\n");
}

// sub_2D856C  (0x2D856C) — 0 args (1-byte nop, nullsub_23)
void sub_2D856C(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D856C()\n");
}

// sub_2D8634  (0x2D8634) — 0 args (3-byte function)
void sub_2D8634(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D8634()\n");
}

// sub_2D87C0  (0x2D87C0) — 0 args (1-byte nop, nullsub_24)
void sub_2D87C0(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2D87C0()\n");
}

// sub_2DB538  (0x2DB538) — 0 args (6-byte function)
void sub_2DB538(X86Context& ctx, uint8_t* base)
{
    printf("[HLE_XMV] sub_2DB538()\n");
    ctx.eax = 0;
}