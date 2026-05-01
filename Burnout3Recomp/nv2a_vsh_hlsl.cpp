// ============================================================================
// NV2A vertex-shader microcode -> HLSL translator.
// See nv2a_vsh_hlsl.h for scope; the core field-bit layouts and opcode
// tables are ported verbatim from Cxbx-Reloaded / QEMU's nv2a_vsh.cpp (GPL).
// ============================================================================

#include "nv2a_vsh_hlsl.h"

#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

namespace {

// ---------------------------------------------------------------------------
// Field layout (from Cxbx / QEMU nv2a_vsh)
// ---------------------------------------------------------------------------
enum VshFieldName {
    FLD_ILU = 0,
    FLD_MAC,
    FLD_CONST,
    FLD_V,
    FLD_A_NEG, FLD_A_SWZ_X, FLD_A_SWZ_Y, FLD_A_SWZ_Z, FLD_A_SWZ_W, FLD_A_R, FLD_A_MUX,
    FLD_B_NEG, FLD_B_SWZ_X, FLD_B_SWZ_Y, FLD_B_SWZ_Z, FLD_B_SWZ_W, FLD_B_R, FLD_B_MUX,
    FLD_C_NEG, FLD_C_SWZ_X, FLD_C_SWZ_Y, FLD_C_SWZ_Z, FLD_C_SWZ_W,
    FLD_C_R_HIGH, FLD_C_R_LOW, FLD_C_MUX,
    FLD_OUT_MAC_MASK, FLD_OUT_R, FLD_OUT_ILU_MASK, FLD_OUT_O_MASK,
    FLD_OUT_ORB, FLD_OUT_ADDRESS, FLD_OUT_MUX,
    FLD_A0X, FLD_FINAL
};

struct Mapping { uint8_t sub, start, len; };
static const Mapping field_mapping[] = {
    /*FLD_ILU*/           {1, 25, 3},
    /*FLD_MAC*/           {1, 21, 4},
    /*FLD_CONST*/         {1, 13, 8},
    /*FLD_V*/             {1,  9, 4},
    /*FLD_A_NEG*/         {1,  8, 1},
    /*FLD_A_SWZ_X*/       {1,  6, 2},
    /*FLD_A_SWZ_Y*/       {1,  4, 2},
    /*FLD_A_SWZ_Z*/       {1,  2, 2},
    /*FLD_A_SWZ_W*/       {1,  0, 2},
    /*FLD_A_R*/           {2, 28, 4},
    /*FLD_A_MUX*/         {2, 26, 2},
    /*FLD_B_NEG*/         {2, 25, 1},
    /*FLD_B_SWZ_X*/       {2, 23, 2},
    /*FLD_B_SWZ_Y*/       {2, 21, 2},
    /*FLD_B_SWZ_Z*/       {2, 19, 2},
    /*FLD_B_SWZ_W*/       {2, 17, 2},
    /*FLD_B_R*/           {2, 13, 4},
    /*FLD_B_MUX*/         {2, 11, 2},
    /*FLD_C_NEG*/         {2, 10, 1},
    /*FLD_C_SWZ_X*/       {2,  8, 2},
    /*FLD_C_SWZ_Y*/       {2,  6, 2},
    /*FLD_C_SWZ_Z*/       {2,  4, 2},
    /*FLD_C_SWZ_W*/       {2,  2, 2},
    /*FLD_C_R_HIGH*/      {2,  0, 2},
    /*FLD_C_R_LOW*/       {3, 30, 2},
    /*FLD_C_MUX*/         {3, 28, 2},
    /*FLD_OUT_MAC_MASK*/  {3, 24, 4},
    /*FLD_OUT_R*/         {3, 20, 4},
    /*FLD_OUT_ILU_MASK*/  {3, 16, 4},
    /*FLD_OUT_O_MASK*/    {3, 12, 4},
    /*FLD_OUT_ORB*/       {3, 11, 1},
    /*FLD_OUT_ADDRESS*/   {3,  3, 8},
    /*FLD_OUT_MUX*/       {3,  2, 1},
    /*FLD_A0X*/           {3,  1, 1},
    /*FLD_FINAL*/         {3,  0, 1},
};

static inline uint32_t vsh_get(const uint32_t* t, VshFieldName f) {
    const Mapping& m = field_mapping[f];
    return (t[m.sub] >> m.start) & ((1u << m.len) - 1u);
}

// ---------------------------------------------------------------------------
// Opcode tables
// ---------------------------------------------------------------------------
enum VshParameterType { PARAM_UNKNOWN = 0, PARAM_R, PARAM_V, PARAM_C };
enum VshOutputType    { OUTPUT_C = 0, OUTPUT_O };
enum VshOutputMux     { OMUX_MAC = 0, OMUX_ILU };

enum VshILU { ILU_NOP = 0, ILU_MOV, ILU_RCP, ILU_RCC, ILU_RSQ, ILU_EXP, ILU_LOG, ILU_LIT };
enum VshMAC {
    MAC_NOP = 0, MAC_MOV, MAC_MUL, MAC_ADD, MAC_MAD,
    MAC_DP3, MAC_DPH, MAC_DP4, MAC_DST,
    MAC_MIN, MAC_MAX, MAC_SLT, MAC_SGE, MAC_ARL
};

static const char* mac_opcode[] = {
    "NOP", "MOV", "MUL", "ADD", "MAD",
    "DP3", "DPH", "DP4", "DST",
    "MIN", "MAX", "SLT", "SGE", "ARL"
};
static const char* ilu_opcode[] = {
    "NOP", "MOV", "RCP", "RCC", "RSQ", "EXP", "LOG", "LIT"
};

struct OpParams { bool A, B, C; };
static const OpParams mac_opcode_params[] = {
    /*NOP*/ {false,false,false}, /*MOV*/ {true,false,false},
    /*MUL*/ {true,true,false},   /*ADD*/ {true,false,true},
    /*MAD*/ {true,true,true},    /*DP3*/ {true,true,false},
    /*DPH*/ {true,true,false},   /*DP4*/ {true,true,false},
    /*DST*/ {true,true,false},   /*MIN*/ {true,true,false},
    /*MAX*/ {true,true,false},   /*SLT*/ {true,true,false},
    /*SGE*/ {true,true,false},   /*ARL*/ {true,false,false},
};
static const OpParams ilu_opcode_params[] = {
    {false,false,false}, {false,false,true}, {false,false,true}, {false,false,true},
    {false,false,true},  {false,false,true}, {false,false,true}, {false,false,true},
};
static const bool ilu_force_scalar[] = {
    false, false, true, true, true, true, true, false
};

static const char* out_reg_name[] = {
    "oPos","???","???","oD0","oD1","oFog","oPts","oB0",
    "oB1","oT0","oT1","oT2","oT3","???","???","A0x"
};

// Translate NV2A output register index -> HLSL local that backs it.
// Index is the 4-bit FLD_OUT_ADDRESS field value.
static const char* out_local_name(int idx) {
    switch (idx) {
    case 0:  return "oPos";  // aliased with R12 (write-only in SV_Position)
    case 3:  return "oD0";
    case 4:  return "oD1";
    case 5:  return "oFog";
    case 6:  return "oPts";
    case 7:  return "oB0";
    case 8:  return "oB1";
    case 9:  return "oT0";
    case 10: return "oT1";
    case 11: return "oT2";
    case 12: return "oT3";
    case 15: return "A0x";   // ARL destination alias
    default: return nullptr;
    }
}

#define VSH_D3DSCM_CORRECTION 96
static int16_t convert_c_register(int16_t c_reg) {
    int16_t r = ((((c_reg >> 5) & 7) - 3) * 32) + (c_reg & 31);
    r += VSH_D3DSCM_CORRECTION;
    return r;
}

// ---------------------------------------------------------------------------
// Swizzle / source operand decoding (HLSL flavour)
// ---------------------------------------------------------------------------
// Unlike the GLSL reference we ALWAYS emit a full 4-component expression
// (or an empty suffix, meaning "whole float4") so that the per-operand
// expression produced is always usable as a float4. Writemasks on the
// LHS are still 1..4 letters.

static std::string decode_swizzle_full4(const uint32_t* tok,
                                        VshFieldName swz_x_field) {
    static const char sw[] = "xyzw";
    int x = vsh_get(tok, swz_x_field);
    int y = vsh_get(tok, (VshFieldName)(swz_x_field + 1));
    int z = vsh_get(tok, (VshFieldName)(swz_x_field + 2));
    int w = vsh_get(tok, (VshFieldName)(swz_x_field + 3));

    // For ILU input C with scalar ops, the hw replicates the X swizzle.
    if (swz_x_field == FLD_C_SWZ_X &&
        ilu_force_scalar[vsh_get(tok, FLD_ILU)]) {
        y = z = w = x;
    }

    if (x == 0 && y == 1 && z == 2 && w == 3)
        return std::string(); // identity => use variable directly (still float4)

    char buf[6] = { '.', sw[x], sw[y], sw[z], sw[w], 0 };
    return std::string(buf);
}

// LHS writemask produced as letter chain ("x", "xy", "xyzw"), NO leading dot.
// mask is 4-bit xyzw with x in bit 3, w in bit 0.
static std::string writemask_letters(uint32_t mask) {
    std::string out;
    if (mask & 0x8) out += 'x';
    if (mask & 0x4) out += 'y';
    if (mask & 0x2) out += 'z';
    if (mask & 0x1) out += 'w';
    return out;
}

// Fog register special-case writemask (mirrors Xemu fog_mask_str[]).
// NV2A writes to oFog always put the most-significant masked component into
// oFog.x so the PSH can reliably read the fog factor from oFog.x.
// Index is the raw 4-bit FLD_OUT_O_MASK value (bit3=x, bit2=y, bit1=z, bit0=w).
static const char* fog_mask_letters[16] = {
    "x",    // 0000 (empty → default x so fog.x gets something)
    "x",    // 0001 ___w → x
    "x",    // 0010 __z_ → x
    "xy",   // 0011 __zw → xy
    "x",    // 0100 _y__ → x
    "xy",   // 0101 _y_w → xy
    "xy",   // 0110 _yz_ → xy
    "xyz",  // 0111 _yzw → xyz
    "x",    // 1000 x___ → x
    "xy",   // 1001 x__w → xy
    "xy",   // 1010 x_z_ → xy
    "xyz",  // 1011 x_zw → xyz
    "xy",   // 1100 xy__ → xy
    "xyz",  // 1101 xy_w → xyz
    "xyz",  // 1110 xyz_ → xyz
    "xyzw", // 1111
};

static std::string decode_opcode_input(const uint32_t* tok,
                                       VshParameterType param,
                                       VshFieldName neg_field,
                                       int reg_num) {
    std::string out;
    if (vsh_get(tok, neg_field) > 0) out += "-";

    char tmp[48];
    switch (param) {
    case PARAM_R:
        std::snprintf(tmp, sizeof(tmp), "R%d", reg_num);
        out += tmp;
        break;
    case PARAM_V:
        reg_num = vsh_get(tok, FLD_V);
        std::snprintf(tmp, sizeof(tmp), "vReg[%d]", reg_num);
        out += tmp;
        break;
    case PARAM_C: {
        int16_t raw = (int16_t)vsh_get(tok, FLD_CONST);
        int16_t idx = convert_c_register(raw);
        if (vsh_get(tok, FLD_A0X) > 0) {
            std::snprintf(tmp, sizeof(tmp), "c[A0 + %d]", idx);
        } else {
            std::snprintf(tmp, sizeof(tmp), "c[%d]", idx);
        }
        out += tmp;
        break;
    }
    default:
        out += "/*bad param*/float4(0,0,0,0)";
        break;
    }

    // swizzle field is 1 past the NEG field
    std::string sw = decode_swizzle_full4(tok, (VshFieldName)(neg_field + 1));
    if (!sw.empty()) {
        // Parenthesize negation so that -R0.zzzz doesn't get parsed as -R0 with
        // an unexpected suffix; HLSL is fine with -(R0).zzzz but be explicit.
        if (!out.empty() && out[0] == '-') {
            // rewrite "-X" => "-(X).sw"
            std::string inner = out.substr(1);
            out = "-(" + inner + ")" + sw;
        } else {
            out += sw;
        }
    } else if (!out.empty() && out[0] == '-') {
        std::string inner = out.substr(1);
        out = "-(" + inner + ")";
    }
    return out;
}

// Emit one call to a MAC/ILU macro. `opcode_name` is e.g. "MUL", "DP4" etc.
// `inputs` is the comma-prefixed argument list string (", a, b" or ", a")
// already including the swizzled operand expressions.
static std::string decode_opcode(const uint32_t* tok,
                                 VshOutputMux out_mux,
                                 uint32_t mask,
                                 const char* opcode_name,
                                 const std::string& inputs) {
    std::ostringstream ret;
    int reg_num = (int)vsh_get(tok, FLD_OUT_R);

    if (out_mux == OMUX_MAC
        && vsh_get(tok, FLD_ILU) != ILU_NOP
        && reg_num == 1) {
        // Paired MAC writing to R1 is ignored when ILU is present
        mask = 0;
    } else if (out_mux == OMUX_ILU && vsh_get(tok, FLD_MAC) != MAC_NOP) {
        // Paired ILU opcode can only write R1
        reg_num = 1;
    }

    if (std::strcmp(opcode_name, "ARL") == 0) {
        ret << "  ARL(A0" << inputs << ");\n";
    } else if (mask != 0) {
        std::string m = writemask_letters(mask);
        ret << "  " << opcode_name << "(R" << reg_num << ", " << m
            << inputs << ");\n";
    }

    // Muxed secondary output (same ALU feeding an o-register or c-register).
    if ((uint32_t)vsh_get(tok, FLD_OUT_MUX) == (uint32_t)out_mux
        && vsh_get(tok, FLD_OUT_O_MASK) != 0) {

        std::string dst;
        bool isFogReg = false;
        if ((VshOutputType)vsh_get(tok, FLD_OUT_ORB) == OUTPUT_C) {
            // Writable const register — not emulated. Route to a scratch to
            // avoid HLSL errors; the cbuffer `c[]` can't be written.
            dst = "/*wrC_skipped*/ R0";
        } else {
            int oidx = vsh_get(tok, FLD_OUT_ADDRESS) & 0xF;
            const char* nm = out_local_name(oidx);
            dst = nm ? nm : "R0";
            isFogReg = (oidx == 5); // OUTPUT_REG_FOG
        }
        // For oFog writes, NV2A always routes the most-significant masked
        // component to oFog.x so the PSH can read fog.x reliably.
        uint32_t omask = vsh_get(tok, FLD_OUT_O_MASK);
        std::string m = isFogReg ? std::string(fog_mask_letters[omask & 0xF])
                                 : writemask_letters(omask);
        if (!m.empty())
            ret << "  " << opcode_name << "(" << dst << ", " << m
                << inputs << ");\n";
    }

    return ret.str();
}

// One 128-bit instruction -> emitted HLSL statements.
static std::string decode_token(const uint32_t* tok) {
    std::string out;

    // Decode input C once, used by both MAC and ILU.
    int c_rnum = ((int)vsh_get(tok, FLD_C_R_HIGH) << 2)
               |  (int)vsh_get(tok, FLD_C_R_LOW);
    std::string input_c = decode_opcode_input(
        tok, (VshParameterType)vsh_get(tok, FLD_C_MUX),
        FLD_C_NEG, c_rnum);

    VshMAC mac = (VshMAC)vsh_get(tok, FLD_MAC);
    if (mac != MAC_NOP) {
        std::string inputs;
        if (mac_opcode_params[mac].A) {
            std::string a = decode_opcode_input(
                tok, (VshParameterType)vsh_get(tok, FLD_A_MUX),
                FLD_A_NEG, (int)vsh_get(tok, FLD_A_R));
            inputs += ", "; inputs += a;
        }
        if (mac_opcode_params[mac].B) {
            std::string b = decode_opcode_input(
                tok, (VshParameterType)vsh_get(tok, FLD_B_MUX),
                FLD_B_NEG, (int)vsh_get(tok, FLD_B_R));
            inputs += ", "; inputs += b;
        }
        if (mac_opcode_params[mac].C) {
            inputs += ", "; inputs += input_c;
        }
        out += decode_opcode(tok, OMUX_MAC,
                             vsh_get(tok, FLD_OUT_MAC_MASK),
                             mac_opcode[mac], inputs);
    }

    VshILU ilu = (VshILU)vsh_get(tok, FLD_ILU);
    if (ilu != ILU_NOP) {
        std::string inputs = ", " + input_c;
        out += decode_opcode(tok, OMUX_ILU,
                             vsh_get(tok, FLD_OUT_ILU_MASK),
                             ilu_opcode[ilu], inputs);
    }

    return out;
}

// ---------------------------------------------------------------------------
// HLSL prologue: opcode macros + register decls. Tokens produced by the
// decoder use MUL(R0.xy, a, b), DP4(R1.x, ..) etc.
// ---------------------------------------------------------------------------
static const char* kHlslPrologue = R"HLSL(
// NV2A opcode implementations. Each macro takes a destination register, a
// writemask letter chain (e.g. xy, xyzw), and its source operands. Both LHS
// and RHS use the same mask so component counts match in HLSL.
#define MOV(d,m,a)         d.m = (a).m
#define MUL(d,m,a,b)       d.m = ((a) * (b)).m
#define ADD(d,m,a,b)       d.m = ((a) + (b)).m
#define MAD(d,m,a,b,c)     d.m = ((a) * (b) + (c)).m
#define DP3(d,m,a,b)       d.m = ((float4)dot((a).xyz, (b).xyz)).m
#define DPH(d,m,a,b)       d.m = ((float4)dot(float4((a).xyz, 1.0f), (b))).m
#define DP4(d,m,a,b)       d.m = ((float4)dot((a), (b))).m
#define DST(d,m,a,b)       d.m = float4(1.0f, (a).y * (b).y, (a).z, (b).w).m
#define MIN(d,m,a,b)       d.m = min((a), (b)).m
#define MAX(d,m,a,b)       d.m = max((a), (b)).m
#define SLT(d,m,a,b)       d.m = ((float4)((a) < (b))).m
#define SGE(d,m,a,b)       d.m = ((float4)((a) >= (b))).m
#define ARL(d,a)           d = (int)floor((a).x + 0.001f)

#define RCP(d,m,a)         d.m = ((float4)(1.0f / (a).x)).m
#define RCC(d,m,a)         d.m = _nv2a_rcc((a).x).m
#define RSQ(d,m,a)         d.m = ((float4)rsqrt(abs((a).x))).m
#define EXP(d,m,a)         d.m = _nv2a_exp((a).x).m
#define LOG(d,m,a)         d.m = _nv2a_log((a).x).m
#define LIT(d,m,a)         d.m = _nv2a_lit((a)).m

float4 _nv2a_rcc(float s) {
    float t = 1.0f / s;
    float c = (t > 0.0f)
        ? clamp(t,  5.42101e-20f,  1.884467e+19f)
        : clamp(t, -1.884467e+19f, -5.42101e-20f);
    return (float4)c;
}
float4 _nv2a_exp(float s) {
    float f = floor(s);
    return float4(exp2(f), s - f, exp2(s), 1.0f);
}
float4 _nv2a_log(float s) {
    float t = abs(s);
    float fl = floor(log2(t));
    return float4(fl, t / exp2(fl), log2(t), 1.0f);
}
float4 _nv2a_lit(float4 src) {
    float eps = 1.0f / 256.0f;
    float sw  = clamp(src.w, -(128.0f - eps), 128.0f - eps);
    float sx  = max(src.x, 0.0f);
    float sy  = max(src.y, 0.0f);
    float4 t  = float4(1.0f, sx, 0.0f, 1.0f);
    t.z = (sx > 0.0f) ? exp2(sw * log2(sy)) : 0.0f;
    return t;
}
)HLSL";

// ---------------------------------------------------------------------------
// Declaration parser (D3DVSD_* tokens)
// ---------------------------------------------------------------------------
//   Token type bits 31..29:
//     0 = NOP, 1 = STREAM, 2 = STREAM_DATA, 3 = TESSELATOR, 4 = CONSTMEM,
//     5 = EXT, 0x7 (0xFFFFFFFF) = END.
//   STREAM_DATA:
//     bit 28        : 0 = REG data, 1 = SKIP
//     bits 20..23   : v-register (for REG)
//     bits 16..19   : DataType (for REG)
//     bits 0..15    : count (for SKIP; 1 DWORD per count)
//
// DataType values used in practice by Xbox titles:
//   0x12 FLOAT1      (4 bytes)
//   0x22 FLOAT2      (8 bytes)
//   0x32 FLOAT3      (12 bytes)
//   0x42 FLOAT4      (16 bytes)
//   0x40 D3DCOLOR    (4 bytes, BGRA unorm)
//   0x16 NORMPACKED3 (4 bytes, 11/11/10 signed packed normal)
//   0x15 NORMSHORT1  (2 bytes)  — unused in B3
//   0x25 NORMSHORT2  (4 bytes)
//   0x45 NORMSHORT4  (8 bytes)

struct DeclEntry {
    uint8_t     reg;            // v-register 0..15
    uint8_t     dataType;
    uint8_t     byteSize;       // stream bytes consumed
    uint8_t     numFloats;      // number of meaningful components
    DXGI_FORMAT format;
    bool        isPacked;       // needs shader-side unpack
    bool        isColor;        // D3DCOLOR — supplied as BGRA float4 via DXGI
    uint16_t    streamOffset;   // starting byte offset in the stream
};

static void DataTypeInfo(uint8_t dt, uint8_t& byteSize, uint8_t& numFloats,
                         DXGI_FORMAT& fmt, bool& packed, bool& color) {
    packed = false; color = false;
    switch (dt) {
    case 0x12: byteSize = 4;  numFloats = 1; fmt = DXGI_FORMAT_R32_FLOAT;          return;
    case 0x22: byteSize = 8;  numFloats = 2; fmt = DXGI_FORMAT_R32G32_FLOAT;       return;
    case 0x32: byteSize = 12; numFloats = 3; fmt = DXGI_FORMAT_R32G32B32_FLOAT;    return;
    case 0x42: byteSize = 16; numFloats = 4; fmt = DXGI_FORMAT_R32G32B32A32_FLOAT; return;
    case 0x40: byteSize = 4;  numFloats = 4; fmt = DXGI_FORMAT_B8G8R8A8_UNORM;     color = true; return;
    case 0x16: // NORMPACKED3 — pass as raw uint, unpack in HLSL
               byteSize = 4;  numFloats = 3; fmt = DXGI_FORMAT_R32_UINT;           packed = true; return;
    case 0x15: byteSize = 2;  numFloats = 1; fmt = DXGI_FORMAT_R16_SNORM;          return;
    case 0x25: byteSize = 4;  numFloats = 2; fmt = DXGI_FORMAT_R16G16_SNORM;       return;
    case 0x45: byteSize = 8;  numFloats = 4; fmt = DXGI_FORMAT_R16G16B16A16_SNORM; return;
    default:   byteSize = 0;  numFloats = 0; fmt = DXGI_FORMAT_UNKNOWN;            return;
    }
}

static void ParseDeclaration(const uint32_t* decl, size_t dwords,
                             std::vector<DeclEntry>& out,
                             uint32_t& stride) {
    out.clear();
    stride = 0;
    uint32_t curOffset = 0;
    uint32_t curStream = 0;
    uint32_t stream0End = 0;

    for (size_t i = 0; i < dwords; i++) {
        uint32_t tk = decl[i];
        if (tk == 0xFFFFFFFFu) break;

        uint32_t type = (tk >> 29) & 0x7;
        if (type == 0) continue; // NOP
        if (type == 1) {         // STREAM
            curStream = tk & 0xF;
            curOffset = 0;
            continue;
        }
        if (type == 2) { // STREAM_DATA
            bool isSkip = (tk & (1u << 28)) != 0;
            if (isSkip) {
                // X_D3DVSD_SKIPCOUNTSHIFT = 16, mask = 0xF; count is in DWORDs.
                uint32_t skipDW = (tk >> 16) & 0xF;
                curOffset += skipDW * 4;
                continue;
            }
            // X_D3DVSD_REG(Reg, Type) = tok | ((Type) << 16) | (Reg)
            //   VERTEXREG  : bits 0..4   (0x1F mask)
            //   DATATYPE   : bits 16..23 (0xFF mask) — full Xbox data-type byte
            uint32_t typeByte = (tk >> 16) & 0xFF;
            uint32_t regFull  = tk & 0x1F;

            uint8_t bs, nf; DXGI_FORMAT fmt; bool packed, color;
            DataTypeInfo((uint8_t)typeByte, bs, nf, fmt, packed, color);
            if (bs == 0) {
                // unknown — skip a DWORD to keep stream going
                curOffset += 4;
                continue;
            }
            DeclEntry e{};
            e.reg = (uint8_t)regFull;
            e.dataType = (uint8_t)typeByte;
            e.byteSize = bs;
            e.numFloats = nf;
            e.format = fmt;
            e.isPacked = packed;
            e.isColor = color;
            e.streamOffset = (uint16_t)curOffset;
            curOffset += bs;
            // Only stream 0 is bound as a VB at draw time — entries on other
            // streams are dropped so the HLSL sees them as zero-initialized
            // attributes (via the vReg[] init loop in main()).
            if (curStream == 0) {
                out.push_back(e);
                stream0End = curOffset;
            }
            continue;
        }
        // TESSELATOR / CONSTMEM / EXT — treated as single-DWORD no-op for MVP.
    }
    stride = stream0End;
}

// Produce a default Burnout-3-ish declaration matching the stride-28 layout:
// v0 POSITION (float3), v2 NORMAL (normpacked3), v3 DIFFUSE (d3dcolor), v9 TEX0 (float2).
static void DefaultDeclaration(std::vector<DeclEntry>& out, uint32_t& stride) {
    out.clear();
    DeclEntry e{};
    e = {}; e.reg = 0;  e.dataType = 0x32; e.byteSize = 12; e.numFloats = 3;
            e.format = DXGI_FORMAT_R32G32B32_FLOAT;    e.streamOffset = 0;  out.push_back(e);
    e = {}; e.reg = 2;  e.dataType = 0x16; e.byteSize = 4;  e.numFloats = 3;
            e.format = DXGI_FORMAT_R32_UINT; e.isPacked = true; e.streamOffset = 12; out.push_back(e);
    e = {}; e.reg = 3;  e.dataType = 0x40; e.byteSize = 4;  e.numFloats = 4;
            e.format = DXGI_FORMAT_B8G8R8A8_UNORM; e.isColor = true; e.streamOffset = 16; out.push_back(e);
    e = {}; e.reg = 9;  e.dataType = 0x22; e.byteSize = 8;  e.numFloats = 2;
            e.format = DXGI_FORMAT_R32G32_FLOAT;  e.streamOffset = 20; out.push_back(e);
    stride = 28;
}

// ---------------------------------------------------------------------------
// HLSL emitter: vertex-input struct, output struct, main()
// ---------------------------------------------------------------------------
static void EmitInputStruct(std::ostringstream& o,
                            const std::vector<DeclEntry>& decl) {
    o << "struct VSInput {\n";
    for (size_t i = 0; i < decl.size(); i++) {
        const auto& e = decl[i];
        const char* hlslType = "float4";
        if (e.isPacked) hlslType = "uint";  // raw bits, unpack in main()
        else if (e.isColor) hlslType = "float4";
        else {
            switch (e.numFloats) {
            case 1: hlslType = "float";  break;
            case 2: hlslType = "float2"; break;
            case 3: hlslType = "float3"; break;
            default:hlslType = "float4"; break;
            }
        }
        o << "    " << hlslType << " a" << (int)e.reg
          << " : TEXCOORD" << (int)i << ";\n";
    }
    o << "};\n\n";
}

static void EmitOutputStruct(std::ostringstream& o) {
    o <<
        "struct VSOutput {\n"
        "    float4 oPos_sv : SV_Position;\n"
        "    float4 oD0     : COLOR0;\n"
        "    float4 oD1     : COLOR1;\n"
        "    float4 oFog    : FOG;\n"
        "    float4 oT0     : TEXCOORD0;\n"
        "    float4 oT1     : TEXCOORD1;\n"
        "    float4 oT2     : TEXCOORD2;\n"
        "    float4 oT3     : TEXCOORD3;\n"
        "};\n\n";
}

static void EmitVRegInit(std::ostringstream& o,
                         const std::vector<DeclEntry>& decl) {
    // Zero all attribute registers first (unrolled manually to avoid any
    // dynamic-indexing issues with HLSL cbuffer-style arrays).
    o << "    float4 vReg[16];\n";
    for (int i = 0; i < 16; i++) {
        o << "    vReg[" << i << "] = float4(0,0,0,1);\n";
    }
    for (const auto& e : decl) {
        const std::string src = "input.a" + std::to_string((int)e.reg);
        o << "    vReg[" << (int)e.reg << "] = ";
        if (e.isPacked) {
            // 11/11/10 signed: X: bits 0..10, Y: 11..21, Z: 22..31.
            o << "float4("
              << "((int)((" << src << " & 0x7FFu)           ) - ((" << src << " & 0x400u)        ? 2048 : 0)) / 1023.0f, "
              << "((int)(((" << src << " >> 11) & 0x7FFu)   ) - (((" << src << " >> 11) & 0x400u)? 2048 : 0)) / 1023.0f, "
              << "((int)(((" << src << " >> 22) & 0x3FFu)   ) - (((" << src << " >> 22) & 0x200u)? 1024 : 0)) / 511.0f, "
              << "1.0f);\n";
        } else if (e.isColor) {
            o << "float4(" << src << ");\n"; // already BGRA float4 via DXGI
        } else {
            switch (e.numFloats) {
            case 1: o << "float4(" << src << ", 0, 0, 1);\n"; break;
            case 2: o << "float4(" << src << ", 0, 1);\n";    break;
            case 3: o << "float4(" << src << ", 1);\n";       break;
            default:o << src << ";\n";                         break;
            }
        }
    }
}

// Walk instructions and append their HLSL to `body`. Returns number of
// instructions processed (excluding header).
static uint32_t EmitInstructions(const uint32_t* tokens, size_t tokDwords,
                                 std::ostringstream& body) {
    // tokens[0] is the VSH header (version + count). Instruction stream
    // begins at tokens[1], 4 DWORDs per instruction. Terminate on FLD_FINAL.
    uint32_t count = 0;
    size_t i = 1;
    while (i + 3 < tokDwords) {
        const uint32_t* inst = &tokens[i];
        body << decode_token(inst);
        count++;

        // Xbox VS convention: the viewport-mapping epilogue is
        //   MUL oPos.xyz, R12, c[58]
        //   MAD oPos.xyz, R12, R1.x, c[59]
        // where R1.x is expected to hold 1/clipW (rhw). The Xbox shader
        // compiler usually emits a paired RCC R1.x, R12.w on one of the
        // earlier slots, but some shaders elide it (relying on engine
        // state). To keep R1.x correct in all cases, refresh it any time
        // a token writes oPos.w (R12.w) -- either via the MAC primary
        // output or via the muxed secondary output to o-register #0.
        bool wroteOposW = false;
        VshMAC mac = (VshMAC)vsh_get(inst, FLD_MAC);
        if (mac != MAC_NOP &&
            (int)vsh_get(inst, FLD_OUT_R) == 12 &&
            (vsh_get(inst, FLD_OUT_MAC_MASK) & 0x1)) {
            wroteOposW = true;
        }
        if (vsh_get(inst, FLD_OUT_O_MASK) & 0x1) {
            VshOutputType orb = (VshOutputType)vsh_get(inst, FLD_OUT_ORB);
            int oidx = vsh_get(inst, FLD_OUT_ADDRESS) & 0xF;
            if (orb == OUTPUT_O && oidx == 0) {
                wroteOposW = true;
            }
        }
        if (wroteOposW) {
            body << "  R1.x = (oPos.w != 0.0f) ? (1.0f / oPos.w) : 0.0f;\n";
        }

        bool final_ = (vsh_get(inst, FLD_FINAL) != 0);
        i += 4;
        if (final_) break;
        if (count > 256) break; // safety
    }
    return count;
}

} // namespace

// ---------------------------------------------------------------------------
void Nv2aVsResult_FixupPointers(Nv2aVsResult& r) {
    for (size_t i = 0; i < r.inputLayout.size() && i < r.semanticNames.size(); i++) {
        r.inputLayout[i].SemanticName = r.semanticNames[i].c_str();
    }
}

Nv2aVsResult TranslateNV2AtoHLSL(const uint32_t* funcTokens, size_t funcBytes,
                                 const uint32_t* declTokens, size_t declBytes) {
    Nv2aVsResult res{};
    if (!funcTokens || funcBytes < 20) {
        res.error = "no function tokens";
        return res;
    }
    size_t funcDwords = funcBytes / 4;

    // Parse declaration (or fall back to Burnout 3 default).
    std::vector<DeclEntry> decl;
    uint32_t stride = 0;
    if (declTokens && declBytes >= 4) {
        ParseDeclaration(declTokens, declBytes / 4, decl, stride);
    }
    if (decl.empty()) {
        DefaultDeclaration(decl, stride);
    }
    res.vertexStride = stride;

    // Build HLSL.
    std::ostringstream hlsl;
    hlsl << "// Auto-generated from NV2A microcode by TranslateNV2AtoHLSL\n";
    hlsl << "cbuffer VSConstants : register(b0) { float4 c[192]; };\n\n";
    EmitInputStruct(hlsl, decl);
    EmitOutputStruct(hlsl);
    hlsl << kHlslPrologue;
    hlsl << "\nVSOutput main(VSInput input) {\n";
    hlsl << "    int A0 = 0;\n";
    hlsl << "    float4 R0=float4(0,0,0,0), R1=float4(0,0,0,0), R2=float4(0,0,0,0), R3=float4(0,0,0,0);\n";
    hlsl << "    float4 R4=float4(0,0,0,0), R5=float4(0,0,0,0), R6=float4(0,0,0,0), R7=float4(0,0,0,0);\n";
    hlsl << "    float4 R8=float4(0,0,0,0), R9=float4(0,0,0,0), R10=float4(0,0,0,0), R11=float4(0,0,0,0);\n";
    // R12 is aliased with oPos. HLSL lets us read/write either freely as a
    // local and we copy into SV_Position at the end.
    hlsl << "    float4 oPos=float4(0,0,0,0);\n";
    hlsl << "    #define R12 oPos // Xbox R12 is aliased with oPos\n";
    // Default values for unwritten outputs.
    //   oD0 = (1,1,1,1)   B3 map shaders don't write diffuse and expect a
    //                     fully-lit passthrough (matches Xbox FF "no
    //                     material" behaviour). Setting (0,0,0,1) here
    //                     turns the entire map black.
    //   oFog= (1,1,1,1)   Same story: many B3 PS combiners multiply by
    //                     vFog and expect 1.0 when the VS doesn't write
    //                     fog. Setting (0,0,0,1) blacks out maps.
    //   oD1 = (0,0,0,0)   Specular zero (matches Xemu).
    // Until we plumb vertex DIFFUSE/SPECULAR/FOG passthrough properly
    // (auto-binding vReg[3] -> oD0 when the VS body doesn't write it),
    // keep these "fully on" defaults.
    hlsl << "    float4 oD0=float4(1,1,1,1), oD1=float4(0,0,0,0), oFog=float4(1,1,1,1);\n";
    hlsl << "    float4 oPts=float4(0,0,0,0), oB0=float4(0,0,0,0), oB1=float4(0,0,0,0);\n";
    // Xbox convention: unwritten VS output components default to (0,0,0,1).
    // Using (0,0,0,0) for oT* breaks PS_TM_PROJECT2D draws whose NV2A shader
    // writes only .xy — the projective divide inT.xy / max(inT.w, 1e-6)
    // blows UVs up to ~1e6, producing frame-varying TV-static noise as
    // interpolator precision wobbles per pixel (symptom seen on Burnout 3
    // garage mesh). Initialise .w to 1.0 so projective divide is identity.
    hlsl << "    float4 oT0=float4(0,0,0,1), oT1=float4(0,0,0,1), oT2=float4(0,0,0,1), oT3=float4(0,0,0,1);\n";
    hlsl << "    int A0x; // scratch for ARL\n";
    EmitVRegInit(hlsl, decl);
    hlsl << "\n    // --- translated NV2A instructions ---\n";
    res.instructionCount = EmitInstructions(funcTokens, funcDwords, hlsl);
    // NV2A shaders end by baking the Xbox viewport transform into oPos:
    //   oPos.xyz = (oPos_clip.xyz * c[58].xyz) / oPos.w + c[59].xyz
    //   oPos.w   = oPos_clip.w  (unchanged)
    // D3D11 SV_Position expects clip-space, so we invert: pull oPos back
    // into NDC using c[58]/c[59] (same slots the shader just used), then
    // re-multiply by oPos.w to restore homogeneous clip coords.
    // If c[58] hasn't been initialized (component zero), skip — the shader
    // already produced clip-space output directly.
    hlsl << "\n    // --- inverse Xbox viewport transform (window -> clip) ---\n";
    hlsl << "    if (c[58].x != 0.0f && c[58].y != 0.0f) {\n";
    hlsl << "        float3 ndc = (oPos.xyz - c[59].xyz) / c[58].xyz;\n";
    hlsl << "        oPos.xyz = ndc * oPos.w;\n";
    hlsl << "    }\n";

    hlsl << "\n    // --- write outputs ---\n";
    hlsl << "    VSOutput output;\n";
    hlsl << "    output.oPos_sv = oPos;\n";
    hlsl << "    output.oD0  = oD0;\n";
    hlsl << "    output.oD1  = oD1;\n";
    hlsl << "    output.oFog = oFog;\n";
    hlsl << "    output.oT0  = oT0;\n";
    hlsl << "    output.oT1  = oT1;\n";
    hlsl << "    output.oT2  = oT2;\n";
    hlsl << "    output.oT3  = oT3;\n";
    hlsl << "    return output;\n";
    hlsl << "}\n";

    res.hlsl = hlsl.str();

    // Build input layout descriptors. SemanticNames use the same "TEXCOORD<i>"
    // encoding as the input struct (which we've already emitted).
    res.semanticNames.reserve(decl.size());
    res.inputLayout.reserve(decl.size());
    for (size_t i = 0; i < decl.size(); i++) {
        res.semanticNames.emplace_back("TEXCOORD");
        D3D11_INPUT_ELEMENT_DESC ied{};
        ied.SemanticName         = nullptr; // fixed up below
        ied.SemanticIndex        = (UINT)i;
        ied.Format               = decl[i].format;
        ied.InputSlot            = 0;
        ied.AlignedByteOffset    = decl[i].streamOffset;
        ied.InputSlotClass       = D3D11_INPUT_PER_VERTEX_DATA;
        ied.InstanceDataStepRate = 0;
        res.inputLayout.push_back(ied);
    }
    Nv2aVsResult_FixupPointers(res);

    res.ok = (res.instructionCount > 0);
    return res;
}
