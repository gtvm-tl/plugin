#include <taihen.h>
#include <vitasdk.h>
#include <psp2/kernel/error.h>
#include <psp2/kernel/modulemgr.h>
#include "functions.h"
#include <stdio.h>

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

static SceUID         hook_play_mp4_hook = -1;
static tai_hook_ref_t hook_play_mp4_ref;

void hook_play_mp4(char* mp4_path, uint8_t unk1, uint32_t unk2) {
    return TAI_CONTINUE(void, hook_play_mp4_ref, "Movie/TITLE_OP_CUSTOM.mp4", unk1, unk2);
}

static SceUID         hook_draw_string_inner_hook = -1;
static tai_hook_ref_t hook_draw_string_inner_ref;

typedef void (*f_unk_utf8_to_utf16) (uint16_t*, int, char*);
typedef uint32_t (*f_unk_gxm_text_draw) (int, int, uint32_t, uint32_t, uint16_t*);

static f_unk_utf8_to_utf16 unk_utf8_to_utf16 = NULL;
static f_unk_gxm_text_draw unk_gxm_text_draw = NULL;

void hook_draw_string_inner(int x, int y, int unk1, int unk2, char* utf8) {
    uint16_t utf16[128];

    unk_utf8_to_utf16(utf16, 128, utf8);
    unk_gxm_text_draw(x, y, unk1, unk2, utf16);
    return;
}

void _start() __attribute__ ((weak, alias ("module_start")));
int module_start(SceSize argc, const void *args) {
    tai_module_info_t tai_info;
    tai_info.size = sizeof(tai_module_info_t);
    taiGetModuleInfo(TAI_MAIN_MODULE, &tai_info);

    // fill global function pointers

    Module_GetAddressForOffset(
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_unk_utf8_to_utf16 | 1,
            &unk_utf8_to_utf16);

    Module_GetAddressForOffset(
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_unk_gxm_text_draw | 1,
            &unk_gxm_text_draw);

    // set up hooks

    hook_play_mp4_hook = taiHookFunctionOffset(
            &hook_play_mp4_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_play_mp4,
            IS_THUMB,
            hook_play_mp4);

    hook_draw_string_inner_hook = taiHookFunctionOffset(
            &hook_draw_string_inner_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_draw_string_inner,
            IS_THUMB,
            hook_draw_string_inner);

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args) {
    // release hooks

    if (hook_play_mp4_hook >= 0)          taiHookRelease(hook_play_mp4_hook, hook_play_mp4_ref);
    if (hook_draw_string_inner_hook >= 0) taiHookRelease(hook_draw_string_inner_hook, hook_draw_string_inner_ref);

    return SCE_KERNEL_STOP_SUCCESS;
}
