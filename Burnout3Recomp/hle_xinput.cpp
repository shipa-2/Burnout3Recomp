#include "x86_recomp_shared.h"
#include "kernel/function.h"
#include <cstdio>
#include <cstring>

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Xinput.h>

// ---------------------------------------------------------------------------
// Xbox XInput / XDevice HLE — Maps host XInput / keyboard to OG Xbox input.
//
// OG Xbox XINPUT_GAMEPAD layout (packed, 18 bytes):
//   uint16_t  wButtons;            // digital buttons (DPAD, Start, Back, Thumbs)
//   uint8_t   bAnalogButtons[8];   // [0]=A [1]=B [2]=X [3]=Y
//                                  // [4]=Black(=RB) [5]=White(=LB)
//                                  // [6]=LTrigger [7]=RTrigger
//   int16_t   sThumbLX, sThumbLY;  // left stick
//   int16_t   sThumbRX, sThumbRY;  // right stick
//
// OG Xbox XINPUT_STATE (22 bytes):
//   uint32_t  dwPacketNumber;
//   XINPUT_GAMEPAD  Gamepad;         // 18 bytes
// ---------------------------------------------------------------------------

// Xbox wButtons bit masks (same values as PC XInput for the digital buttons)
static constexpr uint16_t XPAD_DPAD_UP     = 0x0001;
static constexpr uint16_t XPAD_DPAD_DOWN   = 0x0002;
static constexpr uint16_t XPAD_DPAD_LEFT   = 0x0004;
static constexpr uint16_t XPAD_DPAD_RIGHT  = 0x0008;
static constexpr uint16_t XPAD_START       = 0x0010;
static constexpr uint16_t XPAD_BACK        = 0x0020;
static constexpr uint16_t XPAD_LTHUMB      = 0x0040;
static constexpr uint16_t XPAD_RTHUMB      = 0x0080;

// bAnalogButtons indices
static constexpr int XPAD_A      = 0;
static constexpr int XPAD_B      = 1;
static constexpr int XPAD_X      = 2;
static constexpr int XPAD_Y      = 3;
static constexpr int XPAD_BLACK  = 4;   // maps to RB on modern controllers
static constexpr int XPAD_WHITE  = 5;   // maps to LB on modern controllers
static constexpr int XPAD_LTRIG  = 6;
static constexpr int XPAD_RTRIG  = 7;

static constexpr uint32_t XBOX_ERROR_DEVICE_NOT_CONNECTED = 0x48F;  // 1167
static constexpr uint32_t XBOX_ERROR_SUCCESS = 0;

// Fake handles for opened controllers (port 0–3)
static constexpr uint32_t FAKE_HANDLE_BASE = 0xD00D0000;

// State
static uint32_t g_packetNumber = 0;
static bool     g_deviceInited = false;
static bool     g_pendingInsertion = false;  // set after XInitDevices, cleared after reported once

// ---------------------------------------------------------------------------
// Read host input and translate to OG Xbox format.
// Writes 18 bytes of Xbox XINPUT_GAMEPAD to guest memory at `gamepadAddr`.
// Returns the wButtons value for convenience.
// ---------------------------------------------------------------------------
static void PollHostInput(uint8_t* base, uint32_t gamepadAddr)
{
    uint16_t wButtons = 0;
    uint8_t  analog[8] = {};
    int16_t  lx = 0, ly = 0, rx = 0, ry = 0;

    // --- Try host XInput first (gamepad) ---
    XINPUT_STATE hostState = {};
    bool haveGamepad = (XInputGetState(0, &hostState) == ERROR_SUCCESS);

    if (haveGamepad) {
        const auto& gp = hostState.Gamepad;

        // Digital buttons — direct mapping
        if (gp.wButtons & XINPUT_GAMEPAD_DPAD_UP)     wButtons |= XPAD_DPAD_UP;
        if (gp.wButtons & XINPUT_GAMEPAD_DPAD_DOWN)   wButtons |= XPAD_DPAD_DOWN;
        if (gp.wButtons & XINPUT_GAMEPAD_DPAD_LEFT)   wButtons |= XPAD_DPAD_LEFT;
        if (gp.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT)  wButtons |= XPAD_DPAD_RIGHT;
        if (gp.wButtons & XINPUT_GAMEPAD_START)        wButtons |= XPAD_START;
        if (gp.wButtons & XINPUT_GAMEPAD_BACK)         wButtons |= XPAD_BACK;
        if (gp.wButtons & XINPUT_GAMEPAD_LEFT_THUMB)   wButtons |= XPAD_LTHUMB;
        if (gp.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)  wButtons |= XPAD_RTHUMB;

        // Face buttons → analog (0 or 0xFF)
        if (gp.wButtons & XINPUT_GAMEPAD_A) analog[XPAD_A] = 0xFF;
        if (gp.wButtons & XINPUT_GAMEPAD_B) analog[XPAD_B] = 0xFF;
        if (gp.wButtons & XINPUT_GAMEPAD_X) analog[XPAD_X] = 0xFF;
        if (gp.wButtons & XINPUT_GAMEPAD_Y) analog[XPAD_Y] = 0xFF;

        // Shoulder → Black/White
        if (gp.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) analog[XPAD_BLACK] = 0xFF;
        if (gp.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER)  analog[XPAD_WHITE] = 0xFF;

        // Triggers (PC: 0-255, Xbox: 0-255 — direct copy)
        analog[XPAD_LTRIG] = gp.bLeftTrigger;
        analog[XPAD_RTRIG] = gp.bRightTrigger;

        // Sticks
        lx = gp.sThumbLX;
        ly = gp.sThumbLY;
        rx = gp.sThumbRX;
        ry = gp.sThumbRY;
    }

    // --- Keyboard fallback (always merged in) ---
    auto key = [](int vk) -> bool { return (GetAsyncKeyState(vk) & 0x8000) != 0; };

    // WASD → Left stick
    if (key('W'))      ly =  32767;
    if (key('S'))      ly = -32768;
    if (key('A'))      lx = -32768;
    if (key('D'))      lx =  32767;

    // Arrow keys → DPAD
    if (key(VK_UP))    wButtons |= XPAD_DPAD_UP;
    if (key(VK_DOWN))  wButtons |= XPAD_DPAD_DOWN;
    if (key(VK_LEFT))  wButtons |= XPAD_DPAD_LEFT;
    if (key(VK_RIGHT)) wButtons |= XPAD_DPAD_RIGHT;

    // Common key mappings
    if (key(VK_RETURN) || key('K'))  analog[XPAD_A] = 0xFF;      // Enter/K → A
    if (key(VK_ESCAPE) || key('L'))  analog[XPAD_B] = 0xFF;      // Esc/L → B
    if (key('J'))                    analog[XPAD_X] = 0xFF;       // J → X
    if (key('I'))                    analog[XPAD_Y] = 0xFF;       // I → Y
    if (key('Q'))                    analog[XPAD_WHITE] = 0xFF;   // Q → White/LB
    if (key('E'))                    analog[XPAD_BLACK] = 0xFF;   // E → Black/RB
    if (key('Z'))                    analog[XPAD_LTRIG] = 0xFF;   // Z → LT
    if (key('C'))                    analog[XPAD_RTRIG] = 0xFF;   // C → RT
    if (key(VK_SPACE))               wButtons |= XPAD_START;      // Space → Start
    if (key(VK_BACK))                wButtons |= XPAD_BACK;       // Backspace → Back

    // Write OG Xbox XINPUT_GAMEPAD (18 bytes, packed)
    X86_MEM_WRITE_u16(base, gamepadAddr + 0, wButtons);
    for (int i = 0; i < 8; i++)
        X86_MEM_WRITE_u8(base, gamepadAddr + 2 + i, analog[i]);
    X86_MEM_WRITE_u16(base, gamepadAddr + 10, (uint16_t)lx);
    X86_MEM_WRITE_u16(base, gamepadAddr + 12, (uint16_t)ly);
    X86_MEM_WRITE_u16(base, gamepadAddr + 14, (uint16_t)rx);
    X86_MEM_WRITE_u16(base, gamepadAddr + 16, (uint16_t)ry);
}

// ---------------------------------------------------------------------------
// XInitDevices  (address 0xDD50F)
// void __stdcall XInitDevices(DWORD dwPreallocTypeCount,
//                             PXDEVICE_PREALLOC_TYPE PreallocTypes)
// 2 args, ret 0x08
// ---------------------------------------------------------------------------
void XInitDevices(X86Context& ctx, uint8_t* base)
{
    uint32_t count = GuestArg32(ctx, base, 0);
    uint32_t types = GuestArg32(ctx, base, 1);
    fprintf(stderr, "[HLE] XInitDevices(count=%u, types=0x%08X)\n", count, types);

    g_deviceInited = true;
    g_pendingInsertion = true;  // trigger a fake device insertion on next XGetDeviceChanges call

    GuestReturn32(ctx, 0);
    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// XInitDevices_0  (address 0xDE2B0)  — thunk to XInitDevices
// ---------------------------------------------------------------------------
void XInitDevices_0(X86Context& ctx, uint8_t* base)
{
    XInitDevices(ctx, base);
}

// ---------------------------------------------------------------------------
// XGetDevices  (address 0xDE2B5)
// Returns bitmask of connected device slots.
// Bit 0 = port 0, etc.  We report port 0 connected.
// 1 arg, ret 0x04
// ---------------------------------------------------------------------------
void XGetDevices(X86Context& ctx, uint8_t* base)
{
    fprintf(stderr, "[HLE] XGetDevices -> 0x1 (port 0 connected)\n");
    // Report gamepad on port 0
    GuestReturn32(ctx, 1);
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// XGetDeviceChanges  (address 0xDE2D7)
// BOOL __stdcall XGetDeviceChanges(PXPP_DEVICE_TYPE DeviceType,
//                                  PDWORD pdwInsertions,
//                                  PDWORD pdwRemovals)
// 3 args, ret 0x0C
// ---------------------------------------------------------------------------
void XGetDeviceChanges(X86Context& ctx, uint8_t* base)
{
    uint32_t pInsertions = GuestArg32(ctx, base, 1);
    uint32_t pRemovals   = GuestArg32(ctx, base, 2);

    if (g_pendingInsertion) {
        // Report gamepad on port 0 as newly inserted (bit 0 = port 0)
        if (pInsertions) X86_MEM_WRITE_u32(base, pInsertions, 1);
        if (pRemovals)   X86_MEM_WRITE_u32(base, pRemovals,   0);
        g_pendingInsertion = false;
        fprintf(stderr, "[HLE] XGetDeviceChanges -> insertion on port 0\n");
        GuestReturn32(ctx, 1);  // TRUE — changes occurred
    } else {
        if (pInsertions) X86_MEM_WRITE_u32(base, pInsertions, 0);
        if (pRemovals)   X86_MEM_WRITE_u32(base, pRemovals,   0);
        GuestReturn32(ctx, 0);  // FALSE — no changes
    }
    GuestStackCleanup(ctx, 12);
}

// ---------------------------------------------------------------------------
// XInputOpen  (address 0xDDFAE)
// HANDLE __stdcall XInputOpen(PXPP_DEVICE_TYPE DeviceType,
//                             DWORD dwPort, DWORD dwSlot,
//                             PXINPUT_POLLING_PARAMETERS pPollingParams)
// Returns a fake handle for port 0, NULL for others.
// 4 args, ret 0x10
// ---------------------------------------------------------------------------
void XInputOpen(X86Context& ctx, uint8_t* base)
{
    uint32_t port = GuestArg32(ctx, base, 1);
    uint32_t slot = GuestArg32(ctx, base, 2);
    fprintf(stderr, "[HLE] XInputOpen(port=%u, slot=%u)", port, slot);

    uint32_t handle = 0;
    if (port == 0) {
        handle = FAKE_HANDLE_BASE | port;
        fprintf(stderr, " -> 0x%08X\n", handle);
    } else {
        fprintf(stderr, " -> NULL (unsupported port)\n");
    }

    GuestReturn32(ctx, handle);
    GuestStackCleanup(ctx, 16);
}

// ---------------------------------------------------------------------------
// XInputClose  (address 0xDE004)
// void __stdcall XInputClose(HANDLE hDevice)
// 1 arg, ret 0x04
// ---------------------------------------------------------------------------
void XInputClose(X86Context& ctx, uint8_t* base)
{
    GuestStackCleanup(ctx, 4);
}

// ---------------------------------------------------------------------------
// XInputGetCapabilities  (address 0xDE010)
// DWORD __stdcall XInputGetCapabilities(HANDLE hDevice,
//                                       PXINPUT_CAPABILITIES pCapabilities)
// 2 args, ret 0x08
// ---------------------------------------------------------------------------
void XInputGetCapabilities(X86Context& ctx, uint8_t* base)
{
    uint32_t hDevice = GuestArg32(ctx, base, 0);
    uint32_t pCaps   = GuestArg32(ctx, base, 1);

    if ((hDevice & 0xFFFF0000) != FAKE_HANDLE_BASE || pCaps == 0) {
        GuestReturn32(ctx, XBOX_ERROR_DEVICE_NOT_CONNECTED);
        GuestStackCleanup(ctx, 8);
        return;
    }

    // Xbox XINPUT_CAPABILITIES (packed):
    //   +0   uint8_t  SubType
    //   +1   uint16_t Reserved
    //   +3   XINPUT_GAMEPAD In.Gamepad (18 bytes) — max ranges
    //   +21  XINPUT_RUMBLE  Out.Rumble (4 bytes)
    // Total: 25 bytes
    memset(base + pCaps, 0, 25);
    X86_MEM_WRITE_u8(base,  pCaps + 0, 0x01);   // SubType = GAMEPAD
    X86_MEM_WRITE_u16(base, pCaps + 1, 0);       // Reserved

    // In.Gamepad — report all buttons available
    X86_MEM_WRITE_u16(base, pCaps + 3, 0x00FF);  // wButtons: all digital
    for (int i = 0; i < 8; i++)
        X86_MEM_WRITE_u8(base, pCaps + 5 + i, 0xFF); // all analog buttons
    // Sticks: full range
    X86_MEM_WRITE_u16(base, pCaps + 13, 0x7FFF);
    X86_MEM_WRITE_u16(base, pCaps + 15, 0x7FFF);
    X86_MEM_WRITE_u16(base, pCaps + 17, 0x7FFF);
    X86_MEM_WRITE_u16(base, pCaps + 19, 0x7FFF);

    // Out.Rumble
    X86_MEM_WRITE_u16(base, pCaps + 21, 0xFFFF);
    X86_MEM_WRITE_u16(base, pCaps + 23, 0xFFFF);

    GuestReturn32(ctx, XBOX_ERROR_SUCCESS);
    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// XInputGetState  (address 0xDE1E8)
// DWORD __stdcall XInputGetState(HANDLE hDevice, PXINPUT_STATE pState)
// 2 args, ret 0x08
//
// Xbox XINPUT_STATE (22 bytes):
//   +0   uint32_t  dwPacketNumber
//   +4   XINPUT_GAMEPAD  Gamepad (18 bytes)
// ---------------------------------------------------------------------------
void XInputGetState(X86Context& ctx, uint8_t* base)
{
    uint32_t hDevice = GuestArg32(ctx, base, 0);
    uint32_t pState  = GuestArg32(ctx, base, 1);

    if ((hDevice & 0xFFFF0000) != FAKE_HANDLE_BASE || pState == 0) {
        GuestReturn32(ctx, XBOX_ERROR_DEVICE_NOT_CONNECTED);
        GuestStackCleanup(ctx, 8);
        return;
    }

    g_packetNumber++;
    X86_MEM_WRITE_u32(base, pState + 0, g_packetNumber);
    PollHostInput(base, pState + 4);

    uint16_t btn = X86_MEM_READ_u16(base, pState + 4);
    uint8_t analog0 = X86_MEM_READ_u8(base, pState + 6); // A button
    uint8_t analog1 = X86_MEM_READ_u8(base, pState + 7); // B button

    // Always log when any input is detected
    // if (btn != 0 || analog0 != 0 || analog1 != 0) {
    //     fprintf(stderr, "[HLE] XInputGetState INPUT DETECTED: pkt=%u, wButtons=0x%04X, A=%u, B=%u\n",
    //             g_packetNumber, btn, analog0, analog1);
    // }

    //static int s_getLog = 0;
    //if (s_getLog < 10) {
    //    fprintf(stderr, "[HLE] XInputGetState(pkt=%u, wButtons=0x%04X, A=%u)\n",
    //            g_packetNumber, btn, analog0);
    //    s_getLog++;
    //}

    GuestReturn32(ctx, XBOX_ERROR_SUCCESS);
    GuestStackCleanup(ctx, 8);
}

// ---------------------------------------------------------------------------
// XInputSetState  (address 0xDE25B)
// DWORD __stdcall XInputSetState(HANDLE hDevice, PXINPUT_FEEDBACK pFeedback)
// 2 args, ret 0x08
// ---------------------------------------------------------------------------
void XInputSetState(X86Context& ctx, uint8_t* base)
{
    uint32_t hDevice = GuestArg32(ctx, base, 0);

    if ((hDevice & 0xFFFF0000) != FAKE_HANDLE_BASE) {
        GuestReturn32(ctx, XBOX_ERROR_DEVICE_NOT_CONNECTED);
        GuestStackCleanup(ctx, 8);
        return;
    }

    // Accept rumble silently (no host rumble forwarding for now)
    GuestReturn32(ctx, XBOX_ERROR_SUCCESS);
    GuestStackCleanup(ctx, 8);
}
