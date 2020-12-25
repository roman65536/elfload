#include "elfload.h"

#if defined(__m68k__)

/*
Note: UNTESTED! I only used static elf files.
*/

#define R_M68K_NONE     0
#define R_M68K_RELATIVE 22

el_status el_applyrela(el_ctx *ctx, Elf_RelA *rel)
{
    uint32_t *p = (uint32_t*) (rel->r_offset + ctx->base_load_vaddr);
    uint32_t type = ELF_R_TYPE(rel->r_info);

    switch (type) {
        case R_M68K_NONE: break;
        case R_M68K_RELATIVE:
            EL_DEBUG("Applying R_M68K_RELATIVE reloc @%p\n", p);
            *p = rel->r_addend + ctx->base_load_vaddr;
            break;
        default:
            EL_DEBUG("Bad relocation %u\n", type);
            return EL_BADREL;

    }

    return EL_OK;
}

#endif

