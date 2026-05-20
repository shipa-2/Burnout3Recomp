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
#include <cstdarg>
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
#include <d3d11_1.h>     // ID3DUserDefinedAnnotation (RenderDoc markers)
#include <dxgi.h>
#include <d3dcompiler.h>
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "dxguid.lib")

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

// ----------------------------------------------------------------------------
// Tag a D3D11 device child with a human-readable debug name so RenderDoc /
// PIX / the D3D11 debug layer show e.g. "B3_VS_FFFE0009" instead of opaque
// pointers. Safe to call with nullptr — no-op.
// ----------------------------------------------------------------------------
static void SetD3DName(ID3D11DeviceChild* obj, const char* fmt, ...)
{
    if (!obj || !fmt) return;
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    int n = std::vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (n <= 0) return;
    if (n >= (int)sizeof(buf)) n = (int)sizeof(buf) - 1;
    obj->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)n, buf);
}
static void SetD3DName(IDXGIObject* obj, const char* fmt, ...)
{
    if (!obj || !fmt) return;
    char buf[128];
    va_list ap;
    va_start(ap, fmt);
    int n = std::vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);
    if (n <= 0) return;
    if (n >= (int)sizeof(buf)) n = (int)sizeof(buf) - 1;
    obj->SetPrivateData(WKPDID_D3DDebugObjectName, (UINT)n, buf);
}

// ============================================================================
// HLSL Shaders
// ============================================================================

// 2D vertex shader: screen-space XYZRHW → clip space, single UV replicated to all stages
static const char s_vsHlsl[] =
    "cbuffer CB : register(b0) { float2 screenSize; float2 screenOffset; }\n"
    "struct VS_IN { float2 pos : POSITION; float2 uv : TEXCOORD; float4 col : COLOR; };\n"
    "struct VS_OUT {\n"
    "  float4 pos  : SV_POSITION;\n"
    "  float4 oD0  : COLOR0;\n"
    "  float4 oD1  : COLOR1;\n"
    "  float4 oFog : FOG;\n"
    "  float4 oT0  : TEXCOORD0;\n"
    "  float4 oT1  : TEXCOORD1;\n"
    "  float4 oT2  : TEXCOORD2;\n"
    "  float4 oT3  : TEXCOORD3;\n"
    "};\n"
    "VS_OUT main(VS_IN v) {\n"
    "  VS_OUT o;\n"
    "  o.pos.x =  ((v.pos.x - screenOffset.x) / screenSize.x) * 2.0f - 1.0f;\n"
    "  o.pos.y = -((v.pos.y - screenOffset.y) / screenSize.y) * 2.0f + 1.0f;\n"
    "  o.pos.z = 0.0f; o.pos.w = 1.0f;\n"
    "  o.oD0 = v.col;\n"
    "  o.oD1 = float4(0,0,0,0);\n"
    "  o.oFog = float4(1,1,1,1);\n"
    "  o.oT0 = float4(v.uv, 0, 1);\n"
    "  o.oT1 = float4(v.uv, 0, 1);\n"
    "  o.oT2 = float4(v.uv, 0, 1);\n"
    "  o.oT3 = float4(v.uv, 0, 1);\n"
    "  return o;\n"
    "}\n";

// Extended 2D vertex shader: 4 independent UV channels for multi-sample post-FX (blur, etc.)
// Vertex layout: pos(xy) + uv0..uv3(4×xy) + col(rgba) = 44 bytes
static const char s_vsExHlsl[] =
    "cbuffer CB : register(b0) { float2 screenSize; float2 screenOffset; }\n"
    "struct VS_IN {\n"
    "  float2 pos  : POSITION;\n"
    "  float2 uv0  : TEXCOORD0;\n"
    "  float2 uv1  : TEXCOORD1;\n"
    "  float2 uv2  : TEXCOORD2;\n"
    "  float2 uv3  : TEXCOORD3;\n"
    "  float4 col  : COLOR;\n"
    "};\n"
    "struct VS_OUT {\n"
    "  float4 pos  : SV_POSITION;\n"
    "  float4 oD0  : COLOR0;\n"
    "  float4 oD1  : COLOR1;\n"
    "  float4 oFog : FOG;\n"
    "  float4 oT0  : TEXCOORD0;\n"
    "  float4 oT1  : TEXCOORD1;\n"
    "  float4 oT2  : TEXCOORD2;\n"
    "  float4 oT3  : TEXCOORD3;\n"
    "};\n"
    "VS_OUT main(VS_IN v) {\n"
    "  VS_OUT o;\n"
    "  o.pos.x =  ((v.pos.x - screenOffset.x) / screenSize.x) * 2.0f - 1.0f;\n"
    "  o.pos.y = -((v.pos.y - screenOffset.y) / screenSize.y) * 2.0f + 1.0f;\n"
    "  o.pos.z = 0.0f; o.pos.w = 1.0f;\n"
    "  o.oD0  = v.col;\n"
    "  o.oD1  = float4(0,0,0,0);\n"
    "  o.oFog = float4(1,1,1,1);\n"
    "  o.oT0  = float4(v.uv0, 0, 1);\n"
    "  o.oT1  = float4(v.uv1, 0, 1);\n"
    "  o.oT2  = float4(v.uv2, 0, 1);\n"
    "  o.oT3  = float4(v.uv3, 0, 1);\n"
    "  return o;\n"
    "}\n";

// Untextured pixel shader: use vertex colour only
static const char s_psUntexturedHlsl[] =
    "struct PS_IN { float4 pos:SV_POSITION; float4 oD0:COLOR0; float4 oD1:COLOR1; float4 oFog:FOG; float4 oT0:TEXCOORD0; float4 oT1:TEXCOORD1; float4 oT2:TEXCOORD2; float4 oT3:TEXCOORD3; };\n"
    "float4 main(PS_IN p) : SV_TARGET { return p.oD0; }\n";

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
    "struct PS_IN { float4 pos:SV_POSITION; float4 oD0:COLOR0; float4 oD1:COLOR1; float4 oFog:FOG; float4 oT0:TEXCOORD0; float4 oT1:TEXCOORD1; float4 oT2:TEXCOORD2; float4 oT3:TEXCOORD3; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  float a = t.Sample(s, p.oT0.xy).a;\n"
    "  return float4(p.oD0.rgb, p.oD0.a * a);\n"
    "}\n";

// Modulate pixel shader: texture colour * vertex colour
static const char s_psModulateHlsl[] =
    "Texture2D t : register(t0); SamplerState s : register(s0);\n"
    "struct PS_IN { float4 pos:SV_POSITION; float4 oD0:COLOR0; float4 oD1:COLOR1; float4 oFog:FOG; float4 oT0:TEXCOORD0; float4 oT1:TEXCOORD1; float4 oT2:TEXCOORD2; float4 oT3:TEXCOORD3; };\n"
    "float4 main(PS_IN p) : SV_TARGET {\n"
    "  float4 tc = t.Sample(s, p.oT0.xy);\n"
    "  return tc * p.oD0;\n"
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
    "  return float4(tc.rgb * col, tc.a * p.col.a);\n"
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

struct GuestRT;
struct GuestRTBind {
    GuestRT* rt  = nullptr;
    uint32_t mip = 0;
};

// Render-to-texture support: tracks a guest texture that the game writes to
// via SetRenderTarget and later samples as a shader resource (e.g. dynamic
// environment maps in Burnout 3 car-select).
struct GuestRT {
    ID3D11Texture2D*                       texture     = nullptr; // shared, all mips, RT+SR bound
    ID3D11ShaderResourceView*              srv         = nullptr; // full chain SRV
    std::vector<ID3D11RenderTargetView*>   rtvPerMip;             // one RTV per mip level
    std::vector<ID3D11ShaderResourceView*> srvPerMip;
    // Per-RT-mip "source" SRV exposing only mips strictly above the bound
    // RT mip (i.e. larger / coarser-resolution mips have larger indices, so
    // these expose mips 0..M-1 when RT=mip M). Used to dodge the D3D11
    // RTV/SRV overlap hazard during bloom downsample chains, which sample
    // mip M-1 while writing to mip M of the same texture.
    std::vector<ID3D11ShaderResourceView*> srvSrcExclMip;
    // Per-GuestRT depth buffer (sized baseW x baseH, one DSV per mip).
    // Bound alongside the GuestRT's RTV for 3D draws so depth test works
    // correctly when the game renders a scene into an offscreen texture
    // (e.g. environment/reflection maps or the main render target).
    ID3D11Texture2D*                       depthTex    = nullptr;
    std::vector<ID3D11DepthStencilView*>   dsvPerMip;
    uint32_t                               baseW       = 0;
    uint32_t                               baseH       = 0;
    uint32_t                               mipCount    = 1;
    uint32_t                               parentTexAddr = 0;
    uint32_t                               dataAddr    = 0;       // parent texture's pixel data addr
    uint32_t                               fmtField    = 0;
    uint32_t                               sizeField   = 0;
    uint8_t                                xFmt        = 0;
    DXGI_FORMAT                            dxgiFormat  = DXGI_FORMAT_UNKNOWN;
};

// Per-surface RT binding (each mip surface points back to the parent's GuestRT).
struct SurfaceRTBind {
    GuestRT* rt     = nullptr;
    uint32_t mip    = 0;
    uint32_t parent = 0;   // guest texture parent ptr (so we can count siblings before rt is created)
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
    //  - "scene" = our own offscreen RT-bindable texture that all 3D draws
    //    target. Has BIND_RENDER_TARGET | BIND_SHADER_RESOURCE so it can be
    //    used as a CopyRects source / sampled by post-FX (bloom, motion blur,
    //    refl, lens flare). The legacy `backBufferTex/RTV` names are retained
    //    and now alias the scene resources so existing draw paths keep working.
    //  - "swapChain" = the DXGI buffer; only touched at Present() to blit the
    //    scene into and call swapChain->Present.
    ID3D11Texture2D*          backBufferTex  = nullptr;  // alias: sceneTex
    ID3D11RenderTargetView*   backBufferRTV  = nullptr;  // alias: sceneRTV
    ID3D11ShaderResourceView* sceneSRV       = nullptr;
    ID3D11Texture2D*          prevSceneTex   = nullptr;
    ID3D11ShaderResourceView* prevSceneSRV   = nullptr;
    ID3D11Texture2D*          swapChainTex   = nullptr;
    ID3D11RenderTargetView*   swapChainRTV   = nullptr;
    DXGI_FORMAT               sceneFormat    = DXGI_FORMAT_R8G8B8A8_UNORM;
    // Depth target. depthTex is created TYPELESS so we can also create an SRV
    // (depthSRV) that lens-flare / DoF can sample.
    ID3D11Texture2D*          depthTex       = nullptr;
    ID3D11DepthStencilView*   depthDSV       = nullptr;
    ID3D11ShaderResourceView* depthSRV       = nullptr;

    // 2D Pipeline
    ID3D11VertexShader*       vs2D           = nullptr;
    ID3D11InputLayout*        il2D           = nullptr;
    // Extended 2D pipeline: 4 independent UV channels for multi-sample post-FX
    ID3D11VertexShader*       vs2DEx         = nullptr;
    ID3D11InputLayout*        il2DEx         = nullptr;
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
    // Render-to-texture: per-parent guest texture (keyed by parent texture
    // header addr) and per-surface RTV binding (keyed by surface addr).
    std::unordered_map<uint32_t, GuestRT*>          guestRTByParent;
    std::unordered_map<uint32_t, GuestRTBind>       guestRTByDataAddr;
    std::unordered_map<uint32_t, SurfaceRTBind>     guestRTBySurface;
    uint32_t                                        currentRTSurf = 0; // 0 = back buffer
    GuestRT*                                        activeGuestRT = nullptr; // currently bound (or nullptr = back buffer)
    uint32_t                                        activeGuestRTMip = 0;
    // Back-buffer surface tracking for RT routing
    uint32_t                  xboxBBSurf     = 0;
    uint32_t                  xboxBBSurf2    = 0;

    // ---- RenderDoc / PIX annotation ----
    ID3DUserDefinedAnnotation* annotation    = nullptr;  // SetMarker per draw

    // ---- Debug instrumentation (env-gated; see g_dbg) ----
    ID3D11PixelShader*        psDebugColor   = nullptr;  // outputs per-draw unique color
    ID3D11Buffer*             cbDebug        = nullptr;  // float4: drawIdx, flags, pad, pad
    ID3D11RasterizerState*    rsWire         = nullptr;  // wireframe + no-cull + no depth-clip

    // Scratch texture for in-place RT read/write hazard mitigation (motion blur, etc.)
    ID3D11Texture2D*          scratchTex       = nullptr;
    ID3D11ShaderResourceView* scratchSRV       = nullptr;
    uint32_t                  scratchW         = 0;
    uint32_t                  scratchH         = 0;
    DXGI_FORMAT               scratchFmt       = DXGI_FORMAT_UNKNOWN;
};

static D3D11State g_d3d11;

// Emit a RenderDoc / PIX marker visible in the event browser.
// Format example: f=1195 d=042 RT=192580C0 IM/QUAD 4v
static void RdocMark(const wchar_t* label) {
    if (g_d3d11.annotation) g_d3d11.annotation->SetMarker(label);
}

// Forward decls for render-to-texture helpers (definitions live further down).
static GuestRT* EnsureGuestRT(uint8_t* base, uint32_t parentTexAddr);

// ============================================================================
// Debug instrumentation flags (env-var driven; sampled at pipeline init).
//
//   B3_DEBUG_COLOR_PS   - replace every 3D PS with a unique-per-draw color PS.
//                         If wheels now appear as colored blobs, the original
//                         PS (alpha/discard/tex) is the reason they vanish.
//   B3_DEBUG_NOCULL     - force no-cull + depth-test off + no depth-clip on all
//                         3D draws. If wheels appear, the issue is culling or
//                         depth/z-clip (e.g. bad per-object world transform).
//   B3_DEBUG_WIREFRAME  - after each 3D draw, re-issue it in wireframe with a
//                         solid white PS so submitted-but-invisible geometry
//                         shows up as an outline.
//   B3_DEBUG_DRAW_LOG   - log every 3D draw's state (draw idx, VS/PS handle,
//                         prim, vc, stride, tex, bbox). Correlate with
//                         scene_dump.obj `o drawNNN_...` groups.
// ============================================================================
struct DebugFlags {
    bool colorPS   = false;
    bool noCull    = false;
    bool wireframe = false;
    bool drawLog   = false;
    bool slotDiff  = false;
    bool guestShadow = false;
    bool mvpUploads = false;
    bool setXform   = false;
    bool vbHash    = false; // [VBHASH] per-draw FNV-1a diagnostic
    bool objDump   = false; // scene_dump.obj first-N-draws diagnostic
    bool scStats   = false; // [SC] state-cache hit/miss every N frames
    bool sampled   = false;
};
static DebugFlags g_dbg;

static void SampleDebugFlagsOnce() {
    if (g_dbg.sampled) return;
    g_dbg.sampled = true;
    auto envOn = [](const char* k) {
        const char* v = std::getenv(k);
        return v && v[0] && v[0] != '0';
    };
    g_dbg.colorPS   = envOn("B3_DEBUG_COLOR_PS");
    g_dbg.noCull    = envOn("B3_DEBUG_NOCULL");
    g_dbg.wireframe = envOn("B3_DEBUG_WIREFRAME");
    g_dbg.drawLog   = envOn("B3_DEBUG_DRAW_LOG");
    g_dbg.slotDiff  = envOn("B3_DEBUG_SLOT_DIFF");
    g_dbg.guestShadow = envOn("B3_DEBUG_GUEST_SHADOW");
    g_dbg.mvpUploads = envOn("B3_DEBUG_MVP_UPLOADS");
    g_dbg.setXform = envOn("B3_DEBUG_SET_TRANSFORM");
    g_dbg.vbHash   = envOn("B3_DEBUG_VB_HASH");
    g_dbg.objDump  = envOn("B3_DEBUG_OBJ_DUMP");
    g_dbg.scStats  = envOn("B3_DEBUG_SC_STATS");
    if (g_dbg.colorPS || g_dbg.noCull || g_dbg.wireframe
        || g_dbg.drawLog || g_dbg.slotDiff || g_dbg.guestShadow
        || g_dbg.mvpUploads || g_dbg.setXform) {
        fprintf(stderr,
            "[DBG] debug flags: colorPS=%d noCull=%d wireframe=%d drawLog=%d slotDiff=%d guestShadow=%d mvpUploads=%d setXform=%d\n",
            g_dbg.colorPS, g_dbg.noCull, g_dbg.wireframe,
            g_dbg.drawLog, g_dbg.slotDiff, g_dbg.guestShadow,
            g_dbg.mvpUploads, g_dbg.setXform);
    }
}

// Shared 3D draw counter, incremented once per HLE_Draw3D entry. Used by both
// the scene_dump.obj labeller and the per-draw debug log so a drawNNN group in
// the OBJ matches `[D3D] #NNN ...` in the log 1:1.
static uint32_t g_draw3DIndex = 0;

// ============================================================================
// D3D11 pipeline-state cache.
//
// Per-draw HLE_Draw3D unconditionally re-binds VS/PS/IL/BS/DSS/RS/topology/VB/
// IB/CBs/SRVs/Samplers. With ~3000 3D draws/frame in Burnout 3 that's tens of
// thousands of redundant ID3D11DeviceContext::Set* calls — each one walks the
// runtime/driver "lazy state" tracker even when the bound object is identical
// to the currently-bound one. Filtering redundant binds in user space removes
// that overhead entirely. See repo memory: docs/perf-state-cache.md.
//
// Correctness: D3D11 state is sticky across draws and frames, so the cache
// only needs to be invalidated when something OUTSIDE the cache mutates the
// device state — e.g. ID3D11DeviceContext::ClearState (we never call it) or a
// device-removed reset. We also invalidate at Present() as a safety net.
// ============================================================================
struct D3DStateCache {
    ID3D11VertexShader*       vs           = nullptr;
    ID3D11PixelShader*        ps           = nullptr;
    ID3D11InputLayout*        il           = nullptr;
    ID3D11BlendState*         bs           = nullptr;
    float                     bsFactor[4]  = { -1, -1, -1, -1 };
    UINT                      bsMask       = 0;
    ID3D11DepthStencilState*  dss          = nullptr;
    UINT                      stencilRef   = 0xFFFFFFFFu;
    ID3D11RasterizerState*    rs           = nullptr;
    D3D_PRIMITIVE_TOPOLOGY    topo         = D3D_PRIMITIVE_TOPOLOGY_UNDEFINED;
    ID3D11Buffer*             vb           = nullptr;
    UINT                      vbStride     = 0;
    UINT                      vbOffset     = 0;
    ID3D11Buffer*             ib           = nullptr;
    DXGI_FORMAT               ibFormat     = DXGI_FORMAT_UNKNOWN;
    UINT                      ibOffset     = 0;
    ID3D11Buffer*             vsCB0        = nullptr;
    ID3D11Buffer*             psCB0        = nullptr;
    ID3D11ShaderResourceView* psSRV[8]     = {};
    UINT                      psSRVCount   = 0;   // contiguous bound count
    ID3D11SamplerState*       psSamp[8]    = {};
    UINT                      psSampCount  = 0;

    // Stats
    uint64_t totalCalls   = 0;
    uint64_t skippedCalls = 0;
};
static D3DStateCache g_sc;

static inline void SC_Invalidate() {
    g_sc = D3DStateCache{};
}

static inline void SC_VS(ID3D11VertexShader* p) {
    g_sc.totalCalls++;
    if (g_sc.vs == p) { g_sc.skippedCalls++; return; }
    g_sc.vs = p;
    g_d3d11.context->VSSetShader(p, nullptr, 0);
}
static inline void SC_PS(ID3D11PixelShader* p) {
    g_sc.totalCalls++;
    if (g_sc.ps == p) { g_sc.skippedCalls++; return; }
    g_sc.ps = p;
    g_d3d11.context->PSSetShader(p, nullptr, 0);
}
static inline void SC_IL(ID3D11InputLayout* p) {
    g_sc.totalCalls++;
    if (g_sc.il == p) { g_sc.skippedCalls++; return; }
    g_sc.il = p;
    g_d3d11.context->IASetInputLayout(p);
}
static inline void SC_BlendState(ID3D11BlendState* p, const float bf[4], UINT mask) {
    g_sc.totalCalls++;
    if (g_sc.bs == p && g_sc.bsMask == mask
        && g_sc.bsFactor[0] == bf[0] && g_sc.bsFactor[1] == bf[1]
        && g_sc.bsFactor[2] == bf[2] && g_sc.bsFactor[3] == bf[3]) {
        g_sc.skippedCalls++;
        return;
    }
    g_sc.bs = p;
    g_sc.bsMask = mask;
    for (int i = 0; i < 4; i++) g_sc.bsFactor[i] = bf[i];
    g_d3d11.context->OMSetBlendState(p, bf, mask);
}
static inline void SC_DepthStencil(ID3D11DepthStencilState* p, UINT ref) {
    g_sc.totalCalls++;
    if (g_sc.dss == p && g_sc.stencilRef == ref) { g_sc.skippedCalls++; return; }
    g_sc.dss = p; g_sc.stencilRef = ref;
    g_d3d11.context->OMSetDepthStencilState(p, ref);
}
static inline void SC_Raster(ID3D11RasterizerState* p) {
    g_sc.totalCalls++;
    if (g_sc.rs == p) { g_sc.skippedCalls++; return; }
    g_sc.rs = p;
    g_d3d11.context->RSSetState(p);
}
static inline void SC_Topology(D3D_PRIMITIVE_TOPOLOGY t) {
    g_sc.totalCalls++;
    if (g_sc.topo == t) { g_sc.skippedCalls++; return; }
    g_sc.topo = t;
    g_d3d11.context->IASetPrimitiveTopology(t);
}
static inline void SC_VB(ID3D11Buffer* p, UINT stride, UINT offset) {
    g_sc.totalCalls++;
    if (g_sc.vb == p && g_sc.vbStride == stride && g_sc.vbOffset == offset) {
        g_sc.skippedCalls++;
        return;
    }
    g_sc.vb = p; g_sc.vbStride = stride; g_sc.vbOffset = offset;
    g_d3d11.context->IASetVertexBuffers(0, 1, &p, &stride, &offset);
}
static inline void SC_IB(ID3D11Buffer* p, DXGI_FORMAT fmt, UINT offset) {
    g_sc.totalCalls++;
    if (g_sc.ib == p && g_sc.ibFormat == fmt && g_sc.ibOffset == offset) {
        g_sc.skippedCalls++;
        return;
    }
    g_sc.ib = p; g_sc.ibFormat = fmt; g_sc.ibOffset = offset;
    g_d3d11.context->IASetIndexBuffer(p, fmt, offset);
}
static inline void SC_VSCB0(ID3D11Buffer* p) {
    g_sc.totalCalls++;
    if (g_sc.vsCB0 == p) { g_sc.skippedCalls++; return; }
    g_sc.vsCB0 = p;
    g_d3d11.context->VSSetConstantBuffers(0, 1, &p);
}
static inline void SC_PSCB0(ID3D11Buffer* p) {
    g_sc.totalCalls++;
    if (g_sc.psCB0 == p) { g_sc.skippedCalls++; return; }
    g_sc.psCB0 = p;
    g_d3d11.context->PSSetConstantBuffers(0, 1, &p);
}
static inline void SC_PSSRVs(UINT count, ID3D11ShaderResourceView* const* srvs) {
    g_sc.totalCalls++;
    if (count <= 8) {
        bool same = (count == g_sc.psSRVCount);
        if (same) {
            for (UINT i = 0; i < count; i++) {
                if (g_sc.psSRV[i] != srvs[i]) { same = false; break; }
            }
        }
        if (same) { g_sc.skippedCalls++; return; }
        for (UINT i = 0; i < count; i++) g_sc.psSRV[i] = srvs[i];
        // If we previously bound more, those slots are now dangling in cache —
        // zero them so a follow-up smaller bind doesn't think they match.
        for (UINT i = count; i < g_sc.psSRVCount && i < 8; i++) g_sc.psSRV[i] = nullptr;
        g_sc.psSRVCount = count;
    }
    g_d3d11.context->PSSetShaderResources(0, count, srvs);
}
static inline void SC_PSSamplers(UINT count, ID3D11SamplerState* const* samps) {
    g_sc.totalCalls++;
    if (count <= 8) {
        bool same = (count == g_sc.psSampCount);
        if (same) {
            for (UINT i = 0; i < count; i++) {
                if (g_sc.psSamp[i] != samps[i]) { same = false; break; }
            }
        }
        if (same) { g_sc.skippedCalls++; return; }
        for (UINT i = 0; i < count; i++) g_sc.psSamp[i] = samps[i];
        for (UINT i = count; i < g_sc.psSampCount && i < 8; i++) g_sc.psSamp[i] = nullptr;
        g_sc.psSampCount = count;
    }
    g_d3d11.context->PSSetSamplers(0, count, samps);
}

// Periodic stats dump (gated by B3_DEBUG_SC_STATS).
static inline void SC_FrameStats() {
    if (!g_dbg.scStats) return;
    static uint32_t s_frames = 0;
    static uint64_t s_lastTotal = 0, s_lastSkipped = 0;
    if (++s_frames % 256 == 0) {
        uint64_t dt = g_sc.totalCalls   - s_lastTotal;
        uint64_t ds = g_sc.skippedCalls - s_lastSkipped;
        s_lastTotal   = g_sc.totalCalls;
        s_lastSkipped = g_sc.skippedCalls;
        if (dt) {
            fprintf(stderr,
                "[SC] last 256 frames: %llu state calls, %llu filtered (%.1f%%)\n",
                (unsigned long long)dt, (unsigned long long)ds,
                (double)ds * 100.0 / (double)dt);
        }
    }
}

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
static constexpr uint32_t X_D3DFMT_G8B8         = 0x28;

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
// Relocated from the Xbox-canonical D3DVIEWPORT8 offset region to avoid
// collision with D3DTS_VIEW (+0xC60..0xC9F) and D3DTS_PROJECTION
// (+0xCA0..0xCDF) which engine code reads via D3D_pDevice.
static constexpr uint32_t kDeviceViewport     = 0x1E00;  // D3DVIEWPORT8: X,Y,W,H,MinZ,MaxZ

// Xbox NV2A primitive types used by RenderWare im2d
static constexpr uint32_t NV2A_PRIM_POINTS      = 1;
static constexpr uint32_t NV2A_PRIM_LINES       = 2;
static constexpr uint32_t NV2A_PRIM_LINESTRIP   = 3;
static constexpr uint32_t NV2A_PRIM_TRIANGLES   = 5;
static constexpr uint32_t NV2A_PRIM_TRISTRIP    = 6;
static constexpr uint32_t NV2A_PRIM_TRIFAN      = 7;
static constexpr uint32_t NV2A_PRIM_QUADS       = 8;
static constexpr uint32_t NV2A_PRIM_QUADSTRIP   = 9;

static bool IsRTFormat(uint8_t xFmt) {
    switch (xFmt) {
    case X_D3DFMT_A8R8G8B8: case X_D3DFMT_LIN_A8R8G8B8:
    case X_D3DFMT_X8R8G8B8: case X_D3DFMT_LIN_X8R8G8B8:
    case X_D3DFMT_R5G6B5:   case 0x1C: // LIN_R5G6B5
    case X_D3DFMT_A1R5G5B5: case 0x1D: // LIN_A1R5G5B5
    case X_D3DFMT_A4R4G4B4:
    case 0x17: // LIN_G8B8
    case 0x11: // G8B8
    case 0x19: // LIN_A8
    case 0x01: // AL8
    case 0x00: // L8
    case 0x0B: // P8
    case 0x0F: // DXT5
    case 0x0C: // DXT1
    case 0x0E: // DXT3
        return true;
    default:
        return false;
    }
}

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
static constexpr uint32_t NV2A_SET_ALPHA_TEST_ENABLE   = 0x00040300;
static constexpr uint32_t NV2A_SET_BLEND_ENABLE        = 0x00040304;
static constexpr uint32_t NV2A_SET_DITHER_ENABLE           = 0x00040310; // ignored
static constexpr uint32_t NV2A_SET_STENCIL_TEST_ENABLE     = 0x0004032C;
static constexpr uint32_t NV2A_SET_POLY_OFFSET_FILL_ENABLE = 0x00040338; // ignored
static constexpr uint32_t NV2A_SET_ALPHA_FUNC              = 0x0004033C; // was 0x338 (wrong)
static constexpr uint32_t NV2A_SET_ALPHA_REF               = 0x00040340;
static constexpr uint32_t NV2A_SET_BLEND_FUNC_SRC      = 0x00040344;
static constexpr uint32_t NV2A_SET_BLEND_FUNC_DST      = 0x00040348;
static constexpr uint32_t NV2A_SET_BLEND_EQUATION      = 0x00040350;
static constexpr uint32_t NV2A_SET_DEPTH_FUNC          = 0x00040354;
static constexpr uint32_t NV2A_SET_COLOR_MASK          = 0x00040358;
static constexpr uint32_t NV2A_SET_DEPTH_MASK          = 0x0004035C;
static constexpr uint32_t NV2A_SET_STENCIL_MASK        = 0x00040360;
static constexpr uint32_t NV2A_SET_STENCIL_FUNC        = 0x00040364;
static constexpr uint32_t NV2A_SET_STENCIL_FUNC_REF    = 0x00040368;
static constexpr uint32_t NV2A_SET_STENCIL_FUNC_MASK   = 0x0004036C;
static constexpr uint32_t NV2A_SET_STENCIL_OP_FAIL     = 0x00040370;
static constexpr uint32_t NV2A_SET_STENCIL_OP_ZFAIL    = 0x00040374;
static constexpr uint32_t NV2A_SET_STENCIL_OP_ZPASS    = 0x00040378;

// Tracked GPU render states
static bool g_alphaTestEnabled   = false;
static bool g_alphaBlendEnabled  = false;
static uint32_t g_alphaRef       = 0;
static uint32_t g_alphaFunc      = 8; // D3DCMP_ALWAYS
static uint32_t g_blendSrc       = 1; // D3DBLEND_ONE
static uint32_t g_blendDst       = 0; // D3DBLEND_ZERO
// NV097 SET_BLEND_EQUATION: 0x8006=ADD, 0x800A=SUBTRACT, 0x8009=REV_SUBTRACT,
//   0x8007=MIN, 0x8008=MAX. Default ADD.
static uint32_t g_blendEquation  = 0x8006;
// NV097 depth func: GL_LEQUAL=0x0203 default. Values 0x0200..0x0207.
static uint32_t g_depthFunc        = 0x0203;
static bool     g_depthWriteEnable = true;
// NV097 SET_COLOR_MASK: per-byte ARGB (byte0=alpha,1=red,2=green,3=blue).
// Each byte is 0 or 1. 0x01010101 = write all channels.
static uint32_t g_colorWriteMask   = 0x01010101u;
// Stencil state. NV097 stencil func uses GL constants 0x0200..0x0207 (same
// as depth). Stencil ops: 0x1E00=KEEP 0x0000=ZERO 0x1E01=REPLACE
//   0x1E02=INCR_SAT 0x1E03=DECR_SAT 0x150A=INVERT 0x8507=INCR 0x8508=DECR.
static bool     g_stencilTestEnable = false;
static uint32_t g_stencilMask       = 0xFFFFFFFF; // write mask
static uint32_t g_stencilFunc       = 0x0207;     // ALWAYS
static uint32_t g_stencilRef        = 0;
static uint32_t g_stencilFuncMask   = 0xFFFFFFFF; // read/compare mask
static uint32_t g_stencilOpFail     = 0x1E00;     // KEEP
static uint32_t g_stencilOpZFail    = 0x1E00;     // KEEP
static uint32_t g_stencilOpZPass    = 0x1E00;     // KEEP

// RW render state lookup table address (maps RW state index -> NV2A method)
static constexpr uint32_t kRWStateMethodTable = 0x3A8190;
static constexpr uint32_t kRWStateMethodCount = 166;

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

    // NOTE: we deliberately do *not* init the game's own D3D_pDevice global
    // at guest 0x35FB48. Populating it would activate ~20 recompiled engine
    // code paths (SetScreenSpaceOffset, flicker filter, passthrough program
    // push-buffer emitters, etc.) that then trample or reconfigure state
    // our HLE rendering pipeline assumes stable. Instead, individual engine
    // helpers that require the pointer are HLE'd directly — see
    // `B3_sub_40660_HLE` below.

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
            // Mirror back-buffer surface pointers to cdev+0x1A14+i*4 so that
            // native code reading *(D3D_pDevice+0x1A14) (where D3D_pDevice=0)
            // finds a valid surface (used by sub_402C0 to obtain the RT).
            {
                uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
                X86_MEM_WRITE_u32(base, cdev + 0x1A14 + i * 4, surfAddr);
            }
            // The first back-buffer is also the initial render target.
            // Write to both the HLE tracking field and the Xbox SDK's own field
            // (D3D_pDevice+0x1A04) so native code that reads the latter sees a
            // valid surface address from the very first frame.
            if (i == 0) {
                uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
                X86_MEM_WRITE_u32(base, cdev + 0x1A04, surfAddr);
                X86_MEM_WRITE_u32(base, kDeviceAddr + 0x1A04, surfAddr);
                X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, surfAddr);
            }
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

// ---- Post-processing diagnostic (B3_DEBUG_PP=1) ----------------------------
// Logs RT transitions, per-RT draw counts, and texture binds that resolve to
// a tracked guest render-target SRV. Use to pinpoint where a post-processing
// chain (motion blur, bloom, heat haze, etc.) breaks.
static bool PpDebug() {
    static int s_state = -1;
    if (s_state == -1) {
        const char* e = std::getenv("B3_DEBUG_PP");
        s_state = (e && *e && *e != '0') ? 1 : 0;
    }
    return s_state != 0;
}
static uint32_t g_ppDrawsSinceRT = 0;
static uint32_t g_ppPrevRT       = 0xFFFFFFFFu;
static uint32_t g_ppFrame        = 0;

// D3DDevice_Swap  (0xD6D30) — 1 arg, ret 4
void D3DDevice_Swap(X86Context& ctx, uint8_t* base)
{
    uint32_t flags = GuestArg32(ctx, base, 0);
    //fprintf(stderr, "[HLE] D3DDevice_Swap(flags=0x%X) frame=%u\n", flags, g_swapCount);

    g_swapCount++;
    g_vblankCount++;
    g_drawCallCount = 0;
    if (PpDebug()) {
        fprintf(stderr, "[PP] === frame %u end (last RT 0x%08X had %u draws) ===\n",
                g_ppFrame, g_ppPrevRT, g_ppDrawsSinceRT);
        ++g_ppFrame;
        g_ppDrawsSinceRT = 0;
    }

    // Pump Win32 messages so the window stays responsive.
    HLE_PumpMessages();

    // ---- D3D11 present + VBlank signaling ------------------------------------
    if (g_d3d11.initialized && g_d3d11.swapChain) {
        // Sync interval: 1 = vsync (caps at refresh rate, typically 60Hz),
        // 0 = unlocked (present as fast as possible). Allow override via
        // B3_VSYNC env var: "0" disables vsync, anything else (or unset)
        // keeps the default vsync-on behavior.
        static const UINT s_syncInterval = []() -> UINT {
            if (const char* v = std::getenv("B3_VSYNC")) {
                if (v[0] == '0' && v[1] == '\0') return 0;
            }
            return 1;
        }();
        // Blit our scene render target into the DXGI swap-chain buffer.
        // (Scene tex is RT+SR, DXGI buffer is RT-only — formats match.)
        if (g_d3d11.swapChainTex && g_d3d11.backBufferTex) {
            // Preserve the completed frame for the next frame's Bloom/Blur
            if (g_d3d11.prevSceneTex) {
                g_d3d11.context->CopyResource(g_d3d11.prevSceneTex, g_d3d11.backBufferTex);
            }
            // Blit our scene render target into the DXGI swap-chain buffer.
            g_d3d11.context->CopyResource(g_d3d11.swapChainTex, g_d3d11.backBufferTex);
        }
        g_d3d11.swapChain->Present(s_syncInterval, 0);
        SC_FrameStats();
        // Present() does not actually clear pipeline state on D3D11, but the
        // swap-chain's back-buffer RTV may be reallocated on resize, which
        // would leave stale OM bindings. Reset the cache here so any future
        // RT change is observed by the next draw's binding sequence.
        SC_Invalidate();

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

        // Allow disabling the 60Hz throttle via env var. When B3_VSYNC=0
        // (same switch that unlocks DXGI Present), skip the wait entirely
        // so the FPS counter can measure rates above 60.
        static const bool s_throttle = []() {
            if (const char* v = std::getenv("B3_VSYNC")) {
                if (v[0] == '0' && v[1] == '\0') return false;
            }
            return true;
        }();

        static bool s_timerInit = false;
        if (!s_timerInit) {
            timeBeginPeriod(1);
            s_timerInit = true;
        }

        static auto s_frameStart = Clock::now();
        auto elapsed = Clock::now() - s_frameStart;

        // Only sleep if this frame completed faster than one VBlank period.
        if (s_throttle && elapsed < kFramePeriod) {
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
    SampleDebugFlagsOnce();
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

        // Previously we mirrored VIEW/PROJ into the Xbox D3DDevice struct
        // slots (pDev+0xC60 / pDev+0xCA0) so the game's `sub_40660`
        // extractor could build a correct MVP. We now instead intercept
        // `sub_40660` directly (`B3_sub_40660_HLE`) which pulls from the
        // cached `g_lastGoodView/Proj` below — avoiding the need to
        // initialise the game's D3D_pDevice global and the cascade of
        // side-effects that unlocks.

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

    GuestStackCleanup(ctx, 8);
}

// ============================================================================
// sub_40660 HLE wrapper — MVP-source matrix extractor
// ============================================================================
// Burnout3's `sub_40660` (inside `CB3GraphicsManager::OpenViewport`) is the
// root of the per-frame MVP composition chain:
//     D3D_pDevice at 0x35FB48 -> read VIEW from +0xC60, PROJ from +0xCA0,
//       extra vec4 from +0xEE0 -> compose VIEW*PROJ transposed -> eventually
//       uploaded to c[112..115] by sub_40500.
//
// We can't simply populate 0x35FB48 globally: doing so activates a dozen
// other recompiled engine paths (passthrough-program push-buffer writers,
// SetScreenSpaceOffset, flicker filter, etc.) that subtly misconfigure
// shader and texture state and leave meshes rendering as solid colour.
//
// Instead, wrap the function: allocate a one-shot scratch buffer, populate
// *only* +0xC60 / +0xCA0 / +0xEE0 from our cached matrices, point
// D3D_pDevice at the scratch for the duration of this call, run the
// original recompiled sub_40660, then clear D3D_pDevice back to zero so
// all the other engine paths remain inert.
static uint32_t g_b3PDevScratch = 0;

void sub_40660_orig(X86Context& ctx, uint8_t* base) {
	// 0x40660: push ebp
	{ auto _pv = (uint32_t)(ctx.ebp); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40661: mov ebp, esp
	ctx.ebp = ctx.esp;
	// 0x40663: and esp, 0xFFFFFFF0
	ctx.esp = ctx.esp & -16;
	X86_UPDATE_FLAGS_LOGIC(ctx, ctx.esp, 32);
	// 0x40666: sub esp, 0x54
	{ uint32_t _d = ctx.esp; uint32_t _s = 84;
	  uint64_t _res = (uint64_t)_d - (uint64_t)_s;
	  X86_UPDATE_FLAGS_SUB(ctx, _res, (int32_t)_d, (int32_t)_s, 32);
	  ctx.esp = (uint32_t)_res; }
	// 0x40669: mov eax, [ebp+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x4066C: mov ecx, [eax+0x3B0]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x3B0u);
	// 0x40672: push ebx
	{ auto _pv = (uint32_t)(ctx.ebx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40673: mov ebx, [ecx+0x58]
	ctx.ebx = X86_MEM_READ_u32(base, ctx.ecx + 0x58u);
	// 0x40676: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x40679: mov ecx, [eax+0x80]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x80u);
	// 0x4067F: mov [edx+0x160], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x160u, ctx.ecx);
	// 0x40685: mov ecx, [eax+0x84]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.eax + 0x84u);
	// 0x4068B: mov [edx+0x164], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x164u, ctx.ecx);
	// 0x40691: add eax, 0x80
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(128);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)128, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x40696: mov eax, [eax+0x08]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x40699: mov [edx+0x168], eax
	X86_MEM_WRITE_u32(base, ctx.edx + 0x168u, ctx.eax);
	// 0x4069F: mov ecx, [ebx+0x84]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.ebx + 0x84u);
	// 0x406A5: mov eax, [0x0035FB48]
	ctx.eax = X86_MEM_READ_u32(base, 0x35FB48u);
	// 0x406AA: mov [edx+0x170], ecx
	X86_MEM_WRITE_u32(base, ctx.edx + 0x170u, ctx.ecx);
	// 0x406B0: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x406B1: lea esi, [eax+0xC60]
	ctx.esi = ctx.eax + 0xC60u;
	// 0x406B7: push edi
	{ auto _pv = (uint32_t)(ctx.edi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x406B8: mov ecx, 0x10
	ctx.ecx = 16;
	// 0x406BD: mov edi, edx
	ctx.edi = ctx.edx;
	// 0x406BF: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x406C1: lea esi, [eax+0xCA0]
	ctx.esi = ctx.eax + 0xCA0u;
	// 0x406C7: add eax, 0xEE0
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(3808);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)3808, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x406CC: lea edi, [edx+0x40]
	ctx.edi = ctx.edx + 0x40u;
	// 0x406CF: mov ecx, 0x10
	ctx.ecx = 16;
	// 0x406D4: rep movsd
	while (ctx.ecx) {
		X86_MEM_WRITE_u32(base, ctx.edi, X86_MEM_READ_u32(base, ctx.esi));
		ctx.esi += ctx.flags.df ? -4 : 4;
		ctx.edi += ctx.flags.df ? -4 : 4;
		ctx.ecx--;
	}
	// 0x406D6: mov esi, [eax]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax);
	// 0x406D8: lea ecx, [edx+0x100]
	ctx.ecx = ctx.edx + 0x100u;
	// 0x406DE: mov [ecx], esi
	X86_MEM_WRITE_u32(base, ctx.ecx, ctx.esi);
	// 0x406E0: mov esi, [eax+0x04]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x406E3: mov [ecx+0x04], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x4u, ctx.esi);
	// 0x406E6: mov esi, [eax+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x406E9: mov [ecx+0x08], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x8u, ctx.esi);
	// 0x406EC: mov esi, [eax+0x0C]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0xCu);
	// 0x406EF: mov [ecx+0x0C], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0xCu, ctx.esi);
	// 0x406F2: mov esi, [eax+0x10]
	ctx.esi = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x406F5: mov [ecx+0x10], esi
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x10u, ctx.esi);
	// 0x406F8: mov eax, [eax+0x14]
	ctx.eax = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x406FB: mov [ecx+0x14], eax
	X86_MEM_WRITE_u32(base, ctx.ecx + 0x14u, ctx.eax);
	// 0x406FE: lea eax, [edx+0x40]
	ctx.eax = ctx.edx + 0x40u;
	// 0x40701: push eax
	{ auto _pv = (uint32_t)(ctx.eax); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40702: push edx
	{ auto _pv = (uint32_t)(ctx.edx); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x40703: lea esi, [edx+0x80]
	ctx.esi = ctx.edx + 0x80u;
	// 0x40709: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x4070A: call 0x001CF153
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1CF153(ctx, base);
	ctx.esp += 4;
	// 0x4070F: lea ecx, [edx+0xC0]
	ctx.ecx = ctx.edx + 0xC0u;
	// 0x40715: mov [esp+0x1C], esi
	X86_MEM_WRITE_u32(base, ctx.esp + 0x1Cu, ctx.esi);
	// 0x40719: mov [esp+0x18], ecx
	X86_MEM_WRITE_u32(base, ctx.esp + 0x18u, ctx.ecx);
	// 0x4071D: mov ecx, [esp+0x1C]
	ctx.ecx = X86_MEM_READ_u32(base, ctx.esp + 0x1Cu);
	// 0x40721: mov eax, [esp+0x18]
	ctx.eax = X86_MEM_READ_u32(base, ctx.esp + 0x18u);
	// 0x40725: movaps xmm0, [ecx]
	X86_MEM_READ_XMM(base, ctx.ecx, ctx.xmm[0]);
	// 0x40728: movaps xmm2, [ecx+0x10]
	X86_MEM_READ_XMM(base, ctx.ecx + 0x10u, ctx.xmm[2]);
	// 0x4072C: movaps xmm3, [ecx+0x20]
	X86_MEM_READ_XMM(base, ctx.ecx + 0x20u, ctx.xmm[3]);
	// 0x40730: movaps xmm5, [ecx+0x30]
	X86_MEM_READ_XMM(base, ctx.ecx + 0x30u, ctx.xmm[5]);
	// 0x40734: movaps xmm1, xmm0
	ctx.xmm[1] = ctx.xmm[0];
	// 0x40737: movaps xmm4, xmm3
	ctx.xmm[4] = ctx.xmm[3];
	// 0x4073A: unpcklps xmm0, xmm2
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[0].f32[0]; _tmp.f32[1] = ctx.xmm[2].f32[0];
	  _tmp.f32[2] = ctx.xmm[0].f32[1]; _tmp.f32[3] = ctx.xmm[2].f32[1];
	  ctx.xmm[0] = _tmp; }
	// 0x4073D: unpckhps xmm1, xmm2
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[1].f32[2]; _tmp.f32[1] = ctx.xmm[2].f32[2];
	  _tmp.f32[2] = ctx.xmm[1].f32[3]; _tmp.f32[3] = ctx.xmm[2].f32[3];
	  ctx.xmm[1] = _tmp; }
	// 0x40740: unpcklps xmm3, xmm5
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[3].f32[0]; _tmp.f32[1] = ctx.xmm[5].f32[0];
	  _tmp.f32[2] = ctx.xmm[3].f32[1]; _tmp.f32[3] = ctx.xmm[5].f32[1];
	  ctx.xmm[3] = _tmp; }
	// 0x40743: unpckhps xmm4, xmm5
	{ X86XmmReg _tmp;
	  _tmp.f32[0] = ctx.xmm[4].f32[2]; _tmp.f32[1] = ctx.xmm[5].f32[2];
	  _tmp.f32[2] = ctx.xmm[4].f32[3]; _tmp.f32[3] = ctx.xmm[5].f32[3];
	  ctx.xmm[4] = _tmp; }
	// 0x40746: movlps [eax], xmm0
	X86_MEM_WRITE_u64(base, ctx.eax, ctx.xmm[0].u64[0]);
	// 0x40749: movlps [eax+0x08], xmm3
	X86_MEM_WRITE_u64(base, ctx.eax + 0x8u, ctx.xmm[3].u64[0]);
	// 0x4074D: movhps qword ptr [eax+0x10], xmm0
	X86_MEM_WRITE_u64(base, ctx.eax + 0x10u, ctx.xmm[0].u64[1]);
	// 0x40751: movhps qword ptr [eax+0x18], xmm3
	X86_MEM_WRITE_u64(base, ctx.eax + 0x18u, ctx.xmm[3].u64[1]);
	// 0x40755: movlps [eax+0x20], xmm1
	X86_MEM_WRITE_u64(base, ctx.eax + 0x20u, ctx.xmm[1].u64[0]);
	// 0x40759: movlps [eax+0x28], xmm4
	X86_MEM_WRITE_u64(base, ctx.eax + 0x28u, ctx.xmm[4].u64[0]);
	// 0x4075D: movhps qword ptr [eax+0x30], xmm1
	X86_MEM_WRITE_u64(base, ctx.eax + 0x30u, ctx.xmm[1].u64[1]);
	// 0x40761: movhps qword ptr [eax+0x38], xmm4
	X86_MEM_WRITE_u64(base, ctx.eax + 0x38u, ctx.xmm[4].u64[1]);
	// 0x40765: mov eax, [ebx+0x04]
	ctx.eax = X86_MEM_READ_u32(base, ctx.ebx + 0x4u);
	// 0x40768: movss xmm0, dword ptr [eax+0x50]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x50u);
	// 0x4076D: add eax, 0x50
	{ uint64_t _res = (uint64_t)(uint32_t)(ctx.eax) + (uint64_t)(uint32_t)(80);
	  X86_UPDATE_FLAGS_ADD(ctx, _res, (int32_t)ctx.eax, (int32_t)80, 32);
	  ctx.eax = (uint32_t)_res; }
	// 0x40770: mov esi, [ebp+0x08]
	ctx.esi = X86_MEM_READ_u32(base, ctx.ebp + 0x8u);
	// 0x40773: movss [esp+0x20], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x20u, ctx.xmm[0].u32[0]);
	// 0x40779: movss xmm0, dword ptr [eax+0x04]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x4u);
	// 0x4077E: movss [esp+0x24], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x24u, ctx.xmm[0].u32[0]);
	// 0x40784: movss xmm0, dword ptr [eax+0x08]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x8u);
	// 0x40789: movss [esp+0x28], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x28u, ctx.xmm[0].u32[0]);
	// 0x4078F: movss xmm0, dword ptr [eax+0x10]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x10u);
	// 0x40794: movss [esp+0x30], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x30u, ctx.xmm[0].u32[0]);
	// 0x4079A: movss xmm0, dword ptr [eax+0x14]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x14u);
	// 0x4079F: movss [esp+0x34], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x34u, ctx.xmm[0].u32[0]);
	// 0x407A5: movss xmm0, dword ptr [eax+0x18]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x18u);
	// 0x407AA: movss [esp+0x38], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x38u, ctx.xmm[0].u32[0]);
	// 0x407B0: movss xmm0, dword ptr [eax+0x20]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x20u);
	// 0x407B5: movss [esp+0x40], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x40u, ctx.xmm[0].u32[0]);
	// 0x407BB: movss xmm0, dword ptr [eax+0x24]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x24u);
	// 0x407C0: movss [esp+0x44], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x44u, ctx.xmm[0].u32[0]);
	// 0x407C6: movss xmm0, dword ptr [eax+0x28]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x28u);
	// 0x407CB: movss [esp+0x48], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x48u, ctx.xmm[0].u32[0]);
	// 0x407D1: movss xmm0, dword ptr [eax+0x30]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x30u);
	// 0x407D6: movss [esp+0x50], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x50u, ctx.xmm[0].u32[0]);
	// 0x407DC: movss xmm0, dword ptr [eax+0x34]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x34u);
	// 0x407E1: movss [esp+0x54], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x54u, ctx.xmm[0].u32[0]);
	// 0x407E7: movss xmm0, dword ptr [eax+0x38]
	ctx.xmm[0].u32[0] = X86_MEM_READ_u32(base, ctx.eax + 0x38u);
	// 0x407EC: lea ecx, [edx+0x120]
	ctx.ecx = ctx.edx + 0x120u;
	// 0x407F2: push esi
	{ auto _pv = (uint32_t)(ctx.esi); ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, _pv); }
	// 0x407F3: lea eax, [esp+0x24]
	ctx.eax = ctx.esp + 0x24u;
	// 0x407F7: movss [esp+0x5C], xmm0
	X86_MEM_WRITE_u32(base, ctx.esp + 0x5Cu, ctx.xmm[0].u32[0]);
	// 0x407FD: call 0x00040310
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_40310(ctx, base);
	ctx.esp += 4;
	// 0x40802: lea ecx, [esi+0x680]
	ctx.ecx = ctx.esi + 0x680u;
	// 0x40808: mov eax, ebx
	ctx.eax = ctx.ebx;
	// 0x4080A: call 0x001C8F70
	ctx.esp -= 4; X86_MEM_WRITE_u32(base, ctx.esp, 0);
	sub_1C8F70(ctx, base);
	ctx.esp += 4;
	// 0x4080F: pop edi
	ctx.edi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40810: pop esi
	ctx.esi = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40811: pop ebx
	ctx.ebx = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40812: mov esp, ebp
	ctx.esp = ctx.ebp;
	// 0x40814: pop ebp
	ctx.ebp = X86_MEM_READ_u32(base, ctx.esp);
	ctx.esp += 4;
	// 0x40815: ret 0x04
	ctx.esp += 4;
	return;
}

void sub_40660(X86Context& ctx, uint8_t* base)
{
    if (g_b3PDevScratch == 0) {
        // Give it a full 4 KiB so any future extension offset we haven't
        // yet mapped falls inside a dead zone rather than walking off the
        // allocation.
        g_b3PDevScratch = ContigAlloc(0x1000, 16);
        if (g_b3PDevScratch != 0) {
            memset(base + g_b3PDevScratch, 0, 0x1000);
        }
    }

    if (g_b3PDevScratch != 0) {
        // Populate only the offsets the game's sub_40660 reads from.
        if (g_haveView)
            memcpy(base + g_b3PDevScratch + 0xC60u, g_lastGoodView, 64);
        if (g_haveProj)
            memcpy(base + g_b3PDevScratch + 0xCA0u, g_lastGoodProj, 64);
        // The +0xEE0 slot is copied as a single 16-byte vector (4 floats).
        // We don't know its exact semantics (may be an inverse-view or a
        // viewport/bias vector); leaving it zero has produced correct
        // placement in tests, so keep that default.
        memset(base + g_b3PDevScratch + 0xEE0u, 0, 16);
    }

    uint32_t savedPDev = X86_MEM_READ_u32(base, 0x35FB48u);
    if (g_b3PDevScratch != 0)
        X86_MEM_WRITE_u32(base, 0x35FB48u, g_b3PDevScratch);

    // Call the original recompiled implementation (preserves all the
    // peripheral engine-state setup that sub_40660 does beyond the matrix
    // reads — e.g. writes to edx+0x160..0x170 fed from other engine
    // structures, plus the trailing calls to sub_40310 / sub_1C8F70).
    sub_40660_orig(ctx, base);

    // Restore so none of the ~20 other recompiled paths that early-out
    // when D3D_pDevice==0 start running.
    X86_MEM_WRITE_u32(base, 0x35FB48u, savedPDev);
}

// ============================================================================
// Render target / back buffer / depth stencil
// ============================================================================

// D3DDevice_SetRenderTarget  (0x96AB0) — 2 args, ret 8
void D3DDevice_SetRenderTarget(X86Context& ctx, uint8_t* base)
{
    uint32_t pRT = GuestArg32(ctx, base, 0);
    uint32_t pDS = GuestArg32(ctx, base, 1);

    // Write to the Xbox SDK's own current-RT field so native game code that
    // reads it (sub_3C810, sub_32810) sees the correct value.
    // D3D_pDevice lives at guest 0x35FB48; we deliberately keep it 0 to avoid
    // activating ~20 engine code paths, so those functions read from
    // (cdev=0)+0x1A04 = guest address 0x1A04.  Write there AND to our own
    // HLE device block at kDeviceAddr+0x1A04.
    {
        uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
        X86_MEM_WRITE_u32(base, cdev + 0x1A04, pRT);
        X86_MEM_WRITE_u32(base, cdev + 0x1A08, pDS);
    }
    X86_MEM_WRITE_u32(base, kDeviceAddr + 0x1A04, pRT);
    X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, pRT);
    X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceDepthStencil, pDS);

    g_d3d11.currentRTSurf = pRT;

    if (PpDebug()) {
        uint32_t pParent = pRT ? X86_MEM_READ_u32(base, pRT + 0x14) : 0;
        bool inMap = g_d3d11.guestRTBySurface.count(pRT) != 0;
        fprintf(stderr, "[PP] f=%u SetRT rt=0x%08X ds=0x%08X parent=0x%08X inMap=%d (prev=0x%08X had %u draws)\n",
                g_ppFrame, pRT, pDS, pParent, (int)inMap, g_ppPrevRT, g_ppDrawsSinceRT);
        g_ppPrevRT = pRT;
        g_ppDrawsSinceRT = 0;
    }

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
        memcpy(base + kDeviceAddr + kDeviceViewport, base + pVP, 24);
        //fprintf(stderr, "[HLE] SetViewport(x=%u, y=%u, w=%u, h=%u)\n",
        //    X86_MEM_READ_u32(base,kDeviceAddr+kDeviceViewport+0),
        //    X86_MEM_READ_u32(base,kDeviceAddr+kDeviceViewport+4),
        //    X86_MEM_READ_u32(base,kDeviceAddr+kDeviceViewport+8),
        //    X86_MEM_READ_u32(base,kDeviceAddr+kDeviceViewport+12));
    }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetViewportOffsetAndScale  (0xD5520) — 2 args, ret 8
void D3DDevice_GetViewportOffsetAndScale(X86Context& ctx, uint8_t* base)
{
    uint32_t pOffset = GuestArg32(ctx, base, 0);
    uint32_t pScale  = GuestArg32(ctx, base, 1);

    float vpX = (float)X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 0);
    float vpY = (float)X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 4);
    float vpW = (float)X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
    float vpH = (float)X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);

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
extern uint32_t g_currentPSHandle; // defined later in file
extern uint32_t g_texBoundSource[4];
static void HLE_SetTexture(uint8_t* base, uint32_t stage, uint32_t pTexture)
{
    if (stage < 4) {
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0B00 + stage * 4, pTexture);
        g_texBoundSource[stage] = 0; // SRC_HLE
    }
    if (PpDebug() && pTexture != 0) {
        uint32_t dataAddr = X86_MEM_READ_u32(base, pTexture + 4);
        bool byParent = g_d3d11.guestRTByParent.count(pTexture)   != 0;
        bool byData   = g_d3d11.guestRTByDataAddr.count(dataAddr) != 0;
        if (byParent || byData) {
            fprintf(stderr,
                    "[PP] f=%u SetTexture stage=%u hdr=0x%08X data=0x%08X => GuestRT SRV (%s)\n",
                    g_ppFrame, stage, pTexture, dataAddr,
                    byParent ? "parent" : "data");
        }
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

    // Allocate 24 bytes for a full X_D3DSurface struct
    uint32_t surfAddr = ContigAlloc(24, 64);
    X86_MEM_WRITE_u32(base, surfAddr + 0x00,
                      1 | X_D3DCOMMON_TYPE_SURFACE | X_D3DCOMMON_D3DCREATED);
    
    uint32_t parentData = 0;
    uint32_t fmtField = 0;
    uint32_t sizeField = 0;

    if (pThis != 0) {
        parentData = X86_MEM_READ_u32(base, pThis + 0x04);
        fmtField   = X86_MEM_READ_u32(base, pThis + 0x0C);
        sizeField  = X86_MEM_READ_u32(base, pThis + 0x10);
        
        // Advance data pointer based on requested mip level
        uint8_t xFmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
        uint8_t fmtInfo = XboxFormatInfo(xFmt);
        uint32_t bppField = fmtInfo & 0x3C;
        bool isDXT = IsCompressedFormat(xFmt);
        uint32_t compMin = isDXT ? 2 : 0;
        
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        uint32_t logP = (fmtField >> X_D3DFORMAT_PSIZE_SHIFT) & 0xF;

        uint32_t offset = 0;
        uint32_t tU = logU, tV = logV, tP = logP;
        for (uint32_t i = 0; i < level; ++i) {
            uint32_t curU = (tU > compMin) ? tU : compMin;
            uint32_t curV = (tV > compMin) ? tV : compMin;
            uint32_t levelBits = curU + curV + tP;
            offset += (1u << levelBits) * bppField / 8;
            if (tU > 0) tU--;
            if (tV > 0) tV--;
            if (tP > 0) tP--;
        }
        offset = (offset + 127) & ~127u; // Xbox mip sizes are rounded
        parentData += offset;
    }

    X86_MEM_WRITE_u32(base, surfAddr + 0x04, parentData);
    X86_MEM_WRITE_u32(base, surfAddr + 0x08, 0);         // Lock
    X86_MEM_WRITE_u32(base, surfAddr + 0x0C, fmtField);  // Format
    X86_MEM_WRITE_u32(base, surfAddr + 0x10, sizeField); // Size
    X86_MEM_WRITE_u32(base, surfAddr + 0x14, pThis);     // Parent (Fixed offset!)

    if (pThis != 0) {
        uint32_t common = X86_MEM_READ_u32(base, pThis + 0);
        common++;
        X86_MEM_WRITE_u32(base, pThis + 0, common);

        uint8_t xF = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
        if (IsRTFormat(xF)) {
            SurfaceRTBind b;
            b.rt     = nullptr;
            b.mip    = level;
            b.parent = pThis;
            g_d3d11.guestRTBySurface[surfAddr] = b;
            fprintf(stderr, "[D3D11] track RT-surface(GSL) 0x%08X parent=0x%08X mip=%u\n",
                    surfAddr, pThis, level);
        }
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

static uint32_t GetMipFromSurface(uint8_t* base, uint32_t surfAddr, GuestRT* rt) {
    if (!rt || !base || surfAddr == 0) return 0;
    
    uint32_t sData = X86_MEM_READ_u32(base, surfAddr + 4) & 0x0FFFFFFF;
    
    // 1. Look up exact mip offset via the masked data address
    auto it = g_d3d11.guestRTByDataAddr.find(sData);
    if (it != g_d3d11.guestRTByDataAddr.end() && it->second.rt == rt) {
        return it->second.mip;
    }
    
    // 2. Fallback: Compare width to base parent dimensions
    uint32_t sFmt = X86_MEM_READ_u32(base, surfAddr + 12);
    uint32_t sSize = X86_MEM_READ_u32(base, surfAddr + 16);
    
    uint32_t w = 0;
    if (sSize != 0) {
        w = (sSize & X_D3DSIZE_WIDTH_MASK) + 1;
    } else {
        uint32_t logU = (sFmt >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        w = 1u << logU;
    }
    
    if (w > 0 && rt->baseW > 0) {
        uint32_t m = 0;
        uint32_t mw = rt->baseW;
        while (mw > w && m < rt->mipCount - 1) {
            mw = std::max<uint32_t>(1, mw >> 1);
            m++;
        }
        if (mw == w) return m;
    }
    return 0;
}

extern uint8_t* g_b2dBase;

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
        // Pick the active RTV: guest RT-to-texture, or back buffer.
        ID3D11RenderTargetView* activeRTV = g_d3d11.backBufferRTV;
        ID3D11DepthStencilView* activeDSV = g_d3d11.depthDSV;
        bool isGuestRT = false;
        {
            uint32_t surfAddr = g_d3d11.currentRTSurf;
            if (surfAddr == 0)
                surfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
            if (surfAddr != 0) {
                GuestRT* rt = nullptr;
                uint32_t mip = 0;

                auto it = g_d3d11.guestRTBySurface.find(surfAddr);
                if (it != g_d3d11.guestRTBySurface.end()) {
                    rt = it->second.rt;
                    if (!rt) {
                        uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
                        if (pParent != 0) {
                            rt = EnsureGuestRT(base, pParent);
                            if (rt) it->second.rt = rt;
                        }
                    }
                    if (rt) {
                        mip = GetMipFromSurface(base, surfAddr, rt);
                        it->second.mip = mip;
                    }
                } else {
                    uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
                    if (pParent != 0) {
                        rt = EnsureGuestRT(base, pParent);
                        if (rt) {
                            mip = GetMipFromSurface(base, surfAddr, rt);
                            SurfaceRTBind b;
                            b.rt = rt;
                            b.mip = mip;
                            b.parent = pParent;
                            g_d3d11.guestRTBySurface[surfAddr] = b;
                        }
                    }
                }

                if (rt && mip < rt->rtvPerMip.size() && rt->rtvPerMip[mip]) {
                    activeRTV = rt->rtvPerMip[mip];
                    activeDSV = (mip < rt->dsvPerMip.size()) ? rt->dsvPerMip[mip] : nullptr;
                    isGuestRT = true;
                }
            }
        }

        // ---- D3D11 hardware clear ----
        if (flags & X_D3DCLEAR_TARGET) {
            // Convert A8R8G8B8 to float[4] RGBA
            float a = ((color >> 24) & 0xFF) / 255.0f;
            float r = ((color >> 16) & 0xFF) / 255.0f;
            float g = ((color >>  8) & 0xFF) / 255.0f;
            float b = ((color >>  0) & 0xFF) / 255.0f;
            // Force alpha=1 on the main backbuffer so post-FX composites that
            // use SRC_ALPHA blending (blur, reflection) always write correctly.
            // On real Xbox NV2A hardware the framebuffer alpha is 1 after 3D
            // rendering; the game's motion-blur composite PS multiplies its
            // output alpha by backbuffer.a — so zero here makes it invisible.
            if (!isGuestRT) a = 1.0f;
            float clearColor[4] = { r, g, b, a };
            g_d3d11.context->ClearRenderTargetView(activeRTV, clearColor);
        }

        if ((flags & (X_D3DCLEAR_ZBUFFER | X_D3DCLEAR_STENCIL)) && activeDSV) {
            UINT dsFlags = 0;
            if (flags & X_D3DCLEAR_ZBUFFER) dsFlags |= D3D11_CLEAR_DEPTH;
            if (flags & X_D3DCLEAR_STENCIL) dsFlags |= D3D11_CLEAR_STENCIL;
            g_d3d11.context->ClearDepthStencilView(
                activeDSV, dsFlags, zVal, static_cast<UINT8>(stencil & 0xFF));
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
// When B3_DEBUG_RS=1 the stub logs the value it receives (deduped) so we can
// see which Xbox D3D render states the game is setting that we currently drop.
static bool RsDebug() {
    static int s_state = -1;
    if (s_state == -1) {
        const char* e = std::getenv("B3_DEBUG_RS");
        s_state = (e && *e && *e != '0') ? 1 : 0;
    }
    return s_state != 0;
}
static void RsDebugLogStub(const char* name, uint32_t value) {
    if (!RsDebug()) return;
    static std::unordered_map<std::string, uint32_t> s_seen;
    auto it = s_seen.find(name);
    if (it != s_seen.end() && it->second == value) return;
    s_seen[name] = value;
    fprintf(stderr, "[RS] DROP %-44s value=0x%08X (%u)\n", name, value, value);
}
#define DEFINE_SETRENDERSTATE_STUB_RET4(name) \
void name(X86Context& ctx, uint8_t* base) { \
    RsDebugLogStub(#name, GuestArg32(ctx, base, 0)); \
    GuestStackCleanup(ctx, 4); \
}

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
extern uint32_t g_psFinalCombinerConst[2];
static void ProcessNV2AMethod(uint32_t method, uint32_t value) {
    // Legitimate render-state calls are well-formed push-buffer header words:
    //   bits[31:18] = count == 1, bit[17] = 0 (incrementing), bits[15:13] = 0
    //   (subchannel 0) → the 0x0004xxxx family.
    // Anything outside that family (ASCII-text profiler labels, zero-count
    // NOPs, etc.) comes from debug/profiler init code that reuses the
    // SetRenderState_Simple path to write scratch data.  Silently discard.
    if ((method & 0xFFFC0000) != 0x00040000)
        return;

    bool handled = true;
    switch (method) {
        case NV2A_SET_ALPHA_TEST_ENABLE:       g_alphaTestEnabled  = (value != 0); break;
        case NV2A_SET_BLEND_ENABLE:            g_alphaBlendEnabled = (value != 0); break;
        case NV2A_SET_DITHER_ENABLE:           /* no D3D11 equivalent */            break;
        case NV2A_SET_STENCIL_TEST_ENABLE:     g_stencilTestEnable = (value != 0); break;
        case NV2A_SET_POLY_OFFSET_FILL_ENABLE: /* ignored */                        break;
        case NV2A_SET_ALPHA_FUNC:              g_alphaFunc = value;                 break;
        case NV2A_SET_ALPHA_REF:               g_alphaRef  = value;                 break;
        case NV2A_SET_BLEND_FUNC_SRC:          g_blendSrc  = value;                 break;
        case NV2A_SET_BLEND_FUNC_DST:          g_blendDst  = value;                 break;
        case NV2A_SET_BLEND_EQUATION:          g_blendEquation = value;             break;
        case NV2A_SET_DEPTH_FUNC:              g_depthFunc = value;                 break;
        case NV2A_SET_DEPTH_MASK:              g_depthWriteEnable = (value != 0);   break;
        case NV2A_SET_COLOR_MASK:              g_colorWriteMask = value;            break;
        case NV2A_SET_STENCIL_MASK:            g_stencilMask     = value;           break;
        case NV2A_SET_STENCIL_FUNC:            g_stencilFunc     = value;           break;
        case NV2A_SET_STENCIL_FUNC_REF:        g_stencilRef      = value;           break;
        case NV2A_SET_STENCIL_FUNC_MASK:       g_stencilFuncMask = value;           break;
        case NV2A_SET_STENCIL_OP_FAIL:         g_stencilOpFail   = value;           break;
        case NV2A_SET_STENCIL_OP_ZFAIL:        g_stencilOpZFail  = value;           break;
        case NV2A_SET_STENCIL_OP_ZPASS:        g_stencilOpZPass  = value;           break;
        // Methods present in B3 but with no meaningful D3D11 mapping:
        case 0x0004037C: // NV2A two-sided stencil (no D3D11 equivalent)
        case 0x0004034C: // NV097_SET_BLEND_COLOR (constant-color blend, unsupported)
        case 0x000409F8: // Unknown NV2A method
        case 0x00040384: // NV097_SET_POLYGON_OFFSET_SCALE_FACTOR (value always 0)
        case 0x00040388: // NV097_SET_POLYGON_OFFSET_BIAS (value always 0)
        case 0x00040330: // NV097_SET_POLY_OFFSET_POINT_ENABLE
        case 0x00040334: // NV097_SET_POLY_OFFSET_LINE_ENABLE
        case 0x00041D78: // NV097_SET_ZMIN_MAX_CONTROL
            /* ignored */
            break;
        default:
            static std::unordered_set<uint32_t> s_seenMethods;
            if (s_seenMethods.insert(method).second)
                printf("[NV2A] UNHANDLED method=0x%08X val=0x%08X\n", method, value);
            break;
    }
    if (handled && RsDebug()) {
        // Dedup: log each (method,value) pair only on first occurrence.
        static std::unordered_map<uint32_t, uint32_t> s_seen;
        auto it = s_seen.find(method);
        if (it == s_seen.end() || it->second != value) {
            s_seen[method] = value;
            fprintf(stderr, "[RS] NV2A SET method=0x%04X value=0x%08X\n",
                    method, value);
        }
    }
    if (!handled && RsDebug()) {
        // Combiner factor / texture-format methods are noisy and tracked
        // separately below; suppress them here.
        bool isCombFactor = (method >= 0x1A60 && method < 0x1AA0);
        if (!isCombFactor) {
            static std::unordered_map<uint32_t, uint32_t> s_seen;
            auto it = s_seen.find(method);
            if (it == s_seen.end() || it->second != value) {
                s_seen[method] = value;
                fprintf(stderr, "[RS] NV2A DROP method=0x%04X value=0x%08X\n",
                        method, value);
            }
        }
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
            // Log slot 2 always (it's fc0 for the tonemapper PSH 0x00900000).
            // Other slots: log first 8 occurrences each to avoid noise.
            static int s_logCount[16] = {};
            if (slot == 2 || s_logCount[slot] < 8) {
                ++s_logCount[slot];
                fprintf(stderr,
                    "[PSH] combiner factor slot=%u (method=0x%04X) value=0x%08X\n",
                    slot, method, value);
            }
        }
    }
    // NV097_SET_COMBINER_SPECULAR_FOG_CW0 (0x1E20) and CW1 (0x1E24): the
    // final-combiner constants. Map to psC[16]/psC[17] (consumed by
    // translated PS as fc0/fc1). B3 modulates these per-frame for car
    // reflection tint and specular weight; baking them at translate time
    // would freeze them on the first car's paint.
    if (method == 0x1E20) {
        g_psFinalCombinerConst[0] = value;
    } else if (method == 0x1E24) {
        g_psFinalCombinerConst[1] = value;
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

// Final-combiner constants (X_D3DRS_PSFINALCOMBINERCONSTANT0/1, RS 26/27).
// Values are 0xAARRGGBB. Refreshed on every captured write through:
//   * NV2A method NV097_SET_COMBINER_SPECULAR_FOG_CW0 (0x1E20) -> [0]
//   * NV097_SET_COMBINER_SPECULAR_FOG_CW1 (0x1E24)             -> [1]
//   * RS-shadow indices 26/27 (read at draw time as a fallback)
// Seeded from PSDef.bakedFc0/bakedFc1 at SetPixelShader handle switches so
// shaders that never override them still get their authored values.
uint32_t   g_psFinalCombinerConst[2] = {};

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

// Separate ring for recompiled code (sub_3DA90) that writes inline NV2A
// vertex data via CDevice.m_pPush at guest address 0 (since D3D_pDevice=0).
// Must NOT share the same base as the HLE ring so that HLE constant uploads
// and recompiled IM writes don't overwrite each other.
static uint32_t g_pbIMBase = 0;
static uint32_t g_pbIMSize = 0x10000; // 64 KB — plenty for one frame of IM writes
static uint32_t s_pbIMLastWalked = 0;

// Set to true only while WalkPushBuffer is called from D3DDevice_End so that
// inline vertex collection (SET_BEGIN_END, VERTEX2F_M, etc.) is active only
// for the IM ring, not for the shader-constant ring walked during 3D draws.
static bool g_pbWalkForIM = false;

static void EnsurePushBuffer(uint8_t* base) {
    if (g_pbGuestBase) return;
    g_pbGuestSize = 0x00800000; // 8 MiB
    g_pbGuestBase = ContigAlloc(g_pbGuestSize, 4096);
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    X86_MEM_WRITE_u32(base, 0x35D6A4u, g_pbGuestBase + g_pbGuestSize);
    s_pbLastWalked = g_pbGuestBase;
    fprintf(stderr, "[PB] HLE ring allocated base=0x%08X size=0x%X\n",
            g_pbGuestBase, g_pbGuestSize);
}

static void EnsureIMPushBuffer(uint8_t* base) {
    if (g_pbIMBase) return;
    g_pbIMBase = ContigAlloc(g_pbIMSize, 4096);
    // Write to CDevice.m_pPush/m_pLimit (addresses 0/4 since D3D_pDevice=0)
    // so recompiled sub_3DA90 uses this dedicated ring.
    X86_MEM_WRITE_u32(base, 0u, g_pbIMBase);
    X86_MEM_WRITE_u32(base, 4u, g_pbIMBase + g_pbIMSize);
    s_pbIMLastWalked = g_pbIMBase;
    fprintf(stderr, "[PB] IM ring allocated base=0x%08X size=0x%X\n",
            g_pbIMBase, g_pbIMSize);
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
static uint32_t g_texBoundSource[4] = {0}; // 0 = HLE SetTexture, 1 = NV2A Push Buffer
// NV2A viewport scale/translate (set via push buffer NV097_SET_VIEWPORT_SCALE/TRANSLATE).
// scale.y is the half-height in clip space, translate.y is the screen-space center Y.
// Used to reconstruct CB2D screenSize/Offset for post-FX draws that bypass SetViewport.
static float g_nv2aVpScaleX     = 0.0f;
static float g_nv2aVpScaleY     = 0.0f;
static float g_nv2aVpTranslateX = 0.0f;
static float g_nv2aVpTranslateY = 0.0f;

// NV2A inline vertex state — captured from push-buffer methods 0x18C4/0x18C8
// (TEXCOORD0_S/T), 0x18D0/0x18D4 (TEXCOORD1_S/T), and 0x1880 (VERTEX2F_M).
static void WalkPushBuffer(uint8_t* base) {
    // Walk the HLE shader-constant ring (0x35D6A0).
    uint32_t pbPut = X86_MEM_READ_u32(base, 0x35D6A0u);
    if (s_pbLastWalked == 0) { s_pbLastWalked = pbPut; }
    if (pbPut <  s_pbLastWalked) { s_pbLastWalked = pbPut; } // wrap
    // Walk the separate IM ring (addr 0, used by recompiled sub_3DA90).
    // Only do this when called from D3DDevice_End (g_pbWalkForIM=true).
    if (g_pbWalkForIM && g_pbIMBase) {
        uint32_t imPut = X86_MEM_READ_u32(base, 0u);
        if (s_pbIMLastWalked == 0) s_pbIMLastWalked = imPut;
        if (imPut != s_pbIMLastWalked && imPut >= s_pbIMLastWalked) {
            bool imInlineActive = false; // tracks BEGIN/END inside this walk
            static int s_probe = 0;
            if (s_probe < 20) {
                fprintf(stderr, "[PB] IM walk: put=0x%08X last=0x%08X range=%u\n",
                        imPut, s_pbIMLastWalked, imPut - s_pbIMLastWalked);
                s_probe++;
            }
            // Walk IM ring inline vertex data
            uint32_t ip = s_pbIMLastWalked;
            while (ip + 4 <= imPut) {
                uint32_t hdr = X86_MEM_READ_u32(base, ip);
                ip += 4;
                uint32_t count  = (hdr >> 18) & 0x7FF;
                uint32_t method = (hdr & 0x1FFC);
                if (count == 0 || ip + count * 4 > imPut) break;
                switch (method) {
                case 0x17FC: { // SET_BEGIN_END
                    uint32_t prim = X86_MEM_READ_u32(base, ip);
                    if (prim == 0) {
                        imInlineActive = false;
                    } else {
                        imInlineActive = true;
                        if (!g_imActive) {
                            g_imActive = true;
                            g_imPrimType = (int)prim;
                            g_imCurrent = {};
                            g_imCurrent.diffuse = 0xFFFFFFFF;
                            g_imCurrent.w = 1.0f;
                        }
                    }
                    break;
                }
                case 0x18C4: // TEXCOORD0_2F_S — U
                    if (count >= 1) {
                        uint32_t b = X86_MEM_READ_u32(base, ip);
                        memcpy(&g_imCurrent.u, &b, 4);
                        if (count >= 2) { b = X86_MEM_READ_u32(base, ip+4); memcpy(&g_imCurrent.v, &b, 4); }
                    }
                    break;
                case 0x18C8: // TEXCOORD0_2F_T — data[0]=horiz(U), data[1]=vert(V)
                    if (count >= 1) {
                        uint32_t b = X86_MEM_READ_u32(base, ip);
                        memcpy(&g_imCurrent.u, &b, 4);
                        if (count >= 2) { b = X86_MEM_READ_u32(base, ip+4); memcpy(&g_imCurrent.v, &b, 4); }
                    }
                    break;
                case 0x1880: // VERTEX2F_M — X,Y: emit vertex
                    if (count >= 2 && imInlineActive) {
                        uint32_t xb = X86_MEM_READ_u32(base, ip);
                        uint32_t yb = X86_MEM_READ_u32(base, ip+4);
                        memcpy(&g_imCurrent.x, &xb, 4);
                        memcpy(&g_imCurrent.y, &yb, 4);
                        g_imVertices.push_back(g_imCurrent);
                    }
                    break;
                default: break;
                }
                ip += count * 4;
            }
            s_pbIMLastWalked = imPut;
        }
    }
    // Now continue with the HLE ring walk below.
    if (pbPut == s_pbLastWalked) return;

    uint32_t p = s_pbLastWalked;
    uint32_t end = pbPut;
    uint32_t curConstAddr = 0;

    while (p + 4 <= end) {
        uint32_t hdr = X86_MEM_READ_u32(base, p);
        p += 4; // advance past header; all data reads below use p for first payload DWORD
        uint32_t instr  = (hdr >> 29) & 0x7;
        uint32_t count  = (hdr >> 18) & 0x7FF;
        // uint32_t sub = (hdr >> 13) & 0x7;
        uint32_t method = (hdr & 0x1FFC); // bits 2..12

        // Skip jmp/call (not used by SDK fast paths but be safe).
        if (instr == 1 /*JMP_NEAR*/ || instr == 2 /*CALL_FAR*/) continue;

        if (count == 0) continue;
        if (p + count * 4 > end + 4) break; // +4: p already past header

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
        case 0x09CC: // NV097_SET_VIEWPORT_SCALE_X
            if (count >= 1) g_nv2aVpScaleX = std::bit_cast<float>(X86_MEM_READ_u32(base, p));
            if (count >= 2) g_nv2aVpScaleY = std::bit_cast<float>(X86_MEM_READ_u32(base, p + 4));
            break;
        case 0x09D0: // NV097_SET_VIEWPORT_SCALE_Y
            if (count >= 1) g_nv2aVpScaleY = std::bit_cast<float>(X86_MEM_READ_u32(base, p));
            break;
        case 0x0AF0: // NV097_SET_VIEWPORT_TRANSLATE_X
            if (count >= 1) g_nv2aVpTranslateX = std::bit_cast<float>(X86_MEM_READ_u32(base, p));
            if (count >= 2) g_nv2aVpTranslateY = std::bit_cast<float>(X86_MEM_READ_u32(base, p + 4));
            break;
        case 0x0AF4: // NV097_SET_VIEWPORT_TRANSLATE_Y
            if (count >= 1) g_nv2aVpTranslateY = std::bit_cast<float>(X86_MEM_READ_u32(base, p));
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
                        case 0x00: 
                            g_nv2aTexture[stage].offset = val; 
                            g_nv2aTexture[stage].dirty = true; 
                            g_texBoundSource[stage] = 1; // SRC_NV2A
                            break;
                        case 0x04: {
                            g_nv2aTexture[stage].format = val;
                            g_nv2aTexture[stage].dirty = true;
                            static std::unordered_set<uint64_t> s_seenNvFmt;
                            uint64_t k = ((uint64_t)stage << 32) | val;
                            if (s_seenNvFmt.insert(k).second && s_seenNvFmt.size() <= 64) {
                                fprintf(stderr, "[NV2A pb] stage=%u SET_TEXTURE_FORMAT=0x%08X "
                                                "(lowBits=0x%02X cube=%d dim=%u fmt=0x%02X)\n",
                                        stage, val, val & 0xFFu,
                                        (int)((val & 0x04u) != 0),
                                        (val >> 4) & 0xFu,
                                        (val >> 8) & 0xFFu);
                            }
                            break;
                        }
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
//
// PERF: this scans 768 floats and was called once per draw. Cache the
// answer per frame (keyed off g_swapCount) — constants only get *added*
// during a frame, so once we've seen non-zero data the result stays true
// for the rest of that frame, and a `false` result is rechecked on the
// next frame anyway. Cuts ~6% off main-thread CPU in busy 3D scenes.
extern int g_swapCount;
static bool HasMvpConstants(uint8_t* base) {
    static int  s_cachedFrame = -1;
    static bool s_cachedValue = false;
    if (s_cachedFrame == g_swapCount && s_cachedValue) return true;
    for (uint32_t r = 0; r < 192; r++) {
        const float* hs = g_vshConstants[r];
        const float* sh = reinterpret_cast<const float*>(
            base + kVshConstantShadow + r * 16);
        for (int k = 0; k < 4; k++) {
            if (std::isfinite(hs[k]) && hs[k] != 0.0f) {
                s_cachedFrame = g_swapCount; s_cachedValue = true; return true;
            }
            if (std::isfinite(sh[k]) && sh[k] != 0.0f) {
                s_cachedFrame = g_swapCount; s_cachedValue = true; return true;
            }
        }
    }
    s_cachedFrame = g_swapCount; s_cachedValue = false;
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
    // A draw is "3D" if the live handle has a translated programmable VS
    // in our cache. Synthetic handles (0xFFFE00xx) created by
    // D3DDevice_CreateVertexShader are NOT distinguishable from FVF codes
    // by any bit pattern (both have bit 0 = 0), so we must look them up.
    bool hasProgVS = (liveVS != 0) && (g_vsByHandle.find(liveVS) != g_vsByHandle.end());
    if (hasProgVS && g_d3d11.vs3D && HasMvpConstants(base)) {
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
    {
        const char* why =
            !hasProgVS             ? "no-prog-VS" :
            !g_d3d11.vs3D          ? "no-vs3D"    :
            !HasMvpConstants(base) ? "no-MVP"     : "?";
        static std::unordered_map<uint64_t,int> s_fbCount;
        uint64_t key = ((uint64_t)liveVS << 32) | (uint32_t)why[0];
        int& c = s_fbCount[key];
        if (c < 8) {
            fprintf(stderr,
                "[HLE] Draw FALLBACK->2D reason=%s liveVS=0x%08X "
                "prim=%u start=%u count=%u stride=%u vb=0x%X tex=0x%X\n",
                why, liveVS, primType, startVert, vertCount, stride, vbAddr,
                X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00));
            ++c;
        }
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

    if (reg == X_D3DVSDE_TEXCOORD0) {
        // Only track texcoord0 (reg 9).  sub_3DA90 also calls
        // SetVertexData2f(10, ...) for texcoord1, which must NOT overwrite
        // the texcoord0 U/V we just captured.
        g_imCurrent.u = fx;
        g_imCurrent.v = fy;
    } else if (reg == X_D3DVSDE_POSITION || reg == (int)X_D3DVSDE_VERTEX) {
        // sub_3DA90's v3=true path interleaves inline NV2A texcoord writes to
        // the push buffer with SetVertexData2f(POSITION) calls.  Walk the IM
        // ring right now so those texcoords update g_imCurrent before we push.
        if (g_pbIMBase) {
            g_pbWalkForIM = true;
            WalkPushBuffer(base);
            g_pbWalkForIM = false;
        }
        if (!g_imActive) {
            g_imActive   = true;
            g_imPrimType = NV2A_PRIM_QUADS;
        }
        g_imCurrent.x = fx;
        g_imCurrent.y = fy;
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
    } else if (reg == (uint32_t)X_D3DVSDE_TEXCOORD0) {
        // Only texcoord0; TEXCOORD1 must not overwrite the captured U/V.
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
    // Walk the IM ring (sub_3DA90's inline NV2A vertex writes).
    // g_pbWalkForIM gates vertex capture so the HLE ring walker (called
    // during 3D draws) never accidentally activates IM mode.
    EnsureIMPushBuffer(base);
    g_pbWalkForIM = true;
    WalkPushBuffer(base);
    g_pbWalkForIM = false;

    if (!g_imVertices.empty()) {
        static int s_endLog = 0;
        if (s_endLog < 200) {
            uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
            uint32_t rtSurf  = g_d3d11.currentRTSurf;
            uint32_t nv0off  = g_nv2aTexture[0].offset;
            fprintf(stderr, "[HLE] End f=%u d=%u: %zu verts prim=%d tex=0x%08X src=%d nv0=0x%08X RT=0x%08X",
                    g_ppFrame, g_drawCallCount, g_imVertices.size(), g_imPrimType,
                    texAddr, g_texBoundSource[0], nv0off, rtSurf);
            if (!g_imVertices.empty()) {
                auto& v0 = g_imVertices[0];
                fprintf(stderr, " v0=(%.1f,%.1f uv=%.3f,%.3f)", v0.x, v0.y, v0.u, v0.v);
            }
            fprintf(stderr, "\n");
            s_endLog++;
        }
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
                SetD3DName(entry.vs, "B3_VS_%08X_func_%08X", newHandle, pFunc);
                SetD3DName(entry.il, "B3_IL_%08X_stride%u", newHandle, entry.vertexStride);
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
    
    uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
    if (cdev != 0) {
        cdev &= 0x3FFFFFFFu;
        X86_MEM_WRITE_u32(base, cdev + 0x798u, handle);
    }
    
    // Invalidate Burnout 3's custom VS cache so it doesn't skip future binds
    X86_MEM_WRITE_u32(base, 0x41AAB8, 0xFFFFFFFF);

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
    // Baked final-combiner constants (X_D3DRS_PSFINALCOMBINERCONSTANT0/1).
    // The translated PS reads them from psC[16]/[17] which are refreshed
    // each draw from the live runtime shadow (g_psFinalCombinerConstant
    // below). Seeded here so a shader that never overrides them at
    // runtime still sees the values it was authored with.
    uint32_t bakedFc0 = 0;
    uint32_t bakedFc1 = 0;
};
static std::unordered_map<uint32_t /*guestPsDefAddr*/, TranslatedPS> g_psByHandle;
uint32_t g_currentPSHandle = 0;
// Snapshot of texture handles bound at D3DDevice_SetPixelShader time.
// The Xbox GPU retains its last-programmed texture-offset register even when
// the CPU-side cache is later cleared by SetTexture(NULL). We mirror that by
// using these values as fallback when the live HLE slot is zero.
static uint32_t g_psTexHandleSnapshot[4] = {};

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
// This mirrors CreatePixelShader's "copy PSDef constants into render-state
// bank" behaviour for shaders that rely on their baked defaults (e.g. B3
// car-body PS uses c0=(1,1,1,1) as a paint-passthrough factor and never
// explicitly SetPixelShaderConstant's it). Without the re-seed, leftover
// values from a previously-bound shader (e.g. ground-overlay tint
// ~0.3,0.3,0.3,0.5) leak in and darken/fade the car paint.
static void ReseedPSConstantsFromBaked(const TranslatedPS& entry)
{
    auto unpackArgb = [](uint32_t argb, float out[4]) {
        out[0] = ((argb >> 16) & 0xFF) / 255.0f;
        out[1] = ((argb >>  8) & 0xFF) / 255.0f;
        out[2] = ((argb >>  0) & 0xFF) / 255.0f;
        out[3] = ((argb >> 24) & 0xFF) / 255.0f;
    };
    for (int i = 0; i < 8; ++i) unpackArgb(entry.bakedC0[i], g_pshConstants[i]);
    for (int i = 0; i < 8; ++i) unpackArgb(entry.bakedC1[i], g_pshConstants[8 + i]);
    g_pshConstantsDirty = 0;
    // Seed final-combiner constants from PSDef defaults. Runtime writes via
    // NV097_SET_COMBINER_SPECULAR_FOG_CW0/1 (or RS 26/27) will override.
    g_psFinalCombinerConst[0] = entry.bakedFc0;
    g_psFinalCombinerConst[1] = entry.bakedFc1;
}


void D3DDevice_CreatePixelShader(X86Context& ctx, uint8_t* base)
{
    uint32_t pPSDef = GuestArg32(ctx, base, 0);
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
                SetD3DName(entry.ps, "B3_PS_psDef_%08X", pPSDef);
            }
            for (int s = 0; s < 4; ++s) {
                entry.usesStage[s] = tr.usesStage[s];
                entry.samplesStage[s] = tr.samplesStage[s];
            }
            entry.numCombiners = tr.numCombiners;
            entry.hlsl = tr.hlsl;
            for (int i = 0; i < 8; ++i) entry.bakedC0[i] = tr.bakedC0[i];
            for (int i = 0; i < 8; ++i) entry.bakedC1[i] = tr.bakedC1[i];
            entry.bakedFc0 = tr.bakedFc0;
            entry.bakedFc1 = tr.bakedFc1;
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
            // Dump HLSL for offline inspection. Default: first 8 unique
            // shaders. With B3_DUMP_PS=1, dump every unique PS into
            // ./ps_dump/PS_<addr>.hlsl (the directory must exist).
            static int s_dumpCount = 0;
            static int s_dumpAll = -1;
            if (s_dumpAll < 0) {
                const char* e = std::getenv("B3_DUMP_PS");
                s_dumpAll = (e && *e && *e != '0') ? 1 : 0;
            }
            if (tr.ok && (s_dumpAll || s_dumpCount < 8)) {
                char fname[96];
                if (s_dumpAll)
                    std::snprintf(fname, sizeof(fname), "ps_dump/PS_%08X.hlsl", pPSDef);
                else
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
    uint32_t prevHandle = g_currentPSHandle;
    g_currentPSHandle = handle;
    
    // Invalidate Burnout 3's custom PS cache
    X86_MEM_WRITE_u32(base, 0x41AABC, 0xFFFFFFFF);

    // Snapshot the four texture handles currently bound. On real Xbox the GPU
    // keeps the last-written texture registers even when D3DDevice_SetTexture
    // is later called with NULL; this snapshot lets BindTranslatedPSFor2D
    // fall back to them if the live slot has been cleared.
    if (handle != 0 && base) {
        for (uint32_t s = 0; s < 4; ++s)
            g_psTexHandleSnapshot[s] = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + s * 4);
    }
    if (handle == 0x00900000 || handle == 0x00901000) {
        static int s_setPS[2] = {};
        int slot = (handle == 0x00900000) ? 0 : 1;
        if (s_setPS[slot]++ < 4) {
            uint32_t hlT0 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
            uint32_t hlT1 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B04);
            uint32_t hlT2 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B08);
            uint32_t hlT3 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B0C);
            fprintf(stderr,
                "[PS-SET] PS=0x%08X prev=0x%08X hlT=[0x%08X,0x%08X,0x%08X,0x%08X]\n",
                handle, prevHandle, hlT0, hlT1, hlT2, hlT3);
        }
    }
    if (handle == 0x00900000) {
        static int s_set900 = 0;
        if (s_set900++ < 16) {
            uint32_t retAddr = X86_MEM_READ_u32(base, ctx.esp);
            uint32_t hlT0 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
            uint32_t hlT1 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B04);
            uint32_t hlT2 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B08);
            uint32_t hlT3 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B0C);
            fprintf(stderr,
                "[PS900-SET] #%d ret=0x%08X prev=0x%08X hlT=[0x%08X,0x%08X,0x%08X,0x%08X]\n",
                s_set900, retAddr, prevHandle, hlT0, hlT1, hlT2, hlT3);
        }
    }
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
                const bool isReflPS = (handle == 0x008F9000) ||
                    (handle == 0x008FD000) ||
                    (handle == 0x008FF000);
                if (ID3DBlob* blob = D3D11CompileShader(tr.hlsl.c_str(), "main", "ps_5_0")) {
                    HRESULT hr = g_d3d11.device->CreatePixelShader(
                        blob->GetBufferPointer(), blob->GetBufferSize(),
                        nullptr, &entry.ps);
                    blob->Release();
                    if (FAILED(hr)) entry.ps = nullptr;
                    SetD3DName(entry.ps, "B3_PS_%08X_psDef_%08X", handle, psDefAddr);
                }
                for (int s = 0; s < 4; ++s) {
                    entry.usesStage[s] = tr.usesStage[s];
                    entry.samplesStage[s] = tr.samplesStage[s];
                }
                entry.numCombiners = tr.numCombiners;
                entry.hlsl = tr.hlsl;
                for (int i = 0; i < 8; ++i) entry.bakedC0[i] = tr.bakedC0[i];
                for (int i = 0; i < 8; ++i) entry.bakedC1[i] = tr.bakedC1[i];
            }
            SeedPSConstantsFromBaked(entry);
            fprintf(stderr, "[PSH] h=0x%08X psDefOff=%u combiners=%u compiled=%s usesStage=%d%d%d%d HLSL_len=%zu\n",
                handle, (psDefAddr - handle), tr.numCombiners,
                entry.ps ? "OK" : "FAIL",
                (int)entry.usesStage[0], (int)entry.usesStage[1],
                (int)entry.usesStage[2], (int)entry.usesStage[3],
                entry.hlsl.size());
            // Dump HLSL for blur PSes to aid debugging.
            if (handle == 0x00900000u || handle == 0x00901000u) {
                char fname[64];
                snprintf(fname, sizeof(fname), "blur_ps_%08X.hlsl", handle);
                if (FILE* f = fopen(fname, "w")) {
                    fwrite(entry.hlsl.c_str(), 1, entry.hlsl.size(), f);
                    fclose(f);
                    fprintf(stderr, "[PSH] Dumped HLSL to %s\n", fname);
                }
            }
            g_psByHandle.emplace(handle, std::move(entry));
        }
        else {
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
    // On every handle switch, re-seed the PS constant bank with the newly-
    // bound shader's baked PSConstant0/1 defaults. Without this, constants
    // that the previous shader uploaded (and marked dirty) persist and leak
    // into the new shader's stages — e.g. the ground-overlay PS leaves a
    // dark semi-transparent tint in c0 that then darkens the car body.
    if (handle != prevHandle && handle != 0) {
        auto it = g_psByHandle.find(handle);
        if (it != g_psByHandle.end() && it->second.ps) {
            ReseedPSConstantsFromBaked(it->second);
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
    EnsureIMPushBuffer(base);
    WalkPushBuffer(base);
    // Reset HLE ring
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    s_pbLastWalked = g_pbGuestBase;
    // Reset IM ring
    X86_MEM_WRITE_u32(base, 0u, g_pbIMBase);
    X86_MEM_WRITE_u32(base, 4u, g_pbIMBase + g_pbIMSize);
    s_pbIMLastWalked = g_pbIMBase;
    // Return the IM ring base — recompiled code (sub_3DA90/sub_402C0) uses
    // the return value as its push-buffer write pointer.  Returning
    // g_pbIMBase keeps all their writes inside the IM ring so that
    // WalkPushBuffer can find them; the HLE ring is only used by the
    // HLE shader-constant walker which tracks 0x35D6A0 independently.
    ctx.eax = g_pbIMBase;
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_MakeSpace  (0x9C870) — 0 args, plain ret
void D3DDevice_MakeSpace(X86Context& ctx, uint8_t* base)
{
    EnsurePushBuffer(base);
    EnsureIMPushBuffer(base);
    WalkPushBuffer(base);
    // Reset HLE ring
    X86_MEM_WRITE_u32(base, 0x35D6A0u, g_pbGuestBase);
    s_pbLastWalked = g_pbGuestBase;
    // Reset IM ring
    X86_MEM_WRITE_u32(base, 0u, g_pbIMBase);
    X86_MEM_WRITE_u32(base, 4u, g_pbIMBase + g_pbIMSize);
    s_pbIMLastWalked = g_pbIMBase;
    ctx.eax = g_pbIMBase; // same reasoning as D3D_MakeRequestedSpace
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

// D3DResource_IsBusy  (0x34C970) — 0 stack args, thiscall (ECX = X_D3DResource*)
//
// Returns TRUE if the GPU is still consuming the resource (i.e. the fence
// stored in Common & X_D3DCOMMON_BUSYSIGNALS_MASK has not yet been retired).
// Our HLE has no async GPU pipeline — every draw completes synchronously
// before the guest code continues — so resources are never busy.  Return 0
// (FALSE) unconditionally, matching Cxbx-Reloaded D3DResource_IsBusy.
void D3DResource_IsBusy(X86Context& ctx, uint8_t* base) {
    GuestReturn32(ctx, 0); // FALSE: never busy
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

    // Mirror the RT into the Xbox SDK's own field (same fix as SetRenderTarget).
    {
        uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
        X86_MEM_WRITE_u32(base, cdev + 0x1A04, pRT);
        // No DS arg in Fast variant; write 0 to keep the DS field consistent.
        X86_MEM_WRITE_u32(base, cdev + 0x1A08, 0);
    }
    X86_MEM_WRITE_u32(base, kDeviceAddr + 0x1A04, pRT);
    X86_MEM_WRITE_u32(base, kDeviceAddr + kDeviceRenderTarget, pRT);

    g_d3d11.currentRTSurf = pRT;

    if (PpDebug()) {
        uint32_t pParent = pRT ? X86_MEM_READ_u32(base, pRT + 0x14) : 0;
        bool inMap = g_d3d11.guestRTBySurface.count(pRT) != 0;
        fprintf(stderr, "[PP] f=%u SetRTFast rt=0x%08X parent=0x%08X inMap=%d (prev=0x%08X had %u draws)\n",
                g_ppFrame, pRT, pParent, (int)inMap, g_ppPrevRT, g_ppDrawsSinceRT);
        g_ppPrevRT = pRT;
        g_ppDrawsSinceRT = 0;
    }

    GuestStackCleanup(ctx, 4);
}

// ----------------------------------------------------------------------------
// D3DDevice_CopyRects (0x0034D060) — Xbox D3D8 form, 5 args, ret 20 bytes:
//   void CopyRects(IDirect3DSurface8* pSrcSurf, const RECT* pSrcRects,
//                  UINT cRects, IDirect3DSurface8* pDstSurf,
//                  const POINT* pDstPoints);
//
// Burnout 3 uses this every frame to capture the back buffer into an
// offscreen texture for bloom / motion-blur source / lens-flare and to
// resolve auxiliary RTs into sample-able textures. Without it post-FX have
// nothing to sample and the engine falls back to the (zeroed) destination
// texture's initial allocation — so reflections look black, bloom is absent,
// motion blur ghosting is absent, etc.
// ----------------------------------------------------------------------------

namespace {

struct CopyRectsResource {
    ID3D11Texture2D* tex         = nullptr;
    UINT             subresource = 0;
    UINT             width       = 0;
    UINT             height      = 0;
    DXGI_FORMAT      format      = DXGI_FORMAT_UNKNOWN;
    bool             isDepth     = false;
};

// Returns true if surfAddr is one of the back-buffer surface addresses the
// engine published into kDeviceBackBufBase[0..3].
bool IsBackBufferSurface(uint8_t* base, uint32_t surfAddr)
{
    if (surfAddr == 0) return false;
    for (int i = 0; i < 4; ++i) {
        uint32_t bb = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase + i * 4);
        if (bb != 0 && bb == surfAddr) return true;
    }
    return false;
}

bool IsDepthStencilSurface(uint8_t* base, uint32_t surfAddr)
{
    if (surfAddr == 0) return false;
    uint32_t ds = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceDepthStencil);
    return surfAddr == ds;
}

// Resolve a guest surface address to the D3D11 resource backing it.
// `forWrite` selects between the SRV and RTV/DSV path: when writing we may
// need to lazily promote a regular guest texture into a GuestRT.
bool ResolveCopyRectsResource(uint8_t* base, uint32_t surfAddr, bool forWrite,
                              CopyRectsResource& out)
{
    if (surfAddr == 0) return false;

    // Back buffer (scene tex, full-mip-0 single-sub, RT+SR bindable).
    if (IsBackBufferSurface(base, surfAddr)) {
        if (!g_d3d11.backBufferTex) return false;
        D3D11_TEXTURE2D_DESC td;
        g_d3d11.backBufferTex->GetDesc(&td);
        out.tex         = g_d3d11.backBufferTex;
        out.subresource = 0;
        out.width       = td.Width;
        out.height      = td.Height;
        out.format      = td.Format;
        return true;
    }

    // Depth surface (sourcable via TYPELESS+DSV+SRV scene depth).
    if (IsDepthStencilSurface(base, surfAddr)) {
        if (!g_d3d11.depthTex) return false;
        D3D11_TEXTURE2D_DESC td;
        g_d3d11.depthTex->GetDesc(&td);
        out.tex         = g_d3d11.depthTex;
        out.subresource = 0;
        out.width       = td.Width;
        out.height      = td.Height;
        out.format      = td.Format;
        out.isDepth     = true;
        return true;
    }

    // Guest render-to-texture surface (mip-of-parent).
    auto its = g_d3d11.guestRTBySurface.find(surfAddr);
    if (its != g_d3d11.guestRTBySurface.end()) {
        GuestRT* rt = its->second.rt;
        if (!rt) {
            uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
            if (pParent != 0) rt = EnsureGuestRT(base, pParent);
            if (rt) its->second.rt = rt;
        }
        if (rt && rt->texture) {
            uint32_t mip = GetMipFromSurface(base, surfAddr, rt);
            its->second.mip = mip;
            uint32_t w = std::max<uint32_t>(1, rt->baseW >> mip);
            uint32_t h = std::max<uint32_t>(1, rt->baseH >> mip);
            out.tex         = rt->texture;
            out.subresource = D3D11CalcSubresource(mip, 0, rt->mipCount);
            out.width       = w;
            out.height      = h;
            out.format      = rt->dxgiFormat;
            return true;
        }
    }

    // Last resort: surface points at a regular guest texture / image surface.
    uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
    if (pParent != 0) {
        if (GuestRT* rt = EnsureGuestRT(base, pParent)) {
            uint32_t mip = GetMipFromSurface(base, surfAddr, rt);
            SurfaceRTBind b{}; b.rt = rt; b.mip = mip; b.parent = pParent;
            g_d3d11.guestRTBySurface[surfAddr] = b;
            uint32_t w = std::max<uint32_t>(1, rt->baseW >> mip);
            uint32_t h = std::max<uint32_t>(1, rt->baseH >> mip);
            out.tex         = rt->texture;
            out.subresource = D3D11CalcSubresource(mip, 0, rt->mipCount);
            out.width       = w;
            out.height      = h;
            out.format      = rt->dxgiFormat;
            return true;
        }
    }

    (void)forWrite;
    return false;
}

} // anonymous namespace

void D3DDevice_CopyRects(X86Context& ctx, uint8_t* base)
{
    uint32_t pSrcSurf   = GuestArg32(ctx, base, 0);
    uint32_t pSrcRects  = GuestArg32(ctx, base, 1);
    uint32_t cRects     = GuestArg32(ctx, base, 2);
    uint32_t pDstSurf   = GuestArg32(ctx, base, 3);
    uint32_t pDstPoints = GuestArg32(ctx, base, 4);

    auto cleanup = [&]() { GuestStackCleanup(ctx, 20); };

    if (!g_d3d11.initialized || !g_d3d11.context) { cleanup(); return; }
    if (pSrcSurf == 0 || pDstSurf == 0)            { cleanup(); return; }

    CopyRectsResource src{}, dst{};
    if (!ResolveCopyRectsResource(base, pSrcSurf, /*forWrite*/false, src) ||
        !ResolveCopyRectsResource(base, pDstSurf, /*forWrite*/true,  dst))
    {
        static int s_unresolved = 0;
        if (s_unresolved++ < 8) {
            fprintf(stderr,
                "[HLE] CopyRects unresolved: src=0x%08X dst=0x%08X (count=%u)\n",
                pSrcSurf, pDstSurf, cRects);
        }
        cleanup();
        return;
    }

    // Format compatibility: CopySubresourceRegion requires identical (or in
    // some cases bit-compatible) formats. Bail rather than corrupt memory.
    if (src.format != dst.format && !(src.isDepth && dst.isDepth)) {
        static int s_fmtmiss = 0;
        if (s_fmtmiss++ < 8) {
            fprintf(stderr,
                "[HLE] CopyRects format mismatch: src=%d dst=%d\n",
                (int)src.format, (int)dst.format);
        }
        cleanup();
        return;
    }

    if (cRects == 0 || pSrcRects == 0) {
        // Whole-surface copy.
        UINT w = std::min(src.width,  dst.width);
        UINT h = std::min(src.height, dst.height);
        D3D11_BOX box = { 0, 0, 0, w, h, 1 };
        UINT dstX = 0, dstY = 0;
        if (pDstPoints != 0) {
            dstX = (UINT)X86_MEM_READ_u32(base, pDstPoints + 0);
            dstY = (UINT)X86_MEM_READ_u32(base, pDstPoints + 4);
        }
        g_d3d11.context->CopySubresourceRegion(
            dst.tex, dst.subresource, dstX, dstY, 0,
            src.tex, src.subresource, &box);
    } else {
        for (uint32_t i = 0; i < cRects; ++i) {
            uint32_t rectAddr = pSrcRects + i * 16; // RECT = 4 LONGs
            int32_t  l = (int32_t)X86_MEM_READ_u32(base, rectAddr + 0);
            int32_t  t = (int32_t)X86_MEM_READ_u32(base, rectAddr + 4);
            int32_t  r = (int32_t)X86_MEM_READ_u32(base, rectAddr + 8);
            int32_t  b = (int32_t)X86_MEM_READ_u32(base, rectAddr + 12);
            if (l < 0) l = 0; if (t < 0) t = 0;
            if (r > (int32_t)src.width)  r = (int32_t)src.width;
            if (b > (int32_t)src.height) b = (int32_t)src.height;
            if (r <= l || b <= t) continue;

            UINT dstX = (UINT)l, dstY = (UINT)t;
            if (pDstPoints != 0) {
                uint32_t ptAddr = pDstPoints + i * 8; // POINT = 2 LONGs
                dstX = (UINT)X86_MEM_READ_u32(base, ptAddr + 0);
                dstY = (UINT)X86_MEM_READ_u32(base, ptAddr + 4);
            }
            // Clip destination so we never write past the dest surface.
            int32_t copyW = r - l;
            int32_t copyH = b - t;
            if ((int32_t)dstX + copyW > (int32_t)dst.width)
                copyW = (int32_t)dst.width  - (int32_t)dstX;
            if ((int32_t)dstY + copyH > (int32_t)dst.height)
                copyH = (int32_t)dst.height - (int32_t)dstY;
            if (copyW <= 0 || copyH <= 0) continue;

            D3D11_BOX box = {
                (UINT)l, (UINT)t, 0,
                (UINT)(l + copyW), (UINT)(t + copyH), 1
            };
            g_d3d11.context->CopySubresourceRegion(
                dst.tex, dst.subresource, dstX, dstY, 0,
                src.tex, src.subresource, &box);
        }
    }

    static int s_logged = 0;
    if (s_logged++ < 4) {
        fprintf(stderr,
            "[HLE] CopyRects ok: src=0x%08X(%ux%u) -> dst=0x%08X(%ux%u) cRects=%u%s\n",
            pSrcSurf, src.width, src.height,
            pDstSurf, dst.width, dst.height,
            cRects, src.isDepth ? " [depth]" : "");
    }

    cleanup();
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
    uint32_t regStart = 0;
    uint32_t count = 0;
    uint32_t pData = 0;
    
    // Grab typical registers and stack args
    uint32_t arg0 = GuestArg32(ctx, base, 0);
    uint32_t arg1 = GuestArg32(ctx, base, 1);
    uint32_t arg2 = GuestArg32(ctx, base, 2);

    // Pattern 1: LTCG fastcall (ECX=Reg, EAX=Count, Stack0=pData)
    if (ctx.ecx < 16 && ctx.eax > 0 && ctx.eax <= 16 && arg0 >= 0x10000) {
        regStart = ctx.ecx;
        count = ctx.eax;
        pData = arg0;
        GuestStackCleanup(ctx, 4);
    } 
    // Pattern 2: __fastcall (ECX=Reg, EDX=pData, Stack0=Count)
    else if (ctx.ecx < 16 && ctx.edx >= 0x10000 && arg0 > 0 && arg0 <= 16) {
        regStart = ctx.ecx;
        pData = ctx.edx;
        count = arg0;
        GuestStackCleanup(ctx, 4);
    }
    // Pattern 3: stdcall (Register, pData, Count)
    else if (arg0 < 16 && arg1 >= 0x10000 && arg2 > 0 && arg2 <= 16) {
        regStart = arg0;
        pData = arg1;
        count = arg2;
        GuestStackCleanup(ctx, 12);
    }
    // Pattern 4: IDA scrambled stdcall (Register, Count, pData)
    else if (arg0 < 16 && arg2 >= 0x10000 && arg1 > 0 && arg1 <= 16) {
        regStart = arg0;
        count = arg1;
        pData = arg2;
        GuestStackCleanup(ctx, 12);
    }
    // Pattern 5: IDA scrambled stdcall (Count, Register, pData) -> FIXES BLOOM
    else if (arg0 > 0 && arg0 <= 16 && arg1 < 16 && arg2 >= 0x10000) {
        count = arg0;
        regStart = arg1;
        pData = arg2;
        GuestStackCleanup(ctx, 12);
    }
    // Pattern 6: IDA scrambled stdcall (Register, 0, pData) -> Assume Count = 1
    else if (arg0 < 16 && arg2 >= 0x10000 && arg1 == 0) {
        regStart = arg0;
        count = 1;
        pData = arg2;
        GuestStackCleanup(ctx, 12);
    }
    // Pattern 7: __fastcall without count (ECX=Reg, EDX=pData) -> Assume Count = 1
    else if (ctx.ecx < 16 && ctx.edx >= 0x10000) {
        regStart = ctx.ecx;
        pData = ctx.edx;
        count = 1;
        GuestStackCleanup(ctx, 0); 
    }
    // Pattern 8: __fastcall with EAX=pData
    else if (ctx.ecx < 16 && ctx.eax >= 0x10000) {
        regStart = ctx.ecx;
        pData = ctx.eax;
        count = 1;
        GuestStackCleanup(ctx, 0);
    }
    // Pattern 9: fastcall (ECX=Reg, EDX=Count, Stack0=pData) with Count=0
    else if (ctx.ecx < 16 && arg0 >= 0x10000 && ctx.edx == 0) {
        regStart = ctx.ecx;
        count = 1;
        pData = arg0;
        GuestStackCleanup(ctx, 4);
    }
    else {
        // Fallback: Avoid crashing 
        GuestStackCleanup(ctx, 12);
        return;
    }

    if (pData != 0 && count > 0 && regStart < 16) {
        uint32_t copyCount = std::min<uint32_t>(count, 16 - regStart);
        memcpy(&g_pshConstants[regStart][0], base + pData, copyCount * 16);
        for (uint32_t i = 0; i < copyCount; ++i)
            g_pshConstantsDirty |= (1u << (regStart + i));
    }
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
    g_currentVSHandle = 0;
    g_currentPSHandle = 0;

    uint32_t cdev = X86_MEM_READ_u32(base, 0x35FB48u);
    if (cdev != 0) {
        cdev &= 0x3FFFFFFFu;
        X86_MEM_WRITE_u32(base, cdev + 0x798u, 0);
    }
    
    // Invalidate Burnout 3's custom VS cache
    X86_MEM_WRITE_u32(base, 0x41AAB8, 0xFFFFFFFF);
    X86_MEM_WRITE_u32(base, 0x41AABC, 0xFFFFFFFF);
    
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
    SampleDebugFlagsOnce();
    if (pData == 0 || count4s == 0) return;
    const float* src = reinterpret_cast<const float*>(base + pData);
    uint32_t dstMax  = (reg + count4s > 192) ? (192 - reg) : count4s;
    if (reg < 192 && dstMax > 0) {
        memcpy(g_vshConstants[reg], src, dstMax * 16);
        // Also mirror into guest shadow
        memcpy(base + kVshConstantShadow + reg * 16, src, dstMax * 16);
    }
}

void D3DDevice_SetVertexShaderConstant1(X86Context& ctx, uint8_t* base) {
    uint32_t arg0 = GuestArg32(ctx, base, 0);
    uint32_t arg1 = GuestArg32(ctx, base, 1);
    uint32_t reg = 0, pData = 0;
    
    if (ctx.ecx < 192 && ctx.edx >= 0x10000) {
        reg = ctx.ecx;
        pData = ctx.edx;
        GuestStackCleanup(ctx, 0);
    } else if (arg0 < 192 && arg1 >= 0x10000) {
        reg = arg0;
        pData = arg1;
        GuestStackCleanup(ctx, 8);
    } else {
        GuestStackCleanup(ctx, 0);
        return;
    }

    CaptureVshConstants(base, reg, pData, 1);
}

void D3DDevice_SetVertexShaderConstant1Fast(X86Context& ctx, uint8_t* base) {
    uint32_t arg0 = GuestArg32(ctx, base, 0);
    uint32_t arg1 = GuestArg32(ctx, base, 1);
    uint32_t reg = 0, pData = 0;
    
    if (ctx.ecx < 192 && ctx.edx >= 0x10000) {
        reg = ctx.ecx;
        pData = ctx.edx;
        GuestStackCleanup(ctx, 0);
    } else if (arg0 < 192 && arg1 >= 0x10000) {
        reg = arg0;
        pData = arg1;
        GuestStackCleanup(ctx, 8);
    } else {
        GuestStackCleanup(ctx, 0);
        return;
    }

    CaptureVshConstants(base, reg, pData, 1);
}

void D3DDevice_SetVertexShaderConstant4(X86Context& ctx, uint8_t* base) {
    uint32_t arg0 = GuestArg32(ctx, base, 0);
    uint32_t arg1 = GuestArg32(ctx, base, 1);
    uint32_t reg = 0, pData = 0;
    
    if (ctx.ecx < 192 && ctx.edx >= 0x10000) {
        reg = ctx.ecx;
        pData = ctx.edx;
        GuestStackCleanup(ctx, 0);
    } else if (arg0 < 192 && arg1 >= 0x10000) {
        reg = arg0;
        pData = arg1;
        GuestStackCleanup(ctx, 8);
    } else {
        GuestStackCleanup(ctx, 0);
        return;
    }

    CaptureVshConstants(base, reg, pData, 4);
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

    // Track this surface so SetRenderTarget(surfAddr) can route draws into
    // the parent's GuestRT. The mip level is inferred from the per-parent
    // creation order (NV2A textures hand surfaces out from largest to
    // smallest mip).
    if (pParent != 0) {
        uint32_t pFmt = X86_MEM_READ_u32(base, pParent + 12);
        uint8_t  xF   = (pFmt >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;
        if (IsRTFormat(xF)) {
            // Count existing surfaces already registered for this parent;
            // that becomes the mip level for the new surface. NB: the rt
            // pointer is still null at registration time (filled lazily on
            // first SetRenderTarget), so DO NOT gate on `kv.second.rt` —
            // doing so makes every surface come back as mip 0, which silently
            // routes the entire bloom downsample chain into mip 0 and breaks
            // post-FX (bloom / motion blur / reflections / lens flare).
            uint32_t mipLevel = 0;
            for (auto& kv : g_d3d11.guestRTBySurface) {
                if (kv.second.parent == pParent) ++mipLevel;
            }
            // Register a placeholder; the GuestRT itself is created lazily
            // when SetRenderTarget actually targets one of these surfaces.
            SurfaceRTBind b;
            b.rt     = nullptr;
            b.mip    = mipLevel;
            b.parent = pParent;
            g_d3d11.guestRTBySurface[surfAddr] = b;
            fprintf(stderr, "[D3D11] track RT-surface 0x%08X parent=0x%08X mip=%u\n",
                    surfAddr, pParent, mipLevel);
        }
        // if (xF == X_D3DFMT_A8R8G8B8 || xF == X_D3DFMT_LIN_A8R8G8B8) {
        //     // Count existing surfaces already registered for this parent;
        //     // that becomes the mip level for the new surface. NB: the rt
        //     // pointer is still null at registration time (filled lazily on
        //     // first SetRenderTarget), so DO NOT gate on `kv.second.rt` —
        //     // doing so makes every surface come back as mip 0, which silently
        //     // routes the entire bloom downsample chain into mip 0 and breaks
        //     // post-FX (bloom / motion blur / reflections / lens flare).
        //     uint32_t mipLevel = 0;
        //     for (auto& kv : g_d3d11.guestRTBySurface) {
        //         if (kv.second.parent == pParent) ++mipLevel;
        //     }
        //     // Register a placeholder; the GuestRT itself is created lazily
        //     // when SetRenderTarget actually targets one of these surfaces.
        //     SurfaceRTBind b;
        //     b.rt     = nullptr;
        //     b.mip    = mipLevel;
        //     b.parent = pParent;
        //     g_d3d11.guestRTBySurface[surfAddr] = b;
        //     fprintf(stderr, "[D3D11] track RT-surface 0x%08X parent=0x%08X mip=%u\n",
        //             surfAddr, pParent, mipLevel);
        // }
    }

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

// Ensure a D3D11 RT-capable texture exists for the parent guest texture
// Read width/height from an NV2A texture header in guest memory.
// Uses the same sizeField/fmtField encoding as EnsureGuestRT.
// Returns false if the address is 0 or dimensions look bogus.
static bool GetGuestTexDims(uint8_t* base, uint32_t addr, uint32_t& w, uint32_t& h)
{
    w = h = 0;
    if (!addr || !base) return false;
    uint32_t fmtField  = X86_MEM_READ_u32(base, addr + 12);
    uint32_t sizeField = X86_MEM_READ_u32(base, addr + 16);
    if (sizeField != 0) {
        w = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        h = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
    } else {
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        w = 1u << logU;
        h = 1u << logV;
    }
    return (w >= 2 && h >= 2 && w <= 4096 && h <= 4096);
}

// `parentTexAddr`. Creates the underlying ID3D11Texture2D with full mip
// chain, both BIND_RENDER_TARGET | BIND_SHADER_RESOURCE, plus per-mip RTVs
// and a full-chain SRV. Returns the GuestRT* (cached) or nullptr if the
// parent texture's format is not RT-eligible.
static GuestRT* EnsureGuestRT(uint8_t* base, uint32_t parentTexAddr)
{
    if (!g_d3d11.initialized || parentTexAddr == 0) return nullptr;

    auto it = g_d3d11.guestRTByParent.find(parentTexAddr);
    if (it != g_d3d11.guestRTByParent.end()) return it->second;

    uint32_t fmtField  = X86_MEM_READ_u32(base, parentTexAddr + 12);
    uint32_t sizeField = X86_MEM_READ_u32(base, parentTexAddr + 16);
    uint32_t dataAddr  = X86_MEM_READ_u32(base, parentTexAddr + 4);
    uint8_t  xFmt      = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

    if (!IsRTFormat(xFmt)) {
        static int s_fmtLog = 0;
        if (s_fmtLog < 16) {
            fprintf(stderr, "[D3D11] EnsureGuestRT: parent=0x%08X xFmt=0x%02X not RT-capable\n",
                    parentTexAddr, xFmt);
            ++s_fmtLog;
        }
        return nullptr;
    }

    uint32_t baseW, baseH;
    if (sizeField != 0) {
        baseW = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
        baseH = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
    } else {
        uint32_t logU = (fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        baseW = 1u << logU;
        baseH = 1u << logV;
    }
    if (baseW == 0 || baseH == 0 || baseW > 4096 || baseH > 4096) return nullptr;

    // Determine mip count from the largest dimension.
    uint32_t mipCount = 1;
    {
        uint32_t m = (baseW > baseH) ? baseW : baseH;
        while (m > 1) { m >>= 1; mipCount++; }
    }

    auto* rt = new GuestRT();
    rt->parentTexAddr = parentTexAddr;
    rt->dataAddr      = dataAddr;
    rt->fmtField      = fmtField;
    rt->sizeField     = sizeField;
    rt->xFmt          = xFmt;
    rt->baseW         = baseW;
    rt->baseH         = baseH;
    rt->mipCount      = mipCount;
    rt->dxgiFormat    = DXGI_FORMAT_B8G8R8A8_UNORM;

    D3D11_TEXTURE2D_DESC td = {};
    td.Width            = baseW;
    td.Height           = baseH;
    td.MipLevels        = mipCount;
    td.ArraySize        = 1;
    td.Format           = rt->dxgiFormat;
    td.SampleDesc.Count = 1;
    td.Usage            = D3D11_USAGE_DEFAULT;
    td.BindFlags        = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;

    HRESULT hr = g_d3d11.device->CreateTexture2D(&td, nullptr, &rt->texture);
    if (FAILED(hr) || !rt->texture) {
        fprintf(stderr, "[D3D11] EnsureGuestRT: CreateTexture2D failed 0x%08X (parent=0x%08X %ux%u mips=%u)\n",
                hr, parentTexAddr, baseW, baseH, mipCount);
        delete rt;
        return nullptr;
    }
    SetD3DName(rt->texture, "B3_GuestRT_parent_%08X_%ux%u_mips%u",
               parentTexAddr, baseW, baseH, mipCount);

    rt->rtvPerMip.resize(mipCount, nullptr);
    rt->srvPerMip.resize(mipCount, nullptr);
    for (uint32_t m = 0; m < mipCount; ++m) {
        D3D11_RENDER_TARGET_VIEW_DESC rd = {};
        rd.Format             = rt->dxgiFormat;
        rd.ViewDimension      = D3D11_RTV_DIMENSION_TEXTURE2D;
        rd.Texture2D.MipSlice = m;
        ID3D11RenderTargetView* rtv = nullptr;
        hr = g_d3d11.device->CreateRenderTargetView(rt->texture, &rd, &rtv);
        if (SUCCEEDED(hr)) rt->rtvPerMip[m] = rtv;
        SetD3DName(rtv, "B3_GuestRTV_parent_%08X_mip%u", parentTexAddr, m);

        D3D11_SHADER_RESOURCE_VIEW_DESC sm = {};
        sm.Format                    = rt->dxgiFormat;
        sm.ViewDimension             = D3D11_SRV_DIMENSION_TEXTURE2D;
        sm.Texture2D.MostDetailedMip = m;
        sm.Texture2D.MipLevels       = 1;
        ID3D11ShaderResourceView* sv = nullptr;
        if (SUCCEEDED(g_d3d11.device->CreateShaderResourceView(rt->texture, &sm, &sv))) {
            rt->srvPerMip[m] = sv;
            SetD3DName(sv, "B3_GuestRT_SRV_mip%u_parent_%08X", m, parentTexAddr);
        }
    }

    D3D11_SHADER_RESOURCE_VIEW_DESC sd = {};
    sd.Format                    = rt->dxgiFormat;
    sd.ViewDimension             = D3D11_SRV_DIMENSION_TEXTURE2D;
    sd.Texture2D.MostDetailedMip = 0;
    sd.Texture2D.MipLevels       = mipCount;
    g_d3d11.device->CreateShaderResourceView(rt->texture, &sd, &rt->srv);
    SetD3DName(rt->srv, "B3_GuestRT_SRV_parent_%08X", parentTexAddr);

    // Build per-mip "source" SRVs: srvSrcExclMip[M] exposes mips 0..M-1 so
    // it does NOT overlap with rtvPerMip[M]. Index 0 stays nullptr (no
    // valid source if rendering to mip 0 of this same texture).
    rt->srvSrcExclMip.resize(mipCount, nullptr);
    for (uint32_t M = 1; M < mipCount; ++M) {
        D3D11_SHADER_RESOURCE_VIEW_DESC sx = {};
        sx.Format                    = rt->dxgiFormat;
        sx.ViewDimension             = D3D11_SRV_DIMENSION_TEXTURE2D;
        sx.Texture2D.MostDetailedMip = 0;
        sx.Texture2D.MipLevels       = M;
        ID3D11ShaderResourceView* sv = nullptr;
        if (SUCCEEDED(g_d3d11.device->CreateShaderResourceView(
                rt->texture, &sx, &sv))) {
            rt->srvSrcExclMip[M] = sv;
            SetD3DName(sv, "B3_GuestRT_SRVexcl_%08X_RTmip%u", parentTexAddr, M);
        }
    }

    // Clear all mips to opaque black so first-frame sampling before any
    // render-to-texture pass produces a defined result.
    if (g_d3d11.context) {
        const float black[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        for (uint32_t m = 0; m < mipCount; ++m) {
            if (rt->rtvPerMip[m])
                g_d3d11.context->ClearRenderTargetView(rt->rtvPerMip[m], black);
        }
    }

    // Create per-GuestRT depth buffer so 3D scene draws get depth testing.
    // Each mip level of the color RT maps to a matching mip of the depth
    // texture (mip dimensions are baseW>>m x baseH>>m).
    {
        D3D11_TEXTURE2D_DESC dtd = {};
        dtd.Width            = baseW;
        dtd.Height           = baseH;
        dtd.MipLevels        = mipCount;
        dtd.ArraySize        = 1;
        dtd.Format           = DXGI_FORMAT_R24G8_TYPELESS;
        dtd.SampleDesc.Count = 1;
        dtd.Usage            = D3D11_USAGE_DEFAULT;
        dtd.BindFlags        = D3D11_BIND_DEPTH_STENCIL;
        rt->dsvPerMip.resize(mipCount, nullptr);
        if (SUCCEEDED(g_d3d11.device->CreateTexture2D(&dtd, nullptr, &rt->depthTex))) {
            SetD3DName(rt->depthTex, "B3_GuestRT_Depth_parent_%08X_%ux%u",
                       parentTexAddr, baseW, baseH);
            for (uint32_t m = 0; m < mipCount; ++m) {
                D3D11_DEPTH_STENCIL_VIEW_DESC dvd = {};
                dvd.Format             = DXGI_FORMAT_D24_UNORM_S8_UINT;
                dvd.ViewDimension      = D3D11_DSV_DIMENSION_TEXTURE2D;
                dvd.Texture2D.MipSlice = m;
                ID3D11DepthStencilView* dsv = nullptr;
                if (SUCCEEDED(g_d3d11.device->CreateDepthStencilView(rt->depthTex, &dvd, &dsv)))
                    rt->dsvPerMip[m] = dsv;
            }
            // Pre-clear all depth mips to far (1.0) so first draw is correct.
            if (g_d3d11.context) {
                for (uint32_t m = 0; m < mipCount; ++m) {
                    if (rt->dsvPerMip[m])
                        g_d3d11.context->ClearDepthStencilView(rt->dsvPerMip[m],
                            D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL, 1.0f, 0);
                }
            }
        }
    }

    g_d3d11.guestRTByParent[parentTexAddr]   = rt;
    if (dataAddr != 0) {
        uint8_t fmtInfo = XboxFormatInfo(rt->xFmt);
        uint32_t bppField = fmtInfo & 0x3C;
        bool isDXT = IsCompressedFormat(rt->xFmt);
        uint32_t compMin = isDXT ? 2 : 0;
        
        uint32_t logU = (rt->fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF;
        uint32_t logV = (rt->fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF;
        uint32_t logP = (rt->fmtField >> X_D3DFORMAT_PSIZE_SHIFT) & 0xF;

        for (uint32_t m = 0; m < mipCount; ++m) {
            uint32_t offset = 0;
            uint32_t tU = logU, tV = logV, tP = logP;
            for (uint32_t i = 0; i < m; ++i) {
                uint32_t curU = (tU > compMin) ? tU : compMin;
                uint32_t curV = (tV > compMin) ? tV : compMin;
                uint32_t levelBits = curU + curV + tP;
                offset += (1u << levelBits) * bppField / 8;
                if (tU > 0) tU--;
                if (tV > 0) tV--;
                if (tP > 0) tP--;
            }
            offset = (offset + 127) & ~127u; // Xbox mip sizes are rounded to 128-byte block sizes iteratively
            
            GuestRTBind bind;
            bind.rt = rt;
            bind.mip = m;
            g_d3d11.guestRTByDataAddr[(dataAddr + offset) & 0x0FFFFFFF] = bind;
        }
    }

    // Register actual surface data addresses to support custom allocations
    for (const auto& kv : g_d3d11.guestRTBySurface) {
        if (kv.second.parent == parentTexAddr) {
            uint32_t surfData = X86_MEM_READ_u32(base, kv.first + 4) & 0x0FFFFFFF;
            GuestRTBind bind;
            bind.rt = rt;
            bind.mip = kv.second.mip;
            g_d3d11.guestRTByDataAddr[surfData] = bind;
        }
    }

    fprintf(stderr, "[D3D11] EnsureGuestRT: parent=0x%08X data=0x%08X %ux%u mips=%u srv=%p\n",
            parentTexAddr, dataAddr, baseW, baseH, mipCount, (void*)rt->srv);
    return rt;
}

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
    
    if (st.offset == 0) return nullptr;

    uint32_t dataAddr = st.offset & 0x0FFFFFFF;
    if (dataAddr == 0) return nullptr;

    // Detect if this dataAddr belongs to the back buffer for Post-FX
    uint32_t activeRTData = 0;
    uint32_t rtAddr = g_d3d11.currentRTSurf;
    if (rtAddr == 0) rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
    if (rtAddr == 0) rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);
    if (rtAddr != 0) activeRTData = X86_MEM_READ_u32(base, rtAddr + 4);

    for (int i = 0; i < 4; ++i) {
        uint32_t bbAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase + i * 4);
        if (bbAddr != 0) {
            uint32_t bbData = X86_MEM_READ_u32(base, bbAddr + 4);
            if (dataAddr == bbData) {
                if (dataAddr == activeRTData) {
                    return g_d3d11.sceneSRV; // Active RT => feedback loop (Hazard mitigation uses scratch)
                } else {
                    return g_d3d11.sceneSRV; // Sample current frame (post-bloom) for radial/directional blur
                }
            }
        }
    }

    // GuestRT checks (Fast-path for bloom/blur mipmaps)
    auto itD = g_d3d11.guestRTByDataAddr.find(dataAddr);
    if (itD != g_d3d11.guestRTByDataAddr.end() && itD->second.rt) {
        if (itD->second.mip == 0) {
            return itD->second.rt->srv;
        } else if (itD->second.mip < itD->second.rt->srvPerMip.size()) {
            return itD->second.rt->srvPerMip[itD->second.mip];
        }
    }

    // If it's a regular texture (not an RT), we MUST have a format to proceed.
    if (st.format == 0) return nullptr;

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
        uint32_t w = (st.imageRect >> 16) & 0xFFFF;
        uint32_t h = (st.imageRect >>  0) & 0xFFFF;
        if (w == 0 || h == 0 || w > 4096 || h > 4096) return nullptr;
        uint32_t pitch = (st.control1 >> 16) & 0xFFFF;
        uint32_t pitch64 = pitch ? (pitch / 64) : 1;
        sizeField = ((w - 1) & X_D3DSIZE_WIDTH_MASK)
                  | (((h - 1) << X_D3DSIZE_HEIGHT_SHIFT) & X_D3DSIZE_HEIGHT_MASK)
                  | ((((pitch64 - 1) & 0xFF)) << X_D3DSIZE_PITCH_SHIFT);
    }

    // Allocate one synthetic header per (dataAddr, fmt, sizeField)
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

    // Detect if this dataAddr belongs to the back buffer for Post-FX
    uint32_t activeRTData = 0;
    uint32_t rtAddr = g_d3d11.currentRTSurf;
    if (rtAddr == 0) rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
    if (rtAddr == 0) rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);
    if (rtAddr != 0) activeRTData = X86_MEM_READ_u32(base, rtAddr + 4);

    for (int i = 0; i < 4; ++i) {
        uint32_t bbAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase + i * 4);
        if (bbAddr != 0) {
            uint32_t bbData = X86_MEM_READ_u32(base, bbAddr + 4);
            if (dataAddr == bbData) {
                if (dataAddr == activeRTData) {
                    return g_d3d11.sceneSRV; // Active RT => feedback loop (Hazard mitigation uses scratch)
                } else {
                    return g_d3d11.sceneSRV; // Sample current frame (post-bloom) for radial/directional blur
                }
            }
        }
    }

    uint32_t xFmt = (fmtField >> X_D3DFORMAT_FORMAT_SHIFT) & 0xFF;

    // If this texture's parent (or its data buffer) matches a tracked
    // render-to-texture, return the GuestRT's SRV directly so the game
    // sees the contents the GPU actually rendered.
    {
        auto itP = g_d3d11.guestRTByParent.find(xboxTexAddr);
        if (itP != g_d3d11.guestRTByParent.end() && itP->second && itP->second->srv)
            return itP->second->srv;
        auto itD = g_d3d11.guestRTByDataAddr.find(dataAddr & 0x0FFFFFFF);
        if (itD != g_d3d11.guestRTByDataAddr.end() && itD->second.rt) {
            if (itD->second.mip == 0) {
                return itD->second.rt->srv;
            } else if (itD->second.mip < itD->second.rt->srvPerMip.size()) {
                return itD->second.rt->srvPerMip[itD->second.mip];
            }
        }
    }

    // Xbox native VRAM addresses (0x08000000-0x0FFFFFFF) may contain GPU-managed
    // framebuffer regions (bloom source, motion-blur capture, etc.) that the D3D11
    // renderer never writes to directly.  However the same range also holds regular
    // game textures loaded from disk AND small lookup/palette textures whose pixel
    // data is legitimately all-zero.  Distinguish framebuffer captures by:
    //   1. Probing guest memory — NV2A captures are never written so they stay zero.
    //   2. Requiring a minimum texture size (>= 64x64) — small lookup tables must
    //      NOT be redirected to prevSceneSRV because that would feed random scene
    //      pixels into NV2A lighting/normal-map lookups and corrupt 3D shading.
    if (dataAddr >= 0x08000000u && dataAddr < 0x10000000u) {
        const uint32_t* probe = reinterpret_cast<const uint32_t*>(base + dataAddr);
        bool hasData = false;
        for (int k = 0; k < 16 && !hasData; ++k)
            hasData = (probe[k] != 0u);
        if (!hasData) {
            // Decode dimensions quickly from the already-loaded fmtField/sizeField.
            uint32_t vW, vH;
            if (sizeField != 0) {
                vW = (sizeField & X_D3DSIZE_WIDTH_MASK) + 1;
                vH = ((sizeField & X_D3DSIZE_HEIGHT_MASK) >> X_D3DSIZE_HEIGHT_SHIFT) + 1;
            } else {
                vW = 1u << ((fmtField >> X_D3DFORMAT_USIZE_SHIFT) & 0xF);
                vH = 1u << ((fmtField >> X_D3DFORMAT_VSIZE_SHIFT) & 0xF);
            }
            static int s_vramLog = 0;
            if (s_vramLog < 16) {
                fprintf(stderr, "[D3D11] VRAM-range tex hdr=0x%08X data=0x%08X (zero) %ux%u -> %s\n",
                        xboxTexAddr, dataAddr, vW, vH,
                        (vW >= 64 && vH >= 64) ? "sceneSRV" : "skip(too small)");
                ++s_vramLog;
            }
            if (vW >= 64 && vH >= 64)
                return g_d3d11.sceneSRV; // Use current-frame scene; prevSceneSRV causes bloom feedback loop
        }
    }

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

    // Detect Xbox cubemap flag (bit 2 of the format field per Cxbx
    // X_D3DFORMAT_CUBEMAP = 0x00000004). Cubemaps on NV2A are square and
    // store 6 faces concatenated in memory at dataAddr + face*faceBytes,
    // each face independently swizzled.
    const bool isCube = (fmtField & 0x00000004u) != 0;
    if (isCube && texW != texH) {
        // Malformed cube; drop through as 2D.
        fprintf(stderr, "[D3D11] cube with non-square dims %ux%u (fmt=0x%02X); treating as 2D\n",
                texW, texH, xFmt);
    }
    const uint32_t numFaces = (isCube && texW == texH) ? 6u : 1u;
    if (numFaces == 6) {
        static int s_cubeLog = 0;
        if (s_cubeLog < 8) {
            fprintf(stderr, "[D3D11] cube texture hdr=0x%08X data=0x%08X %ux%u fmt=0x%02X\n",
                    xboxTexAddr, dataAddr, texW, texH, xFmt);
            ++s_cubeLog;
        }
    }

    // Build upload buffer(s). For cubes, faceBufs[0..5] each hold one face.
    std::vector<std::vector<uint8_t>> faceBufs(numFaces);
    uint32_t uploadPitch = 0;
    uint32_t srcFaceBytes = 0;   // bytes per face in Xbox memory

    // Compute source bytes-per-pixel for non-DXT paths (used for face stride).
    uint32_t srcBpp = 4;
    if (!nativeDXT) {
        switch (xFmt) {
        case X_D3DFMT_R5G6B5: case 0x1C: case X_D3DFMT_A1R5G5B5: case 0x1D:
        case X_D3DFMT_A4R4G4B4:
        case 0x03:
            srcBpp = 2; break;
        case 0x00: case 0x01: case 0x19: case X_D3DFMT_P8:
            srcBpp = 1; break;
        default:
            srcBpp = 4; break;
        }
    }
    if (nativeDXT) {
        uint32_t blockSize = (xFmt == X_D3DFMT_DXT1 || xFmt == 0x0D) ? 8u : 16u;
        uint32_t bw = (texW + 3) / 4;
        uint32_t bh = (texH + 3) / 4;
        uploadPitch  = bw * blockSize;
        srcFaceBytes = bh * uploadPitch;
    } else {
        uploadPitch  = texW * 4;
        srcFaceBytes = texW * texH * srcBpp;
    }

    auto buildFace = [&](uint32_t faceSrcAddr, std::vector<uint8_t>& buf) {
        if (nativeDXT) {
            buf.resize(srcFaceBytes);
            memcpy(buf.data(), base + faceSrcAddr, buf.size());
            return;
        }
        buf.resize((size_t)texH * uploadPitch);
        uint32_t* dst32 = reinterpret_cast<uint32_t*>(buf.data());

        std::vector<uint8_t> tmp;
        const uint8_t* src = base + faceSrcAddr;
        if (swizzled) {
            tmp.resize((size_t)texW * texH * srcBpp);
            UnswizzleTexture(src, tmp.data(), texW, texH, srcBpp);
            src = tmp.data();
        }

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
            case 0x00: case 0x01: { // L8 / AL8
                uint8_t l = src[i];
                argb = ((uint32_t)l << 24) | 0x00FFFFFFu;
                break;
            }
            case 0x19: { // A8
                uint8_t a = src[i];
                argb = ((uint32_t)a << 24) | 0x00FFFFFFu;
                break;
            }
            default:
                argb = reinterpret_cast<const uint32_t*>(src)[i];
                break;
            }
            dst32[i] = argb;
        }
    };

    for (uint32_t f = 0; f < numFaces; ++f) {
        buildFace(dataAddr + f * srcFaceBytes, faceBufs[f]);
    }
    // Keep a reference to the first face's buffer for legacy diagnostics.
    std::vector<uint8_t>& buf = faceBufs[0];

    // Create immutable D3D11 texture
    D3D11_TEXTURE2D_DESC td = {};
    td.Width     = texW;
    td.Height    = texH;
    td.MipLevels = 1;
    td.ArraySize = numFaces;
    td.Format    = dxgiFmt;
    td.SampleDesc.Count   = 1;
    td.SampleDesc.Quality = 0;
    td.Usage     = D3D11_USAGE_IMMUTABLE;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    if (numFaces == 6) td.MiscFlags = D3D11_RESOURCE_MISC_TEXTURECUBE;

    D3D11_SUBRESOURCE_DATA initData[6] = {};
    for (uint32_t f = 0; f < numFaces; ++f) {
        initData[f].pSysMem     = faceBufs[f].data();
        initData[f].SysMemPitch = uploadPitch;
    }

    ID3D11Texture2D* pTex = nullptr;
    HRESULT hr = g_d3d11.device->CreateTexture2D(&td, initData, &pTex);
    if (FAILED(hr)) {
        fprintf(stderr, "[D3D11] CreateTexture2D failed: 0x%08X (%ux%u fmt=0x%02X cube=%d)\n",
                hr, texW, texH, xFmt, (int)(numFaces == 6));
        return nullptr;
    }
    SetD3DName(pTex, "B3_Tex_%08X_data%08X_%ux%u_xfmt%02X%s",
               xboxTexAddr, dataAddr, texW, texH, xFmt,
               numFaces == 6 ? "_cube" : "");

    ID3D11ShaderResourceView* pSRV = nullptr;
    hr = g_d3d11.device->CreateShaderResourceView(pTex, nullptr, &pSRV);
    if (FAILED(hr)) { pTex->Release(); return nullptr; }
    SetD3DName(pSRV, "B3_TexSRV_%08X_xfmt%02X", xboxTexAddr, xFmt);

    TextureCacheEntry& ent = g_d3d11.textureCache[xboxTexAddr];
    ent.texture      = pTex;
    ent.srv          = pSRV;
    ent.xboxDataAddr = dataAddr;
    ent.width        = texW;
    ent.height       = texH;
    ent.dxgiFormat   = dxgiFmt;
    ent.xboxFmtCode  = static_cast<uint8_t>(xFmt);
    ent.isAlphaOnly  = isAlphaOnly;

    return pSRV;
}

static ID3D11ShaderResourceView* ResolveShaderResourceView(uint8_t* base, uint32_t stage, uint32_t snapshotAddr = 0, bool* outAlphaOnly = nullptr, uint32_t* outTexAddr = nullptr, uint32_t* outW = nullptr, uint32_t* outH = nullptr) {
    if (stage >= 4) return nullptr;
    ID3D11ShaderResourceView* srv = nullptr;
    bool alphaOnly = false;
    uint32_t texW = 1, texH = 1;
    // If an explicit address is supplied by the caller (e.g. stage-aware snap/live
    // selection in BindTranslatedPSFor2D), use it directly.  Otherwise fall back to
    // the live texture register, which is correct for ordinary draw calls.
    uint32_t texAddr = snapshotAddr ? snapshotAddr
                                    : X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + stage * 4);
    
    auto tryHLE = [&]() -> ID3D11ShaderResourceView* {
        if (texAddr) {
            ID3D11ShaderResourceView* s = GetOrCreateTextureSRV(base, texAddr);
            if (s) {
                auto it = g_d3d11.textureCache.find(texAddr);
                if (it != g_d3d11.textureCache.end()) {
                    alphaOnly = it->second.isAlphaOnly;
                    texW = it->second.width;
                    texH = it->second.height;
                }
                return s;
            }
        }
        return nullptr;
    };
    
    auto tryNV2A = [&]() -> ID3D11ShaderResourceView* {
        ID3D11ShaderResourceView* s = ResolveNV2ATextureSRV(base, stage);
        if (s) {
            const NV2ATextureState& st = g_nv2aTexture[stage];
            if (st.imageRect != 0) {
                texW = (st.imageRect >> 16) & 0xFFFF;
                texH = (st.imageRect >>  0) & 0xFFFF;
            }
        }
        return s;
    };
    
    if (g_texBoundSource[stage] == 1 && snapshotAddr == 0) { // NV2A, no explicit override
        srv = tryNV2A();
        if (!srv) srv = tryHLE();
    } else {
        srv = tryHLE();
        if (!srv) srv = tryNV2A();
    }
    
    if (texW == 0) texW = 1;
    if (texH == 0) texH = 1;
    
    if (outAlphaOnly) *outAlphaOnly = alphaOnly;
    if (outTexAddr) *outTexAddr = texAddr;
    if (outW) *outW = texW;
    if (outH) *outH = texH;
    return srv;
}

// ============================================================================
// D3D11 back-buffer management
// ============================================================================

static void ReleaseBackBufferResources()
{
    auto R = [](auto*& p){ if (p) { p->Release(); p = nullptr; } };
    R(g_d3d11.backBufferRTV);
    R(g_d3d11.backBufferTex);
    R(g_d3d11.sceneSRV);
    R(g_d3d11.prevSceneSRV);
    R(g_d3d11.prevSceneTex);
    R(g_d3d11.swapChainRTV);
    R(g_d3d11.swapChainTex);
    R(g_d3d11.depthDSV);
    R(g_d3d11.depthSRV);
    R(g_d3d11.depthTex);
}

static void CreateBackBufferResources()
{
    // Acquire the actual DXGI swap-chain buffer (presentation only).
    HRESULT hr = g_d3d11.swapChain->GetBuffer(0, __uuidof(ID3D11Texture2D),
                                               reinterpret_cast<void**>(&g_d3d11.swapChainTex));
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] GetBuffer failed: 0x%08X\n", hr); return; }
    SetD3DName(g_d3d11.swapChainTex, "B3_SwapChainTex");

    // Inspect format/size from the DXGI buffer so the scene texture matches.
    D3D11_TEXTURE2D_DESC scDesc = {};
    g_d3d11.swapChainTex->GetDesc(&scDesc);
    g_d3d11.sceneFormat = scDesc.Format;

    hr = g_d3d11.device->CreateRenderTargetView(g_d3d11.swapChainTex, nullptr,
                                                 &g_d3d11.swapChainRTV);
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateRTV(swapChain) failed: 0x%08X\n", hr); return; }
    SetD3DName(g_d3d11.swapChainRTV, "B3_SwapChainRTV");

    // Create our own scene render target. RT+SR bind so post-FX / CopyRects
    // can sample previously-rendered content.
    D3D11_TEXTURE2D_DESC sd = {};
    sd.Width            = scDesc.Width;
    sd.Height           = scDesc.Height;
    sd.MipLevels        = 1;
    sd.ArraySize        = 1;
    sd.Format           = scDesc.Format;
    sd.SampleDesc.Count = 1;
    sd.Usage            = D3D11_USAGE_DEFAULT;
    sd.BindFlags        = D3D11_BIND_RENDER_TARGET | D3D11_BIND_SHADER_RESOURCE;
    hr = g_d3d11.device->CreateTexture2D(&sd, nullptr, &g_d3d11.backBufferTex);
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateTexture2D(scene) failed: 0x%08X\n", hr); return; }
    SetD3DName(g_d3d11.backBufferTex, "B3_SceneTex");

    hr = g_d3d11.device->CreateRenderTargetView(g_d3d11.backBufferTex, nullptr,
                                                 &g_d3d11.backBufferRTV);
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateRTV(scene) failed: 0x%08X\n", hr); return; }
    SetD3DName(g_d3d11.backBufferRTV, "B3_SceneRTV");

    hr = g_d3d11.device->CreateShaderResourceView(g_d3d11.backBufferTex, nullptr,
                                                    &g_d3d11.sceneSRV);
    if (FAILED(hr)) { fprintf(stderr, "[D3D11] CreateSRV(scene) failed: 0x%08X\n", hr); return; }
    SetD3DName(g_d3d11.sceneSRV, "B3_SceneSRV");

    hr = g_d3d11.device->CreateTexture2D(&sd, nullptr, &g_d3d11.prevSceneTex);
    if (SUCCEEDED(hr)) {
        SetD3DName(g_d3d11.prevSceneTex, "B3_PrevSceneTex");
        g_d3d11.device->CreateShaderResourceView(g_d3d11.prevSceneTex, nullptr, &g_d3d11.prevSceneSRV);
        SetD3DName(g_d3d11.prevSceneSRV, "B3_PrevSceneSRV");
    }

    // Depth target: TYPELESS so we can have both a DSV (D24_UNORM_S8_UINT) and
    // an SRV (R24_UNORM_X8_TYPELESS) for sampling depth in shaders.
    D3D11_TEXTURE2D_DESC dd = {};
    dd.Width               = g_d3d11.width;
    dd.Height              = g_d3d11.height;
    dd.MipLevels           = 1;
    dd.ArraySize           = 1;
    dd.Format              = DXGI_FORMAT_R24G8_TYPELESS;
    dd.SampleDesc.Count    = 1;
    dd.Usage               = D3D11_USAGE_DEFAULT;
    dd.BindFlags           = D3D11_BIND_DEPTH_STENCIL | D3D11_BIND_SHADER_RESOURCE;
    g_d3d11.device->CreateTexture2D(&dd, nullptr, &g_d3d11.depthTex);
    if (g_d3d11.depthTex) {
        D3D11_DEPTH_STENCIL_VIEW_DESC dvd = {};
        dvd.Format        = DXGI_FORMAT_D24_UNORM_S8_UINT;
        dvd.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2D;
        g_d3d11.device->CreateDepthStencilView(g_d3d11.depthTex, &dvd, &g_d3d11.depthDSV);

        D3D11_SHADER_RESOURCE_VIEW_DESC svd = {};
        svd.Format                    = DXGI_FORMAT_R24_UNORM_X8_TYPELESS;
        svd.ViewDimension             = D3D11_SRV_DIMENSION_TEXTURE2D;
        svd.Texture2D.MipLevels       = 1;
        g_d3d11.device->CreateShaderResourceView(g_d3d11.depthTex, &svd, &g_d3d11.depthSRV);
    }
    SetD3DName(g_d3d11.depthTex, "B3_DepthTex");
    SetD3DName(g_d3d11.depthDSV, "B3_DepthDSV");
    SetD3DName(g_d3d11.depthSRV, "B3_DepthSRV");

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
    SetD3DName(g_d3d11.vs2D, "B3_VS_2D_screen");

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
    SetD3DName(g_d3d11.il2D, "B3_IL_2D");

    // Extended VS + IL: 4 independent UV channels for multi-sample post-FX blur draws
    {
        ID3DBlob* vsExBlob = D3D11CompileShader(s_vsExHlsl, "main", "vs_4_0");
        if (vsExBlob) {
            g_d3d11.device->CreateVertexShader(vsExBlob->GetBufferPointer(),
                                               vsExBlob->GetBufferSize(),
                                               nullptr, &g_d3d11.vs2DEx);
            SetD3DName(g_d3d11.vs2DEx, "B3_VS_2D_Ex");

            // Vtx2DEx: pos(2f) + uv0(2f) + uv1(2f) + uv2(2f) + uv3(2f) + color(B8G8R8A8)
            // Offsets:   0         8         16        24        32        40
            D3D11_INPUT_ELEMENT_DESC iedEx[] = {
                { "POSITION", 0, DXGI_FORMAT_R32G32_FLOAT,   0,  0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT,   0,  8, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 1, DXGI_FORMAT_R32G32_FLOAT,   0, 16, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 2, DXGI_FORMAT_R32G32_FLOAT,   0, 24, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "TEXCOORD", 3, DXGI_FORMAT_R32G32_FLOAT,   0, 32, D3D11_INPUT_PER_VERTEX_DATA, 0 },
                { "COLOR",    0, DXGI_FORMAT_B8G8R8A8_UNORM, 0, 40, D3D11_INPUT_PER_VERTEX_DATA, 0 },
            };
            g_d3d11.device->CreateInputLayout(iedEx, 6,
                                              vsExBlob->GetBufferPointer(),
                                              vsExBlob->GetBufferSize(), &g_d3d11.il2DEx);
            SetD3DName(g_d3d11.il2DEx, "B3_IL_2D_Ex");
            vsExBlob->Release();
        }
    }

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
    SetD3DName(g_d3d11.psUntextured, "B3_PS_2D_Untextured");
    SetD3DName(g_d3d11.psAlpha,      "B3_PS_2D_AlphaOnly");
    SetD3DName(g_d3d11.psModulate,   "B3_PS_2D_Modulate");

    // Constant buffer (16 bytes: float2 screenSize + float2 pad)
    D3D11_BUFFER_DESC cbd = {};
    cbd.ByteWidth      = 16;
    cbd.Usage          = D3D11_USAGE_DYNAMIC;
    cbd.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
    cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&cbd, nullptr, &g_d3d11.cb2D);
    SetD3DName(g_d3d11.cb2D, "B3_CB_2D_screenSize");

    // Dynamic vertex buffer (initial 256K)
    g_d3d11.dynamicVBSize = 262144;
    D3D11_BUFFER_DESC vbd = {};
    vbd.ByteWidth      = g_d3d11.dynamicVBSize;
    vbd.Usage          = D3D11_USAGE_DYNAMIC;
    vbd.BindFlags      = D3D11_BIND_VERTEX_BUFFER;
    vbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&vbd, nullptr, &g_d3d11.dynamicVB);
    SetD3DName(g_d3d11.dynamicVB, "B3_DynVB");

    // Dynamic index buffer (initial 64K)
    g_d3d11.dynamicIBSize = 65536;
    D3D11_BUFFER_DESC ibd = {};
    ibd.ByteWidth      = g_d3d11.dynamicIBSize;
    ibd.Usage          = D3D11_USAGE_DYNAMIC;
    ibd.BindFlags      = D3D11_BIND_INDEX_BUFFER;
    ibd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
    g_d3d11.device->CreateBuffer(&ibd, nullptr, &g_d3d11.dynamicIB);
    SetD3DName(g_d3d11.dynamicIB, "B3_DynIB");

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
            SetD3DName(g_d3d11.vs3D, "B3_VS_3D_fallback");
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
            SetD3DName(g_d3d11.il3D, "B3_IL_3D_fallback_stride28");
            vs3Blob->Release();
        }
        ID3DBlob* ps3Blob = D3D11CompileShader(s_ps3DHlsl, "main", "ps_4_0");
        if (ps3Blob) {
            g_d3d11.device->CreatePixelShader(ps3Blob->GetBufferPointer(),
                                               ps3Blob->GetBufferSize(),
                                               nullptr, &g_d3d11.ps3D);
            SetD3DName(g_d3d11.ps3D, "B3_PS_3D_fallback_textured");
            ps3Blob->Release();
        }
        ID3DBlob* ps3uBlob = D3D11CompileShader(s_ps3DUntexturedHlsl, "main", "ps_4_0");
        if (ps3uBlob) {
            g_d3d11.device->CreatePixelShader(ps3uBlob->GetBufferPointer(),
                                               ps3uBlob->GetBufferSize(),
                                               nullptr, &g_d3d11.ps3DUntextured);
            SetD3DName(g_d3d11.ps3DUntextured, "B3_PS_3D_fallback_untextured");
            ps3uBlob->Release();
        }
        // 192 × float4 NV2A constants
        D3D11_BUFFER_DESC cb3 = {};
        cb3.ByteWidth      = 192 * 16;
        cb3.Usage          = D3D11_USAGE_DYNAMIC;
        cb3.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
        cb3.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        g_d3d11.device->CreateBuffer(&cb3, nullptr, &g_d3d11.cb3D);
        SetD3DName(g_d3d11.cb3D, "B3_CB_VS_NV2A_c192");

        // 32 × float4 NV2A pixel-shader constants (psC[]) - see nv2a_ps_hlsl.cpp.
        D3D11_BUFFER_DESC cbP = {};
        cbP.ByteWidth      = 32 * 16;
        cbP.Usage          = D3D11_USAGE_DYNAMIC;
        cbP.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
        cbP.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        g_d3d11.device->CreateBuffer(&cbP, nullptr, &g_d3d11.cbPS);
        SetD3DName(g_d3d11.cbPS, "B3_CB_PS_NV2A_c32");

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

    // ---- Debug instrumentation resources ----
    SampleDebugFlagsOnce();
    {
        // Debug color PS: hashes drawIdx into a unique RGB, ignores all inputs.
        // Separate input struct for hardcoded s_vs3DHlsl (pos/col/uv)
        // vs. translated NV2A VS output. Use only SV_POSITION so the PS
        // compiles against any VS's SV_POSITION signature (D3D11 only
        // requires matching for signatures the PS reads — we read none).
        static const char s_psDebugHlsl[] =
            "cbuffer CBDebug : register(b0) { float4 dbg; /* x=drawIdx */ }\n"
            "float4 main(float4 p : SV_POSITION) : SV_TARGET {\n"
            "  float n = dbg.x;\n"
            "  float r = frac(n * 0.6180339887);\n"
            "  float g = frac(n * 0.3819660112);\n"
            "  float b = frac(n * 0.7548776662);\n"
            "  return float4(r * 0.8 + 0.2, g * 0.8 + 0.2, b * 0.8 + 0.2, 1.0);\n"
            "}\n";
        if (ID3DBlob* blob = D3D11CompileShader(s_psDebugHlsl, "main", "ps_4_0")) {
            g_d3d11.device->CreatePixelShader(blob->GetBufferPointer(),
                                              blob->GetBufferSize(),
                                              nullptr, &g_d3d11.psDebugColor);
            blob->Release();
        }

        // cbDebug: 1 × float4 (draw index)
        D3D11_BUFFER_DESC cbd = {};
        cbd.ByteWidth      = 16;
        cbd.Usage          = D3D11_USAGE_DYNAMIC;
        cbd.BindFlags      = D3D11_BIND_CONSTANT_BUFFER;
        cbd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;
        g_d3d11.device->CreateBuffer(&cbd, nullptr, &g_d3d11.cbDebug);

        // Wireframe rasterizer: no-cull, no depth-clip, wireframe fill.
        D3D11_RASTERIZER_DESC rsw = {};
        rsw.FillMode        = D3D11_FILL_WIREFRAME;
        rsw.CullMode        = D3D11_CULL_NONE;
        rsw.DepthClipEnable = FALSE;
        g_d3d11.device->CreateRasterizerState(&rsw, &g_d3d11.rsWire);
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

    // Acquire annotation interface for RenderDoc / PIX event markers.
    g_d3d11.context->QueryInterface(__uuidof(ID3DUserDefinedAnnotation),
        reinterpret_cast<void**>(&g_d3d11.annotation));

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
    if (g_d3d11.annotation) { g_d3d11.annotation->Release(); g_d3d11.annotation = nullptr; }
    R(g_d3d11.scratchTex); R(g_d3d11.scratchSRV);
    R(g_d3d11.vs2D); R(g_d3d11.il2D);
    R(g_d3d11.vs2DEx); R(g_d3d11.il2DEx);
    R(g_d3d11.psUntextured); R(g_d3d11.psAlpha); R(g_d3d11.psModulate);
    R(g_d3d11.cb2D); R(g_d3d11.dynamicVB); R(g_d3d11.dynamicIB);
    R(g_d3d11.bsAlpha); R(g_d3d11.bsOpaque); R(g_d3d11.rsNoCull); R(g_d3d11.dssOff);
    R(g_d3d11.samplerLinear); R(g_d3d11.samplerWrap);
    R(g_d3d11.vs3D); R(g_d3d11.il3D); R(g_d3d11.ps3D); R(g_d3d11.ps3DUntextured); R(g_d3d11.cb3D);
    R(g_d3d11.cbPS);
    R(g_d3d11.dssOn); R(g_d3d11.rsCull3D);
    R(g_d3d11.psDebugColor); R(g_d3d11.cbDebug); R(g_d3d11.rsWire);
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

// Extended 2D vertex for translated-PS draws with 4 independent UV stages — 44 bytes.
// Layout matches X_D3DFVF_XYZRHW|DIFFUSE|TEX4 after stripping z/rhw and extracting xy.
struct Vtx2DEx {
    float    x, y;        // screen-space position    (8)
    float    u0, v0;      // UV for PS stage 0        (8)
    float    u1, v1;      // UV for PS stage 1        (8)
    float    u2, v2;      // UV for PS stage 2        (8)
    float    u3, v3;      // UV for PS stage 3        (8)
    uint32_t color;       // ARGB → BGRA_UNORM D3D11  (4)
    // Total: 44 bytes
};

// Translate an NV097_SET_BLEND_FUNC factor (OpenGL-style enum written by
// the Xbox D3D runtime into NV2A methods 0x0344/0x0348) to a D3D11_BLEND.
// These are the enum values NVIDIA used in their GL mapping:
//   0x0000 ZERO, 0x0001 ONE,
//   0x0300..0x0308 SRC_COLOR/INV, SRC_ALPHA/INV, DST_ALPHA/INV, DST_COLOR/INV, SRC_ALPHA_SATURATE.
//   0x8001..0x8004 CONSTANT_{COLOR,ALPHA} variants (ignored: approximated).
static D3D11_BLEND NvBlendFactorToD3D11(uint32_t f, bool alphaChannel)
{
    switch (f) {
        case 0x0000: return D3D11_BLEND_ZERO;
        case 0x0001: return D3D11_BLEND_ONE;
        case 0x0300: return alphaChannel ? D3D11_BLEND_SRC_ALPHA     : D3D11_BLEND_SRC_COLOR;
        case 0x0301: return alphaChannel ? D3D11_BLEND_INV_SRC_ALPHA : D3D11_BLEND_INV_SRC_COLOR;
        case 0x0302: return D3D11_BLEND_SRC_ALPHA;
        case 0x0303: return D3D11_BLEND_INV_SRC_ALPHA;
        case 0x0304: return D3D11_BLEND_DEST_ALPHA;
        case 0x0305: return D3D11_BLEND_INV_DEST_ALPHA;
        case 0x0306: return alphaChannel ? D3D11_BLEND_DEST_ALPHA     : D3D11_BLEND_DEST_COLOR;
        case 0x0307: return alphaChannel ? D3D11_BLEND_INV_DEST_ALPHA : D3D11_BLEND_INV_DEST_COLOR;
        case 0x0308: return D3D11_BLEND_SRC_ALPHA_SAT;
        // Fallback for unsupported/constant-color cases.
        default:     return alphaChannel ? D3D11_BLEND_ONE : D3D11_BLEND_ONE;
    }
}

// NV097 blend equation -> D3D11_BLEND_OP
static D3D11_BLEND_OP NvBlendEqToD3D11(uint32_t eq) {
    switch (eq) {
    case 0x8006: return D3D11_BLEND_OP_ADD;              // FUNC_ADD_SIGNED / FUNC_ADD
    case 0x8009: return D3D11_BLEND_OP_REV_SUBTRACT;     // FUNC_REVERSE_SUBTRACT
    case 0x800A: return D3D11_BLEND_OP_SUBTRACT;         // FUNC_SUBTRACT
    case 0x8007: return D3D11_BLEND_OP_MIN;
    case 0x8008: return D3D11_BLEND_OP_MAX;
    default:     return D3D11_BLEND_OP_ADD;
    }
}
// Cache of blend states keyed by (src,dst,colorMask) so we don't rebuild per-draw.
// nvColorMask is the raw NV097_SET_COLOR_MASK value, byte order BGRA (LSB=blue):
//   bit  0 -> blue write enable
//   bit  8 -> green write enable
//   bit 16 -> red write enable
//   bit 24 -> alpha write enable
static UINT8 NvColorMaskToD3D11(uint32_t nvMask)
{
    UINT8 m = 0;
    if ((nvMask >>  0) & 0xFF) m |= D3D11_COLOR_WRITE_ENABLE_BLUE;
    if ((nvMask >>  8) & 0xFF) m |= D3D11_COLOR_WRITE_ENABLE_GREEN;
    if ((nvMask >> 16) & 0xFF) m |= D3D11_COLOR_WRITE_ENABLE_RED;
    if ((nvMask >> 24) & 0xFF) m |= D3D11_COLOR_WRITE_ENABLE_ALPHA;
    return m;
}
static ID3D11BlendState* GetOrCreateBlendState(uint32_t nvSrc, uint32_t nvDst,
                                               bool blendEnable,
                                               uint32_t nvColorMask,
                                               uint32_t nvBlendEq = 0x8006)
{
    struct Key { uint32_t src, dst, mask, eq; bool en; bool operator==(const Key& o) const {
        return src==o.src && dst==o.dst && mask==o.mask && eq==o.eq && en==o.en; } };
    struct H { size_t operator()(const Key& k) const noexcept {
        return std::hash<uint64_t>()(
            (uint64_t(k.src) ^ (uint64_t(k.dst) << 16) ^
             (uint64_t(k.mask) << 32) ^ (uint64_t(k.eq) << 8)) | (k.en ? 1ull : 0ull));
    } };
    static std::unordered_map<Key, ID3D11BlendState*, H> s_cache;
    Key key { nvSrc, nvDst, nvColorMask, nvBlendEq, blendEnable };
    auto it = s_cache.find(key);
    if (it != s_cache.end()) return it->second;

    D3D11_BLEND_OP blendOp = NvBlendEqToD3D11(nvBlendEq);
    D3D11_BLEND_DESC bd = {};
    bd.RenderTarget[0].BlendEnable           = blendEnable ? TRUE : FALSE;
    bd.RenderTarget[0].SrcBlend              = NvBlendFactorToD3D11(nvSrc, false);
    bd.RenderTarget[0].DestBlend             = NvBlendFactorToD3D11(nvDst, false);
    bd.RenderTarget[0].BlendOp               = blendOp;
    bd.RenderTarget[0].SrcBlendAlpha         = NvBlendFactorToD3D11(nvSrc, true);
    bd.RenderTarget[0].DestBlendAlpha        = NvBlendFactorToD3D11(nvDst, true);
    bd.RenderTarget[0].BlendOpAlpha          = blendOp;
    bd.RenderTarget[0].RenderTargetWriteMask = NvColorMaskToD3D11(nvColorMask);
    ID3D11BlendState* bs = nullptr;
    if (g_d3d11.device && SUCCEEDED(g_d3d11.device->CreateBlendState(&bd, &bs))) {
        s_cache.emplace(key, bs);
        return bs;
    }
    return g_d3d11.bsAlpha; // fallback
}

// Cache of depth-stencil states keyed by all relevant state variables.
static D3D11_COMPARISON_FUNC NvDepthFuncToD3D11(uint32_t nvFunc) {
    // NV097 uses GL constants 0x0200 NEVER .. 0x0207 ALWAYS.
    static const D3D11_COMPARISON_FUNC kMap[8] = {
        D3D11_COMPARISON_NEVER,         // 0x0200
        D3D11_COMPARISON_LESS,          // 0x0201
        D3D11_COMPARISON_EQUAL,         // 0x0202
        D3D11_COMPARISON_LESS_EQUAL,    // 0x0203
        D3D11_COMPARISON_GREATER,       // 0x0204
        D3D11_COMPARISON_NOT_EQUAL,     // 0x0205
        D3D11_COMPARISON_GREATER_EQUAL, // 0x0206
        D3D11_COMPARISON_ALWAYS,        // 0x0207
    };
    uint32_t idx = nvFunc & 7;
    if ((nvFunc & ~7u) != 0x0200) return D3D11_COMPARISON_LESS_EQUAL;
    return kMap[idx];
}
// NV097 stencil op values (GL-derived):
//   0x1E00=KEEP  0x0000=ZERO  0x1E01=REPLACE  0x1E02=INCR_SAT  0x1E03=DECR_SAT
//   0x150A=INVERT  0x8507=INCR  0x8508=DECR
static D3D11_STENCIL_OP NvStencilOpToD3D11(uint32_t nvOp) {
    switch (nvOp) {
    case 0x0000: return D3D11_STENCIL_OP_ZERO;
    case 0x1E00: return D3D11_STENCIL_OP_KEEP;
    case 0x1E01: return D3D11_STENCIL_OP_REPLACE;
    case 0x1E02: return D3D11_STENCIL_OP_INCR_SAT;
    case 0x1E03: return D3D11_STENCIL_OP_DECR_SAT;
    case 0x150A: return D3D11_STENCIL_OP_INVERT;
    case 0x8507: return D3D11_STENCIL_OP_INCR;
    case 0x8508: return D3D11_STENCIL_OP_DECR;
    default:     return D3D11_STENCIL_OP_KEEP;
    }
}
struct DepthStencilKey {
    uint32_t depthFunc;
    uint32_t stencilFunc, stencilMask, stencilFuncMask;
    uint32_t opFail, opZFail, opZPass;
    bool depthWrite, depthEnable, stencilEnable;
    bool operator==(const DepthStencilKey& o) const noexcept {
        return depthFunc==o.depthFunc && stencilFunc==o.stencilFunc &&
               stencilMask==o.stencilMask && stencilFuncMask==o.stencilFuncMask &&
               opFail==o.opFail && opZFail==o.opZFail && opZPass==o.opZPass &&
               depthWrite==o.depthWrite && depthEnable==o.depthEnable &&
               stencilEnable==o.stencilEnable;
    }
};
struct DepthStencilKeyHash {
    size_t operator()(const DepthStencilKey& k) const noexcept {
        size_t h = std::hash<uint32_t>()(k.depthFunc);
        h ^= std::hash<uint32_t>()(k.stencilFunc)  + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<uint32_t>()(k.stencilMask)  + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<uint32_t>()(k.opFail)        + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<uint32_t>()(k.opZFail)       + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<uint32_t>()(k.opZPass)       + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<bool>()(k.depthWrite)        + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<bool>()(k.depthEnable)       + 0x9e3779b9 + (h<<6) + (h>>2);
        h ^= std::hash<bool>()(k.stencilEnable)     + 0x9e3779b9 + (h<<6) + (h>>2);
        return h;
    }
};
static ID3D11DepthStencilState* GetOrCreateDepthState(uint32_t nvFunc,
                                                      bool depthWrite,
                                                      bool depthEnable,
                                                      bool stencilEnable,
                                                      uint32_t stencilFunc,
                                                      uint32_t stencilMask,
                                                      uint32_t stencilFuncMask,
                                                      uint32_t opFail,
                                                      uint32_t opZFail,
                                                      uint32_t opZPass)
{
    static std::unordered_map<DepthStencilKey, ID3D11DepthStencilState*, DepthStencilKeyHash> s_cache;
    DepthStencilKey key { nvFunc, stencilFunc, stencilMask, stencilFuncMask,
                          opFail, opZFail, opZPass, depthWrite, depthEnable, stencilEnable };
    auto it = s_cache.find(key);
    if (it != s_cache.end()) return it->second;

    D3D11_DEPTH_STENCIL_DESC d = {};
    d.DepthEnable    = depthEnable ? TRUE : FALSE;
    d.DepthWriteMask = depthWrite  ? D3D11_DEPTH_WRITE_MASK_ALL
                                   : D3D11_DEPTH_WRITE_MASK_ZERO;
    d.DepthFunc      = NvDepthFuncToD3D11(nvFunc);
    d.StencilEnable  = stencilEnable ? TRUE : FALSE;
    d.StencilReadMask  = (UINT8)(stencilFuncMask & 0xFF);
    d.StencilWriteMask = (UINT8)(stencilMask & 0xFF);
    D3D11_DEPTH_STENCILOP_DESC sop;
    sop.StencilFailOp      = NvStencilOpToD3D11(opFail);
    sop.StencilDepthFailOp = NvStencilOpToD3D11(opZFail);
    sop.StencilPassOp      = NvStencilOpToD3D11(opZPass);
    sop.StencilFunc        = NvDepthFuncToD3D11(stencilFunc);
    d.FrontFace = sop;
    d.BackFace  = sop; // NV2A single-sided stencil; back=front
    ID3D11DepthStencilState* dss = nullptr;
    if (g_d3d11.device && SUCCEEDED(g_d3d11.device->CreateDepthStencilState(&d, &dss))) {
        s_cache.emplace(key, dss);
        return dss;
    }
    return depthEnable ? g_d3d11.dssOn : g_d3d11.dssOff;
}

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

static void EnsureScratchTexture(uint32_t w, uint32_t h, DXGI_FORMAT fmt) {
    if (g_d3d11.scratchTex && g_d3d11.scratchW == w && g_d3d11.scratchH == h && g_d3d11.scratchFmt == fmt)
        return;
    if (g_d3d11.scratchSRV) { g_d3d11.scratchSRV->Release(); g_d3d11.scratchSRV = nullptr; }
    if (g_d3d11.scratchTex) { g_d3d11.scratchTex->Release(); g_d3d11.scratchTex = nullptr; }
    
    D3D11_TEXTURE2D_DESC td = {};
    td.Width = w;
    td.Height = h;
    td.MipLevels = 1;
    td.ArraySize = 1;
    td.Format = fmt;
    td.SampleDesc.Count = 1;
    td.Usage = D3D11_USAGE_DEFAULT;
    td.BindFlags = D3D11_BIND_SHADER_RESOURCE;
    
    if (SUCCEEDED(g_d3d11.device->CreateTexture2D(&td, nullptr, &g_d3d11.scratchTex))) {
        g_d3d11.device->CreateShaderResourceView(g_d3d11.scratchTex, nullptr, &g_d3d11.scratchSRV);
        g_d3d11.scratchW = w;
        g_d3d11.scratchH = h;
        g_d3d11.scratchFmt = fmt;
        SetD3DName(g_d3d11.scratchTex, "B3_ScratchTex_InPlaceRT");
    }
}

// Bind a translated programmable PS for use from the 2D batch path.
// Uploads the live psC[0..15] from the RS shadow + final-combiner constants
// (psC[16/17]) into cbPS, binds tps->ps, then resolves up to 4 texture
// stages from kDeviceAddr+0x0B00..0x0B0C with NV2A push-buffer fallback.
// Stages that the PS samples but cannot be resolved are bound as a null
// SRV (D3D11 reads return zero — which is the correct semantics for a
// post-FX shader whose source RTs the game intentionally unbound).
//
// Caller is responsible for setting VS/IL/topology/blend/depth/raster/VB.
static bool BindTranslatedPSFor2D(uint8_t* base, TranslatedPS* tps)
{
    if (!tps || !tps->ps || !g_d3d11.cbPS) return false;

    constexpr uint32_t kRSShadowBase  = 0x35FB58;
    constexpr uint32_t kRWPendingBase = 0x75D4A0;
    constexpr uint32_t kPSConstRsIdx  = 10;
    for (uint32_t i = 0; i < 16; ++i) {
        uint32_t rs = kPSConstRsIdx + i;
        uint32_t v = 0;
        if (rs < kHLERenderStateCount) v = g_hleRenderStateCache[rs];
        if (v == 0) v = X86_MEM_READ_u32(base, kRSShadowBase + rs * 4);
        if (v == 0) v = X86_MEM_READ_u32(base, kRWPendingBase + rs * 4);
        
        // Guard against clobbering constants cleanly set by SetPixelShaderConstant
        if (v != 0 && !(g_pshConstantsDirty & (1u << i))) {
            g_pshConstants[i][0] = ((v >> 16) & 0xFF) / 255.0f;
            g_pshConstants[i][1] = ((v >>  8) & 0xFF) / 255.0f;
            g_pshConstants[i][2] = ((v >>  0) & 0xFF) / 255.0f;
            g_pshConstants[i][3] = ((v >> 24) & 0xFF) / 255.0f;
            g_pshConstantsDirty |= (1u << i);
        }
    }

    float psStage[32 * 4] = {};
    std::memcpy(psStage, &g_pshConstants[0][0], 16 * 4 * sizeof(float));

    uint32_t fcArgb[2] = { tps->bakedFc0, tps->bakedFc1 };
    if (g_psFinalCombinerConst[0] != 0) fcArgb[0] = g_psFinalCombinerConst[0];
    if (g_psFinalCombinerConst[1] != 0) fcArgb[1] = g_psFinalCombinerConst[1];
    for (int k = 0; k < 2; ++k) {
        uint32_t rs = 26u + (uint32_t)k;
        if (rs < kHLERenderStateCount) {
            uint32_t v = g_hleRenderStateCache[rs];
            if (v != 0) fcArgb[k] = v;
        }
    }
    for (int k = 0; k < 2; ++k) {
        float* dst = psStage + (16 + k) * 4;
        uint32_t v = fcArgb[k];
        dst[0] = ((v >> 16) & 0xFF) / 255.0f;
        dst[1] = ((v >>  8) & 0xFF) / 255.0f;
        dst[2] = ((v >>  0) & 0xFF) / 255.0f;
        dst[3] = ((v >> 24) & 0xFF) / 255.0f;
    }

    D3D11_MAPPED_SUBRESOURCE mr{};
    if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cbPS, 0,
            D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
        std::memcpy(mr.pData, psStage, sizeof(psStage));
        g_d3d11.context->Unmap(g_d3d11.cbPS, 0);
    }
    SC_PSCB0(g_d3d11.cbPS);
    SC_PS(tps->ps);

    ID3D11ShaderResourceView* srvs[4]  = {};
    ID3D11SamplerState*       samps[4] = {};

    // Diagnostic: log live vs snapshot texture addresses for the blur PSes
    static bool s_bindDiagDone[2] = {};
    {
        int psSlot = (g_currentPSHandle == 0x00900000u) ? 0 : (g_currentPSHandle == 0x00901000u) ? 1 : -1;
        if (psSlot >= 0 && !s_bindDiagDone[psSlot]) {
            s_bindDiagDone[psSlot] = true;
            for (unsigned s = 0; s < 4; ++s) {
                uint32_t liveA = base ? X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + s * 4) : 0;
                uint32_t snapA = g_psTexHandleSnapshot[s];
                uint32_t usedA = (s == 0) ? (liveA ? liveA : snapA) : (snapA ? snapA : liveA);
                bool inParent  = g_d3d11.guestRTByParent.count(usedA) != 0;
                fprintf(stderr, "[BIND-TPS] PS=0x%08X stage=%u snap=0x%08X live=0x%08X used=0x%08X inParent=%d src=%d\n",
                        g_currentPSHandle, s, snapA, liveA, usedA, (int)inParent, g_texBoundSource[s]);
            }
        }
    }

    for (unsigned s = 0; s < 4; ++s) {
        ID3D11ShaderResourceView* stageSrv = nullptr;
        if (tps->usesStage[s]) {
            // The game sets ALL texture stages to the primary texture just before
            // the draw (clobbering stages 1+). Stage 0 live is correct (primary
            // texture); stages 1+ must come from the snapshot captured at
            // SetPixelShader time (where secondary textures were still correct).
            uint32_t liveAddr = base ? X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + s * 4) : 0;
            uint32_t addr;
            if (s == 0)
                addr = liveAddr ? liveAddr : g_psTexHandleSnapshot[0];
            else
                addr = g_psTexHandleSnapshot[s] ? g_psTexHandleSnapshot[s] : liveAddr;
            stageSrv = ResolveShaderResourceView(base, s, addr);
        }
        srvs[s]  = stageSrv;
        // Bloom chain downsampling passes use UV coordinates that exceed [0,1] and
        // expect CLAMP semantics (the Xbox NV2A sampler is set to CLAMP for these stages).
        // All other translated PSes keep WRAP.
        samps[s] = (g_currentPSHandle == 0x008FC000u ||
                    g_currentPSHandle == 0x008FD000u ||
                    g_currentPSHandle == 0x008FE000u ||
                    g_currentPSHandle == 0x008FF000u)
                   ? g_d3d11.samplerLinear
                   : g_d3d11.samplerWrap;
    }

    if (g_d3d11.activeGuestRT) {
        GuestRT* art = g_d3d11.activeGuestRT;
        uint32_t aMip = g_d3d11.activeGuestRTMip;
        ID3D11ShaderResourceView* sub = (aMip < art->srvSrcExclMip.size()) ? art->srvSrcExclMip[aMip] : nullptr;
        for (unsigned s = 0; s < 4; ++s) {
            if (srvs[s] == art->srv) {
                if (sub) {
                    srvs[s] = sub;
                } else {
                    // aMip==0: srvSrcExclMip[0] is always null (no lower mips to exclude).
                    // Copy mip 0 of this GuestRT to scratch so the blur shader reads what
                    // the previous pass (e.g. radial blur) just rendered into this surface.
                    EnsureScratchTexture(art->baseW, art->baseH, art->dxgiFormat);
                    if (g_d3d11.scratchTex) {
                        g_d3d11.context->CopySubresourceRegion(
                            g_d3d11.scratchTex, 0, 0, 0, 0,
                            art->texture, 0, nullptr);
                        srvs[s] = g_d3d11.scratchSRV;
                    } else {
                        srvs[s] = nullptr;
                    }
                }
            } else if (aMip < art->srvPerMip.size() && srvs[s] == art->srvPerMip[aMip]) {
                // Exact-overlap prevention for Blur passes sampling Mip X and writing Mip X 
                uint32_t mw = std::max<uint32_t>(1, art->baseW >> aMip);
                uint32_t mh = std::max<uint32_t>(1, art->baseH >> aMip);
                EnsureScratchTexture(mw, mh, art->dxgiFormat);
                if (g_d3d11.scratchTex) {
                    g_d3d11.context->CopySubresourceRegion(
                        g_d3d11.scratchTex, 0, 0, 0, 0,
                        art->texture, aMip, nullptr);
                    srvs[s] = g_d3d11.scratchSRV;
                } else {
                    srvs[s] = nullptr;
                }
            }
        }
    } else {
        // Active RT is the Back Buffer
        for (unsigned s = 0; s < 4; ++s) {
            if (srvs[s] == g_d3d11.sceneSRV) {
                EnsureScratchTexture(g_d3d11.width, g_d3d11.height, g_d3d11.sceneFormat);
                if (g_d3d11.scratchTex) {
                    g_d3d11.context->CopySubresourceRegion(
                        g_d3d11.scratchTex, 0, 0, 0, 0,
                        g_d3d11.backBufferTex, 0, nullptr);
                    srvs[s] = g_d3d11.scratchSRV;
                } else {
                    srvs[s] = nullptr;
                }
            }
        }
    }

    SC_PSSRVs(4, srvs);
    SC_PSSamplers(4, samps);

    return true;
}

// Draw a batch of Vtx2D vertices directly to the D3D11 back buffer.
// topo:        D3D11 primitive topology
// srv:         texture SRV (nullptr = untextured)
// isAlphaOnly: true for A8/L8 font textures → use psAlpha + force alpha blend
static const char* g_b2dCallerTag = "?";
// Guest base pointer set by the caller right before HLE_DrawBatch2D so the
// translated-PS fallback path (BindTranslatedPSFor2D) can read texture
// pointers from kDeviceAddr+0x0B00..0x0B0C without changing the signature
// of HLE_DrawBatch2D. nullptr disables the translated-PS fallback.
static uint8_t* g_b2dBase = nullptr;

static void HLE_DrawBatch2D(const Vtx2D*              verts,
                             uint32_t                  nverts,
                             D3D_PRIMITIVE_TOPOLOGY    topo,
                             ID3D11ShaderResourceView* srv,
                             bool                      isAlphaOnly,
                             const Vtx2DEx*            exVerts  = nullptr,
                             uint32_t                  nexVerts = 0)
{
    if (!g_d3d11.initialized || !g_d3d11.pipelineReady || nverts == 0) return;

    // Decide whether to use the extended (multi-UV) vertex path.
    // Only used when a translated PS is active AND valid extended vertices are provided.
    TranslatedPS* tpsCheck = nullptr;
    if (g_currentPSHandle && g_b2dBase) {
        auto it = g_psByHandle.find(g_currentPSHandle);
        if (it != g_psByHandle.end() && it->second.ps) tpsCheck = &it->second;
    }
    const bool useExPath = (exVerts != nullptr && nexVerts > 0 &&
                            tpsCheck != nullptr &&
                            g_d3d11.vs2DEx && g_d3d11.il2DEx);
    const uint32_t drawVerts  = useExPath ? nexVerts : nverts;
    const uint32_t vbNeeded   = useExPath
                                    ? nexVerts * (uint32_t)sizeof(Vtx2DEx)
                                    : nverts   * (uint32_t)sizeof(Vtx2D);

    EnsureDynVB(vbNeeded);
    if (!g_d3d11.dynamicVB) return;

    // Upload vertices (extended or standard path)
    D3D11_MAPPED_SUBRESOURCE mr = {};
    if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicVB, 0, D3D11_MAP_WRITE_DISCARD, 0, &mr)))
        return;
    if (useExPath)
        memcpy(mr.pData, exVerts, nexVerts * sizeof(Vtx2DEx));
    else
        memcpy(mr.pData, verts, nverts * sizeof(Vtx2D));
    g_d3d11.context->Unmap(g_d3d11.dynamicVB, 0);

    uint32_t vpX = (g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + kDeviceViewport + 0) : 0);
    uint32_t vpY = (g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + kDeviceViewport + 4) : 0);
    uint32_t vpW = (g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + kDeviceViewport + 8) : 0);
    uint32_t vpH = (g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + kDeviceViewport + 12) : 0);

    if (vpW == 0) vpW = g_d3d11.width;
    if (vpH == 0) vpH = g_d3d11.height;

    uint32_t guestVpX = vpX, guestVpY = vpY, guestVpW = vpW, guestVpH = vpH;
    // When the guest viewport is unset (all zeros), infer dimensions from
    // the active guest render target so the D3D11 RSSetViewports call covers
    // the full RT area.  The CB2D transform is computed separately from vertex
    // data in the CB2D update block below.
    if (guestVpW == 0 && guestVpH == 0 && g_d3d11.activeGuestRT) {
        guestVpW = g_d3d11.activeGuestRT->baseW;
        guestVpH = g_d3d11.activeGuestRT->baseH;
        guestVpX = 0;
        guestVpY = 0;
    }

    {
        uint32_t surfAddr = g_d3d11.currentRTSurf;
        if (surfAddr == 0)
            surfAddr = (g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + kDeviceRenderTarget) : 0);
        bool boundGuestRT = false;
        if (surfAddr != 0) {
            GuestRT* rt = nullptr;
            uint32_t mip = 0;
            
            auto it = g_d3d11.guestRTBySurface.find(surfAddr);
            if (it != g_d3d11.guestRTBySurface.end()) {
                rt = it->second.rt;
                uint32_t pParent = g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, surfAddr + 0x14) : 0;
                if (!rt && pParent && g_b2dBase) {
                    rt = EnsureGuestRT(g_b2dBase, pParent);
                    if (rt) it->second.rt = rt;
                }
                if (rt && g_b2dBase) {
                    mip = GetMipFromSurface(g_b2dBase, surfAddr, rt);
                    it->second.mip = mip;
                }
            } else if (g_b2dBase) {
                uint32_t pParent = X86_MEM_READ_u32(g_b2dBase, surfAddr + 0x14);
                if (pParent != 0) {
                    rt = EnsureGuestRT(g_b2dBase, pParent);
                }
                // Fallback: treat surfAddr itself as the texture header.
                // Burnout 3's bloom pass calls SetRenderTarget with texture
                // object addresses directly (0x4D6A18, 0x4D6A30, 0x4D6A48)
                // rather than GetSurfaceLevel surfaces, so pParent is 0 or
                // garbage.  Only try this for game-side addresses (below the
                // ContigAlloc region at 0x19000000); back-buffer surfaces from
                // CreateDevice live at 0x19000000+ and must NOT be treated as
                // texture headers.
                if (!rt && surfAddr < 0x19000000u) {
                    static int s_fbLog = 0;
                    if (s_fbLog < 16) {
                        uint32_t fb_fmt  = X86_MEM_READ_u32(g_b2dBase, surfAddr + 12);
                        uint32_t fb_size = X86_MEM_READ_u32(g_b2dBase, surfAddr + 16);
                        uint32_t fb_data = X86_MEM_READ_u32(g_b2dBase, surfAddr + 4);
                        fprintf(stderr, "[D3D11] RT-self-hdr fallback surfAddr=0x%08X pParent=0x%08X data=0x%08X fmt=0x%08X size=0x%08X\n",
                                surfAddr, pParent, fb_data, fb_fmt, fb_size);
                        ++s_fbLog;
                    }
                    rt = EnsureGuestRT(g_b2dBase, surfAddr);
                }
                if (rt) {
                    mip = GetMipFromSurface(g_b2dBase, surfAddr, rt);
                    SurfaceRTBind b;
                    b.rt = rt;
                    b.mip = mip;
                    b.parent = pParent;
                    g_d3d11.guestRTBySurface[surfAddr] = b;
                }
            }

            if (rt && mip < rt->rtvPerMip.size() && rt->rtvPerMip[mip]) {
                ID3D11ShaderResourceView* nullSRVs[4] = {};
                SC_PSSRVs(4, nullSRVs);
                g_d3d11.context->OMSetRenderTargets(1, &rt->rtvPerMip[mip], nullptr);
                g_d3d11.activeGuestRT    = rt;
                g_d3d11.activeGuestRTMip = mip;
                boundGuestRT = true;
                
                // Allow guest viewport settings to map 1:1 with NDC dimensions organically.
            }
        }
        if (!boundGuestRT) {
            g_d3d11.context->OMSetRenderTargets(1, &g_d3d11.backBufferRTV, nullptr);
            g_d3d11.activeGuestRT = nullptr;
            g_d3d11.activeGuestRTMip = 0;
        }
    }

    // Rasterizer + viewport
    SC_Raster(g_d3d11.rsNoCull);
    {
        // D3D11 viewport must cover the full RT with positive dimensions.
        // Use the actual RT size when the guest viewport is unset.
        float rtW = (vpW > 0) ? static_cast<float>(vpW) : static_cast<float>(g_d3d11.width);
        float rtH = (vpH > 0) ? static_cast<float>(vpH) : static_cast<float>(g_d3d11.height);
        if (g_d3d11.activeGuestRT) {
            rtW = static_cast<float>(g_d3d11.activeGuestRT->baseW);
            rtH = static_cast<float>(g_d3d11.activeGuestRT->baseH);
        }
        D3D11_VIEWPORT vp11 = {};
        vp11.Width    = rtW;
        vp11.Height   = rtH;
        vp11.TopLeftX = static_cast<float>(vpX);
        // For ExPath draws (post-FX composites), expand symmetric Xbox letterbox
        // viewports to full screen.  The CB2D transform is derived from vertex data
        // (not the viewport), so the NDC range is already correct — expanding the
        // D3D11 viewport just maps that NDC range to the full screen instead of the
        // letterbox content rows.  Non-ExPath 2D draws keep the original viewport
        // because their CB2D IS derived from the viewport.
        if (useExPath && vpY > 0 && vpH + 2u * vpY == g_bbHeight)
            vp11.TopLeftY = 0.0f;
        else
            vp11.TopLeftY = static_cast<float>(vpY);
        vp11.MaxDepth = 1.0f;
        g_d3d11.context->RSSetViewports(1, &vp11);
    }

    // Update constant buffer with current screen size Using Guest's intended window space (not physical RT space)
    mr = {};
    if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cb2D, 0, D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
        float cbSizeX = static_cast<float>(guestVpW);
        float cbSizeY = static_cast<float>(guestVpH);
        float cbOffX  = static_cast<float>(guestVpX);
        float cbOffY  = static_cast<float>(guestVpY);

        // For ExPath draws (post-FX stride=52 quads), derive the correct Y
        // transform directly from the vertex positions. The Xbox NV2A may use a
        // non-standard viewport (e.g. centered Y where +Y=top) that doesn't
        // match our "screen-space from top-left" assumption.
        // Rule: if any vertex Y < 0, the coordinate system is center-origin
        // (max_y is screen-top → ndc=+1, min_y is screen-bottom → ndc=-1),
        // so we use off=max_y, size=min_y-max_y (negative, flipping the VS).
        // Otherwise it's normal screen-space: off=min_y, size=max_y-min_y.
        if (useExPath && nexVerts > 0 && exVerts != nullptr) {
            float minY = exVerts[0].y, maxY = exVerts[0].y;
            float minX = exVerts[0].x, maxX = exVerts[0].x;
            for (uint32_t vi = 1; vi < nexVerts; ++vi) {
                if (exVerts[vi].y < minY) minY = exVerts[vi].y;
                if (exVerts[vi].y > maxY) maxY = exVerts[vi].y;
                if (exVerts[vi].x < minX) minX = exVerts[vi].x;
                if (exVerts[vi].x > maxX) maxX = exVerts[vi].x;
            }
            // PS=0x00901000 is the blur composite drawn in centered coordinates
            // (+Y = up, 0 = screen centre).  The game may emit the composite as
            // a single quad (Y = +barH → -barH) or split into two half-quads
            // (Y = +barH → 0  and  Y = 0 → -barH).
            // For PS 0x00901000 (blur composite) we apply a fixed full-screen
            // mapping (not the Xbox letterbox-area mapping) so the composite
            // fills the entire screen.  The condition also catches split
            // half-quads (top: minY=0 maxY>0, bottom: minY<0 maxY=0).
            if (g_currentPSHandle == 0x00901000u &&
                (minY < 0.0f || maxY > 0.0f)) {
                // Centred composite (PS 0x00901000).  The game uses Y = ±barH
                // in centred coords (±Y = up/down from screen centre).  Map
                // the full ±barH range to the full screen so the composite
                // fills edge-to-edge, removing the Xbox letterbox bars.
                //
                // For any sub-quad layout (single ±barH, or split top/bottom):
                //   cbOffY  = barH       (Y = +barH → NDC = +1, screen top)
                //   cbSizeY = -2 * barH  (Y = -barH → NDC = -1, screen bottom)
                //
                // barH is derived from the vertex data so this is robust to
                // any bar height the game uses.
                const float barH = std::max(maxY, -minY);
                cbOffY  = barH;
                cbSizeY = -2.0f * barH;
                cbOffX  = minX;
                cbSizeX = maxX - minX;
            } else if (minY < 0.0f) {
                // Other centred/inverted draw (e.g. PS=0x00900000 blur accum):
                // max_y = top of screen.
                cbOffX  = minX;
                cbSizeX = maxX - minX;
                cbOffY  = maxY;
                cbSizeY = minY - maxY; // negative → flips VS Y direction
            } else {
                // Normal screen-space: min_y = top of screen.
                cbOffY  = minY;
                cbSizeY = (maxY > minY) ? (maxY - minY) : cbSizeY;
                cbOffX  = minX;
                cbSizeX = (maxX > minX) ? (maxX - minX) : cbSizeX;
            }
        }

        float* cb = static_cast<float*>(mr.pData);
        cb[0] = cbSizeX;
        cb[1] = cbSizeY;
        cb[2] = cbOffX;
        cb[3] = cbOffY;
        g_d3d11.context->Unmap(g_d3d11.cb2D, 0);
    }

    // If a programmable PS is active (post-FX path) we'll bind that
    // shader below — look it up early so we can also use the real NV2A
    // blend state. Without this, post-FX quads that the original Xbox
    // expects to alpha-blend or additively blend over the scene render
    // as opaque black/white when the LUTs/RTs sample as zero.
    TranslatedPS* tps = nullptr;
    if (g_currentPSHandle && g_b2dBase) {
        auto it = g_psByHandle.find(g_currentPSHandle);
        if (it != g_psByHandle.end() && it->second.ps) tps = &it->second;
    }

    // Blend state
    float bf[4] = { 1,1,1,1 };
    ID3D11BlendState* bs;
    if (tps) {
        bs = GetOrCreateBlendState(g_blendSrc, g_blendDst,
                                   g_alphaBlendEnabled,
                                   g_colorWriteMask,
                                   g_blendEquation);
    } else {
        bs = (g_alphaBlendEnabled || isAlphaOnly) ? g_d3d11.bsAlpha : g_d3d11.bsOpaque;
    }
    SC_BlendState(bs, bf, 0xFFFFFFFF);
    SC_DepthStencil(g_d3d11.dssOff, 0);

    //// Rasterizer + viewport
    //SC_Raster(g_d3d11.rsNoCull);
    //D3D11_VIEWPORT vp = {};
    //vp.Width    = static_cast<float>(g_d3d11.width);
    //vp.Height   = static_cast<float>(g_d3d11.height);
    //vp.MaxDepth = 1.0f;
    //g_d3d11.context->RSSetViewports(1, &vp);

    // Vertex shader + input layout + cbuffer
    if (useExPath) {
        SC_VS(g_d3d11.vs2DEx);
        SC_IL(g_d3d11.il2DEx);
    } else {
        SC_VS(g_d3d11.vs2D);
        SC_IL(g_d3d11.il2D);
    }
    SC_VSCB0(g_d3d11.cb2D);

    // Pixel shader selection.
    //
    // Prefer the game's translated programmable PS when one is bound. The
    // 2D path is also used by post-FX fullscreen quads (DrawVerticesUP)
    // whose game-side render target is a programmable PS — falling through
    // to psUntextured/psModulate would render the quad as solid white.
    // Stages whose source RTs the game intentionally unbinds resolve to
    // null SRVs (sampling returns 0), giving the same all-zero output the
    // original Xbox shader produces — typically alpha=0 ⇒ invisible.
    bool boundTPS = false;
    if (tps) {
        boundTPS = BindTranslatedPSFor2D(g_b2dBase, tps);
    }
    if (!boundTPS) {
        ID3D11PixelShader* ps;
        if (!srv)              ps = g_d3d11.psUntextured;
        else if (isAlphaOnly)  ps = g_d3d11.psAlpha;
        else                   ps = g_d3d11.psModulate;
        SC_PS(ps);

        if (srv) {
            // Hazard mitigation 
            if (g_d3d11.activeGuestRT && srv == g_d3d11.activeGuestRT->srv) {
                uint32_t aMip = g_d3d11.activeGuestRTMip;
                if (aMip < g_d3d11.activeGuestRT->srvSrcExclMip.size())
                    srv = g_d3d11.activeGuestRT->srvSrcExclMip[aMip];
                else
                    srv = nullptr;
            } else if (g_d3d11.activeGuestRT && g_d3d11.activeGuestRTMip < g_d3d11.activeGuestRT->srvPerMip.size() && srv == g_d3d11.activeGuestRT->srvPerMip[g_d3d11.activeGuestRTMip]) {
                GuestRT* art = g_d3d11.activeGuestRT;
                uint32_t aMip = g_d3d11.activeGuestRTMip;
                uint32_t mw = std::max<uint32_t>(1, art->baseW >> aMip);
                uint32_t mh = std::max<uint32_t>(1, art->baseH >> aMip);
                EnsureScratchTexture(mw, mh, art->dxgiFormat);
                if (g_d3d11.scratchTex) {
                    g_d3d11.context->CopySubresourceRegion(
                        g_d3d11.scratchTex, 0, 0, 0, 0,
                        art->texture, aMip, nullptr);
                    srv = g_d3d11.scratchSRV;
                } else {
                    srv = nullptr;
                }
            } else if (!g_d3d11.activeGuestRT && srv == g_d3d11.sceneSRV) {
                EnsureScratchTexture(g_d3d11.width, g_d3d11.height, g_d3d11.sceneFormat);
                if (g_d3d11.scratchTex) {
                    g_d3d11.context->CopySubresourceRegion(
                        g_d3d11.scratchTex, 0, 0, 0, 0,
                        g_d3d11.backBufferTex, 0, nullptr);
                    srv = g_d3d11.scratchSRV;
                } else {
                    srv = nullptr;
                }
            }

            ID3D11ShaderResourceView* one[1]   = { srv };
            ID3D11SamplerState*       samp1[1] = { g_d3d11.samplerLinear };
            SC_PSSRVs(1, one);
            SC_PSSamplers(1, samp1);
        }
    }

    // Vertex buffer
    UINT stride = useExPath ? (UINT)sizeof(Vtx2DEx) : (UINT)sizeof(Vtx2D), offset = 0;
    SC_VB(g_d3d11.dynamicVB, stride, offset);
    SC_Topology(topo);
    // {
    //     wchar_t _m[192];
    //     const wchar_t* topoName = (topo == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST)  ? L"TRILIST" :
    //                               (topo == D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP) ? L"TRISTRIP" :
    //                               (topo == D3D11_PRIMITIVE_TOPOLOGY_LINELIST)      ? L"LINELIST" : L"OTHER";
    //     uint32_t tex0 = g_b2dBase ? X86_MEM_READ_u32(g_b2dBase, kDeviceAddr + 0x0B00) : 0;
    //     swprintf(_m, 192, L"f=%u d=%u RT=%08X IM/%s %uv tex=%08X srv=%s",
    //              g_ppFrame, g_drawCallCount, g_d3d11.currentRTSurf, topoName, drawVerts,
    //              tex0, srv ? L"Y" : L"N");
    //     RdocMark(_m);
    // }
    g_d3d11.context->Draw(drawVerts, 0);

    // Unbind SRV to avoid hazards on next frame
    if (boundTPS) {
        ID3D11ShaderResourceView* nullSRVs[4] = {};
        SC_PSSRVs(4, nullSRVs);
    } else if (srv) {
        ID3D11ShaderResourceView* nullSRV[1] = { nullptr };
        SC_PSSRVs(1, nullSRV);
    }
}

// ============================================================================
// 3D pipeline — programmable VS with NV2A constant MVP
// ============================================================================
//

// Bind the active render target (back buffer or guest RT-to-texture) and
// matching viewport. Returns true if a guest RT was bound.
static bool BindActiveRenderTarget(uint8_t* base, bool wantDepth)
{
    uint32_t surfAddr = g_d3d11.currentRTSurf;
    if (surfAddr == 0)
        surfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);

    // Read the Guest's explicitly requested viewport
    uint32_t vpX = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 0);
    uint32_t vpY = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 4);
    uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
    uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);

    if (surfAddr != 0) {
        GuestRT* rt = nullptr;
        uint32_t mip = 0;
        
        auto it = g_d3d11.guestRTBySurface.find(surfAddr);
        if (it != g_d3d11.guestRTBySurface.end()) {
            rt = it->second.rt;
            uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
            if (!rt && pParent != 0) {
                rt = EnsureGuestRT(base, pParent);
                if (rt) it->second.rt = rt;
            }
            if (rt) {
                mip = GetMipFromSurface(base, surfAddr, rt);
                it->second.mip = mip;
            }
        } else {
            uint32_t pParent = X86_MEM_READ_u32(base, surfAddr + 0x14);
            if (pParent != 0) {
                rt = EnsureGuestRT(base, pParent);
                if (rt) {
                    mip = GetMipFromSurface(base, surfAddr, rt);
                    SurfaceRTBind b;
                    b.rt = rt;
                    b.mip = mip;
                    b.parent = pParent;
                    g_d3d11.guestRTBySurface[surfAddr] = b;
                }
            }
        }

        if (rt && mip < rt->rtvPerMip.size() && rt->rtvPerMip[mip]) {
            if (PpDebug())
                fprintf(stderr, "[PP] f=%u BindGuestRT surf=0x%08X mip=%u rtvSz=%u\n",
                        g_ppFrame, surfAddr, mip, (unsigned)rt->rtvPerMip.size());
            ID3D11ShaderResourceView* nullSRVs[4] = { nullptr, nullptr, nullptr, nullptr };
            SC_PSSRVs(4, nullSRVs);
            ID3D11DepthStencilView* guestDSV = (wantDepth && mip < rt->dsvPerMip.size())
                                               ? rt->dsvPerMip[mip] : nullptr;
            g_d3d11.context->OMSetRenderTargets(1, &rt->rtvPerMip[mip], guestDSV);
            g_d3d11.activeGuestRT    = rt;
            g_d3d11.activeGuestRTMip = mip;
            
            D3D11_VIEWPORT vp = {};
            vp.Width    = vpW > 0 ? static_cast<float>(vpW) : static_cast<float>(g_d3d11.width);
            // Expand symmetric Xbox letterbox viewport so the D3D11 rasterizer covers
            // the full screen.  c[58]/c[59] (fed from device memory) keep the original
            // Xbox values, so the VS epilogue maps scene vertices to NDC ±1 as expected.
            // The expanded D3D11 viewport then maps NDC ±1 to rows 0..screenH.
            // Guard: only expand when the RT is tall enough (e.g. the 640×480 scene RT,
            // not small 128×128 reflection/shadow map RTs which would clip content).
            if (vpY > 0 && vpH + 2u * vpY == g_bbHeight && rt->baseH >= g_bbHeight)
                { vp.Height = static_cast<float>(g_bbHeight); vp.TopLeftY = 0.0f; }
            else
                { vp.Height = vpH > 0 ? static_cast<float>(vpH) : static_cast<float>(g_d3d11.height);
                  vp.TopLeftY = static_cast<float>(vpY); }
            vp.TopLeftX = static_cast<float>(vpX);
            vp.MaxDepth = 1.0f;
            g_d3d11.context->RSSetViewports(1, &vp);
            return true;
        }
    }

    if (PpDebug())
        fprintf(stderr, "[PP] f=%u BindBackBuf surf=0x%08X\n",
                g_ppFrame, surfAddr);
    g_d3d11.context->OMSetRenderTargets(1, &g_d3d11.backBufferRTV,
                                        wantDepth ? g_d3d11.depthDSV : nullptr);
    g_d3d11.activeGuestRT    = nullptr;
    g_d3d11.activeGuestRTMip = 0;

    D3D11_VIEWPORT vp = {};
    vp.Width    = vpW > 0 ? static_cast<float>(vpW) : static_cast<float>(g_d3d11.width);
    if (vpY > 0 && vpH + 2u * vpY == g_bbHeight)
        { vp.Height = static_cast<float>(g_bbHeight); vp.TopLeftY = 0.0f; }
    else
        { vp.Height = vpH > 0 ? static_cast<float>(vpH) : static_cast<float>(g_d3d11.height);
          vp.TopLeftY = static_cast<float>(vpY); }
    vp.TopLeftX = static_cast<float>(vpX);
    vp.MaxDepth = 1.0f;
    g_d3d11.context->RSSetViewports(1, &vp);
    return false;
}

// Dispatcher invoked from D3DDevice_DrawVertices / DrawIndexedVertices when
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

    // Assign this draw a stable index BEFORE any early-outs that would make
    // scene_dump.obj drop the same draw. Using a counter that increments for
    // every HLE_Draw3D call keeps the OBJ `o drawNNN_...` labels aligned with
    // the `[D3D] #NNN ...` log lines.
    const uint32_t drawIdx = g_draw3DIndex++;
    if (PpDebug()) ++g_ppDrawsSinceRT;

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
    //
    // Cache the maxIdx scan result keyed on (pIndexData, indexCount). The
    // scan does an O(N) loop over guest IB memory and is hot for indexed
    // draws — when the same index buffer is reused across draw calls
    // (extremely common in Burnout 3), recomputing it every time burns CPU
    // for no reason.
    uint32_t vcount = vertexCount;
    if (indexCount) {
        static uint32_t s_lastIBPtr   = 0;
        static uint32_t s_lastIBCount = 0;
        static uint32_t s_lastIBVCount = 0;
        if (s_lastIBPtr == pIndexData && s_lastIBCount == indexCount) {
            vcount = s_lastIBVCount;
        } else {
            uint32_t maxIdx = 0;
            for (uint32_t i = 0; i < indexCount; i++) {
                uint16_t ix = X86_MEM_READ_u16(base, pIndexData + i * 2);
                if (ix > maxIdx) maxIdx = ix;
            }
            vcount = maxIdx + 1;
            s_lastIBPtr    = pIndexData;
            s_lastIBCount  = indexCount;
            s_lastIBVCount = vcount;
        }
    }
    if (vcount == 0) return;
    uint32_t vbBytes = vcount * stride;
    if (vbBytes == 0) return;

    // Upload vertex data verbatim into the dynamic VB.
    //
    // Skip the Map(DISCARD)+memcpy if the same source range was uploaded on
    // the previous draw and the underlying dynamic-VB allocation hasn't been
    // recreated by EnsureDynVB. Map(DISCARD) forces a buffer rename in the
    // driver and is one of the most expensive per-draw ops; runs of draws
    // sharing the same VB (typical for instanced-looking sets like wheels,
    // lights, body panels) collapse to a single upload.
    EnsureDynVB(vbBytes);
    if (!g_d3d11.dynamicVB) return;
    {
        static ID3D11Buffer* s_lastVBBuf  = nullptr;
        static uint32_t      s_lastVBData = 0;
        static uint32_t      s_lastVBSize = 0;
        bool needUpload = (g_d3d11.dynamicVB != s_lastVBBuf)
                       || (vbData            != s_lastVBData)
                       || (vbBytes           != s_lastVBSize);
        if (needUpload) {
            D3D11_MAPPED_SUBRESOURCE mr = {};
            if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicVB, 0,
                                             D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
            memcpy(mr.pData, base + vbData, vbBytes);
            g_d3d11.context->Unmap(g_d3d11.dynamicVB, 0);
            s_lastVBBuf  = g_d3d11.dynamicVB;
            s_lastVBData = vbData;
            s_lastVBSize = vbBytes;
        }
    }

    // Upload indices (if indexed). Same skip pattern as the VB upload above:
    // when consecutive draws use the same source IB range, avoid the second
    // Map(DISCARD) per draw.
    if (indexCount) {
        uint32_t ibBytes = indexCount * 2;
        EnsureDynIB(ibBytes);
        if (!g_d3d11.dynamicIB) return;
        static ID3D11Buffer* s_lastIBBuf = nullptr;
        static uint32_t      s_lastIBSrc = 0;
        static uint32_t      s_lastIBLen = 0;
        bool needIBUpload = (g_d3d11.dynamicIB != s_lastIBBuf)
                         || (pIndexData        != s_lastIBSrc)
                         || (ibBytes           != s_lastIBLen);
        if (needIBUpload) {
            D3D11_MAPPED_SUBRESOURCE mr = {};
            if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicIB, 0,
                                             D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
            memcpy(mr.pData, base + pIndexData, ibBytes);
            g_d3d11.context->Unmap(g_d3d11.dynamicIB, 0);
            s_lastIBBuf = g_d3d11.dynamicIB;
            s_lastIBSrc = pIndexData;
            s_lastIBLen = ibBytes;
        }
    }

    // Upload NV2A vertex constants. For any slot that is still all-zero in
    // the host cache, fall back to the guest shadow (so code that wrote to
    // 0x35FDF8 directly still has effect).
    //
    // Optimisation: we stage the 192 × float4 payload into a per-frame static
    // buffer first, run all the fix-ups / diagnostics on that staging buffer,
    // then memcmp against the last uploaded contents. If the bits are
    // identical (typical for runs of draws that share a world matrix and
    // material), we skip Map(DISCARD) entirely. Map(DISCARD) forces the
    // D3D11 driver to allocate/rename a new buffer chunk and is one of the
    // single most expensive driver-side operations on the per-draw hot path.
    {
        static float    s_stage[192 * 4] = {};
        static float    s_lastUploaded[192 * 4] = {};
        static bool     s_lastValid = false;
        static uint64_t s_uploadCalls = 0;
        static uint64_t s_uploadSkipped = 0;

        float* dst = s_stage;
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

        // Force c[58]/c[59] to match our render viewport. The Xbox D3D runtime
        // writes these via SetViewport (through the NV2A push buffer); we don't
        // emulate that path, so without this override NV2A shaders that fold
        // the viewport transform into oPos (`oPos = clip * c[58] / w + c[59]`)
        // would collapse every vertex to the origin or NaN. Backing them with
        // real viewport scale/offset, and then inverting that transform in the
        // translated HLSL epilogue, restores clip-space output.
        {
            uint32_t vpX = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 0);
            uint32_t vpY = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 4);
            uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
            uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
            if (vpW == 0) vpW = g_d3d11.width;
            if (vpH == 0) vpH = g_d3d11.height;
            
            float fVpW = static_cast<float>(vpW);
            float fVpH = static_cast<float>(vpH);
            float fVpX = static_cast<float>(vpX);
            float fVpY = static_cast<float>(vpY);

            dst[58*4+0] = fVpW * 0.5f;         dst[58*4+1] = -fVpH * 0.5f;
            dst[58*4+2] = 1.0f;                dst[58*4+3] = 0.0f;
            dst[59*4+0] = fVpX + fVpW * 0.5f;  dst[59*4+1] = fVpY + fVpH * 0.5f;
            dst[59*4+2] = 0.0f;                dst[59*4+3] = 1.0f;
        }

        // Hash-skip: if the staged buffer is bit-identical to the last one
        // we uploaded, no need to touch the GPU. memcmp is faster than a
        // streaming hash for 3072 bytes (12 cachelines, sequential access).
        ++s_uploadCalls;
        bool needUpload = !s_lastValid
            || std::memcmp(s_stage, s_lastUploaded, sizeof(s_stage)) != 0;
        if (needUpload) {
            D3D11_MAPPED_SUBRESOURCE cmr{};
            if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cb3D, 0,
                    D3D11_MAP_WRITE_DISCARD, 0, &cmr))) {
                std::memcpy(cmr.pData, s_stage, sizeof(s_stage));
                g_d3d11.context->Unmap(g_d3d11.cb3D, 0);
                std::memcpy(s_lastUploaded, s_stage, sizeof(s_stage));
                s_lastValid = true;
            }
        } else {
            ++s_uploadSkipped;
        }

        // Periodic stats (gated by B3_DEBUG_SC_STATS so it shares a switch
        // with the state-cache stats). Logs upload skip rate every 256 frames.
        if (g_dbg.scStats) {
            static uint32_t s_frames = 0;
            static uint64_t s_lastTotal = 0, s_lastSkipped = 0;
            // Frame boundary detection via swap counter — increments once per
            // Present in D3DDevice_Swap. We snapshot every time it advances.
            static uint32_t s_lastSwap = 0;
            if (g_swapCount != s_lastSwap) {
                s_lastSwap = g_swapCount;
                if (++s_frames % 256 == 0) {
                    uint64_t dt = s_uploadCalls   - s_lastTotal;
                    uint64_t ds = s_uploadSkipped - s_lastSkipped;
                    s_lastTotal   = s_uploadCalls;
                    s_lastSkipped = s_uploadSkipped;
                    if (dt) {
                        fprintf(stderr,
                            "[CB] VS last 256 frames: %llu draws, %llu CB uploads skipped (%.1f%%)\n",
                            (unsigned long long)dt, (unsigned long long)ds,
                            (double)ds * 100.0 / (double)dt);
                    }
                }
            }
        }
    }

    // Topology mapping.
    D3D_PRIMITIVE_TOPOLOGY topo;
    std::vector<uint16_t> fanOrQuadIdx; // used for expansion
    bool useExpanded = false;

    switch (primType) {
    case NV2A_PRIM_POINTS:    topo = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST; break;
    case NV2A_PRIM_LINES:     topo = D3D11_PRIMITIVE_TOPOLOGY_LINELIST; break;
    case NV2A_PRIM_LINESTRIP: topo = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP; break;
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
    case NV2A_PRIM_QUADSTRIP: {
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        useExpanded = true;
        if (indexCount) {
            for (uint32_t i = 0; i + 3 < indexCount; i += 2) {
                uint16_t a = X86_MEM_READ_u16(base, pIndexData + (i+0) * 2);
                uint16_t b = X86_MEM_READ_u16(base, pIndexData + (i+1) * 2);
                uint16_t c = X86_MEM_READ_u16(base, pIndexData + (i+2) * 2);
                uint16_t d = X86_MEM_READ_u16(base, pIndexData + (i+3) * 2);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(c);
                fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(d); fanOrQuadIdx.push_back(c);
            }
        } else {
            for (uint32_t i = 0; i + 3 < vertexCount; i += 2) {
                uint16_t a = static_cast<uint16_t>(startVertex + i + 0);
                uint16_t b = static_cast<uint16_t>(startVertex + i + 1);
                uint16_t c = static_cast<uint16_t>(startVertex + i + 2);
                uint16_t d = static_cast<uint16_t>(startVertex + i + 3);
                fanOrQuadIdx.push_back(a); fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(c);
                fanOrQuadIdx.push_back(b); fanOrQuadIdx.push_back(d); fanOrQuadIdx.push_back(c);
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
        D3D11_MAPPED_SUBRESOURCE mr = {};
        if (FAILED(g_d3d11.context->Map(g_d3d11.dynamicIB, 0,
                                         D3D11_MAP_WRITE_DISCARD, 0, &mr))) return;
        memcpy(mr.pData, fanOrQuadIdx.data(), drawIndexCount * 2);
        g_d3d11.context->Unmap(g_d3d11.dynamicIB, 0);
    }

    bool useTexture = (g_currentPSHandle != 0 || ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;

    if (useTexture) {
        srv = ResolveShaderResourceView(base, 0, 0);
        if (!srv) {
            for (uint32_t stage = 1; stage < 4; ++stage) {
                srv = ResolveShaderResourceView(base, stage, 0);
                if (srv) break;
            }
        }
    }

    // Resolve the currently bound texture (if any).
    // Burnout 3 uses programmable pixel shaders driven via the pushbuffer,
    // so the fixed-function TSS combiner state is stale for most 3D draws
    // (we frequently see colorOp=DISABLE while a real texture is bound).
    // Bind whatever high-level texture the game selected with SetTexture,
    // falling back to push-buffer-shadowed NV2A state if that slot is empty.
    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    srv = nullptr;
    bool colorOpOk = ColorOpUsesTexture();
    (void)colorOpOk;
    if (texAddr) {
        srv = GetOrCreateTextureSRV(base, texAddr);
    }
    if (!srv) {
        srv = ResolveNV2ATextureSRV(base, 0);
    }
    // PP fullscreen-quad fallback: try stages 1..3 if stage 0 is empty.
    // Many Burnout 3 PP passes (bloom composite, motion-blur darken) bind
    // the scene/RT texture at a non-zero stage and rely on a programmable
    // pixel shader we can't translate yet.
    if (!srv) {
        for (uint32_t stage = 1; stage < 4; ++stage) {
            uint32_t a = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00 + stage * 4);
            if (a == 0) continue;
            ID3D11ShaderResourceView* s = GetOrCreateTextureSRV(base, a);
            if (s) { srv = s; texAddr = a; break; }
        }
    }
    if (!srv) {
        for (uint32_t stage = 1; stage < 4; ++stage) {
            ID3D11ShaderResourceView* s = ResolveNV2ATextureSRV(base, stage);
            if (s) { srv = s; break; }
        }
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

    // OM: render target + depth (back buffer, or guest RT-to-texture).
    bool boundGuestRT = BindActiveRenderTarget(base, /*wantDepth=*/true);
    float bf[4] = { 1,1,1,1 };
    // Honor tracked NV2A blend state, including the per-byte color write mask
    // and current SRC/DST blend factors. SET_COLOR_MASK is heavily used by
    // Burnout 3 transparent / additive overlays; SET_DEPTH_MASK toggles
    // depth write on/off per draw for transparent passes.
    ID3D11BlendState* bs3D = GetOrCreateBlendState(
        g_blendSrc, g_blendDst, g_alphaBlendEnabled, g_colorWriteMask, g_blendEquation);
    SC_BlendState(bs3D, bf, 0xFFFFFFFF);
    {
        bool depthEnable = !g_dbg.noCull;
        ID3D11DepthStencilState* dss = depthEnable
            ? GetOrCreateDepthState(g_depthFunc, g_depthWriteEnable, true,
                                    g_stencilTestEnable,
                                    g_stencilFunc, g_stencilMask, g_stencilFuncMask,
                                    g_stencilOpFail, g_stencilOpZFail, g_stencilOpZPass)
            : g_d3d11.dssOff;
        SC_DepthStencil(dss, g_stencilRef);
    }

    // RS: no-cull for Burnout 3 car geometry. (Viewport already set by
    // BindActiveRenderTarget.)
    SC_Raster(
        g_dbg.noCull ? g_d3d11.rsNoCull
                     : (g_d3d11.rsCull3D ? g_d3d11.rsCull3D : g_d3d11.rsNoCull));

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
    SC_VS(useVS);
    SC_VSCB0(g_d3d11.cb3D);
    SC_IL(useIL);

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
    // The guest combiner expects a texture (arg1=TEXTURE, op != DISABLE)
    // but none is bound at any stage and we have no translated programmable
    // PS to fake it — typically a PP fullscreen quad whose intended pixel
    // shader we can't emulate. Falling through to ps3DUntextured outputs
    // `(max(col.rgb,0.6), 1.0)` which renders as solid bright rectangles
    // for vertex colours like 0x00FFFFFF. Drop the draw rather than render
    // the artifact.
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
                
                // Guard against clobbering constants cleanly set by SetPixelShaderConstant
                if (v != 0 && !(g_pshConstantsDirty & (1u << i))) {
                    g_pshConstants[i][0] = ((v >> 16) & 0xFF) / 255.0f;
                    g_pshConstants[i][1] = ((v >>  8) & 0xFF) / 255.0f;
                    g_pshConstants[i][2] = ((v >>  0) & 0xFF) / 255.0f;
                    g_pshConstants[i][3] = ((v >> 24) & 0xFF) / 255.0f;
                    g_pshConstantsDirty |= (1u << i);
                }
            }

            // Hash-skip CB upload like we do for the VS CB. cbPS is 32×float4
            // = 512 bytes; memcmp on a hot cache line is well under a μs and
            // saves a Map(DISCARD) per draw when nothing changed (typical
            // for runs of draws sharing the same combiner constants).
            static float s_psStage[32 * 4]   = {};
            static float s_psLast[32 * 4]    = {};
            static bool  s_psLastValid       = false;
            std::memcpy(s_psStage, &g_pshConstants[0][0], 16 * 4 * sizeof(float));
            std::memset(s_psStage + 16 * 4, 0, (32 - 16) * 4 * sizeof(float));

            // psC[16]/[17] = final-combiner constants (FC0/FC1).
            // Priority order:
            //   1. Live shadow updated by ProcessNV2AMethod for
            //      NV097_SET_COMBINER_SPECULAR_FOG_CW0/1 (0x1E20/0x1E24).
            //   2. RS shadow at indices 26/27 (X_D3DRS_PSFINAL
            //      COMBINERCONSTANT0/1) for paths that bypass NV2A method
            //      capture.
            //   3. The current PS's baked PSDef defaults — used when the
            //      game never overrides them at runtime. We look them up
            //      directly here (rather than relying on a seed-on-handle-
            //      switch path) so map shaders whose PS handle was never
            //      cycled through SetPixelShader still see correct baked
            //      values instead of a black FC.
            uint32_t fcArgb[2] = { 0, 0 };
            fcArgb[0] = tps->bakedFc0;
            fcArgb[1] = tps->bakedFc1;
            if (g_psFinalCombinerConst[0] != 0) fcArgb[0] = g_psFinalCombinerConst[0];
            if (g_psFinalCombinerConst[1] != 0) fcArgb[1] = g_psFinalCombinerConst[1];
            for (int k = 0; k < 2; ++k) {
                uint32_t rs = 26u + (uint32_t)k;
                if (rs < kHLERenderStateCount) {
                    uint32_t v = g_hleRenderStateCache[rs];
                    if (v != 0) fcArgb[k] = v;
                }
            }
            for (int k = 0; k < 2; ++k) {
                float* dst = s_psStage + (16 + k) * 4;
                uint32_t v = fcArgb[k];
                dst[0] = ((v >> 16) & 0xFF) / 255.0f; // R
                dst[1] = ((v >>  8) & 0xFF) / 255.0f; // G
                dst[2] = ((v >>  0) & 0xFF) / 255.0f; // B
                dst[3] = ((v >> 24) & 0xFF) / 255.0f; // A
            }

            if (!s_psLastValid
                || std::memcmp(s_psStage, s_psLast, sizeof(s_psStage)) != 0) {
                D3D11_MAPPED_SUBRESOURCE mr{};
                if (SUCCEEDED(g_d3d11.context->Map(g_d3d11.cbPS, 0,
                        D3D11_MAP_WRITE_DISCARD, 0, &mr))) {
                    std::memcpy(mr.pData, s_psStage, sizeof(s_psStage));
                    g_d3d11.context->Unmap(g_d3d11.cbPS, 0);
                    std::memcpy(s_psLast, s_psStage, sizeof(s_psStage));
                    s_psLastValid = true;
                }
            }
            SC_PSCB0(g_d3d11.cbPS);
        }

        SC_PS(tps->ps);
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
        // Hazard mitigation: if the active RT is a GuestRT (e.g. bloom mip),
        // any SRV that points at the same texture's full mip chain will be
        // silently detached by D3D11 because the SRV overlaps the bound RTV.
        // Substitute the pre-built sub-range SRV that excludes the current
        // RT mip so the shader can sample previous (larger) mips.
        if (g_d3d11.activeGuestRT) {
            GuestRT* art = g_d3d11.activeGuestRT;
            uint32_t aMip = g_d3d11.activeGuestRTMip;
            ID3D11ShaderResourceView* sub = (aMip < art->srvSrcExclMip.size()) ? art->srvSrcExclMip[aMip] : nullptr;
            for (unsigned s = 0; s < 4; ++s) {
                if (srvs[s] == art->srv) {
                    srvs[s] = sub;
                } else if (aMip < art->srvPerMip.size() && srvs[s] == art->srvPerMip[aMip]) {
                    uint32_t mw = std::max<uint32_t>(1, art->baseW >> aMip);
                    uint32_t mh = std::max<uint32_t>(1, art->baseH >> aMip);
                    EnsureScratchTexture(mw, mh, art->dxgiFormat);
                    if (g_d3d11.scratchTex) {
                        g_d3d11.context->CopySubresourceRegion(
                            g_d3d11.scratchTex, 0, 0, 0, 0,
                            art->texture, aMip, nullptr);
                        srvs[s] = g_d3d11.scratchSRV;
                    } else {
                        srvs[s] = nullptr;
                    }
                }
            }
        } else {
            // Active RT is the Back Buffer
            for (unsigned s = 0; s < 4; ++s) {
                if (srvs[s] == g_d3d11.sceneSRV) {
                    EnsureScratchTexture(g_d3d11.width, g_d3d11.height, g_d3d11.sceneFormat);
                    if (g_d3d11.scratchTex) {
                        g_d3d11.context->CopySubresourceRegion(
                            g_d3d11.scratchTex, 0, 0, 0, 0,
                            g_d3d11.backBufferTex, 0, nullptr);
                        srvs[s] = g_d3d11.scratchSRV;
                    } else {
                        srvs[s] = nullptr;
                    }
                }
            }
        }
        SC_PSSRVs(4, srvs);
        SC_PSSamplers(4, samps);
    } else {
        ID3D11PixelShader* ps = srv ? g_d3d11.ps3D
                                    : (g_d3d11.ps3DUntextured ? g_d3d11.ps3DUntextured
                                                              : g_d3d11.psUntextured);
        SC_PS(ps);
        if (srv) {
            // Hazard mitigation (mirrors multi-stage path above).
            if (g_d3d11.activeGuestRT && srv == g_d3d11.activeGuestRT->srv) {
                uint32_t aMip = g_d3d11.activeGuestRTMip;
                if (aMip < g_d3d11.activeGuestRT->srvSrcExclMip.size())
                    srv = g_d3d11.activeGuestRT->srvSrcExclMip[aMip];
                else
                    srv = nullptr;
            } else if (g_d3d11.activeGuestRT && g_d3d11.activeGuestRTMip < g_d3d11.activeGuestRT->srvPerMip.size() && srv == g_d3d11.activeGuestRT->srvPerMip[g_d3d11.activeGuestRTMip]) {
                GuestRT* art = g_d3d11.activeGuestRT;
                uint32_t aMip = g_d3d11.activeGuestRTMip;
                uint32_t mw = std::max<uint32_t>(1, art->baseW >> aMip);
                uint32_t mh = std::max<uint32_t>(1, art->baseH >> aMip);
                EnsureScratchTexture(mw, mh, art->dxgiFormat);
                if (g_d3d11.scratchTex) {
                    g_d3d11.context->CopySubresourceRegion(
                        g_d3d11.scratchTex, 0, 0, 0, 0,
                        art->texture, aMip, nullptr);
                    srv = g_d3d11.scratchSRV;
                } else {
                    srv = nullptr;
                }
            }
            ID3D11ShaderResourceView* one[1]   = { srv };
            ID3D11SamplerState*       samp1[1] = { g_d3d11.samplerWrap };
            SC_PSSRVs(1, one);
            SC_PSSamplers(1, samp1);
        }
    }

    // VB
    UINT vbStride = stride, vbOffset = 0;
    SC_VB(g_d3d11.dynamicVB, vbStride, vbOffset);
    SC_Topology(topo);

    {
        wchar_t _m[128];
        swprintf(_m, 128, L"f=%u d=%u RT=%08X 3D pt=%u %s",
                 g_ppFrame, drawIdx, g_d3d11.currentRTSurf, primType,
                 indexCount ? L"IDX" : L"VTX");
        RdocMark(_m);
    }
    if (useExpanded) {
        SC_IB(g_d3d11.dynamicIB, DXGI_FORMAT_R16_UINT, 0);
        g_d3d11.context->DrawIndexed(drawIndexCount, 0, 0);
    } else if (indexCount) {
        SC_IB(g_d3d11.dynamicIB, DXGI_FORMAT_R16_UINT, 0);
        g_d3d11.context->DrawIndexed(indexCount, 0, 0);
    } else {
        g_d3d11.context->Draw(vertexCount, startVertex);
    }

    // Unbind SRV to avoid hazards between subsequent 2D passes.
    if (tps) {
        ID3D11ShaderResourceView* nullSRVs[4] = {};
        SC_PSSRVs(4, nullSRVs);
    } else if (srv) {
        ID3D11ShaderResourceView* nullSRV[1] = { nullptr };
        SC_PSSRVs(1, nullSRV);
    }
}

// Handles all Xbox/NV2A primitive types by expanding to tri-lists or strips.
static void DrawSWVertsD3D11(uint8_t* base, const SWVertex* sv, size_t n, int primType,
                              ID3D11ShaderResourceView* srv, bool isAlphaOnly,
                              uint32_t srcTexW = 0, uint32_t srcTexH = 0)
{
    if (n == 0 || !g_d3d11.initialized) return;

    // Normalize pixel-space UV coordinates to 0-1 for D3D11 sampler.
    // sub_3DA90 writes UV in screen-pixel space (0..srcTexW, 0..srcTexH)
    // both via D3DDevice_SetVertexData2f and via raw NV2A push-buffer methods.
    // Detect pixel-space by checking whether any vertex has |u| or |v| > 2.
    // Use source texture dimensions when provided; fall back to g_bbWidth/g_bbHeight.
    uint32_t normW = (srcTexW > 0) ? srcTexW : g_bbWidth;
    uint32_t normH = (srcTexH > 0) ? srcTexH : g_bbHeight;
    bool needsUVNorm = false;
    if (normW > 0 && normH > 0) {
        for (size_t i = 0; i < n; i++) {
            if (sv[i].u > 2.0f || sv[i].v > 2.0f ||
                sv[i].u < -2.0f || sv[i].v < -2.0f) {
                needsUVNorm = true; break;
            }
        }
    }
    float uvScaleU = needsUVNorm ? (1.0f / (float)normW) : 1.0f;
    float uvScaleV = needsUVNorm ? (1.0f / (float)normH) : 1.0f;

    std::vector<Vtx2D> verts;
    verts.reserve(n * 2);
    auto push = [&](const SWVertex& v) {
        verts.push_back({v.x, v.y, v.u * uvScaleU, v.v * uvScaleV, v.diffuse});
    };

    D3D_PRIMITIVE_TOPOLOGY topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

    // Note: only NV2A prim types reach this path (from SubmitPrims).
    // X_D3DPT values overlap with NV2A values so they are NOT combined here.
    switch (primType) {
    case NV2A_PRIM_TRIANGLES:   // 5
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
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 0; i + 3 < n; i += 4) {
            push(sv[i]); push(sv[i+1]); push(sv[i+2]);
            push(sv[i]); push(sv[i+2]); push(sv[i+3]);
        }
        break;
    case NV2A_PRIM_QUADSTRIP:   // 9
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (size_t i = 0; i + 3 < n; i += 2) {
            push(sv[i]); push(sv[i+1]); push(sv[i+2]);
            push(sv[i+1]); push(sv[i+3]); push(sv[i+2]);
        }
        break;
    default:
        return;
    }

    if (!verts.empty()) {
        g_b2dCallerTag = "SW";
        g_b2dBase = base;
        HLE_DrawBatch2D(verts.data(), static_cast<uint32_t>(verts.size()), topo, srv, isAlphaOnly);
        g_b2dBase = nullptr;
    }
}

// Full draw: resolve texture from guest state then call DrawSWVertsD3D11
static void DrawSWVertsWithTexD3D11(uint8_t* base, const SWVertex* sv, size_t n, int primType)
{
    bool useTexture = (g_currentPSHandle != 0 || ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;
    bool isAlphaOnly = false;

    uint32_t texAddr0 = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    uint32_t rtSurf   = g_d3d11.currentRTSurf;
    
    if (useTexture) {
        srv = ResolveShaderResourceView(base, 0, 0, &isAlphaOnly);
        if (!srv) {
            for (uint32_t stage = 1; stage < 4; ++stage) {
                srv = ResolveShaderResourceView(base, stage, 0, &isAlphaOnly);
                if (srv) break;
            }
        }
    }

    // Bloom diagnostic: log IM draws when RT or texture is in the bloom range.
    if (rtSurf == 0 || (rtSurf >= 0x19200000u && rtSurf < 0x19300000u)
        || (texAddr0 >= 0x4D0000u && texAddr0 < 0x4E0000u)) {
        uint32_t data0 = texAddr0 ? X86_MEM_READ_u32(base, texAddr0 + 4) : 0;
        bool rtInMap   = g_d3d11.guestRTBySurface.count(rtSurf) != 0;
        fprintf(stderr,
                "[BLOOM] IM-End f=%u rt=0x%08X(inMap=%d) tex=0x%08X data=0x%08X"
                " srv=%s n=%zu prim=%d PS=0x%08X useT=%d\n",
                g_ppFrame, rtSurf, (int)rtInMap, texAddr0, data0,
                srv ? "YES" : "NULL", n, primType, g_currentPSHandle, (int)useTexture);
        // Dump raw SWVertex UV data (first time per PS) so we can see what's
        // happening to V before the /g_bbHeight normalization in DrawSWVertsD3D11.
        static uint32_t s_bloomVtxDone = 0;
        uint32_t mask = (g_currentPSHandle == 0x008FC000u) ? 1u :
                        (g_currentPSHandle == 0x008FD000u) ? 2u :
                        (g_currentPSHandle == 0x008FE000u) ? 4u :
                        (g_currentPSHandle == 0x008FF000u) ? 8u : 0u;
        if (mask && !(s_bloomVtxDone & mask)) {
            s_bloomVtxDone |= mask;
            uint32_t vpW2 = base ? X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8)  : 0;
            uint32_t vpH2 = base ? X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12) : 0;
            fprintf(stderr, "[BLOOM-VTX] PS=0x%08X bbW=%u bbH=%u vpW=%u vpH=%u srcTexW=%u srcTexH=%u n=%zu:\n",
                    g_currentPSHandle, g_bbWidth, g_bbHeight, vpW2, vpH2,
                    (texAddr0 && g_d3d11.guestRTBySurface.count(texAddr0) && g_d3d11.guestRTBySurface.at(texAddr0).rt)
                        ? g_d3d11.guestRTBySurface.at(texAddr0).rt->baseW : 0u,
                    (texAddr0 && g_d3d11.guestRTBySurface.count(texAddr0) && g_d3d11.guestRTBySurface.at(texAddr0).rt)
                        ? g_d3d11.guestRTBySurface.at(texAddr0).rt->baseH : 0u,
                    n);
            for (size_t vi = 0; vi < n && vi < 4; vi++) {
                fprintf(stderr, "  [%zu] pos=(%.3f,%.3f) uv=(%.4f,%.4f) diff=0x%08X\n",
                        vi, sv[vi].x, sv[vi].y, sv[vi].u, sv[vi].v, sv[vi].diffuse);
            }
        }
    }

    // Look up source texture dimensions so DrawSWVertsD3D11 uses the correct
    // UV normalization divisor (rather than the global g_bbWidth/g_bbHeight
    // which is always 640x480, even when the source RT is 320x240 or 160x120).
    uint32_t srcTexW = 0, srcTexH = 0;
    if (texAddr0) {
        auto itSrc = g_d3d11.guestRTBySurface.find(texAddr0);
        if (itSrc != g_d3d11.guestRTBySurface.end() && itSrc->second.rt) {
            srcTexW = itSrc->second.rt->baseW;
            srcTexH = itSrc->second.rt->baseH;
        }
    }

    // Letterbox position fix (PS=0x008FC000): The scene RT now has content in
    // all rows 0..479 from the expanded 3D viewport (Fix 3).  But the game's
    // composite quad sits in the Xbox letterbox band (pos_y = vpY..vpY+vpH,
    // nominally 16..464) and the CB2D transform maps it only to backbuffer
    // rows 16..464, leaving black gaps at top and bottom.  Remap the vertex
    // Y positions from the content band to the full screen so the composite
    // covers rows 0..479.  UV stays unchanged; the full-height source RT is
    // sampled end-to-end.
    if (g_currentPSHandle == 0x008FC000u && n <= 4) {
        float minY = sv[0].y, maxY = sv[0].y;
        for (size_t i = 1; i < n; ++i) {
            if (sv[i].y < minY) minY = sv[i].y;
            if (sv[i].y > maxY) maxY = sv[i].y;
        }
        float fullH = static_cast<float>(g_bbHeight);
        float spanH = maxY - minY;
        // Only apply to symmetric letterbox quads (top bar height == bottom bar height).
        if (minY > 0.5f && spanH > 0.5f && fabsf((fullH - maxY) - minY) < 2.0f) {
            SWVertex adjVerts[4];
            float invSpan = fullH / spanH;
            for (size_t i = 0; i < n; ++i) {
                adjVerts[i]   = sv[i];
                adjVerts[i].y = (sv[i].y - minY) * invSpan;
            }
            DrawSWVertsD3D11(base, adjVerts, n, primType, srv, isAlphaOnly, srcTexW, srcTexH);
            return;
        }
    }

    DrawSWVertsD3D11(base, sv, n, primType, srv, isAlphaOnly, srcTexW, srcTexH);
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

    // Process any pending NV2A push-buffer writes (blend state, texture stages,
    // etc.) that were flushed by _rwXbFlushCacheBuffer before this draw.
    // Without this call the blur/post-FX setup done by sub_45EE0/sub_40F90
    // (alpha blend enable, src/dst factors, texture bindings) is never applied.
    WalkPushBuffer(base);

    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    // See note in DrawSWVertsWithTexD3D11.
    bool useTexture = (g_currentPSHandle != 0 || ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;

    // Diagnostic: log DrawVerticesUP draws for blur investigation.
    if (g_currentPSHandle == 0x00900000u || g_currentPSHandle == 0x00901000u) {
        uint32_t dataAddr = texAddr ? X86_MEM_READ_u32(base, texAddr + 4) : 0;
        uint32_t rtSurf   = g_d3d11.currentRTSurf;
        bool rtInMap = g_d3d11.guestRTBySurface.count(rtSurf) != 0;
        auto psIt = g_psByHandle.find(g_currentPSHandle);
        bool tpsOk = (psIt != g_psByHandle.end() && psIt->second.ps != nullptr);
        uint32_t snap1 = g_psTexHandleSnapshot[1];
        uint32_t snap2 = g_psTexHandleSnapshot[2];
        uint32_t snap3 = g_psTexHandleSnapshot[3];
        uint32_t vpW_diag = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
        uint32_t vpH_diag = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
        fprintf(stderr,
                "[DVUP2] f=%u rt=0x%08X(inMap=%d) tex=0x%08X data=0x%08X"
                " prim=%u vtxCnt=%u stride=%u PS=0x%08X tpsOk=%d"
                " snap0=0x%08X snap1=0x%08X snap2=0x%08X snap3=0x%08X"
                " vp=%ux%u nv2aVp=(sx=%.1f sy=%.1f tx=%.1f ty=%.1f) blend:en=%d src=%u dst=%u\n",
                g_ppFrame, rtSurf, (int)rtInMap, texAddr, dataAddr,
                primType, vtxCount, vtxStride, g_currentPSHandle, (int)tpsOk,
                texAddr, snap1, snap2, snap3, vpW_diag, vpH_diag,
                g_nv2aVpScaleX, g_nv2aVpScaleY, g_nv2aVpTranslateX, g_nv2aVpTranslateY,
                (int)g_alphaBlendEnabled, g_blendSrc, g_blendDst);
        // Dump raw vertex data for first 4 vertices so we can verify position/UV values.
        if (vtxStride == 52 && vtxCount >= 1) {
            for (uint32_t vi = 0; vi < vtxCount && vi < 4; vi++) {
                uint32_t off = pVtxData + vi * 52;
                float vx, vy, vz, vw, u0, v0, u1, v1, u2, v2, u3, v3;
                memcpy(&vx, base + off +  0, 4); memcpy(&vy, base + off +  4, 4);
                memcpy(&vz, base + off +  8, 4); memcpy(&vw, base + off + 12, 4);
                memcpy(&u0, base + off + 20, 4); memcpy(&v0, base + off + 24, 4);
                memcpy(&u1, base + off + 28, 4); memcpy(&v1, base + off + 32, 4);
                memcpy(&u2, base + off + 36, 4); memcpy(&v2, base + off + 40, 4);
                memcpy(&u3, base + off + 44, 4); memcpy(&v3, base + off + 48, 4);
                uint32_t vcol = X86_MEM_READ_u32(base, off + 16);
                fprintf(stderr,
                        "[DVUP2-VTX%u] pos=(%.1f,%.1f,%.3f,%.3f) col=0x%08X"
                        " uv0=(%.3f,%.3f) uv1=(%.3f,%.3f) uv2=(%.3f,%.3f) uv3=(%.3f,%.3f)\n",
                        vi, vx, vy, vz, vw, vcol,
                        u0, v0, u1, v1, u2, v2, u3, v3);
            }
        }
    }
    // Diagnostic: log bloom chain downsampling draws (PS=0x008FD000/0x008FE000/0x008FF000).
    // These feed into the blur draw's stage1 (0x004D6A48), so their UV handling matters.
    if (g_currentPSHandle == 0x008FD000u || g_currentPSHandle == 0x008FE000u ||
        g_currentPSHandle == 0x008FF000u || g_currentPSHandle == 0x008FC000u) {
        static bool s_bloomDiagDone[4] = {};
        int slot = (g_currentPSHandle == 0x008FC000u) ? 0 :
                   (g_currentPSHandle == 0x008FD000u) ? 1 :
                   (g_currentPSHandle == 0x008FE000u) ? 2 : 3;
        if (!s_bloomDiagDone[slot]) {
            s_bloomDiagDone[slot] = true;
            uint32_t rtSurf = g_d3d11.currentRTSurf;
            fprintf(stderr, "[BLOOM-CHAIN] PS=0x%08X rt=0x%08X stride=%u vtxCnt=%u\n",
                    g_currentPSHandle, rtSurf, vtxStride, vtxCount);
            for (uint32_t vi = 0; vi < vtxCount && vi < 4; vi++) {
                uint32_t off = pVtxData + vi * vtxStride;
                float vx, vy;
                memcpy(&vx, base + off + 0, 4); memcpy(&vy, base + off + 4, 4);
                // Read UVs from the most likely offsets based on stride
                float ua = 0, va = 0;
                if (vtxStride == 28) {
                    memcpy(&ua, base + off + 20, 4); memcpy(&va, base + off + 24, 4);
                } else if (vtxStride >= 20) {
                    memcpy(&ua, base + off + 8,  4); memcpy(&va, base + off + 12, 4);
                }
                fprintf(stderr, "[BLOOM-CHAIN-VTX%u] pos=(%.2f,%.2f) uv=(%.4f,%.4f)\n",
                        vi, vx, vy, ua, va);
            }
        }
    }
    bool isAlphaOnly = false;
    uint32_t texW = 1, texH = 1;
    
    if (useTexture) {
        srv = ResolveShaderResourceView(base, 0, 0, &isAlphaOnly, nullptr, &texW, &texH);
        if (!srv) {
            for (uint32_t stage = 1; stage < 4; ++stage) {
                srv = ResolveShaderResourceView(base, stage, 0, &isAlphaOnly, nullptr, &texW, &texH);
                if (srv) break;
            }
        }
    }

    // Detect if UVs are in pixel coordinates (only relevant for the non-stride-28/52 format)
    bool uvInPixels = false;
    if (vtxStride != 28 && vtxStride != 52 && srv && texW > 1 && texH > 1) {
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

    // Determine whether to build extended (4-UV) vertex data for translated-PS draws.
    // stride=52 = XYZRHW(16) + DIFFUSE(4) + UV0..UV3(4×8) used by blur/post-FX quads.
    const bool buildExVerts = (vtxStride == 52) && (g_currentPSHandle != 0);

    // Per-stage UV affine normalization for ExPath (stride=52 post-FX quads).
    //
    // The Xbox vertex data stores UVs in pixel space, but the direction of V
    // varies by draw:
    //   - Blur draw  (PS 0x00900000): V decreases from top→bottom (17.8→-16),
    //     so simple /height gives a tiny range that wraps badly.
    //   - Composite  (PS 0x00901000): V increases from top→bottom (1.3→238.5),
    //     so /height works, but vertex-range is cleaner and exact.
    //
    // The unified formula for both:
    //   u_norm = (u_pixel - u_left) / (u_right - u_left)
    //   v_norm = (v_pixel - v_top)  / (v_bot   - v_top)
    //
    // where v_top is the V value at the screen-top vertex and v_bot is at the
    // screen-bottom vertex.  When v_top > v_bot the denominator is negative and
    // v_norm increases correctly from 0→1 top→bottom.
    struct UVAffine { float uOff, uRng, vOff, vRng; };
    UVAffine uvAff[4] = {};
    for (int s = 0; s < 4; s++) { uvAff[s] = {0.0f, 1.0f, 0.0f, 1.0f}; }

    if (buildExVerts && vtxCount >= 2) {
        // Pre-scan: find top/bottom/left/right vertices in screen space.
        // For screen-space draws (all Y ≥ 0): min Y = screen top.
        // For centered draws   (some Y < 0): max Y = screen top (+Y = up).
        float scanMinY = FLT_MAX, scanMaxY = -FLT_MAX;
        float scanMinX = FLT_MAX, scanMaxX = -FLT_MAX;
        uint32_t minYidx = 0, maxYidx = 0, minXidx = 0, maxXidx = 0;
        for (uint32_t i = 0; i < vtxCount; i++) {
            uint32_t soff = pVtxData + i * vtxStride;
            float sx, sy;
            memcpy(&sx, base + soff,     4);
            memcpy(&sy, base + soff + 4, 4);
            if (sy < scanMinY) { scanMinY = sy; minYidx = i; }
            if (sy > scanMaxY) { scanMaxY = sy; maxYidx = i; }
            if (sx < scanMinX) { scanMinX = sx; minXidx = i; }
            if (sx > scanMaxX) { scanMaxX = sx; maxXidx = i; }
        }
        // PS=0x00901000 (blur composite) always uses centred Y coordinates
        // (+Y = up, 0 = screen centre) even when a sub-quad doesn't cross
        // zero (e.g. the top-half split quad Y=0..+16 has scanMinY=0).
        // Force isCentered for that PS handle so topIdx/botIdx are correct.
        bool isCentered = (scanMinY < 0.0f) || (g_currentPSHandle == 0x00901000u);
        uint32_t topIdx   = isCentered ? maxYidx : minYidx;
        uint32_t botIdx   = isCentered ? minYidx : maxYidx;
        uint32_t leftIdx  = minXidx;
        uint32_t rightIdx = maxXidx;

        // Derive the affine transform from STAGE 0 only, then share it across
        // all stages.  Per-stage independent normalization would map every stage
        // to exactly [0,1], erasing the small inter-stage UV offsets that carry
        // the motion-blur streak direction.  Using stage 0 as the reference
        // keeps those offsets intact (e.g. stage 1 might end up at 0.054..1.079
        // in V, i.e. shifted ~5% down — that IS the blur streak).
        {
            float uL, uR, vT, vB;
            memcpy(&uL, base + pVtxData + leftIdx  * vtxStride + 20, 4); // stage0 U
            memcpy(&uR, base + pVtxData + rightIdx * vtxStride + 20, 4);
            memcpy(&vT, base + pVtxData + topIdx   * vtxStride + 24, 4); // stage0 V
            memcpy(&vB, base + pVtxData + botIdx   * vtxStride + 24, 4);
            float uRng = uR - uL;
            float vRng = vB - vT;
            UVAffine shared = {
                uL, (fabsf(uRng) > 1e-6f) ? uRng : 1.0f,
                vT, (fabsf(vRng) > 1e-6f) ? vRng : 1.0f
            };
            for (int s = 0; s < 4; s++) uvAff[s] = shared;
        }

        // For the blur draw (PS 0x00900000), override with per-stage
        // texture-dimension normalization to achieve correct center-out streaks.
        // Stage0 is the scene texture (640x480); stages 1-3 are the bloom
        // texture (160x120).  The game stores all UVs in scene-width units
        // for U but bloom-height units for V.  Normalising stage-1 V by 120
        // (not 480) moves the vanishing point to ~V=0.46 on screen (near
        // centre), giving outward-radiating streaks.  Wrap-unrolling of
        // negative V is performed in the vertex loop below.
        if (g_currentPSHandle == 0x00900000u) {
            uvAff[0] = { 0.f, 640.f, 0.f, 480.f }; // stage0: scene  U÷640 V÷480
            uvAff[1] = { 0.f, 640.f, 0.f, 120.f }; // stage1: bloom  U÷640 V÷120
            uvAff[2] = { 0.f, 640.f, 0.f, 480.f }; // stage2: scene  U÷640 V÷480
            uvAff[3] = { 0.f, 640.f, 0.f, 480.f }; // stage3: scene  U÷640 V÷480
        }

        // For the blur composite (PS 0x00901000), override stages 0-2 with
        // fixed texture-dimension normalization.  The blur-accum buffer is
        // 320×240, so U÷320 V÷240 maps every sample to [0,1] exactly:
        //   stage0: blur accum (320×240)
        //   stage1: main RT, but UV is in 320×240 "blur-accum pixel" units
        //   stage2: main RT (same unit space)
        //   stage3: intentionally left vertex-derived (keeps inter-stage streak)
        if (g_currentPSHandle == 0x00901000u) {
            uvAff[0] = { 0.f, 320.f, 0.f, 240.f };
            uvAff[1] = { 0.f, 320.f, 0.f, 240.f };
            uvAff[2] = { 0.f, 320.f, 0.f, 240.f };
            // uvAff[3]: intentionally shared (vertex-derived)
        }

        // One-time diagnostic
        static bool s_uvDiagDone[2] = {};
        int psSlot = (g_currentPSHandle == 0x00900000u) ? 0 : (g_currentPSHandle == 0x00901000u) ? 1 : -1;
        if (psSlot >= 0 && !s_uvDiagDone[psSlot]) {
            s_uvDiagDone[psSlot] = true;
            fprintf(stderr, "[DVUP2-UVAFFINE] PS=0x%08X isCentered=%d "
                    "s0 uOff=%.2f uRng=%.2f vOff=%.2f vRng=%.2f | "
                    "s1 uOff=%.2f uRng=%.2f vOff=%.2f vRng=%.2f\n",
                    g_currentPSHandle, (int)isCentered,
                    uvAff[0].uOff, uvAff[0].uRng, uvAff[0].vOff, uvAff[0].vRng,
                    uvAff[1].uOff, uvAff[1].uRng, uvAff[1].vOff, uvAff[1].vRng);
        }
    }

    // Build normalized Vtx2D array (and optional Vtx2DEx for stride=52 TPS draws)
    std::vector<Vtx2D>   v2d(vtxCount);
    std::vector<Vtx2DEx> v2dEx;
    if (buildExVerts) v2dEx.reserve(vtxCount);

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
        } else if (vtxStride == 52) {
            // D3DFVF_XYZRHW|DIFFUSE|TEX4: X@0,Y@4,Z@8,W@12,col@16,U0@20,V0@24,...U3@44,V3@48
            col = X86_MEM_READ_u32(base, off + 16);
            memcpy(&u, base + off + 20, 4);  // UV0.u — primary UV for stage 0
            memcpy(&v, base + off + 24, 4);  // UV0.v
            if (buildExVerts) {
                Vtx2DEx ex;
                ex.x = x; ex.y = y; ex.color = col;
                memcpy(&ex.u0, base + off + 20, 4); memcpy(&ex.v0, base + off + 24, 4);
                memcpy(&ex.u1, base + off + 28, 4); memcpy(&ex.v1, base + off + 32, 4);
                memcpy(&ex.u2, base + off + 36, 4); memcpy(&ex.v2, base + off + 40, 4);
                memcpy(&ex.u3, base + off + 44, 4); memcpy(&ex.v3, base + off + 48, 4);
                // For the blur draw, unroll negative V values before normalization
                // so that GPU linear interpolation stays within [0,1] and does not
                // cross the wrap boundary (which would produce wrong centre values).
                if (g_currentPSHandle == 0x00900000u) {
                    if (ex.v0 < 0.f) ex.v0 += 480.f; // stage0: scene height
                    if (ex.v1 < 0.f) ex.v1 += 120.f; // stage1: bloom height
                    if (ex.v2 < 0.f) ex.v2 += 480.f; // stage2: scene height
                    if (ex.v3 < 0.f) ex.v3 += 480.f; // stage3: scene height
                }
                // Normalize pixel-space UVs to 0-1 using per-stage affine transform.
                // v_norm = (v_pixel - v_top) / (v_bot - v_top); negative range flips V.
                ex.u0 = (ex.u0 - uvAff[0].uOff) / uvAff[0].uRng;
                ex.v0 = (ex.v0 - uvAff[0].vOff) / uvAff[0].vRng;
                ex.u1 = (ex.u1 - uvAff[1].uOff) / uvAff[1].uRng;
                ex.v1 = (ex.v1 - uvAff[1].vOff) / uvAff[1].vRng;
                ex.u2 = (ex.u2 - uvAff[2].uOff) / uvAff[2].uRng;
                ex.v2 = (ex.v2 - uvAff[2].vOff) / uvAff[2].vRng;
                ex.u3 = (ex.u3 - uvAff[3].uOff) / uvAff[3].uRng;
                ex.v3 = (ex.v3 - uvAff[3].vOff) / uvAff[3].vRng;
                v2dEx.push_back(ex);
            }
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

    // Post-normalization diagnostic for blur draw: print actual GPU-bound UV values
    // AND the active PS constant blend weights. Together these uniquely determine
    // the streak direction and intensity that the GPU will produce.
    if (g_currentPSHandle == 0x00900000u && buildExVerts && !v2dEx.empty()) {
        static bool s_postNormDone = false;
        if (!s_postNormDone) {
            s_postNormDone = true;
            // Print first and last vertex (all 4 UV stages) to verify top/bottom.
            const Vtx2DEx& fe = v2dEx.front();
            const Vtx2DEx& le = v2dEx.back();
            fprintf(stderr,
                    "[DVUP2-POSTNORM] first: pos=(%.1f,%.1f)"
                    " s0=(%.4f,%.4f) s1=(%.4f,%.4f) s2=(%.4f,%.4f) s3=(%.4f,%.4f)\n",
                    fe.x, fe.y,
                    fe.u0, fe.v0, fe.u1, fe.v1, fe.u2, fe.v2, fe.u3, fe.v3);
            fprintf(stderr,
                    "[DVUP2-POSTNORM] last:  pos=(%.1f,%.1f)"
                    " s0=(%.4f,%.4f) s1=(%.4f,%.4f) s2=(%.4f,%.4f) s3=(%.4f,%.4f)\n",
                    le.x, le.y,
                    le.u0, le.v0, le.u1, le.v1, le.u2, le.v2, le.u3, le.v3);
            // psC[0].a = stage0 blend weight (scene vs bloom).
            // psC[1].a = stage1 blend weight applied to r0.
            // psC[2].a = final-combiner scale (fc0) for this shader.
            fprintf(stderr,
                    "[DVUP2-POSTNORM] psC[0].a=%.4f psC[1].a=%.4f psC[2].a=%.4f\n",
                    g_pshConstants[0][3], g_pshConstants[1][3], g_pshConstants[2][3]);
        }
    }
    // Post-normalization diagnostic for composite draw: print blend weights.
    if (g_currentPSHandle == 0x00901000u && buildExVerts && !v2dEx.empty()) {
        static bool s_compNormDone = false;
        if (!s_compNormDone) {
            s_compNormDone = true;
            // psC[0].a = weight for blur RT (stage0: blurRT vs scene).
            // psC[1].a = weight for stage1 blend (accumulated vs scene[uv2]).
            fprintf(stderr,
                    "[DVUP2-COMPNORM] psC[0].a=%.4f psC[1].a=%.4f\n",
                    g_pshConstants[0][3], g_pshConstants[1][3]);
        }
    }

    // Map NV2A primitive types to D3D11 topology (expand fans/quads)
    std::vector<Vtx2D>   expanded;
    std::vector<Vtx2DEx> expandedEx;
    D3D_PRIMITIVE_TOPOLOGY topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

    // Helper: expand ex-verts with same index pattern as v2d
    auto pushEx3 = [&](uint32_t a, uint32_t b, uint32_t c) {
        if (!v2dEx.empty()) {
            expandedEx.push_back(v2dEx[a]);
            expandedEx.push_back(v2dEx[b]);
            expandedEx.push_back(v2dEx[c]);
        }
    };

    switch (primType) {
    case NV2A_PRIM_TRIANGLES:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        expanded = v2d;
        expandedEx = v2dEx;
        break;
    case NV2A_PRIM_TRISTRIP:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP;
        expanded = v2d;
        expandedEx = v2dEx;
        break;
    case NV2A_PRIM_TRIFAN:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (uint32_t i = 1; i + 1 < vtxCount; i++) {
            expanded.push_back(v2d[0]);
            expanded.push_back(v2d[i]);
            expanded.push_back(v2d[i+1]);
            pushEx3(0, i, i+1);
        }
        break;
    case NV2A_PRIM_QUADS:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (uint32_t i = 0; i + 3 < vtxCount; i += 4) {
            expanded.push_back(v2d[i]);   expanded.push_back(v2d[i+1]); expanded.push_back(v2d[i+2]);
            expanded.push_back(v2d[i]);   expanded.push_back(v2d[i+2]); expanded.push_back(v2d[i+3]);
            pushEx3(i, i+1, i+2); pushEx3(i, i+2, i+3);
        }
        break;
    case NV2A_PRIM_QUADSTRIP:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        for (uint32_t i = 0; i + 3 < vtxCount; i += 2) {
            expanded.push_back(v2d[i]);   expanded.push_back(v2d[i+1]); expanded.push_back(v2d[i+2]);
            expanded.push_back(v2d[i+1]); expanded.push_back(v2d[i+3]); expanded.push_back(v2d[i+2]);
            pushEx3(i, i+1, i+2); pushEx3(i+1, i+3, i+2);
        }
        break;
    default:
        topo = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
        expanded = v2d;
        expandedEx = v2dEx;
        break;
    }

    if (!expanded.empty()) {
        g_b2dCallerTag = "DVUP";
        g_b2dBase = base;
        const Vtx2DEx* exPtr = expandedEx.empty() ? nullptr : expandedEx.data();
        HLE_DrawBatch2D(expanded.data(), static_cast<uint32_t>(expanded.size()),
                        topo, srv, isAlphaOnly,
                        exPtr, static_cast<uint32_t>(expandedEx.size()));
        g_b2dBase = nullptr;
    }

    GuestStackCleanup(ctx, 16);
}

void D3DDevice_DrawIndexedVertices(X86Context& ctx, uint8_t* base) {
    uint32_t primType   = GuestArg32(ctx, base, 0);
    uint32_t indexCount = GuestArg32(ctx, base, 1);
    uint32_t pIndexData = GuestArg32(ctx, base, 2);

    uint32_t vbAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x1660);
    uint32_t stride = X86_MEM_READ_u32(base, kDeviceAddr + 0x1664);
    if (vbAddr == 0 || indexCount == 0 || stride < 20) {
        GuestStackCleanup(ctx, 12); return;
    }

    // ADD THIS: Safely resolve the data pointer
    uint32_t vbData = X86_MEM_READ_u32(base, vbAddr + 4);
    if (vbData == 0) vbData = vbAddr + 0x0C; // fallback: inline data
    vbData &= 0x3FFFFFFFu;

    // Drain any inline NV2A push-buffer writes (constants etc.) before
    // checking shader-program preconditions.
    WalkPushBuffer(base);

    // Programmable vertex shader path — transform via NV2A constants (3D).
    uint32_t liveVSi = LiveVSHandle(base);
    bool hasProgVSi = (liveVSi != 0) && (g_vsByHandle.find(liveVSi) != g_vsByHandle.end());
    if (hasProgVSi && g_d3d11.vs3D && HasMvpConstants(base)) {
        // FIX: If pIndexData is 0, the game is faking a non-indexed draw. 
        // Route to HLE_Draw3D using indexCount as the vertexCount.
        if (pIndexData == 0) {
            HLE_Draw3D(base, primType, 0, indexCount, 0, 0);
        } else {
            HLE_Draw3D(base, primType, 0, 0, indexCount, pIndexData);
        }
        GuestStackCleanup(ctx, 12);
        return;
    }
    
    // --- 2D Fallback Path ---
    {
        const char* why =
            !hasProgVSi            ? "no-prog-VS" :
            !g_d3d11.vs3D          ? "no-vs3D"    :
            !HasMvpConstants(base) ? "no-MVP"     : "?";
        static std::unordered_map<uint64_t,int> s_fbCount;
        uint64_t key = ((uint64_t)liveVSi << 32) | (uint32_t)why[0];
        int& c = s_fbCount[key];
        if (c < 8) {
            fprintf(stderr,
                "[HLE] DrawIdx FALLBACK->2D reason=%s liveVS=0x%08X "
                "prim=%u ic=%u stride=%u vb=0x%X tex=0x%X\n",
                why, liveVSi, primType, indexCount, stride, vbAddr,
                X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00));
            ++c;
        }
    }

    uint32_t texAddr = X86_MEM_READ_u32(base, kDeviceAddr + 0x0B00);
    // See note in DrawSWVertsWithTexD3D11.
    bool useTexture  = (texAddr != 0) && (g_currentPSHandle != 0 || ColorOpUsesTexture());
    ID3D11ShaderResourceView* srv = nullptr;
    bool isAlphaOnly = false;
    uint32_t texW = 1, texH = 1;
    
    if (useTexture) {
        srv = ResolveShaderResourceView(base, 0, 0, &isAlphaOnly, nullptr, &texW, &texH);
        if (!srv) {
            for (uint32_t stage = 1; stage < 4; ++stage) {
                srv = ResolveShaderResourceView(base, stage, 0, &isAlphaOnly, nullptr, &texW, &texH);
                if (srv) break;
            }
        }
    }

    bool uvInPixels = false;
    if (stride != 28 && srv && texW > 1 && texH > 1) {
        float maxUV = 0.0f;
        uint32_t checkCount = std::min<uint32_t>(indexCount, 16);
        for (uint32_t i = 0; i < checkCount; i++) {
            uint32_t idx = pIndexData ? X86_MEM_READ_u16(base, pIndexData + i * 2) : i;
            uint32_t off = vbData + idx * stride;
            float us, vs;
            memcpy(&us, base + off + 8,  4);
            memcpy(&vs, base + off + 12, 4);
            if (fabsf(us) > maxUV) maxUV = fabsf(us);
            if (fabsf(vs) > maxUV) maxUV = fabsf(vs);
        }
        uvInPixels = (maxUV > 1.5f);
    }

    auto readVtx = [&](uint32_t idx) -> Vtx2D {
        uint32_t off = vbData + idx * stride; 
        float x, y, u = 0.f, v = 0.f;
        uint32_t col = 0xFFFFFFFF;
        memcpy(&x, base + off, 4);
        memcpy(&y, base + off + 4, 4);

        if (stride == 28) {
            col = X86_MEM_READ_u32(base, off + 16);
            memcpy(&u, base + off + 20, 4);
            memcpy(&v, base + off + 24, 4);
        } else {
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
        return {x, y, u, v, col};
    };

    auto readIdx = [&](uint32_t i) -> uint32_t {
        if (pIndexData == 0) return i; 
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
    case NV2A_PRIM_QUADSTRIP:
        for (uint32_t i = 0; i + 3 < indexCount; i += 2) {
            auto v0 = readVtx(readIdx(i)),   v1 = readVtx(readIdx(i+1));
            auto v2 = readVtx(readIdx(i+2)), v3 = readVtx(readIdx(i+3));
            expanded.push_back(v0); expanded.push_back(v1); expanded.push_back(v2);
            expanded.push_back(v1); expanded.push_back(v3); expanded.push_back(v2);
        }
        break;
    default:
        GuestStackCleanup(ctx, 12); return;
    }

    if (!expanded.empty()) {
        g_b2dCallerTag = "DI";
        g_b2dBase = base;
        HLE_DrawBatch2D(expanded.data(), static_cast<uint32_t>(expanded.size()),
                        topo, srv, isAlphaOnly);
        g_b2dBase = nullptr;
    }

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
    // On real Xbox, swizzled (non-linear, non-DXT) textures store sizeField = 0.
    // Only linear and DXT textures encode dimensions in the Size DWORD.
    // FindSurfaceWithinTexture uses sizeField != 0 as the selector for the linear path,
    // so writing a non-zero sizeDword for swizzled textures causes it to return the same
    // data address for every mip level, breaking bloom/post-FX mip chain rendering.
    uint32_t sizeDword = 0;
    if (isLinear || isDXT) {
        uint32_t pitchLog = 0;
        if (pitch >= 64)
            pitchLog = (pitch / 64) - 1;

        sizeDword = ((width  - 1) & X_D3DSIZE_WIDTH_MASK)
                  | (((height - 1) & 0xFFF) << X_D3DSIZE_HEIGHT_SHIFT)
                  | ((pitchLog & 0xFF) << X_D3DSIZE_PITCH_SHIFT);
    }

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

// sub_1ACD20 (0x1ACD20): per-player letterbox renderer.
// Draws black screen-space bars at the top/bottom of each player viewport via
// D3DDevice_DrawVerticesUP (TRIANGLEFAN, stride=32, no texture).
// On PC we render full-frame without letter-box bars, and this draw fires
// while bloom render-target state is still active, causing the black geometry
// to corrupt the blur-composite result.  Disable by doing nothing.
void sub_1ACD20(X86Context& ctx, uint8_t* base) {
}
