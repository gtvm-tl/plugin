#include <taihen.h>
#include <vitasdk.h>
#include <psp2/kernel/error.h>
#include <psp2/kernel/modulemgr.h>
#include <stdio.h>
#include "functions.h"
#include "ghidra-decomp-compat.h"

#include "taihen-fix-next.h"

int Module_GetAddressForOffset(SceUID module_UID, unsigned segment, unsigned offset, void* out_address){
    if (out_address == NULL) return SCE_KERNEL_ERROR_INVALID_ARGUMENT;
    if (segment > 3) return SCE_KERNEL_ERROR_INVALID_ARGUMENT;

    SceKernelModuleInfo modInfo;
    int ret = sceKernelGetModuleInfo(module_UID, &modInfo);
    if (ret < 0) return ret;

    if (offset > modInfo.segments[segment].memsz) return SCE_KERNEL_ERROR_INVALID_ARGUMENT;
    *(uintptr_t*)out_address = ((uintptr_t)modInfo.segments[segment].vaddr + offset);
    return 0;
}

static SceUID         hook_draw_text_gxm_hook = -1;
static tai_hook_ref_t hook_draw_text_gxm_ref;

void hook_draw_text_gxm(int unk1, int unk2, int unk3, uint rgba, wchar16 *text_utf16) {
    // 0xFF3e0b0b
    return TAI_CONTINUE(void, hook_draw_text_gxm_ref, unk1, unk2, unk3, rgba, text_utf16);
}

static SceUID         hook_set_font_size_hook = -1;
static tai_hook_ref_t hook_set_font_size_ref;

float hook_set_font_size(float font_size1, float font_size2) {
    return TAI_NEXT(hook_set_font_size, hook_set_font_size_ref, font_size1*0.9, font_size2*0.9);
}

static SceUID         hook_set_font_size_2_hook = -1;
static tai_hook_ref_t hook_set_font_size_2_ref;

float hook_set_font_size_2(float font_size) {
    return TAI_NEXT(hook_set_font_size_2, hook_set_font_size_2_ref, font_size*0.9);
}

static SceUID         hook_init_font_hook = -1;
static tai_hook_ref_t hook_init_font_ref;

typedef float (*f_set_font_size_2) (float);

// 2022-03-24 raehik
// Calling in the hook crashes my game, I forgot how to do it properly maybe?
// the stupid workaround doesn't even work???
// dumb. where else are they setting this goddamn value
void hook_init_font(void) {
    TAI_NEXT(hook_init_font, hook_init_font_ref);
    //((f_set_font_size_2) FUNC_VADDR_set_font_size_2) (1.0f);
    hook_set_font_size_2(0.9f);
    return;
}

void _start() __attribute__ ((weak, alias ("module_start")));
int module_start(SceSize argc, const void *args) {
    tai_module_info_t tai_info;
    tai_info.size = sizeof(tai_module_info_t);
    taiGetModuleInfo(TAI_MAIN_MODULE, &tai_info);

    // set up hooks

    /*
    hook_draw_text_gxm_hook = taiHookFunctionOffset(
            &hook_draw_text_gxm_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_draw_text_gxm,
            IS_THUMB,
            hook_draw_text_gxm);
    */

    hook_set_font_size_hook = taiHookFunctionOffset(
            &hook_set_font_size_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_set_font_size,
            IS_THUMB,
            hook_set_font_size);

    hook_set_font_size_2_hook = taiHookFunctionOffset(
            &hook_set_font_size_2_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_set_font_size_2,
            IS_THUMB,
            hook_set_font_size_2);

    /*
    hook_init_font_hook = taiHookFunctionOffset(
            &hook_init_font_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_init_font,
            IS_THUMB,
            hook_init_font);
    */

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args) {
    // release hooks

    if (hook_draw_text_gxm_hook >= 0) taiHookRelease(hook_draw_text_gxm_hook, hook_draw_text_gxm_ref);
    if (hook_set_font_size_hook >= 0) taiHookRelease(hook_set_font_size_hook, hook_set_font_size_ref);
    if (hook_set_font_size_2_hook >= 0) taiHookRelease(hook_set_font_size_2_hook, hook_set_font_size_2_ref);
    if (hook_init_font_hook >= 0) taiHookRelease(hook_init_font_hook, hook_init_font_ref);

    return SCE_KERNEL_STOP_SUCCESS;
}
