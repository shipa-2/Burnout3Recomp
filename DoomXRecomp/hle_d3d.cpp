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

#define STB_IMAGE_IMPLEMENTATION
#define STBI_NO_STDIO           // we only load from memory
#include "stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#include <windows.h>

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
        0, L"DoomXRecompWnd", L"DoomX Recomp",
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

static constexpr uint32_t kDeviceRenderTarget = 0x1A10;
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

// Swap / VBlank counters (returned by D3DDevice_Swap, read by guest code)
static uint32_t g_swapCount  = 0;
static uint32_t g_vblankCount = 0;

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

    // Create a host Win32 window for presentation.
    {
        uint32_t winW = 640, winH = 480;
        if (pPresent != 0) {
            uint32_t pw = X86_MEM_READ_u32(base, pPresent + 0x00);
            uint32_t ph = X86_MEM_READ_u32(base, pPresent + 0x04);
            if (pw > 0 && ph > 0) { winW = pw; winH = ph; }
        }
        HLE_CreatePresentationWindow(winW, winH);
    }

    fprintf(stderr, "[HLE] Direct3D_CreateDevice -> S_OK (device=0x%08X)\n", kDeviceAddr);

    GuestReturn32(ctx, 0);       // S_OK
    GuestStackCleanup(ctx, 24);  // ret 24
}

// ============================================================================
// Swap / Present
// ============================================================================

// D3DDevice_Swap  (0x96540) — 1 arg, ret 4
void D3DDevice_Swap(X86Context& ctx, uint8_t* base)
{
    uint32_t flags = GuestArg32(ctx, base, 0);
    //fprintf(stderr, "[HLE] D3DDevice_Swap(flags=0x%X) frame=%u\n", flags, g_swapCount);

    // Dump frame 0 render target to PNG for debugging
    {
        static bool frameDumped = false;
        if (!frameDumped) {
            frameDumped = true;
            uint32_t bbSurf = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);
            if (bbSurf == 0) bbSurf = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
            if (bbSurf != 0) {
                uint32_t bbData = X86_MEM_READ_u32(base, bbSurf + 4);
                if (bbData != 0) {
                    uint32_t w = 640, h = 480;
                    std::vector<uint8_t> rgba(w * h * 4);
                    uint32_t* src = reinterpret_cast<uint32_t*>(base + bbData);
                    for (uint32_t i = 0; i < w * h; i++) {
                        uint32_t px = src[i];
                        rgba[i*4+0] = (px >> 16) & 0xFF;
                        rgba[i*4+1] = (px >>  8) & 0xFF;
                        rgba[i*4+2] = (px      ) & 0xFF;
                        rgba[i*4+3] = 255;
                    }
                    stbi_write_png("frame_dump.png", w, h, 4, rgba.data(), w * 4);
                    fprintf(stderr, "[HLE] FRAME DUMP: %ux%u -> frame_dump.png\n", w, h);
                }
            }
        }
    }

    g_swapCount++;
    g_vblankCount++;

    // Pump Win32 messages so the window stays responsive.
    HLE_PumpMessages();

    // Blit the current back-buffer contents to the presentation window via GDI.
    if (g_hWnd) {
        // Find the back-buffer pixel data.
        uint32_t bbSurfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);
        if (bbSurfAddr == 0)
            bbSurfAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);

        if (bbSurfAddr != 0) {
            uint32_t bbDataAddr = X86_MEM_READ_u32(base, bbSurfAddr + 4); // Data ptr
            if (bbDataAddr != 0) {
                // Read viewport dimensions to determine buffer size.
                uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
                uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
                if (vpW == 0 || vpH == 0) { vpW = 640; vpH = 480; }

                RECT clientRect;
                GetClientRect(g_hWnd, &clientRect);
                int dstW = clientRect.right - clientRect.left;
                int dstH = clientRect.bottom - clientRect.top;

                // Set up a BITMAPINFO for the A8R8G8B8 pixel buffer.
                BITMAPINFO bmi{};
                bmi.bmiHeader.biSize        = sizeof(BITMAPINFOHEADER);
                bmi.bmiHeader.biWidth       = (LONG)vpW;
                bmi.bmiHeader.biHeight      = -(LONG)vpH; // top-down
                bmi.bmiHeader.biPlanes      = 1;
                bmi.bmiHeader.biBitCount    = 32;
                bmi.bmiHeader.biCompression = BI_RGB;

                HDC hdc = GetDC(g_hWnd);
                StretchDIBits(hdc,
                              0, 0, dstW, dstH,        // dest rect
                              0, 0, (int)vpW, (int)vpH, // src rect
                              base + bbDataAddr,
                              &bmi,
                              DIB_RGB_COLORS,
                              SRCCOPY);
                ReleaseDC(g_hWnd, hdc);
            }
        }
    }

    // ---- Frame pacing: sleep only the remainder of a 16 ms budget ----
    // {
    //     using Clock = std::chrono::high_resolution_clock;
    //     static auto s_lastFrame = Clock::now();
    //     auto now = Clock::now();
    //     auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(now - s_lastFrame);
    //     if (elapsed.count() < 16)
    //         std::this_thread::sleep_for(std::chrono::milliseconds(16) - elapsed);
    //     s_lastFrame = Clock::now();
    // }

    // ---- FPS counter (printed every 60 frames) ----
    // ---- Hot-function dump every 300 frames ----
    // {
    //     using Clock = std::chrono::high_resolution_clock;
    //     static auto s_lastReport = Clock::now();
    //     static uint64_t s_frameCount = 0;
    //     s_frameCount++;
    //     if (s_frameCount % 60 == 0) {
    //         auto now = Clock::now();
    //         double ms = std::chrono::duration<double, std::milli>(now - s_lastReport).count();
    //         fprintf(stderr, "[PERF] 60 frames in %.1f ms (%.1f fps)\n", ms, 60000.0 / ms);
    //         s_lastReport = now;
    //     }
    //     if (s_frameCount % 300 == 0) {
    //         DumpHotFunctions(30);
    //     }
    // }

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

// D3DDevice_SetFlickerFilter  (0x968C0) — 1 arg, ret 4
void D3DDevice_SetFlickerFilter(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_SetSoftDisplayFilter  (0x96910) — 1 arg, ret 4
void D3DDevice_SetSoftDisplayFilter(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Transform
// ============================================================================

// D3DDevice_SetTransform  (0x96760) — 2 args, ret 8
void D3DDevice_SetTransform(X86Context& ctx, uint8_t* base)
{
    uint32_t state   = GuestArg32(ctx, base, 0);
    uint32_t pMatrix = GuestArg32(ctx, base, 1);

    if (pMatrix != 0 && state < 20) {
        uint32_t dst = kDeviceAddr + 0x0A70 + state * 64;
        memcpy(base + dst, base + pMatrix, 64);
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
    fprintf(stderr, "[HLE] D3DDevice_SetRenderTarget(pRT=0x%08X, pDS=0x%08X)\n", pRT, pDS);

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
        fprintf(stderr, "[HLE] SetViewport(x=%u, y=%u, w=%u, h=%u)\n", vpX, vpY, vpW, vpH);
    }
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_GetViewportOffsetAndScale  (0x97E30) — 2 args, ret 8
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
void D3DDevice_SetTexture(X86Context& ctx, uint8_t* base)
{
    uint32_t stage    = GuestArg32(ctx, base, 0);
    uint32_t pTexture = GuestArg32(ctx, base, 1);

    //// Log every unique texture
    //static std::set<uint32_t> s_loggedTex;
    //if (s_loggedTex.find(pTexture) == s_loggedTex.end()) {
    //    fprintf(stderr, "[HLE] SetTexture(stage=%u, tex=0x%08X)\n", stage, pTexture);
    //    s_loggedTex.insert(pTexture);
    //}

    if (stage < 4)
        X86_MEM_WRITE_u32(base, kDeviceAddr + 0x0B00 + stage * 4, pTexture);
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

    //fprintf(stderr, "[HLE] D3DDevice_Clear(count=%u, pRects=0x%08X, flags=0x%X, "
    //                "color=0x%08X, z=%.4f, stencil=%u)\n",
    //        count, pRects, flags, color, zVal, stencil);

    // ---------- Clear colour target ----------
    if (flags & X_D3DCLEAR_TARGET) {
        uint32_t rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceRenderTarget);
        if (rtAddr == 0)
            rtAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceBackBufBase);

        if (rtAddr != 0) {
            uint32_t dataAddr = X86_MEM_READ_u32(base, rtAddr + 4);
            if (dataAddr != 0) {
                // Determine surface dimensions from the viewport.
                uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
                uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
                if (vpW == 0 || vpH == 0) { vpW = 640; vpH = 480; }

                // Build a per-channel mask from the partial clear flags.
                // Xbox allows clearing individual R/G/B/A channels.
                uint32_t channelMask = 0;
                if (flags & X_D3DCLEAR_TARGET_A) channelMask |= 0xFF000000;
                if (flags & X_D3DCLEAR_TARGET_R) channelMask |= 0x00FF0000;
                if (flags & X_D3DCLEAR_TARGET_G) channelMask |= 0x0000FF00;
                if (flags & X_D3DCLEAR_TARGET_B) channelMask |= 0x000000FF;
                bool fullChannelClear = (channelMask == 0xFFFFFFFF);

                uint32_t* pixels = reinterpret_cast<uint32_t*>(base + dataAddr);

                if (pRects == 0 || count == 0) {
                    // Clear the entire surface.
                    uint32_t total = vpW * vpH;
                    if (fullChannelClear) {
                        // Fast path: fill entire buffer.
                        for (uint32_t i = 0; i < total; i++)
                            pixels[i] = color;
                    } else {
                        uint32_t keep = ~channelMask;
                        uint32_t cc   = color & channelMask;
                        for (uint32_t i = 0; i < total; i++)
                            pixels[i] = (pixels[i] & keep) | cc;
                    }
                } else {
                    // Clear individual rectangles.
                    for (uint32_t r = 0; r < count; r++) {
                        uint32_t rectAddr = pRects + r * 16;
                        int32_t x1 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 0);
                        int32_t y1 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 4);
                        int32_t x2 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 8);
                        int32_t y2 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 12);

                        // Clamp to surface dimensions.
                        if (x1 < 0) x1 = 0;
                        if (y1 < 0) y1 = 0;
                        if (x2 > (int32_t)vpW) x2 = (int32_t)vpW;
                        if (y2 > (int32_t)vpH) y2 = (int32_t)vpH;

                        for (int32_t y = y1; y < y2; y++) {
                            for (int32_t x = x1; x < x2; x++) {
                                uint32_t idx = (uint32_t)y * vpW + (uint32_t)x;
                                if (fullChannelClear)
                                    pixels[idx] = color;
                                else
                                    pixels[idx] = (pixels[idx] & ~channelMask) | (color & channelMask);
                            }
                        }
                    }
                }
            }
        }
    }

    // ---------- Clear depth / stencil buffer ----------
    if (flags & (X_D3DCLEAR_ZBUFFER | X_D3DCLEAR_STENCIL)) {
        uint32_t dsAddr = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceDepthStencil);
        if (dsAddr != 0) {
            uint32_t dsData = X86_MEM_READ_u32(base, dsAddr + 4);
            if (dsData != 0) {
                uint32_t vpW = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 8);
                uint32_t vpH = X86_MEM_READ_u32(base, kDeviceAddr + kDeviceViewport + 12);
                if (vpW == 0 || vpH == 0) { vpW = 640; vpH = 480; }
                uint32_t total = vpW * vpH;

                // D24S8 layout: upper 24 bits = depth, lower 8 bits = stencil.
                // Convert float Z [0..1] to 24-bit integer depth.
                uint32_t intZ = (uint32_t)(zVal * 16777215.0f); // 0xFFFFFF
                if (intZ > 0x00FFFFFF) intZ = 0x00FFFFFF;

                uint32_t clearVal = (intZ << 8) | (stencil & 0xFF);
                bool clearZ = (flags & X_D3DCLEAR_ZBUFFER) != 0;
                bool clearS = (flags & X_D3DCLEAR_STENCIL) != 0;

                uint32_t* ds = reinterpret_cast<uint32_t*>(base + dsData);

                auto clearRange = [&](uint32_t start, uint32_t end) {
                    if (clearZ && clearS) {
                        for (uint32_t i = start; i < end; i++)
                            ds[i] = clearVal;
                    } else if (clearZ) {
                        for (uint32_t i = start; i < end; i++)
                            ds[i] = (ds[i] & 0x000000FF) | (intZ << 8);
                    } else { // stencil only
                        uint32_t s8 = stencil & 0xFF;
                        for (uint32_t i = start; i < end; i++)
                            ds[i] = (ds[i] & 0xFFFFFF00) | s8;
                    }
                };

                if (pRects == 0 || count == 0) {
                    clearRange(0, total);
                } else {
                    for (uint32_t r = 0; r < count; r++) {
                        uint32_t rectAddr = pRects + r * 16;
                        int32_t x1 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 0);
                        int32_t y1 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 4);
                        int32_t x2 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 8);
                        int32_t y2 = (int32_t)X86_MEM_READ_u32(base, rectAddr + 12);
                        if (x1 < 0) x1 = 0;
                        if (y1 < 0) y1 = 0;
                        if (x2 > (int32_t)vpW) x2 = (int32_t)vpW;
                        if (y2 > (int32_t)vpH) y2 = (int32_t)vpH;
                        for (int32_t y = y1; y < y2; y++)
                            clearRange((uint32_t)y * vpW + (uint32_t)x1,
                                       (uint32_t)y * vpW + (uint32_t)x2);
                    }
                }
            }
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

    fprintf(stderr, "[HLE] SetScissors(count=%u, exclusive=%u, pRects=0x%08X)\n",
            count, exclusive, pRects);

    if (count > 0 && pRects != 0 && !exclusive) {
        // Store first inclusive scissor rect in device state
        uint32_t left   = X86_MEM_READ_u32(base, pRects + 0);
        uint32_t top    = X86_MEM_READ_u32(base, pRects + 4);
        uint32_t right  = X86_MEM_READ_u32(base, pRects + 8);
        uint32_t bottom = X86_MEM_READ_u32(base, pRects + 12);
        fprintf(stderr, "[HLE]   rect[0] = (%u, %u, %u, %u)\n", left, top, right, bottom);

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

#define DEFINE_SETRENDERSTATE_STUB_RET4(name) \
void name(X86Context& ctx, uint8_t* base) { GuestStackCleanup(ctx, 4); }

DEFINE_SETRENDERSTATE_STUB_RET4(D3DDevice_SetRenderState_PSTextureModes)
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

#undef DEFINE_SETRENDERSTATE_STUB_RET4

// D3DDevice_SetRenderState_FrontFace  (0x981E0) — __fastcall, plain ret
void D3DDevice_SetRenderState_FrontFace(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetRenderState_Simple  (0x97DA0) — __fastcall, plain ret
void D3DDevice_SetRenderState_Simple(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_SetRenderStateNotInline  (0x97DD0) — 2 args, ret 8
void D3DDevice_SetRenderStateNotInline(X86Context& ctx, uint8_t* base)
{
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

// D3DDevice_SetTextureStageStateNotInline  (0x98810) — 3 args, ret 12
void D3DDevice_SetTextureStageStateNotInline(X86Context& ctx, uint8_t* base)
{
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

// D3D_CommonSetMultiSampleModeAndScale  (0x98C90) — 0 args, plain ret
void D3D_CommonSetMultiSampleModeAndScale(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
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

    // One-time diagnostic for texture sampling
    {
        static bool diagDone = false;
        if (!diagDone) {
            diagDone = true;
            fprintf(stderr, "[HLE] RasterTri DIAG: texAddr=0x%08X\n", texAddr);
        }
    }

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

// Submit a batch of vertices as the given primitive type
static void SubmitPrims(uint8_t* base, const SWVertex* verts, size_t n, int primType)
{
    RenderTarget rt;
    if (!GetRT(base, rt)) return;

    auto tri = [&](const SWVertex& a, const SWVertex& b, const SWVertex& c) {
        // Backface cull (D3DCULL_CCW default): skip back-facing triangles
        float cross = (b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y);
        if (cross <= 0.0f) return;
        RasterTri(base, a, b, c, rt);
    };

    switch (primType) {
    case X_D3DPT_TRIANGLELIST:
        for (size_t i = 0; i + 2 < n; i += 3)
            tri(verts[i], verts[i+1], verts[i+2]);
        break;
    case X_D3DPT_TRIANGLESTRIP:
        for (size_t i = 0; i + 2 < n; i++)
            if (i & 1) tri(verts[i+1], verts[i], verts[i+2]);
            else        tri(verts[i], verts[i+1], verts[i+2]);
        break;
    case X_D3DPT_TRIANGLEFAN:
        for (size_t i = 1; i + 1 < n; i++)
            tri(verts[0], verts[i], verts[i+1]);
        break;
    case 8: // X_D3DPT_QUADLIST — Xbox-specific, 4 verts per quad
    case X_D3DPT_QUADLIST:
        for (size_t i = 0; i + 3 < n; i += 4) {
            // No backface cull for screen-space quads — both CW and CCW are valid in
            // y-down screen space depending on how the game submits vertices.
            // Sort the 4 vertices into TL, TR, BR, BL for RasterRect
            const SWVertex* q[4] = { &verts[i], &verts[i+1], &verts[i+2], &verts[i+3] };
            // Sort by Y first (top to bottom), then X (left to right)
            std::sort(q, q + 4, [](const SWVertex* a, const SWVertex* b) {
                return (a->y != b->y) ? (a->y < b->y) : (a->x < b->x);
            });
            // q[0],q[1] are the top two, q[2],q[3] are the bottom two
            // Within each pair, ensure left comes first
            const SWVertex* tl = (q[0]->x <= q[1]->x) ? q[0] : q[1];
            const SWVertex* tr = (q[0]->x <= q[1]->x) ? q[1] : q[0];
            const SWVertex* bl = (q[2]->x <= q[3]->x) ? q[2] : q[3];
            const SWVertex* br = (q[2]->x <= q[3]->x) ? q[3] : q[2];
            RasterRect(base, *tl, *tr, *br, *bl, rt);
        }
        break;
    case X_D3DPT_QUADSTRIP:
        for (size_t i = 0; i + 3 < n; i += 2) {
            tri(verts[i], verts[i+1], verts[i+2]);
            tri(verts[i+1], verts[i+3], verts[i+2]);
        }
        break;
    default:
        break;
    }
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
        if (stride >= 32) fvf = D3DFVF_XYZRHW | D3DFVF_DIFFUSE | (1 << D3DFVF_TEXCOUNT_SHIFT);
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
        // For D3DVSDE_VERTEX, z/w carry UV coords (screen-space position + UV packed)
        if (reg == X_D3DVSDE_VERTEX) {
            g_imCurrent.u = fz;
            g_imCurrent.v = fw;
        }
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
    }
    g_imVertices.clear();
    g_imActive = false;

    GuestStackCleanup(ctx, 0);
}

// ============================================================================
// Vertex / Pixel shaders
// ============================================================================

// D3DDevice_CreateVertexShader  (0x99C70) — 4 args, ret 16
void D3DDevice_CreateVertexShader(X86Context& ctx, uint8_t* base)
{
    uint32_t pHandle = GuestArg32(ctx, base, 2);
    fprintf(stderr, "[HLE] D3DDevice_CreateVertexShader\n");

    static uint32_t s_nextVSHandle = 0xFFFE0000;
    if (pHandle != 0)
        X86_MEM_WRITE_u32(base, pHandle, s_nextVSHandle++);

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

// D3DDevice_LoadVertexShader  (0x99E40) — 2 args, ret 8
void D3DDevice_LoadVertexShader(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SelectVertexShader  (0x99EA0) — 2 args, ret 8
void D3DDevice_SelectVertexShader(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
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
    // On Xbox, if bit 0 is clear the handle IS the FVF code
    if (!(handle & 1))
        g_currentFVF = handle;
    GuestStackCleanup(ctx, 4);
}

// D3DDevice_CreatePixelShader  (0x9B0F0) — 2 args, ret 8
void D3DDevice_CreatePixelShader(X86Context& ctx, uint8_t* base)
{
    uint32_t pHandle = GuestArg32(ctx, base, 1);
    static uint32_t s_nextPSHandle = 0xFFFF0000;
    if (pHandle != 0)
        X86_MEM_WRITE_u32(base, pHandle, s_nextPSHandle++);
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_SetPixelShader  (0x9B140) — 1 arg, ret 4
void D3DDevice_SetPixelShader(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ============================================================================
// Resource management
// ============================================================================

// D3D_DestroyResource  (0x9A350) — 1 arg, ret 4
void D3D_DestroyResource(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE] D3D_DestroyResource(0x%08X)\n", GuestArg32(ctx, base, 0));
    GuestStackCleanup(ctx, 4);
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

// D3DResource_GetType  (0x9A500) — 1 arg, ret 4
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
    GuestStackCleanup(ctx, 4);
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

// D3D_SetTileNoWait  (0x971B0) — 2 args, ret 8
void D3D_SetTileNoWait(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
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
void D3D_CDevice_KickOff(X86Context& ctx, uint8_t* base)
{
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

// D3D_BlockOnTime  (0x9C5C0) — 2 args, ret 8
void D3D_BlockOnTime(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3D_MakeRequestedSpace  (0x9C730) — 2 args, ret 8
void D3D_MakeRequestedSpace(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 8);
}

// D3DDevice_MakeSpace  (0x9C870) — 0 args, plain ret
void D3DDevice_MakeSpace(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 0);
}

// D3DDevice_BeginStateBig  (0x9C880) — 1 arg, ret 4
void D3DDevice_BeginStateBig(X86Context& ctx, uint8_t* base)
{
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 4);
}

// D3D_BlockOnResource  (0x9C8F0) — 1 arg, ret 4
void D3D_BlockOnResource(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
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

// D3D8_Get2DSurfaceDesc  (0x9FFF0) — 3 args, ret 12
void D3D8_Get2DSurfaceDesc(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 12);
}

// D3D8_Lock2DSurface  (0xA02E0) — 6 args, ret 24
void D3D8_Lock2DSurface(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 24);
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


// ============================================================
// Auto-generated D3D stubs (154 functions)
// Each logs once on first call, then no-ops with stack cleanup
// ============================================================

void sub_95AE0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_95AE0 (0x00095AE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_95BC0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_95BC0 (0x00095BC0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_95CE0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_95CE0 (0x00095CE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_95E00(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_95E00 (0x00095E00) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_95F80(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_95F80 (0x00095F80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_96010(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96010 (0x00096010) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_96080(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96080 (0x00096080) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_96200(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96200 (0x00096200) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_963F0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_963F0 (0x000963F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_96500(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96500 (0x00096500) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_96630(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96630 (0x00096630) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_966F0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_966F0 (0x000966F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_96970(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_96970 (0x00096970) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_975E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_975E0 (0x000975E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_98900(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_98900 (0x00098900) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_98970(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_98970 (0x00098970) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_98B60(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_98B60 (0x00098B60) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_99770(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_99770 (0x00099770) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_998B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_998B0 (0x000998B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_99960(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_99960 (0x00099960) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_999D0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_999D0 (0x000999D0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_99B70(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_99B70 (0x00099B70) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9A060(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A060 (0x0009A060) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9A0A0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A0A0 (0x0009A0A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9A300(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A300 (0x0009A300) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9A3F0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A3F0 (0x0009A3F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9A430(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A430 (0x0009A430) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9A5C0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A5C0 (0x0009A5C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9A6E0(X86Context& ctx, uint8_t* base) {
    // return 1
    GuestReturn32(ctx, 1);
    GuestStackCleanup(ctx, 4);
}

void sub_9A6F0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A6F0 (0x0009A6F0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 24);
}

void sub_9A740(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A740 (0x0009A740) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9A7F0(X86Context& ctx, uint8_t* base) {
    // return 0
    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 0);
}

void sub_9A800(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9A800 (0x0009A800) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9AB80(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9AB80 (0x0009AB80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B3A0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B3A0 (0x0009B3A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_9B400(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B400 (0x0009B400) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_9B470(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B470 (0x0009B470) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9B483(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B483 (0x0009B483) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9B4C3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B4C3 (0x0009B4C3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 20);
}

void sub_9B526(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B526 (0x0009B526) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9B55A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B55A (0x0009B55A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B585(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B585 (0x0009B585) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B5C6(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B5C6 (0x0009B5C6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B649(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B649 (0x0009B649) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B6E1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B6E1 (0x0009B6E1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_9B80A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B80A (0x0009B80A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9B89A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B89A (0x0009B89A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9B905(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B905 (0x0009B905) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9B91A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B91A (0x0009B91A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9B938(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9B938 (0x0009B938) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9BA06(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9BA06 (0x0009BA06) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9BBAF(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9BBAF (0x0009BBAF) called\n"); logged = true; }
    GuestStackCleanup(ctx, 28);
}

void sub_9BD9D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9BD9D (0x0009BD9D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9BE5F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9BE5F (0x0009BE5F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C020(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C020 (0x0009C020) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C040(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C040 (0x0009C040) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9C070(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C070 (0x0009C070) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9C0E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C0E0 (0x0009C0E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C180(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C180 (0x0009C180) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C1B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C1B0 (0x0009C1B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C2B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C2B0 (0x0009C2B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C330(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C330 (0x0009C330) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9C3B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C3B0 (0x0009C3B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C490(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C490 (0x0009C490) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9C970(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C970 (0x0009C970) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9C9B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C9B0 (0x0009C9B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9C9C0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9C9C0 (0x0009C9C0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9CA20(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9CA20 (0x0009CA20) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9CA30(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9CA30 (0x0009CA30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9CC40(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9CC40 (0x0009CC40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9CFC0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9CFC0 (0x0009CFC0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9D1B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9D1B0 (0x0009D1B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9D390(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9D390 (0x0009D390) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9D750(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9D750 (0x0009D750) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9D840(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9D840 (0x0009D840) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9DA00(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9DA00 (0x0009DA00) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9DB40(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9DB40 (0x0009DB40) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9DE90(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9DE90 (0x0009DE90) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9E090(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E090 (0x0009E090) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9E2A1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E2A1 (0x0009E2A1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9E323(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E323 (0x0009E323) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9E380(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E380 (0x0009E380) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_9E3E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E3E0 (0x0009E3E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9E4E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E4E0 (0x0009E4E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9E5B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E5B0 (0x0009E5B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9E610(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E610 (0x0009E610) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9E660(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9E660 (0x0009E660) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

void sub_9ECA0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9ECA0 (0x0009ECA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9EDB0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9EDB0 (0x0009EDB0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9F550(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9F550 (0x0009F550) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9FA20(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FA20 (0x0009FA20) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9FBD0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FBD0 (0x0009FBD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_9FBE0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FBE0 (0x0009FBE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9FCA0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FCA0 (0x0009FCA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_9FCD0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FCD0 (0x0009FCD0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9FD10(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FD10 (0x0009FD10) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9FE30(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FE30 (0x0009FE30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_9FEA0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_9FEA0 (0x0009FEA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 28);
}

void sub_A00B0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A00B0 (0x000A00B0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}

void sub_A0380(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0380 (0x000A0380) called\n"); logged = true; }
    GuestStackCleanup(ctx, 40);
}

void sub_A0575(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0575 (0x000A0575) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A05D4(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A05D4 (0x000A05D4) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A064D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A064D (0x000A064D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 28);
}

void sub_A08E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A08E0 (0x000A08E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A0A10(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0A10 (0x000A0A10) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A0AF0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0AF0 (0x000A0AF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A0C00(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0C00 (0x000A0C00) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A0D30(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0D30 (0x000A0D30) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A0DA0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0DA0 (0x000A0DA0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_A0DF0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A0DF0 (0x000A0DF0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A1060(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1060 (0x000A1060) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A1110(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1110 (0x000A1110) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A12A0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A12A0 (0x000A12A0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_A1380(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1380 (0x000A1380) called\n"); logged = true; }
    GuestStackCleanup(ctx, 5);
}

void sub_A13B3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A13B3 (0x000A13B3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A151A(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A151A (0x000A151A) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A1618(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1618 (0x000A1618) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A16E7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A16E7 (0x000A16E7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A171D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A171D (0x000A171D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A174D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A174D (0x000A174D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A17BE(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A17BE (0x000A17BE) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A17FD(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A17FD (0x000A17FD) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A1836(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1836 (0x000A1836) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A1A33(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1A33 (0x000A1A33) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A1A45(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1A45 (0x000A1A45) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_A1BD2(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1BD2 (0x000A1BD2) called\n"); logged = true; }
    GuestStackCleanup(ctx, 20);
}

void sub_A1C0B(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1C0B (0x000A1C0B) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_A1C80(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A1C80 (0x000A1C80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A265F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A265F (0x000A265F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A2782(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A2782 (0x000A2782) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A2803(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A2803 (0x000A2803) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A2A80(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A2A80 (0x000A2A80) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A2B20(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A2B20 (0x000A2B20) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_A30E0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A30E0 (0x000A30E0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A4AE0(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A4AE0 (0x000A4AE0) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A4B1D(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A4B1D (0x000A4B1D) called\n"); logged = true; }
    GuestStackCleanup(ctx, 40);
}

void sub_A4EE6(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A4EE6 (0x000A4EE6) called\n"); logged = true; }
    GuestStackCleanup(ctx, 32);
}

void sub_A500F(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A500F (0x000A500F) called\n"); logged = true; }
    GuestStackCleanup(ctx, 16);
}

void sub_A570C(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A570C (0x000A570C) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A586E(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A586E (0x000A586E) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A5989(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A5989 (0x000A5989) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A5ADB(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A5ADB (0x000A5ADB) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A5C03(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A5C03 (0x000A5C03) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A5D54(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A5D54 (0x000A5D54) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A5EA9(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A5EA9 (0x000A5EA9) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A6092(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A6092 (0x000A6092) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A6095(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A6095 (0x000A6095) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_A60C1(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A60C1 (0x000A60C1) called\n"); logged = true; }
    GuestStackCleanup(ctx, 8);
}

void sub_A60ED(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A60ED (0x000A60ED) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A6D90(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A6D90 (0x000A6D90) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A7325(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A7325 (0x000A7325) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A76A5(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A76A5 (0x000A76A5) called\n"); logged = true; }
    GuestStackCleanup(ctx, 0);
}

void sub_A76D3(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A76D3 (0x000A76D3) called\n"); logged = true; }
    GuestStackCleanup(ctx, 4);
}

void sub_A76F7(X86Context& ctx, uint8_t* base) {
    static bool logged = false;
    if (!logged) { fprintf(stderr, "[HLE-STUB] sub_A76F7 (0x000A76F7) called\n"); logged = true; }
    GuestStackCleanup(ctx, 12);
}

