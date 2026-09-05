// x86_recomp_shared.h declares these three mid-asm hooks (bloom/blur render pass
// overrides) but nothing in the currently-regenerated recomp output or hand-written
// HLE files defines or calls them -- not referenced anywhere in the address mapping
// table either. Stubbed as no-ops to satisfy the linker; if these turn out to be
// live hooks in a version of the tree we don't have, replace with real bodies.
#include "x86_recomp_shared.h"

void HLE_CB3BloomRenderPass(X86Context& ctx, uint8_t* base) {}
void HLE_CB3BlurRenderPass1(X86Context& ctx, uint8_t* base) {}
void HLE_CB3BlurRenderPass2(X86Context& ctx, uint8_t* base) {}
