// ============================================================================
// NV2A vertex-shader microcode -> HLSL translator.
//
// Ported (very loosely) from Cxbx-Reloaded's nv2a_vsh.cpp (which itself is
// QEMU-derived, GPL). The goal is to take the Xbox XVS function tokens
// captured at D3DDevice_CreateVertexShader time and produce an HLSL vs_5_0
// program that can be fed to D3DCompile at runtime.
//
// The emitted HLSL:
//   - Declares `cbuffer VSConstants : register(b0) { float4 c[192]; };`
//     (mirrors the existing NV2A constant upload path in hle_d3d.cpp).
//   - Declares an input struct derived from the declaration token stream
//     (.decl.bin), one field per used v-register.
//   - Declares an output struct covering SV_Position, COLOR0/1, FOG and
//     TEXCOORD0..3.
//   - Translates each NV2A instruction into the equivalent HLSL using
//     op-specific macros (MOV/MUL/DP4/RCP/...).
//
// The result also includes a D3D11_INPUT_ELEMENT_DESC[] that matches the
// input struct so the caller can build an ID3D11InputLayout.
// ============================================================================

#pragma once

#include <cstdint>
#include <cstddef>
#include <string>
#include <vector>
#include <d3d11.h>

struct Nv2aVsResult {
    bool                                   ok = false;
    std::string                            hlsl;

    // Backing storage for the SemanticName pointers in inputLayout — the
    // D3D11 API expects stable C strings; keep them alive here.
    std::vector<std::string>               semanticNames;
    std::vector<D3D11_INPUT_ELEMENT_DESC>  inputLayout;

    // Computed vertex stride in bytes (sum of per-element sizes). The actual
    // stride used at draw time comes from SetStreamSource, but this lets the
    // caller sanity-check.
    uint32_t                               vertexStride = 0;

    // For diagnostics.
    std::string                            error;
    uint32_t                               instructionCount = 0;
};

// Fix up the SemanticName pointers in inputLayout to point at
// semanticNames[i].c_str(). Call after copying the result to a new home.
void Nv2aVsResult_FixupPointers(Nv2aVsResult& r);

// funcTokens points at the .func.bin content, i.e. [header, then 4-DWORD
// instructions]. funcBytes is sizeof those DWORDs.
// declTokens points at the .decl.bin content (raw D3DVSD_ tokens ending in
// 0xFFFFFFFF). May be null/empty — a default Burnout-3-style layout is then
// used as a best-effort fallback.
Nv2aVsResult TranslateNV2AtoHLSL(const uint32_t* funcTokens, size_t funcBytes,
                                 const uint32_t* declTokens, size_t declBytes);
