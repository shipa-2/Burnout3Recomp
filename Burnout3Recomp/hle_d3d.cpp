// ============================================================================
// HLE Direct3D Backend — based on Cxbx-Reloaded's D3D8/D3D9 HLE patches.
//
// This file provides High Level Emulation stubs for the Xbox D3D8 library
// functions referenced by the Doom homebrew port.  Instead of executing the
// original GPU-touching code (which talks to the NV2A), each function is
// intercepted here.  Where Cxbx would translate to a host D3D9 call we
// instead operate purely on the guest D3D state kept in the recompiled
// binary's own memory, so that higher-level game code sees a consistent
// picture.  No actual rendering takes place (yet).
//
// Calling-convention notes (verified from recompiled ret instructions):
//   Most Xbox D3D functions are __stdcall (callee-cleanup, args on stack).
//   D3DDevice_SetRenderState_Simple is __fastcall: ECX=Method, EDX=Value.
//   SetRenderState_FrontFace is __fastcall with plain ret.
//   Internal NV2A functions typically use plain ret.
// ============================================================================

#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include "kernel/file_io.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <filesystem>

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_STDIO           // we only load from memory
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <timeapi.h>              // for timeBeginPeriod
#pragma comment(lib, "winmm.lib")

// D3D11 hardware rendering
#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

#include "kernel/xdm.h"
#include "nv2a_vsh_hlsl.h"
#include "nv2a_ps_hlsl.h"

// Cache of per-handle compiled NV2A vertex shaders. Populated by
// D3DDevice_CreateVertexShader, consumed by HLE_Draw3D.
struct VsCacheEntry {
    ID3D11VertexShader* vs           = nullptr;
    ID3D11InputLayout*  il           = nullptr;
    uint32_t            vertexStride = 0;   // informational
    bool                failed       = false; // translation/compile failed once
    std::string         hlsl;                 // kept for first-use diagnostic
};
static std::unordered_map<uint32_t, VsCacheEntry> g_vsByHandle;

// Forward declaration — D3DCompile wrapper defined much later in this file.
static ID3DBlob* D3D11CompileShader(const char* hlsl, const char* entry, const char* target);

// ============================================================================
// HLSL Shaders
// ============================================================================

// 2D vertex shader: screen-space XYZRHW → clip space
// Constant buffer slot 0: float2 screenSize
static const char s_vsHlsl[] =
    "cbuffer CB : register(b0) { float2 screenSize; float2 pad; }\n"
    "struct VS_IN { float2 pos : POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "struct VS_OUT { float4 pos : SV_POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "VS_OUT main(VS_IN v) {\n"
    "  VS_OUT o;\n"
    "  o.pos.x =  (v.pos.x / screenSize.x) * 2.0f - 1.0f;\n"
    "  o.pos.y = -(v.pos.y / screenSize.y) * 2.0f + 1.0f;\n"
    "  o.pos.z = 0.0f; o.pos.w = 1.0f;\n"
    "  o.uv = v.uv; o.col = v.col;\n"
    "  return o;\n"
    "}\n";

// Untextured pixel shader: use vertex colour only
static const char s_psUntexturedHlsl[] =
    "struct PS_IN { float4 pos : SV_POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "float4 main(PS_IN p) : SV_TARGET { return p.col; }\n";

// 3D untextured PS: same as above but floors the vertex colour so Xbox VS
// output with oD0 close to 0 (unlit/back-facing) doesn't render as pure
// black. Used only when no texture is bound on a 3D draw.
static const char s_ps3DUntexturedHlsl[] =
    "struct PS_IN { float4 pos : SV_POSITION; float4 col : COLOR; float2 uv : TEXCOORD; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  return float4(max(p.col.rgb, 0.6), 1.0);\n"
    "}\n";

// Alpha-only textured pixel shader: for A8/L8/P8-font textures
// Samples the alpha channel and uses vertex colour's RGB
static const char s_psAlphaHlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct PS_IN { float4 pos : SV_POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  float a = t.Sample(s, p.uv).a;\n"
    "  return float4(p.col.rgb, p.col.a * a);\n"
    "}\n";

// Modulate pixel shader: texture colour * vertex colour
static const char s_psModulateHlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct PS_IN { float4 pos : SV_POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  float4 tc = t.Sample(s, p.uv);\n"
    "  return tc * p.col;\n"
    "}\n";

// 3D vertex shader: model-space XYZ → clip space via NV2A constant MVP at c[112..115].
// Input layout must match VB stride=28 (Burnout 3 car format):
//   float3 pos(12) + NORMPACKED3 normal(4) + D3DCOLOR diffuse(4) + float2 uv(8)
// Lighting is computed from the packed normal + directional light at c[97].
static const char s_vs3DHlsl[] =
    "cbuffer C3D : register(b0) { float4 c[192]; }\n"
    "struct VS_IN  { float3 pos : POSITION; uint n : NORMAL; float4 col : COLOR; float2 uv : TEXCOORD; };\n"
    "struct VS_OUT { float4 pos : SV_POSITION; float4 col : COLOR; float2 uv : TEXCOORD; };\n"
    "VS_OUT main(VS_IN v) {\n"
    "  VS_OUT o;\n"
    "  float4 P = float4(v.pos, 1.0);\n"
    "  o.pos.x = dot(c[112], P);\n"
    "  o.pos.y = dot(c[113], P);\n"
    "  o.pos.z = dot(c[114], P);\n"
    "  o.pos.w = dot(c[115], P);\n"
    "  int xr = (int)(v.n & 0x7FFu); if (xr > 1023) xr -= 2048;\n"
    "  int yr = (int)((v.n >> 11u) & 0x7FFu); if (yr > 1023) yr -= 2048;\n"
    "  int zr = (int)((v.n >> 22u) & 0x3FFu); if (zr > 511)  zr -= 1024;\n"
    "  float3 n = normalize(float3(xr / 1023.0, yr / 1023.0, zr / 511.0));\n"
    "  float3 Lraw = -c[97].xyz;\n"
    "  float Llen = dot(Lraw, Lraw);\n"
    "  float lit = 1.0;\n"
    "  if (Llen > 0.0001) { float3 Ld = Lraw * rsqrt(Llen); lit = 0.3 + 0.7 * saturate(dot(n, Ld)); }\n"
    "  o.col = float4(lit, lit, lit, 1.0);\n"
    "  o.uv  = v.uv;\n"
    "  return o;\n"
    "}\n";

// 3D textured pixel shader: modulate texture by vertex lighting, force opaque alpha.
static const char s_ps3DHlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct PS_IN { float4 pos : SV_POSITION; float4 col : COLOR; float2 uv : TEXCOORD; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  // The NV2A VS in Burnout 3 emits oD0 straight from a per-vertex\n"
    "  // color attribute rather than running the fixed-function lighting\n"
    "  // pipeline, so oD0 is typically dim (pre-shaded baked values). Until\n"
    "  // we wire up real per-scene lighting, floor the modulation to a high\n"
    "  // ambient so interiors don't render near-black.\n"
    "  float4 tc = t.Sample(s, p.uv);\n"
    "  float3 col = max(p.col.rgb, 0.8);\n"
    "  return float4(tc.rgb * col, 1.0);\n"
    "}\n";

// ============================================================================
// D3D11 state
// ============================================================================

struct TextureCacheEntry {
    ID3D11Texture2D*          texture     = nullptr;
    ID3D11ShaderResourceView* srv         = nullptr;
    uint32_t                  xboxDataAddr = 0;
    uint32_t                  width        = 0;
    uint32_t                  height       = 0;
    DXGI_FORMAT               dxgiFormat   = DXGI_FORMAT_UNKNOWN;
    uint8_t                   xboxFmtCode  = 0;
    bool                      isAlphaOnly  = false;
};

struct RenderTargetEntry {
    ID3D11Texture2D*          texture  = nullptr;
    ID3D11RenderTargetView*   rtv      = nullptr;
    ID3D11ShaderResourceView* srv      = nullptr;
    ID3D11Texture2D*          depthTex = nullptr;
    ID3D11DepthStencilView*   dsv      = nullptr;
    uint32_t                  width    = 0;
    uint32_t                  height   = 0;
};

struct D3D11State {
    // Core
    ID3D11Device*           device          = nullptr;
    ID3D11DeviceContext*    context         = nullptr;
    IDXGISwapChain*         swapChain       = nullptr;
    bool                    initialized     = false;
    uint32_t                width           = 640;
    uint32_t                height          = 480;

    // Back buffer
    ID3D11Texture2D*          backBufferTex  = nullptr;
    ID3D11RenderTargetView*   backBufferRTV  = nullptr;
    ID3D11Texture2D*          depthTex       = nullptr;
    ID3D11DepthStencilView*   depthDSV       = nullptr;

    // 2D Pipeline
    ID3D11VertexShader*       vs2D           = nullptr;
    ID3D11InputLayout*        il2D           = nullptr;
    ID3D11PixelShader*        psUntextured   = nullptr;
    ID3D11PixelShader*        psAlpha        = nullptr;
    ID3D11PixelShader*        psModulate     = nullptr;
    ID3D11Buffer*             cb2D           = nullptr;  // screen-size constant buffer
    bool                      pipelineReady  = false;

    // 3D Pipeline (model-space XYZ + normal + diffuse + UV, transformed via NV2A constants)
    ID3D11VertexShader*       vs3D           = nullptr;
    ID3D11InputLayout*        il3D           = nullptr;
    ID3D11PixelShader*        ps3D           = nullptr;
    ID3D11PixelShader*        ps3DUntextured = nullptr;
    ID3D11Buffer*             cb3D           = nullptr;  // 192 × float4 NV2A constants
    ID3D11Buffer*             cbPS           = nullptr;  // 32  × float4 NV2A PS constants (psC[])
    ID3D11DepthStencilState*  dssOn          = nullptr;  // depth test+write ON (3D)
    ID3D11RasterizerState*    rsCull3D       = nullptr;  // no-cull, depth-clip on

    // Dynamic geometry buffers
    ID3D11Buffer*             dynamicVB      = nullptr;
    uint32_t                  dynamicVBSize  = 0;
    ID3D11Buffer*             dynamicIB      = nullptr;
    uint32_t                  dynamicIBSize  = 0;

    // Render states
    ID3D11BlendState*         bsAlpha        = nullptr;  // src-alpha blend
    ID3D11BlendState*         bsOpaque       = nullptr;  // no blend
    ID3D11RasterizerState*    rsNoCull       = nullptr;
    ID3D11DepthStencilState*  dssOff         = nullptr;  // depth off (2D)

    // Samplers
    ID3D11SamplerState*       samplerLinear  = nullptr;
    ID3D11SamplerState*       samplerWrap    = nullptr;

    // Texture caches
    std::unordered_map<uint32_t, TextureCacheEntry> textureCache;
    std::unordered_map<uint32_t, RenderTargetEntry> rtCache;
    // Back-buffer surface tracking for RT routing
    uint32_t                  xboxBBSurf     = 0;
    uint32_t                  xboxBBSurf2    = 0;
};

static D3D11State g_d3d11;

// ============================================================================
// Host presentation window
// ============================================================================

static HWND  g_hWnd        = nullptr;
static bool  g_wndClassReg = false;

static LRESULT CALLBACK HLE_WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg) {
    case WM_CLOSE:
        PostQuitMessage(0);
        return 0;
    case WM_DESTROY:
        g_hWnd = nullptr;
        return 0;
    }
    return DefWindowProcW(hWnd, msg, wParam, lParam);
}

// Forward declarations for D3D11 helpers defined later in the file
static void HLE_InitD3D11(HWND hwnd, uint32_t w, uint32_t h);

static void HLE_CreatePresentationWindow(uint32_t width, uint32_t height)
{
    if (g_hWnd) return;

    if (!g_wndClassReg) {
        WNDCLASSEXW wc{};
        wc.cbSize        = sizeof(wc);
        wc.style         = CS_HREDRAW | CS_VREDRAW;
        wc.lpfnWndProc   = HLE_WndProc;
        wc.hInstance      = GetModuleHandleW(nullptr);
        wc.hCursor       = LoadCursorW(nullptr, MAKEINTRESOURCEW(32512));
        wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
        wc.lpszClassName = L"DoomXRecompWnd";
        RegisterClassExW(&wc);
        g_wndClassReg = true;
    }

    RECT rc = { 0, 0, (LONG)width, (LONG)height };
    AdjustWindowRect(&rc, WS_OVERLAPPEDWINDOW, FALSE);

    g_hWnd = CreateWindowExW(
        0, L"DoomXRecompWnd", L"Burnout 3 Recomp",
        WS_OVERLAPPEDWINDOW | WS_VISIBLE,
        CW_USEDEFAULT, CW_USEDEFAULT,
        rc.right - rc.left, rc.bottom - rc.top,
        nullptr, nullptr, GetModuleHandleW(nullptr), nullptr);

    fprintf(stderr, "[HLE] Created presentation window %ux%u (HWND=%p)\n",
            width, height, (void*)g_hWnd);
}

static void HLE_PumpMessages()
{
    MSG msg;
    while (PeekMessageW(&msg, nullptr, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            ExitProcess(0);
        }
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
}

// ============================================================================
// Xbox D3D constants (from Cxbx-Reloaded XbD3D8Types.h)
// ============================================================================

// Resource Common field masks
static constexpr uint32_t X_D3DCOMMON_REFCOUNT_MASK    = 0x0000FFFF;
static constexpr uint32_t X_D3DCOMMON_TYPE_MASK        = 0x00070000;
static constexpr uint32_t X_D3DCOMMON_TYPE_SHIFT       = 16;
static constexpr uint32_t X_D3DCOMMON_TYPE_VERTEXBUFFER = 0x00000000;
static constexpr uint32_t X_D3DCOMMON_TYPE_INDEXBUFFER  = 0x00010000;
static constexpr uint32_t X_D3DCOMMON_TYPE_PUSHBUFFER   = 0x00020000;
static constexpr uint32_t X_D3DCOMMON_TYPE_PALETTE      = 0x00030000;
static constexpr uint32_t X_D3DCOMMON_TYPE_TEXTURE      = 0x00040000;
static constexpr uint32_t X_D3DCOMMON_TYPE_SURFACE      = 0x00050000;
static constexpr uint32_t X_D3DCOMMON_TYPE_FIXUP        = 0x00060000;
static constexpr uint32_t X_D3DCOMMON_D3DCREATED        = 0x01000000;
static constexpr uint32_t X_D3DCOMMON_ISLOCKED          = 0x02000010;

// Resource types (X_D3DRESOURCETYPE)
static constexpr uint32_t X_D3DRTYPE_NONE           = 0;
static constexpr uint32_t X_D3DRTYPE_SURFACE        = 1;
static constexpr uint32_t X_D3DRTYPE_VOLUME         = 2;
static constexpr uint32_t X_D3DRTYPE_TEXTURE        = 3;
static constexpr uint32_t X_D3DRTYPE_VOLUMETEXTURE  = 4;
static constexpr uint32_t X_D3DRTYPE_CUBETEXTURE    = 5;
static constexpr uint32_t X_D3DRTYPE_VERTEXBUFFER   = 6;
static constexpr uint32_t X_D3DRTYPE_INDEXBUFFER    = 7;
static constexpr uint32_t X_D3DRTYPE_PUSHBUFFER     = 8;
static constexpr uint32_t X_D3DRTYPE_PALETTE        = 9;

// Palette sizes (entries)
static constexpr uint32_t X_D3DPALETTE_256 = 0;

// Xbox D3DCLEAR flags (from Cxbx-Reloaded XbD3D8Types.h)
static constexpr uint32_t X_D3DCLEAR_ZBUFFER   = 0x00000001;
static constexpr uint32_t X_D3DCLEAR_STENCIL   = 0x00000002;
static constexpr uint32_t X_D3DCLEAR_TARGET_R  = 0x00000010;
static constexpr uint32_t X_D3DCLEAR_TARGET_G  = 0x00000020;
static constexpr uint32_t X_D3DCLEAR_TARGET_B  = 0x00000040;
static constexpr uint32_t X_D3DCLEAR_TARGET_A  = 0x00000080;
static constexpr uint32_t X_D3DCLEAR_TARGET    = X_D3DCLEAR_TARGET_R | X_D3DCLEAR_TARGET_G |
                                                 X_D3DCLEAR_TARGET_B | X_D3DCLEAR_TARGET_A;

// Xbox D3D format values (subset used by Doom)
static constexpr uint32_t X_D3DFMT_A8R8G8B8     = 0x06;
static constexpr uint32_t X_D3DFMT_X8R8G8B8     = 0x07;
static constexpr uint32_t X_D3DFMT_R5G6B5       = 0x05;
static constexpr uint32_t X_D3DFMT_A1R5G5B5     = 0x02;
static constexpr uint32_t X_D3DFMT_A4R4G4B4     = 0x04;
static constexpr uint32_t X_D3DFMT_P8           = 0x0B;
static constexpr uint32_t X_D3DFMT_DXT1         = 0x0C;
static constexpr uint32_t X_D3DFMT_DXT3         = 0x0E;
static constexpr uint32_t X_D3DFMT_DXT5         = 0x0F;
static constexpr uint32_t X_D3DFMT_LIN_A8R8G8B8 = 0x12;
static constexpr uint32_t X_D3DFMT_LIN_X8R8G8B8 = 0x1E;

// Pixel container format field masks
static constexpr uint32_t X_D3DFORMAT_FORMAT_MASK  = 0x0000FF00;
static constexpr uint32_t X_D3DFORMAT_FORMAT_SHIFT = 8;
static constexpr uint32_t X_D3DFORMAT_MIPMAP_MASK  = 0x000F0000;
static constexpr uint32_t X_D3DFORMAT_MIPMAP_SHIFT = 16;
static constexpr uint32_t X_D3DFORMAT_USIZE_SHIFT  = 20;
static constexpr uint32_t X_D3DFORMAT_VSIZE_SHIFT  = 24;
static constexpr uint32_t X_D3DFORMAT_PSIZE_SHIFT  = 28;
static constexpr uint32_t X_D3DFORMAT_DIMENSION_SHIFT = 4;

// Size field masks (non-power-of-2 / linear textures)
static constexpr uint32_t X_D3DSIZE_WIDTH_MASK   = 0x00000FFF;
static constexpr uint32_t X_D3DSIZE_HEIGHT_MASK  = 0x00FFF000;
static constexpr uint32_t X_D3DSIZE_HEIGHT_SHIFT = 12;
static constexpr uint32_t X_D3DSIZE_PITCH_MASK   = 0xFF000000;
static constexpr uint32_t X_D3DSIZE_PITCH_SHIFT  = 24;

// ============================================================================
// Guest device layout offsets
// ============================================================================

static constexpr uint32_t kDevicePtrAddr    = 0xA5648;
static constexpr uint32_t kDeviceAddr       = 0xA5650;
static constexpr uint32_t kDeviceFlagsOfs   = 0xA5658;
static constexpr uint32_t kD3DInitFlag      = 0xA5F88;
static constexpr uint32_t kPushBufSizeAddr  = 0xA7E28;
static constexpr uint32_t kPushBufSegAddr   = 0xA7E2C;

static constexpr uint32_t kDeviceRenderTarget  = 0x1A10;
static constexpr uint32_t kDevicePaletteBase   = 0x0B10; // 4 palette slots: [stage] * 4
static constexpr uint32_t kDeviceBackBufBase  = 0x1A14;
static constexpr uint32_t kDeviceDepthStencil = 0x1A08;
static constexpr uint32_t kDeviceViewport     = 0x0C80;  // D3DVIEWPORT8: X,Y,W,H,MinZ,MaxZ

// ============================================================================
// Simple contiguous-memory bump allocator for guest GPU resources
// ============================================================================
// ContigAlloc region starts at 0x19000000, above the o1heap (0x200000..0x19000000),
// to prevent the GPU resource bump allocator from corrupting heap-managed memory.
static uint32_t s_contigAllocHead = 0x19000000;

static uint32_t ContigAlloc(uint32_t size, uint32_t alignment = 64)
{
    s_contigAllocHead = (s_contigAllocHead + alignment - 1) & ~(alignment - 1);
    uint32_t addr = s_contigAllocHead;
    s_contigAllocHead += size;
    return addr;
}

// ============================================================================
// Xbox D3D format helpers
// ============================================================================

// Returns the format-table entry byte: bits [5:2] = BPP, bit 0 = linear flag.
// Mirrors the NV2A format table at 0x35BE08 in the Xbox D3D library.
static uint8_t XboxFormatInfo(uint32_t format)
{
    switch (format) {
    // Swizzled formats (bit 0 = 0)
    case 0x00: return  8;  // L8
    case 0x01: return  8;  // AL8
    case 0x02: return 16;  // A1R5G5B5
    case 0x03: return 16;  // X1R5G5B5
    case 0x04: return 16;  // A4R4G4B4
    case 0x05: return 16;  // R5G6B5
    case 0x06: return 32;  // A8R8G8B8
    case 0x07: return 32;  // X8R8G8B8
    case 0x0B: return  8;  // P8
    case 0x0C: return  4;  // DXT1 (compressed, separate handling)
    case 0x0E: return  8;  // DXT3
    case 0x0F: return  8;  // DXT5
    case 0x11: return 16;  // G8B8
    case 0x19: return  8;  // A8
    case 0x1B: return  8;  // LIN_L8
    case 0x24: return 16;  // YUY2
    case 0x25: return 16;  // UYVY
    case 0x2E: return 32;  // D24S8
    case 0x30: return 16;  // D16
    // Linear formats (bit 0 = 1)
    case 0x12: return 32 | 1;  // LIN_A8R8G8B8
    case 0x1A: return 32 | 1;  // LIN_A8B8G8R8
    case 0x1C: return 16 | 1;  // LIN_R5G6B5
    case 0x1D: return 16 | 1;  // LIN_A1R5G5B5
    case 0x1E: return 32 | 1;  // LIN_X8R8G8B8
    case 0x2C: return 32 | 1;  // LIN_D24S8
    default:   return 32;      // unknown → 32bpp swizzled
    }
}

static bool IsCompressedFormat(uint32_t format)
{
    return format == 0x0C || format == 0x0D || format == 0x0E || format == 0x0F;
}

static uint32_t Log2Ceil(uint32_t v)
{
    uint32_t r = 0;
    while ((1u << r) < v) r++;
    return r;
}

// Swap / VBlank counters (returned by D3DDevice_Swap, read by guest code)
int g_swapCount  = 0;
static uint32_t g_vblankCount = 0;
static uint32_t g_drawCallCount = 0;  // incremented by DrawVertices / End

// Back-buffer dimensions (set during CreateDevice, used for rasteriser & blit)
static uint32_t g_bbWidth  = 640;
static uint32_t g_bbHeight = 480;

// NV2A push buffer method constants (count=1, subchannel=0)
static constexpr uint32_t NV2A_SET_ALPHA_TEST_ENABLE = 0x00040300;
static constexpr uint32_t NV2A_SET_BLEND_ENABLE      = 0x00040304;
static constexpr uint32_t NV2A_SET_ALPHA_FUNC        = 0x00040338;
static constexpr uint32_t NV2A_SET_ALPHA_REF         = 0x0004033C;
static constexpr uint32_t NV2A_SET_BLEND_FUNC_SRC    = 0x00040344;
static constexpr uint32_t NV2A_SET_BLEND_FUNC_DST    = 0x00040348;

// Tracked GPU render states
static bool g_alphaTestEnabled   = false;
static bool g_alphaBlendEnabled  = false;
static uint32_t g_alphaRef       = 0;
static uint32_t g_alphaFunc      = 8; // D3DCMP_ALWAYS
static uint32_t g_blendSrc       = 1; // D3DBLEND_ONE
static uint32_t g_blendDst       = 0; // D3DBLEND_ZERO

// RW render state lookup table address (maps RW state index -> NV2A method)
static constexpr uint32_t kRWStateMethodTable = 0x3A8190;
static constexpr uint32_t kRWStateMethodCount = 92;

// Xbox D3D Texture Stage State types (indices 12+ for combiner ops)
static constexpr uint32_t D3DTSS_COLOROP   = 12;
static constexpr uint32_t D3DTSS_COLORARG0 = 13;
static constexpr uint32_t D3DTSS_COLORARG1 = 14;
static constexpr uint32_t D3DTSS_COLORARG2 = 15;
static constexpr uint32_t D3DTSS_ALPHAOP   = 16;
static constexpr uint32_t D3DTSS_ALPHAARG0 = 17;
static constexpr uint32_t D3DTSS_ALPHAARG1 = 18;
static constexpr uint32_t D3DTSS_ALPHAARG2 = 19;

// D3D Texture Op values
static constexpr uint32_t D3DTOP_DISABLE    = 1;
static constexpr uint32_t D3DTOP_SELECTARG1 = 2;
static constexpr uint32_t D3DTOP_SELECTARG2 = 3;
static constexpr uint32_t D3DTOP_MODULATE   = 4;
static constexpr uint32_t D3DTOP_MODULATE2X = 5;
static constexpr uint32_t D3DTOP_MODULATE4X = 6;

// D3D Texture Argument values
static constexpr uint32_t D3DTA_DIFFUSE = 0;
static constexpr uint32_t D3DTA_CURRENT = 1;
static constexpr uint32_t D3DTA_TEXTURE = 2;

// Tracked combiner state for stage 0 (set by SetTextureStageStateNotInline)
static uint32_t g_colorOp   = D3DTOP_MODULATE; // D3D default
static uint32_t g_colorArg1 = D3DTA_TEXTURE;
static uint32_t g_colorArg2 = D3DTA_CURRENT;

// Returns true if the current TSS combiner state for stage 0 actually samples
// the texture. SELECTARG1/2 only use texture if the selected arg is D3DTA_TEXTURE;
// for other ops (MODULATE etc.) either arg may reference it.
static bool ColorOpUsesTexture() {
    if (g_colorOp == D3DTOP_DISABLE) return false;
    if (g_colorOp == D3DTOP_SELECTARG1) return (g_colorArg1 & 0x7) == D3DTA_TEXTURE;
    if (g_colorOp == D3DTOP_SELECTARG2) return (g_colorArg2 & 0x7) == D3DTA_TEXTURE;
    return ((g_colorArg1 & 0x7) == D3DTA_TEXTURE) || ((g_colorArg2 & 0x7) == D3DTA_TEXTURE);
}

// RW pending TSS buffer: value at 0x75D740 + (stage + stateType*4) * 4
static constexpr uint32_t kRWTSSBuffer = 0x75D740;
// D3D TSS cache: value at 0x35D498 + (stage*32 + stateType) * 4
static constexpr uint32_t kD3DTSSCache = 0x35D498;

// ----------------------------------------------------------------------------
// Host-side shadow of the Xbox D3D library's cached GPU state.
//
// In the original XBE the XBD3D8 library keeps two large cache arrays in the
// .data segment — D3D_g_RenderState at 0x35FB58 (166 dwords) and
// D3D_g_DeferredTextureState at 0x35D498 (4 stages * 32 states). Game code
// (RenderWare's __rwXbCache*) reads these directly to decide whether a
// pending state change is redundant. We intercept the Set* calls in HLE
// so those guest segments are never touched during the hot path; instead
// we shadow the current "last programmed" state here.
//
// This replaces the previous approach of writing back into 0x35FB58 /
// 0x35D498 via X86_MEM_WRITE_u32 (which was expensive and triggered the
// D3D-segment access tracer on every hot-path read).
// ----------------------------------------------------------------------------
static constexpr uint32_t kHLERenderStateCount = 166; // 0x298 / 4
static uint32_t g_hleRenderStateCache[kHLERenderStateCount] = {};
static uint32_t g_hleTSSCache[4][32] = {};

// ============================================================================
// Device creation and lifecycle
// ============================================================================

// Direct3D_CreateDevice  (0x9A630)
// 6 args, ret 24
void Direct3D_CreateDevice(X86Context& ctx, uint8_t* base)
{
    uint32_t adapter  = GuestArg32(ctx, base, 0);
    uint32_t devType  = GuestArg32(ctx, base, 1);
    uint32_t hWnd     = GuestArg32(ctx, base, 2);
    uint32_t flags    = GuestArg32(ctx, base, 3);
    uint32_t pPresent = GuestArg32(ctx, base, 4);
    uint32_t ppDevice = GuestArg32(ctx, base, 5);

    fprintf(stderr, "[HLE] Direct3D_CreateDevice(adapter=%u, type=%u, hwnd=0x%X, "
                    "flags=0x%X, pPresent=0x%08X, ppDevice=0x%08X)\n",
            adapter, devType, hWnd, flags, pPresent, ppDevice);

    if (X86_MEM_READ_u32(base, kPushBufSegAddr) == 0)
        X86_MEM_WRITE_u32(base, kPushBufSegAddr, 0x80000);
    if (X86_MEM_READ_u32(base, kPushBufSizeAddr) == 0)
        X86_MEM_WRITE_u32(base, kPushBufSizeAddr, 0x8000);

    X86_MEM_WRITE_u32(base, kDevicePtrAddr, kDeviceAddr);
    X86_MEM_WRITE_u32(base, kD3DInitFlag, 1);

    uint32_t devFlags = X86_MEM_READ_u32(base, kDeviceFlagsOfs);
    devFlags |= (flags & 0x10);
    X86_MEM_WRITE_u32(base, kDeviceFlagsOfs, devFlags);

    if (ppDevice != 0)
        X86_MEM_WRITE_u32(base, ppDevice, kDeviceAddr);

    // Set up back-buffer and depth-stencil surfaces from present params.
    if (pPresent != 0) {
        uint32_t bbWidth  = X86_MEM_READ_u32(base, pPresent + 0x00);
        uint32_t bbHeight = X86_MEM_READ_u32(base, pPresent + 0x04);
        uint32_t bbCount  = X86_MEM_READ_u32(base, pPresent + 0x0C);

        fprintf(stderr, "[HLE]   PresentParams: %ux%u count=%u\n",
                bbWidth, bbHeight, bbCount);

        if (bbCount == 0) bbCount = 1;
        for (uint32_t i = 0; i < bbCount && i < 3; i++) {
            uint32_t surfAddr = ContigAlloc(12);
            X86_MEM_WRITE_u32(base, surfAddr + 0,
                              1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED);
            uint32_t pixBuf = ContigAlloc(bbWidth * bbHeight * 4);
            X86_MEM_WRITE_u32(base, surfAddr + 4, pixBuf);
            X86_MEM_WRITE_u32(base, surfAddr + 8, 0);
            X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceBackBufBase + i * 4, surfAddr);
            // The first back-buffer is also the initial render target.
            if (i == 0)
                X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, surfAddr);
        }

        uint32_t enableDS = X86_MEM_READ_u32(base, pPresent + 0x20);
        if (enableDS) {
            uint32_t dsAddr = ContigAlloc(12);
            X86_MEM_WRITE_u32(base, dsAddr + 0,
                              1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED);
            uint32_t dsBuf = ContigAlloc(bbWidth * bbHeight * 4);
            X86_MEM_WRITE_u32(base, dsAddr + 4, dsBuf);
            X86_MEM_WRITE_u32(base, dsAddr + 8, 0);
            X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceDepthStencil, dsAddr);
        }
    }

    // Initialise viewport so D3DDevice_Clear doesn't see garbage dimensions.
    {
        uint32_t vpW = 640, vpH = 480;
        if (pPresent != 0) {
            uint32_t pw = X86_MEM_READ_u32(base, pPresent + 0x00);
            uint32_t ph = X86_MEM_READ_u32(base, pPresent + 0x04);
            if (pw > 0 && ph > 0) { vpW = pw; vpH = ph; }
        }
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceViewport + 0,  0);   // X
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceViewport + 4,  0);   // Y
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceViewport + 8,  vpW); // Width
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceViewport + 12, vpH); // Height
        // MinZ / MaxZ as floats
        float minZ = 0.0f, maxZ = 1.0f;
        X86_MEM_WRITE_F32(base, kDeviceAddr + kDeviceViewport + 16, minZ);
        X86_MEM_WRITE_F32(base, kDeviceAddr + kDeviceViewport + 20, maxZ);

        g_bbWidth  = vpW;
        g_bbHeight = vpH;

        // Create a host Win32 window for presentation.
        HLE_CreatePresentationWindow(vpW, vpH);
        // Initialize D3D11 hardware device now that we have a window.
        HLE_InitD3D11(g_hWnd, vpW, vpH);
    }

    fprintf(stderr, "[HLE] Direct3D_CreateDevice -> S_OK (device=0x%08X)\n", kDeviceAddr);

    GuestReturn32(ctx, 0);       // S_OK
    GuestStackCleanup(ctx, 24);  // ret 24
}

// ============================================================================
// Swap / Present
// ============================================================================

// D3DDevice_Swap  (0xD6D30) — 1 arg, ret 4
void D3DDevice_Swap(X86Context& ctx, uint8_t* base)
{
    uint32_t flags = GuestArg32(ctx, base, 0);
    //fprintf(stderr, "[HLE] D3DDevice_Swap(flags=0x%X) frame=%u\n", flags, g_swapCount);

    // Dump frame 30 to PNG for debugging
    {
        static uint32_t dumpFrame = 0;
        if (dumpFrame < 31) {
            dumpFrame++;
            if (dumpFrame == 31) {
                uint32_t d3dObj = X86_MEM_READ_u32(base, 0x118CF0u);
                uint32_t surf = d3dObj ? X86_MEM_READ_u32(base, d3dObj + 0xBC) : 0;
                if (surf) {
                    uint32_t pixFmt   = X86_MEM_READ_u32(base, surf + 0x04);
                    uint32_t w        = X86_MEM_READ_u32(base, surf + 0x08);
                    uint32_t h        = X86_MEM_READ_u32(base, surf + 0x0C);
                    uint32_t pixAddr  = X86_MEM_READ_u32(base, surf + 0x14);
                    uint32_t palAddr  = pixFmt ? X86_MEM_READ_u32(base, pixFmt + 0x00) : 0;
                    uint32_t colAddr  = palAddr ? X86_MEM_READ_u32(base, palAddr + 0x04) : 0;
                    if (pixAddr && w && h) {
                        std::vector<uint8_t> rgba(w * h * 4);
                        const uint8_t* s = base + pixAddr;
                        for (uint32_t i = 0; i < w * h; i++) {
                            uint8_t idx = s[i];
                            if (colAddr) {
                                rgba[i*4+0] = base[colAddr + idx*4 + 0];
                                rgba[i*4+1] = base[colAddr + idx*4 + 1];
                                rgba[i*4+2] = base[colAddr + idx*4 + 2];
                            } else {
                                rgba[i*4+0] = rgba[i*4+1] = rgba[i*4+2] = idx;
                            }
                            rgba[i*4+3] = 255;
                        }
                        stbi_write_png("frame_dump.png", w, h, 4, rgba.data(), w * 4);
                        fprintf(stderr, "[HLE] FRAME DUMP: %ux%u -> frame_dump.png (palette=%s)\n",
                                w, h, colAddr ? "yes" : "no");
                    }
                }
            }
        }
    }

    g_swapCount++;
    g_vblankCount++;
    g_drawCallCount = 0;

    // Pump Win32 messages so the window stays responsive.
    HLE_PumpMessages();

    // ---- D3D11 present + VBlank signaling ------------------------------------
    if (g_d3d11.initialized && g_d3d11.swapChain) {
        g_d3d11.swapChain->Present(1, 0);

        // Signal Xbox VBlank events so guest timer code advances correctly.
        auto signalVBlank = [&](uint32_t addr) {
            if (addr == 0) return;
            auto* evt = QueryKernelObject<Event>(base, addr, true, false);
            if (evt) { evt->Set(); evt->Reset(); }
        };
        signalVBlank(kDeviceAddr + 0x1DBC);
        signalVBlank(kDeviceAddr + 0x194);
    }

    // ---- Frame pacing: cap at 60 Hz, but don't wait when already behind ----
    // On real Xbox, Swap(0) blocks until VBlank (~16.667 ms).  The game timer
    // uses rdtsc/QPC to measure real elapsed time per frame and simulates the
    // correct number of ticks.  We only need to throttle when the frame was
    // faster than 16.667 ms; when rendering is slow we must NOT add extra
    // delay or the timer will under-count ticks and the game runs slow.
    {
        using Clock = std::chrono::high_resolution_clock;
        static constexpr auto kFramePeriod =
            std::chrono::duration_cast<Clock::duration>(
                std::chrono::duration<double>(1.0 / 60.0));

        static bool s_timerInit = false;
        if (!s_timerInit) {
            timeBeginPeriod(1);
            s_timerInit = true;
        }

        static auto s_frameStart = Clock::now();
        auto elapsed = Clock::now() - s_frameStart;

        // Only sleep if this frame completed faster than one VBlank period.
        if (elapsed < kFramePeriod) {
            auto deadline = s_frameStart + kFramePeriod;
            auto spinPoint = deadline - std::chrono::milliseconds(1);
            if (Clock::now() < spinPoint)
                std::this_thread::sleep_until(spinPoint);
            while (Clock::now() < deadline) {}
        }

        s_frameStart = Clock::now();
    }

    // ---- FPS counter (printed every 60 frames) ----
    {
        using Clock = std::chrono::high_resolution_clock;
        static auto s_lastReport = Clock::now();
        static uint64_t s_frameCount = 0;
        static uint32_t s_lastVBlank = 0;
        s_frameCount++;
        if (s_frameCount % 60 == 0) {
            auto now = Clock::now();
            double ms = std::chrono::duration<double, std::milli>(now - s_lastReport).count();
            uint32_t vblank = X86_MEM_READ_u32(base, 0x4A1EB4u);
            uint32_t vbDelta = vblank - s_lastVBlank;
            fprintf(stderr, "[PERF] 60 swaps in %.1f ms (%.1f fps), vblank=%u (+%u, %.1f vb/sec)\n",
                    ms, 60000.0 / ms, vblank, vbDelta, vbDelta * 1000.0 / ms);
            s_lastVBlank = vblank;
            s_lastReport = now;
        }
    }

    GuestReturn32(ctx, g_swapCount);
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Device caps / parameters / display
// ============================================================================

// D3DDevice_GetDeviceCaps  (0x96700) — 1 arg, ret 4
void D3DDevice_GetDeviceCaps(X86Context& ctx, uint8_t* base)
{
    uint32_t pCaps = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[HLE] D3DDevice_GetDeviceCaps(0x%08X)\n", pCaps);

    if (pCaps != 0) {
        memset(base + pCaps, 0, 300);
        X86_MEM_WRITE_u32(base, pCaps + 0x00, 1);           // DeviceType = HAL
        X86_MEM_WRITE_u32(base, pCaps + 0x04, 0xFFFFFFFF);  // Caps
        X86_MEM_WRITE_u32(base, pCaps + 0x2C, 4);           // MaxTextureBlendStages
        X86_MEM_WRITE_u32(base, pCaps + 0x30, 4);           // MaxSimultaneousTextures
        X86_MEM_WRITE_u32(base, pCaps + 0x34, 4096);        // MaxTextureWidth
        X86_MEM_WRITE_u32(base, pCaps + 0x38, 4096);        // MaxTextureHeight
        X86_MEM_WRITE_u32(base, pCaps + 0x80, 136);         // MaxVertexShaderConst
    }

    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetCreationParameters  (0x96720) — 1 arg, ret 4
void D3DDevice_GetCreationParameters(X86Context& ctx, uint8_t* base)
{
    uint32_t pParams = GuestArg32(ctx, base, 0);
    if (pParams != 0) {
        X86_MEM_WRITE_u32(base, pParams + 0x00, 0);    // AdapterOrdinal
        X86_MEM_WRITE_u32(base, pParams + 0x04, 1);    // DeviceType = HAL
        X86_MEM_WRITE_u32(base, pParams + 0x08, 0);    // hFocusWindow
        X86_MEM_WRITE_u32(base, pParams + 0x0C, 0x20); // BehaviorFlags
    }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetDisplayMode  (0x969E0) — 1 arg, ret 4
void D3DDevice_GetDisplayMode(X86Context& ctx, uint8_t* base)
{
    uint32_t pMode = GuestArg32(ctx, base, 0);
    if (pMode != 0) {
        X86_MEM_WRITE_u32(base, pMode + 0x00, 640);
        X86_MEM_WRITE_u32(base, pMode + 0x04, 480);
        X86_MEM_WRITE_u32(base, pMode + 0x08, 60);
        X86_MEM_WRITE_u32(base, pMode + 0x0C, 0);
        X86_MEM_WRITE_u32(base, pMode + 0x10, X_D3DFMT_LIN_X8R8G8B8);
    }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_IsBusy  (0x97180) — 0 args, plain ret
void D3DDevice_IsBusy(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// VSync / display filter
// ============================================================================

// D3DDevice_BlockUntilVerticalBlank  (0x96890) — 0 args, plain ret
void D3DDevice_BlockUntilVerticalBlank(X86Context& ctx, uint8_t* base)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(16));
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetFlickerFilter  (0xD8100) — plain ret (cdecl in Quake 2 build)
void D3DDevice_SetFlickerFilter(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetSoftDisplayFilter  (0x96910) — 1 arg, ret 4
void D3DDevice_SetSoftDisplayFilter(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Transform
// ============================================================================

// Last-known-good VIEW and PROJECTION matrices, captured by the
// D3DDevice_SetTransform hook. The game occasionally calls SetTransform with
// an all-zero matrix as part of a reset sequence before immediately re-
// setting real values; caching here means a zero clobber doesn't lose the
// previously-valid matrix between draws. Consumed in HLE_Draw3D to
// synthesize c[112..115] when the shader constant upload path is dead.
static float g_lastGoodView[16] = {};
static float g_lastGoodProj[16] = {};
static bool  g_haveView = false;
static bool  g_haveProj = false;

// D3DDevice_SetTransform  (0xD7850) — 2 args, ret 8
void D3DDevice_SetTransform(X86Context& ctx, uint8_t* base)
{
    uint32_t state   = GuestArg32(ctx, base, 0);
    uint32_t pMatrix = GuestArg32(ctx, base, 1);

    // Widened storage: keep state<64 in our slot table (Xbox D3DTS_WORLD = 256,
    // D3DTS_VIEW = 2, D3DTS_PROJECTION = 3, D3DTS_TEXTURE[0..3] = 16..19). We
    // also mirror the high D3DTS_WORLDMATRIX range (256..259) into slots 32..35
    // so host-side MVP composition can see WORLD too.
    if (pMatrix != 0) {
        uint32_t slot = 0xFFFFFFFFu;
        if (state < 32) {
            slot = state;
        } else if (state >= 256 && state < 256 + 4) {
            // D3DTS_WORLDMATRIX(i) -> slot 32..35
            slot = 32 + (state - 256);
        }
        if (slot != 0xFFFFFFFFu) {
            uint32_t dst = kDeviceAddr + 0x0A70 + slot * 64;
            memcpy(base + dst, base + pMatrix, 64);
        }

        // Cache last-good VIEW (state=0) and PROJECTION (state=1). Only
        // accept matrices with a non-zero diagonal — the game is observed
        // to push all-zero matrices as part of a reset/init sequence; those
        // would otherwise invalidate the real transforms mid-frame.
        const float* m = reinterpret_cast<const float*>(base + pMatrix);
        bool hasDiag = (m[0] != 0.0f || m[5] != 0.0f ||
                        m[10] != 0.0f || m[15] != 0.0f);
        if (hasDiag) {
            if (state == 0) {
                memcpy(g_lastGoodView, m, 64);
                g_haveView = true;
            } else if (state == 1) {
                memcpy(g_lastGoodProj, m, 64);
                g_haveProj = true;
            }
        }
    }

    // DIAGNOSTIC: log every *unique* (state, matrix-hash) combination we see,
    // plus a small running count of repeat calls per state. Previously capped
    // at 16 absolute so we only ever saw the very first frame of setup.
    if (pMatrix != 0) {
        float m[16];
        memcpy(m, base + pMatrix, 64);
        // Cheap 64-bit hash of the 16 floats (FNV-1a-ish).
        uint64_t h = 1469598103934665603ull;
        const uint32_t* p = reinterpret_cast<const uint32_t*>(m);
        for (int i = 0; i < 16; i++) { h ^= p[i]; h *= 1099511628211ull; }

        struct Seen { uint32_t state; uint64_t hash; uint32_t count; };
        static std::vector<Seen> s_seen;
        static uint32_t s_totalCalls = 0;
        s_totalCalls++;

        bool novel = true;
        for (auto& s : s_seen) {
            if (s.state == state && s.hash == h) { s.count++; novel = false; break; }
        }
        if (novel && s_seen.size() < 64) {
            s_seen.push_back({state, h, 1});
            // fprintf(stderr, "[HLE] SetTransform state=%u (#%u novel, %u total calls) "
            //         "m=[%.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f / "
            //         "%.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f]\n",
            //         state, (uint32_t)s_seen.size(), s_totalCalls,
            //         m[0],m[1],m[2],m[3], m[4],m[5],m[6],m[7],
            //         m[8],m[9],m[10],m[11], m[12],m[13],m[14],m[15]);
        }
        // Every 1024 calls, dump a short summary so we can see which states
        // are hot (likely per-object WORLD etc.).
        if ((s_totalCalls & 1023) == 0) {
            // fprintf(stderr, "[HLE] SetTransform summary @ %u calls:", s_totalCalls);
            // uint32_t perState[40] = {};
            // for (auto& s : s_seen) {
            //     uint32_t idx = (s.state < 32) ? s.state
            //                  : (s.state >= 256 && s.state < 260) ? (32 + s.state - 256)
            //                  : 39;
            //     if (idx < 40) perState[idx] += s.count;
            // }
            // for (uint32_t i = 0; i < 40; i++) {
            //     if (perState[i]) fprintf(stderr, " s%u=%u", i, perState[i]);
            // }
            // fprintf(stderr, "\n");
        }
    }

    GuestStackCleanup(ctx, 8);
}

// ============================================================================
// Render target / back buffer / depth stencil
// ============================================================================

// D3DDevice_SetRenderTarget  (0x96AB0) — 2 args, ret 8
void D3DDevice_SetRenderTarget(X86Context& ctx, uint8_t* base)
{
    uint32_t pRT = GuestArg32(ctx, base, 0);
    uint32_t pDS = GuestArg32(ctx, base, 1);
    //fprintf(stderr, "[HLE] D3DDevice_SetRenderTarget(pRT=0x%08X, pDS=0x%08X)\n", pRT, pDS);

    if (pRT != 0)
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, pRT);
    if (pDS != 0)
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceDepthStencil, pDS);

    GuestStackCleanup(ctx, 8);
}

// D3DDevice_GetBackBuffer2  (0x96D30) — 1 arg, ret 4
void D3DDevice_GetBackBuffer2(X86Context& ctx, uint8_t* base)
{
    int32_t backBuffer = static_cast<int32_t>(GuestArg32(ctx, base, 0));
    if (backBuffer < 0) backBuffer = 0;

    uint32_t surfAddr = X86_MEM_READ_u32(base,
        kDeviceAddr + kDeviceBackBufBase + backBuffer * 4);

    if (surfAddr != 0) {
        uint32_t common = X86_MEM_READ_u32(base, surfAddr + 0);
        common = (common & ~X_D3DCOMMON_REFCOUNT_MASK)
               | (((common & X_D3DCOMMON_REFCOUNT_MASK) + 1) & X_D3DCOMMON_REFCOUNT_MASK);
        X86_MEM_WRITE_u32(base, surfAddr + 0, common);
    }

    //fprintf(stderr, "[HLE] D3DDevice_GetBackBuffer2(%d) -> 0x%08X\n", backBuffer, surfAddr);

    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetDepthStencilSurface2  (0x96D80) — 0 args, plain ret
void D3DDevice_GetDepthStencilSurface2(X86Context& ctx, uint8_t* base)
{
    uint32_t surfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceDepthStencil);
    fprintf(stderr, "[HLE] D3DDevice_GetDepthStencilSurface2() -> 0x%08X\n", surfAddr);
    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Viewport
// ============================================================================

// D3DDevice_SetViewport  (0x96DA0) — 1 arg, ret 4
void D3DDevice_SetViewport(X86Context& ctx, uint8_t* base)
{
    uint32_t pVP = GuestArg32(ctx, base, 0);
    if (pVP != 0) {
        memcpy(base + kDeviceAddr + 0x0C80, base + pVP, 24);
        uint32_t vpX = X86_MEM_READ_u32(base, kDeviceAddr + 0x0C80);
        uint32_t vpY = X86_MEM_READ_u32(base, kDeviceAddr + 0x0C84);
        uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + 0x0C88);
        uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + 0x0C8C);
        //fprintf(stderr, "[HLE] SetViewport(x=%u, y=%u, w=%u, h=%u)\n", vpX, vpY, vpW, vpH);
    }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetViewportOffsetAndScale  (0xD5520) — 2 args, ret 8
void D3DDevice_GetViewportOffsetAndScale(X86Context& ctx, uint8_t* base)
{
    uint32_t pOffset = GuestArg32(ctx, base, 0);
    uint32_t pScale  = GuestArg32(ctx, base, 1);

    float vpX = (float)X86_MEM_READ_u32(base, kDeviceAddr + 0x0C80);
    float vpY = (float)X86_MEM_READ_u32(base, kDeviceAddr + 0x0C84);
    float vpW = (float)X86_MEM_READ_u32(base, kDeviceAddr + 0x0C88);
    float vpH = (float)X86_MEM_READ_u32(base, kDeviceAddr + 0x0C8C);

    if (pOffset != 0) {
        X86_MEM_WRITE_F32(base, pOffset + 0, vpX + vpW * 0.5f);
        X86_MEM_WRITE_F32(base, pOffset + 4, vpY + vpH * 0.5f);
        X86_MEM_WRITE_F32(base, pOffset + 8, 0.0f);
        X86_MEM_WRITE_F32(base, pOffset + 12, 0.0f);
    }

    if (pScale != 0) {
        X86_MEM_WRITE_F32(base, pScale + 0, vpW * 0.5f);
        X86_MEM_WRITE_F32(base, pScale + 4, -(vpH * 0.5f));
        X86_MEM_WRITE_F32(base, pScale + 8, 1.0f);
        X86_MEM_WRITE_F32(base, pScale + 12, 0.0f);
    }

    GuestStackCleanup(ctx, 8);
}

// D3D_UpdateProjectionViewportTransform  (0x97F60) — 0 args, plain ret
void D3D_UpdateProjectionViewportTransform(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Texture management
// ============================================================================

// D3DDevice_SetTexture  (0x96FD0) — 2 args, ret 8
static void HLE_SetTexture(uint8_t* base, uint32_t stage, uint32_t pTexture)
{
    if (stage < 4)
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0B00 + stage * 4, pTexture);
    static int s_logLeft = 16;
    if (s_logLeft > 0) {
        fprintf(stderr, "[HLE] SetTexture stage=%u pTexture=0x%08X\n",
                stage, pTexture);
        s_logLeft--;
    }
}

void D3DDevice_SetTexture(X86Context& ctx, uint8_t* base)
{
    uint32_t stage    = GuestArg32(ctx, base, 0);
    uint32_t pTexture = GuestArg32(ctx, base, 1);

    HLE_SetTexture(base, stage, pTexture);
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_CreateTexture2  (0x97830) — 7 args, ret 28
void D3DDevice_CreateTexture2(X86Context& ctx, uint8_t* base)
{
    uint32_t width  = GuestArg32(ctx, base, 0);
    uint32_t height = GuestArg32(ctx, base, 1);
    uint32_t depth  = GuestArg32(ctx, base, 2);
    uint32_t levels = GuestArg32(ctx, base, 3);
    uint32_t usage  = GuestArg32(ctx, base, 4);
    uint32_t format = GuestArg32(ctx, base, 5);
    uint32_t type   = GuestArg32(ctx, base, 6);

    fprintf(stderr, "[HLE] D3DDevice_CreateTexture2(%ux%ux%u, levels=%u, fmt=0x%X, type=%u)\n",
            width, height, depth, levels, format, type);

    if (levels == 0) levels = 1;
    if (depth == 0) depth = 1;

    uint32_t resAddr = ContigAlloc(20, 64);
    uint32_t commonType = (type == X_D3DRTYPE_SURFACE)
                        ? X_D3DCOMMON_TYPE_SURFACE : X_D3DCOMMON_TYPE_TEXTURE;

    X86_MEM_WRITE_u32(base, resAddr + 0,
                      1 | commonType | X_D3DCOMMON_D3DCREATED);

    uint32_t pixelSize = width * height * depth * 4;
    uint32_t dataAddr = ContigAlloc(pixelSize, 128);
    memset(base + dataAddr, 0, pixelSize);

    X86_MEM_WRITE_u32(base, resAddr + 4, dataAddr);
    X86_MEM_WRITE_u32(base, resAddr + 8, 0);

    uint32_t fmtField = (format << X_D3DFORMAT_FORMAT_SHIFT)
                      | ((levels - 1) << X_D3DFORMAT_MIPMAP_SHIFT);
    X86_MEM_WRITE_u32(base, resAddr + 12, fmtField);
    X86_MEM_WRITE_u32(base, resAddr + 16,
                      ((width - 1) & 0xFFF) | (((height - 1) & 0xFFF) << 12));

    GuestReturn32(ctx, resAddr);
    GuestStackCleanup(ctx, 28);
}

// D3DBaseTexture_GetLevelCount  (0x978E0) — 1 arg, ret 4
void D3DBaseTexture_GetLevelCount(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t levels = 1;
    if (pThis != 0) {
        uint32_t fmtField = X86_MEM_READ_u32(base, pThis + 12);
        levels = ((fmtField & X_D3DFORMAT_MIPMAP_MASK) >> X_D3DFORMAT_MIPMAP_SHIFT) + 1;
    }
    GuestReturn32(ctx, levels);
    GuestStackCleanup(ctx, 4);
}

// D3DTexture_GetLevelDesc  (0x978F0) — trampoline to D3D8_Get2DSurfaceDesc, ret 12
void D3DTexture_GetLevelDesc(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t level = GuestArg32(ctx, base, 1);
    uint32_t pDesc = GuestArg32(ctx, base, 2);

    if (pThis != 0 && pDesc != 0) {
        uint32_t fmtField  = X86_MEM_READ_u32(base, pThis + 12);
        uint32_t sizeField = X86_MEM_READ_u32(base, pThis + 16);
        uint32_t fmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

        uint32_t texW, texH;
        if (sizeField != 0) {
            texW = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
            texH = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
        } else {
            uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
            uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
            int adjU = (int)logU - (int)level;
            int adjV = (int)logV - (int)level;
            texW = 1u << (adjU > 0 ? adjU : 0);
            texH = 1u << (adjV > 0 ? adjV : 0);
        }

        // X_D3DSURFACE_DESC layout (7 DWORDs, 28 bytes):
        //   [0] Format, [1] Type, [2] Usage,
        //   [3] Size,   [4] MultiSampleType,
        //   [5] Width,  [6] Height
        X86_MEM_WRITE_u32(base, pDesc +  0, fmt);   // Format
        X86_MEM_WRITE_u32(base, pDesc +  4, 3);     // Type = D3DRTYPE_TEXTURE
        X86_MEM_WRITE_u32(base, pDesc +  8, 0);     // Usage
        X86_MEM_WRITE_u32(base, pDesc + 12, 0);     // Size (unused by caller)
        X86_MEM_WRITE_u32(base, pDesc + 16, 0);     // MultiSampleType
        X86_MEM_WRITE_u32(base, pDesc + 20, texW);  // Width
        X86_MEM_WRITE_u32(base, pDesc + 24, texH);  // Height

        fprintf(stderr, "[HLE] D3DTexture_GetLevelDesc(0x%08X, %u) -> %ux%u\n",
                pThis, level, texW, texH);
    }

    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 12);
}

// D3DTexture_GetSurfaceLevel2  (0x97900) — 2 args, ret 8
void D3DTexture_GetSurfaceLevel2(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t level = GuestArg32(ctx, base, 1);

    uint32_t surfAddr = ContigAlloc(16, 64);
    X86_MEM_WRITE_u32(base, surfAddr + 0,
                      1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED);
    uint32_t parentData = 0;
    if (pThis != 0)
        parentData = X86_MEM_READ_u32(base, pThis + 4);
    X86_MEM_WRITE_u32(base, surfAddr + 4, parentData);
    X86_MEM_WRITE_u32(base, surfAddr + 8, 0);
    X86_MEM_WRITE_u32(base, surfAddr + 12, pThis);

    if (pThis != 0) {
        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        common++;
        X86_MEM_WRITE_u32(base, pThis + 0, common);
    }

    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 8);
}

// D3DTexture_LockRect  (0x97950) — 5 args, ret 20
void D3DTexture_LockRect(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0);
    uint32_t level       = GuestArg32(ctx, base, 1);
    uint32_t pLockedRect = GuestArg32(ctx, base, 2);

    if (pThis != 0 && pLockedRect != 0) {
        uint32_t dataAddr = X86_MEM_READ_u32(base, pThis + 4);
        uint32_t sizeField = X86_MEM_READ_u32(base, pThis + 16);
        uint32_t width = (sizeField & 0xFFF) + 1;
        uint32_t pitch = width * 4;

        X86_MEM_WRITE_u32(base, pLockedRect + 0, pitch);
        X86_MEM_WRITE_u32(base, pLockedRect + 4, dataAddr);

        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        common |= X_D3DCOMMON_ISLOCKED;
        X86_MEM_WRITE_u32(base, pThis + 0, common);
    }

    GuestStackCleanup(ctx, 20);
}

// ============================================================================
// Clear / Scissor / Screen offset
// ============================================================================

// D3DDevice_Clear  (0x97980) — 6 args, ret 24
//
// Args (stdcall):
//   [0] Count    — number of rects (0 = clear entire render target)
//   [1] pRects   — guest pointer to array of D3DRECT {x1,y1,x2,y2} (each 16 bytes)
//   [2] Flags    — X_D3DCLEAR_TARGET / ZBUFFER / STENCIL bitmask
//   [3] Color    — A8R8G8B8 clear colour
//   [4] Z        — depth clear value (float, passed as uint32_t bitwise)
//   [5] Stencil  — stencil clear value
void D3DDevice_Clear(X86Context& ctx, uint8_t* base)
{
    uint32_t count   = GuestArg32(ctx, base, 0);
    uint32_t pRects  = GuestArg32(ctx, base, 1);
    uint32_t flags   = GuestArg32(ctx, base, 2);
    uint32_t color   = GuestArg32(ctx, base, 3);
    uint32_t zBits   = GuestArg32(ctx, base, 4); // float reinterpreted as u32
    uint32_t stencil = GuestArg32(ctx, base, 5);

    float zVal;
    memcpy(&zVal, &zBits, sizeof(float));

    if (g_d3d11.initialized && g_d3d11.backBufferRTV) {
        // ---- D3D11 hardware clear ----
        if (flags & X_D3DCLEAR_TARGET) {
            // Convert A8R8G8B8 to float[4] RGBA
            float a = ((color >> 24) & 0xFF) / 255.0f;
            float r = ((color >> 16) & 0xFF) / 255.0f;
            float g = ((color >>  8) & 0xFF) / 255.0f;
            float b = ((color >>  0) & 0xFF) / 255.0f;
            float clearColor[4] = { r, g, b, a };
            g_d3d11.context->ClearRenderTargetView(g_d3d11.backBufferRTV, clearColor);
        }
        if ((flags & (X_D3DCLEAR_ZBUFFER | X_D3DCLEAR_STENCIL)) && g_d3d11.depthDSV) {
            UINT dsFlags = 0;
            if (flags & X_D3DCLEAR_ZBUFFER) dsFlags |= D3D11_CLEAR_DEPTH;
            if (flags & X_D3DCLEAR_STENCIL) dsFlags |= D3D11_CLEAR_STENCIL;
            g_d3d11.context->ClearDepthStencilView(
                g_d3d11.depthDSV, dsFlags, zVal, static_cast<UINT8>(stencil & 0xFF));
        }
    }

    GuestStackCleanup(ctx, 24);
}

// D3DDevice_SetScissors  (0x97290) — 3 args, ret 12
//   arg0: Count (DWORD) — number of rects
//   arg1: Exclusive (BOOL) — TRUE = exclude rects, FALSE = include (clip to) rects
//   arg2: pRects (D3DRECT*) — pointer to array of {left, top, right, bottom}
void D3DDevice_SetScissors(X86Context& ctx, uint8_t* base)
{
    uint32_t count     = GuestArg32(ctx, base, 0);
    uint32_t exclusive = GuestArg32(ctx, base, 1);
    uint32_t pRects    = GuestArg32(ctx, base, 2);

    //fprintf(stderr, "[HLE] SetScissors(count=%u, exclusive=%u, pRects=0x%08X)\n",
    //        count, exclusive, pRects);

    if (count > 0 && pRects != 0 && !exclusive) {
        // Store first inclusive scissor rect in device state
        uint32_t left   = X86_MEM_READ_u32(base, pRects + 0);
        uint32_t top    = X86_MEM_READ_u32(base, pRects + 4);
        uint32_t right  = X86_MEM_READ_u32(base, pRects + 8);
        uint32_t bottom = X86_MEM_READ_u32(base, pRects + 12);
        //fprintf(stderr, "[HLE]   rect[0] = (%u, %u, %u, %u)\n", left, top, right, bottom);

        // Store in device state for rasterizer clipping
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D00, 1);      // scissor enabled
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D04, left);
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D08, top);
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D0C, right);
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D10, bottom);
    } else {
        // Disable scissor (count=0 or exclusive mode)
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0D00, 0);
    }

    GuestStackCleanup(ctx, 12);
}

// D3DDevice_SetScreenSpaceOffset  (0x97590) — 2 args, ret 8
void D3DDevice_SetScreenSpaceOffset(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// ============================================================================
// Render state — SetRenderState_* (most: 1 arg, ret 4)
// ============================================================================

// All SetRenderState_* functions use ret 4 (stdcall, 1 arg) in Quake 2 build.
#define DEFINE_SETRENDERSTATE_STUB_RET4(name) \
void name(X86Context& ctx, uint8_t* base) { GuestStackCleanup(ctx, 4); }

DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_EdgeAntiAlias)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_ShadowFunc)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_FogColor)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_CullMode)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_NormalizeNormals)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_TextureFactor)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_LineWidth)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_Dxt1NoiseEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_ZBias)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_LogicOp)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_FillMode)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_BackFillMode)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_TwoSidedLighting)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_VertexBlend)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_ZEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_StencilEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_StencilFail)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_YuvEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_OcclusionCullEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_StencilCullEnable)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_RopZCmpAlwaysRead)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_RopZRead)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_DoNotCullUncompressed)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_MultiSampleMode)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_MultiSampleRenderTargetMode)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_MultiSampleAntiAlias)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_MultiSampleMask)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_SampleAlpha)
DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_PSTextureModes)

#undef DEFINE_SETRENDERSTATE_STUB_RET4

// D3DDevice_SetRenderState_FrontFace  (0xD47F0) — 1 arg, ret 4 in Quake 2 build
void D3DDevice_SetRenderState_FrontFace(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// Helper: process a NV2A method+value pair to update tracked render state
// Forward references for the pixel-shader constant shadow (defined further
// below); ProcessNV2AMethod writes into these when it sees
// NV097_SET_COMBINER_FACTOR0/1 methods emitted by the game's inlined
// D3DDevice_SetPixelShaderConstant.
extern float    g_pshConstants[16][4];
extern uint32_t g_pshConstantsDirty;
static void ProcessNV2AMethod(uint32_t method, uint32_t value) {
    switch (method) {
        case NV2A_SET_ALPHA_TEST_ENABLE: g_alphaTestEnabled  = (value != 0); break;
        case NV2A_SET_BLEND_ENABLE:      g_alphaBlendEnabled = (value != 0); break;
        case NV2A_SET_ALPHA_FUNC:        g_alphaFunc = value; break;
        case NV2A_SET_ALPHA_REF:         g_alphaRef  = value; break;
        case NV2A_SET_BLEND_FUNC_SRC:    g_blendSrc  = value; break;
        case NV2A_SET_BLEND_FUNC_DST:    g_blendDst  = value; break;
        default: break;
    }
    // NV097_SET_COMBINER_FACTOR0(i) (0x1A60..0x1A7C) -> psC[ 0.. 7]  (C0 bank)
    // NV097_SET_COMBINER_FACTOR1(i) (0x1A80..0x1A9C) -> psC[ 8..15]  (C1 bank)
    // Xbox D3D SDK inlines D3DDevice_SetPixelShaderConstant so our
    // function-level hook never fires for it. The inlined code writes
    // straight to these NV2A methods via SetRenderState_Simple/NotInline.
    // Value is 0xAARRGGBB (D3DCOLOR); unpack to float4(r,g,b,a).
    if (method >= 0x1A60 && method < 0x1AA0 && (method & 3) == 0) {
        uint32_t slot = (method - 0x1A60) >> 2; // 0..15 (C0 0..7, then C1 0..7)
        if (slot < 16) {
            g_pshConstants[slot][0] = ((value >> 16) & 0xFF) / 255.0f; // R
            g_pshConstants[slot][1] = ((value >>  8) & 0xFF) / 255.0f; // G
            g_pshConstants[slot][2] = ((value >>  0) & 0xFF) / 255.0f; // B
            g_pshConstants[slot][3] = ((value >> 24) & 0xFF) / 255.0f; // A
            g_pshConstantsDirty |= (1u << slot);
            static int s_logCount = 0;
            if (s_logCount < 16) {
                fprintf(stderr,
                    "[PSH] combiner factor slot=%u (method=0x%04X) value=0x%08X\n",
                    slot, method, value);
                ++s_logCount;
            }
        }
    }
}

// D3DDevice_SetRenderState_Simple  (0x97DA0) — __fastcall: ECX=Method, EDX=Value
void D3DDevice_SetRenderState_Simple(X86Context& ctx, uint8_t* base)
{
    ProcessNV2AMethod(ctx.ecx, ctx.edx);
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetRenderStateNotInline  (0x355390) — 2 args (stateIndex, value), ret 8
// Replaces the recompiled function that looks up NV2A method from table.
//
// Helper that can be called directly from other HLE code (e.g.
// __rwXbFlushCacheBuffer) without having to push args onto the guest stack.
static void HLE_SetRenderStateNotInline(uint8_t* base, uint32_t stateIndex, uint32_t value)
{
    if (stateIndex < kRWStateMethodCount) {
        uint32_t method = X86_MEM_READ_u32(base, kRWStateMethodTable + stateIndex * 4);
        ProcessNV2AMethod(method, value);
    }
    if (stateIndex < kHLERenderStateCount)
        g_hleRenderStateCache[stateIndex] = value;
}

void D3DDevice_SetRenderStateNotInline(X86Context& ctx, uint8_t* base)
{
    uint32_t stateIndex = GuestArg32(ctx, base, 0);
    uint32_t value      = GuestArg32(ctx, base, 1);

    HLE_SetRenderStateNotInline(base, stateIndex, value);

    GuestStackCleanup(ctx, 8);
}

// ============================================================================
// Texture stage state
// ============================================================================

// D3DDevice_SetTextureState_TexCoordIndex  (0x98610) — 2 args, ret 8
void D3DDevice_SetTextureState_TexCoordIndex(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SetTextureState_BumpEnv  (0x98720) — 3 args, ret 12
void D3DDevice_SetTextureState_BumpEnv(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 12);
}

// D3DDevice_SetTextureState_BorderColor  (0x98790) — 2 args, ret 8
void D3DDevice_SetTextureState_BorderColor(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SetTextureState_ColorKeyColor  (0x987D0) — 2 args, ret 8
void D3DDevice_SetTextureState_ColorKeyColor(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SetTextureStageStateNotInline  (0x355610) — 3 args, ret 12
//
// Helper callable directly from other HLE code (e.g. __rwXbFlushCacheBuffer).
static void HLE_SetTextureStageStateNotInline(uint8_t* /*base*/, uint32_t stage,
                                              uint32_t state, uint32_t value)
{
    {
        static int s_tssLog = 0;
        if (s_tssLog < 60)
            fprintf(stderr, "[TSS] stage=%u state=%u value=%u\n", stage, state, value);
        s_tssLog++;
    }

    // Track combiner state for stage 0 in globals
    if (stage == 0) {
        if (state == D3DTSS_COLOROP)   g_colorOp   = value;
        if (state == D3DTSS_COLORARG1) g_colorArg1  = value;
        if (state == D3DTSS_COLORARG2) g_colorArg2  = value;
    }

    // Only update D3D TSS cache for sampler states (< 12).
    // States >= 12 are combiner ops: the original code programs NV2A directly
    // and does NOT write to the cache. Writing to it would short-circuit
    // future RW flush comparisons (pending vs cache) and suppress state changes.
    if (stage < 4 && state < 12)
        g_hleTSSCache[stage][state] = value;
}

void D3DDevice_SetTextureStageStateNotInline(X86Context& ctx, uint8_t* base)
{
    uint32_t stage = GuestArg32(ctx, base, 0);
    uint32_t state = GuestArg32(ctx, base, 1);
    uint32_t value = GuestArg32(ctx, base, 2);

    HLE_SetTextureStageStateNotInline(base, stage, state, value);

    GuestStackCleanup(ctx, 12);
}

// ============================================================================
// Multi-sample, debug
// ============================================================================

// D3D_CommonSetDebugRegisters  (0x98BC0) — 0 args, plain ret
void D3D_CommonSetDebugRegisters(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3D_CommonSetMultiSampleModeAndScale  (0xD5990) — 1 arg, ret 4 in Quake 2 build
void D3D_CommonSetMultiSampleModeAndScale(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Vertex buffer, palette
// ============================================================================

// D3DDevice_CreateVertexBuffer2  (0x99480) — 1 arg, ret 4
void D3DDevice_CreateVertexBuffer2(X86Context& ctx, uint8_t* base)
{
    uint32_t length = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[HLE] D3DDevice_CreateVertexBuffer2(length=%u)\n", length);

    uint32_t vbAddr = ContigAlloc(12, 64);
    uint32_t dataBuf = ContigAlloc(length, 64);
    memset(base + dataBuf, 0, length);

    X86_MEM_WRITE_u32(base, vbAddr + 0,
                      1 | X_D3DCOMMON_TYPE_VERTEXBUFFER | X_D3DCOMMON_D3DCREATED);
    X86_MEM_WRITE_u32(base, vbAddr + 4, dataBuf);
    X86_MEM_WRITE_u32(base, vbAddr + 8, 0);

    GuestReturn32(ctx, vbAddr);
    GuestStackCleanup(ctx, 4);
}

// D3DVertexBuffer_Lock2  (0x994D0) — 2 args, ret 8
void D3DVertexBuffer_Lock2(X86Context& ctx, uint8_t* base)
{
    uint32_t pVB = GuestArg32(ctx, base, 0);
    uint32_t dataAddr = 0;
    if (pVB != 0)
        dataAddr = X86_MEM_READ_u32(base, pVB + 4);
    GuestReturn32(ctx, dataAddr);
    GuestStackCleanup(ctx, 8);
}

// D3DPalette_Lock2  (0x99520) — 2 args, ret 8
void D3DPalette_Lock2(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t dataAddr = 0;
    if (pThis != 0)
        dataAddr = X86_MEM_READ_u32(base, pThis + 4);
    GuestReturn32(ctx, dataAddr);
    GuestStackCleanup(ctx, 8);
}

// D3DPalette_GetSize  (0x99540) — 1 arg, ret 4
void D3DPalette_GetSize(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, X_D3DPALETTE_256);
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Software rasterizer
// ============================================================================

struct SWVertex {
    float x, y, z, w;
    uint32_t diffuse;
    float u, v; // texcoord0
};

// Xbox D3D primitive types
static constexpr int X_D3DPT_POINTLIST      = 1;
static constexpr int X_D3DPT_LINELIST       = 2;
static constexpr int X_D3DPT_LINESTRIP      = 3;
static constexpr int X_D3DPT_TRIANGLELIST   = 4;
static constexpr int X_D3DPT_TRIANGLESTRIP  = 5;
static constexpr int X_D3DPT_TRIANGLEFAN    = 6;
static constexpr int X_D3DPT_QUADLIST       = 13;
static constexpr int X_D3DPT_QUADSTRIP      = 14;

// Xbox vertex attribute register indices (for Begin/End immediate mode)
static constexpr int X_D3DVSDE_POSITION  = 0;
static constexpr int X_D3DVSDE_DIFFUSE   = 3;
static constexpr int X_D3DVSDE_SPECULAR  = 4;
static constexpr int X_D3DVSDE_TEXCOORD0 = 9;
static constexpr int X_D3DVSDE_TEXCOORD1 = 10;
static constexpr uint32_t X_D3DVSDE_VERTEX = 0xFFFFFFFF; // -1, triggers vertex emission with position+UV

// Immediate-mode state
static int        g_imPrimType = 0;
static std::vector<SWVertex> g_imVertices;
static SWVertex   g_imCurrent = {};
static bool       g_imActive  = false;

// Current FVF for DrawVertices
static uint32_t   g_currentFVF = 0;

// Last SetVertexShader handle (programmable shaders have bit 0 set). Used by
// DrawVertices / DrawIndexedVertices to route through the 3D pipeline.
static uint32_t   g_currentVSHandle = 0;

// NV2A vertex shader constant registers (c[0]..c[191]). The recompiled
// SetVertexShaderConstant* entry points snapshot uploads into this array so
// the 3D pipeline can upload them as a DX11 cbuffer at draw time. Also
// mirrored into the Xbox guest shadow at 0x35FDF8 (+ reg*16) so any guest
// code reading it back still works.
static float      g_vshConstants[192][4] = {};

// NV2A pixel shader constant registers.
// D3DDevice_SetPixelShaderConstant (LTCG: ECX=Register, EAX=Count, stack0=pData)
// captures uploads here so the HLE can forward them to the D3D11 pixel shader
// via the PSConstants cbuffer bound at slot b0.
//
// Layout mirrors the Xbox render state bank: slots [0..7] map to
// X_D3DRS_PSCONSTANT0_0..7 (the "C0" bank, used by combiner c0 per stage
// via PSC0Mapping), and slots [8..15] map to X_D3DRS_PSCONSTANT1_0..7
// (the "C1" bank, used by combiner c1 per stage via PSC1Mapping).  Values
// are stored as D3DXCOLOR float4 (r, g, b, a), matching what the game
// passes to SetPixelShaderConstant.
float      g_pshConstants[16][4] = {};
// Bit i = the game has explicitly uploaded slot i via
// D3DDevice_SetPixelShaderConstant at least once.  Used to decide whether
// a newly-created PS can seed its baked PSConstant defaults into a given
// slot without clobbering a runtime upload from the game.
uint32_t   g_pshConstantsDirty   = 0;

// Xbox guest-memory shadow of all vertex-shader constants (game may read back
// from here). 192 × float4 = 3072 bytes starting at this address.
static constexpr uint32_t kVshConstantShadow = 0x35FDF8;

// ----------------------------------------------------------------------------
// NV2A push-buffer walker
//
// The Xbox D3D SDK inlines the "Fast" SetVertexShaderConstant* helpers, so
// our function-table HLE intercepts only the non-inlined paths. The vast
// majority of constant uploads (especially from RenderWare) bypass our hooks
// and write directly into the NV2A push buffer at [push_base, 0x35D6A4),
// where 0x35D6A0 holds the current write pointer ("put").
//
// To recover those uploads we periodically walk the push buffer between
// our last-observed put and the current put, decoding NV2A method headers
// and applying any state we care about (currently: vertex-shader constants).
//
// Header format (little-endian DWORD):
//   bits  2..12  method address (DWORD-aligned NV2A reg)
//   bits 13..15  subchannel
//   bits 18..28  count of payload DWORDs that follow
//   bits 29..31  instr type (0 = method, 1 = jmp_near, 2 = no-incr, ...)
//
// Wraparound: if put wraps, we don't know the buffer base, so we just snap
// to the new put and lose those frames' uploads. Constants are uploaded
// every frame in practice, so this is harmless.
// ----------------------------------------------------------------------------
static uint32_t s_pbLastWalked = 0;
static uint64_t s_pbWalkStats_methods = 0;
static uint64_t s_pbWalkStats_consts  = 0;

// Guest-memory ring buffer that backs the NV2A push channel. The inline
// SetVertexShaderConstant*, SetRenderState_Simple, etc., all read the
// current "put" pointer from [0x35D6A0] and the "limit" from [0x35D6A4];
// if advancing past the limit they call D3DDevice_MakeSpace to obtain
// more room. The original SDK driver page-maps a real NV2A ring; we just
// allocate a large guest buffer and reset it whenever MakeSpace is
// invoked (draining any pending commands through our walker first).
static uint32_t g_pbGuestBase = 0;
static uint32_t g_pbGuestSize = 0;

static void EnsurePushBuffer(uint8_t* base) {
    if (g_pbGuestBase) return;
    g_pbGuestSize = 0x00800000; // 8 MiB
    g_pbGuestBase = ContigAlloc(g_pbGuestSize, 4096);
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    X86_MEM_WRITE_u32(base, 0x35D6A4u, g_pbGuestBase + g_pbGuestSize);
    s_pbLastWalked = g_pbGuestBase;
    fprintf(stderr, "[PB] ring allocated base=0x%08X size=0x%X\n",
            g_pbGuestBase, g_pbGuestSize);
}

static inline void NV2A_UploadConst(uint8_t* base, uint32_t slot, const uint8_t* src) {
    if (slot >= 192) return;
    static bool s_seen[192] = {};
    if (!s_seen[slot]) {
        s_seen[slot] = true;
        const float* f = reinterpret_cast<const float*>(src);
        fprintf(stderr, "[PB] first c[%u] = [%.3f %.3f %.3f %.3f]\n",
                slot, f[0], f[1], f[2], f[3]);
    }
    memcpy(g_vshConstants[slot], src, 16);
    memcpy(base + kVshConstantShadow + slot * 16, src, 16);
    s_pbWalkStats_consts++;
}

// ---- NV2A texture state shadowed from the push buffer --------------------
struct NV2ATextureState {
    uint32_t offset    = 0;   // NV097_SET_TEXTURE_OFFSET  — raw GPU addr
    uint32_t format    = 0;   // context dma + color + logU/V/P + mips + dim
    uint32_t address   = 0;   // wrap modes
    uint32_t control0  = 0;
    uint32_t control1  = 0;   // pitch (bits 16..31)
    uint32_t imageRect = 0;   // (width-1 << 16) | (height-1)
    uint32_t palette   = 0;
    bool     dirty     = false;
};
static NV2ATextureState g_nv2aTexture[4];

static void WalkPushBuffer(uint8_t* base) {
    uint32_t pbPut = X86_MEM_READ_u32(base, 0x35D6A0);
    static int s_probe = 0;
    if (s_probe < 20) {
        fprintf(stderr, "[PB] walk: put=0x%08X last=0x%08X\n", pbPut, s_pbLastWalked);
        s_probe++;
    }
    if (s_pbLastWalked == 0) { s_pbLastWalked = pbPut; return; }
    if (pbPut == s_pbLastWalked) return;
    if (pbPut <  s_pbLastWalked) { s_pbLastWalked = pbPut; return; } // wrap

    uint32_t p = s_pbLastWalked;
    uint32_t end = pbPut;
    uint32_t curConstAddr = 0;

    static int s_hdrProbe = 0;
    while (p + 4 <= end) {
        uint32_t hdr = X86_MEM_READ_u32(base, p);
        if (s_hdrProbe < 30) {
            fprintf(stderr, "[PB]   @0x%08X hdr=0x%08X method=0x%04X count=%u instr=%u\n",
                    p, hdr, (hdr & 0x1FFC), (hdr >> 18) & 0x7FF, (hdr >> 29) & 7);
            s_hdrProbe++;
        }
        p += 4;

        uint32_t instr  = (hdr >> 29) & 0x7;
        uint32_t count  = (hdr >> 18) & 0x7FF;
        // uint32_t sub = (hdr >> 13) & 0x7;
        uint32_t method = (hdr & 0x1FFC); // bits 2..12

        // Skip jmp/call (not used by SDK fast paths but be safe).
        if (instr == 1 /*JMP_NEAR*/ || instr == 2 /*CALL_FAR*/) continue;

        if (count == 0) continue;
        if (p + count * 4 > end) break;

        s_pbWalkStats_methods++;

        switch (method) {
        case 0x1EA4: // NV2A_VP_UPLOAD_CONST_ID — 1 DWORD = constant slot
            curConstAddr = X86_MEM_READ_u32(base, p);
            break;
        case 0x0B80: // NV2A_VP_UPLOAD_CONST(0) — N*4 DWORDs of float4s,
                     // auto-incrementing curConstAddr.
            for (uint32_t i = 0; i + 4 <= count; i += 4) {
                NV2A_UploadConst(base, curConstAddr,
                                 base + p + i * 4);
                curConstAddr++;
            }
            break;
        default: {
            // NV097_SET_COMBINER_FACTOR0/1 (0x1A60..0x1A9C): 16 D3DCOLOR
            // pixel-shader constant slots (C0 bank at 0x1A60+i*4, C1 bank
            // at 0x1A80+i*4).  Burnout 3's inlined SetPixelShaderConstant
            // drops straight into the push-buffer so this is the only
            // reliable capture point.
            if (method >= 0x1A60 && method < 0x1AA0 && (method & 3) == 0) {
                uint32_t baseSlot = (method - 0x1A60) >> 2; // 0..15
                for (uint32_t i = 0; i < count; i++) {
                    uint32_t slot = baseSlot + i;
                    if (slot >= 16) break;
                    uint32_t v = X86_MEM_READ_u32(base, p + i * 4);
                    g_pshConstants[slot][0] = ((v >> 16) & 0xFF) / 255.0f;
                    g_pshConstants[slot][1] = ((v >>  8) & 0xFF) / 255.0f;
                    g_pshConstants[slot][2] = ((v >>  0) & 0xFF) / 255.0f;
                    g_pshConstants[slot][3] = ((v >> 24) & 0xFF) / 255.0f;
                    g_pshConstantsDirty |= (1u << slot);
                }
                static int s_fcLog = 0;
                if (s_fcLog < 16) {
                    uint32_t v0 = X86_MEM_READ_u32(base, p);
                    fprintf(stderr,
                        "[PB] combiner factor method=0x%04X count=%u baseSlot=%u v0=0x%08X\n",
                        method, count, baseSlot, v0);
                    ++s_fcLog;
                }
                break;
            }
            // NV097 texture setup methods, per-stage (stride 0x40).
            //   0x1B00 SET_TEXTURE_OFFSET
            //   0x1B04 SET_TEXTURE_FORMAT     (context DMA + format code + logU/V/P + mips)
            //   0x1B08 SET_TEXTURE_ADDRESS    (wrap modes)
            //   0x1B0C SET_TEXTURE_CONTROL0   (enable + lod)
            //   0x1B10 SET_TEXTURE_CONTROL1   (pitch)
            //   0x1B1C SET_TEXTURE_IMAGE_RECT (width<<16 | height)
            //   0x1B20 SET_TEXTURE_PALETTE
            // RenderWare in Burnout 3 writes these directly into the push
            // buffer instead of going through D3DDevice_SetTexture, so we
            // shadow them here for the 3D draw path to consult.
            if (method >= 0x1B00 && method < 0x1B00 + 4 * 0x40) {
                uint32_t rel   = method - 0x1B00;
                uint32_t stage = rel / 0x40;
                uint32_t sub   = rel % 0x40;
                if (stage < 4) {
                    // Walk the count DWORDs, interpreting consecutive method
                    // addresses (NV2A auto-increments by 4 on non-terminal
                    // instr types but we treat each as absolute here).
                    for (uint32_t i = 0; i < count; i++) {
                        uint32_t val = X86_MEM_READ_u32(base, p + i * 4);
                        uint32_t s   = sub + i * 4;
                        switch (s) {
                        case 0x00: g_nv2aTexture[stage].offset    = val; g_nv2aTexture[stage].dirty = true; break;
                        case 0x04: g_nv2aTexture[stage].format    = val; g_nv2aTexture[stage].dirty = true; break;
                        case 0x08: g_nv2aTexture[stage].address   = val; break;
                        case 0x0C: g_nv2aTexture[stage].control0  = val; break;
                        case 0x10: g_nv2aTexture[stage].control1  = val; break;
                        case 0x1C: g_nv2aTexture[stage].imageRect = val; g_nv2aTexture[stage].dirty = true; break;
                        case 0x20: g_nv2aTexture[stage].palette   = val; break;
                        default: break;
                        }
                    }
                }
            }
            break;
        }
        }

        p += count * 4;
    }

    s_pbLastWalked = pbPut;
}

// Forward decl: programmable-VS 3D draw path (defined near HLE_DrawBatch2D).
static void HLE_Draw3D(uint8_t* base,
                       uint32_t primType,
                       uint32_t startVertex,
                       uint32_t vertexCount,
                       uint32_t indexCount,
                       uint32_t pIndexData);

// Returns true if ANY vertex-shader constant slot has been populated with
// finite non-zero data. Different shaders in Burnout 3 upload their MVP to
// different slots (e.g. 0xFFFE0005 uses c[116..119], not c[112..115]),
// so a narrow window here would gate off most real 3D traffic. Until we
// have per-shader HLSL translation, we let the 3D path run whenever the
// guest has uploaded anything meaningful — expect mis-transformed
// geometry, but at least geometry reaches the rasterizer.
static bool HasMvpConstants(uint8_t* base) {
    for (uint32_t r = 0; r < 192; r++) {
        const float* hs = g_vshConstants[r];
        const float* sh = reinterpret_cast<const float*>(
            base + kVshConstantShadow + r * 16);
        for (int k = 0; k < 4; k++) {
            if (std::isfinite(hs[k]) && hs[k] != 0.0f) return true;
            if (std::isfinite(sh[k]) && sh[k] != 0.0f) return true;
        }
    }
    return false;
}

// Read the currently bound vertex-shader handle from the game's live CDevice
// struct. The game's SDK passthrough/state helpers (D3D_CommonSetPassthrough-
// Program, D3D_LazySet*) write directly into CDevice without calling our
// D3DDevice_SetVertexShader hook, so tracking just that call misses those
// transitions. v5 used the same pattern.
//   *(uint32_t*)(base + 0x35FB48u)     = CDevice pointer (virtual addr)
//   *(uint32_t*)(CDevice + 0x798)      = current VS handle
static uint32_t LiveVSHandle(uint8_t* base) {
    uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
    if (cdev == 0) return g_currentVSHandle;
    cdev &= 0x3FFFFFFFu;
    uint32_t h = X86_MEM_READ_u32(base, cdev + 0x798u);
    return h ? h : g_currentVSHandle;
}

// D3DFVF bits
static constexpr uint32_t D3DFVF_XYZ       = 0x002;
static constexpr uint32_t D3DFVF_XYZRHW    = 0x004;
static constexpr uint32_t D3DFVF_NORMAL    = 0x010;
static constexpr uint32_t D3DFVF_DIFFUSE   = 0x040;
static constexpr uint32_t D3DFVF_SPECULAR  = 0x080;
static constexpr uint32_t D3DFVF_TEXCOUNT_MASK  = 0xF00;
static constexpr uint32_t D3DFVF_TEXCOUNT_SHIFT = 8;

static uint32_t FVFVertexSize(uint32_t fvf)
{
    uint32_t size = 0;
    if (fvf & D3DFVF_XYZRHW)   size += 16; // x,y,z,rhw
    else if (fvf & D3DFVF_XYZ) size += 12; // x,y,z
    if (fvf & D3DFVF_NORMAL)   size += 12;
    if (fvf & D3DFVF_DIFFUSE)  size += 4;
    if (fvf & D3DFVF_SPECULAR) size += 4;
    uint32_t texCount = (fvf & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;
    size += texCount * 8; // 2 floats per texcoord
    return size;
}

// Read back-buffer pointer and dimensions
struct RenderTarget {
    uint32_t* pixels;
    uint32_t  w, h;
    // Scissor clip rect (pixel bounds, inclusive)
    int clipLeft, clipTop, clipRight, clipBottom;
};

static bool GetRT(uint8_t* base, RenderTarget& rt)
{
    uint32_t rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
    if (rtAddr == 0)
        rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);
    if (rtAddr == 0) return false;

    uint32_t dataAddr = X86_MEM_READ_u32(base, rtAddr + 4);
    if (dataAddr == 0) return false;

    rt.pixels = reinterpret_cast<uint32_t*>(base + dataAddr);
    rt.w = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
    rt.h = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
    if (rt.w == 0 || rt.h == 0) { rt.w = 640; rt.h = 480; }

    // Default clip to full render target
    rt.clipLeft   = 0;
    rt.clipTop    = 0;
    rt.clipRight  = (int)rt.w - 1;
    rt.clipBottom = (int)rt.h - 1;

    // Apply scissor rect if enabled
    uint32_t scissorEnabled = X86_MEM_READ_u32(base, kDeviceAddr + 0x0D00);
    if (scissorEnabled) {
        int sL = (int)X86_MEM_READ_u32(base, kDeviceAddr + 0x0D04);
        int sT = (int)X86_MEM_READ_u32(base, kDeviceAddr + 0x0D08);
        int sR = (int)X86_MEM_READ_u32(base, kDeviceAddr + 0x0D0C) - 1; // D3DRECT right is exclusive
        int sB = (int)X86_MEM_READ_u32(base, kDeviceAddr + 0x0D10) - 1; // D3DRECT bottom is exclusive
        rt.clipLeft   = std::max(rt.clipLeft, sL);
        rt.clipTop    = std::max(rt.clipTop, sT);
        rt.clipRight  = std::min(rt.clipRight, sR);
        rt.clipBottom = std::min(rt.clipBottom, sB);
    }

    return true;
}

// Sample texture at (u,v), nearest-neighbor.  Returns A8R8G8B8.
// Xbox GPU swizzle: convert linear (x,y) to swizzled byte offset for power-of-2 textures
static uint32_t XboxSwizzleOffset(uint32_t x, uint32_t y, uint32_t logW, uint32_t logH)
{
    uint32_t offset = 0;
    uint32_t shift = 0;
    uint32_t minLog = std::min(logW, logH);

    // Phase 1: Interleave bits of x and y up to the smaller dimension
    for (uint32_t i = 0; i < minLog; i++) {
        offset |= ((x >> i) & 1) << shift++;
        offset |= ((y >> i) & 1) << shift++;
    }
    // Phase 2: Remaining bits from the larger dimension
    if (logW > logH) {
        for (uint32_t i = minLog; i < logW; i++)
            offset |= ((x >> i) & 1) << shift++;
    } else {
        for (uint32_t i = minLog; i < logH; i++)
            offset |= ((y >> i) & 1) << shift++;
    }
    return offset;
}

// Returns bytes-per-pixel for known formats (0 = unsupported)
static uint32_t FormatBPP(uint32_t fmt)
{
    switch (fmt) {
    case X_D3DFMT_A8R8G8B8:     return 4;
    case X_D3DFMT_X8R8G8B8:     return 4;
    case X_D3DFMT_LIN_A8R8G8B8: return 4;
    case X_D3DFMT_LIN_X8R8G8B8: return 4;
    case X_D3DFMT_R5G6B5:       return 2;
    case X_D3DFMT_A1R5G5B5:     return 2;
    case X_D3DFMT_A4R4G4B4:     return 2;
    default: return 4; // fallback
    }
}

// Read a raw pixel at (tx,ty) from texture data, handling format + swizzle
static uint32_t ReadTexel(uint8_t* base, uint32_t dataAddr, uint32_t tx, uint32_t ty,
                          uint32_t texW, uint32_t texH, uint32_t fmt, bool swizzled)
{
    uint32_t bpp = FormatBPP(fmt);
    uint32_t pixelOffset;

    if (swizzled) {
        uint32_t logW = 0, logH = 0;
        for (uint32_t t = texW; t > 1; t >>= 1) logW++;
        for (uint32_t t = texH; t > 1; t >>= 1) logH++;
        pixelOffset = XboxSwizzleOffset(tx, ty, logW, logH);
    } else {
        pixelOffset = ty * texW + tx;
    }

    uint32_t byteOffset = pixelOffset * bpp;
    uint32_t pixel = 0;

    switch (fmt) {
    case X_D3DFMT_A4R4G4B4: {
        uint16_t raw = *reinterpret_cast<uint16_t*>(base + dataAddr + byteOffset);
        uint32_t a = ((raw >> 12) & 0xF) * 17;  // 4-bit → 8-bit (0xF → 0xFF)
        uint32_t r = ((raw >> 8)  & 0xF) * 17;
        uint32_t g = ((raw >> 4)  & 0xF) * 17;
        uint32_t b = ((raw >> 0)  & 0xF) * 17;
        pixel = (a << 24) | (r << 16) | (g << 8) | b;
        break;
    }
    case X_D3DFMT_A1R5G5B5: {
        uint16_t raw = *reinterpret_cast<uint16_t*>(base + dataAddr + byteOffset);
        uint32_t a = (raw & 0x8000) ? 255 : 0;
        uint32_t r = ((raw >> 10) & 0x1F) * 255 / 31;
        uint32_t g = ((raw >> 5)  & 0x1F) * 255 / 31;
        uint32_t b = ((raw >> 0)  & 0x1F) * 255 / 31;
        pixel = (a << 24) | (r << 16) | (g << 8) | b;
        break;
    }
    case X_D3DFMT_R5G6B5: {
        uint16_t raw = *reinterpret_cast<uint16_t*>(base + dataAddr + byteOffset);
        uint32_t r = ((raw >> 11) & 0x1F) * 255 / 31;
        uint32_t g = ((raw >> 5)  & 0x3F) * 255 / 63;
        uint32_t b = ((raw >> 0)  & 0x1F) * 255 / 31;
        pixel = 0xFF000000 | (r << 16) | (g << 8) | b;
        break;
    }
    case X_D3DFMT_X8R8G8B8:
    case X_D3DFMT_LIN_X8R8G8B8:
        pixel = *reinterpret_cast<uint32_t*>(base + dataAddr + byteOffset);
        pixel |= 0xFF000000; // force opaque
        break;
    default: // A8R8G8B8, LIN_A8R8G8B8, etc.
        pixel = *reinterpret_cast<uint32_t*>(base + dataAddr + byteOffset);
        break;
    }
    return pixel;
}

// Cached texture info — read once per draw, used per pixel
struct TexCache {
    uint32_t dataAddr;
    uint32_t texW, texH;
    uint32_t fmt;
    bool swizzled;
    bool valid;
};

static TexCache CacheTexture(uint8_t* base, uint32_t texAddr)
{
    TexCache tc = {};
    tc.valid = false;
    if (texAddr == 0) return tc;

    tc.dataAddr = X86_MEM_READ_u32(base, texAddr + 4);
    if (tc.dataAddr == 0) return tc;

    uint32_t fmtField  = X86_MEM_READ_u32(base, texAddr + 12);
    uint32_t sizeField = X86_MEM_READ_u32(base, texAddr + 16);
    tc.fmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

    if (sizeField != 0) {
        tc.texW = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        tc.texH = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
        tc.swizzled = false;
    } else {
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        tc.texW = 1u << logU;
        tc.texH = 1u << logV;
        tc.swizzled = (tc.fmt != X_D3DFMT_LIN_A8R8G8B8 && tc.fmt != X_D3DFMT_LIN_X8R8G8B8);
    }
    tc.valid = (tc.texW > 0 && tc.texH > 0);
    return tc;
}

static inline uint32_t SampleTexCached(uint8_t* base, const TexCache& tc, float su, float sv)
{
    if (!tc.valid) return 0xFFFFFFFF;

    if (su > 1.0f || su < -1.0f || sv > 1.0f || sv < -1.0f) {
        su /= (float)tc.texW;
        sv /= (float)tc.texH;
    }
    su = su - floorf(su);
    sv = sv - floorf(sv);

    uint32_t tx = std::min((uint32_t)(su * tc.texW), tc.texW - 1);
    uint32_t ty = std::min((uint32_t)(sv * tc.texH), tc.texH - 1);

    return ReadTexel(base, tc.dataAddr, tx, ty, tc.texW, tc.texH, tc.fmt, tc.swizzled);
}

static uint32_t SampleTex(uint8_t* base, uint32_t texAddr, float su, float sv)
{
    TexCache tc = CacheTexture(base, texAddr);
    return SampleTexCached(base, tc, su, sv);
}

// Alpha-blend src over dst (both A8R8G8B8)
static uint32_t AlphaBlend(uint32_t src, uint32_t dst)
{
    uint32_t sa = (src >> 24) & 0xFF;
    if (sa == 255) return src;
    if (sa == 0) return dst;

    uint32_t inv = 255 - sa;
    uint32_t r = (((src >> 16) & 0xFF) * sa + ((dst >> 16) & 0xFF) * inv + 127) / 255;
    uint32_t g = (((src >> 8) & 0xFF)  * sa + ((dst >> 8) & 0xFF)  * inv + 127) / 255;
    uint32_t b = ((src & 0xFF) * sa + (dst & 0xFF) * inv + 127) / 255;
    uint32_t a = std::min(255u, sa + (((dst >> 24) & 0xFF) * inv + 127) / 255);
    return (a << 24) | (r << 16) | (g << 8) | b;
}

// Modulate two A8R8G8B8 colors (multiply per-channel)
static uint32_t Modulate(uint32_t c1, uint32_t c2)
{
    uint32_t a = (((c1 >> 24) & 0xFF) * ((c2 >> 24) & 0xFF) + 127) / 255;
    uint32_t r = (((c1 >> 16) & 0xFF) * ((c2 >> 16) & 0xFF) + 127) / 255;
    uint32_t g = (((c1 >> 8) & 0xFF)  * ((c2 >> 8) & 0xFF)  + 127) / 255;
    uint32_t b = ((c1 & 0xFF) * (c2 & 0xFF) + 127) / 255;
    return (a << 24) | (r << 16) | (g << 8) | b;
}

// Rasterize a single triangle (screen-space coordinates) into the render target
static void RasterTri(uint8_t* base, const SWVertex& v0, const SWVertex& v1,
                      const SWVertex& v2, const RenderTarget& rt)
{
    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00); // stage 0
    TexCache tc = CacheTexture(base, texAddr);

    int minX = std::max(rt.clipLeft, (int)floorf(std::min({v0.x, v1.x, v2.x})));
    int maxX = std::min(rt.clipRight, (int)ceilf(std::max({v0.x, v1.x, v2.x})));
    int minY = std::max(rt.clipTop, (int)floorf(std::min({v0.y, v1.y, v2.y})));
    int maxY = std::min(rt.clipBottom, (int)ceilf(std::max({v0.y, v1.y, v2.y})));

    float denom = (v1.y - v2.y) * (v0.x - v2.x) + (v2.x - v1.x) * (v0.y - v2.y);
    if (fabsf(denom) < 0.001f) return;
    float invD = 1.0f / denom;

    bool uniformDiffuse = (v0.diffuse == v1.diffuse && v1.diffuse == v2.diffuse);
    bool opaqueWhite = (v0.diffuse == 0xFFFFFFFF);

    for (int py = minY; py <= maxY; py++) {
        float fy = (float)py + 0.5f;
        uint32_t rowOff = (uint32_t)py * rt.w;
        for (int px = minX; px <= maxX; px++) {
            float fx = (float)px + 0.5f;

            float w0 = ((v1.y - v2.y) * (fx - v2.x) + (v2.x - v1.x) * (fy - v2.y)) * invD;
            float w1 = ((v2.y - v0.y) * (fx - v2.x) + (v0.x - v2.x) * (fy - v2.y)) * invD;
            float w2 = 1.0f - w0 - w1;
            constexpr float kEdgeEps = -1.0f / 512.0f;
            if (w0 < kEdgeEps || w1 < kEdgeEps || w2 < kEdgeEps) continue;

            // Interpolate texcoords
            float tu = w0 * v0.u + w1 * v1.u + w2 * v2.u;
            float tv = w0 * v0.v + w1 * v1.v + w2 * v2.v;

            uint32_t texCol = SampleTexCached(base, tc, tu, tv);

            uint32_t final_col;
            if (opaqueWhite) {
                final_col = texCol;
            } else if (uniformDiffuse) {
                final_col = Modulate(texCol, v0.diffuse);
            } else {
                auto lch = [&](int sh) -> uint8_t {
                    float val = w0 * ((v0.diffuse >> sh) & 0xFF)
                              + w1 * ((v1.diffuse >> sh) & 0xFF)
                              + w2 * ((v2.diffuse >> sh) & 0xFF);
                    return (uint8_t)std::clamp(val, 0.0f, 255.0f);
                };
                uint32_t vtxCol = ((uint32_t)lch(24) << 24) | ((uint32_t)lch(16) << 16)
                                | ((uint32_t)lch(8) << 8)   | lch(0);
                final_col = Modulate(texCol, vtxCol);
            }

            uint32_t idx = rowOff + (uint32_t)px;
            uint32_t sa = (final_col >> 24) & 0xFF;
            if (sa == 255)
                rt.pixels[idx] = final_col;
            else if (sa > 0)
                rt.pixels[idx] = AlphaBlend(final_col, rt.pixels[idx]);
        }
    }
}

// Rasterize an axis-aligned rectangle (4 verts: TL, TR, BR, BL) into the render target.
// Uses bilinear parameter interpolation across the rect — no triangle split seams.
static void RasterRect(uint8_t* base, const SWVertex& v0, const SWVertex& v1,
                       const SWVertex& v2, const SWVertex& v3, const RenderTarget& rt)
{
    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    TexCache tc = CacheTexture(base, texAddr);

    // Bounding box of the 4 vertices
    float fminX = std::min({v0.x, v1.x, v2.x, v3.x});
    float fmaxX = std::max({v0.x, v1.x, v2.x, v3.x});
    float fminY = std::min({v0.y, v1.y, v2.y, v3.y});
    float fmaxY = std::max({v0.y, v1.y, v2.y, v3.y});

    int minX = std::max(rt.clipLeft, (int)floorf(fminX));
    int maxX = std::min(rt.clipRight, (int)ceilf(fmaxX));
    int minY = std::max(rt.clipTop, (int)floorf(fminY));
    int maxY = std::min(rt.clipBottom, (int)ceilf(fmaxY));

    float invW = (fmaxX > fminX) ? 1.0f / (fmaxX - fminX) : 0.0f;
    float invH = (fmaxY > fminY) ? 1.0f / (fmaxY - fminY) : 0.0f;

    // Fast path: uniform diffuse (all 4 corners identical)
    bool uniformDiffuse = (v0.diffuse == v1.diffuse && v1.diffuse == v2.diffuse && v2.diffuse == v3.diffuse);
    bool opaqueWhite = (v0.diffuse == 0xFFFFFFFF);

    // Corners: v0=TL, v1=TR, v2=BR, v3=BL
    for (int py = minY; py <= maxY; py++) {
        float fy = (float)py + 0.5f;
        float tv = (fy - fminY) * invH; // 0..1 top to bottom
        uint32_t rowOff = (uint32_t)py * rt.w;

        for (int px = minX; px <= maxX; px++) {
            float fx = (float)px + 0.5f;
            float tu_param = (fx - fminX) * invW; // 0..1 left to right

            // Bilinear interpolation of UV coords
            float uTop    = v0.u + (v1.u - v0.u) * tu_param;
            float uBottom = v3.u + (v2.u - v3.u) * tu_param;
            float finalU  = uTop + (uBottom - uTop) * tv;

            float vTop    = v0.v + (v1.v - v0.v) * tu_param;
            float vBottom = v3.v + (v2.v - v3.v) * tu_param;
            float finalV  = vTop + (vBottom - vTop) * tv;

            uint32_t texCol = SampleTexCached(base, tc, finalU, finalV);

            uint32_t final_col;
            if (opaqueWhite) {
                // Diffuse is white opaque — texCol IS the final color
                final_col = texCol;
            } else if (uniformDiffuse) {
                // Uniform diffuse — modulate once, no interpolation needed
                final_col = Modulate(texCol, v0.diffuse);
            } else {
                // Bilinear interpolation of diffuse color
                auto lerpCh = [&](int sh) -> uint8_t {
                    float cTL = (float)((v0.diffuse >> sh) & 0xFF);
                    float cTR = (float)((v1.diffuse >> sh) & 0xFF);
                    float cBR = (float)((v2.diffuse >> sh) & 0xFF);
                    float cBL = (float)((v3.diffuse >> sh) & 0xFF);
                    float top = cTL + (cTR - cTL) * tu_param;
                    float bot = cBL + (cBR - cBL) * tu_param;
                    return (uint8_t)std::clamp(top + (bot - top) * tv, 0.0f, 255.0f);
                };
                uint32_t vtxCol = ((uint32_t)lerpCh(24) << 24) | ((uint32_t)lerpCh(16) << 16)
                                | ((uint32_t)lerpCh(8) << 8)   | lerpCh(0);
                final_col = Modulate(texCol, vtxCol);
            }

            uint32_t idx = rowOff + (uint32_t)px;
            uint32_t sa = (final_col >> 24) & 0xFF;
            if (sa == 255)
                rt.pixels[idx] = final_col;
            else if (sa > 0)
                rt.pixels[idx] = AlphaBlend(final_col, rt.pixels[idx]);
        }
    }
}

// Forward declaration for D3D11 draw helper defined later in the file
static void DrawSWVertsWithTexD3D11(uint8_t* base, const SWVertex* sv, size_t n, int primType);

// Submit a batch of vertices as the given primitive type
static void SubmitPrims(uint8_t* base, const SWVertex* verts, size_t n, int primType)
{
    DrawSWVertsWithTexD3D11(base, verts, n, primType);
}

// Parse a vertex from a raw byte buffer given FVF
static SWVertex ParseFVFVertex(const uint8_t* p, uint32_t fvf)
{
    SWVertex sv = {};
    sv.diffuse = 0xFFFFFFFF; // default white opaque

    uint32_t off = 0;
    if (fvf & D3DFVF_XYZRHW) {
        memcpy(&sv.x, p + off, 4); off += 4;
        memcpy(&sv.y, p + off, 4); off += 4;
        memcpy(&sv.z, p + off, 4); off += 4;
        memcpy(&sv.w, p + off, 4); off += 4;
    } else if (fvf & D3DFVF_XYZ) {
        memcpy(&sv.x, p + off, 4); off += 4;
        memcpy(&sv.y, p + off, 4); off += 4;
        memcpy(&sv.z, p + off, 4); off += 4;
        sv.w = 1.0f;
    }
    if (fvf & D3DFVF_NORMAL) off += 12; // skip normal
    if (fvf & D3DFVF_DIFFUSE) {
        memcpy(&sv.diffuse, p + off, 4); off += 4;
    }
    if (fvf & D3DFVF_SPECULAR) off += 4; // skip
    uint32_t texCount = (fvf & D3DFVF_TEXCOUNT_MASK) >> D3DFVF_TEXCOUNT_SHIFT;
    if (texCount >= 1) {
        memcpy(&sv.u, p + off, 4); off += 4;
        memcpy(&sv.v, p + off, 4); off += 4;
    }
    return sv;
}

// ============================================================================
// Drawing
// ============================================================================

// D3DDevice_DrawVertices  (0x99550) — 3 args, ret 12
void D3DDevice_DrawVertices(X86Context& ctx, uint8_t* base)
{
    uint32_t primType   = GuestArg32(ctx, base, 0);
    uint32_t startVert  = GuestArg32(ctx, base, 1);
    uint32_t vertCount  = GuestArg32(ctx, base, 2);

    // Read stream 0
    uint32_t vbAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x1660);
    uint32_t stride = X86_MEM_READ_u32(base, kDeviceAddr + 0x1664);

    static int s_drawLog = 0;
    bool shouldLog = false;// (s_drawLog < 80);
    //if (shouldLog) {
    //    s_drawLog++;
    //}
    //// Always log quad draws (logo rendering)
    //if (primType == 8 && vertCount == 4) {
    //    static int s_quadLog = 0;
    //    if (s_quadLog < 40) {
    //        fprintf(stderr, "[HLE] DrawVertices(type=%u, start=%u, count=%u, fvf=0x%X, vb=0x%X, stride=%u)\n",
    //                primType, startVert, vertCount, g_currentFVF, vbAddr, stride);
    //        s_quadLog++;
    //    }
    //}

    if (vbAddr == 0 || stride == 0 || vertCount == 0) {
        if (shouldLog) fprintf(stderr, "  -> skipped: vbAddr=%u stride=%u count=%u\n", vbAddr, stride, vertCount);
        GuestStackCleanup(ctx, 12);
        return;
    }

    // Drain any inline NV2A push-buffer writes (constants etc.) before
    // checking shader-program preconditions.
    WalkPushBuffer(base);

    // Programmable vertex shader path — transform via NV2A constants (3D).
    uint32_t liveVS = LiveVSHandle(base);
    static int s_drawProbe = 0;
    if (s_drawProbe < 20) {
        fprintf(stderr,
            "[HLE] DrawVertices prim=%u start=%u count=%u stride=%u vb=0x%X "
            "liveVS=0x%X tracked=0x%X mvp=%d\n",
            primType, startVert, vertCount, stride, vbAddr,
            liveVS, g_currentVSHandle, (int)HasMvpConstants(base));
        s_drawProbe++;
    }
    if ((liveVS & 1) && g_d3d11.vs3D && HasMvpConstants(base)) {
        static int s_log3D = 0;
        if (s_log3D < 8) {
            // fprintf(stderr,
            //     "[HLE] Draw3D prim=%u start=%u count=%u stride=%u vb=0x%X "
            //     "c112=[%.3f %.3f %.3f %.3f] c115=[%.3f %.3f %.3f %.3f]\n",
            //     primType, startVert, vertCount, stride, vbAddr,
            //     g_vshConstants[112][0], g_vshConstants[112][1],
            //     g_vshConstants[112][2], g_vshConstants[112][3],
            //     g_vshConstants[115][0], g_vshConstants[115][1],
            //     g_vshConstants[115][2], g_vshConstants[115][3]);
            s_log3D++;
        }
        HLE_Draw3D(base, primType, startVert, vertCount, 0, 0);
        GuestStackCleanup(ctx, 12);
        return;
    }

    // VB is an Xbox resource: +4 = data pointer
    uint32_t vbData = X86_MEM_READ_u32(base, vbAddr + 4);
    if (vbData == 0) {
        if (shouldLog) fprintf(stderr, "  -> skipped: vbData=0\n");
        GuestStackCleanup(ctx, 12);
        return;
    }

    // If FVF is 0 (hardware vertex shader), try to use stride to guess layout
    uint32_t fvf = g_currentFVF;
    if (fvf == 0) {
        // Fallback: assume XYZRHW + DIFFUSE + 1 TEX if stride matches
        // stride=28: XYZRHW(16)+Diffuse(4)+UV(8) — video blit uses exactly this
        if (stride >= 28) fvf = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | (1 << D3DFVF_TEXCOUNT_SHIFT);
        else if (stride >= 24) fvf = D3DFVF_XYZRHW | (1 << D3DFVF_TEXCOUNT_SHIFT);  // XYZRHW(16) + UV(8)
        else if (stride >= 20) fvf = D3DFVF_XYZRHW;
        else fvf = D3DFVF_XYZ;
        if (shouldLog) fprintf(stderr, "  -> FVF was 0, guessed 0x%X from stride=%u\n", fvf, stride);
    }

    const uint8_t* vertBase = base + vbData + startVert * stride;

    std::vector<SWVertex> verts(vertCount);
    for (uint32_t i = 0; i < vertCount; i++)
        verts[i] = ParseFVFVertex(vertBase + i * stride, fvf);

    if (shouldLog && vertCount >= 3) {
        //for (uint32_t i = 0; i < std::min(vertCount, 4u); i++) {
        //    fprintf(stderr, "  v[%u] pos=(%.1f, %.1f, %.1f, %.1f) diffuse=%08X uv=(%.3f, %.3f)\n",
        //            i, verts[i].x, verts[i].y, verts[i].z, verts[i].w,
        //            verts[i].diffuse, verts[i].u, verts[i].v);
        //}
        //RenderTarget rt;
        //if (GetRT(base, rt))
        //    fprintf(stderr, "  RT: %ux%u pixels=%p\n", rt.w, rt.h, rt.pixels);
        //else
        //    fprintf(stderr, "  RT: FAILED to get render target!\n");
    }

    // Log vertex data for quad draws (logo rendering debug)
    if (primType == 8 && vertCount == 4) {
        //static int s_quadVertLog = 0;
        //if (s_quadVertLog < 40) {
        //    for (uint32_t i = 0; i < vertCount; i++) {
        //        fprintf(stderr, "  v[%u] pos=(%.1f, %.1f, %.1f, %.1f) diffuse=%08X uv=(%.3f, %.3f)\n",
        //                i, verts[i].x, verts[i].y, verts[i].z, verts[i].w,
        //                verts[i].diffuse, verts[i].u, verts[i].v);
        //    }
        //    uint32_t texStage0 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
        //    fprintf(stderr, "  texture[0]=0x%08X\n", texStage0);
        //    RenderTarget rt;
        //    if (GetRT(base, rt))
        //        fprintf(stderr, "  RT: %ux%u\n", rt.w, rt.h);
        //    else
        //        fprintf(stderr, "  RT: FAILED\n");
        //    s_quadVertLog++;
        //}
    }

    SubmitPrims(base, verts.data(), verts.size(), (int)primType);
    g_drawCallCount++;

    GuestStackCleanup(ctx, 12);
}

// D3DDevice_SetVertexData2f  (0x995F0) — 3 args, ret 12
void D3DDevice_SetVertexData2f(X86Context& ctx, uint8_t* base)
{
    uint32_t reg  = GuestArg32(ctx, base, 0);
    uint32_t xBits = GuestArg32(ctx, base, 1);
    uint32_t yBits = GuestArg32(ctx, base, 2);
    float fx, fy;
    memcpy(&fx, &xBits, 4);
    memcpy(&fy, &yBits, 4);

    if (reg == X_D3DVSDE_TEXCOORD0 || reg == X_D3DVSDE_TEXCOORD1) {
        g_imCurrent.u = fx;
        g_imCurrent.v = fy;
    } else if (reg == X_D3DVSDE_POSITION || reg == (int)X_D3DVSDE_VERTEX) {
        g_imCurrent.x = fx;
        g_imCurrent.y = fy;
        // Position write triggers vertex emission
        g_imVertices.push_back(g_imCurrent);
    }

    GuestStackCleanup(ctx, 12);
}

// D3DDevice_SetVertexData4f  (0x99630) — 5 args, ret 20
void D3DDevice_SetVertexData4f(X86Context& ctx, uint8_t* base)
{
    uint32_t reg = GuestArg32(ctx, base, 0);
    uint32_t xB  = GuestArg32(ctx, base, 1);
    uint32_t yB  = GuestArg32(ctx, base, 2);
    uint32_t zB  = GuestArg32(ctx, base, 3);
    uint32_t wB  = GuestArg32(ctx, base, 4);
    float fx, fy, fz, fw;
    memcpy(&fx, &xB, 4);
    memcpy(&fy, &yB, 4);
    memcpy(&fz, &zB, 4);
    memcpy(&fw, &wB, 4);

    if (reg == (uint32_t)X_D3DVSDE_POSITION || reg == X_D3DVSDE_VERTEX) {
        g_imCurrent.x = fx;
        g_imCurrent.y = fy;
        g_imCurrent.z = fz;
        g_imCurrent.w = fw;
        g_imVertices.push_back(g_imCurrent);
    } else if (reg == (uint32_t)X_D3DVSDE_TEXCOORD0 || reg == (uint32_t)X_D3DVSDE_TEXCOORD1) {
        g_imCurrent.u = fx;
        g_imCurrent.v = fy;
    } else if (reg == X_D3DVSDE_DIFFUSE) {
        // Packed as 4 floats 0-1 -> ARGB
        uint8_t a = (uint8_t)(std::clamp(fw, 0.0f, 1.0f) * 255.0f);
        uint8_t r = (uint8_t)(std::clamp(fx, 0.0f, 1.0f) * 255.0f);
        uint8_t g = (uint8_t)(std::clamp(fy, 0.0f, 1.0f) * 255.0f);
        uint8_t b = (uint8_t)(std::clamp(fz, 0.0f, 1.0f) * 255.0f);
        g_imCurrent.diffuse = ((uint32_t)a << 24) | ((uint32_t)r << 16)
                            | ((uint32_t)g << 8)  | b;
    }

    GuestStackCleanup(ctx, 20);
}

// D3DDevice_SetVertexDataColor  (0x99690) — 2 args, ret 8
void D3DDevice_SetVertexDataColor(X86Context& ctx, uint8_t* base)
{
    uint32_t reg   = GuestArg32(ctx, base, 0);
    uint32_t color = GuestArg32(ctx, base, 1);

    if (reg == X_D3DVSDE_DIFFUSE)
        g_imCurrent.diffuse = color;

    GuestStackCleanup(ctx, 8);
}

// D3DDevice_Begin  (0x996E0) — 1 arg, ret 4
void D3DDevice_Begin(X86Context& ctx, uint8_t* base)
{
    g_imPrimType = (int)GuestArg32(ctx, base, 0);
    g_imVertices.clear();
    g_imCurrent = {};
    g_imCurrent.diffuse = 0xFFFFFFFF;
    g_imCurrent.w = 1.0f;
    g_imActive = true;

    GuestStackCleanup(ctx, 4);
}

// D3DDevice_End  (0x99720) — 0 args, plain ret
void D3DDevice_End(X86Context& ctx, uint8_t* base)
{
    if (g_imActive && !g_imVertices.empty()) {
        uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
        //static int s_endLog = 0;
        //if (s_endLog < 200) {
        //    fprintf(stderr, "[HLE] End: %zu verts, prim=%d, tex=0x%08X",
        //            g_imVertices.size(), g_imPrimType, texAddr);
        //    if (!g_imVertices.empty()) {
        //        auto& v0 = g_imVertices[0];
        //        fprintf(stderr, " v0=(%.1f,%.1f)", v0.x, v0.y);
        //    }
        //    fprintf(stderr, "\n");
        //    s_endLog++;
        //}
        SubmitPrims(base, g_imVertices.data(), g_imVertices.size(), g_imPrimType);
        g_drawCallCount++;
    }
    g_imVertices.clear();
    g_imActive = false;

    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Vertex / Pixel shaders
// ============================================================================

// D3DDevice_CreateVertexShader  (0x99C70) — 4 args, ret 16
//   arg0 = pDeclaration (FVF-like token stream)
//   arg1 = pFunction    (NV2A microcode tokens; 16 bytes per slot, terminated
//                        by a token with bit 0 set in DWORD 3)
//   arg2 = pHandle      (out)
//   arg3 = Usage
void D3DDevice_CreateVertexShader(X86Context& ctx, uint8_t* base)
{
    uint32_t pDecl   = GuestArg32(ctx, base, 0);
    uint32_t pFunc   = GuestArg32(ctx, base, 1);
    uint32_t pHandle = GuestArg32(ctx, base, 2);
    uint32_t usage   = GuestArg32(ctx, base, 3);

    static uint32_t s_nextVSHandle = 0xFFFE0000;
    uint32_t newHandle = s_nextVSHandle++;

    fprintf(stderr, "[HLE] CreateVertexShader: handle=0x%08X decl=0x%08X "
                    "func=0x%08X usage=0x%X\n",
            newHandle, pDecl, pFunc, usage);

    // -----------------------------------------------------------------
    // Capture declaration + function bytes to disk so the offline
    // NV2A->HLSL translator can consume them. Manifest format:
    //   handle,declAddr,funcAddr,numInstructions,declBytes,funcBytes
    // -----------------------------------------------------------------
    namespace fs = std::filesystem;
    static bool s_dumpDirReady = false;
    static fs::path s_dumpDir;
    if (!s_dumpDirReady) {
        s_dumpDirReady = true;
        s_dumpDir = fs::current_path() / "out" / "shaders";
        std::error_code ec;
        fs::create_directories(s_dumpDir, ec);
        // Start a fresh manifest each run.
        std::ofstream m(s_dumpDir / "manifest.csv", std::ios::trunc);
        m << "handle,decl_addr,func_addr,decl_bytes,func_bytes,decl_file,func_file\n";
    }

    // Count declaration tokens (0xFFFFFFFF-terminated).
    std::vector<uint32_t> declTokens;
    if (pDecl) {
        for (uint32_t i = 0; i < 256; i++) {
            uint32_t tok = X86_MEM_READ_u32(base, pDecl + i * 4);
            declTokens.push_back(tok);
            if (tok == 0xFFFFFFFFu) break;
        }
    }

    // Walk function tokens. Burnout 3 uses NV2A microcode with 4-DWORD
    // instructions; END flag is bit 0 of DWORD 3 (A_TYPE field per Cxbx
    // `FLD_FINAL`). Previous code assumed DWORD 0 — wrong, hence tiny dumps.
    std::vector<uint32_t> funcTokens;
    if (pFunc) {
        // First DWORD is VSH header: lo16=version ('x ' = 0x2078 = VERSION_XVS),
        // hi16=instruction count. Copy it.
        uint32_t hdr = X86_MEM_READ_u32(base, pFunc);
        funcTokens.push_back(hdr);
        for (uint32_t i = 0; i < 256; i++) {
            uint32_t off = 4 + i * 16;
            uint32_t d0 = X86_MEM_READ_u32(base, pFunc + off + 0);
            uint32_t d1 = X86_MEM_READ_u32(base, pFunc + off + 4);
            uint32_t d2 = X86_MEM_READ_u32(base, pFunc + off + 8);
            uint32_t d3 = X86_MEM_READ_u32(base, pFunc + off + 12);
            funcTokens.push_back(d0);
            funcTokens.push_back(d1);
            funcTokens.push_back(d2);
            funcTokens.push_back(d3);
            if (d3 & 1) break; // FLD_FINAL
        }
    }

    // Deduplicate by guest func address — many CreateVertexShader calls
    // share bytecode and we only need one dump per unique program.
    static std::set<uint32_t> s_dumpedFunc;
    bool firstDump = (pFunc != 0) && s_dumpedFunc.insert(pFunc).second;

    if (firstDump) {
        char nameBuf[64];
        std::snprintf(nameBuf, sizeof(nameBuf), "vs_%08X", pFunc);
        fs::path declPath = s_dumpDir / (std::string(nameBuf) + ".decl.bin");
        fs::path funcPath = s_dumpDir / (std::string(nameBuf) + ".func.bin");

        if (!declTokens.empty()) {
            std::ofstream f(declPath, std::ios::binary);
            f.write(reinterpret_cast<const char*>(declTokens.data()),
                    declTokens.size() * 4);
        }
        if (!funcTokens.empty()) {
            std::ofstream f(funcPath, std::ios::binary);
            f.write(reinterpret_cast<const char*>(funcTokens.data()),
                    funcTokens.size() * 4);
        }
        std::ofstream mani(s_dumpDir / "manifest.csv", std::ios::app);
        mani << "0x" << std::hex << newHandle << ","
             << "0x" << pDecl << ","
             << "0x" << pFunc << std::dec << ","
             << (declTokens.size() * 4) << ","
             << (funcTokens.size() * 4) << ","
             << declPath.filename().string() << ","
             << funcPath.filename().string() << "\n";
        fprintf(stderr, "[SHADER] captured %s (decl=%zuB func=%zuB)\n",
                nameBuf, declTokens.size() * 4, funcTokens.size() * 4);
    }

    if (pHandle != 0)
        X86_MEM_WRITE_u32(base, pHandle, newHandle);

    // ----------------------------------------------------------------------
    // NV2A VS microcode -> HLSL -> D3D11 vertex shader + input layout.
    // Fall back silently (leaving g_vsByHandle empty for this handle) so
    // HLE_Draw3D will use the hardcoded s_vs3DHlsl fallback.
    // ----------------------------------------------------------------------
    if (g_d3d11.device && !funcTokens.empty()) {
        Nv2aVsResult r = TranslateNV2AtoHLSL(
            funcTokens.data(), funcTokens.size() * 4,
            declTokens.empty() ? nullptr : declTokens.data(),
            declTokens.size() * 4);
        Nv2aVsResult_FixupPointers(r);

        if (firstDump) {
            // Emit the translated HLSL beside the raw captures for debugging.
            char nameBuf[64];
            std::snprintf(nameBuf, sizeof(nameBuf), "vs_%08X.hlsl", pFunc);
            std::ofstream h(s_dumpDir / nameBuf);
            h << r.hlsl;
            if (!r.ok)
                fprintf(stderr, "[SHADER] translate failed (%s) for func=0x%08X\n",
                        r.error.c_str(), pFunc);
        }

        if (r.ok) {
            ID3DBlob* blob = D3D11CompileShader(r.hlsl.c_str(), "main", "vs_5_0");
            if (blob) {
                VsCacheEntry entry{};
                HRESULT hr1 = g_d3d11.device->CreateVertexShader(
                    blob->GetBufferPointer(), blob->GetBufferSize(),
                    nullptr, &entry.vs);
                HRESULT hr2 = S_OK;
                if (SUCCEEDED(hr1) && !r.inputLayout.empty()) {
                    hr2 = g_d3d11.device->CreateInputLayout(
                        r.inputLayout.data(), (UINT)r.inputLayout.size(),
                        blob->GetBufferPointer(), blob->GetBufferSize(),
                        &entry.il);
                }
                entry.vertexStride = r.vertexStride;
                entry.failed = FAILED(hr1) || FAILED(hr2);
                entry.hlsl = r.hlsl;
                blob->Release();
                g_vsByHandle[newHandle] = entry;
                if (firstDump) {
                    fprintf(stderr,
                        "[SHADER] compiled vs_%08X -> handle=0x%08X "
                        "(hr1=0x%08X hr2=0x%08X stride=%u)\n",
                        pFunc, newHandle, hr1, hr2, entry.vertexStride);
                }
            } else {
                VsCacheEntry entry{};
                entry.failed = true;
                g_vsByHandle[newHandle] = entry;
            }
        } else {
            VsCacheEntry entry{};
            entry.failed = true;
            g_vsByHandle[newHandle] = entry;
        }
    }

    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// D3DDevice_SetStreamSource  (0x99DB0) — 3 args, ret 12
void D3DDevice_SetStreamSource(X86Context& ctx, uint8_t* base)
{
    uint32_t stream = GuestArg32(ctx, base, 0);
    uint32_t pVB    = GuestArg32(ctx, base, 1);
    uint32_t stride = GuestArg32(ctx, base, 2);

    static int s_ssLog = 0;
    if (s_ssLog < 50) {
        //fprintf(stderr, "[HLE] SetStreamSource(stream=%u, vb=0x%08X, stride=%u)\n", stream, pVB, stride);
        s_ssLog++;
    }

    if (stream < 16) {
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x1660 + stream * 8, pVB);
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x1664 + stream * 8, stride);
    }

    GuestStackCleanup(ctx, 12);
}

// D3DDevice_LoadVertexShader  (0xD8730) — 1 arg, ret 4 in Quake 2 build
void D3DDevice_LoadVertexShader(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_SelectVertexShader  (0xD87C0) — plain ret (cdecl in Quake 2 build)
void D3DDevice_SelectVertexShader(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetShaderConstantMode  (0x99F40) — 1 arg, ret 4
void D3DDevice_SetShaderConstantMode(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_SetVertexShader  (0x9A190) — 1 arg, ret 4
void D3DDevice_SetVertexShader(X86Context& ctx, uint8_t* base)
{
    uint32_t handle = GuestArg32(ctx, base, 0);
    g_currentVSHandle = handle;
    static uint32_t s_lastHandle = 0xFFFFFFFFu;
    if (handle != s_lastHandle) {
        // fprintf(stderr, "[HLE] SetVertexShader handle=0x%08X (bit0=%u)\n",
        //         handle, handle & 1);
        s_lastHandle = handle;
    }
    // On Xbox, if bit 0 is clear the handle IS the FVF code
    if (!(handle & 1))
        g_currentFVF = handle;
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_CreatePixelShader  (0x9B0F0) — 2 args, ret 8
//   arg0 = const X_D3DPIXELSHADERDEF* pPSDef  (guest pointer to 60 DWORDs)
//   arg1 = DWORD* pHandle                      (out)
//
// On Xbox, the "handle" returned is actually a pointer to an X_PixelShader
// structure whose pPSDef member points at the original definition. We mirror
// this by returning pPSDef as the handle (it's already a stable guest address)
// and we translate the register-combiner tokens into an HLSL pixel shader at
// creation time, caching the compiled ID3D11PixelShader by handle.
struct TranslatedPS {
    ID3D11PixelShader* ps = nullptr;
    bool usesStage[4]    = {false, false, false, false};
    bool samplesStage[4] = {false, false, false, false};
    unsigned numCombiners = 0;
    std::string hlsl; // kept for diagnostics
    // Baked PSConstant0/1 defaults from the PSDef (ARGB packed). Used to
    // seed g_pshConstants[] the first time this PS becomes active.
    uint32_t bakedC0[8] = {};
    uint32_t bakedC1[8] = {};
};
static std::unordered_map<uint32_t /*guestPsDefAddr*/, TranslatedPS> g_psByHandle;
static uint32_t g_currentPSHandle = 0;

// Seed the runtime PS-constant shadow with a freshly-translated PS's baked
// PSConstant0/1 defaults, but only for slots the game has not already
// uploaded via D3DDevice_SetPixelShaderConstant.  This mimics the Xbox
// driver behaviour where D3DDevice_CreatePixelShader copies the PSDef's
// constants into the render-state bank — runtime uploads supersede them.
static void SeedPSConstantsFromBaked(const TranslatedPS& entry)
{
    auto unpackArgb = [](uint32_t argb, float out[4]) {
        out[0] = ((argb >> 16) & 0xFF) / 255.0f; // R
        out[1] = ((argb >>  8) & 0xFF) / 255.0f; // G
        out[2] = ((argb >>  0) & 0xFF) / 255.0f; // B
        out[3] = ((argb >> 24) & 0xFF) / 255.0f; // A
    };
    for (int i = 0; i < 8; ++i) {
        if (!(g_pshConstantsDirty & (1u << i)))
            unpackArgb(entry.bakedC0[i], g_pshConstants[i]);
    }
    for (int i = 0; i < 8; ++i) {
        if (!(g_pshConstantsDirty & (1u << (8 + i))))
            unpackArgb(entry.bakedC1[i], g_pshConstants[8 + i]);
    }
}

void D3DDevice_CreatePixelShader(X86Context& ctx, uint8_t* base)
{
    uint32_t pPSDef  = GuestArg32(ctx, base, 0);
    uint32_t pHandle = GuestArg32(ctx, base, 1);

    // Translate + compile once per unique PSDef guest address. If the game
    // re-creates the same PSDef later, we'll reuse the cached compilation.
    if (pPSDef != 0 && g_psByHandle.find(pPSDef) == g_psByHandle.end()) {
        uint32_t dwords[Nv2aPsHlsl::kPsDefDwordCount] = {};
        for (size_t i = 0; i < Nv2aPsHlsl::kPsDefDwordCount; ++i)
            dwords[i] = X86_MEM_READ_u32(base, pPSDef + (uint32_t)(i * 4));
        Nv2aPsHlsl::Result tr = Nv2aPsHlsl::Translate(dwords);

        TranslatedPS entry;
        if (tr.ok) {
            if (ID3DBlob* blob = D3D11CompileShader(tr.hlsl.c_str(), "main", "ps_5_0")) {
                HRESULT hr = g_d3d11.device->CreatePixelShader(
                    blob->GetBufferPointer(), blob->GetBufferSize(),
                    nullptr, &entry.ps);
                blob->Release();
                if (FAILED(hr)) entry.ps = nullptr;
            }
            for (int s = 0; s < 4; ++s) {
                entry.usesStage[s]    = tr.usesStage[s];
                entry.samplesStage[s] = tr.samplesStage[s];
            }
            entry.numCombiners = tr.numCombiners;
            entry.hlsl         = tr.hlsl;
            for (int i = 0; i < 8; ++i) entry.bakedC0[i] = tr.bakedC0[i];
            for (int i = 0; i < 8; ++i) entry.bakedC1[i] = tr.bakedC1[i];
        }
        {
            static int s_logCount = 0;
            if (s_logCount < 8) {
                fprintf(stderr,
                    "[PSH] CreatePixelShader psDef=0x%08X ok=%d ps=%p "
                    "stages[0..3]=%d,%d,%d,%d combiners=%u\n",
                    pPSDef, (int)tr.ok, (void*)entry.ps,
                    (int)tr.samplesStage[0], (int)tr.samplesStage[1],
                    (int)tr.samplesStage[2], (int)tr.samplesStage[3],
                    tr.numCombiners);
                ++s_logCount;
            }
            // Dump HLSL for offline inspection (first 8 unique shaders only).
            static int s_dumpCount = 0;
            if (tr.ok && s_dumpCount < 8) {
                char fname[64];
                std::snprintf(fname, sizeof(fname), "pshader_0x%08X.hlsl", pPSDef);
                if (FILE* fp = std::fopen(fname, "w")) {
                    std::fwrite(tr.hlsl.data(), 1, tr.hlsl.size(), fp);
                    std::fclose(fp);
                }
                ++s_dumpCount;
            }
        }
        SeedPSConstantsFromBaked(entry);
        g_psByHandle.emplace(pPSDef, std::move(entry));
    }

    // Echo pPSDef as the handle so SetPixelShader can look it up directly.
    if (pHandle != 0)
        X86_MEM_WRITE_u32(base, pHandle, pPSDef);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SetPixelShader  (0x9B140) — 1 arg, ret 4
void D3DDevice_SetPixelShader(X86Context& ctx, uint8_t* base)
{
    uint32_t handle = GuestArg32(ctx, base, 0);
    g_currentPSHandle = handle;
    // Lazy translation path: Burnout 3 inlines D3DDevice_CreatePixelShader,
    // so our CreatePixelShader hook never fires. The handle the game passes
    // to SetPixelShader is a guest pointer to an X_PixelShader struct of the
    // form { DWORD RefCount; X_D3DPIXELSHADERDEF PSDef; } (Xbox SDK layout).
    // Some variants prepend additional bookkeeping fields, so we probe a few
    // candidate offsets (0, 4, 8, 12) and pick the first one where
    // PSCombinerCount (dword 53) looks sane (1..8).
    if (handle != 0 && g_psByHandle.find(handle) == g_psByHandle.end()) {
        static const uint32_t kProbe[] = { 4u, 0u, 8u, 12u };
        uint32_t psDefAddr = 0;
        uint32_t combinerCount = 0;
        for (uint32_t off : kProbe) {
            uint32_t cc = X86_MEM_READ_u32(base, handle + off + 53u * 4u);
            // PSCombinerCount stores combiner count in low byte (bits 0..3)
            // and flags in upper byte; mask to combiner-count nibble.
            uint32_t n = cc & 0xF;
            if (n >= 1 && n <= 8) { psDefAddr = handle + off; combinerCount = n; break; }
        }
        if (psDefAddr != 0) {
            uint32_t dwords[Nv2aPsHlsl::kPsDefDwordCount] = {};
            for (size_t i = 0; i < Nv2aPsHlsl::kPsDefDwordCount; ++i)
                dwords[i] = X86_MEM_READ_u32(base, psDefAddr + (uint32_t)(i * 4));
            Nv2aPsHlsl::Result tr = Nv2aPsHlsl::Translate(dwords);
            TranslatedPS entry;
            if (tr.ok) {
                if (ID3DBlob* blob = D3D11CompileShader(tr.hlsl.c_str(), "main", "ps_5_0")) {
                    HRESULT hr = g_d3d11.device->CreatePixelShader(
                        blob->GetBufferPointer(), blob->GetBufferSize(),
                        nullptr, &entry.ps);
                    blob->Release();
                    if (FAILED(hr)) entry.ps = nullptr;
                }
                for (int s = 0; s < 4; ++s) {
                    entry.usesStage[s]    = tr.usesStage[s];
                    entry.samplesStage[s] = tr.samplesStage[s];
                }
                entry.numCombiners = tr.numCombiners;
                entry.hlsl         = tr.hlsl;
                for (int i = 0; i < 8; ++i) entry.bakedC0[i] = tr.bakedC0[i];
                for (int i = 0; i < 8; ++i) entry.bakedC1[i] = tr.bakedC1[i];
            }
            static int s_logCount = 0;
            if (s_logCount < 8) {
                fprintf(stderr,
                    "[PSH] SetPixelShader h=0x%08X psDef=0x%08X ok=%d ps=%p "
                    "stages[0..3]=%d,%d,%d,%d combiners=%u(probe=%u)\n",
                    handle, psDefAddr, (int)tr.ok, (void*)entry.ps,
                    (int)tr.samplesStage[0], (int)tr.samplesStage[1],
                    (int)tr.samplesStage[2], (int)tr.samplesStage[3],
                    tr.numCombiners, combinerCount);
                fprintf(stderr,
                    "[PSH]   bakedC0: %08X %08X %08X %08X %08X %08X %08X %08X\n",
                    entry.bakedC0[0], entry.bakedC0[1], entry.bakedC0[2], entry.bakedC0[3],
                    entry.bakedC0[4], entry.bakedC0[5], entry.bakedC0[6], entry.bakedC0[7]);
                fprintf(stderr,
                    "[PSH]   bakedC1: %08X %08X %08X %08X %08X %08X %08X %08X\n",
                    entry.bakedC1[0], entry.bakedC1[1], entry.bakedC1[2], entry.bakedC1[3],
                    entry.bakedC1[4], entry.bakedC1[5], entry.bakedC1[6], entry.bakedC1[7]);
                ++s_logCount;
            }
            static int s_dumpCount = 0;
            if (tr.ok && s_dumpCount < 8) {
                char fname[64];
                std::snprintf(fname, sizeof(fname), "pshader_0x%08X.hlsl", handle);
                if (FILE* fp = std::fopen(fname, "w")) {
                    std::fwrite(tr.hlsl.data(), 1, tr.hlsl.size(), fp);
                    std::fclose(fp);
                }
                ++s_dumpCount;
            }
            SeedPSConstantsFromBaked(entry);
            g_psByHandle.emplace(handle, std::move(entry));
        } else {
            static int s_warnCount = 0;
            if (s_warnCount < 4) {
                fprintf(stderr,
                    "[PSH] SetPixelShader h=0x%08X: no plausible PSDef offset (CombinerCount probe failed)\n",
                    handle);
                ++s_warnCount;
            }
            // Insert empty entry so we don't re-probe every call.
            g_psByHandle.emplace(handle, TranslatedPS{});
        }
    }
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Resource management
// ============================================================================

// D3D_DestroyResource  (0xD8D90) — plain ret (cdecl in Quake 2 build)
void D3D_DestroyResource(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE] D3D_DestroyResource(0x%08X)\n", GuestArg32(ctx, base, 0));
    GuestStackCleanup(ctx, 0);
}

// D3DResource_AddRef  (0x9A470) — 1 arg, ret 4
void D3DResource_AddRef(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t refCount = 0;
    if (pThis != 0) {
        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        refCount = (common & X_D3DCOMMON_REFCOUNT_MASK) + 1;
        common = (common & ~X_D3DCOMMON_REFCOUNT_MASK) | (refCount & X_D3DCOMMON_REFCOUNT_MASK);
        X86_MEM_WRITE_u32(base, pThis + 0, common);
    }
    GuestReturn32(ctx, refCount);
    GuestStackCleanup(ctx, 4);
}

// D3DResource_Release  (0x9A4B0) — 1 arg, ret 4
void D3DResource_Release(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t refCount = 0;
    if (pThis != 0) {
        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        refCount = (common & X_D3DCOMMON_REFCOUNT_MASK);
        if (refCount > 0) refCount--;
        common = (common & ~X_D3DCOMMON_REFCOUNT_MASK) | (refCount & X_D3DCOMMON_REFCOUNT_MASK);
        X86_MEM_WRITE_u32(base, pThis + 0, common);
    }
    GuestReturn32(ctx, refCount);
    GuestStackCleanup(ctx, 4);
}

// D3DResource_GetType  (0xD8F30) — plain ret (cdecl in Quake 2 build)
void D3DResource_GetType(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t rType = X_D3DRTYPE_NONE;
    if (pThis != 0) {
        uint32_t commonType = X86_MEM_READ_u32(base, pThis + 0) & X_D3DCOMMON_TYPE_MASK;
        switch (commonType) {
        case X_D3DCOMMON_TYPE_VERTEXBUFFER: rType = X_D3DRTYPE_VERTEXBUFFER; break;
        case X_D3DCOMMON_TYPE_INDEXBUFFER:  rType = X_D3DRTYPE_INDEXBUFFER;  break;
        case X_D3DCOMMON_TYPE_PUSHBUFFER:   rType = X_D3DRTYPE_PUSHBUFFER;   break;
        case X_D3DCOMMON_TYPE_PALETTE:      rType = X_D3DRTYPE_PALETTE;      break;
        case X_D3DCOMMON_TYPE_TEXTURE:      rType = X_D3DRTYPE_TEXTURE;      break;
        case X_D3DCOMMON_TYPE_SURFACE:      rType = X_D3DRTYPE_SURFACE;      break;
        default: break;
        }
    }
    GuestReturn32(ctx, rType);
    GuestStackCleanup(ctx, 0);
}

// D3DResource_Register  (0x9A590) — 2 args, ret 8
// Xbox SDK: D3DResource_Register(D3DResource *pThis, PVOID pBase)
// The Data field (+4) stores a relative offset from pBase to the pixel data.
// Register converts it to an absolute guest address: Data = pBase + Data.
void D3DResource_Register(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t pBase = GuestArg32(ctx, base, 1);

    if (pThis != 0) {
        // Fix up refcount
        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        if ((common & X_D3DCOMMON_REFCOUNT_MASK) == 0) {
            common = (common & ~X_D3DCOMMON_REFCOUNT_MASK) | 1;
            X86_MEM_WRITE_u32(base, pThis + 0, common);
        }

        // Fix up Data field: convert relative offset to absolute address
        uint32_t dataOffset = X86_MEM_READ_u32(base, pThis + 4);
        uint32_t dataAddr = pBase + dataOffset;
        X86_MEM_WRITE_u32(base, pThis + 4, dataAddr);

        fprintf(stderr, "[HLE] D3DResource_Register(pThis=0x%08X, pBase=0x%08X) "
                "Data: offset=0x%08X -> addr=0x%08X\n",
                pThis, pBase, dataOffset, dataAddr);
    }
    GuestStackCleanup(ctx, 8);
}

// ============================================================================
// Contiguous memory
// ============================================================================

// D3D_AllocContiguousMemory  (0x9B340) — tail-calls XMemAlloc, net ret 8
void D3D_AllocContiguousMemory(X86Context& ctx, uint8_t* base)
{
    uint32_t size      = GuestArg32(ctx, base, 0);
    uint32_t alignment = GuestArg32(ctx, base, 1);
    if (alignment == 0) alignment = 64;

    uint32_t addr = ContigAlloc(size, alignment);
    memset(base + addr, 0, size);

    fprintf(stderr, "[HLE] D3D_AllocContiguousMemory(size=%u, align=%u) -> 0x%08X\n",
            size, alignment, addr);

    GuestReturn32(ctx, addr);
    GuestStackCleanup(ctx, 8);
}

// D3D_FreeContiguousMemory  (0x9B380) — 1 arg, ret 4
void D3D_FreeContiguousMemory(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Surface operations
// ============================================================================

// D3DSurface_GetDesc  (0x9B430) — 2 args, ret 8
void D3DSurface_GetDesc(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis = GuestArg32(ctx, base, 0);
    uint32_t pDesc = GuestArg32(ctx, base, 1);

    if (pThis != 0 && pDesc != 0) {
        X86_MEM_WRITE_u32(base, pDesc + 0x00, X_D3DFMT_LIN_X8R8G8B8);
        X86_MEM_WRITE_u32(base, pDesc + 0x04, X_D3DRTYPE_SURFACE);
        X86_MEM_WRITE_u32(base, pDesc + 0x08, 0);
        X86_MEM_WRITE_u32(base, pDesc + 0x0C, 640 * 480 * 4);
        X86_MEM_WRITE_u32(base, pDesc + 0x10, 0);
        X86_MEM_WRITE_u32(base, pDesc + 0x14, 640);
        X86_MEM_WRITE_u32(base, pDesc + 0x18, 480);
    }
    GuestStackCleanup(ctx, 8);
}

// D3DSurface_LockRect  (0x9B450) — 4 args, ret 16
void D3DSurface_LockRect(X86Context& ctx, uint8_t* base)
{
    uint32_t pThis       = GuestArg32(ctx, base, 0);
    uint32_t pLockedRect = GuestArg32(ctx, base, 1);

    if (pThis != 0 && pLockedRect != 0) {
        uint32_t dataAddr = X86_MEM_READ_u32(base, pThis + 4);
        X86_MEM_WRITE_u32(base, pLockedRect + 0, 640 * 4);
        X86_MEM_WRITE_u32(base, pLockedRect + 4, dataAddr);
    }
    GuestStackCleanup(ctx, 16);
}

// ============================================================================
// Tile
// ============================================================================

// D3D_SetTileNoWait  (0xD7D40) — plain ret (cdecl in Quake 2 build)
void D3D_SetTileNoWait(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Push buffer / NV2A internals
// ============================================================================

// D3D_CMiniport_CreateCtxDmaObject  (0x9B73B) — 5 args, ret 20
void D3D_CMiniport_CreateCtxDmaObject(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 20);
}

// D3D_CMiniport_InitHardware  (0x9BA4D) — 0 args, plain ret
void D3D_CMiniport_InitHardware(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE] D3D_CMiniport_InitHardware — stubbed\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// D3D_CDevice_KickOff  (0x9C3E0) — 0 args, plain ret
//
// The game flushes the push buffer here. Drain any pending NV2A method
// writes (vertex-shader constants etc.) into our host-side cache.
void D3D_CDevice_KickOff(X86Context& ctx, uint8_t* base)
{
    WalkPushBuffer(base);
    GuestStackCleanup(ctx, 0);
}

// j_D3D_KickOffAndWaitForIdle  (0x96880) — trampoline, plain ret
void j_D3D_KickOffAndWaitForIdle(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3D_KickOffAndWaitForIdle  (0x9C8D0) — 0 args, plain ret
void D3D_KickOffAndWaitForIdle(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3D_SetFence  (0x9C500) — 1 arg, ret 4
void D3D_SetFence(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3D_BlockOnTime  (0x351770) — 1 stack arg (flags), EAX=fence, ret 4
void D3D_BlockOnTime(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3D_MakeRequestedSpace  (0x9C730) — 2 args, ret 8
void D3D_MakeRequestedSpace(X86Context& ctx, uint8_t* base)
{
    EnsurePushBuffer(base);
    WalkPushBuffer(base);
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    s_pbLastWalked = g_pbGuestBase;
    // Return the new put in EAX (callers often use the result as &[put]).
    ctx.eax = g_pbGuestBase;
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_MakeSpace  (0x9C870) — 0 args, plain ret
void D3DDevice_MakeSpace(X86Context& ctx, uint8_t* base)
{
    EnsurePushBuffer(base);
    WalkPushBuffer(base);
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    s_pbLastWalked = g_pbGuestBase;
    ctx.eax = g_pbGuestBase;
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_BeginStateBig  (0x9C880) — 1 arg, ret 4
void D3DDevice_BeginStateBig(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// D3D_BlockOnResource  (0x351B50) — 0 stack args, plain ret (thiscall: ecx = resource)
void D3D_BlockOnResource(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3D_LazySetPointParams  (0x9CAD0) — 1 arg, ret 4
void D3D_LazySetPointParams(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3D_CDevice_SetStateVB  (0x9E110) — 1 arg, ret 4
void D3D_CDevice_SetStateVB(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3D_CDevice_FreeFrameBuffers  (0x9EE80) — 0 args, plain ret
void D3D_CDevice_FreeFrameBuffers(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3D_CDevice_InitializeFrameBuffers  (0x9EFB0) — 1 arg, ret 4
void D3D_CDevice_InitializeFrameBuffers(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// D3D8-level internal helpers
// ============================================================================

// D3D8_Get2DSurfaceDesc  (0xDF100) — plain ret (cdecl in Quake 2 build)
// Args: pPixelContainer, face(?), level(?), pDesc(?)
// The Quake 2 build uses cdecl (no callee cleanup).
void D3D8_Get2DSurfaceDesc(X86Context& ctx, uint8_t* base)
{
    uint32_t pSurface = GuestArg32(ctx, base, 0);
    // Arg layout may vary; try to fill a D3DSURFACE_DESC if a desc pointer is on the stack.
    // For now, just log and return success without corrupting the stack.
    static bool logged = false;
    if (!logged) {
        fprintf(stderr, "[HLE] D3D8_Get2DSurfaceDesc(pSurface=0x%08X)\n", pSurface);
        logged = true;
    }
    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 0);
}

// D3D8_Lock2DSurface  (0xDF3E0) — 4 args, ret 16 in Quake 2 build
// Args (stdcall): pResource, pLockedRect, pRect, Flags
// Locks a 2D surface and returns pitch + data pointer in pLockedRect.
void D3D8_Lock2DSurface(X86Context& ctx, uint8_t* base)
{
    uint32_t pResource   = GuestArg32(ctx, base, 0);
    uint32_t pLockedRect = GuestArg32(ctx, base, 1);
    uint32_t pRect       = GuestArg32(ctx, base, 2);
    // uint32_t flags     = GuestArg32(ctx, base, 3);

    if (pResource != 0 && pLockedRect != 0) {
        uint32_t dataAddr  = X86_MEM_READ_u32(base, pResource + 4);
        uint32_t sizeField = X86_MEM_READ_u32(base, pResource + 16);
        uint32_t fmtField  = X86_MEM_READ_u32(base, pResource + 12);
        uint32_t fmt       = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

        // Determine width from Size field or Format field
        uint32_t width = 0;
        if (sizeField != 0) {
            width = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        } else {
            uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
            width = 1u << logU;
        }
        if (width == 0) width = 320; // fallback

        // Calculate pitch based on format
        uint32_t bpp = FormatBPP(fmt);
        uint32_t pitch = width * (bpp > 0 ? bpp : 4);

        // If a sub-rect is specified, adjust data pointer to the start of the rect
        if (pRect != 0) {
            uint32_t left = X86_MEM_READ_u32(base, pRect + 0);
            uint32_t top  = X86_MEM_READ_u32(base, pRect + 4);
            dataAddr += top * pitch + left * (bpp > 0 ? bpp : 4);
        }

        // Write D3DLOCKED_RECT: { INT Pitch; void* pBits; }
        X86_MEM_WRITE_u32(base, pLockedRect + 0, pitch);
        X86_MEM_WRITE_u32(base, pLockedRect + 4, dataAddr);

        // Set the ISLOCKED flag
        uint32_t common = X86_MEM_READ_u32(base, pResource + 0);
        common |= X_D3DCOMMON_ISLOCKED;
        X86_MEM_WRITE_u32(base, pResource + 0, common);

        static int s_lockLog = 0;
        if (s_lockLog < 5) {
            fprintf(stderr, "[HLE] D3D8_Lock2DSurface(res=0x%08X) -> pitch=%u data=0x%08X w=%u fmt=0x%02X\n",
                    pResource, pitch, dataAddr, width, fmt);
            s_lockLog++;
        }
    }

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 16);
}

// ============================================================================
// Display capabilities / flip
// ============================================================================

// D3D_CMiniport_GetDisplayCapabilities  (0xA05B5) — 0 args, plain ret
void D3D_CMiniport_GetDisplayCapabilities(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// D3D_CMiniport_IsFlipPending  (0xA08C0) — 0 args, plain ret
void D3D_CMiniport_IsFlipPending(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Image parsing via stb_image (supports PNG, BMP, TGA, JPG, GIF, PSD, HDR)
// ============================================================================

// Decoded image: always stored as A8R8G8B8 (32-bit BGRA, matching Xbox layout).
struct DecodedImage {
    uint32_t width  = 0;
    uint32_t height = 0;
    std::vector<uint32_t> pixels; // width*height ARGB32 pixels
};

// ---- DXT1 block decompression -----------------------------------------------

static inline uint32_t DXT1_RGB565toARGB(uint16_t c)
{
    uint32_t r = ((c >> 11) & 0x1F) * 255 / 31;
    uint32_t g = ((c >> 5)  & 0x3F) * 255 / 63;
    uint32_t b = ((c >> 0)  & 0x1F) * 255 / 31;
    return 0xFF000000u | (r << 16) | (g << 8) | b;
}

static void DecompressDXT1Block(const uint8_t* block, uint32_t out[16])
{
    uint16_t c0 = block[0] | (block[1] << 8);
    uint16_t c1 = block[2] | (block[3] << 8);
    uint32_t color[4];
    color[0] = DXT1_RGB565toARGB(c0);
    color[1] = DXT1_RGB565toARGB(c1);
    if (c0 > c1) {
        // 4-colour block: c2 = 2/3*c0 + 1/3*c1, c3 = 1/3*c0 + 2/3*c1
        uint32_t r0 = (color[0] >> 16) & 0xFF, g0 = (color[0] >> 8) & 0xFF, b0 = color[0] & 0xFF;
        uint32_t r1 = (color[1] >> 16) & 0xFF, g1 = (color[1] >> 8) & 0xFF, b1 = color[1] & 0xFF;
        color[2] = 0xFF000000u | (((2*r0+r1)/3)<<16) | (((2*g0+g1)/3)<<8) | ((2*b0+b1)/3);
        color[3] = 0xFF000000u | (((r0+2*r1)/3)<<16) | (((g0+2*g1)/3)<<8) | ((b0+2*b1)/3);
    } else {
        // 3-colour + transparent block
        uint32_t r0 = (color[0] >> 16) & 0xFF, g0 = (color[0] >> 8) & 0xFF, b0 = color[0] & 0xFF;
        uint32_t r1 = (color[1] >> 16) & 0xFF, g1 = (color[1] >> 8) & 0xFF, b1 = color[1] & 0xFF;
        color[2] = 0xFF000000u | (((r0+r1)/2)<<16) | (((g0+g1)/2)<<8) | ((b0+b1)/2);
        color[3] = 0x00000000u; // transparent black
    }
    uint32_t indices = block[4] | (block[5] << 8) | (block[6] << 16) | (block[7] << 24);
    for (int i = 0; i < 16; i++) {
        out[i] = color[indices & 3];
        indices >>= 2;
    }
}

// ---- XPR0 (Xbox Packed Resource) parsing ------------------------------------

static bool ParseXPR0(const uint8_t* data, size_t size, DecodedImage& img, uint32_t& outMipCount)
{
    if (size < 12 + 20) return false;
    if (data[0] != 'X' || data[1] != 'P' || data[2] != 'R' || data[3] != '0')
        return false;

    uint32_t totalSize = *(const uint32_t*)(data + 4);
    uint32_t headerSize = *(const uint32_t*)(data + 8);
    if (headerSize > size || totalSize > size) return false;

    // First resource entry starts at offset 12
    // X_D3DPixelContainer layout: Common(4) + Data(4) + Lock(4) + Format(4) + Size(4) = 20 bytes
    uint32_t common   = *(const uint32_t*)(data + 12);
    uint32_t dataOff  = *(const uint32_t*)(data + 16); // offset from headerSize
    // offset 20 = Lock (skip)
    uint32_t fmtField = *(const uint32_t*)(data + 24);
    uint32_t sizeField = *(const uint32_t*)(data + 28);

    uint32_t resType = (common >> 16) & 7;
    if (resType != 4) { // 4 = Texture
        fprintf(stderr, "[HLE]   XPR0: resource type %u (not texture)\n", resType);
        return false;
    }

    uint32_t fmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
    uint32_t texW, texH;
    if (sizeField != 0) {
        texW = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        texH = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
    } else {
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        texW = 1u << logU;
        texH = 1u << logV;
    }
    if (texW == 0 || texH == 0) return false;

    const uint8_t* texData = data + headerSize + dataOff;
    size_t texDataSize = size - (headerSize + dataOff);

    fprintf(stderr, "[HLE]   XPR0: %ux%u fmt=0x%02X dataOff=%u\n", texW, texH, fmt, dataOff);

    outMipCount = 1;
    img.width = texW;
    img.height = texH;
    img.pixels.resize((size_t)texW * texH);

    // Decode based on format
    if (fmt == X_D3DFMT_DXT1) {
        uint32_t bw = (texW + 3) / 4;
        uint32_t bh = (texH + 3) / 4;
        if (texDataSize < (size_t)(bw * bh * 8)) {
            fprintf(stderr, "[HLE]   XPR0: not enough data for DXT1 (%zu < %u)\n",
                    texDataSize, bw * bh * 8);
            return false;
        }
        for (uint32_t by = 0; by < bh; by++) {
            for (uint32_t bx = 0; bx < bw; bx++) {
                uint32_t blockPixels[16];
                DecompressDXT1Block(texData + (by * bw + bx) * 8, blockPixels);
                for (uint32_t py = 0; py < 4 && (by * 4 + py) < texH; py++) {
                    for (uint32_t px = 0; px < 4 && (bx * 4 + px) < texW; px++) {
                        img.pixels[(by * 4 + py) * texW + (bx * 4 + px)] = blockPixels[py * 4 + px];
                    }
                }
            }
        }
    } else if (fmt == X_D3DFMT_A8R8G8B8 || fmt == X_D3DFMT_LIN_A8R8G8B8) {
        size_t needed = (size_t)texW * texH * 4;
        if (texDataSize < needed) return false;
        bool swizzled = (fmt == X_D3DFMT_A8R8G8B8 && sizeField == 0);
        if (swizzled) {
            uint32_t logW = 0, logH = 0;
            for (uint32_t t = texW; t > 1; t >>= 1) logW++;
            for (uint32_t t = texH; t > 1; t >>= 1) logH++;
            const uint32_t* src32 = reinterpret_cast<const uint32_t*>(texData);
            for (uint32_t y = 0; y < texH; y++)
                for (uint32_t x = 0; x < texW; x++)
                    img.pixels[y * texW + x] = src32[XboxSwizzleOffset(x, y, logW, logH)];
        } else {
            memcpy(img.pixels.data(), texData, needed);
        }
    } else if (fmt == X_D3DFMT_X8R8G8B8 || fmt == X_D3DFMT_LIN_X8R8G8B8) {
        size_t needed = (size_t)texW * texH * 4;
        if (texDataSize < needed) return false;
        const uint32_t* src32 = reinterpret_cast<const uint32_t*>(texData);
        for (uint32_t i = 0; i < texW * texH; i++)
            img.pixels[i] = src32[i] | 0xFF000000u;
    } else if (fmt == X_D3DFMT_A4R4G4B4) {
        size_t needed = (size_t)texW * texH * 2;
        if (texDataSize < needed) return false;
        const uint16_t* src16 = reinterpret_cast<const uint16_t*>(texData);
        for (uint32_t i = 0; i < texW * texH; i++) {
            uint16_t raw = src16[i];
            uint32_t a = ((raw >> 12) & 0xF) * 17;
            uint32_t r = ((raw >> 8)  & 0xF) * 17;
            uint32_t g = ((raw >> 4)  & 0xF) * 17;
            uint32_t b = ((raw >> 0)  & 0xF) * 17;
            img.pixels[i] = (a << 24) | (r << 16) | (g << 8) | b;
        }
    } else {
        fprintf(stderr, "[HLE]   XPR0: unsupported format 0x%02X\n", fmt);
        return false;
    }

    return true;
}

// Parse any image format supported by stb_image from a raw memory buffer.
// Output pixels are converted to A8R8G8B8 (Xbox native order).
static bool ParseImage(const uint8_t* data, size_t size, DecodedImage& img, uint32_t& outMipCount)
{
    outMipCount = 1;

    // Try Xbox Packed Resource (XPR0) first
    if (size >= 4 && data[0] == 'X' && data[1] == 'P' && data[2] == 'R' && data[3] == '0') {
        if (ParseXPR0(data, size, img, outMipCount))
            return true;
        fprintf(stderr, "[HLE]   XPR0 parse failed, falling back to stb_image\n");
    }

    int w = 0, h = 0, channels = 0;
    // Request 4 channels (RGBA) regardless of source format
    stbi_uc* pixels = stbi_load_from_memory(data, (int)size, &w, &h, &channels, 4);
    if (!pixels) {
        fprintf(stderr, "[HLE]   stb_image error: %s\n", stbi_failure_reason());
        return false;
    }

    img.width  = (uint32_t)w;
    img.height = (uint32_t)h;
    img.pixels.resize((size_t)w * h);

    // stb_image returns RGBA (R at byte 0). Xbox A8R8G8B8 is BGRA in memory
    // (B at byte 0 on little-endian).  Swizzle R<->B.
    const uint8_t* src = pixels;
    for (int i = 0; i < w * h; i++) {
        uint8_t r = src[i * 4 + 0];
        uint8_t g = src[i * 4 + 1];
        uint8_t b = src[i * 4 + 2];
        uint8_t a = src[i * 4 + 3];
        img.pixels[i] = ((uint32_t)a << 24) | ((uint32_t)r << 16) |
                        ((uint32_t)g << 8)  | (uint32_t)b;
    }

    stbi_image_free(pixels);

    fprintf(stderr, "[HLE]   parsed %dx%d image (%d source channels)\n", w, h, channels);
    return true;
}

// ---- Texture dump (debug) ---------------------------------------------------

static int g_dumpIndex = 0;

static void DumpTextureToPNG(const DecodedImage& img, const char* label)
{
    if (img.pixels.empty() || img.width == 0 || img.height == 0) return;

    // Create dump directory next to executable
    std::filesystem::create_directories("tex_dump");

    // Build filename: tex_dump/00_label.png
    char filename[512];
    // Sanitize label: replace path separators and special chars
    std::string safe(label ? label : "unknown");
    for (char& c : safe) {
        if (c == '\\' || c == '/' || c == ':' || c == '?' || c == '*' || c == '"' || c == '<' || c == '>' || c == '|')
            c = '_';
    }
    snprintf(filename, sizeof(filename), "tex_dump/%02d_%s.png", g_dumpIndex++, safe.c_str());

    // Convert A8R8G8B8 (BGRA) back to RGBA for stb_image_write
    std::vector<uint8_t> rgba(img.width * img.height * 4);
    for (size_t i = 0; i < img.pixels.size(); i++) {
        uint32_t p = img.pixels[i];
        rgba[i * 4 + 0] = (uint8_t)((p >> 16) & 0xFF); // R
        rgba[i * 4 + 1] = (uint8_t)((p >> 8) & 0xFF);  // G
        rgba[i * 4 + 2] = (uint8_t)((p) & 0xFF);       // B
        rgba[i * 4 + 3] = (uint8_t)((p >> 24) & 0xFF); // A
    }

    int ok = stbi_write_png(filename, (int)img.width, (int)img.height, 4,
                            rgba.data(), (int)(img.width * 4));
    fprintf(stderr, "[HLE]   DUMP: %s (%ux%u) -> %s\n",
            ok ? "OK" : "FAIL", img.width, img.height, filename);
}

// ---- Guest texture builder --------------------------------------------------

// Compute floor(log2(v)), minimum 0.
static uint32_t Log2Floor(uint32_t v)
{
    uint32_t r = 0;
    while (v > 1) { v >>= 1; r++; }
    return r;
}

// Determine if v is a power of 2.
static bool IsPow2(uint32_t v) { return v && !(v & (v - 1)); }

// Build an Xbox D3D texture (X_D3DPixelContainer) in guest memory from decoded
// A8R8G8B8 pixels.  Returns the guest address of the texture struct.
static uint32_t BuildGuestTexture(uint8_t* base, const DecodedImage& img,
                                  uint32_t mipLevels = 1)
{
    uint32_t w = img.width;
    uint32_t h = img.height;
    if (w == 0) w = 1;
    if (h == 0) h = 1;
    if (mipLevels == 0) mipLevels = 1;

    // Clamp mip levels to what the dimensions can actually produce
    uint32_t maxMips = 1 + Log2Floor(std::max(w, h));
    if (mipLevels > maxMips) mipLevels = maxMips;

    // Allocate pixel data for all mip levels (A8R8G8B8 = 4 bytes/pixel)
    uint32_t totalBytes = 0;
    {
        uint32_t mw = w, mh = h;
        for (uint32_t i = 0; i < mipLevels; i++) {
            totalBytes += mw * mh * 4;
            if (mw > 1) mw >>= 1;
            if (mh > 1) mh >>= 1;
        }
    }

    uint32_t dataAddr = ContigAlloc(totalBytes, 128);

    // Copy level-0 pixels
    if (!img.pixels.empty()) {
        uint32_t level0Bytes = w * h * 4;
        memcpy(base + dataAddr, img.pixels.data(),
               std::min((size_t)level0Bytes, img.pixels.size() * 4));
    } else {
        memset(base + dataAddr, 0xFF, w * h * 4);
    }

    // Simple box-filter mipmap generation for additional levels
    {
        uint32_t prevOff = dataAddr;
        uint32_t prevW = w, prevH = h;
        uint32_t curOff = dataAddr + w * h * 4;
        for (uint32_t level = 1; level < mipLevels; level++) {
            uint32_t mw = prevW > 1 ? prevW / 2 : 1;
            uint32_t mh = prevH > 1 ? prevH / 2 : 1;
            const uint32_t* src = reinterpret_cast<const uint32_t*>(base + prevOff);
            uint32_t*       dst = reinterpret_cast<uint32_t*>(base + curOff);
            for (uint32_t y = 0; y < mh; y++) {
                for (uint32_t x = 0; x < mw; x++) {
                    // Average 2x2 block from previous level
                    uint32_t sx = x * 2, sy = y * 2;
                    uint32_t r = 0, g = 0, b = 0, a = 0;
                    auto accum = [&](uint32_t px) {
                        a += (px >> 24) & 0xFF;
                        r += (px >> 16) & 0xFF;
                        g += (px >>  8) & 0xFF;
                        b += (px      ) & 0xFF;
                    };
                    accum(src[sy * prevW + sx]);
                    accum(src[sy * prevW + std::min(sx + 1, prevW - 1)]);
                    accum(src[std::min(sy + 1, prevH - 1) * prevW + sx]);
                    accum(src[std::min(sy + 1, prevH - 1) * prevW + std::min(sx + 1, prevW - 1)]);
                    dst[y * mw + x] = ((a / 4) << 24) | ((r / 4) << 16) |
                                      ((g / 4) << 8) | (b / 4);
                }
            }
            prevOff = curOff;
            prevW = mw;
            prevH = mh;
            curOff += mw * mh * 4;
        }
    }

    // Allocate the 20-byte X_D3DPixelContainer struct
    uint32_t texAddr = ContigAlloc(20, 64);

    // +0  Common: refcount=1 | TYPE_TEXTURE | D3DCREATED
    X86_MEM_WRITE_u32(base, texAddr + 0,
                      1 | X_D3DCOMMON_TYPE_TEXTURE | X_D3DCOMMON_D3DCREATED);
    // +4  Data: pointer to pixel data
    X86_MEM_WRITE_u32(base, texAddr + 4, dataAddr);
    // +8  Lock: 0
    X86_MEM_WRITE_u32(base, texAddr + 8, 0);

    // +12 Format bitfield
    // Always use LIN_A8R8G8B8 + Size field because our pixel data is stored
    // linearly (memcpy from decoded image).  Non-linear (swizzled) format
    // would cause SampleTex to apply Xbox swizzle offsets to linear data.
    uint32_t fmtField = (X_D3DFMT_LIN_A8R8G8B8 << X_D3DFORMAT_FORMAT_SHIFT)
                      | ((mipLevels - 1) << X_D3DFORMAT_MIPMAP_SHIFT)
                      | (2u << X_D3DFORMAT_DIMENSION_SHIFT); // 2D texture
    X86_MEM_WRITE_u32(base, texAddr + 12, fmtField);

    {
        uint32_t pitch = w * 4;
        uint32_t sizeField = ((w - 1) & X_D3DSIZE_WIDTH_MASK)
                           | (((h - 1) << X_D3DSIZE_HEIGHT_SHIFT) & X_D3DSIZE_HEIGHT_MASK)
                           | ((((pitch / 64) > 0 ? (pitch / 64) - 1 : 0)
                               << X_D3DSIZE_PITCH_SHIFT) & X_D3DSIZE_PITCH_MASK);
        X86_MEM_WRITE_u32(base, texAddr + 16, sizeField);
    }

    fprintf(stderr, "[HLE]   -> texture @ 0x%08X  data @ 0x%08X  %ux%u  mips=%u\n",
            texAddr, dataAddr, w, h, mipLevels);
    return texAddr;
}

// ============================================================================
// D3DX utility functions
// ============================================================================

// D3DXLoadSurfaceFromMemory  (0xA7E7D) — 10 args, ret 40
void D3DXLoadSurfaceFromMemory(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE] D3DXLoadSurfaceFromMemory — stubbed (S_OK)\n");
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 40);
}

// D3DXCheckTextureRequirements  (0xA8087) — 7 args, ret 28
void D3DXCheckTextureRequirements(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 28);
}

// D3DXLoadSurfaceFromSurface  (0xA8246) — 8 args, ret 32
void D3DXLoadSurfaceFromSurface(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 32);
}

// D3DXFilterTexture  (0xA836F) — 4 args, ret 16
void D3DXFilterTexture(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 16);
}

// D3DXCreateTextureFromFileInMemoryEx  (0xA84C2) — 15 args, ret 60
//
// Args (Xbox D3D8 / D3DX8 — stdcall):
//   [0]  pDevice      — ignored (we have a single global device)
//   [1]  pSrcData     — guest pointer to raw image file data
//   [2]  SrcDataSize  — byte count of image data
//   [3]  Width        — desired width  (0 / D3DX_DEFAULT = use source)
//   [4]  Height       — desired height (0 / D3DX_DEFAULT = use source)
//   [5]  MipLevels    — 0 = full chain, else explicit count
//   [6]  Usage
//   [7]  Format       — desired X_D3DFORMAT (0 = use source format)
//   [8]  Pool
//   [9]  Filter
//   [10] MipFilter
//   [11] ColorKey
//   [12] pSrcInfo     — [out] optional D3DXIMAGE_INFO
//   [13] pPalette     — [out] optional palette
//   [14] ppTexture    — [out] receives guest texture pointer
void D3DXCreateTextureFromFileInMemoryEx(X86Context& ctx, uint8_t* base)
{
    uint32_t pSrcData    = GuestArg32(ctx, base, 1);
    uint32_t srcDataSize = GuestArg32(ctx, base, 2);
    uint32_t reqWidth    = GuestArg32(ctx, base, 3);
    uint32_t reqHeight   = GuestArg32(ctx, base, 4);
    uint32_t reqMips     = GuestArg32(ctx, base, 5);
    uint32_t pSrcInfo    = GuestArg32(ctx, base, 12);
    uint32_t ppTexture   = GuestArg32(ctx, base, 14);

    fprintf(stderr, "[HLE] D3DXCreateTextureFromFileInMemoryEx(src=0x%08X, size=%u, "
                    "w=%u, h=%u, mips=%u, ppTex=0x%08X)\n",
            pSrcData, srcDataSize, reqWidth, reqHeight, reqMips, ppTexture);

    DecodedImage img;
    uint32_t fileMipCount = 1;
    bool ok = false;

    if (pSrcData != 0 && srcDataSize > 0) {
        const uint8_t* srcBytes = base + pSrcData;
        ok = ParseImage(srcBytes, srcDataSize, img, fileMipCount);
    }

    if (!ok) {
        // Parsing failed — create a small fallback texture so the game doesn't crash
        fprintf(stderr, "[HLE]   image parse FAILED — creating 1x1 magenta fallback\n");
        img.width = 1;
        img.height = 1;
        img.pixels = { 0xFFFF00FFu }; // magenta = easy to spot
        fileMipCount = 1;
    }

    // Apply requested dimensions (0 / D3DX_DEFAULT = keep source)
    uint32_t w = (reqWidth  == 0 || reqWidth  == 0xFFFFFFFF) ? img.width  : reqWidth;
    uint32_t h = (reqHeight == 0 || reqHeight == 0xFFFFFFFF) ? img.height : reqHeight;

    // Very simple nearest-neighbor resize if dimensions differ from source
    if ((w != img.width || h != img.height) && img.width > 0 && img.height > 0) {
        DecodedImage resized;
        resized.width = w;
        resized.height = h;
        resized.pixels.resize(w * h);
        for (uint32_t y = 0; y < h; y++) {
            uint32_t sy = y * img.height / h;
            for (uint32_t x = 0; x < w; x++) {
                uint32_t sx = x * img.width / w;
                resized.pixels[y * w + x] = img.pixels[sy * img.width + sx];
            }
        }
        img = std::move(resized);
    }

    // Mip count: 0 means full chain
    uint32_t mips = reqMips;
    if (mips == 0) {
        mips = 1 + Log2Floor(std::max(w, h));
    }
    // Prefer file-embedded mip count if it was larger (e.g. DDS)
    if (fileMipCount > mips) mips = fileMipCount;

    uint32_t texAddr = BuildGuestTexture(base, img, mips);

    DumpTextureToPNG(img, "inmemory");

    // Fill optional pSrcInfo (D3DXIMAGE_INFO — 6 DWORDs)
    if (pSrcInfo != 0) {
        X86_MEM_WRITE_u32(base, pSrcInfo + 0,  img.width);      // Width
        X86_MEM_WRITE_u32(base, pSrcInfo + 4,  img.height);     // Height
        X86_MEM_WRITE_u32(base, pSrcInfo + 8,  1);              // Depth
        X86_MEM_WRITE_u32(base, pSrcInfo + 12, mips);           // MipLevels
        X86_MEM_WRITE_u32(base, pSrcInfo + 16, X_D3DFMT_A8R8G8B8); // Format
        X86_MEM_WRITE_u32(base, pSrcInfo + 20, X_D3DRTYPE_TEXTURE); // ResourceType
    }

    if (ppTexture != 0)
        X86_MEM_WRITE_u32(base, ppTexture, texAddr);

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 60);
}

// D3DXCreateTextureFromFileExA  (0xA885E) — 14 args, ret 56
//
// Args (Xbox D3D8 / D3DX8 — stdcall):
//   [0]  pDevice
//   [1]  pSrcFile     — guest pointer to null-terminated filename (Xbox path)
//   [2]  Width
//   [3]  Height
//   [4]  MipLevels
//   [5]  Usage
//   [6]  Format
//   [7]  Pool
//   [8]  Filter
//   [9]  MipFilter
//   [10] ColorKey
//   [11] pSrcInfo     — [out]
//   [12] pPalette     — [out]
//   [13] ppTexture    — [out]
void D3DXCreateTextureFromFileExA(X86Context& ctx, uint8_t* base)
{
    uint32_t pFilename = GuestArg32(ctx, base, 1);
    uint32_t reqWidth  = GuestArg32(ctx, base, 2);
    uint32_t reqHeight = GuestArg32(ctx, base, 3);
    uint32_t reqMips   = GuestArg32(ctx, base, 4);
    uint32_t pSrcInfo  = GuestArg32(ctx, base, 11);
    uint32_t ppTexture = GuestArg32(ctx, base, 13);

    std::string xboxFilename;
    if (pFilename != 0)
        xboxFilename = reinterpret_cast<const char*>(base + pFilename);

    fprintf(stderr, "[HLE] D3DXCreateTextureFromFileExA(\"%s\", w=%u, h=%u, mips=%u)\n",
            xboxFilename.c_str(), reqWidth, reqHeight, reqMips);

    // Read the file from host filesystem
    std::filesystem::path hostPath = TranslateXboxPath(xboxFilename);
    std::vector<uint8_t> fileData;

    {
        std::ifstream file(hostPath, std::ios::binary | std::ios::ate);
        if (!file.is_open()) {
            fprintf(stderr, "[HLE]   FAILED to open \"%s\" -> host \"%s\"\n",
                    xboxFilename.c_str(), hostPath.string().c_str());

            // Create a 1x1 magenta fallback
            DecodedImage fallback;
            fallback.width = 1;
            fallback.height = 1;
            fallback.pixels = { 0xFFFF00FFu };
            uint32_t texAddr = BuildGuestTexture(base, fallback, 1);
            if (ppTexture != 0)
                X86_MEM_WRITE_u32(base, ppTexture, texAddr);
            GuestReturn32(ctx, 0x80004005u); // E_FAIL
            GuestStackCleanup(ctx, 56);
            return;
        }

        auto fileSize = file.tellg();
        if (fileSize <= 0 || fileSize > 64 * 1024 * 1024) { // 64 MB sanity limit
            fprintf(stderr, "[HLE]   file too large or empty (%lld bytes)\n", (long long)fileSize);
            DecodedImage fallback;
            fallback.width = 1;
            fallback.height = 1;
            fallback.pixels = { 0xFFFF00FFu };
            uint32_t texAddr = BuildGuestTexture(base, fallback, 1);
            if (ppTexture != 0)
                X86_MEM_WRITE_u32(base, ppTexture, texAddr);
            GuestReturn32(ctx, 0x80004005u);
            GuestStackCleanup(ctx, 56);
            return;
        }

        fileData.resize(static_cast<size_t>(fileSize));
        file.seekg(0);
        file.read(reinterpret_cast<char*>(fileData.data()), fileSize);
    }

    fprintf(stderr, "[HLE]   loaded %zu bytes from \"%s\"\n",
            fileData.size(), hostPath.string().c_str());

    // Parse the image
    DecodedImage img;
    uint32_t fileMipCount = 1;
    bool ok = ParseImage(fileData.data(), fileData.size(), img, fileMipCount);

    if (!ok) {
        fprintf(stderr, "[HLE]   image parse FAILED — creating 1x1 magenta fallback\n");
        img.width = 1;
        img.height = 1;
        img.pixels = { 0xFFFF00FFu };
        fileMipCount = 1;
    }

    // Apply requested dimensions
    uint32_t w = (reqWidth  == 0 || reqWidth  == 0xFFFFFFFF) ? img.width  : reqWidth;
    uint32_t h = (reqHeight == 0 || reqHeight == 0xFFFFFFFF) ? img.height : reqHeight;

    if ((w != img.width || h != img.height) && img.width > 0 && img.height > 0) {
        DecodedImage resized;
        resized.width = w;
        resized.height = h;
        resized.pixels.resize(w * h);
        for (uint32_t y = 0; y < h; y++) {
            uint32_t sy = y * img.height / h;
            for (uint32_t x = 0; x < w; x++) {
                uint32_t sx = x * img.width / w;
                resized.pixels[y * w + x] = img.pixels[sy * img.width + sx];
            }
        }
        img = std::move(resized);
    }

    uint32_t mips = reqMips;
    if (mips == 0) mips = 1 + Log2Floor(std::max(w, h));
    if (fileMipCount > mips) mips = fileMipCount;

    uint32_t texAddr = BuildGuestTexture(base, img, mips);

    DumpTextureToPNG(img, xboxFilename.c_str());

    if (pSrcInfo != 0) {
        X86_MEM_WRITE_u32(base, pSrcInfo + 0,  img.width);
        X86_MEM_WRITE_u32(base, pSrcInfo + 4,  img.height);
        X86_MEM_WRITE_u32(base, pSrcInfo + 8,  1);
        X86_MEM_WRITE_u32(base, pSrcInfo + 12, mips);
        X86_MEM_WRITE_u32(base, pSrcInfo + 16, X_D3DFMT_A8R8G8B8);
        X86_MEM_WRITE_u32(base, pSrcInfo + 20, X_D3DRTYPE_TEXTURE);
    }

    if (ppTexture != 0)
        X86_MEM_WRITE_u32(base, ppTexture, texAddr);

    GuestReturn32(ctx, 0); // S_OK
    GuestStackCleanup(ctx, 56);
}

// ============================================================================
// Burnout 3 D3D segment stubs — auto-generated from d3d.txt
// Functions not yet implemented get a one-shot log + stack cleanup.
// ============================================================================

void D3D_CleanPrivateData(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CleanPrivateData (0x0034C700) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_InternalReleaseSurface(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_InternalReleaseSurface (0x0034C800) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3DResource_IsBusy(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DResource_IsBusy (0x0034C970) called\n"); logged = true; }
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

void D3DResource_BlockUntilNotBusy(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DResource_BlockUntilNotBusy (0x0034CA00) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_PixelJar_GetPitch(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_PixelJar_GetPitch (0x0034CA10) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_PixelJar_GetSlice(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_PixelJar_GetSlice (0x0034CA70) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_SetRenderTargetFast(X86Context& ctx, uint8_t* base) {
    uint32_t pRT = GuestArg32(ctx, base, 0);
    //fprintf(stderr, "[HLE] D3DDevice_SetRenderTargetFast(pRT=0x%08X)\n", pRT);
    if (pRT != 0) {
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, pRT);
    }
    GuestStackCleanup(ctx, 4);
}

void D3DDevice_CopyRects(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_CopyRects (0x0034D060) called\n"); logged = true; }
    GuestStackCleanup(ctx, 20);
}

// D3DDevice_GetRenderTarget2  (0x34D390) — 0 args, plain ret
// Returns the current render target surface in EAX, increments its refcount.
void D3DDevice_GetRenderTarget2(X86Context& ctx, uint8_t* base) {
    uint32_t surfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
    if (surfAddr == 0)
        surfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);

    if (surfAddr != 0) {
        // Increment refcount (lower 16 bits of Common field)
        uint32_t common = X86_MEM_READ_u32(base, surfAddr + 0);
        common = (common & ~X_D3DCOMMON_REFCOUNT_MASK)
               | (((common & X_D3DCOMMON_REFCOUNT_MASK) + 1) & X_D3DCOMMON_REFCOUNT_MASK);
        X86_MEM_WRITE_u32(base, surfAddr + 0, common);
    }

    fprintf(stderr, "[HLE] D3DDevice_GetRenderTarget2() -> 0x%08X\n", surfAddr);
    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_SetMaterial(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_SetMaterial (0x0034D750) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3DDevice_SetLight(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_SetLight (0x0034D780) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3DDevice_LightEnable(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_LightEnable (0x0034DB40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3DDevice_SetPalette(X86Context& ctx, uint8_t* base) {
    uint32_t stage    = GuestArg32(ctx, base, 0);
    uint32_t pPalette = GuestArg32(ctx, base, 1);
    if (stage < 4)
        X86_MEM_WRITE_u32(base, kDeviceAddr + kDevicePaletteBase + stage * 4, pPalette);
    GuestStackCleanup(ctx, 8);
}

// Forward declaration (defined later in this file)
void D3D_CDevice_UnInit(X86Context& ctx, uint8_t* base);

// D3DDevice_Release  (0x34DF00) — 0 args, plain ret
// Decrements device refcount.  If it reaches 1, calls D3D_CDevice_UnInit
// and zeros the device block (original behaviour from the recompiled code).
void D3DDevice_Release(X86Context& ctx, uint8_t* base) {
    uint32_t devPtr = kDeviceAddr;
    uint32_t refCount = X86_MEM_READ_u32(base, devPtr + 0x938);
    fprintf(stderr, "[HLE] D3DDevice_Release() refCount=%u\n", refCount);

    if (refCount <= 1) {
        // Full teardown: call CDevice_UnInit and zero device memory
        D3D_CDevice_UnInit(ctx, base);
        memset(base + devPtr, 0, 0x938 * 4);
        X86_MEM_WRITE_u32(base, kDevicePtrAddr, 0);
    } else {
        X86_MEM_WRITE_u32(base, devPtr + 0x938, refCount - 1);
    }
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_BeginVisibilityTest(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_BeginVisibilityTest (0x0034DF40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_GetVisibilityAddress(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_GetVisibilityAddress (0x0034DF80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_EndVisibilityTest(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_EndVisibilityTest (0x0034DFE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_GetVisibilityTestResult(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_GetVisibilityTestResult (0x0034E040) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3DDevice_GetDisplayFieldStatus(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_GetDisplayFieldStatus (0x0034E0A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_D3DInternals(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_D3DInternals (0x0034E530) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3DDevice_DeletePixelShader(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_DeletePixelShader (0x0034E770) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_SetPixelShaderConstant  (0x34E9A0) — LTCG calling convention:
//   ECX = Register (start constant index, 0-based; 0..15)
//   EAX = ConstantCount (number of float4 vectors)
//   stack[0] = pConstantData (guest pointer to float4 array)
//
// Based on Cxbx-Reloaded D3DDevice_SetPixelShaderConstant_4 (LTCG ecx/eax
// variant).  On Xbox these map to the 16 pixel-shader constant render
// states (X_D3DRS_PSCONSTANT0_0..7 + X_D3DRS_PSCONSTANT1_0..7).  Our
// translated PS reads them from cbuffer psC[0..15] — the draw path
// (HLE_Draw3D) uploads g_pshConstants[] into cbPS just before PSSetShader.
void D3DDevice_SetPixelShaderConstant(X86Context& ctx, uint8_t* base) {
    uint32_t regStart = ctx.ecx;
    uint32_t count    = ctx.eax;                 // number of float4 vectors
    uint32_t pData    = GuestArg32(ctx, base, 0); // guest pointer to float4 data

    if (pData != 0 && count > 0 && regStart < 16) {
        uint32_t copyCount = count;
        if (regStart + copyCount > 16)
            copyCount = 16 - regStart;
        memcpy(&g_pshConstants[regStart][0], base + pData, copyCount * 16);
        for (uint32_t i = 0; i < copyCount; ++i)
            g_pshConstantsDirty |= (1u << (regStart + i));
    }

    GuestStackCleanup(ctx, 4);
}

void D3D_InitializeVertexShaderFromFvf(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_InitializeVertexShaderFromFvf (0x0034EC70) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_ShadowVertexShaderState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ShadowVertexShaderState (0x0034EE40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_ParseProgram(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ParseProgram (0x0034EEF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3D_ParseDeclarationStream(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ParseDeclarationStream (0x0034F1A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3D_ParseDeclarationConstants(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ParseDeclarationConstants (0x0034F340) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_DeleteVertexShader  (0x34F590) — 1 arg, ret 4
// On the real Xbox the handle points to a D3DVertexShader struct with a
// refcount at handle-1.  Our CreateVertexShader gives opaque dummy handles
// (0xFFFE0000+) so there is nothing to free.
void D3DDevice_DeleteVertexShader(X86Context& ctx, uint8_t* base) {
    uint32_t handle = GuestArg32(ctx, base, 0);
    fprintf(stderr, "[HLE] D3DDevice_DeleteVertexShader(handle=0x%08X)\n", handle);
    GuestStackCleanup(ctx, 4);
}

// D3D_CommonSetPassthroughProgram  (0x34F5B0) — no stack args, plain ret
//
// Internal helper: programs the NV2A to use the fixed-function passthrough
// vertex program (screen-space 2D rendering).  In our HLE the 2D vs 3D
// pipeline switch is driven by the draw call itself, so this is a no-op.
void D3D_CommonSetPassthroughProgram(X86Context& ctx, uint8_t* base) {
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Vertex-shader constant capture
// ============================================================================
// All four SetVertexShaderConstant* entry points are Xbox __fastcall:
//   ECX = register index (NV2A slot, already biased by the SDK)
//   EDX = pointer to constant data in guest memory
// "NotInlineFast" additionally takes a count (in DWORDs) as a stack arg.
// We mirror every upload into g_vshConstants[] (host) and 0x35FDF8+reg*16
// (guest shadow, so any code reading back from there still works).

static inline void CaptureVshConstants(uint8_t* base, uint32_t reg,
                                        uint32_t pData, uint32_t count4s)
{
    if (pData == 0 || count4s == 0) return;
    const float* src = reinterpret_cast<const float*>(base + pData);
    uint32_t dstMax  = (reg + count4s > 192) ? (192 - reg) : count4s;
    if (reg < 192 && dstMax > 0) {
        memcpy(g_vshConstants[reg], src, dstMax * 16);
        // Also mirror into guest shadow
        memcpy(base + kVshConstantShadow + reg * 16, src, dstMax * 16);
    }
    static int s_logCap = 0;
    // Track first-write per register so we see EVERY distinct slot the game
    // touches without flooding the log.
    static bool s_seen[192] = {};
    bool firstSeen = (reg < 192) && !s_seen[reg];
    if (firstSeen) s_seen[reg] = true;
    bool touchesMvp = (reg < 116) && (reg + count4s > 112);

    // MVP-targeted diagnostic: log EVERY upload that overlaps c[112..115]
    // where at least one float is non-zero, tracking distinct (source-addr,
    // first-row-hash) tuples so we can identify any real MVP buffer beyond
    // the known-dead 0x004D6730. Cap at ~32 distinct tuples to bound log.
    if (touchesMvp) {
        bool anyNonZero = false;
        for (uint32_t i = 0; i < dstMax * 4; i++) {
            if (src[i] != 0.0f) { anyNonZero = true; break; }
        }
        if (anyNonZero) {
            uint64_t h = 1469598103934665603ull;
            const uint32_t* pw = reinterpret_cast<const uint32_t*>(src);
            for (uint32_t i = 0; i < dstMax * 4; i++) { h ^= pw[i]; h *= 1099511628211ull; }
            struct MvpSeen { uint32_t srcAddr; uint64_t hash; uint32_t count; };
            static std::vector<MvpSeen> s_mvpSeen;
            bool novel = true;
            for (auto& ms : s_mvpSeen) {
                if (ms.srcAddr == pData && ms.hash == h) { ms.count++; novel = false; break; }
            }
            if (novel && s_mvpSeen.size() < 32) {
                s_mvpSeen.push_back({pData, h, 1});
                fprintf(stderr, "[HLE] **MVP-UPLOAD** reg=%u cnt=%u src=0x%08X  (distinct=%u)\n",
                        reg, count4s, pData, (uint32_t)s_mvpSeen.size());
                for (uint32_t i = 0; i < dstMax && i < 4; i++) {
                    fprintf(stderr, "       row%u c[%u] = [%.4f %.4f %.4f %.4f]\n",
                            i, reg + i, src[i*4+0], src[i*4+1], src[i*4+2], src[i*4+3]);
                }
            }
        }
    }
    if (firstSeen || touchesMvp || s_logCap < 32) {
        // fprintf(stderr, "[HLE] VshConst reg=%u count=%u src=0x%08X first=[%.3f %.3f %.3f %.3f]%s%s\n",
        //         reg, count4s, pData, src[0], src[1], src[2], src[3],
        //         touchesMvp ? "  <-- MVP range" : "",
        //         firstSeen ? "  (FIRST)" : "");
        // Dump full payload the FIRST time we see a multi-vec4 write so we
        // can sanity-check whether "the matrix is really zero" or whether
        // only row0 happens to be zero.
        if (firstSeen && count4s >= 2) {
            for (uint32_t i = 0; i < count4s; i++) {
                fprintf(stderr, "       row%u c[%u] = [%.4f %.4f %.4f %.4f]\n",
                        i, reg + i, src[i*4+0], src[i*4+1], src[i*4+2], src[i*4+3]);
            }
        }
        s_logCap++;
    }
}

void D3DDevice_SetVertexShaderConstant1(X86Context& ctx, uint8_t* base) {
    CaptureVshConstants(base, ctx.ecx, ctx.edx, 1);
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_SetVertexShaderConstant1Fast(X86Context& ctx, uint8_t* base) {
    CaptureVshConstants(base, ctx.ecx, ctx.edx, 1);
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_SetVertexShaderConstant4(X86Context& ctx, uint8_t* base) {
    CaptureVshConstants(base, ctx.ecx, ctx.edx, 4);
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetVertexShaderConstantNotInlineFast  (0x34F9A0) — __fastcall:
//   ECX = Register (start slot index), EDX = pConstantData, arg0 = ConstantCount
//
// Based on Cxbx-Reloaded: copies constant data into the NV2A push buffer.
// Since we don't render, we write the data to the push buffer area in
// guest memory so that any code reading the push buffer back sees valid data,
// and advance the write pointer correctly.
void D3DDevice_SetVertexShaderConstantNotInlineFast(X86Context& ctx, uint8_t* base) {
    uint32_t reg       = ctx.ecx;
    uint32_t pData     = ctx.edx;
    uint32_t count     = GuestArg32(ctx, base, 0); // count in DWORDs

    // Capture into host + guest shadow so the 3D pipeline + game readbacks
    // both see the new values. count is in DWORDs; each float4 is 4 DWORDs.
    CaptureVshConstants(base, reg, pData, count / 4);

    // NOTE: we intentionally do NOT emit these writes into the NV2A push
    // buffer. The on-ring format requires a NV2A_VP_UPLOAD_CONST_ID header
    // (0x41EA4) followed by a NV2A_VP_UPLOAD_CONST(0) header
    // (0x00B80 | (count << 18)) before the float payload, and our inline
    // Fast paths already do this correctly. Duplicating here without the
    // second header corrupts the ring and breaks the push-buffer walker.

    GuestStackCleanup(ctx, 4);
}

// D3D_CreateSurfaceOfTexture  (0x34FA80) — 2 stack args, ret 8
//
// Allocates a 24-byte X_D3DSurface header and links it to a parent texture.
//
// Register inputs:
//   EAX = data address   (physical address of this mip level's pixel data)
//   EDI = parent texture  (X_D3DPixelContainer*)
// Stack args:
//   arg0 = Format DWORD  (for this mip level)
//   arg1 = Size DWORD    (for this mip level)
//
// Returns the new surface pointer in EAX (via ECX in the original code).
void D3D_CreateSurfaceOfTexture(X86Context& ctx, uint8_t* base) {
    uint32_t dataAddr = ctx.eax;
    uint32_t pParent  = ctx.edi;
    uint32_t fmtDword = GuestArg32(ctx, base, 0);
    uint32_t sizeDword = GuestArg32(ctx, base, 1);

    uint32_t surfAddr = ContigAlloc(24, 64);

    // X_D3DSurface layout: Common, Data, Lock, Format, Size, Parent
    X86_MEM_WRITE_u32(base, surfAddr + 0x00,
                      1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED);
    X86_MEM_WRITE_u32(base, surfAddr + 0x04, dataAddr & 0x0FFFFFFF);
    X86_MEM_WRITE_u32(base, surfAddr + 0x08, 0);          // Lock
    X86_MEM_WRITE_u32(base, surfAddr + 0x0C, fmtDword);   // Format
    X86_MEM_WRITE_u32(base, surfAddr + 0x10, sizeDword);   // Size
    X86_MEM_WRITE_u32(base, surfAddr + 0x14, pParent);     // Parent

    // Increment parent's refcount
    if (pParent != 0) {
        uint32_t common = X86_MEM_READ_u32(base, pParent + 0);
        common = (common & ~X_D3DCOMMON_REFCOUNT_MASK)
               | (((common & X_D3DCOMMON_REFCOUNT_MASK) + 1) & X_D3DCOMMON_REFCOUNT_MASK);
        X86_MEM_WRITE_u32(base, pParent + 0, common);
    }

    fprintf(stderr, "[HLE] D3D_CreateSurfaceOfTexture(data=0x%08X, parent=0x%08X) -> 0x%08X\n",
            dataAddr, pParent, surfAddr);

    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_CreateSurface2  (0x34FAF0) — 4 args, ret 16
//
// Creates a standalone surface (no parent texture).
//
// Stack args:
//   arg0 = width
//   arg1 = height
//   arg2 = (unused / type)
//   arg3 = format code
//
// Returns the new surface pointer in EAX.
void D3DDevice_CreateSurface2(X86Context& ctx, uint8_t* base) {
    uint32_t width  = GuestArg32(ctx, base, 0);
    uint32_t height = GuestArg32(ctx, base, 1);
    uint32_t format = GuestArg32(ctx, base, 3);

    uint8_t  fmtInfo  = XboxFormatInfo(format);
    uint32_t bppField = fmtInfo & 0x3C;
    bool     isDXT    = IsCompressedFormat(format);

    if (width  == 0) width  = 1;
    if (height == 0) height = 1;

    // Calculate pitch (64-byte aligned)
    uint32_t pitch;
    if (isDXT) {
        uint32_t bw = (width + 3) / 4;
        pitch = bw * ((format == 0x0C) ? 8 : 16);
    } else {
        pitch = bppField * width / 8;
    }
    pitch = (pitch + 63) & ~63u;
    if (pitch == 0) pitch = 64;

    uint32_t rowCount = isDXT ? ((height + 3) / 4) : height;
    uint32_t dataSize = pitch * rowCount;

    // Encode Format and Size DWORDs
    uint32_t logU = Log2Ceil(width);
    uint32_t logV = Log2Ceil(height);

    uint32_t fmtDword = (1 << 4)              // dim = 1 (2D)
                       | (format << X_D3DFORMAT_FORMAT_SHIFT)
                       | ((logU & 0xF) << X_D3DFORMAT_USIZE_SHIFT)
                       | ((logV & 0xF) << X_D3DFORMAT_VSIZE_SHIFT);

    uint32_t pitchLog = (pitch >= 64) ? (pitch / 64 - 1) : 0;
    uint32_t sizeDword = ((width  - 1) & X_D3DSIZE_WIDTH_MASK)
                       | (((height - 1) & 0xFFF) << X_D3DSIZE_HEIGHT_SHIFT)
                       | ((pitchLog & 0xFF) << X_D3DSIZE_PITCH_SHIFT);

    // Allocate surface header (24 bytes) and pixel data
    uint32_t surfAddr = ContigAlloc(24, 64);
    uint32_t pixAddr  = ContigAlloc(dataSize, 128);
    memset(base + pixAddr, 0, dataSize);

    X86_MEM_WRITE_u32(base, surfAddr + 0x00,
                      1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED | 0x80000000);
    X86_MEM_WRITE_u32(base, surfAddr + 0x04, pixAddr & 0x0FFFFFFF);
    X86_MEM_WRITE_u32(base, surfAddr + 0x08, 0);           // Lock
    X86_MEM_WRITE_u32(base, surfAddr + 0x0C, fmtDword);    // Format
    X86_MEM_WRITE_u32(base, surfAddr + 0x10, sizeDword);    // Size
    X86_MEM_WRITE_u32(base, surfAddr + 0x14, 0);           // Parent = null

    fprintf(stderr, "[HLE] D3DDevice_CreateSurface2(%ux%u, fmt=0x%X) -> 0x%08X (data=0x%08X, %u bytes)\n",
            width, height, format, surfAddr, pixAddr, dataSize);

    GuestReturn32(ctx, surfAddr);
    GuestStackCleanup(ctx, 16);
}

void D3D_MMXMemCpyDwordBlock(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_MMXMemCpyDwordBlock (0x0034FCF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

// ---- Minimal software triangle rasterizer for 2D pre-transformed verts ----
// Xbox NV2A primitive types used by RenderWare im2d
static constexpr uint32_t NV2A_PRIM_TRIANGLES = 5;
static constexpr uint32_t NV2A_PRIM_TRISTRIP  = 6;
static constexpr uint32_t NV2A_PRIM_TRIFAN    = 7;
static constexpr uint32_t NV2A_PRIM_QUADS     = 8;
static constexpr uint32_t NV2A_PRIM_QUADSTRIP = 9;

// ============================================================================
// D3D11 texture helpers
// ============================================================================

// Morton/Z-order unswizzle for power-of-2 Xbox textures
static void UnswizzleTexture(const uint8_t* src, uint8_t* dst,
                              uint32_t w, uint32_t h, uint32_t bytesPerPixel)
{
    uint32_t logW = 0, logH = 0;
    for (uint32_t t = w; t > 1; t >>= 1) logW++;
    for (uint32_t t = h; t > 1; t >>= 1) logH++;
    uint32_t minLog = (logW < logH) ? logW : logH;
    for (uint32_t y = 0; y < h; y++) {
        for (uint32_t x = 0; x < w; x++) {
            uint32_t off = 0, shift = 0;
            for (uint32_t i = 0; i < minLog; i++) {
                off |= ((x >> i) & 1u) << shift++;
                off |= ((y >> i) & 1u) << shift++;
            }
            if (logW > logH)
                for (uint32_t i = minLog; i < logW; i++)
                    off |= ((x >> i) & 1u) << shift++;
            else
                for (uint32_t i = minLog; i < logH; i++)
                    off |= ((y >> i) & 1u) << shift++;
            memcpy(dst + (y * w + x) * bytesPerPixel,
                   src + off        * bytesPerPixel, bytesPerPixel);
        }
    }
}

// Look up or create a D3D11 SRV for an Xbox texture at xboxTexAddr.
// Returns nullptr if the texture cannot be decoded/uploaded.
static ID3D11ShaderResourceView* GetOrCreateTextureSRV(uint8_t* base, uint32_t xboxTexAddr);

// Resolve the currently bound stage-`stage` texture from the push-buffer-
// shadowed NV2A state. RenderWare in Burnout 3 writes SET_TEXTURE_* methods
// directly into the pushbuffer instead of using D3DDevice_SetTexture, so
// the high-level kDeviceAddr+0x0B00 slot is stale for many draws.
//
// We synthesize an Xbox-format texture header from the NV2A state the first
// time we see a given GPU offset, stash the header in the guest contiguous
// pool, and hand that synthetic header to GetOrCreateTextureSRV. The SRV is
// then cached the normal way (keyed by the synthetic header address).
static ID3D11ShaderResourceView* ResolveNV2ATextureSRV(uint8_t* base, uint32_t stage)
{
    if (stage >= 4) return nullptr;
    const NV2ATextureState& st = g_nv2aTexture[stage];
    if (st.offset == 0 || st.format == 0) return nullptr;

    // NV097_SET_TEXTURE_FORMAT matches the Xbox X_D3DFORMAT layout 1:1
    // (colour code at bits 8..15, logU/V at 20..27, mipmap at 16..19) — the
    // SDK literally copies header->fmtField into the pushbuffer method.
    uint32_t fmt  = st.format;
    uint32_t xFmt = (fmt >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

    auto isLinear = [](uint32_t f) {
        switch (f) {
        case 0x0D: case 0x10: case 0x11: case 0x12: case 0x13:
        case 0x16: case 0x17: case 0x19: case 0x1A: case 0x1C:
        case 0x1D: case 0x1E: return true;
        default: return false;
        }
    };

    uint32_t sizeField = 0;
    if (isLinear(xFmt) && st.imageRect != 0) {
        // NV097 image-rect = (width << 16) | height (absolute, not -1).
        uint32_t w = (st.imageRect >> 16) & 0xFFFF;
        uint32_t h = (st.imageRect >>  0) & 0xFFFF;
        if (w == 0 || h == 0 || w > 4096 || h > 4096) return nullptr;
        uint32_t pitch = (st.control1 >> 16) & 0xFFFF;
        uint32_t pitch64 = pitch ? (pitch / 64) : 1;
        sizeField = ((w - 1) & X_D3DSIZE_WIDTH_MASK)
                  | (((h - 1) << X_D3DSIZE_HEIGHT_SHIFT) & X_D3DSIZE_HEIGHT_MASK)
                  | ((((pitch64 - 1) & 0xFF)) << X_D3DSIZE_PITCH_SHIFT);
    }

    uint32_t dataAddr = st.offset & 0x0FFFFFFF;
    if (dataAddr == 0) return nullptr;

    // Allocate one synthetic header per (dataAddr, fmt, sizeField) so the
    // downstream cache keyed on header-address never thrashes.
    struct NvKey { uint32_t a, b, c; };
    struct H { size_t operator()(const NvKey& k) const noexcept {
        return std::hash<uint64_t>()((uint64_t)k.a ^ ((uint64_t)k.b << 1) ^ ((uint64_t)k.c << 33));
    }};
    struct E { bool operator()(const NvKey& a, const NvKey& b) const noexcept {
        return a.a == b.a && a.b == b.b && a.c == b.c;
    }};
    static std::unordered_map<NvKey, uint32_t, H, E> s_hdrMap;

    NvKey key{ dataAddr, fmt, sizeField };
    auto it = s_hdrMap.find(key);
    uint32_t hdrAddr;
    if (it != s_hdrMap.end()) {
        hdrAddr = it->second;
    } else {
        hdrAddr = ContigAlloc(20, 4);
        if (hdrAddr == 0) return nullptr;
        X86_MEM_WRITE_u32(base, hdrAddr + 0,
                          1 | X_D3DCOMMON_TYPE_TEXTURE | X_D3DCOMMON_D3DCREATED);
        X86_MEM_WRITE_u32(base, hdrAddr + 4,  dataAddr);
        X86_MEM_WRITE_u32(base, hdrAddr + 8,  0);
        X86_MEM_WRITE_u32(base, hdrAddr + 12, fmt);
        X86_MEM_WRITE_u32(base, hdrAddr + 16, sizeField);
        s_hdrMap.emplace(key, hdrAddr);
    }

    return GetOrCreateTextureSRV(base, hdrAddr);
}

// Look up or create a D3D11 SRV for an Xbox texture at xboxTexAddr.
// Returns nullptr if the texture cannot be decoded/uploaded.
static ID3D11ShaderResourceView* GetOrCreateTextureSRV(uint8_t* base, uint32_t xboxTexAddr)
{
    if (!g_d3d11.initialized || xboxTexAddr == 0) return nullptr;

    uint32_t dataAddr  = X86_MEM_READ_u32(base, xboxTexAddr + 4);
    uint32_t fmtField  = X86_MEM_READ_u32(base, xboxTexAddr + 12);
    uint32_t sizeField = X86_MEM_READ_u32(base, xboxTexAddr + 16);
    if (dataAddr == 0) return nullptr;

    uint32_t xFmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

    // Cache check: key = xboxTexAddr, validate by (dataAddr, xFmt)
    auto it = g_d3d11.textureCache.find(xboxTexAddr);
    if (it != g_d3d11.textureCache.end()) {
        auto& e = it->second;
        if (e.xboxDataAddr == dataAddr && e.xboxFmtCode == xFmt && e.srv)
            return e.srv;
        if (e.texture) { e.texture->Release(); e.texture = nullptr; }
        if (e.srv)     { e.srv->Release();     e.srv     = nullptr; }
    }

    // Determine dimensions
    uint32_t texW, texH;
    bool swizzled;
    if (sizeField != 0) {
        texW     = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        texH     = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
        swizzled = false;
    } else {
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        texW     = 1u << logU;
        texH     = 1u << logV;
        // Linear (non-swizzled) format codes — LIN_* variants and any texture
        // whose format code indicates it is stored row-major in memory.
        static constexpr uint32_t kLinearFmts[] = {
            0x0D,                    // LIN_DXT1
            0x10,                    // LIN_A1R5G5B5
            0x11,                    // LIN_R5G6B5
            X_D3DFMT_LIN_A8R8G8B8,  // 0x12
            0x13,                    // LIN_L8
            0x16,                    // LIN_R8B8
            0x17,                    // LIN_G8B8
            0x19,                    // LIN_A8
            0x1A,                    // LIN_AL8
            0x1C,                    // LIN_R5G6B5 (alt)
            0x1D,                    // LIN_A1R5G5B5 (alt)
            X_D3DFMT_LIN_X8R8G8B8,  // 0x1E
        };
        swizzled = true;
        for (uint32_t lf : kLinearFmts) {
            if (xFmt == lf) { swizzled = false; break; }
        }
    }
    if (texW == 0 || texH == 0 || texW > 4096 || texH > 4096) return nullptr;

    DXGI_FORMAT dxgiFmt = DXGI_FORMAT_B8G8R8A8_UNORM;
    bool isAlphaOnly = false;
    bool nativeDXT   = false;
    switch (xFmt) {
    case X_D3DFMT_DXT1: case 0x0D:
        dxgiFmt = DXGI_FORMAT_BC1_UNORM; nativeDXT = true; break;
    case X_D3DFMT_DXT3:
        dxgiFmt = DXGI_FORMAT_BC2_UNORM; nativeDXT = true; break;
    case X_D3DFMT_DXT5:
        dxgiFmt = DXGI_FORMAT_BC3_UNORM; nativeDXT = true; break;
    case 0x00: case 0x01: case 0x19:   // L8, AL8, A8
        dxgiFmt = DXGI_FORMAT_B8G8R8A8_UNORM; isAlphaOnly = true; break;
    default:
        dxgiFmt = DXGI_FORMAT_B8G8R8A8_UNORM; break;
    }

    // Build upload buffer
    std::vector<uint8_t> buf;
    uint32_t uploadPitch;

    if (nativeDXT) {
        uint32_t blockSize = (xFmt == X_D3DFMT_DXT1 || xFmt == 0x0D) ? 8u : 16u;
        uint32_t bw = (texW + 3) / 4;
        uint32_t bh = (texH + 3) / 4;
        uploadPitch = bw * blockSize;
        buf.resize((size_t)bh * uploadPitch);
        // Xbox DXT textures are always stored linearly in memory — the NV2A
        // does not support swizzled DXT (there is no "LIN_DXT3"/"LIN_DXT5"
        // format code for this reason). Copy as-is.
        memcpy(buf.data(), base + dataAddr, buf.size());
    } else {
        // Decode to B8G8R8A8_UNORM
        uploadPitch = texW * 4;
        buf.resize((size_t)texH * uploadPitch);
        uint32_t* dst32 = reinterpret_cast<uint32_t*>(buf.data());

        // For swizzled textures, unswizzle to a temp buffer first
        uint32_t srcBpp = 4;
        switch (xFmt) {
        case X_D3DFMT_R5G6B5: case 0x1C: case X_D3DFMT_A1R5G5B5: case 0x1D:
        case X_D3DFMT_A4R4G4B4:
        case 0x03: // X1R5G5B5
            srcBpp = 2; break;
        case 0x00: case 0x01: case 0x19: case X_D3DFMT_P8:
            srcBpp = 1; break;
        default:
            srcBpp = 4; break;
        }

        std::vector<uint8_t> tmp;
        const uint8_t* src = base + dataAddr;
        if (swizzled) {
            tmp.resize((size_t)texW * texH * srcBpp);
            UnswizzleTexture(src, tmp.data(), texW, texH, srcBpp);
            src = tmp.data();
        }

        // Resolve palette for P8
        const uint32_t* palette = nullptr;
        if (xFmt == X_D3DFMT_P8) {
            uint32_t pPal = X86_MEM_READ_u32(base, kDeviceAddr + kDevicePaletteBase);
            if (pPal != 0) {
                uint32_t palData = X86_MEM_READ_u32(base, pPal + 4);
                if (palData != 0)
                    palette = reinterpret_cast<const uint32_t*>(base + palData);
            }
        }

        for (uint32_t i = 0; i < texW * texH; i++) {
            uint32_t argb = 0;
            switch (xFmt) {
            case X_D3DFMT_A8R8G8B8:   case X_D3DFMT_LIN_A8R8G8B8:
                argb = reinterpret_cast<const uint32_t*>(src)[i];
                break;
            case X_D3DFMT_X8R8G8B8:   case X_D3DFMT_LIN_X8R8G8B8:
                argb = reinterpret_cast<const uint32_t*>(src)[i] | 0xFF000000u;
                break;
            case X_D3DFMT_R5G6B5: case 0x1C: {
                uint16_t p = reinterpret_cast<const uint16_t*>(src)[i];
                uint32_t r = ((p >> 11) & 0x1Fu) * 255 / 31;
                uint32_t g = ((p >>  5) & 0x3Fu) * 255 / 63;
                uint32_t b = ((p >>  0) & 0x1Fu) * 255 / 31;
                argb = 0xFF000000u | (r << 16) | (g << 8) | b;
                break;
            }
            case X_D3DFMT_A1R5G5B5: case 0x1D: {
                uint16_t p = reinterpret_cast<const uint16_t*>(src)[i];
                uint32_t a = (p & 0x8000u) ? 255u : 0u;
                uint32_t r = ((p >> 10) & 0x1Fu) * 255 / 31;
                uint32_t g = ((p >>  5) & 0x1Fu) * 255 / 31;
                uint32_t b = ((p >>  0) & 0x1Fu) * 255 / 31;
                argb = (a << 24) | (r << 16) | (g << 8) | b;
                break;
            }
            case 0x03: { // X1R5G5B5
                uint16_t p = reinterpret_cast<const uint16_t*>(src)[i];
                uint32_t r = ((p >> 10) & 0x1Fu) * 255 / 31;
                uint32_t g = ((p >>  5) & 0x1Fu) * 255 / 31;
                uint32_t b = ((p >>  0) & 0x1Fu) * 255 / 31;
                argb = 0xFF000000u | (r << 16) | (g << 8) | b;
                break;
            }
            case X_D3DFMT_A4R4G4B4: {
                uint16_t p = reinterpret_cast<const uint16_t*>(src)[i];
                uint32_t a = ((p >> 12) & 0xFu) * 17;
                uint32_t r = ((p >>  8) & 0xFu) * 17;
                uint32_t g = ((p >>  4) & 0xFu) * 17;
                uint32_t b = ((p >>  0) & 0xFu) * 17;
                argb = (a << 24) | (r << 16) | (g << 8) | b;
                break;
            }
            case X_D3DFMT_P8:
                argb = palette ? palette[src[i]] : 0xFFFFFFFFu;
                break;
            case 0x00: case 0x01: { // L8 / AL8 — store luma in alpha, white RGB
                uint8_t l = src[i];
                argb = ((uint32_t)l << 24) | 0x00FFFFFFu;
                break;
            }
            case 0x19: { // A8 — store alpha, white RGB
                uint8_t a = src[i];
                argb = ((uint32_t)a << 24) | 0x00FFFFFFu;
                break;
            }
            default:
                argb = reinterpret_cast<const uint32_t*>(src)[i];
                break;
            }
            // Xbox A8R8G8B8 and D3D11 B8G8R8A8_UNORM share the same byte layout
            // on little-endian: bytes [B,G,R,A] = ARGB uint32 (B at lowest address).
            dst32[i] = argb;
        }
    }

    // Create immutable D3D11 texture
    D3D11_TEXTURE2D_DESC td = {};
    td.Width     = texW;
    td.Height    = texH;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format    = dxgiFmt;
    td.SampleDesc.Count   = 1;
    td.SampleDesc.Quality = 0;
    td.Usage     = D3D11_USAGE_IMMUTABLE;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem     = buf.data();
    initData.SysMemPitch = uploadPitch;

    ID3D11Texture2D* pTex = nullptr;
    HRESULT hr = g_d3d11.device->CreateTexture2D(&td, &initData, &pTex);
    if (FAILED(hr)) {
        fprintf(stderr, "[D3D11] CreateTexture2D failed: 0x%08X (%ux%u fmt=0x%02X)\n",
                hr, texW, texH, xFmt);
        return nullptr;
    }

    ID3D11ShaderResourceView* pSRV = nullptr;
    hr = g_d3d11.device->CreateShaderResourceView(pTex, nullptr, &pSRV);
    if (FAILED(hr)) { pTex->Release(); return nullptr; }

    TextureCacheEntry& ent = g_d3d11.textureCache[xboxTexAddr];
    ent.texture      = pTex;
    ent.srv          = pSRV;
    ent.xboxDataAddr = dataAddr;
    ent.width        = texW;
    ent.height       = texH;
    ent.dxgiFormat   = dxgiFmt;
    ent.xboxFmtCode  = static_cast<uint8_t>(xFmt);
    ent.isAlphaOnly  = isAlphaOnly;

    // Diagnostic: sample a few pixels from the uploaded buffer so we can tell
    // if the Xbox texture data is actually populated (vs still zero from
    // CreateTexture2) and whether our format decode produced meaningful data.
    {
        static int s_upDiag = 0;
        if (s_upDiag < 24) {
            uint32_t p0 = 0, pm = 0, pe = 0;
            size_t bsz = buf.size();
            if (bsz >= 4) {
                p0 = *reinterpret_cast<uint32_t*>(buf.data());
                pm = *reinterpret_cast<uint32_t*>(buf.data() + (bsz / 2 & ~3u));
                pe = *reinterpret_cast<uint32_t*>(buf.data() + bsz - 4);
            }
            // Count how many of the first 256 4-byte words are non-zero.
            int nz = 0, samples = (int)std::min<size_t>(256, bsz / 4);
            for (int i = 0; i < samples; ++i)
                if (reinterpret_cast<uint32_t*>(buf.data())[i] != 0) ++nz;
            fprintf(stderr,
                "[TEXUP] tex=0x%08X data=0x%08X %ux%u xFmt=0x%02X dxgi=%d sw=%d bytes=%zu "
                "p0=0x%08X pm=0x%08X pe=0x%08X nz=%d/%d\n",
                xboxTexAddr, dataAddr, texW, texH, xFmt, (int)dxgiFmt,
                swizzled ? 1 : 0, bsz, p0, pm, pe, nz, samples);
            ++s_upDiag;
        }
    }

    return pSRV;
}

// ============================================================================
// D3D11 back-buffer management
// ============================================================================

static void ReleaseBackBufferResources()
{
    auto R = [](auto*& p){ if (p) { p->Release(); p = nullptr; } };
    R(g_d3d11.backBufferRTV);
    R(g_d3d11.backBufferTex);
    R(g_d3d11.depthDSV);
    R(g_d3d11.depthTex);
}

static void CreateBackBufferResources()
{
    HRESULT hr = g_d3d11.swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                               reinterpret_cast<void**>(&g_d3d11.backBufferTex));
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] GetBuffer failed: 0x%08X\n", hr); return; }

    hr = g_d3d11.device->CreateRenderTargetView(g_d3d11.backBufferTex, nullptr,
                                                 &g_d3d11.backBufferRTV);
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateRTV failed: 0x%08X\n", hr); return; }

    D3D11_TEXTURE2D_DESC dd = {};
    dd.Width               = g_d3d11.width;
    dd.Height              = g_d3d11.height;
    dd.MipLevels           = 1;
    dd.ArraySize           = 1;
    dd.Format              = DXGI_FORMAT_D24_UNORM_S8_UINT;
    dd.SampleDesc.Count    = 1;
    dd.Usage               = D3D11_USAGE_DEFAULT;
    dd.BindFlags           = D3D11_BIND_DEPTH_STENCIL;
    g_d3d11.device->CreateTexture2D(&dd, nullptr, &g_d3d11.depthTex);
    if (g_d3d11.depthTex)
        g_d3d11.device->CreateDepthStencilView(g_d3d11.depthTex, nullptr, &g_d3d11.depthDSV);

    D3D11_VIEWPORT vp = {};
    vp.Width    = static_cast<float>(g_d3d11.width);
    vp.Height   = static_cast<float>(g_d3d11.height);
    vp.MaxDepth = 1.0f;
    g_d3d11.context->RSSetViewports(1, &vp);
}

// ============================================================================
// D3D11 pipeline init
// ============================================================================

static ID3DBlob* D3D11CompileShader(const char* hlsl, const char* entry, const char* target)
{
    ID3DBlob* code  = nullptr;
    ID3DBlob* error = nullptr;
    HRESULT hr = D3DCompile(hlsl, strlen(hlsl), nullptr, nullptr, nullptr,
                             entry, target,
                             D3DCOMPILE_OPTIMIZATION_LEVEL1, 0, &code, &error);
    if (FAILED(hr)) {
        fprintf(stderr, "[D3D11] D3DCompile(%s) failed: %s\n", entry,
                error ? static_cast<const char*>(error->GetBufferPointer()) : "(none)");
        if (error) error->Release();
        return nullptr;
    }
    if (error) error->Release();
    return code;
}

static void InitRenderingPipeline()
{
    // Vertex shader (entry = "main")
    ID3DBlob* vsBlob = D3D11CompileShader(s_vsHlsl, "main", "vs_4_0");
    if (!vsBlob) return;
    HRESULT hr = g_d3d11.device->CreateVertexShader(vsBlob->GetBufferPointer(),
                                                     vsBlob->GetBufferSize(),
                                                     nullptr, &g_d3d11.vs2D);
    if (FAILED(hr)) { vsBlob->Release(); return; }

    // Input layout: POSITION(float2) + TEXCOORD(float2) + COLOR(BGRA_UNORM) = 20 bytes
    D3D11_INPUT_ELEMENT_DESC ied[] = {
        { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,   0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,   0,  8, D3D11_INPUT_PER_VERTEX_DATA, 0 },
        { "COLOR",    0, DXGI_FORMAT_B8G8R8A8_UNORM, 0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
    };
    hr = g_d3d11.device->CreateInputLayout(ied, 3,
                                            vsBlob->GetBufferPointer(),
                                            vsBlob->GetBufferSize(), &g_d3d11.il2D);
    vsBlob->Release();
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateInputLayout failed\n"); return; }

    // Pixel shaders
    auto compPS = [&](const char* hlsl, ID3D11PixelShader** pp) {
        ID3DBlob* blob = D3D11CompileShader(hlsl, "main", "ps_4_0");
        if (!blob) return;
        g_d3d11.device->CreatePixelShader(blob->GetBufferPointer(),
                                           blob->GetBufferSize(), nullptr, pp);
        blob->Release();
    };
    compPS(s_psUntexturedHlsl, &g_d3d11.psUntextured);
    compPS(s_psAlphaHlsl,      &g_d3d11.psAlpha);
    compPS(s_psModulateHlsl,   &g_d3d11.psModulate);

    // Constant buffer (16 bytes: float2 screenSize + float2 pad)
    D3D11_BUFFER_DESC cbd = {};
    cbd.ByteWidth      = 16;
    cbd.Usage          = D3D11_USAGE_DYNAMIC;
    cbd.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&cbd, nullptr, &g_d3d11.cb2D);

    // Dynamic vertex buffer (initial 256K)
    g_d3d11.dynamicVBSize = 262144;
    D3D11_BUFFER_DESC vbd = {};
    vbd.ByteWidth      = g_d3d11.dynamicVBSize;
    vbd.Usage          = D3D11_USAGE_DYNAMIC;
    vbd.BindFlags      = D3D11_BIND_VERTEX_BUFFER;
    vbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&vbd, nullptr, &g_d3d11.dynamicVB);

    // Dynamic index buffer (initial 64K)
    g_d3d11.dynamicIBSize = 65536;
    D3D11_BUFFER_DESC ibd = {};
    ibd.ByteWidth      = g_d3d11.dynamicIBSize;
    ibd.Usage          = D3D11_USAGE_DYNAMIC;
    ibd.BindFlags      = D3D11_BIND_INDEX_BUFFER;
    ibd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&ibd, nullptr, &g_d3d11.dynamicIB);

    // Blend states
    D3D11_BLEND_DESC bda = {};
    bda.RenderTarget[0].BlendEnable           = TRUE;
    bda.RenderTarget[0].SrcBlend              = D3D11_BLEND_SRC_ALPHA;
    bda.RenderTarget[0].DestBlend             = D3D11_BLEND_INV_SRC_ALPHA;
    bda.RenderTarget[0].BlendOp               = D3D11_BLEND_OP_ADD;
    bda.RenderTarget[0].SrcBlendAlpha         = D3D11_BLEND_ONE;
    bda.RenderTarget[0].DestBlendAlpha        = D3D11_BLEND_ZERO;
    bda.RenderTarget[0].BlendOpAlpha          = D3D11_BLEND_OP_ADD;
    bda.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    g_d3d11.device->CreateBlendState(&bda, &g_d3d11.bsAlpha);

    D3D11_BLEND_DESC bdo = {};
    bdo.RenderTarget[0].BlendEnable           = FALSE;
    bdo.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;
    g_d3d11.device->CreateBlendState(&bdo, &g_d3d11.bsOpaque);

    // Rasterizer: no-cull solid
    D3D11_RASTERIZER_DESC rsd = {};
    rsd.FillMode = D3D11_FILL_SOLID;
    rsd.CullMode = D3D11_CULL_NONE;
    g_d3d11.device->CreateRasterizerState(&rsd, &g_d3d11.rsNoCull);

    // Depth-stencil: disabled (2D rendering)
    D3D11_DEPTH_STENCIL_DESC dsd = {};
    dsd.DepthEnable    = FALSE;
    dsd.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ZERO;
    dsd.DepthFunc      = D3D11_COMPARISON_ALWAYS;
    g_d3d11.device->CreateDepthStencilState(&dsd, &g_d3d11.dssOff);

    // Samplers: linear/clamp and linear/wrap
    D3D11_SAMPLER_DESC sd = {};
    sd.Filter   = D3D11_FILTER_MIN_MAG_MIP_LINEAR;
    sd.AddressU = D3D11_TEXTURE_ADDRESS_CLAMP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_CLAMP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_CLAMP;
    sd.MaxLOD   = D3D11_FLOAT32_MAX;
    g_d3d11.device->CreateSamplerState(&sd, &g_d3d11.samplerLinear);
    sd.AddressU = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressV = D3D11_TEXTURE_ADDRESS_WRAP;
    sd.AddressW = D3D11_TEXTURE_ADDRESS_WRAP;
    g_d3d11.device->CreateSamplerState(&sd, &g_d3d11.samplerWrap);

    // ---- 3D pipeline (programmable VS / MVP via NV2A constants) ----
    {
        ID3DBlob* vs3Blob = D3D11CompileShader(s_vs3DHlsl, "main", "vs_4_0");
        if (vs3Blob) {
            g_d3d11.device->CreateVertexShader(vs3Blob->GetBufferPointer(),
                                                vs3Blob->GetBufferSize(),
                                                nullptr, &g_d3d11.vs3D);
            // Burnout 3 car format: stride 28 = float3 pos + 11/11/10 normal +
            // BGRA diffuse + float2 uv.
            D3D11_INPUT_ELEMENT_DESC ied3[] = {
                { "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "NORMAL",   0, DXGI_FORMAT_R32_UINT,        0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "COLOR",    0, DXGI_FORMAT_B8G8R8A8_UNORM,  0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,    0, 20, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            };
            g_d3d11.device->CreateInputLayout(ied3, 4,
                                               vs3Blob->GetBufferPointer(),
                                               vs3Blob->GetBufferSize(),
                                               &g_d3d11.il3D);
            vs3Blob->Release();
        }
        ID3DBlob* ps3Blob = D3D11CompileShader(s_ps3DHlsl, "main", "ps_4_0");
        if (ps3Blob) {
            g_d3d11.device->CreatePixelShader(ps3Blob->GetBufferPointer(),
                                               ps3Blob->GetBufferSize(),
                                               nullptr, &g_d3d11.ps3D);
            ps3Blob->Release();
        }
        ID3DBlob* ps3uBlob = D3D11CompileShader(s_ps3DUntexturedHlsl, "main", "ps_4_0");
        if (ps3uBlob) {
            g_d3d11.device->CreatePixelShader(ps3uBlob->GetBufferPointer(),
                                               ps3uBlob->GetBufferSize(),
                                               nullptr, &g_d3d11.ps3DUntextured);
            ps3uBlob->Release();
        }
        // 192 × float4 NV2A constants
        D3D11_BUFFER_DESC cb3 = {};
        cb3.ByteWidth      = 192 * 16;
        cb3.Usage          = D3D11_USAGE_DYNAMIC;
        cb3.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
        cb3.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        g_d3d11.device->CreateBuffer(&cb3, nullptr, &g_d3d11.cb3D);

        // 32 × float4 NV2A pixel-shader constants (psC[]) - see nv2a_ps_hlsl.cpp.
        D3D11_BUFFER_DESC cbP = {};
        cbP.ByteWidth      = 32 * 16;
        cbP.Usage          = D3D11_USAGE_DYNAMIC;
        cbP.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
        cbP.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        g_d3d11.device->CreateBuffer(&cbP, nullptr, &g_d3d11.cbPS);

        // Depth test on + write on, LESS_EQUAL
        D3D11_DEPTH_STENCIL_DESC dsOn = {};
        dsOn.DepthEnable    = TRUE;
        dsOn.DepthWriteMask = D3D11_DEPTH_WRITE_MASK_ALL;
        dsOn.DepthFunc      = D3D11_COMPARISON_LESS_EQUAL;
        g_d3d11.device->CreateDepthStencilState(&dsOn, &g_d3d11.dssOn);

        // Rasterizer: no-cull (art assets are often single-sided with
        // inconsistent winding), depth clipping on.
        D3D11_RASTERIZER_DESC rsd3 = {};
        rsd3.FillMode        = D3D11_FILL_SOLID;
        rsd3.CullMode        = D3D11_CULL_NONE;
        rsd3.DepthClipEnable = TRUE;
        g_d3d11.device->CreateRasterizerState(&rsd3, &g_d3d11.rsCull3D);
    }

    g_d3d11.pipelineReady = true;
    fprintf(stderr, "[D3D11] Rendering pipeline initialized\n");
}

// ============================================================================
// D3D11 device init / shutdown
// ============================================================================

static void HLE_InitD3D11(HWND hwnd, uint32_t w, uint32_t h)
{
    g_d3d11 = D3D11State{};
    g_d3d11.width  = w;
    g_d3d11.height = h;

    DXGI_SWAP_CHAIN_DESC scd = {};
    scd.BufferCount                        = 2;
    scd.BufferDesc.Width                   = w;
    scd.BufferDesc.Height                  = h;
    scd.BufferDesc.Format                  = DXGI_FORMAT_B8G8R8A8_UNORM;
    scd.BufferDesc.RefreshRate.Numerator   = 60;
    scd.BufferDesc.RefreshRate.Denominator = 1;
    scd.BufferUsage                        = DXGI_USAGE_RENDER_TARGET_OUTPUT;
    scd.OutputWindow                       = hwnd;
    scd.SampleDesc.Count                   = 1;
    scd.Windowed                           = TRUE;
    scd.SwapEffect                         = DXGI_SWAP_EFFECT_DISCARD;

    D3D_FEATURE_LEVEL fls[] = {
        D3D_FEATURE_LEVEL_11_0, D3D_FEATURE_LEVEL_10_1, D3D_FEATURE_LEVEL_10_0
    };
    D3D_FEATURE_LEVEL fl = D3D_FEATURE_LEVEL_11_0;

    HRESULT hr = D3D11CreateDeviceAndSwapChain(
        nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, 0,
        fls, ARRAYSIZE(fls), D3D11_SDK_VERSION,
        &scd, &g_d3d11.swapChain,
        &g_d3d11.device, &fl, &g_d3d11.context);
    if (FAILED(hr)) {
        fprintf(stderr, "[D3D11] D3D11CreateDeviceAndSwapChain failed: 0x%08X\n", hr);
        return;
    }
    fprintf(stderr, "[D3D11] Device created (FL %04X)\n", static_cast<unsigned>(fl));

    CreateBackBufferResources();
    InitRenderingPipeline();
    g_d3d11.initialized = true;
    fprintf(stderr, "[D3D11] Initialized %ux%u\n", w, h);
}

static void HLE_ShutdownD3D11()
{
    if (!g_d3d11.initialized) return;
    for (auto& [key, ent] : g_d3d11.textureCache) {
        if (ent.srv)     ent.srv->Release();
        if (ent.texture) ent.texture->Release();
    }
    g_d3d11.textureCache.clear();
    for (auto& [key, ent] : g_d3d11.rtCache) {
        if (ent.rtv)      ent.rtv->Release();
        if (ent.srv)      ent.srv->Release();
        if (ent.texture)  ent.texture->Release();
        if (ent.dsv)      ent.dsv->Release();
        if (ent.depthTex) ent.depthTex->Release();
    }
    g_d3d11.rtCache.clear();
    auto R = [](auto*& p){ if (p) { p->Release(); p = nullptr; } };
    R(g_d3d11.vs2D); R(g_d3d11.il2D);
    R(g_d3d11.psUntextured); R(g_d3d11.psAlpha); R(g_d3d11.psModulate);
    R(g_d3d11.cb2D); R(g_d3d11.dynamicVB); R(g_d3d11.dynamicIB);
    R(g_d3d11.bsAlpha); R(g_d3d11.bsOpaque); R(g_d3d11.rsNoCull); R(g_d3d11.dssOff);
    R(g_d3d11.samplerLinear); R(g_d3d11.samplerWrap);
    R(g_d3d11.vs3D); R(g_d3d11.il3D); R(g_d3d11.ps3D); R(g_d3d11.ps3DUntextured); R(g_d3d11.cb3D);
    R(g_d3d11.cbPS);
    R(g_d3d11.dssOn); R(g_d3d11.rsCull3D);
    ReleaseBackBufferResources();
    R(g_d3d11.swapChain);
    if (g_d3d11.context) { g_d3d11.context->ClearState(); g_d3d11.context->Release(); g_d3d11.context = nullptr; }
    R(g_d3d11.device);
    g_d3d11.initialized = false;
}

// Invalidate (and release) the cached D3D11 texture SRV for an Xbox texture
// object address.  Called by the XMV decoder after writing new frame pixels to
// guest memory so the next draw call re-uploads the updated surface.
void HLE_InvalidateTextureSRV(uint32_t texAddr)
{
    auto it = g_d3d11.textureCache.find(texAddr);
    if (it == g_d3d11.textureCache.end()) return;
    auto& e = it->second;
    if (e.srv)     { e.srv->Release();     e.srv     = nullptr; }
    if (e.texture) { e.texture->Release(); e.texture = nullptr; }
    g_d3d11.textureCache.erase(it);
}

// ============================================================================
// D3D11 draw support
// ============================================================================

// Normalized 2D vertex: screen-space XY, UV, BGRA color — 20 bytes
struct Vtx2D {
    float    x, y, u, v;
    uint32_t color; // ARGB in memory = BGRA_UNORM in D3D11
};

static void EnsureDynVB(uint32_t needed)
{
    if (!g_d3d11.dynamicVB || needed <= g_d3d11.dynamicVBSize) return;
    g_d3d11.dynamicVB->Release(); g_d3d11.dynamicVB = nullptr;
    g_d3d11.dynamicVBSize = (needed + 65535u) & ~65535u;
    D3D11_BUFFER_DESC d = {};
    d.ByteWidth = g_d3d11.dynamicVBSize; d.Usage = D3D11_USAGE_DYNAMIC;
    d.BindFlags = D3D11_BIND_VERTEX_BUFFER; d.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&d, nullptr, &g_d3d11.dynamicVB);
}

static void EnsureDynIB(uint32_t needed)
{
    if (!g_d3d11.dynamicIB || needed <= g_d3d11.dynamicIBSize) return;
    g_d3d11.dynamicIB->Release(); g_d3d11.dynamicIB = nullptr;
    g_d3d11.dynamicIBSize = (needed + 16383u) & ~16383u;
    D3D11_BUFFER_DESC d = {};
    d.ByteWidth = g_d3d11.dynamicIBSize; d.Usage = D3D11_USAGE_DYNAMIC;
    d.BindFlags = D3D11_BIND_INDEX_BUFFER; d.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&d, nullptr, &g_d3d11.dynamicIB);
}

// Draw a batch of Vtx2D vertices directly to the D3D11 back buffer.
// topo:        D3D11 primitive topology
// srv:         texture SRV (nullptr = untextured)
// isAlphaOnly: true for A8/L8 font textures → use psAlpha + force alpha blend
static void HLE_DrawBatch2D(const Vtx2D*              verts,
                             uint32_t                  nverts,
                             D3D_PRIMITIVE_TOPOLOGY    topo,
                             ID3D11ShaderResourceView* srv,
                             bool                      isAlphaOnly)
{
    if (!g_d3d11.initialized || !g_d3d11.pipelineReady || nverts == 0) return;

    uint32_t vbNeeded = nverts * sizeof(Vtx2D);
    EnsureDynVB(vbNeeded);
    if (!g_d3d11.dynamicVB) return;

    // Upload vertices
    D3D11_MAPPED_SUBRESOURCE mr = {};
    if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicVB, 0, D3D11_MAP_WRITE_DISCARD, 0, &mr)))
        return;
    memcpy(mr.pData, verts, vbNeeded);
    g_d3d11.context->Unmap(g_d3d11.dynamicVB, 0);

    // Update constant buffer with current screen size
    if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cb2D, 0, D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
        float* cb = static_cast<float*>(mr.pData);
        cb[0] = static_cast<float>(g_d3d11.width);
        cb[1] = static_cast<float>(g_d3d11.height);
        cb[2] = 0.0f; cb[3] = 0.0f;
        g_d3d11.context->Unmap(g_d3d11.cb2D, 0);
    }

    // Render target
    g_d3d11.context->OMSetRenderTargets(1, &g_d3d11.backBufferRTV, nullptr);

    // Blend state
    float bf[4] = { 1,1,1,1 };
    ID3D11BlendState* bs = (g_alphaBlendEnabled || isAlphaOnly) ? g_d3d11.bsAlpha : g_d3d11.bsOpaque;
    g_d3d11.context->OMSetBlendState(bs, bf, 0xFFFFFFFF);
    g_d3d11.context->OMSetDepthStencilState(g_d3d11.dssOff, 0);

    // Rasterizer + viewport
    g_d3d11.context->RSSetState(g_d3d11.rsNoCull);
    D3D11_VIEWPORT vp = {};
    vp.Width    = static_cast<float>(g_d3d11.width);
    vp.Height   = static_cast<float>(g_d3d11.height);
    vp.MaxDepth = 1.0f;
    g_d3d11.context->RSSetViewports(1, &vp);

    // Vertex shader + input layout + cbuffer
    g_d3d11.context->VSSetShader(g_d3d11.vs2D, nullptr, 0);
    g_d3d11.context->VSSetConstantBuffers(0, 1, &g_d3d11.cb2D);
    g_d3d11.context->IASetInputLayout(g_d3d11.il2D);

    // Pixel shader selection
    ID3D11PixelShader* ps;
    if (!srv)              ps = g_d3d11.psUntextured;
    else if (isAlphaOnly)  ps = g_d3d11.psAlpha;
    else                   ps = g_d3d11.psModulate;
    g_d3d11.context->PSSetShader(ps, nullptr, 0);

    if (srv) {
        g_d3d11.context->PSSetShaderResources(0, 1, &srv);
        // Use clamp sampler to avoid bleeding at texture-atlas borders.
        g_d3d11.context->PSSetSamplers(0, 1, &g_d3d11.samplerLinear);
    }

    // Vertex buffer
    UINT stride = sizeof(Vtx2D), offset = 0;
    g_d3d11.context->IASetVertexBuffers(0, 1, &g_d3d11.dynamicVB, &stride, &offset);
    g_d3d11.context->IASetPrimitiveTopology(topo);
    g_d3d11.context->Draw(nverts, 0);

    // Unbind SRV to avoid hazards on next frame
    if (srv) {
        ID3D11ShaderResourceView* nullSRV = nullptr;
        g_d3d11.context->PSSetShaderResources(0, 1, &nullSRV);
    }
}

// ============================================================================
// 3D pipeline — programmable VS with NV2A constant MVP
// ============================================================================
//
// Dispatcher invoked from D3DDevice_DrawVertices / DrawIndexedVertices when
// the current SetVertexShader handle has bit 0 set (programmable shader).
//
//   primType      : NV2A primitive type (5=trilist, 6=tristrip, 7=fan, 8=quads)
//   startVertex   : first vertex in the bound VB to draw (non-indexed)
//   vertexCount   : vertex count (non-indexed) — 0 means indexed draw
//   indexCount    : number of indices (indexed draw)
//   pIndexData    : guest VA of index data (16-bit indices)
static void HLE_Draw3D(uint8_t* base,
                       uint32_t primType,
                       uint32_t startVertex,
                       uint32_t vertexCount,
                       uint32_t indexCount,
                       uint32_t pIndexData)
{
    if (!g_d3d11.initialized || !g_d3d11.pipelineReady) return;
    if (!g_d3d11.vs3D || !g_d3d11.il3D || !g_d3d11.ps3D || !g_d3d11.cb3D) return;

    // Resolve current stream 0 (VB resource ptr + stride). v6 keeps the
    // stream table at kDeviceAddr + 0x1660 / +0x1664 (see SetStreamSource).
    uint32_t vbRes  = X86_MEM_READ_u32(base, kDeviceAddr + 0x1660);
    uint32_t stride = X86_MEM_READ_u32(base, kDeviceAddr + 0x1664);
    if (vbRes == 0 || stride == 0) return;

    // D3DResource header stores the raw data pointer at +4 (virtual address).
    uint32_t vbData = X86_MEM_READ_u32(base, vbRes + 4);
    if (vbData == 0) vbData = vbRes + 0x0C; // fallback: inline data
    vbData &= 0x3FFFFFFFu;

    // Determine how many unique vertices we need to upload.
    uint32_t vcount = vertexCount;
    if (indexCount) {
        uint32_t maxIdx = 0;
        for (uint32_t i = 0; i < indexCount; i++) {
            uint16_t ix = X86_MEM_READ_u16(base, pIndexData + i * 2);
            if (ix > maxIdx) maxIdx = ix;
        }
        vcount = maxIdx + 1;
    }
    if (vcount == 0) return;
    uint32_t vbBytes = vcount * stride;
    if (vbBytes == 0) return;

    // Upload vertex data verbatim into the dynamic VB.
    EnsureDynVB(vbBytes);
    if (!g_d3d11.dynamicVB) return;
    D3D11_MAPPED_SUBRESOURCE mr = {};
    if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicVB, 0,
                                     D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
    memcpy(mr.pData, base + vbData, vbBytes);
    g_d3d11.context->Unmap(g_d3d11.dynamicVB, 0);

    // DIAGNOSTIC: fnv-1a hash the VB content per draw, group by vbRes+vcount
    // and log when the hash CHANGES frame-to-frame for the same VB. That
    // confirms whether the game is uploading varying vertex data on a
    // nominally-static garage mesh.
    {
        auto hash_fnv = [](const uint8_t* p, size_t n) {
            uint64_t h = 0xcbf29ce484222325ULL;
            for (size_t i = 0; i < n; ++i) {
                h ^= p[i];
                h *= 0x100000001b3ULL;
            }
            return h;
        };
        uint64_t h = hash_fnv(base + vbData, vbBytes);
        struct HashVal { uint64_t last; int changes; int seen; };
        static std::unordered_map<uint64_t, HashVal> s_vbHash;
        uint64_t key = ((uint64_t)vbRes << 32) ^ ((uint64_t)vcount << 8) ^ stride;
        auto& v = s_vbHash[key];
        v.seen++;
        if (v.last != 0 && v.last != h) {
            v.changes++;
            if (v.changes <= 6) {
                fprintf(stderr,
                    "[VBHASH] vbRes=0x%08X vc=%u stride=%u CHANGED "
                    "%016llX -> %016llX (seen=%d chg=%d)\n",
                    vbRes, vcount, stride,
                    (unsigned long long)v.last,
                    (unsigned long long)h,
                    v.seen, v.changes);
            }
        }
        v.last = h;
    }

    // DIAGNOSTIC: dump the first N draw calls to a single OBJ file so the
    // geometry can be inspected in Blender. We write each draw as its own
    // "o drawNN" group; positions are taken from offset 0 (float3) of the
    // VB, and triangles are reconstructed from the current topology. This
    // lets us confirm mesh shape independently of the shader pipeline.
    {
        static FILE*    s_objFp         = nullptr;
        static uint32_t s_objVertexBase = 0;   // global vertex counter (OBJ is 1-based)
        static int      s_objDrawsLeft  = 64;  // dump first N draws then stop
        static int      s_objDrawIdx    = 0;
        if (s_objDrawsLeft > 0 && stride >= 12 && vcount >= 3) {
            if (!s_objFp) {
                s_objFp = std::fopen("scene_dump.obj", "w");
                if (s_objFp) {
                    std::fprintf(s_objFp,
                        "# Burnout 3 Recomp diagnostic scene dump\n"
                        "# coordinates are raw object-space (no transform)\n");
                }
            }
            if (s_objFp) {
                const uint8_t* vp = base + vbData;
                // Positions
                std::fprintf(s_objFp, "o draw%03d_prim%u_ic%u\n",
                             s_objDrawIdx, primType,
                             indexCount ? indexCount : vertexCount);
                for (uint32_t v = 0; v < vcount; v++) {
                    float xyz[3];
                    std::memcpy(xyz, vp + v * stride, 12);
                    std::fprintf(s_objFp, "v %.4f %.4f %.4f\n",
                                 xyz[0], xyz[1], xyz[2]);
                }
                // Faces (1-based, global)
                auto faceTri = [&](uint32_t a, uint32_t b, uint32_t c) {
                    std::fprintf(s_objFp, "f %u %u %u\n",
                                 s_objVertexBase + a + 1,
                                 s_objVertexBase + b + 1,
                                 s_objVertexBase + c + 1);
                };
                auto idx = [&](uint32_t i) -> uint32_t {
                    if (indexCount) return X86_MEM_READ_u16(base, pIndexData + i * 2);
                    return startVertex + i;
                };
                uint32_t n = indexCount ? indexCount : vertexCount;
                switch (primType) {
                case 5: // TRIANGLES
                    for (uint32_t t = 0; t + 2 < n; t += 3)
                        faceTri(idx(t), idx(t + 1), idx(t + 2));
                    break;
                case 6: // TRISTRIP
                    for (uint32_t t = 0; t + 2 < n; t++) {
                        if (t & 1) faceTri(idx(t + 1), idx(t), idx(t + 2));
                        else       faceTri(idx(t), idx(t + 1), idx(t + 2));
                    }
                    break;
                case 7: // TRIFAN
                    for (uint32_t t = 1; t + 1 < n; t++)
                        faceTri(idx(0), idx(t), idx(t + 1));
                    break;
                case 8: // QUADS
                    for (uint32_t q = 0; q + 3 < n; q += 4) {
                        faceTri(idx(q), idx(q + 1), idx(q + 2));
                        faceTri(idx(q), idx(q + 2), idx(q + 3));
                    }
                    break;
                default: break; // points/lines — skip
                }
                s_objVertexBase += vcount;
                std::fflush(s_objFp);
                s_objDrawIdx++;
                s_objDrawsLeft--;
                if (s_objDrawsLeft == 0) {
                    std::fprintf(s_objFp, "# end of capture\n");
                    std::fclose(s_objFp);
                    s_objFp = nullptr;
                    fprintf(stderr,
                        "[HLE] scene_dump.obj: wrote %d draws, %u vertices\n",
                        s_objDrawIdx, s_objVertexBase);
                }
            }
        }
    }

    // DIAGNOSTIC: dump the first few vertex positions so we can see the
    // coordinate scale the game is feeding us. Position is at offset 0 of
    // every Burnout 3 VB layout we've seen. Compute min/max over all verts
    // for x/y/z so we can pick a sane synthetic projection.
    {
        static int s_vbDumpsLeft = 8;
        if (s_vbDumpsLeft > 0 && stride >= 12 && vcount >= 1) {
            const uint8_t* vp = base + vbData;
            float mn[3] = {  1e30f,  1e30f,  1e30f };
            float mx[3] = { -1e30f, -1e30f, -1e30f };
            uint32_t scanN = vcount < 1024 ? vcount : 1024;
            for (uint32_t v = 0; v < scanN; v++) {
                float xyz[3];
                memcpy(xyz, vp + v * stride, 12);
                for (int k = 0; k < 3; k++) {
                    if (!std::isfinite(xyz[k])) continue;
                    if (xyz[k] < mn[k]) mn[k] = xyz[k];
                    if (xyz[k] > mx[k]) mx[k] = xyz[k];
                }
            }
            float p0[3], p1[3];
            memcpy(p0, vp, 12);
            memcpy(p1, vp + stride, 12);
            fprintf(stderr,
                "[VB] vc=%u stride=%u v0=(%.3f,%.3f,%.3f) v1=(%.3f,%.3f,%.3f) "
                "bbox x=[%.3f,%.3f] y=[%.3f,%.3f] z=[%.3f,%.3f]\n",
                vcount, stride, p0[0], p0[1], p0[2], p1[0], p1[1], p1[2],
                mn[0], mx[0], mn[1], mx[1], mn[2], mx[2]);
            s_vbDumpsLeft--;
        }
    }

    // Upload indices (if indexed).
    if (indexCount) {
        uint32_t ibBytes = indexCount * 2;
        EnsureDynIB(ibBytes);
        if (!g_d3d11.dynamicIB) return;
        if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicIB, 0,
                                         D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
        memcpy(mr.pData, base + pIndexData, ibBytes);
        g_d3d11.context->Unmap(g_d3d11.dynamicIB, 0);
    }

    // Upload NV2A vertex constants. For any slot that is still all-zero in
    // the host cache, fall back to the guest shadow (so code that wrote to
    // 0x35FDF8 directly still has effect).
    if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cb3D, 0,
                                        D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
        float* dst = static_cast<float*>(mr.pData);
        for (uint32_t i = 0; i < 192; i++) {
            const float* src = g_vshConstants[i];
            // DIAGNOSTIC: ignore guest shadow fallback — it aliases into
            // game code/data at 0x35FDF8 which gives garbage for slots the
            // game never explicitly wrote via SetVertexShaderConstant*.
            const float* pick = src;
            // Sanitize infs/NaNs before handing to the shader — NV2A
            // drivers happily write inf/-inf into the near/far registers,
            // and propagating those through the HLSL VS corrupts every
            // vertex's position to NaN, collapsing the primitive.
            for (int k = 0; k < 4; k++) {
                float v = pick[k];
                dst[i * 4 + k] = std::isfinite(v) ? v : 0.0f;
            }
        }
        // DIAGNOSTIC: detect which VS-constant slots vary across successive
        // draws of the SAME VS handle. We log the first ~64 change events.
        #if 0
        {
            static uint64_t s_prevSlotHash[192] = {};
            static uint32_t s_prevVs = 0;
            static uint32_t s_logCount = 0;
            if (g_currentVSHandle == s_prevVs && s_prevVs != 0) {
                for (uint32_t i = 0; i < 192 && s_logCount < 64; i++) {
                    uint64_t h = 1469598103934665603ull;
                    const uint32_t* pw = reinterpret_cast<const uint32_t*>(&dst[i*4]);
                    for (int k = 0; k < 4; k++) { h ^= pw[k]; h *= 1099511628211ull; }
                    if (s_prevSlotHash[i] != 0 && s_prevSlotHash[i] != h) {
                        fprintf(stderr,
                            "[VSCVAR] vs=0x%08X c[%u] = [%.4f %.4f %.4f %.4f]\n",
                            s_prevVs, i,
                            dst[i*4+0], dst[i*4+1], dst[i*4+2], dst[i*4+3]);
                        s_logCount++;
                    }
                    s_prevSlotHash[i] = h;
                }
            } else {
                // New VS -> reset tracking
                for (uint32_t i = 0; i < 192; i++) {
                    uint64_t h = 1469598103934665603ull;
                    const uint32_t* pw = reinterpret_cast<const uint32_t*>(&dst[i*4]);
                    for (int k = 0; k < 4; k++) { h ^= pw[k]; h *= 1099511628211ull; }
                    s_prevSlotHash[i] = h;
                }
            }
            s_prevVs = g_currentVSHandle;
        }
        #endif
        // Force c[58]/c[59] to match our render viewport. The Xbox D3D runtime
        // writes these via SetViewport (through the NV2A push buffer); we don't
        // emulate that path, so without this override NV2A shaders that fold
        // the viewport transform into oPos (`oPos = clip * c[58] / w + c[59]`)
        // would collapse every vertex to the origin or NaN. Backing them with
        // real viewport scale/offset, and then inverting that transform in the
        // translated HLSL epilogue, restores clip-space output.
        {
            const float vpW = 640.0f, vpH = 480.0f;
            dst[58*4+0] = vpW * 0.5f;  dst[58*4+1] = -vpH * 0.5f;
            dst[58*4+2] = 1.0f;        dst[58*4+3] = 0.0f;
            dst[59*4+0] = vpW * 0.5f;  dst[59*4+1] = vpH * 0.5f;
            dst[59*4+2] = 0.0f;        dst[59*4+3] = 1.0f;
        }
        // DIAGNOSTIC: when c[112..115] is all zero (the engine's MVP-build
        // routine writes to guest scratch buffers 0x004D66F0 / 0x004D6730
        // that are never populated — see repo memory
        // b3-3d-rendering-mvp-gap.md for the IDA investigation), inject a
        // synthetic MVP so we can verify the rest of the pipeline. We try
        // (a) identity first (works for screen-space helpers and any verts
        // already in clip space), and if needed users can swap in a real
        // perspective matrix below.
        {
            bool mvpAllZero = true;
            for (int row = 112; row < 116 && mvpAllZero; row++) {
                for (int k = 0; k < 4 && mvpAllZero; k++) {
                    if (dst[row*4 + k] != 0.0f) mvpAllZero = false;
                }
            }
            if (mvpAllZero) {
                // Use the cached last-good VIEW and PROJ (populated by
                // D3DDevice_SetTransform). The engine's
                // SetVertexShaderConstant(112,...) path uploads zeros from
                // dead scratch buffers, so we have to synthesize here.

                float mvp[16]; // row-vector MVP (= VIEW * PROJ)
                bool usingReal = false;

                if (g_haveView && g_haveProj) {
                    // Row-major matrix multiply VIEW*PROJ, row-vector style:
                    //   OUT[i][j] = sum_k VIEW[i][k] * PROJ[k][j]
                    for (int r = 0; r < 4; r++)
                      for (int c = 0; c < 4; c++) {
                        float s = 0;
                        for (int k = 0; k < 4; k++)
                            s += g_lastGoodView[r*4+k] * g_lastGoodProj[k*4+c];
                        mvp[r*4+c] = s;
                      }
                    usingReal = true;
                } else {
                    // Synthetic orbit fallback (legacy behaviour) — only
                    // fires before the first valid SetTransform VIEW+PROJ.
                    static auto s_startTime = std::chrono::steady_clock::now();
                    auto now = std::chrono::steady_clock::now();
                    float t = std::chrono::duration<float>(now - s_startTime).count();
                    const float tgtX = 25.0f, tgtY = 2.0f, tgtZ = -7.0f;
                    const float camDist   = 120.0f;
                    const float camHeight = 25.0f;
                    const float angSpeed  = 0.3f;
                    float ang = angSpeed * t;
                    float cx = tgtX + camDist * std::sin(ang);
                    float cz = tgtZ + camDist * std::cos(ang);
                    float cy = tgtY + camHeight;
                    float ex = cx, ey = cy, ez = cz;
                    float fx = tgtX - ex, fy = tgtY - ey, fz = tgtZ - ez;
                    float flen = std::sqrt(fx*fx + fy*fy + fz*fz);
                    fx /= flen; fy /= flen; fz /= flen;
                    float rx =  fz, ry = 0, rz = -fx;
                    float rlen = std::sqrt(rx*rx + rz*rz);
                    rx /= rlen; rz /= rlen;
                    float ux = fy*rz - fz*ry;
                    float uy = fz*rx - fx*rz;
                    float uz = fx*ry - fy*rx;
                    float view[16] = {
                        rx, ux, fx, 0,
                        ry, uy, fy, 0,
                        rz, uz, fz, 0,
                        -(rx*ex + ry*ey + rz*ez),
                        -(ux*ex + uy*ey + uz*ez),
                        -(fx*ex + fy*ey + fz*ez),
                        1
                    };
                    const float fovY   = 1.0471975f;
                    const float aspect = 4.0f / 3.0f;
                    const float zn = 0.5f, zf = 5000.0f;
                    const float yScale = 1.0f / std::tan(fovY * 0.5f);
                    const float xScale = yScale / aspect;
                    const float zRange = zf / (zf - zn);
                    float proj[16] = {
                        xScale, 0,      0,                  0,
                        0,      yScale, 0,                  0,
                        0,      0,      zRange,             1,
                        0,      0,     -zn*zRange,          0
                    };
                    for (int r = 0; r < 4; r++)
                      for (int c = 0; c < 4; c++) {
                        float s = 0;
                        for (int k = 0; k < 4; k++) s += view[r*4+k] * proj[k*4+c];
                        mvp[r*4+c] = s;
                      }
                }

                // Transpose row-vector MVP into c[112..115] so the shader's
                // column-vector DP4 produces the correct clip-space output.
                for (int r = 0; r < 4; r++)
                  for (int c = 0; c < 4; c++)
                    dst[(112 + r)*4 + c] = mvp[c*4 + r];

                // DIAGNOSTIC: log any time the injected MVP *meaningfully*
                // changes. Capture a hash of c[112..115] so per-draw logs
                // are deduped but every distinct matrix is shown.
                uint64_t h = 1469598103934665603ull;
                const uint32_t* pw = reinterpret_cast<const uint32_t*>(dst + 112*4);
                for (int i = 0; i < 16; i++) { h ^= pw[i]; h *= 1099511628211ull; }
                static uint64_t s_lastHash = 0;
                static int s_distinct = 0;
                if (h != s_lastHash && s_distinct < 24) {
                    s_lastHash = h;
                    s_distinct++;
                    // fprintf(stderr,
                    //     "[HLE] MVP-inject #%d %s\n"
                    //     "         c112=[%.3f %.3f %.3f %.3f]\n"
                    //     "         c113=[%.3f %.3f %.3f %.3f]\n"
                    //     "         c114=[%.3f %.3f %.3f %.3f]\n"
                    //     "         c115=[%.3f %.3f %.3f %.3f]\n",
                    //     s_distinct,
                    //     usingReal ? "(REAL VIEW*PROJ)" : "(synthetic orbit)",
                    //     dst[112*4+0], dst[112*4+1], dst[112*4+2], dst[112*4+3],
                    //     dst[113*4+0], dst[113*4+1], dst[113*4+2], dst[113*4+3],
                    //     dst[114*4+0], dst[114*4+1], dst[114*4+2], dst[114*4+3],
                    //     dst[115*4+0], dst[115*4+1], dst[115*4+2], dst[115*4+3]);
                    // if (usingReal) {
                    //     fprintf(stderr,
                    //         "         VIEW=[%.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f /\n"
                    //         "               %.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f]\n"
                    //         "         PROJ=[%.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f /\n"
                    //         "               %.3f %.3f %.3f %.3f / %.3f %.3f %.3f %.3f]\n",
                    //         g_lastGoodView[0],g_lastGoodView[1],g_lastGoodView[2],g_lastGoodView[3],
                    //         g_lastGoodView[4],g_lastGoodView[5],g_lastGoodView[6],g_lastGoodView[7],
                    //         g_lastGoodView[8],g_lastGoodView[9],g_lastGoodView[10],g_lastGoodView[11],
                    //         g_lastGoodView[12],g_lastGoodView[13],g_lastGoodView[14],g_lastGoodView[15],
                    //         g_lastGoodProj[0],g_lastGoodProj[1],g_lastGoodProj[2],g_lastGoodProj[3],
                    //         g_lastGoodProj[4],g_lastGoodProj[5],g_lastGoodProj[6],g_lastGoodProj[7],
                    //         g_lastGoodProj[8],g_lastGoodProj[9],g_lastGoodProj[10],g_lastGoodProj[11],
                    //         g_lastGoodProj[12],g_lastGoodProj[13],g_lastGoodProj[14],g_lastGoodProj[15]);
                    // }
                }
            }
        }
        // One-time scan: list every constant slot that holds non-zero data
        // so we can figure out where the game actually stores its MVP.
        static bool s_dumpedNonzero = false;
        if (!s_dumpedNonzero) {
            s_dumpedNonzero = true;
            fprintf(stderr, "[HLE] non-zero VS constant slots:\n");
            for (uint32_t i = 0; i < 192; i++) {
                float a = dst[i*4+0], b = dst[i*4+1], c = dst[i*4+2], d = dst[i*4+3];
                if (a != 0 || b != 0 || c != 0 || d != 0) {
                    fprintf(stderr, "  c[%u] = [%.4f %.4f %.4f %.4f]\n",
                            i, a, b, c, d);
                }
            }
        }
        static int s_logCB = 0;
        if (s_logCB < 3) {
            fprintf(stderr,
                "[HLE] 3D cbuffer c[112..115]:\n"
                "  c112=[%.4f %.4f %.4f %.4f]\n"
                "  c113=[%.4f %.4f %.4f %.4f]\n"
                "  c114=[%.4f %.4f %.4f %.4f]\n"
                "  c115=[%.4f %.4f %.4f %.4f]\n",
                dst[112*4+0], dst[112*4+1], dst[112*4+2], dst[112*4+3],
                dst[113*4+0], dst[113*4+1], dst[113*4+2], dst[113*4+3],
                dst[114*4+0], dst[114*4+1], dst[114*4+2], dst[114*4+3],
                dst[115*4+0], dst[115*4+1], dst[115*4+2], dst[115*4+3]);
            s_logCB++;
        }
        g_d3d11.context->Unmap(g_d3d11.cb3D, 0);
    }

    // Topology mapping.
    D3D_PRIMITIVE_TOPOLOGY topo;
    std::vector<uint16_t> fanOrQuadIdx; // used for expansion
    bool useExpanded = false;
    switch (primType) {
    case 1: topo = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
    case 2: topo = D3D11_PRIMITIVE_TOPOLOGY_LINELIST; break;
    case 3: topo = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP; break;
    case NV2A_PRIM_TRIANGLES: topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;  break;
    case NV2A_PRIM_TRISTRIP:  topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP; break;
    case NV2A_PRIM_TRIFAN: {
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        useExpanded = true;
        if (indexCount) {
            for (uint32_t i = 1; i + 1 < indexCount; i++) {
                fanOrQuadIdx.push_back(X86_MEM_READ_u16(base, pIndexData));
                fanOrQuadIdx.push_back(X86_MEM_READ_u16(base, pIndexData + i * 2));
                fanOrQuadIdx.push_back(X86_MEM_READ_u16(base, pIndexData + (i + 1) * 2));
            }
        } else {
            for (uint32_t i = 1; i + 1 < vertexCount; i++) {
                fanOrQuadIdx.push_back(static_cast<uint16_t>(startVertex));
                fanOrQuadIdx.push_back(static_cast<uint16_t>(startVertex + i));
                fanOrQuadIdx.push_back(static_cast<uint16_t>(startVertex + i + 1));
            }
        }
        break;
    }
    case NV2A_PRIM_QUADS: {
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        useExpanded = true;
        if (indexCount) {
            for (uint32_t i = 0; i + 3 < indexCount; i += 4) {
                uint16_t a = X86_MEM_READ_u16(base, pIndexData + (i+0) * 2);
                uint16_t b = X86_MEM_READ_u16(base, pIndexData + (i+1) * 2);
                uint16_t c = X86_MEM_READ_u16(base, pIndexData + (i+2) * 2);
                uint16_t d = X86_MEM_READ_u16(base, pIndexData + (i+3) * 2);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(c);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(c); fanOrQuadIdx.push_back(d);
            }
        } else {
            for (uint32_t i = 0; i + 3 < vertexCount; i += 4) {
                uint16_t a = static_cast<uint16_t>(startVertex + i + 0);
                uint16_t b = static_cast<uint16_t>(startVertex + i + 1);
                uint16_t c = static_cast<uint16_t>(startVertex + i + 2);
                uint16_t d = static_cast<uint16_t>(startVertex + i + 3);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(c);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(c); fanOrQuadIdx.push_back(d);
            }
        }
        break;
    }
    default:
        return; // unsupported prim
    }

    // If we expanded indices client-side, push them into the dynamic IB.
    uint32_t drawIndexCount = 0;
    if (useExpanded) {
        drawIndexCount = static_cast<uint32_t>(fanOrQuadIdx.size());
        if (drawIndexCount == 0) return;
        EnsureDynIB(drawIndexCount * 2);
        if (!g_d3d11.dynamicIB) return;
        if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicIB, 0,
                                         D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
        memcpy(mr.pData, fanOrQuadIdx.data(), drawIndexCount * 2);
        g_d3d11.context->Unmap(g_d3d11.dynamicIB, 0);
    }

    // Resolve the currently bound texture (if any).
    // Burnout 3 uses programmable pixel shaders driven via the pushbuffer,
    // so the fixed-function TSS combiner state is stale for most 3D draws
    // (we frequently see colorOp=DISABLE while a real texture is bound).
    // Bind whatever high-level texture the game selected with SetTexture,
    // falling back to push-buffer-shadowed NV2A state if that slot is empty.
    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    ID3D11ShaderResourceView* srv = nullptr;
    bool colorOpOk = ColorOpUsesTexture();
    (void)colorOpOk;
    if (texAddr) {
        srv = GetOrCreateTextureSRV(base, texAddr);
    }
    if (!srv) {
        srv = ResolveNV2ATextureSRV(base, 0);
    }
    {
        static int s_noSrvDiag = 0;
        if (!srv && s_noSrvDiag < 32) {
            fprintf(stderr,
                "[NOTEX] draw=%d texAddr=0x%08X colorOp=0x%X arg1=0x%X arg2=0x%X useTex=%d nvOff=0x%08X nvFmt=0x%08X nvRect=0x%08X nvCtl1=0x%08X\n",
                s_noSrvDiag, texAddr, g_colorOp, g_colorArg1, g_colorArg2,
                (texAddr && colorOpOk) ? 1 : 0,
                g_nv2aTexture[0].offset, g_nv2aTexture[0].format,
                g_nv2aTexture[0].imageRect, g_nv2aTexture[0].control1);
            ++s_noSrvDiag;
        }
        // Track distinct (texAddr, stride, prim) per draw so we can see how
        // many unique textures the garage scene actually uses. Cars/scenery
        // should cycle through many texture addresses; if we see only one
        // address repeated, texture switching is broken.
        static uint32_t s_lastTex = 0xFFFFFFFFu;
        static int s_drawLog = 0;
        if (texAddr != s_lastTex && s_drawLog < 40) {
            s_lastTex = texAddr;
            s_drawLog++;
            // Also peek the first vertex's UV to see what coords come through.
            float u0 = 0, v0 = 0;
            if (stride >= 20 && vcount >= 1) {
                // Burnout 3 standard layout: pos(12) + norm(4) + col(4) + uv(8),
                // UV at offset 20.
                uint32_t uvOff = stride - 8;
                u0 = *reinterpret_cast<const float*>(base + vbData + uvOff);
                v0 = *reinterpret_cast<const float*>(base + vbData + uvOff + 4);
            }
            fprintf(stderr,
                "[DRAW] n=%d tex=0x%08X srv=%p stride=%u vc=%u uv0=(%.3f,%.3f) psh=0x%08X\n",
                s_drawLog, texAddr, (void*)srv, stride, vcount, u0, v0,
                g_currentPSHandle);
        }
    }

    // OM: render target + depth (depth test on, write on, LESS_EQUAL).
    g_d3d11.context->OMSetRenderTargets(1, &g_d3d11.backBufferRTV, g_d3d11.depthDSV);
    float bf[4] = { 1,1,1,1 };
    g_d3d11.context->OMSetBlendState(g_d3d11.bsOpaque, bf, 0xFFFFFFFF);
    g_d3d11.context->OMSetDepthStencilState(g_d3d11.dssOn, 0);

    // RS: no-cull for Burnout 3 car geometry, full viewport.
    g_d3d11.context->RSSetState(g_d3d11.rsCull3D ? g_d3d11.rsCull3D : g_d3d11.rsNoCull);
    D3D11_VIEWPORT vp = {};
    vp.Width    = static_cast<float>(g_d3d11.width);
    vp.Height   = static_cast<float>(g_d3d11.height);
    vp.MaxDepth = 1.0f;
    g_d3d11.context->RSSetViewports(1, &vp);

    // VS + IL + CB. Prefer a per-handle translated NV2A shader if we have
    // one compiled for the currently bound VS. Otherwise fall back to the
    // hardcoded s_vs3DHlsl / 28-byte layout.
    ID3D11VertexShader* useVS = g_d3d11.vs3D;
    ID3D11InputLayout*  useIL = g_d3d11.il3D;
    {
        uint32_t liveVS = LiveVSHandle(base);
        auto it = g_vsByHandle.find(liveVS);
        if (it != g_vsByHandle.end() && !it->second.failed
            && it->second.vs && it->second.il) {
            useVS = it->second.vs;
            useIL = it->second.il;
            static uint32_t s_lastHit = 0;
            if (liveVS != s_lastHit) {
                // fprintf(stderr, "[HLE] Draw3D using translated VS for handle=0x%08X\n",
                //         liveVS);
                s_lastHit = liveVS;
            }
            // One-time-per-handle dump of which c[N] slots this shader
            // samples — and the actual oPos-producing line(s). Pinpoints
            // which constant slot must hold the MVP for this shader.
            static std::unordered_set<uint32_t> s_dumped;
            if (s_dumped.insert(liveVS).second && !it->second.hlsl.empty()) {
                const std::string& s = it->second.hlsl;
                // Collect unique c[N] indices.
                std::set<int> slots;
                for (size_t p = 0; (p = s.find("c[", p)) != std::string::npos; ) {
                    p += 2;
                    size_t q = p;
                    int idx = 0;
                    bool any = false;
                    while (q < s.size() && s[q] >= '0' && s[q] <= '9') {
                        idx = idx * 10 + (s[q] - '0');
                        ++q;
                        any = true;
                    }
                    if (any && q < s.size() && s[q] == ']')
                        slots.insert(idx);
                }
                std::string list;
                for (int v : slots) {
                    if (!list.empty()) list += ",";
                    list += std::to_string(v);
                }
                fprintf(stderr, "[SHADER] handle=0x%08X samples c[%s]\n",
                        liveVS, list.c_str());
                // Dump lines that write oPos / oD0 / oT0 so we can see
                // color/UV output wiring.
                size_t lineStart = 0;
                for (size_t i = 0; i <= s.size(); ++i) {
                    if (i == s.size() || s[i] == '\n') {
                        std::string line = s.substr(lineStart, i - lineStart);
                        if (line.find("oPos") != std::string::npos ||
                            line.find("oD0")  != std::string::npos ||
                            line.find("oT0")  != std::string::npos) {
                            fprintf(stderr, "[SHADER]   %s\n", line.c_str());
                        }
                        lineStart = i + 1;
                    }
                }
                // Also dump full HLSL to file for offline inspection.
                char fname[64];
                std::snprintf(fname, sizeof(fname),
                              "shader_0x%08X.hlsl", liveVS);
                if (FILE* fp = std::fopen(fname, "w")) {
                    std::fwrite(s.data(), 1, s.size(), fp);
                    std::fclose(fp);
                }
            }
        }
    }
    g_d3d11.context->VSSetShader(useVS, nullptr, 0);
    g_d3d11.context->VSSetConstantBuffers(0, 1, &g_d3d11.cb3D);
    g_d3d11.context->IASetInputLayout(useIL);

    // PS (falls back to untextured 3D variant if no texture bound — keeps
    // NV2A-VS COLOR/TEXCOORD semantics and floors vertex colour so unlit
    // meshes don't render pure black).
    //
    // If we have a translated per-handle PS for the game's current register
    // combiners, prefer that and bind up to 4 texture stages (stage 0 comes
    // from the D3DDevice_SetTexture slot at kDeviceAddr+0x0B00; stages 1..3
    // come from kDeviceAddr+0x0B04/0x0B08/0x0B0C). Otherwise use the old
    // single-texture fallback.
    TranslatedPS* tps = nullptr;
    if (g_currentPSHandle) {
        auto it = g_psByHandle.find(g_currentPSHandle);
        if (it != g_psByHandle.end() && it->second.ps) tps = &it->second;
    }
    if (tps) {
        // Upload psC[0..15] (plus zero-padding up to psC[32]) and bind at b0.
        if (g_d3d11.cbPS) {
            // At draw time, pull the live 16 PS constant slots straight from
            // the Xbox RS shadow. Burnout 3 inlines SetPixelShaderConstant
            // and Cxbx-Reloaded documents that these are maintained as
            // render-state indices 10..25 (X_D3DRS_PSCONSTANT0_0..
            // PSCONSTANT1_7) in 0xAARRGGBB format.
            //
            // The canonical shadow in our HLE is g_hleRenderStateCache[],
            // populated by __rwXbFlushCacheBuffer /
            // D3DDevice_SetRenderStateNotInline. We also fall back to
            // reading the Xbox guest-memory shadow at 0x35FB58 and the
            // RW-pending array at 0x75D4A0 in case code paths bypass
            // those hooks.
            constexpr uint32_t kRSShadowBase  = 0x35FB58;
            constexpr uint32_t kRWPendingBase = 0x75D4A0;
            constexpr uint32_t kPSConstRsIdx  = 10; // X_D3DRS_PSCONSTANT0_0
            for (uint32_t i = 0; i < 16; ++i) {
                uint32_t rs = kPSConstRsIdx + i;
                uint32_t v = 0;
                if (rs < kHLERenderStateCount)
                    v = g_hleRenderStateCache[rs];
                if (v == 0)
                    v = X86_MEM_READ_u32(base, kRSShadowBase + rs * 4);
                if (v == 0)
                    v = X86_MEM_READ_u32(base, kRWPendingBase + rs * 4);
                if (v != 0 || (g_pshConstantsDirty & (1u << i))) {
                    g_pshConstants[i][0] = ((v >> 16) & 0xFF) / 255.0f;
                    g_pshConstants[i][1] = ((v >>  8) & 0xFF) / 255.0f;
                    g_pshConstants[i][2] = ((v >>  0) & 0xFF) / 255.0f;
                    g_pshConstants[i][3] = ((v >> 24) & 0xFF) / 255.0f;
                    g_pshConstantsDirty |= (1u << i);
                }
            }
            static int s_logRS = 0;
            if (s_logRS < 4) {
                fprintf(stderr,
                    "[PSH] draw RS cache C0: %08X %08X %08X %08X | "
                    "C1: %08X %08X %08X %08X dirty=0x%04X\n",
                    g_hleRenderStateCache[10], g_hleRenderStateCache[11],
                    g_hleRenderStateCache[12], g_hleRenderStateCache[13],
                    g_hleRenderStateCache[18], g_hleRenderStateCache[19],
                    g_hleRenderStateCache[20], g_hleRenderStateCache[21],
                    g_pshConstantsDirty);
                ++s_logRS;
            }

            D3D11_MAPPED_SUBRESOURCE mr{};
            if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cbPS, 0,
                    D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
                float* dst = reinterpret_cast<float*>(mr.pData);
                std::memcpy(dst, &g_pshConstants[0][0], 16 * 4 * sizeof(float));
                std::memset(dst + 16 * 4, 0, (32 - 16) * 4 * sizeof(float));
                g_d3d11.context->Unmap(g_d3d11.cbPS, 0);
            }
            g_d3d11.context->PSSetConstantBuffers(0, 1, &g_d3d11.cbPS);
        }

        g_d3d11.context->PSSetShader(tps->ps, nullptr, 0);
        ID3D11ShaderResourceView* srvs[4] = {};
        ID3D11SamplerState*       samps[4] = {};
        uint32_t stageAddr[4] = {};
        for (unsigned s = 0; s < 4; ++s) {
            ID3D11ShaderResourceView* stageSrv = nullptr;
            if (tps->usesStage[s]) {
                uint32_t addr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + s * 4);
                stageAddr[s] = addr;
                if (addr) stageSrv = GetOrCreateTextureSRV(base, addr);
                if (!stageSrv) stageSrv = ResolveNV2ATextureSRV(base, s);
            }
            srvs[s]  = stageSrv;
            samps[s] = g_d3d11.samplerWrap;
        }
        // Diagnostic: multi-stage draws.  If any stage >0 samples, show
        // what texture addresses and SRVs are bound so we can tell whether
        // the TV-static is coming from stale/garbage SRVs.
        if (tps->usesStage[2] || tps->usesStage[3]) {
            static int s_logMulti = 0;
            if (s_logMulti < 16) {
                fprintf(stderr,
                    "[PSH] 3+stage draw: ps=%p uses=%d%d%d%d "
                    "addrs=%08X,%08X,%08X,%08X srvs=%p,%p,%p,%p\n",
                    (void*)tps->ps,
                    tps->usesStage[0], tps->usesStage[1],
                    tps->usesStage[2], tps->usesStage[3],
                    stageAddr[0], stageAddr[1], stageAddr[2], stageAddr[3],
                    (void*)srvs[0], (void*)srvs[1], (void*)srvs[2], (void*)srvs[3]);
                ++s_logMulti;
            }
        }
        g_d3d11.context->PSSetShaderResources(0, 4, srvs);
        g_d3d11.context->PSSetSamplers(0, 4, samps);
    } else {
        ID3D11PixelShader* ps = srv ? g_d3d11.ps3D
                                    : (g_d3d11.ps3DUntextured ? g_d3d11.ps3DUntextured
                                                              : g_d3d11.psUntextured);
        g_d3d11.context->PSSetShader(ps, nullptr, 0);
        if (srv) {
            g_d3d11.context->PSSetShaderResources(0, 1, &srv);
            g_d3d11.context->PSSetSamplers(0, 1, &g_d3d11.samplerWrap);
        }
    }

    // VB
    UINT vbStride = stride, vbOffset = 0;
    g_d3d11.context->IASetVertexBuffers(0, 1, &g_d3d11.dynamicVB, &vbStride, &vbOffset);
    g_d3d11.context->IASetPrimitiveTopology(topo);

    if (useExpanded) {
        g_d3d11.context->IASetIndexBuffer(g_d3d11.dynamicIB, DXGI_FORMAT_R16_UINT, 0);
        g_d3d11.context->DrawIndexed(drawIndexCount, 0, 0);
    } else if (indexCount) {
        g_d3d11.context->IASetIndexBuffer(g_d3d11.dynamicIB, DXGI_FORMAT_R16_UINT, 0);
        g_d3d11.context->DrawIndexed(indexCount, 0, 0);
    } else {
        g_d3d11.context->Draw(vertexCount, startVertex);
    }

    // Unbind SRV to avoid hazards between subsequent 2D passes.
    if (tps) {
        ID3D11ShaderResourceView* nullSRVs[4] = {};
        g_d3d11.context->PSSetShaderResources(0, 4, nullSRVs);
    } else if (srv) {
        ID3D11ShaderResourceView* nullSRV = nullptr;
        g_d3d11.context->PSSetShaderResources(0, 1, &nullSRV);
    }
}

// Handles all Xbox/NV2A primitive types by expanding to tri-lists or strips.
static void DrawSWVertsD3D11(uint8_t* base, const SWVertex* sv, size_t n, int primType,
                              ID3D11ShaderResourceView* srv, bool isAlphaOnly)
{
    if (n == 0 || !g_d3d11.initialized) return;

    std::vector<Vtx2D> verts;
    verts.reserve(n * 2);
    auto push = [&](const SWVertex& v) { verts.push_back({v.x, v.y, v.u, v.v, v.diffuse}); };

    D3D_PRIMITIVE_TOPOLOGY topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

    // Note: only NV2A prim types reach this path (from SubmitPrims).
    // X_D3DPT values overlap with NV2A values so they are NOT combined here.
    switch (primType) {
    case NV2A_PRIM_TRIANGLES:   // 5
    case X_D3DPT_TRIANGLELIST:  // 4
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 0; i < n; i++) push(sv[i]);
        break;
    case NV2A_PRIM_TRISTRIP:    // 6
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
        for (size_t i = 0; i < n; i++) push(sv[i]);
        break;
    case NV2A_PRIM_TRIFAN:      // 7
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 1; i + 1 < n; i++) { push(sv[0]); push(sv[i]); push(sv[i+1]); }
        break;
    case NV2A_PRIM_QUADS:       // 8
    case X_D3DPT_QUADLIST:      // 13
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 0; i + 3 < n; i += 4) {
            push(sv[i]); push(sv[i+1]); push(sv[i+2]);
            push(sv[i]); push(sv[i+2]); push(sv[i+3]);
        }
        break;
    case NV2A_PRIM_QUADSTRIP:   // 9
    case X_D3DPT_QUADSTRIP:     // 14
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 0; i + 3 < n; i += 2) {
            push(sv[i]); push(sv[i+1]); push(sv[i+2]);
            push(sv[i+1]); push(sv[i+3]); push(sv[i+2]);
        }
        break;
    default:
        return;
    }

    if (!verts.empty())
        HLE_DrawBatch2D(verts.data(), static_cast<uint32_t>(verts.size()), topo, srv, isAlphaOnly);
}

// Full draw: resolve texture from guest state then call DrawSWVertsD3D11
static void DrawSWVertsWithTexD3D11(uint8_t* base, const SWVertex* sv, size_t n, int primType)
{
    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    bool useTexture  = (texAddr != 0 && ColorOpUsesTexture());

    ID3D11ShaderResourceView* srv = nullptr;
    bool isAlphaOnly = false;
    if (useTexture) {
        srv = GetOrCreateTextureSRV(base, texAddr);
        if (srv) {
            auto it = g_d3d11.textureCache.find(texAddr);
            if (it != g_d3d11.textureCache.end())
                isAlphaOnly = it->second.isAlphaOnly;
        }
    }

    DrawSWVertsD3D11(base, sv, n, primType, srv, isAlphaOnly);
}

// ---- Texture sampling support for the software rasterizer ----
struct SoftTexInfo {
    uint8_t* mem;        // guest memory base pointer
    uint32_t dataAddr;   // guest address of pixel data
    uint32_t width;
    uint32_t height;
    uint32_t format;     // Xbox D3D format code
    uint32_t palDataAddr; // guest address of palette data (256 * 4 bytes), 0 if none
};

// Xbox swizzle (Morton / Z-order) offset for power-of-2 textures
static uint32_t XboxSwizzle(uint32_t x, uint32_t y, uint32_t w, uint32_t h) {
    uint32_t off = 0, sh = 0;
    uint32_t mX = w - 1, mY = h - 1;
    for (uint32_t b = 1; b <= mX || b <= mY; b <<= 1) {
        if (b <= mX) { if (x & b) off |= (1u << sh); sh++; }
        if (b <= mY) { if (y & b) off |= (1u << sh); sh++; }
    }
    return off;
}

static inline void DecodeRGB565(uint16_t c, uint32_t& r, uint32_t& g, uint32_t& b) {
    r = ((c >> 11) & 0x1F) * 255 / 31;
    g = ((c >> 5)  & 0x3F) * 255 / 63;
    b = ((c >> 0)  & 0x1F) * 255 / 31;
}

// Sample a single texel at integer coordinates
static uint32_t SampleTexel(const SoftTexInfo& tex, uint32_t x, uint32_t y) {
    if (x >= tex.width)  x = tex.width  - 1;
    if (y >= tex.height) y = tex.height - 1;
    uint8_t* m = tex.mem;
    bool lin = (tex.format == X_D3DFMT_LIN_A8R8G8B8 || tex.format == X_D3DFMT_LIN_X8R8G8B8);

    // 32-bit ARGB (swizzled or linear)
    if (tex.format == X_D3DFMT_A8R8G8B8 || tex.format == X_D3DFMT_X8R8G8B8 ||
        tex.format == X_D3DFMT_LIN_A8R8G8B8 || tex.format == X_D3DFMT_LIN_X8R8G8B8) {
        uint32_t off = lin ? (y * tex.width + x) : XboxSwizzle(x, y, tex.width, tex.height);
        uint32_t t = *(uint32_t*)(m + tex.dataAddr + off * 4);
        if (tex.format == X_D3DFMT_X8R8G8B8 || tex.format == X_D3DFMT_LIN_X8R8G8B8)
            t |= 0xFF000000u;
        return t;
    }
    // 16-bit A4R4G4B4 (swizzled)
    if (tex.format == X_D3DFMT_A4R4G4B4) {
        uint32_t off = XboxSwizzle(x, y, tex.width, tex.height);
        uint16_t raw = *(uint16_t*)(m + tex.dataAddr + off * 2);
        return (((raw >> 12) & 0xF) * 17u << 24) | (((raw >> 8) & 0xF) * 17u << 16) |
               (((raw >> 4) & 0xF) * 17u << 8)  |  ((raw & 0xF) * 17u);
    }
    // 16-bit A1R5G5B5 (swizzled)
    if (tex.format == X_D3DFMT_A1R5G5B5) {
        uint32_t off = XboxSwizzle(x, y, tex.width, tex.height);
        uint16_t raw = *(uint16_t*)(m + tex.dataAddr + off * 2);
        uint32_t a = (raw & 0x8000) ? 255 : 0;
        uint32_t r = ((raw >> 10) & 0x1F) * 255 / 31;
        uint32_t g = ((raw >> 5)  & 0x1F) * 255 / 31;
        uint32_t b = (raw & 0x1F) * 255 / 31;
        return (a << 24) | (r << 16) | (g << 8) | b;
    }
    // DXT compressed formats — Xbox DXT uses linear block order (not swizzled)
    if (tex.format == X_D3DFMT_DXT1 || tex.format == X_D3DFMT_DXT3 ||
        tex.format == X_D3DFMT_DXT5) {
        uint32_t bx = x / 4, by = y / 4, ix = x % 4, iy = y % 4;
        uint32_t bpr = (tex.width + 3) / 4;
        uint32_t bsz = (tex.format == X_D3DFMT_DXT1) ? 8 : 16;
        uint8_t* blk = m + tex.dataAddr + (by * bpr + bx) * bsz;

        uint8_t* cb = (tex.format == X_D3DFMT_DXT1) ? blk : blk + 8;
        uint16_t cc0 = *(uint16_t*)(cb), cc1 = *(uint16_t*)(cb + 2);
        uint32_t bits = *(uint32_t*)(cb + 4);
        uint32_t idx = (bits >> (2 * (iy * 4 + ix))) & 3;
        uint32_t r0, g0, b0, r1, g1, b1;
        DecodeRGB565(cc0, r0, g0, b0);
        DecodeRGB565(cc1, r1, g1, b1);

        uint32_t r, g, b, a = 255;
        if (idx == 0)      { r = r0; g = g0; b = b0; }
        else if (idx == 1) { r = r1; g = g1; b = b1; }
        else if (cc0 > cc1 || tex.format != X_D3DFMT_DXT1) {
            if (idx == 2) { r = (2*r0+r1)/3; g = (2*g0+g1)/3; b = (2*b0+b1)/3; }
            else          { r = (r0+2*r1)/3; g = (g0+2*g1)/3; b = (b0+2*b1)/3; }
        } else {
            if (idx == 2) { r = (r0+r1)/2; g = (g0+g1)/2; b = (b0+b1)/2; }
            else          { r = 0; g = 0; b = 0; a = 0; }
        }

        if (tex.format == X_D3DFMT_DXT3) {
            uint32_t ai = iy * 4 + ix;
            uint8_t ab = blk[ai / 2];
            a = ((ai & 1) ? (ab >> 4) : (ab & 0xF)) * 17u;
        } else if (tex.format == X_D3DFMT_DXT5) {
            uint8_t al0 = blk[0], al1 = blk[1];
            uint64_t abits = 0;
            for (int i = 0; i < 6; i++) abits |= (uint64_t)blk[2 + i] << (8 * i);
            uint32_t ai = (uint32_t)((abits >> (3 * (iy * 4 + ix))) & 7);
            if      (ai == 0) a = al0;
            else if (ai == 1) a = al1;
            else if (al0 > al1) a = ((8 - ai) * al0 + (ai - 1) * al1) / 7;
            else if (ai < 6)    a = ((6 - ai) * al0 + (ai - 1) * al1) / 5;
            else                 a = (ai == 6) ? 0 : 255;
        }
        return (a << 24) | (r << 16) | (g << 8) | b;
    }
    // P8 palettized (swizzled, 1 byte per pixel)
    if (tex.format == X_D3DFMT_P8) {
        uint32_t off = XboxSwizzle(x, y, tex.width, tex.height);
        uint8_t idx = *(uint8_t*)(m + tex.dataAddr + off);
        if (tex.palDataAddr == 0) return 0xFFFFFFFFu; // white if palette missing
        return *(uint32_t*)(m + tex.palDataAddr + idx * 4);
    }
    return 0xFFFF00FFu; // magenta = unsupported format
}

static void SoftRasterTriangle(uint32_t* fb, uint32_t fbW, uint32_t fbH,
                                float x0, float y0, float u0, float v0, uint32_t c0,
                                float x1, float y1, float u1, float v1, uint32_t c1,
                                float x2, float y2, float u2, float v2, uint32_t c2,
                                const SoftTexInfo* tex)
{
    int minX = (int)std::floor(std::min({x0, x1, x2}));
    int maxX = (int)std::ceil (std::max({x0, x1, x2}));
    int minY = (int)std::floor(std::min({y0, y1, y2}));
    int maxY = (int)std::ceil (std::max({y0, y1, y2}));
    if (minX < 0) minX = 0;
    if (minY < 0) minY = 0;
    if (maxX >= (int)fbW) maxX = (int)fbW - 1;
    if (maxY >= (int)fbH) maxY = (int)fbH - 1;

    float denom = (y1 - y2) * (x0 - x2) + (x2 - x1) * (y0 - y2);
    if (std::fabs(denom) < 0.0001f) return;
    float inv = 1.0f / denom;

    for (int py = minY; py <= maxY; py++) {
        float fy = py + 0.5f;
        for (int px = minX; px <= maxX; px++) {
            float fx = px + 0.5f;
            float w0 = ((y1 - y2) * (fx - x2) + (x2 - x1) * (fy - y2)) * inv;
            float w1 = ((y2 - y0) * (fx - x2) + (x0 - x2) * (fy - y2)) * inv;
            if (w0 < 0.0f || w1 < 0.0f || (w0 + w1) > 1.001f) continue;

            float w2 = 1.0f - w0 - w1;

            // Interpolate diffuse colour (Gouraud shading)
            uint32_t da = (uint32_t)(w0*((c0>>24)&0xFF) + w1*((c1>>24)&0xFF) + w2*((c2>>24)&0xFF));
            uint32_t dr = (uint32_t)(w0*((c0>>16)&0xFF) + w1*((c1>>16)&0xFF) + w2*((c2>>16)&0xFF));
            uint32_t dg = (uint32_t)(w0*((c0>> 8)&0xFF) + w1*((c1>> 8)&0xFF) + w2*((c2>> 8)&0xFF));
            uint32_t db = (uint32_t)(w0*( c0     &0xFF) + w1*( c1     &0xFF) + w2*( c2     &0xFF));

            uint32_t color;
            if (tex) {
                float su = std::max(0.0f, std::min(w0*u0 + w1*u1 + w2*u2, 1.0f));
                float sv = std::max(0.0f, std::min(w0*v0 + w1*v1 + w2*v2, 1.0f));
                uint32_t tx = std::min((uint32_t)(su * tex->width),  tex->width  - 1);
                uint32_t ty = std::min((uint32_t)(sv * tex->height), tex->height - 1);
                uint32_t texel = SampleTexel(*tex, tx, ty);
                uint32_t ta = (texel >> 24) & 0xFF, tr = (texel >> 16) & 0xFF;
                uint32_t tg = (texel >>  8) & 0xFF, tb = texel & 0xFF;
                uint32_t fa = (ta*da)/255, fr = (tr*dr)/255;
                uint32_t fg = (tg*dg)/255, fbl = (tb*db)/255;
                // Alpha test (only when enabled by game render state)
                if (g_alphaTestEnabled && fa <= g_alphaRef) continue;
                if (g_alphaBlendEnabled && fa < 255) {
                    // Simple SrcAlpha/InvSrcAlpha blend
                    uint32_t dst = fb[py * fbW + px];
                    uint32_t ddr = (dst >> 16) & 0xFF, ddg = (dst >> 8) & 0xFF, ddb = dst & 0xFF;
                    uint32_t invA = 255 - fa;
                    fr = (fr * fa + ddr * invA) / 255;
                    fg = (fg * fa + ddg * invA) / 255;
                    fbl = (fbl * fa + ddb * invA) / 255;
                    fa = 255;
                }
                color = (fa << 24) | (fr << 16) | (fg << 8) | fbl;
            } else {
                color = (da << 24) | (dr << 16) | (dg << 8) | db;
            }
            fb[py * fbW + px] = color;
        }
    }
}

// D3DDevice_DrawVerticesUP  (0x34FD80) — __stdcall, 4 args, ret 16
//
// Software-rasterises pre-transformed 2D triangles to the current render
// target.  Vertex format assumed: float X, float Y at offset 0,4 and
// DWORD diffuse colour (ARGB) at offset 16 within each vertex.
void D3DDevice_DrawVerticesUP(X86Context& ctx, uint8_t* base) {
    uint32_t primType  = GuestArg32(ctx, base, 0);
    uint32_t vtxCount  = GuestArg32(ctx, base, 1);
    uint32_t pVtxData  = GuestArg32(ctx, base, 2);
    uint32_t vtxStride = GuestArg32(ctx, base, 3);

    if (pVtxData == 0 || vtxCount == 0 || vtxStride < 20) {
        GuestStackCleanup(ctx, 16);
        return;
    }


    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    bool useTexture  = (texAddr != 0 && ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;
    bool isAlphaOnly = false;
    uint32_t texW = 1, texH = 1;
    if (useTexture) {
        srv = GetOrCreateTextureSRV(base, texAddr);
        if (srv) {
            auto it = g_d3d11.textureCache.find(texAddr);
            if (it != g_d3d11.textureCache.end()) {
                isAlphaOnly = it->second.isAlphaOnly;
                texW = it->second.width;
                texH = it->second.height;
            }
        }
    }

    // Detect if UVs are in pixel coordinates (only relevant for non-stride-28 format)
    bool uvInPixels = false;
    if (vtxStride != 28 && srv && texW > 1 && texH > 1) {
        float maxUV = 0.0f;
        for (uint32_t i = 0; i < vtxCount; i++) {
            uint32_t off = pVtxData + i * vtxStride;
            float us, vs;
            memcpy(&us, base + off + 8,  4);
            memcpy(&vs, base + off + 12, 4);
            if (fabsf(us) > maxUV) maxUV = fabsf(us);
            if (fabsf(vs) > maxUV) maxUV = fabsf(vs);
        }
        uvInPixels = (maxUV > 1.5f);
    }

    // Build normalized Vtx2D array
    std::vector<Vtx2D> v2d(vtxCount);
    for (uint32_t i = 0; i < vtxCount; i++) {
        uint32_t off = pVtxData + i * vtxStride;
        float x, y, u, v;
        uint32_t col;
        memcpy(&x, base + off,     4);
        memcpy(&y, base + off + 4, 4);
        if (vtxStride == 28) {
            // D3DFVF_XYZRHW|DIFFUSE|TEX1: X@0,Y@4,Z@8,W@12,col@16,U@20,V@24
            col = X86_MEM_READ_u32(base, off + 16);
            memcpy(&u, base + off + 20, 4);
            memcpy(&v, base + off + 24, 4);
        } else {
            // RW custom format: X@0,Y@4,U@8,V@12,col@16
            float ur, vr;
            memcpy(&ur, base + off + 8,  4);
            memcpy(&vr, base + off + 12, 4);
            col = X86_MEM_READ_u32(base, off + 16);
            if (uvInPixels) {
                u = ur / static_cast<float>(texW);
                v = vr / static_cast<float>(texH);
            } else {
                u = ur; v = vr;
            }
        }
        v2d[i] = {x, y, u, v, col};
    }

    // Map NV2A primitive types to D3D11 topology (expand fans/quads)
    std::vector<Vtx2D> expanded;
    D3D_PRIMITIVE_TOPOLOGY topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

    switch (primType) {
    case NV2A_PRIM_TRIANGLES:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        expanded = v2d;
        break;
    case NV2A_PRIM_TRISTRIP:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
        expanded = v2d;
        break;
    case NV2A_PRIM_TRIFAN:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (uint32_t i = 1; i + 1 < vtxCount; i++) {
            expanded.push_back(v2d[0]);
            expanded.push_back(v2d[i]);
            expanded.push_back(v2d[i+1]);
        }
        break;
    case NV2A_PRIM_QUADS:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (uint32_t i = 0; i + 3 < vtxCount; i += 4) {
            expanded.push_back(v2d[i]);   expanded.push_back(v2d[i+1]); expanded.push_back(v2d[i+2]);
            expanded.push_back(v2d[i]);   expanded.push_back(v2d[i+2]); expanded.push_back(v2d[i+3]);
        }
        break;
    default:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        expanded = v2d;
        break;
    }

    if (!expanded.empty())
        HLE_DrawBatch2D(expanded.data(), static_cast<uint32_t>(expanded.size()),
                        topo, srv, isAlphaOnly);

    GuestStackCleanup(ctx, 16);
}

void D3DDevice_DrawIndexedVertices(X86Context& ctx, uint8_t* base) {
    uint32_t primType   = GuestArg32(ctx, base, 0);
    uint32_t indexCount = GuestArg32(ctx, base, 1);
    uint32_t pIndexData = GuestArg32(ctx, base, 2);

    uint32_t vbAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x1660);
    uint32_t stride = X86_MEM_READ_u32(base, kDeviceAddr + 0x1664);
    if (pIndexData == 0 || vbAddr == 0 || indexCount == 0 || stride < 20) {
        GuestStackCleanup(ctx, 12); return;
    }

    // Drain any inline NV2A push-buffer writes (constants etc.) before
    // checking shader-program preconditions.
    WalkPushBuffer(base);

    // Programmable vertex shader path — transform via NV2A constants (3D).
    uint32_t liveVSi = LiveVSHandle(base);
    static int s_drawProbeI = 0;
    if (s_drawProbeI < 20) {
        fprintf(stderr,
            "[HLE] DrawIndexedVertices prim=%u ic=%u stride=%u vb=0x%X idx=0x%X "
            "liveVS=0x%X mvp=%d\n",
            primType, indexCount, stride, vbAddr, pIndexData,
            liveVSi, (int)HasMvpConstants(base));
        s_drawProbeI++;
    }
    if ((liveVSi & 1) && g_d3d11.vs3D && HasMvpConstants(base)) {
        static int s_log3Di = 0;
        if (s_log3Di < 8) {
            // fprintf(stderr,
            //     "[HLE] Draw3D(indexed) prim=%u ic=%u stride=%u vb=0x%X idx=0x%X\n",
            //     primType, indexCount, stride, vbAddr, pIndexData);
            s_log3Di++;
        }
        HLE_Draw3D(base, primType, 0, 0, indexCount, pIndexData);
        GuestStackCleanup(ctx, 12);
        return;
    }

    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    bool useTexture  = (texAddr != 0 && ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;
    bool isAlphaOnly = false;
    if (useTexture) {
        srv = GetOrCreateTextureSRV(base, texAddr);
        if (srv) {
            auto it = g_d3d11.textureCache.find(texAddr);
            if (it != g_d3d11.textureCache.end())
                isAlphaOnly = it->second.isAlphaOnly;
        }
    }

    auto readVtx = [&](uint32_t idx) -> Vtx2D {
        uint32_t off = vbAddr + idx * stride;
        float x, y, u = 0.f, v = 0.f;
        memcpy(&x, base + off, 4);
        memcpy(&y, base + off + 4, 4);
        if (stride >= 24) {
            memcpy(&u, base + off + 8,  4);
            memcpy(&v, base + off + 12, 4);
        }
        uint32_t col = X86_MEM_READ_u32(base, off + 16);
        return {x, y, u, v, col};
    };
    auto readIdx = [&](uint32_t i) -> uint32_t {
        return static_cast<uint32_t>(X86_MEM_READ_u16(base, pIndexData + i * 2));
    };

    std::vector<Vtx2D> expanded;
    D3D_PRIMITIVE_TOPOLOGY topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

    switch (primType) {
    case NV2A_PRIM_TRIANGLES:
        for (uint32_t i = 0; i < indexCount; i++)
            expanded.push_back(readVtx(readIdx(i)));
        break;
    case NV2A_PRIM_TRISTRIP:
        for (uint32_t i = 0; i + 2 < indexCount; i++) {
            if (i & 1) {
                expanded.push_back(readVtx(readIdx(i+1)));
                expanded.push_back(readVtx(readIdx(i)));
            } else {
                expanded.push_back(readVtx(readIdx(i)));
                expanded.push_back(readVtx(readIdx(i+1)));
            }
            expanded.push_back(readVtx(readIdx(i+2)));
        }
        break;
    case NV2A_PRIM_TRIFAN: {
        auto v0 = readVtx(readIdx(0));
        for (uint32_t i = 1; i + 1 < indexCount; i++) {
            expanded.push_back(v0);
            expanded.push_back(readVtx(readIdx(i)));
            expanded.push_back(readVtx(readIdx(i+1)));
        }
        break;
    }
    case NV2A_PRIM_QUADS:
        for (uint32_t i = 0; i + 3 < indexCount; i += 4) {
            auto v0 = readVtx(readIdx(i)),   v1 = readVtx(readIdx(i+1));
            auto v2 = readVtx(readIdx(i+2)), v3 = readVtx(readIdx(i+3));
            expanded.push_back(v0); expanded.push_back(v1); expanded.push_back(v2);
            expanded.push_back(v0); expanded.push_back(v2); expanded.push_back(v3);
        }
        break;
    default:
        GuestStackCleanup(ctx, 12); return;
    }

    if (!expanded.empty())
        HLE_DrawBatch2D(expanded.data(), static_cast<uint32_t>(expanded.size()),
                        topo, srv, isAlphaOnly);

    GuestStackCleanup(ctx, 12);
}

void D3D_SwapSetState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapSetState (0x00350370) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapSaveState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapSaveState (0x003504C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapRestoreState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapRestoreState (0x003505A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_SwapSaveSurfaces(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapSaveSurfaces (0x003507D0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapRestoreSurfaces(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapRestoreSurfaces (0x003508B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapCopyBlt(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapCopyBlt (0x00350950) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_Encode_NVX_FLIP(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Encode_NVX_FLIP (0x00350BD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapCopy(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapCopy (0x00350C10) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_SwapFlip(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapFlip (0x00350DB0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapFirstFlip(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapFirstFlip (0x00350EC0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SwapFinish(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SwapFinish (0x00351050) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_351180(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_351180 (0x00351180) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void D3DCubeTexture_GetCubeMapSurface2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DCubeTexture_GetCubeMapSurface2 (0x00351370) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void D3DCubeTexture_LockRect(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DCubeTexture_LockRect (0x003513C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 24);
}

void D3D_CDevice_InitializePushBuffer(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CDevice_InitializePushBuffer (0x003513F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_ComputeGap(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ComputeGap (0x00351550) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_FindFence(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_FindFence (0x00351580) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CDevice_GpuGet(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CDevice_GpuGet (0x00351680) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_GpuGetOrNewer(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_GpuGetOrNewer (0x00351700) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CDevice_ReentrantKickOffAndWait(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CDevice_ReentrantKickOffAndWait (0x00351AE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_FlushWCCache(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_FlushWCCache (0x00351BD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3DDevice_IsFencePending(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_IsFencePending (0x00351C00) called\n"); logged = true; }
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

void D3DDevice_BeginPush(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_BeginPush (0x00351C20) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3DDevice_EndPush(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3DDevice_EndPush (0x00351C80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_DumpMatrixTransposed(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_DumpMatrixTransposed (0x00351C90) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_FloatToLong(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_FloatToLong (0x00351DB0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_351DC0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_351DC0 (0x00351DC0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_Exp(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Exp (0x00351DD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_Log(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Log (0x00351E30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_Log2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Log2 (0x00351E40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_MapToLinearD3DFORMAT(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_MapToLinearD3DFORMAT (0x00351E50) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CalcTilePitch(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CalcTilePitch (0x00351EF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_PixelJar_GetSurfaceFormat(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_PixelJar_GetSurfaceFormat (0x00351F30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_PixelJar_GetDepthBufferScale(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_PixelJar_GetDepthBufferScale (0x00352040) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// D3D_PixelJar_GetSize  (0x352090) — register-call: ECX=pPixelContainer,
//   EAX=mipLevel; 5 stack args (20 bytes) = output pointers:
//   arg0=pOutWidth, arg1=pOutHeight, arg2=pOutDepth,
//   arg3=pOutPitch, arg4=pOutSlicePitch
//
// Computes the dimensions, pitch, and slice pitch for a given mip level
// of an Xbox D3D pixel container (texture/surface).
void D3D_PixelJar_GetSize(X86Context& ctx, uint8_t* base) {
    uint32_t pTex     = ctx.ecx;
    uint32_t mipLevel = ctx.eax;

    uint32_t pOutWidth  = GuestArg32(ctx, base, 0);
    uint32_t pOutHeight = GuestArg32(ctx, base, 1);
    uint32_t pOutDepth  = GuestArg32(ctx, base, 2);
    uint32_t pOutPitch  = GuestArg32(ctx, base, 3);
    uint32_t pOutSlice  = GuestArg32(ctx, base, 4);

    uint32_t texFormat = X86_MEM_READ_u32(base, pTex + 0x0C);
    uint32_t texSize   = X86_MEM_READ_u32(base, pTex + 0x10);

    uint32_t fmtCode  = (texFormat >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
    uint8_t  fmtInfo  = XboxFormatInfo(fmtCode);
    uint32_t bppField = fmtInfo & 0x3C; // bits-per-pixel
    bool     isDXT    = IsCompressedFormat(fmtCode);

    uint32_t w, h, d, pitch, slicePitch;

    if (texSize != 0) {
        // Non-power-of-2 / linear texture: dimensions in Size field
        w = (texSize & X_D3DSIZE_WIDTH_MASK) + 1;
        h = ((texSize >> X_D3DSIZE_HEIGHT_SHIFT) & 0xFFF) + 1;
        d = 1;
        uint32_t pitchRaw = (texSize >> X_D3DSIZE_PITCH_SHIFT) & 0xFF;
        pitch = (pitchRaw + 1) << 6;
        slicePitch = pitch * h;
    } else {
        // Power-of-2 / swizzled texture: dimensions in Format field
        int32_t logU = ((texFormat >> X_D3DFORMAT_USIZE_SHIFT) & 0xF) - (int32_t)mipLevel;
        int32_t logV = ((texFormat >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF) - (int32_t)mipLevel;
        int32_t logP = ((texFormat >> X_D3DFORMAT_PSIZE_SHIFT) & 0xF) - (int32_t)mipLevel;
        w = (logU > 0) ? (1u << logU) : 1;
        h = (logV > 0) ? (1u << logV) : 1;
        d = (logP > 0) ? (1u << logP) : 1;

        if (isDXT) {
            uint32_t bw = (w + 3) / 4;
            pitch = bw * (fmtCode == 0x0C ? 8 : 16);
        } else {
            pitch = bppField * w / 8;
        }
        slicePitch = pitch * (isDXT ? ((h + 3) / 4) : h);
    }

    if (pOutWidth)  X86_MEM_WRITE_u32(base, pOutWidth, w);
    if (pOutHeight) X86_MEM_WRITE_u32(base, pOutHeight, h);
    if (pOutDepth)  X86_MEM_WRITE_u32(base, pOutDepth, d);
    if (pOutPitch)  X86_MEM_WRITE_u32(base, pOutPitch, pitch);
    if (pOutSlice)  X86_MEM_WRITE_u32(base, pOutSlice, slicePitch);

    GuestStackCleanup(ctx, 20);
}

// D3D_PixelJar_Get2DSurfaceDesc  (0x3521F0) — register-call:
//   EDI = pPixelContainer, ESI = pOutSurfaceDesc, EBX = mipLevel
//   No stack args (ret 0).
//
// Fills an X_D3DSURFACE_DESC structure with:
//   +0x00: Format (format code byte from pixel container)
//   +0x04: Type   (D3DRESOURCETYPE from Common field)
//   +0x08: Usage  (0 = swizzled, 1 = linear, 2 = compressed/tiled)
//   +0x0C: Size   (pitch in bytes)
//   +0x10: MultiSampleType (from device if RT, else D3DMULTISAMPLE_NONE=0x11)
//   +0x14: Width
//   +0x18: Height
void D3D_PixelJar_Get2DSurfaceDesc(X86Context& ctx, uint8_t* base) {
    uint32_t pTex  = ctx.edi;
    uint32_t pDesc = ctx.esi;
    uint32_t mipLevel = ctx.ebx;

    // Format code byte at offset 0x0D in the pixel container
    uint8_t fmtCode = X86_MEM_READ_u8(base, pTex + 0x0D);
    X86_MEM_WRITE_u32(base, pDesc + 0x00, fmtCode);

    // Resource type from Common field
    uint32_t common = X86_MEM_READ_u32(base, pTex + 0x00);
    uint32_t commonType = common & X_D3DCOMMON_TYPE_MASK;
    uint32_t rType = X_D3DRTYPE_NONE;
    switch (commonType) {
    case X_D3DCOMMON_TYPE_VERTEXBUFFER: rType = X_D3DRTYPE_VERTEXBUFFER; break;
    case X_D3DCOMMON_TYPE_INDEXBUFFER:  rType = X_D3DRTYPE_INDEXBUFFER;  break;
    case X_D3DCOMMON_TYPE_PUSHBUFFER:   rType = X_D3DRTYPE_PUSHBUFFER;   break;
    case X_D3DCOMMON_TYPE_PALETTE:      rType = X_D3DRTYPE_PALETTE;      break;
    case X_D3DCOMMON_TYPE_TEXTURE:      rType = X_D3DRTYPE_TEXTURE;      break;
    case X_D3DCOMMON_TYPE_SURFACE:      rType = X_D3DRTYPE_SURFACE;      break;
    default: break;
    }
    X86_MEM_WRITE_u32(base, pDesc + 0x04, rType);

    // Usage / pool: check format table for linear / compressed
    uint8_t fmtInfo = XboxFormatInfo(fmtCode);
    uint32_t usage = 0;
    if ((int8_t)fmtInfo < 0)      usage = 1; // linear (bit 7 set)
    else if (fmtInfo & 0x40)      usage = 2; // compressed/tiled (bit 6 set)
    X86_MEM_WRITE_u32(base, pDesc + 0x08, usage);

    // MultiSampleType: if texture data matches the back buffer, use device MS type
    uint32_t devicePtr = X86_MEM_READ_u32(base, 0x35FB48);
    uint32_t texData   = X86_MEM_READ_u32(base, pTex + 0x04);
    uint32_t backBufAddr = X86_MEM_READ_u32(base, devicePtr + kDeviceBackBufBase);
    uint32_t backBufData = backBufAddr ? X86_MEM_READ_u32(base, backBufAddr + 0x04) : 0;
    if (texData == backBufData && backBufAddr != 0) {
        uint32_t msType = X86_MEM_READ_u32(base, devicePtr + 0x196C);
        X86_MEM_WRITE_u32(base, pDesc + 0x10, msType);
    } else {
        X86_MEM_WRITE_u32(base, pDesc + 0x10, 0x11); // D3DMULTISAMPLE_NONE
    }

    // Compute width, height, pitch via the same logic as GetSize
    uint32_t texFormat = X86_MEM_READ_u32(base, pTex + 0x0C);
    uint32_t texSize   = X86_MEM_READ_u32(base, pTex + 0x10);
    uint32_t bppField  = fmtInfo & 0x3C;
    bool     isDXT     = IsCompressedFormat(fmtCode);
    uint32_t w, h, pitch;

    if (texSize != 0) {
        w = (texSize & X_D3DSIZE_WIDTH_MASK) + 1;
        h = ((texSize >> X_D3DSIZE_HEIGHT_SHIFT) & 0xFFF) + 1;
        uint32_t pitchRaw = (texSize >> X_D3DSIZE_PITCH_SHIFT) & 0xFF;
        pitch = (pitchRaw + 1) << 6;
    } else {
        int32_t logU = ((texFormat >> X_D3DFORMAT_USIZE_SHIFT) & 0xF) - (int32_t)mipLevel;
        int32_t logV = ((texFormat >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF) - (int32_t)mipLevel;
        w = (logU > 0) ? (1u << logU) : 1;
        h = (logV > 0) ? (1u << logV) : 1;
        if (isDXT) {
            uint32_t bw = (w + 3) / 4;
            pitch = bw * (fmtCode == 0x0C ? 8 : 16);
        } else {
            pitch = bppField * w / 8;
        }
    }

    X86_MEM_WRITE_u32(base, pDesc + 0x14, w);
    X86_MEM_WRITE_u32(base, pDesc + 0x18, h);
    X86_MEM_WRITE_u32(base, pDesc + 0x0C, pitch);

    // No stack args, plain ret
}

// D3D_PixelJar_FindSurfaceWithinTexture  (0x352290) — 8 args, ret 32
//
// Locates the data pointer, pitch, and format/size info for a specific
// mipmap level (and optionally a cubemap face / volume slice) within a
// texture resource.
//
// Register inputs: (none used)
// Stack args:
//   arg0 = pTexture   — X_D3DPixelContainer*
//   arg1 = mipLevel   — mipmap level to skip to
//   arg2 = face/slice — cubemap face or volume slice index
//   arg3 = pOutData   — (uint32_t*) receives the data pointer for this level
//   arg4 = pOutPitch  — (uint32_t*) receives row pitch (bytes per row)
//   arg5 = pOutSlice  — (uint32_t*) receives slice pitch (bytes per 2-D slice)
//   arg6 = pOutFormat — (uint32_t*) receives the encoded Format DWORD
//   arg7 = pOutSize   — (uint32_t*) receives the encoded Size DWORD
void D3D_PixelJar_FindSurfaceWithinTexture(X86Context& ctx, uint8_t* base) {
    uint32_t pTex      = GuestArg32(ctx, base, 0);
    uint32_t mipLevel  = GuestArg32(ctx, base, 1);
    uint32_t faceSlice = GuestArg32(ctx, base, 2);
    uint32_t pOutData  = GuestArg32(ctx, base, 3);
    uint32_t pOutPitch = GuestArg32(ctx, base, 4);
    uint32_t pOutSlice = GuestArg32(ctx, base, 5);
    uint32_t pOutFmt   = GuestArg32(ctx, base, 6);
    uint32_t pOutSize  = GuestArg32(ctx, base, 7);

    if (pTex == 0) {
        if (pOutData)  X86_MEM_WRITE_u32(base, pOutData, 0);
        if (pOutPitch) X86_MEM_WRITE_u32(base, pOutPitch, 0);
        if (pOutSlice) X86_MEM_WRITE_u32(base, pOutSlice, 0);
        if (pOutFmt)   X86_MEM_WRITE_u32(base, pOutFmt, 0);
        if (pOutSize)  X86_MEM_WRITE_u32(base, pOutSize, 0);
        GuestStackCleanup(ctx, 32);
        return;
    }

    uint32_t texData   = X86_MEM_READ_u32(base, pTex + 0x04) | 0x80000000;
    uint32_t texFormat = X86_MEM_READ_u32(base, pTex + 0x0C);
    uint32_t texSize   = X86_MEM_READ_u32(base, pTex + 0x10);

    uint32_t fmtCode = (texFormat >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
    uint8_t  fmtInfo = XboxFormatInfo(fmtCode);
    uint32_t bppField = fmtInfo & 0x3C;      // bits-per-pixel (4, 8, 16, or 32)
    bool     isDXT    = IsCompressedFormat(fmtCode);
    uint32_t dxtShift = isDXT ? (fmtCode == 0x0C ? 1 : 2) : 0;

    uint32_t logU, logV, logP;
    uint32_t w, h, pitch;
    uint32_t dataOffset = 0;

    if (texSize != 0) {
        // Non-power-of-2 / linear texture: dimensions in Size field
        uint32_t pitchRaw = (texSize >> 24) & 0xFF;
        pitch = (pitchRaw + 1) << 6;               // 64-byte units
        h = ((texSize >> 12) & 0xFFF) + 1;
        w = (texSize & 0xFFF) + 1;
        uint32_t sliceSize = pitch * h;

        // Face/slice offset
        dataOffset = sliceSize * faceSlice;

        // Write outputs — for non-pow2 textures the format/size pass through
        if (pOutFmt)   X86_MEM_WRITE_u32(base, pOutFmt, texFormat);
        if (pOutSize)  X86_MEM_WRITE_u32(base, pOutSize, texSize);
        if (pOutData)  X86_MEM_WRITE_u32(base, pOutData, texData + dataOffset);
        if (pOutPitch) X86_MEM_WRITE_u32(base, pOutPitch, pitch);
        if (pOutSlice) X86_MEM_WRITE_u32(base, pOutSlice, sliceSize);
    } else {
        // Power-of-2 / swizzled texture: dimensions in Format field
        logU = (texFormat >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        logV = (texFormat >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        logP = (texFormat >> X_D3DFORMAT_PSIZE_SHIFT) & 0xF;

        // Step through mipmap levels to accumulate offset
        uint32_t mU = logU, mV = logV, mP = logP;
        uint32_t offset = 0;
        uint32_t compMin = isDXT ? 2 : 0;  // compressed formats: min dimension in log2

        for (uint32_t i = 0; i < mipLevel; i++) {
            uint32_t curU = (mU > compMin) ? mU : compMin;
            uint32_t curV = (mV > compMin) ? mV : compMin;
            uint32_t levelBits = curU + curV + mP;
            uint32_t levelSize = (1u << levelBits) * bppField / 8;
            offset += levelSize;
            if (mU > 0) mU--;
            if (mV > 0) mV--;
            if (mP > 0) mP--;
        }

        // Round mip offset to 128-byte boundary
        offset = (offset + 127) & ~127u;

        // Face/slice offset (cubemaps have 6 faces per mip chain)
        if (faceSlice > 0) {
            uint32_t fullMipChainSize = 0;
            uint32_t tU = logU, tV = logV, tP = logP;
            uint32_t mipCount = ((texFormat >> X_D3DFORMAT_MIPMAP_SHIFT) & 0xF) + 1;
            for (uint32_t i = 0; i < mipCount; i++) {
                uint32_t curU = (tU > compMin) ? tU : compMin;
                uint32_t curV = (tV > compMin) ? tV : compMin;
                uint32_t levelBits = curU + curV + tP;
                fullMipChainSize += (1u << levelBits) * bppField / 8;
                if (tU > 0) tU--;
                if (tV > 0) tV--;
                if (tP > 0) tP--;
            }
            fullMipChainSize = (fullMipChainSize + 127) & ~127u;
            offset += fullMipChainSize * faceSlice;
        }

        // Dimensions at the requested mip level
        uint32_t curU = (mU > compMin) ? mU : compMin;
        uint32_t curV = (mV > compMin) ? mV : compMin;
        w = 1u << curU;
        h = 1u << curV;

        if (isDXT) {
            pitch = (w / 4) * (fmtCode == 0x0C ? 8 : 16);
        } else {
            pitch = bppField * w / 8;
        }

        // Encoded format for the mip level
        uint32_t mipFmt = (texFormat & 0x000FFFFF)
                        | (mU << 20) | (mV << 24) | (mP << 28);

        if (pOutFmt)   X86_MEM_WRITE_u32(base, pOutFmt, mipFmt);
        if (pOutSize)  X86_MEM_WRITE_u32(base, pOutSize, texSize);
        if (pOutData)  X86_MEM_WRITE_u32(base, pOutData, texData + offset);
        if (pOutPitch) X86_MEM_WRITE_u32(base, pOutPitch, pitch);
        if (pOutSlice) X86_MEM_WRITE_u32(base, pOutSlice, pitch * h);
    }

    GuestStackCleanup(ctx, 32);
}

void D3D_PixelJar_Lock2DSurface(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_PixelJar_Lock2DSurface (0x003524D0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

// D3D_PixelJar_EncodeFormat  (0x352560) — 8 args, ret 32
//
// Encodes texture dimensions and format into Xbox D3D Format / Size DWORDs
// and returns the total pixel-data allocation size in EAX.
//
// Register inputs:
//   EAX = width
//   EDX = height
// Stack args:
//   arg0 = levels    — mipmap level count
//   arg1 = dim       — dimension flags (1 = 2D)
//   arg2 = format    — Xbox D3D format code
//   arg3 = pitch     — row pitch in bytes (0 = auto-calculate)
//   arg4 = depth     — depth for 3-D / volume textures
//   arg5 = (unused)
//   arg6 = pOutFmt   — (uint32_t*) receives encoded Format DWORD
//   arg7 = pOutSize  — (uint32_t*) receives encoded Size DWORD
void D3D_PixelJar_EncodeFormat(X86Context& ctx, uint8_t* base) {
    uint32_t width   = ctx.eax;
    uint32_t height  = ctx.edx;
    uint32_t levels  = GuestArg32(ctx, base, 0);
    uint32_t dim     = GuestArg32(ctx, base, 1);
    uint32_t format  = GuestArg32(ctx, base, 2);
    uint32_t pitch   = GuestArg32(ctx, base, 3);
    uint32_t depth   = GuestArg32(ctx, base, 4);
    uint32_t pFmtOut  = GuestArg32(ctx, base, 6);
    uint32_t pSizeOut = GuestArg32(ctx, base, 7);

    uint8_t  fmtInfo  = XboxFormatInfo(format);
    uint32_t bppField = fmtInfo & 0x3C;      // bits per pixel
    bool     isLinear = (fmtInfo & 1) != 0;
    bool     isDXT    = IsCompressedFormat(format);

    if (levels == 0) levels = 1;
    if (depth  == 0) depth  = 1;
    if (width  == 0) width  = 1;
    if (height == 0) height = 1;

    // ---------- Compute row pitch ----------
    if (pitch == 0) {
        if (isDXT) {
            uint32_t bw = (width + 3) / 4;
            uint32_t blockBytes = (format == 0x0C) ? 8 : 16;
            pitch = bw * blockBytes;
        } else {
            pitch = bppField * width / 8;
        }
        // Align to 64 bytes
        pitch = (pitch + 63) & ~63u;
    }

    // ---------- Compute total data size ----------
    uint32_t totalSize;
    if (isLinear || isDXT) {
        uint32_t rowHeight = isDXT ? ((height + 3) / 4) : height;
        totalSize = pitch * rowHeight * depth;
    } else {
        totalSize = pitch * height * depth;
    }

    // Mipmap chain: add progressively smaller levels
    if (levels > 1) {
        uint32_t mipW = width, mipH = height, mipD = depth;
        for (uint32_t i = 1; i < levels; i++) {
            if (mipW > 1) mipW >>= 1;
            if (mipH > 1) mipH >>= 1;
            if (mipD > 1) mipD >>= 1;
            uint32_t mipPitch;
            if (isDXT) {
                uint32_t bw = (mipW + 3) / 4;
                mipPitch = bw * ((format == 0x0C) ? 8 : 16);
            } else {
                mipPitch = bppField * mipW / 8;
            }
            mipPitch = (mipPitch + 63) & ~63u;
            if (mipPitch == 0) mipPitch = 64;
            uint32_t mipRows = isDXT ? ((mipH + 3) / 4) : mipH;
            if (mipRows == 0) mipRows = 1;
            totalSize += mipPitch * mipRows * mipD;
        }
    }

    // ---------- Encode Format DWORD ----------
    uint32_t logU = Log2Ceil(width);
    uint32_t logV = Log2Ceil(height);
    uint32_t logP = Log2Ceil(depth);

    uint32_t fmtDword = ((dim & 0xF) << 4)
                       | (format << X_D3DFORMAT_FORMAT_SHIFT)
                       | (((levels - 1) & 0xF) << X_D3DFORMAT_MIPMAP_SHIFT)
                       | ((logU & 0xF) << X_D3DFORMAT_USIZE_SHIFT)
                       | ((logV & 0xF) << X_D3DFORMAT_VSIZE_SHIFT)
                       | ((logP & 0xF) << X_D3DFORMAT_PSIZE_SHIFT);

    // ---------- Encode Size DWORD ----------
    uint32_t pitchLog = 0;
    if (pitch >= 64)
        pitchLog = (pitch / 64) - 1;

    uint32_t sizeDword = ((width  - 1) & X_D3DSIZE_WIDTH_MASK)
                       | (((height - 1) & 0xFFF) << X_D3DSIZE_HEIGHT_SHIFT)
                       | ((pitchLog & 0xFF) << X_D3DSIZE_PITCH_SHIFT);

    // ---------- Write outputs ----------
    if (pFmtOut)  X86_MEM_WRITE_u32(base, pFmtOut, fmtDword);
    if (pSizeOut) X86_MEM_WRITE_u32(base, pSizeOut, sizeDword);

    fprintf(stderr, "[HLE] D3D_PixelJar_EncodeFormat(%ux%u, fmt=0x%X, lvl=%u) -> "
                    "size=%u, fmt=0x%08X, sz=0x%08X\n",
            width, height, format, levels, totalSize, fmtDword, sizeDword);

    GuestReturn32(ctx, totalSize);
    GuestStackCleanup(ctx, 32);
}

void D3D_JBInvSqrt(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_JBInvSqrt (0x00352770) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_NormalizeVector3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_NormalizeVector3 (0x003527D0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_XformBy4x3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_XformBy4x3 (0x00352810) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void D3D_MatrixProduct4x4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_MatrixProduct4x4 (0x00352870) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void D3D_Inverse4x4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Inverse4x4 (0x00352970) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_Explut(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_Explut (0x00352EA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_353060(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_353060 (0x00353060) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_InitializeD3dState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_InitializeD3dState (0x00353180) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CDevice_Init(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CDevice_Init (0x00353360) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

// D3D_CDevice_UnInit  (0x353FB0) — 0 stack args, plain ret
//
// Called from D3DDevice_Release when the last reference is dropped.
// The original code receives the device object pointer in EAX (set by
// the caller in the recompiled code).  It:
//   - Blocks for GPU idle (no-op in HLE)
//   - Frees push buffer, frame buffers, vertex shaders
//   - Releases render target and depth-stencil surfaces
//   - Releases cached textures in the global surface table at 0x35D2C8
//   - Calls CMiniport_ShutdownEngines
//   - Zeros the global surface table at 0x35D2C0 (48 DWORDs)
//
// In our HLE environment the bump allocator doesn't support freeing, so
// we just zero out the global state that later code may re-read.
void D3D_CDevice_UnInit(X86Context& ctx, uint8_t* base) {
    // Device object pointer: passed in EAX by the caller (D3DDevice_Release
    // sets eax = dev ptr), or read from the Burnout3 global at 0x35FB48.
    uint32_t devObj = ctx.eax;
    if (devObj == 0)
        devObj = X86_MEM_READ_u32(base, 0x35FB48u);

    fprintf(stderr, "[HLE] D3D_CDevice_UnInit(devObj=0x%08X)\n", devObj);

    // --- Release the render target at [devObj+0x7A0] ---
    if (devObj != 0) {
        uint32_t rt = X86_MEM_READ_u32(base, devObj + 0x7A0u);
        if (rt != 0) {
            // Decrement refcount
            uint32_t common = X86_MEM_READ_u32(base, rt);
            uint32_t rc = common & X_D3DCOMMON_REFCOUNT_MASK;
            if (rc > 0) rc--;
            X86_MEM_WRITE_u32(base, rt, (common & ~X_D3DCOMMON_REFCOUNT_MASK) | rc);
        }

        // --- Release texture / surface refs at [devObj+0xF88..0xF98] ---
        for (uint32_t i = 0; i < 4; i++) {
            uint32_t offPre  = devObj + 0xF88u + i * 4;
            uint32_t offPost = devObj + 0xF98u + i * 4;
            uint32_t res;
            res = X86_MEM_READ_u32(base, offPre);
            if (res != 0) {
                uint32_t c = X86_MEM_READ_u32(base, res);
                uint32_t r = c & X_D3DCOMMON_REFCOUNT_MASK;
                if (r > 0) r--;
                X86_MEM_WRITE_u32(base, res, (c & ~X_D3DCOMMON_REFCOUNT_MASK) | r);
            }
            res = X86_MEM_READ_u32(base, offPost);
            if (res != 0) {
                uint32_t c = X86_MEM_READ_u32(base, res);
                uint32_t r = c & X_D3DCOMMON_REFCOUNT_MASK;
                if (r > 0) r--;
                X86_MEM_WRITE_u32(base, res, (c & ~X_D3DCOMMON_REFCOUNT_MASK) | r);
            }
        }
    }

    // --- Release cached surfaces in global table at 0x35D2C8 (16 entries × 12 bytes) ---
    for (uint32_t off = 0; off < 0xC0; off += 12) {
        uint32_t res = X86_MEM_READ_u32(base, 0x35D2C8u + off);
        if (res != 0) {
            uint32_t c = X86_MEM_READ_u32(base, res);
            uint32_t r = c & X_D3DCOMMON_REFCOUNT_MASK;
            if (r > 0) r--;
            X86_MEM_WRITE_u32(base, res, (c & ~X_D3DCOMMON_REFCOUNT_MASK) | r);
        }
    }

    // --- Zero the global D3D surface table at 0x35D2C0 (48 DWORDs = 192 bytes) ---
    memset(base + 0x35D2C0u, 0, 48 * 4);

    GuestStackCleanup(ctx, 0);
}

void D3D_CommonSetTextureBumpEnv(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CommonSetTextureBumpEnv (0x00355700) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// D3D_CommonSetViewport  (0x3558A0) — no stack args, plain ret
//
// Internal helper: reads the viewport from the CDevice object (ECX = this)
// and writes NV2A viewport registers.  In our HLE the D3D11 viewport is
// applied at draw time from the device shadow at kDeviceAddr+0x0C80
// (maintained by D3DDevice_SetViewport), so no additional action is needed.
void D3D_CommonSetViewport(X86Context& ctx, uint8_t* base) {
    GuestStackCleanup(ctx, 0);
}

void D3D_CommonSetControl0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CommonSetControl0 (0x00355AA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CommonSetAntiAliasingControl(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CommonSetAntiAliasingControl (0x00355B00) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_MapRegisters(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_MapRegisters (0x003561F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_GetGeneralInfo(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_GetGeneralInfo (0x0035621B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_InitEngines(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_InitEngines (0x0035625E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_LoadEngines(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_LoadEngines (0x003562DF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_InitGammaRamp(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_InitGammaRamp (0x0035637E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_GetAddressInfo(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_GetAddressInfo (0x003563B8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_InitDMAChannel(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_InitDMAChannel (0x003564C8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3D_CMiniport_ShutdownEngines(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ShutdownEngines (0x00356526) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_CreateTile(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_CreateTile (0x003566DA) called\n"); logged = true; }
    GuestStackCleanup(ctx, 28);
}

// D3D_CMiniport_DestroyTile  (0x3568C5) — 2 args (this+tileIdx), ret 8
// NV2A miniport tile management — pure hardware op, no-op in HLE.
// The original code returns 1 (success) in EAX.
void D3D_CMiniport_DestroyTile(X86Context& ctx, uint8_t* base) {
    GuestReturn32(ctx, 1);
    GuestStackCleanup(ctx, 8);
}

void D3D_CMiniport_TilingUpdateIdle(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_TilingUpdateIdle (0x00356982) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_SetTimerAlarm(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_SetTimerAlarm (0x003569E8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void D3D_CMiniport_GetTime(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_GetTime (0x00356AC0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_Dpc(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_Dpc (0x00356BF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void D3D_CMiniport_ServiceQueuedFlips(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ServiceQueuedFlips (0x00356CD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_VBlank(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_VBlank (0x00356DA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_ServiceTimerInterrupt(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ServiceTimerInterrupt (0x00356EB0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_ServiceGrInterrupt(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ServiceGrInterrupt (0x00357000) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_ServiceFifoInterrupt(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ServiceFifoInterrupt (0x003570C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_SoftwareMethod(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_SoftwareMethod (0x00357250) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_ShutdownNotification(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_ShutdownNotification (0x003574A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_ReportHardwareError(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_ReportHardwareError (0x00357510) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void D3D_CMiniport_DacProgramVideoStart(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_DacProgramVideoStart (0x00357558) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_DacProgramGammaRamp(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_DacProgramGammaRamp (0x003575D6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_GetTableForCurrentAvInfo(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_GetTableForCurrentAvInfo (0x00357648) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_SetVideoMode(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_SetVideoMode (0x003576C1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 24);
}

void D3D_LazySetShaderStageProgram(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetShaderStageProgram (0x00357A90) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_LazySetTextureState(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetTextureState (0x00357E10) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3D_LazySetSpecFogCombiner(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetSpecFogCombiner (0x00358010) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_LazySetTextureTransform(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetTextureTransform (0x00358200) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_GetColorMaterial(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_GetColorMaterial (0x003585D0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_SetLightColors(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SetLightColors (0x00358670) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_SetSceneAmbientAndMaterialEmission(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SetSceneAmbientAndMaterialEmission (0x00358760) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_SetSpecularParameters(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_SetSpecularParameters (0x00358910) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_LazySetLights(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetLights (0x00358A30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void D3D_LazySetTransform(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetTransform (0x00358DA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

// D3D_LazySetState  (0x358FB0) — no stack args, plain ret
//
// Internal helper: flushes pending (lazily-deferred) render-state writes to
// the NV2A push buffer before a draw call.  In our HLE all render states are
// captured eagerly via the individual Set* intercepts and applied at draw
// time, so there is nothing to flush here.
void D3D_LazySetState(X86Context& ctx, uint8_t* base) {
    GuestStackCleanup(ctx, 0);
}

void D3D_CDevice_LazySetStateUP(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CDevice_LazySetStateUP (0x003591F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_InitSurfaceHeader(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_InitSurfaceHeader (0x00359340) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void D3D_HandleMovieFrameIdle(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_HandleMovieFrameIdle (0x00359390) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_HandleShaderSnapshotPreSwap(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_HandleShaderSnapshotPreSwap (0x00359740) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_HandleShaderSnapshotOpcode(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_HandleShaderSnapshotOpcode (0x003597F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalMcControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalMcControlInit (0x00359D93) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalFbControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalFbControlInit (0x00359EF6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalDacControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalDacControlInit (0x00359FF6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalVideoControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalVideoControlInit (0x0035A0C5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalGrControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrControlInit (0x0035A0FB) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalFifoControlInit(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalFifoControlInit (0x0035A12B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalGrControlLoad(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrControlLoad (0x0035A19C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalGrIdle(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrIdle (0x0035A418) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalGrLoadChannelContext(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrLoadChannelContext (0x0035A457) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_HalGrUnloadChannelContext(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrUnloadChannelContext (0x0035A578) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_HalFifoControlLoad(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalFifoControlLoad (0x0035A5B1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CMiniport_HalFifoContextSwitch(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalFifoContextSwitch (0x0035A636) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void D3D_CMiniport_HalFifoAllocDMA(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalFifoAllocDMA (0x0035A82E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void D3D_CMiniport_HalGrInit3d(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CMiniport_HalGrInit3d (0x0035A9C8) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_FixupPushBuffer(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_FixupPushBuffer (0x0035B3B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_DBGPRINT(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_DBGPRINT (0x0035B450) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_CombinerInput(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_CombinerInput (0x0035B490) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void D3D_LazySetCombiners(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] D3D_LazySetCombiners (0x0035B530) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_35BB00(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE] sub_35BB00 (0x0035BB00) called\n"); logged = true; }
    GuestReturn32(ctx, 1);
    GuestStackCleanup(ctx, 4);
}

void Direct3D_GetAdapterModeCount(X86Context& ctx, uint8_t* base) {
    // Xbox D3D8: UINT Direct3D_GetAdapterModeCount(UINT Adapter)
    // Return 1 mode available (640x480 NTSC).  Without a valid count the
    // RenderWare device-open code fails its mode search and never reaches
    // case 11 of the device-system handler, leaving the raster dispatch
    // table (including ShowRaster at dword_759338) uninitialised → blank display.
    fprintf(stderr, "[HLE] Direct3D_GetAdapterModeCount -> 1\n");
    ctx.eax = 1;
    GuestStackCleanup(ctx, 4);
}

void Direct3D_EnumAdapterModes(X86Context& ctx, uint8_t* base) {
    // Xbox D3D8: HRESULT Direct3D_EnumAdapterModes(UINT Adapter, UINT Mode,
    //                                               X_D3DDISPLAYMODE *pMode)
    // X_D3DDISPLAYMODE = { Width, Height, RefreshRate, Flags, Format }
    // The RW device-open code (sub_1DD4F0) copies the game's requested mode
    // to dword_7591F0 before enumerating, so we mirror it back to guarantee
    // the comparison succeeds.
    uint32_t pMode = GuestArg32(ctx, base, 2);

    if (pMode) {
        // Read the game's requested video mode stored at 0x7591F0 by the
        // RW device-open handler (qmemcpy from the RwVideoMode params):
        //   +0x00 = Width, +0x04 = Height, +0x08 = D3DFORMAT,
        //   +0x1C = Flags, +0x20 = RefreshRate
        uint32_t width   = X86_MEM_READ_u32(base, 0x7591F0);
        uint32_t height  = X86_MEM_READ_u32(base, 0x7591F4);
        uint32_t format  = X86_MEM_READ_u32(base, 0x7591F8);
        uint32_t flags   = X86_MEM_READ_u32(base, 0x7591F0 + 0x1C);
        uint32_t refresh = X86_MEM_READ_u32(base, 0x7591F0 + 0x20);

        // Populate the Xbox D3DDISPLAYMODE struct in guest memory.
        X86_MEM_WRITE_u32(base, pMode + 0,  width);
        X86_MEM_WRITE_u32(base, pMode + 4,  height);
        X86_MEM_WRITE_u32(base, pMode + 8,  refresh);
        X86_MEM_WRITE_u32(base, pMode + 12, flags & 0x1F0);  // masked to match comparison
        X86_MEM_WRITE_u32(base, pMode + 16, format);

        fprintf(stderr, "[HLE] Direct3D_EnumAdapterModes -> %ux%u @%uHz flags=0x%X fmt=0x%X\n",
                width, height, refresh, flags & 0x1F0, format);
    }

    ctx.eax = 0;  // S_OK
    GuestStackCleanup(ctx, 12);
}

void sub_35D2E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D2E0 (0x0035D2E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35D2F5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D2F5 (0x0035D2F5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void nullsub_8(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] nullsub_8 (0x0035D4F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 40);
}

void sub_35D50C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D50C (0x0035D50C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 36);
}

void sub_35D55B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D55B (0x0035D55B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_35D5E5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D5E5 (0x0035D5E5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_35D60E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D60E (0x0035D60E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_35D975(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35D975 (0x0035D975) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_35DA58(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35DA58 (0x0035DA58) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_35DB6A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35DB6A (0x0035DB6A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_35E434(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35E434 (0x0035E434) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}

void sub_35EBD5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35EBD5 (0x0035EBD5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35EC50(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35EC50 (0x0035EC50) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35ED1E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35ED1E (0x0035ED1E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35EE69(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35EE69 (0x0035EE69) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35EEE6(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35EEE6 (0x0035EEE6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35EFAC(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35EFAC (0x0035EFAC) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35F0E7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35F0E7 (0x0035F0E7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35F15C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35F15C (0x0035F15C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_35F232(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_35F232 (0x0035F232) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_360865(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_360865 (0x00360865) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_36089C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_36089C (0x0036089C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// RenderWare Xbox state-cache flush / init  (replaces recompiled bodies)
// ============================================================================
//
// These two functions (__rwXbFlushCacheBuffer @ 0x1D7040 and __rwXbCacheInit
// @ 0x1D7180) are RenderWare's Xbox-specific state-caching layer. They sit
// between game code and the XBD3D8 library: render states and texture stage
// states are staged into RW-owned arrays in the guest .data segment, then
// flushed in batches via calls to D3DDevice_SetRenderStateNotInline /
// D3DDevice_SetTextureStageStateNotInline / D3DDevice_SetTexture.
//
// In the original XBE the flush function decides whether a pending value is
// a no-op by reading the XBD3D8 caches D3D_g_RenderState (0x35FB58, 166 dwords)
// and D3D_g_DeferredTextureState (0x35D498, 4 stages x 32 dwords) directly
// from the .data segment. Our HLE Set*NotInline functions don't touch those
// guest arrays anymore (they keep a host-side shadow), so we re-implement
// the flush and init in HLE to read from the host shadow instead.
//
// Guest-side RW bookkeeping that we still honour faithfully (untouched by
// HLE D3D code — it is RW-private):
//
//   0x75D4A0  uint32[166]        pending render state values
//   0x75DB80  uint32[166]        per-index dirty flag (0 = clean)
//   0x75DB60  uint32             number of dirty render-state entries
//   0x75DE20  uint32[...]        queue of dirty render-state indices
//
//   0x75D740  uint32[4][32]      pending TSS values, stride [stage][state]
//                                where offset = (stage + state*4) * 4
//   0x75D960  uint32[4][32]      per-(stage,state) dirty flag
//   0x75D940  uint32[4]          number of dirty TSS entries per stage
//   0x75D2A0  uint32[4][32]      queue of dirty TSS state-indices per stage
//                                (stride 16 bytes: [stage + N*4])
//
//   0x75DB70  uint32[4]          pending texture per stage
//   0x41AA34  uint32[4]          last-bound texture per stage (shadow)
//
// (Memory note: offsets above come from the IDA decompilation of the
// original XBE at 0x1D7040/0x1D7180.)

// Helper wrappers around the guest arrays to keep the code readable.
static inline uint32_t RWPendingRS(uint8_t* base, uint32_t idx) {
    return X86_MEM_READ_u32(base, 0x75D4A0u + idx * 4);
}
static inline uint32_t RWDirtyIdx(uint8_t* base, uint32_t n) {
    return X86_MEM_READ_u32(base, 0x75DE20u + n * 4);
}
static inline void RWClearRSDirty(uint8_t* base, uint32_t idx) {
    X86_MEM_WRITE_u32(base, 0x75DB80u + idx * 4, 0);
}
static inline uint32_t RWPendingTSS(uint8_t* base, uint32_t stage, uint32_t stateIdx) {
    // offset = (stage + stateIdx * 4) * 4
    return X86_MEM_READ_u32(base, 0x75D740u + (stage + stateIdx * 4) * 4);
}
static inline uint32_t RWTSSQueueEntry(uint8_t* base, uint32_t stage, uint32_t n) {
    // queue: ebx = edi*4 + 0x75D2A0 + n*0x10, i.e. 0x75D2A0 + stage*4 + n*16
    return X86_MEM_READ_u32(base, 0x75D2A0u + stage * 4 + n * 16);
}
static inline void RWClearTSSDirty(uint8_t* base, uint32_t stage, uint32_t stateIdx) {
    X86_MEM_WRITE_u32(base, 0x75D960u + (stage + stateIdx * 4) * 4, 0);
}

// __rwXbFlushCacheBuffer  (0x1D7040) — 0 args, plain ret
//
// Commits all pending RW cached state changes to D3D:
//   1. For each dirty render-state index, call SetRenderStateNotInline if
//      the pending value differs from the host cache.
//   2. For each dirty (stage, TSS-state), call SetTextureStageStateNotInline
//      if the pending value differs from the host cache.
//   3. For each stage, if the pending texture differs from the last bound,
//      call SetTexture.
void __rwXbFlushCacheBuffer(X86Context& ctx, uint8_t* base)
{
    // --- Render state flush ---
    uint32_t rsCount = X86_MEM_READ_u32(base, 0x75DB60u);
    for (uint32_t i = 0; i < rsCount; ++i) {
        uint32_t idx     = RWDirtyIdx(base, i);
        uint32_t pending = RWPendingRS(base, idx);
        uint32_t cached  = (idx < kHLERenderStateCount) ? g_hleRenderStateCache[idx] : 0;
        if (pending != cached)
            HLE_SetRenderStateNotInline(base, idx, pending);
        RWClearRSDirty(base, idx);
    }
    if (rsCount)
        X86_MEM_WRITE_u32(base, 0x75DB60u, 0);

    // --- Texture stage state flush ---
    for (uint32_t stage = 0; stage < 4; ++stage) {
        uint32_t tssCount = X86_MEM_READ_u32(base, 0x75D940u + stage * 4);
        if (!tssCount) continue;

        for (uint32_t n = 0; n < tssCount; ++n) {
            uint32_t stateIdx = RWTSSQueueEntry(base, stage, n);
            uint32_t pending  = RWPendingTSS(base, stage, stateIdx);
            uint32_t cached   = (stateIdx < 32) ? g_hleTSSCache[stage][stateIdx] : 0;
            if (pending != cached)
                HLE_SetTextureStageStateNotInline(base, stage, stateIdx, pending);
            RWClearTSSDirty(base, stage, stateIdx);
        }
        X86_MEM_WRITE_u32(base, 0x75D940u + stage * 4, 0);
    }

    // --- Texture binding flush ---
    for (uint32_t stage = 0; stage < 4; ++stage) {
        uint32_t pending = X86_MEM_READ_u32(base, 0x75DB70u + stage * 4);
        uint32_t current = X86_MEM_READ_u32(base, 0x41AA34u + stage * 4);
        if (pending != current) {
            X86_MEM_WRITE_u32(base, 0x41AA34u + stage * 4, pending);
            HLE_SetTexture(base, stage, pending);
        }
    }

    // Plain ret (no argument cleanup).
    GuestStackCleanup(ctx, 0);
}

// __rwXbCacheInit  (0x1D7180) — 0 args, plain ret
//
// Initialises RW's state-cache arrays and programs the initial GPU state.
// The original code performs a large sequence of fixed SetRenderState /
// SetTextureStageState calls; we mirror that exactly so downstream
// assumptions hold. The only behavioural change from the recompiled
// version is:
//   - The initial copy of D3D_g_RenderState into 0x75D4A0 is replaced with
//     a zero-fill. At entry to Init the XBD3D8 library has not yet
//     programmed any state, so the original copy was already zero in
//     practice.
//   - The read of g_VideoStandard at 0x759200 is kept as a guest memory
//     read since that global is populated by kernel HLE.
//
// Returns 0 via EAX (matches "return result;" in the decompilation, where
// result is the last D3DDevice_SetTexture return value — we stub it as 0).
void __rwXbCacheInit(X86Context& ctx, uint8_t* base)
{
    // Zero both dirty-flag regions and the RW pending-RS cache (166 dwords).
    // 0x75DB80 is the start of a 0x298-byte "dirty flag" block.
    // 0x75D4A0 is the 0x298-byte pending RS cache (originally seeded from
    //   D3D_g_RenderState, which is all zero at entry).
    for (uint32_t i = 0; i < kHLERenderStateCount; ++i) {
        X86_MEM_WRITE_u32(base, 0x75DB80u + i * 4, 0);
        X86_MEM_WRITE_u32(base, 0x75D4A0u + i * 4, 0);
    }

    // dword_75DB60 = 0; (no dirty entries)
    X86_MEM_WRITE_u32(base, 0x75DB60u, 0);

    // Table of (rs_index, initial_value) pairs matching the original
    // recompiled init sequence 1:1. Each pair writes 0x75D4A0+idx*4 and
    // calls SetRenderStateNotInline(idx, val).
    static constexpr struct { uint32_t idx; uint32_t val; } kRSInit[] = {
        { 57,  515 },        // 0x203
        { 58,  516 },        // 0x204
        { 59,  0 },
        { 60,  0 },
        { 61,  0 },
        { 62,  770 },        // 0x302
        { 63,  771 },        // 0x303
        { 64,  1 },
        { 65,  1 },
        { 66,  7425 },       // 0x1D01
        { 67,  16843009 },   // 0x01010101
        { 68,  7680 },       // 0x1E00
        { 69,  7680 },       // 0x1E00
        { 70,  519 },        // 0x207
        { 71,  0 },
        { 72,  0xFFFFFFFFu },
        { 73,  0xFFFFFFFFu },
        { 74,  32774 },      // 0x8006
        { 75,  0 },
        { 76,  4 },
        { 77,  0 },
        { 78,  0 },
        { 79,  0 },
        { 80,  0 },
        { 81,  0 },
        { 92,  0 },
        { 93,  3 },
        { 94,  0 },
        { 95,  1065353216 }, // 1.0f
        { 96,  1065353216 }, // 1.0f
        { 97,  0 },
        { 98,  0 },
        { 99,  0 },
        { 100, 0 },
        { 101, 0 },
        { 102, 0 },
        { 103, 0 },
        { 104, 0 },
        { 105, 1 },
        { 106, 2 },
        { 107, 1 },
        { 108, 2 },
        { 109, 0 },
        { 110, 0 },
        { 111, 0 },
        { 112, 0 },
        { 113, 0 },
        { 114, 0 },
        { 115, 0 },
        { 116, 1065353216 }, // 1.0f
        { 117, 0 },
        { 118, 0 },
        { 119, 0 },
        { 120, 1065353216 },
        { 121, 1065353216 },
        { 122, 1065353216 },
        { 123, 1065353216 },
        { 124, 0 },
        { 125, 1065353216 },
        { 137, 0 },
        { 138, 0xFFFFFFFFu },
        { 139, 6914 },       // 0x1B02
        { 140, 6914 },       // 0x1B02
        { 141, 0 },
        { 142, 0 },
        { 143, 1 },
        { 144, 0 },
        { 145, 7680 },       // 0x1E00
        { 146, 2305 },       // 0x0901
        { 147, 2304 },       // 0x0900
        { 148, 0 },
        { 149, 0 },
        { 150, 0 },
        { 151, 0 },
        { 152, 1 },
        { 153, 0xFFFFFFFFu },
        { 156, 512 },        // 0x200
        { 157, 1065353216 },
        { 159, 1 },
        { 160, 0 },
        { 161, 1 },
        { 162, 1 },
        { 163, 0 },
        { 164, 0 },
        { 165, 0 },
    };
    for (auto& e : kRSInit) {
        X86_MEM_WRITE_u32(base, 0x75D4A0u + e.idx * 4, e.val);
        HLE_SetRenderStateNotInline(base, e.idx, e.val);
    }

    // Fill-mode branch keyed on g_VideoStandard at 0x759200.
    // In the original: picks cull/fill mode based on video format.
    //   default (NTSC, PAL, etc.) → state 126 = 1 (CCW), states 154/155 = 0
    //   special region/format     → state 126 = 5, 2 or 4, with varying 154/155
    // We keep the full classification to stay faithful.
    uint32_t vs = X86_MEM_READ_u32(base, 0x759200u);
    uint32_t rs126 = 1, rs154 = 0, rs155 = 0;
    if (vs > 0x2012u) {
        if (vs > 0x2222u) {
            if (vs == 8755u) { rs126 = 5; } else { rs126 = 1; }
        } else if (vs != 8738u) {
            if (vs == 8225u || vs == 8226u) { rs126 = 2; } else { rs126 = 1; }
        } else {
            rs126 = 5;
        }
    } else if (vs == 8210u) {
        rs126 = 2;
    } else if (vs > 0x1121u) {
        if (vs == 4642u || vs == 4659u) { rs126 = 5; rs154 = 2; rs155 = 2; }
        else { rs126 = 1; }
    } else {
        switch (vs) {
        case 4129: rs126 = 2; rs154 = 1; rs155 = 1; break;
        case 4130: rs126 = 2; rs154 = 2; rs155 = 2; break;
        case 4385: rs126 = 4; rs154 = 1; rs155 = 1; break;
        default:   rs126 = 1; break;
        }
    }
    X86_MEM_WRITE_u32(base, 0x75D4A0u + 126 * 4, rs126);
    HLE_SetRenderStateNotInline(base, 126, rs126);
    X86_MEM_WRITE_u32(base, 0x75D4A0u + 154 * 4, rs154);
    HLE_SetRenderStateNotInline(base, 154, rs154);
    X86_MEM_WRITE_u32(base, 0x75D4A0u + 155 * 4, rs155);
    HLE_SetRenderStateNotInline(base, 155, rs155);

    // --- TSS init ---
    // Zero pending-TSS and dirty-flag arrays. (Original does a nested loop
    // that also copies the deferred TSS into the pending buffer, but that
    // deferred TSS was zero anyway.)
    for (uint32_t stage = 0; stage < 4; ++stage) {
        for (uint32_t state = 0; state < 32; ++state) {
            X86_MEM_WRITE_u32(base, 0x75D740u + (stage + state * 4) * 4, 0);
            X86_MEM_WRITE_u32(base, 0x75D960u + (stage + state * 4) * 4, 0);
        }
        X86_MEM_WRITE_u32(base, 0x75D940u + stage * 4, 0);
    }

    // Stage-0 specific TSS defaults (from the original init).
    //   state 12 (COLOROP)     = 2   (SELECTARG1)
    //   state 13 (COLORARG0)   = 1
    //   state 14 (COLORARG1)   = 0
    //   state 15 (COLORARG2)   = 1
    //   state 16 (ALPHAOP)     = 2
    //   state 17 (ALPHAARG0)   = 1
    //   state 18 (ALPHAARG1)   = 0
    //   state 19 (ALPHAARG2)   = 1
    //   state 20             = 1
    //   state 21             = 0
    //   states 0..11         = {1,1,1,2,2,0,0,0,1,0,0,0}
    //   states 22,23,24,25,26,27,28,29,30 = {0,0,0,0,0,0,0,0xFF000000,0}
    static constexpr struct { uint32_t state; uint32_t val; } kStage0Init[] = {
        { 12, 2 }, { 13, 1 }, { 14, 0 }, { 15, 1 },
        { 16, 2 }, { 17, 1 }, { 18, 0 }, { 19, 1 },
        { 20, 1 }, { 21, 0 },
        { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 2 }, { 4, 2 },
        { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 1 },
        { 9, 0 }, { 10, 0 }, { 11, 0 },
        { 22, 0 }, { 23, 0 }, { 25, 0 }, { 24, 0 },
        { 26, 0 }, { 27, 0 }, { 28, 0 },
        { 29, 0xFF000000u }, { 30, 0 },
    };
    for (auto& e : kStage0Init) {
        X86_MEM_WRITE_u32(base, 0x75D740u + (0 + e.state * 4) * 4, e.val);
        HLE_SetTextureStageStateNotInline(base, 0, e.state, e.val);
    }

    // Stages 1..3 share the same defaults except for state 28 (which equals
    // the stage index) and ALPHAOP/ALPHAARG0 which are 1 instead of 2/1.
    for (uint32_t stage = 1; stage < 4; ++stage) {
        static constexpr struct { uint32_t state; uint32_t val; } kStageNInit[] = {
            { 12, 1 }, { 13, 1 }, { 14, 0 }, { 15, 1 },
            { 16, 1 }, { 17, 1 }, { 18, 0 }, { 19, 1 },
            { 20, 1 }, { 21, 0 },
            { 0, 1 }, { 1, 1 }, { 2, 1 }, { 3, 2 }, { 4, 2 },
            { 5, 0 }, { 6, 0 }, { 7, 0 }, { 8, 1 },
            { 9, 0 }, { 10, 0 }, { 11, 0 },
            { 22, 0 }, { 23, 0 }, { 25, 0 }, { 24, 0 },
            { 26, 0 }, { 27, 0 },
            // state 28 = stage (written per-iteration below)
            { 29, 0xFF000000u }, { 30, 0 },
        };
        for (auto& e : kStageNInit) {
            X86_MEM_WRITE_u32(base, 0x75D740u + (stage + e.state * 4) * 4, e.val);
            HLE_SetTextureStageStateNotInline(base, stage, e.state, e.val);
        }
        X86_MEM_WRITE_u32(base, 0x75D740u + (stage + 28 * 4) * 4, stage);
        HLE_SetTextureStageStateNotInline(base, stage, 28, stage);
    }

    // --- Texture binding init --- clear all four stages.
    for (uint32_t stage = 0; stage < 4; ++stage) {
        HLE_SetTexture(base, stage, 0);
        X86_MEM_WRITE_u32(base, 0x75DB70u + stage * 4, 0);
        X86_MEM_WRITE_u32(base, 0x41AA34u + stage * 4, 0);
    }

    // Return 0 (matches the last D3DDevice_SetTexture return value in the
    // original decompilation).
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}
