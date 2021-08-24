#include <taihen.h>
#include <vitasdk.h>
#include "functions.h"

static SceUID         hook_play_mp4_hook = -1;
static tai_hook_ref_t hook_play_mp4_ref;

void hook_play_mp4(char* mp4_path, uint8_t unk1, uint32_t unk2) {
    return TAI_CONTINUE(void, hook_play_mp4_ref, "Movie/TITLE_OP_CUSTOM.mp4", unk1, unk2);
}

void _start() __attribute__ ((weak, alias ("module_start")));
int module_start(SceSize argc, const void *args) {
    tai_module_info_t tai_info;
    tai_info.size = sizeof(tai_module_info_t);
    taiGetModuleInfo(TAI_MAIN_MODULE, &tai_info);

    // set up hooks
    hook_play_mp4_hook = taiHookFunctionOffset(
            &hook_play_mp4_ref,
            tai_info.modid,
            HOOK_FUNC_ELF_SEGMENT_INDEX,
            FUNC_OFFSET_play_mp4,
            IS_THUMB,
            hook_play_mp4);

    return SCE_KERNEL_START_SUCCESS;
}

int module_stop(SceSize argc, const void *args) {
    // release hooks
    if (hook_play_mp4_hook >= 0) taiHookRelease(hook_play_mp4_hook, hook_play_mp4_ref);

    return SCE_KERNEL_STOP_SUCCESS;
}
