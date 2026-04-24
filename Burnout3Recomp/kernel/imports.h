#pragma once

#include <x86_context.h>
#include <x86_kernel_imports.h>

// Kernel dispatch system.
// Inserts kernel stubs directly into g_funcMap so X86_CALL_INDIRECT
// resolves them in a single hash-map lookup alongside recompiled functions.

namespace KernelDispatch
{
    // Populate IAT thunks in guest memory and register all kernel stubs
    // into g_funcMap.  Must be called after g_memory and X86_INIT_FUNC_MAP().
    void Init();
}
