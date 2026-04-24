// ============================================================================
// NV2A pixel-shader (register combiner) -> HLSL ps_5_0 translator.
//
// Takes an X_D3DPIXELSHADERDEF (60 DWORDs) captured at
// D3DDevice_CreatePixelShader time and produces an HLSL pixel shader that
// mirrors the NV2A register combiners' semantics.
//
// Output signature matches Burnout 3's VS output (see nv2a_vsh_hlsl.cpp):
//   COLOR0 (oD0) = diffuse  -> pixel register V0
//   COLOR1 (oD1) = specular -> pixel register V1
//   TEXCOORDn    (oTn)      -> pixel register Tn (used as texcoord or vector)
//   FOG          (oFog)     -> pixel register FOG
//
// The translator covers the common subset used by Burnout 3 garage/car
// shaders: NONE, PROJECT2D, PASSTHRU, CUBEMAP texture modes, up to 8 RGB+Alpha
// combiner stages and the final combiner.
// ============================================================================
#pragma once

#include <cstdint>
#include <string>

namespace Nv2aPsHlsl {

// Number of DWORDs in X_D3DPIXELSHADERDEF (enough for Decode()).
static constexpr size_t kPsDefDwordCount = 60;

struct Result {
    bool        ok = false;
    std::string hlsl;
    std::string error;
    // Which texture stages are sampled (based on PSTextureModes != NONE / PASSTHRU).
    bool        samplesStage[4] = {false, false, false, false};
    // Which texture stages are needed at all (includes PASSTHRU).
    bool        usesStage[4] = {false, false, false, false};
    // Number of active combiners (0..8).
    unsigned    numCombiners = 0;
    // Baked default values from the PSDef (0xAARRGGBB packed). Callers should
    // seed their pixel-shader constant shadow with these at SetPixelShader
    // time so that shaders which don't call SetPixelShaderConstant at runtime
    // still see the constants the game authored into the shader definition.
    //   bakedC0[i] <- PSConstant0[i] (X_D3DRS_PSCONSTANT0_i, i in 0..7)
    //   bakedC1[i] <- PSConstant1[i] (X_D3DRS_PSCONSTANT1_i, i in 0..7)
    uint32_t    bakedC0[8]  = {};
    uint32_t    bakedC1[8]  = {};
    uint32_t    bakedFc0    = 0;
    uint32_t    bakedFc1    = 0;
};

// Translate a PSDef (exactly kPsDefDwordCount DWORDs, little-endian).
Result Translate(const uint32_t* psDefDwords);

} // namespace Nv2aPsHlsl
