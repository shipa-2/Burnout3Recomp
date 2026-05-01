// ============================================================================
// NV2A pixel-shader (register combiner) -> HLSL ps_5_0 translator.
//
// Ported loosely from Cxbx-Reloaded's XbPixelShader.cpp / PixelShader.cpp.
// We use only the bit-layout knowledge; we emit HLSL as straight-line
// arithmetic rather than depending on Cxbx's macro template.
// ============================================================================
#include "nv2a_ps_hlsl.h"

#include <array>
#include <cstdio>
#include <sstream>
#include <string>
#include <unordered_set>

namespace Nv2aPsHlsl {
namespace {

// ---- Enums (mirrored from Cxbx-Reloaded/XbPixelShader.h) ------------------

enum PS_TEXTUREMODES {
    PS_TM_NONE                   = 0x00,
    PS_TM_PROJECT2D              = 0x01,
    PS_TM_PROJECT3D              = 0x02,
    PS_TM_CUBEMAP                = 0x03,
    PS_TM_PASSTHRU               = 0x04,
    PS_TM_CLIPPLANE              = 0x05,
    PS_TM_BUMPENVMAP             = 0x06,
    PS_TM_BUMPENVMAP_LUM         = 0x07,
    PS_TM_BRDF                   = 0x08,
    PS_TM_DOT_ST                 = 0x09,
    PS_TM_DOT_ZW                 = 0x0A,
    PS_TM_DOT_RFLCT_DIFF         = 0x0B,
    PS_TM_DOT_RFLCT_SPEC         = 0x0C,
    PS_TM_DOT_STR_3D             = 0x0D,
    PS_TM_DOT_STR_CUBE           = 0x0E,
    PS_TM_DPNDNT_AR              = 0x0F,
    PS_TM_DPNDNT_GB              = 0x10,
    PS_TM_DOTPRODUCT             = 0x11,
    PS_TM_DOT_RFLCT_SPEC_CONST   = 0x12,
    PS_TM_MASK                   = 0x1F,
};

enum PS_REG {
    PS_REG_DISCARD    = 0x00,
    PS_REG_C0         = 0x01,
    PS_REG_C1         = 0x02,
    PS_REG_FOG        = 0x03,
    PS_REG_V0         = 0x04,
    PS_REG_V1         = 0x05,
    PS_REG_T0         = 0x08,
    PS_REG_T1         = 0x09,
    PS_REG_T2         = 0x0A,
    PS_REG_T3         = 0x0B,
    PS_REG_R0         = 0x0C,
    PS_REG_R1         = 0x0D,
    PS_REG_V1R0_SUM   = 0x0E,
    PS_REG_EF_PROD    = 0x0F,
    PS_REG_MASK       = 0x0F,
    PS_REG_FC0        = 0x10, // final-combiner C0 (Cxbx extension)
    PS_REG_FC1        = 0x11, // final-combiner C1 (Cxbx extension)
};

// PS_CHANNEL (bit 0x10): 0 = RGB (or BLUE for alpha src), 1 = ALPHA.
constexpr uint8_t PS_CHANNEL_MASK  = 0x10;
constexpr uint8_t PS_CHANNEL_ALPHA = 0x10;

// PS_INPUTMAPPING (bits 0xE0).
enum PS_INPUTMAPPING : uint8_t {
    IM_UNSIGNED_IDENTITY = 0x00, //  saturate(x)        (for final combiner |x|)
    IM_UNSIGNED_INVERT   = 0x20, //  1 - saturate(x)
    IM_EXPAND_NORMAL     = 0x40, //  2*saturate(x) - 1
    IM_EXPAND_NEGATE     = 0x60, // -2*saturate(x) + 1
    IM_HALFBIAS_NORMAL   = 0x80, //    saturate(x) - 0.5
    IM_HALFBIAS_NEGATE   = 0xA0, //   -saturate(x) + 0.5
    IM_SIGNED_IDENTITY   = 0xC0, //    x
    IM_SIGNED_NEGATE     = 0xE0, //   -x
    IM_MASK              = 0xE0,
};

// PS_COMBINEROUTPUT flags (after PSOutputs >> 12).
constexpr uint32_t COF_CD_DOT     = 0x01;
constexpr uint32_t COF_AB_DOT     = 0x02;
constexpr uint32_t COF_AB_CD_MUX  = 0x04;
constexpr uint32_t COF_CD_B2A     = 0x40;
constexpr uint32_t COF_AB_B2A     = 0x80;
constexpr uint32_t COF_OMAP_MASK  = 0x38;

enum OMAP : uint32_t {
    OMAP_IDENT    = 0x00, // y = x
    OMAP_BIAS     = 0x08, // y = x - 0.5
    OMAP_SL1      = 0x10, // y = x * 2
    OMAP_SL1_BIAS = 0x18, // y = (x - 0.5) * 2
    OMAP_SL2      = 0x20, // y = x * 4
    OMAP_SL2_BIAS = 0x28,
    OMAP_SR1      = 0x30, // y = x / 2
    OMAP_SR1_BIAS = 0x38,
};

// Final combiner flags (low byte of PSFinalCombinerInputsEFG).
constexpr uint8_t FC_COMPLEMENT_R0 = 0x20;
constexpr uint8_t FC_COMPLEMENT_V1 = 0x40;
constexpr uint8_t FC_CLAMP_SUM     = 0x80;

// ---- PSDef field extraction ------------------------------------------------

struct PSDef {
    uint32_t PSAlphaInputs[8];
    uint32_t PSFinalCombinerInputsABCD;
    uint32_t PSFinalCombinerInputsEFG;
    uint32_t PSConstant0[8];
    uint32_t PSConstant1[8];
    uint32_t PSAlphaOutputs[8];
    uint32_t PSRGBInputs[8];
    uint32_t PSCompareMode;
    uint32_t PSFinalCombinerConstant0;
    uint32_t PSFinalCombinerConstant1;
    uint32_t PSRGBOutputs[8];
    uint32_t PSCombinerCount;
    uint32_t PSTextureModes;
    uint32_t PSDotMapping;
    uint32_t PSInputTexture;
    uint32_t PSC0Mapping;
    uint32_t PSC1Mapping;
    uint32_t PSFinalCombinerConstants;
};

static void ReadPSDef(const uint32_t* d, PSDef& p) {
    for (int i = 0; i < 8; ++i) p.PSAlphaInputs[i] = d[i];
    p.PSFinalCombinerInputsABCD = d[8];
    p.PSFinalCombinerInputsEFG  = d[9];
    for (int i = 0; i < 8; ++i) p.PSConstant0[i]    = d[10 + i];
    for (int i = 0; i < 8; ++i) p.PSConstant1[i]    = d[18 + i];
    for (int i = 0; i < 8; ++i) p.PSAlphaOutputs[i] = d[26 + i];
    for (int i = 0; i < 8; ++i) p.PSRGBInputs[i]    = d[34 + i];
    p.PSCompareMode            = d[42];
    p.PSFinalCombinerConstant0 = d[43];
    p.PSFinalCombinerConstant1 = d[44];
    for (int i = 0; i < 8; ++i) p.PSRGBOutputs[i]   = d[45 + i];
    p.PSCombinerCount          = d[53];
    p.PSTextureModes           = d[54];
    p.PSDotMapping             = d[55];
    p.PSInputTexture           = d[56];
    p.PSC0Mapping              = d[57];
    p.PSC1Mapping              = d[58];
    p.PSFinalCombinerConstants = d[59];
}

// ---- Decode -----------------------------------------------------------------

struct InputReg {
    uint8_t reg;            // PS_REG
    uint8_t channel;        // 0 (RGB/BLUE) or 0x10 (ALPHA)
    uint8_t inputMapping;   // PS_INPUTMAPPING
};

struct CombOutput {
    uint8_t reg;            // destination PS_REG (DISCARD=0 means no write)
    bool    dotProduct;     // false=mul, true=dot
    bool    blueToAlpha;    // RGB-only: write .b -> dest.a instead of rgb
    InputReg in[2];         // A/B or C/D
};

struct CombChan {
    CombOutput AB;
    CombOutput CD;
    uint8_t    muxSumReg;   // 3rd output register
    bool       mux;         // false: 3rd = AB + CD; true: 3rd = mux(AB, CD) on r0.a
    uint8_t    outMap;      // OMAP_*
};

struct Stage {
    CombChan rgb;
    CombChan alpha;
};

struct FinalComb {
    InputReg in[7];         // A, B, C, D, E, F, G
    bool     complementR0;
    bool     complementV1;
    bool     clampSum;
    bool     present;
};

static InputReg DecodeInput(uint8_t v, bool isFinal) {
    InputReg r;
    r.reg          = v & PS_REG_MASK;
    r.channel      = v & PS_CHANNEL_MASK;
    r.inputMapping = v & IM_MASK;
    if (isFinal) {
        if (r.reg == PS_REG_C0) r.reg = PS_REG_FC0;
        if (r.reg == PS_REG_C1) r.reg = PS_REG_FC1;
    }
    return r;
}

static CombChan DecodeChannel(uint32_t psIn, uint32_t psOut, bool isRGB) {
    CombChan c{};
    // Inputs: bits 24..31=A, 16..23=B, 8..15=C, 0..7=D.
    c.AB.in[0] = DecodeInput((uint8_t)(psIn >> 24), false);
    c.AB.in[1] = DecodeInput((uint8_t)(psIn >> 16), false);
    c.CD.in[0] = DecodeInput((uint8_t)(psIn >>  8), false);
    c.CD.in[1] = DecodeInput((uint8_t)(psIn >>  0), false);

    c.CD.reg    = (uint8_t)((psOut >> 0) & 0xF);
    c.AB.reg    = (uint8_t)((psOut >> 4) & 0xF);
    c.muxSumReg = (uint8_t)((psOut >> 8) & 0xF);

    uint32_t flags = (psOut >> 12);
    c.AB.dotProduct  = isRGB && (flags & COF_AB_DOT);
    c.CD.dotProduct  = isRGB && (flags & COF_CD_DOT);
    c.mux            = (flags & COF_AB_CD_MUX) != 0;
    c.AB.blueToAlpha = isRGB && (flags & COF_AB_B2A);
    c.CD.blueToAlpha = isRGB && (flags & COF_CD_B2A);
    c.outMap         = (uint8_t)(flags & COF_OMAP_MASK);
    return c;
}

// ---- HLSL emission ---------------------------------------------------------

static const char* RegToHlslName(uint8_t r) {
    switch (r) {
        case PS_REG_DISCARD:   return "_discard";
        case PS_REG_C0:        return "c0";
        case PS_REG_C1:        return "c1";
        case PS_REG_FOG:       return "vFog";
        case PS_REG_V0:        return "v0";
        case PS_REG_V1:        return "v1";
        case PS_REG_T0:        return "t0";
        case PS_REG_T1:        return "t1";
        case PS_REG_T2:        return "t2";
        case PS_REG_T3:        return "t3";
        case PS_REG_R0:        return "r0";
        case PS_REG_R1:        return "r1";
        case PS_REG_V1R0_SUM:  return "v1r0Sum";
        case PS_REG_EF_PROD:   return "efProd";
        case PS_REG_FC0:       return "fc0";
        case PS_REG_FC1:       return "fc1";
    }
    return "_discard";
}

// Emits "(expr)" yielding a float3 for RGB-channel reads or float for alpha.
// `asAlphaScalar` selects single-channel (alpha or blue) read.
static std::string EmitInput(const InputReg& in, bool asAlphaScalar, bool isFinal) {
    const char* name = RegToHlslName(in.reg);
    // Channel selection:
    //   RGB pipe:  Channel=0 -> .rgb,    Channel=ALPHA -> .aaa
    //   Alpha pipe:Channel=0 -> .bbb/.b, Channel=ALPHA -> .aaa/.a
    std::string src;
    if (in.reg == PS_REG_DISCARD) {
        // ZERO register; mappings emit a constant.
        src = asAlphaScalar ? "0.0" : "float3(0,0,0)";
    } else {
        src = name;
        if (asAlphaScalar) {
            src += (in.channel == PS_CHANNEL_ALPHA) ? ".a" : ".b";
        } else {
            src += (in.channel == PS_CHANNEL_ALPHA) ? ".aaa" : ".rgb";
        }
    }

    // Apply input mapping. When register is DISCARD(ZERO), many mappings
    // become constants (1.0, -1.0, 0.5, -0.5 etc.).
    const bool isZero = (in.reg == PS_REG_DISCARD);
    char buf[256];
    switch (in.inputMapping) {
        case IM_UNSIGNED_IDENTITY:
            if (isZero) return asAlphaScalar ? std::string("0.0") : std::string("float3(0,0,0)");
            // NV2A IM_UNSIGNED_IDENTITY clamps the input to >= 0 (negatives
            // become zero). Both stages and the final combiner share this
            // semantic; Xemu (psh.c) emits max(x, 0.0) in both cases. Our
            // previous abs() in the final combiner flipped negative
            // specular lobes back to positive, doubling highlights on
            // metallic surfaces.
            std::snprintf(buf, sizeof(buf), "max(%s, %s)", src.c_str(),
                          asAlphaScalar ? "0.0" : "float3(0,0,0)");
            return buf;
        case IM_UNSIGNED_INVERT:
            if (isZero) return asAlphaScalar ? std::string("1.0") : std::string("float3(1,1,1)");
            std::snprintf(buf, sizeof(buf), "(1.0 - saturate(%s))", src.c_str());
            return buf;
        case IM_EXPAND_NORMAL:
            if (isZero) return asAlphaScalar ? std::string("-1.0") : std::string("float3(-1,-1,-1)");
            std::snprintf(buf, sizeof(buf), "(2.0 * max(0.0, %s) - 1.0)", src.c_str());
            return buf;
        case IM_EXPAND_NEGATE:
            if (isZero) return asAlphaScalar ? std::string("1.0") : std::string("float3(1,1,1)");
            std::snprintf(buf, sizeof(buf), "(1.0 - 2.0 * max(0.0, %s))", src.c_str());
            return buf;
        case IM_HALFBIAS_NORMAL:
            if (isZero) return asAlphaScalar ? std::string("-0.5") : std::string("float3(-0.5,-0.5,-0.5)");
            std::snprintf(buf, sizeof(buf), "(max(0.0, %s) - 0.5)", src.c_str());
            return buf;
        case IM_HALFBIAS_NEGATE:
            if (isZero) return asAlphaScalar ? std::string("0.5") : std::string("float3(0.5,0.5,0.5)");
            std::snprintf(buf, sizeof(buf), "(0.5 - max(0.0, %s))", src.c_str());
            return buf;
        case IM_SIGNED_IDENTITY:
            return src; // straight pass-through
        case IM_SIGNED_NEGATE:
            std::snprintf(buf, sizeof(buf), "(-%s)", src.c_str());
            return buf;
    }
    return src;
}

static const char* OutMapFunc(uint8_t om, bool /*isAlpha*/) {
    switch (om) {
        case OMAP_IDENT:    return "";                 // x
        case OMAP_BIAS:     return "bias";             // x - 0.5
        case OMAP_SL1:      return "sl1";              // x * 2
        case OMAP_SL1_BIAS: return "sl1b";             // (x - 0.5) * 2
        case OMAP_SL2:      return "sl2";              // x * 4
        case OMAP_SL2_BIAS: return "sl2b";
        case OMAP_SR1:      return "sr1";              // x / 2
        case OMAP_SR1_BIAS: return "sr1b";
    }
    return "";
}

// Apply output modifier inline (wraps an expression).
static std::string ApplyOutMap(uint8_t om, const std::string& expr) {
    const char* f = OutMapFunc(om, false);
    if (!*f) return expr;
    return std::string(f) + "(" + expr + ")";
}

// Emit assignment of (clamped) value into destination register.
// dstExpr = "r0", "t2" etc.  maskRGB = ".rgb"/".a"/"".
static void EmitDestWrite(std::stringstream& out, const char* dst, const char* mask,
                          const std::string& valueExpr) {
    out << "        " << dst << mask << " = clamp(" << valueExpr
        << ", -1.0, 1.0);\n";
}

// Emit one combiner channel (RGB or Alpha).  For RGB, ops produce float3;
// for Alpha they produce float (scalar).
static void EmitChannel(std::stringstream& out, const CombChan& c, bool isRGB, int stageIdx) {
    const char* opType = isRGB ? "float3" : "float";
    const bool scalar = !isRGB;

    out << "    // stage " << stageIdx << " " << (isRGB ? "rgb" : "alpha") << "\n";
    out << "    {\n";
    out << "        " << opType << " A = " << EmitInput(c.AB.in[0], scalar, false) << ";\n";
    out << "        " << opType << " B = " << EmitInput(c.AB.in[1], scalar, false) << ";\n";
    out << "        " << opType << " C = " << EmitInput(c.CD.in[0], scalar, false) << ";\n";
    out << "        " << opType << " D = " << EmitInput(c.CD.in[1], scalar, false) << ";\n";

    // AB output
    std::string abExpr;
    if (c.AB.dotProduct && isRGB)
        abExpr = "float3(dot(A, B).xxx)";
    else
        abExpr = "A * B";
    abExpr = ApplyOutMap(c.outMap, abExpr);

    // CD output
    std::string cdExpr;
    if (c.CD.dotProduct && isRGB)
        cdExpr = "float3(dot(C, D).xxx)";
    else
        cdExpr = "C * D";
    cdExpr = ApplyOutMap(c.outMap, cdExpr);

    // MUX_SUM output
    std::string msExpr;
    if (c.mux) {
        // NV2A: if CombinerMuxesOnMsb, select on r0.a >= 0.5, else on LSB (rare).
        msExpr = "(r0.a >= 0.5 ? (C * D) : (A * B))";
    } else {
        msExpr = isRGB ? "((A * B) + (C * D))" : "((A * B) + (C * D))";
    }
    msExpr = ApplyOutMap(c.outMap, msExpr);

    // Write destinations
    out << "        " << opType << " ab_val = " << abExpr << ";\n";
    out << "        " << opType << " cd_val = " << cdExpr << ";\n";
    if (c.AB.reg != PS_REG_DISCARD || c.CD.reg != PS_REG_DISCARD || c.muxSumReg != PS_REG_DISCARD) {
        out << "        " << opType << " ms_val = " << msExpr << ";\n";
    }

    auto writeDest = [&](uint8_t reg, const char* src, bool blueToAlpha) {
        if (reg == PS_REG_DISCARD) return;
        const char* dst = RegToHlslName(reg);
        if (isRGB) {
            if (blueToAlpha) {
                out << "        " << dst << ".a = clamp(((" << src << ").b), -1.0, 1.0);\n";
            } else {
                out << "        " << dst << ".rgb = clamp(" << src << ", -1.0, 1.0);\n";
            }
        } else {
            out << "        " << dst << ".a = clamp(" << src << ", -1.0, 1.0);\n";
        }
    };
    writeDest(c.AB.reg,    "ab_val", c.AB.blueToAlpha);
    writeDest(c.CD.reg,    "cd_val", c.CD.blueToAlpha);
    writeDest(c.muxSumReg, "ms_val", false);

    out << "    }\n";
}

// Emit a texture-stage fetch into tN.
// input_tex[stage] = which prior stage's output to use for dependent reads (-1 if none).
// dot_map[stage]   = dotmap function index (0..7) for dot-product modes.
static void EmitTextureStage(std::stringstream& out, unsigned stage, uint8_t mode,
                             const int input_tex[4], const int dot_map[4],
                             Result& r) {
    const char* tN = nullptr;
    switch (stage) {
        case 0: tN = "t0"; break;
        case 1: tN = "t1"; break;
        case 2: tN = "t2"; break;
        case 3: tN = "t3"; break;
        default: return;
    }
    const char* inT = nullptr;
    switch (stage) {
        case 0: inT = "input.oT0"; break;
        case 1: inT = "input.oT1"; break;
        case 2: inT = "input.oT2"; break;
        case 3: inT = "input.oT3"; break;
    }
    const char* samp = "sampler0";
    const char* tex2d = nullptr;
    switch (stage) {
        case 0: samp = "sampler0"; tex2d = "tex2D0"; break;
        case 1: samp = "sampler1"; tex2d = "tex2D1"; break;
        case 2: samp = "sampler2"; tex2d = "tex2D2"; break;
        case 3: samp = "sampler3"; tex2d = "tex2D3"; break;
    }

    switch (mode) {
        case PS_TM_NONE:
            out << "    " << tN << " = float4(0,0,0,0);\n";
            break;
        case PS_TM_PROJECT2D:
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xy / max(" << inT << ".w, 1e-6));\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        case PS_TM_PROJECT3D:
            // Stub as 2D project; we don't have volume textures wired up.
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xy / max(" << inT << ".w, 1e-6));\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        case PS_TM_CUBEMAP:
        // NV2A "dot-product reflect" modes: final stage of a 3-stage
        // chain that builds a reflection/normal vector and samples a
        // cubemap. The VS typically pre-writes the reflection vector
        // into oT.xyz of this stage, so as an approximation we sample
        // the cube directly using oT.xyz (matches what most Xbox
        // titles including Burnout 3 set up).
        case PS_TM_DOT_RFLCT_DIFF:       // 0x0B
        case PS_TM_DOT_RFLCT_SPEC:       // 0x0C
        case PS_TM_DOT_STR_CUBE:         // 0x0E
        case PS_TM_DOT_RFLCT_SPEC_CONST: // 0x12
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xyz);\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        case PS_TM_PASSTHRU:
            out << "    " << tN << " = " << inT << ";\n";
            r.usesStage[stage] = true;
            break;
        case PS_TM_CLIPPLANE: {
            // Discard the pixel if any of the texture coordinate components
            // fail the clip test. PSCompareMode[stage][j] = 1 means ">= 0"
            // passes; 0 means "< 0" passes. We use the conservative approach
            // of discarding outside the range [0, 1] for all components since
            // we don't plumb PSCompareMode through yet.
            out << "    " << tN << " = float4(0,0,0,0);\n";
            out << "    if (" << inT << ".x < 0.0 || " << inT << ".y < 0.0 || "
                << inT << ".z < 0.0 || " << inT << ".w < 0.0) discard;\n";
            r.usesStage[stage] = true;
            break;
        }
        case PS_TM_BUMPENVMAP:
        case PS_TM_BUMPENVMAP_LUM: {
            // Bump-environment mapping: read signed (ds,dt) offset from a
            // prior stage's texture (input_tex[stage]), apply the bump
            // environment matrix, then add to this stage's UV and sample.
            // We don't have the bumpMat cbuffer hooked up yet, so we use
            // an identity transform (ds,dt passed through unchanged). This
            // gives incorrect scale/rotation but at least samples the bumped
            // region of the texture rather than the unbumped UV.
            int src = (stage < 4 && input_tex[stage] >= 0) ? input_tex[stage] : 0;
            // Source texture names t0..t3
            const char* srcNames[4] = {"t0","t1","t2","t3"};
            const char* srcT = srcNames[src < 4 ? src : 0];
            // sign3: convert unsigned [0,1] float8 → signed [-1,1] (NV2A BUMPENVMAP convention)
            // ds from .b channel, dt from .g channel
            out << "    {\n";
            out << "        float2 _dsdt = float2(\n"
                << "            (" << srcT << ".b * 255.0 >= 128.0 ? (" << srcT << ".b * 255.0 - 256.0) / 127.0 : " << srcT << ".b * 255.0 / 127.0),\n"
                << "            (" << srcT << ".g * 255.0 >= 128.0 ? (" << srcT << ".g * 255.0 - 256.0) / 127.0 : " << srcT << ".g * 255.0 / 127.0));\n";
            out << "        " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xy + _dsdt);\n";
            if (mode == PS_TM_BUMPENVMAP_LUM) {
                // Luminance modulation: t *= (bumpScale * lum + bumpOffset)
                // Without uniforms, skip the scale (leave as is).
                // A proper implementation needs bumpScale[stage]/bumpOffset[stage].
            }
            out << "    }\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        }
        case PS_TM_DPNDNT_AR: {
            // Dependent texture read using alpha + red channels from input stage.
            int src = (stage < 4 && input_tex[stage] >= 0) ? input_tex[stage] : 0;
            const char* srcNames[4] = {"t0","t1","t2","t3"};
            const char* srcT = srcNames[src < 4 ? src : 0];
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << srcT << ".ar);\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        }
        case PS_TM_DPNDNT_GB: {
            // Dependent texture read using green + blue channels from input stage.
            int src = (stage < 4 && input_tex[stage] >= 0) ? input_tex[stage] : 0;
            const char* srcNames[4] = {"t0","t1","t2","t3"};
            const char* srcT = srcNames[src < 4 ? src : 0];
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << srcT << ".gb);\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        }
        case PS_TM_DOT_ST: {
            // Dot-product of texture coordinate with input normal-map texel.
            // Contributes one component to a multi-stage chain; sample this stage.
            int src = (stage < 4 && input_tex[stage] >= 0) ? input_tex[stage] : 0;
            const char* srcNames[4] = {"t0","t1","t2","t3"};
            const char* srcT = srcNames[src < 4 ? src : 0];
            // Compute dot product of pT.xyz with the decoded normal.
            out << "    {\n";
            out << "        float _dot" << stage << " = dot(" << inT << ".xyz, " << srcT << ".rgb * 2.0 - 1.0);\n";
            out << "        float2 _dotST = float2(_dot" << stage << ", _dot" << (stage > 0 ? stage-1 : 0) << ");\n";
            out << "        " << tN << " = " << tex2d << ".Sample(" << samp << ", _dotST);\n";
            out << "    }\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        }
        case PS_TM_DOT_ZW:
        case PS_TM_DOTPRODUCT: {
            // Dot-product stages that don't sample (contribute to later stages).
            out << "    " << tN << " = float4(0,0,0,0);\n";
            r.usesStage[stage] = true;
            break;
        }
        case PS_TM_DOT_STR_3D: {
            // 3-stage dot product chain → 3D texture lookup. Approximate as 2D.
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xy / max(" << inT << ".w, 1e-6));\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
        }
        case PS_TM_BRDF:
        default:
            // For unimplemented modes fall back to plain 2D sample.
            out << "    " << tN << " = " << tex2d << ".Sample(" << samp
                << ", " << inT << ".xy);\n";
            r.usesStage[stage] = true;
            r.samplesStage[stage] = true;
            break;
    }
}

// ---- Top-level Translate ---------------------------------------------------

static Result TranslateImpl(const uint32_t* d) {
    Result r;
    if (!d) { r.error = "null psdef"; return r; }

    PSDef p{};
    ReadPSDef(d, p);

    // Export the baked PSConstant0/1 and final-combiner constants so the
    // caller can seed its runtime pixel-shader constant shadow for this PS.
    for (int i = 0; i < 8; ++i) r.bakedC0[i] = p.PSConstant0[i];
    for (int i = 0; i < 8; ++i) r.bakedC1[i] = p.PSConstant1[i];
    r.bakedFc0 = p.PSFinalCombinerConstant0;
    r.bakedFc1 = p.PSFinalCombinerConstant1;

    const unsigned numComb = p.PSCombinerCount & 0xF;
    const uint32_t ccFlags = p.PSCombinerCount >> 8;
    const bool muxOnMsb    = (ccFlags & 0x01) != 0;
    const bool hasFC = (p.PSFinalCombinerInputsABCD != 0) || (p.PSFinalCombinerInputsEFG != 0);
    r.numCombiners = numComb;

    // Decode texture modes.
    uint8_t texMode[4];
    for (int i = 0; i < 4; ++i)
        texMode[i] = (uint8_t)((p.PSTextureModes >> (i * 5)) & PS_TM_MASK);

    // Diagnostic: report PS shaders that use cubemap/reflection sampling.
    {
        static int s_cubePsLog = 0;
        bool anyCube = false;
        for (int i = 0; i < 4; ++i) {
            uint8_t m = texMode[i];
            if (m == PS_TM_CUBEMAP
             || m == PS_TM_DOT_RFLCT_DIFF
             || m == PS_TM_DOT_RFLCT_SPEC
             || m == PS_TM_DOT_STR_CUBE
             || m == PS_TM_DOT_RFLCT_SPEC_CONST)
                anyCube = true;
        }
        if (anyCube && s_cubePsLog < 16) {
            fprintf(stderr, "[PS] cube/reflect PS: modes=[0x%02X,0x%02X,0x%02X,0x%02X] PSTextureModes=0x%08X\n",
                    texMode[0], texMode[1], texMode[2], texMode[3], p.PSTextureModes);
            ++s_cubePsLog;
        }
    }
    // Diagnostic: log EVERY unique PSTextureModes so we can see what modes
    // the game actually uses (cube reflection modes are 0x03/0x0B/0x0C/
    // 0x0E/0x12 — anything other than 00/01/04 is interesting).
    {
        static std::unordered_set<uint32_t> s_allModes;
        if (s_allModes.insert(p.PSTextureModes).second && s_allModes.size() <= 64) {
            fprintf(stderr, "[PS] PSTextureModes=0x%08X -> [0x%02X,0x%02X,0x%02X,0x%02X]\n",
                    p.PSTextureModes, texMode[0], texMode[1], texMode[2], texMode[3]);
        }
    }

    // Decode stages.
    Stage stages[8] = {};
    for (unsigned i = 0; i < numComb && i < 8; ++i) {
        stages[i].rgb   = DecodeChannel(p.PSRGBInputs[i],   p.PSRGBOutputs[i],   true);
        stages[i].alpha = DecodeChannel(p.PSAlphaInputs[i], p.PSAlphaOutputs[i], false);
    }

    // Decode final combiner.
    FinalComb fc{};
    fc.present = hasFC;
    if (hasFC) {
        fc.in[0] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsABCD >> 24), true);
        fc.in[1] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsABCD >> 16), true);
        fc.in[2] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsABCD >>  8), true);
        fc.in[3] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsABCD >>  0), true);
        fc.in[4] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsEFG  >> 24), true);
        fc.in[5] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsEFG  >> 16), true);
        fc.in[6] = DecodeInput((uint8_t)(p.PSFinalCombinerInputsEFG  >>  8), true);
        uint8_t fcFlags = (uint8_t)(p.PSFinalCombinerInputsEFG & 0xFF);
        fc.complementR0 = (fcFlags & FC_COMPLEMENT_R0) != 0;
        fc.complementV1 = (fcFlags & FC_COMPLEMENT_V1) != 0;
        fc.clampSum     = (fcFlags & FC_CLAMP_SUM)     != 0;
    }

    (void)muxOnMsb; // currently always assume MSB

    // Decode dot-mapping functions and input texture indices from PSDotMapping
    // and PSInputTexture (mirrors Xemu's other_stage_input).
    // input_tex[stage]: which prior stage's texture is used as the input for
    //   dependent / bump reads. -1 means no prior stage.
    //   input_tex[0] = -1 (always), input_tex[1] = 0 (always), 2 and 3 from PSInputTexture.
    // dot_map[stage]: dotmap function index 0..7 used for DOT_* modes.
    //   dot_map[0] = 0, dot_map[1..3] from PSDotMapping nibbles.
    int input_tex[4] = { -1, 0, 0, 1 };
    input_tex[2] = (int)((p.PSInputTexture >> 16) & 0xF);
    input_tex[3] = (int)((p.PSInputTexture >> 20) & 0xF);
    int dot_map[4] = { 0, 0, 0, 0 };
    dot_map[1] = (int)((p.PSDotMapping >>  0) & 0xF);
    dot_map[2] = (int)((p.PSDotMapping >>  4) & 0xF);
    dot_map[3] = (int)((p.PSDotMapping >>  8) & 0xF);

    std::stringstream o;
    o << "// auto-generated from X_D3DPIXELSHADERDEF\n";
    o << "cbuffer PSConstants : register(b0) { float4 psC[32]; };\n";
    auto isCubeMode = [](uint8_t m) {
        return m == PS_TM_CUBEMAP
            || m == PS_TM_DOT_RFLCT_DIFF
            || m == PS_TM_DOT_RFLCT_SPEC
            || m == PS_TM_DOT_STR_CUBE
            || m == PS_TM_DOT_RFLCT_SPEC_CONST;
    };
    for (unsigned s = 0; s < 4; ++s) {
        const char* texType = isCubeMode(texMode[s]) ? "TextureCube" : "Texture2D";
        o << texType << " tex2D" << s << " : register(t" << s << "); "
          << "SamplerState sampler" << s << " : register(s" << s << ");\n";
    }
    o << "\n";
    o << "struct PSInput {\n";
    o << "    float4 pos   : SV_POSITION;\n";
    o << "    float4 oD0   : COLOR0;\n";
    o << "    float4 oD1   : COLOR1;\n";
    o << "    float4 oFog  : FOG;\n";
    o << "    float4 oT0   : TEXCOORD0;\n";
    o << "    float4 oT1   : TEXCOORD1;\n";
    o << "    float4 oT2   : TEXCOORD2;\n";
    o << "    float4 oT3   : TEXCOORD3;\n";
    o << "};\n\n";

    // Helper output modifier functions.
    o << "float3 bias(float3 x) { return x - 0.5; }\n";
    o << "float  bias(float  x) { return x - 0.5; }\n";
    o << "float3 sl1 (float3 x) { return x * 2.0; }\n";
    o << "float  sl1 (float  x) { return x * 2.0; }\n";
    o << "float3 sl1b(float3 x) { return (x - 0.5) * 2.0; }\n";
    o << "float  sl1b(float  x) { return (x - 0.5) * 2.0; }\n";
    o << "float3 sl2 (float3 x) { return x * 4.0; }\n";
    o << "float  sl2 (float  x) { return x * 4.0; }\n";
    o << "float3 sl2b(float3 x) { return (x - 0.5) * 4.0; }\n";
    o << "float  sl2b(float  x) { return (x - 0.5) * 4.0; }\n";
    o << "float3 sr1 (float3 x) { return x * 0.5; }\n";
    o << "float  sr1 (float  x) { return x * 0.5; }\n";
    o << "float3 sr1b(float3 x) { return (x - 0.5) * 0.5; }\n";
    o << "float  sr1b(float  x) { return (x - 0.5) * 0.5; }\n\n";

    o << "float4 main(PSInput input) : SV_Target {\n";
    // Bind pixel-shader registers from VS outputs.
    o << "    float4 v0 = input.oD0;\n";
    o << "    float4 v1 = input.oD1;\n";
    o << "    float4 vFog = input.oFog;\n";
    // HACK: our emulator doesn't track the fog render state or upload
    // c[120] (NV2A fog range / params), so VS programs that compute oFog
    // from MIN(clipZ, c[120].z) end up emitting ~0, which the PS final
    // combiner then uses to pick 100% fog colour (also 0) -> pitch-black
    // map. Until fog state is plumbed through, force a no-fog factor of 1.
    // Cars are unaffected because their VS doesn't write oFog (so the VS
    // default of 1.0 reaches us anyway); maps DO write oFog and need the
    // clobber.
    o << "    vFog = float4(1,1,1,1);\n";
    // Texture stages -> t0..t3.
    o << "    float4 t0 = float4(0,0,0,0);\n";
    o << "    float4 t1 = float4(0,0,0,0);\n";
    o << "    float4 t2 = float4(0,0,0,0);\n";
    o << "    float4 t3 = float4(0,0,0,0);\n";
    for (unsigned s = 0; s < 4; ++s)
        EmitTextureStage(o, s, texMode[s], input_tex, dot_map, r);
    // r0/r1/c0/c1: initialised to zero / shader-local constants.
    // On Xbox, r0.a = t0.a before combiners run (and r1.a = t1.a).
    o << "    float4 r0 = float4(0,0,0, t0.a);\n";
    o << "    float4 r1 = float4(0,0,0, t1.a);\n";
    // Per-stage constants (c0/c1) come from the host cbuffer psC[0..15],
    // laid out as { PSConstant0[0..7] at psC[0..7], PSConstant1[0..7] at
    // psC[8..15] }. The host seeds these from the PSDef's baked defaults at
    // SetPixelShader time and overrides them on D3DDevice_SetPixelShaderConstant.
    o << "    float4 c0 = float4(0,0,0,0);\n";
    o << "    float4 c1 = float4(0,0,0,0);\n";
    o << "    float4 fc0 = float4(0,0,0,0);\n";
    o << "    float4 fc1 = float4(0,0,0,0);\n";
    o << "    float4 v1r0Sum = float4(0,0,0,0);\n";
    o << "    float4 efProd  = float4(0,0,0,0);\n";
    o << "    float4 _discard = float4(0,0,0,0);\n";

    // Final-combiner constants. PSFinalCombinerConstants (d[59]) encodes:
    //   bits[3:0]  = fc0_slot: which C0-bank slot (0-7) fc0 reads from.
    //                0xF (or > 7) means "use baked PSFinalCombinerConstant0"
    //                → psC[16] (the dedicated baked slot in our cbuffer).
    //   bits[7:4]  = fc1_slot: same for C1-bank (psC[8+slot]).
    //                0xF (or > 7) means "use baked PSFinalCombinerConstant1"
    //                → psC[17].
    //   bit[8]     = FogAlpha flag (unused in HLSL emission here).
    // The baked PSDef values (p.PSFinalCombinerConstant0/1) are exported via
    // Result::bakedFc0/bakedFc1 so the host seeds psC[16]/[17].
    {
        unsigned fc0_slot = p.PSFinalCombinerConstants & 0xFu;
        unsigned fc1_slot = (p.PSFinalCombinerConstants >> 4) & 0xFu;
        if (fc0_slot <= 7)
            o << "    fc0 = psC[" << fc0_slot << "];\n";
        else
            o << "    fc0 = psC[16];\n";  // baked fallback
        if (fc1_slot <= 7)
            o << "    fc1 = psC[" << (8u + fc1_slot) << "];\n";
        else
            o << "    fc1 = psC[17];\n";  // baked fallback
    }

    // Emit combiner stages (with per-stage c0/c1 from PSConstant0/1 mapped
    // via PSC0Mapping/PSC1Mapping: 4-bit slot index per stage).
    for (unsigned s = 0; s < numComb && s < 8; ++s) {
        unsigned c0Slot = (p.PSC0Mapping >> (s * 4)) & 0xF;
        unsigned c1Slot = (p.PSC1Mapping >> (s * 4)) & 0xF;
        if (c0Slot > 7) c0Slot = s;
        if (c1Slot > 7) c1Slot = s;
        // Pull from host cbuffer: C0 bank at psC[0..7], C1 bank at psC[8..15].
        o << "    c0 = psC[" << c0Slot << "];\n";
        o << "    c1 = psC[" << (8u + c1Slot) << "];\n";
        EmitChannel(o, stages[s].rgb,   true,  (int)s);
        EmitChannel(o, stages[s].alpha, false, (int)s);
    }

    if (fc.present) {
        // Final combiner:
        //   prod = E * F
        //   sum  = (complement? 1-r0 : r0) + (complement? 1-v1 : v1)  [optionally clamped]
        //   r0.rgb = A*B + (1-A)*C + D
        //   r0.a   = G
        // NOTE: v1r0Sum and efProd are "derived" final-combiner registers
        // that the A..G input selectors may reference (input codes 6 and 7).
        // They MUST be computed before we capture A..G, otherwise any input
        // mapped to them reads stale zeros (observed on Burnout 3 garage
        // shader: final-combiner D = v1r0Sum was always 0, dropping the
        // detail-blend term and producing noise-looking output).
        o << "    {\n";
        // Pre-compute the derived registers from the (still-current) stage
        // results in r0/v1/tN/cN.  Note: complement flags are NV2A's
        // per-final-combiner bits; they apply specifically to the
        // r0 + v1 summation inputs.
        {
            std::string r0t = fc.complementR0 ? std::string("(1.0 - r0.rgb)") : std::string("r0.rgb");
            std::string v1t = fc.complementV1 ? std::string("(1.0 - v1.rgb)") : std::string("v1.rgb");
            o << "        float3 _sum = " << r0t << " + " << v1t << ";\n";
            if (fc.clampSum) o << "        _sum = saturate(_sum);\n";
            o << "        v1r0Sum.rgb = _sum;\n";
            // efProd uses the F and E inputs; because EmitInput reads the
            // *same* registers that may themselves alias efProd, we compute
            // E*F from the pre-efProd state first and publish it before A..G.
            o << "        efProd.rgb = " << EmitInput(fc.in[4], false, true)
              << " * " << EmitInput(fc.in[5], false, true) << ";\n";
        }
        o << "        float3 A = " << EmitInput(fc.in[0], false, true) << ";\n";
        o << "        float3 B = " << EmitInput(fc.in[1], false, true) << ";\n";
        o << "        float3 C = " << EmitInput(fc.in[2], false, true) << ";\n";
        o << "        float3 D = " << EmitInput(fc.in[3], false, true) << ";\n";
        o << "        float  G = " << EmitInput(fc.in[6], true,  true) << ";\n";
        o << "        float3 rgb = A * B + (float3(1,1,1) - A) * C + D;\n";
        o << "        r0 = float4(rgb, G);\n";
        o << "    }\n";
    }
    // When no final combiner: r0 already contains the last stage result.

    o << "    float4 outc = saturate(r0);\n";
    o << "    return outc;\n";
    o << "}\n";

    r.hlsl = o.str();
    r.ok = true;
    return r;
}

} // namespace

Result Translate(const uint32_t* psDefDwords) {
    return TranslateImpl(psDefDwords);
}

} // namespace Nv2aPsHlsl
