#pragma once

/**
 * Hook etc. util stuff. Taken from CreepNT's fantastic, clear work:
 * https://github.com/CreepNT/RCHooker/blob/737f5f0592dde543f175ae6937e31a3c308e8558/common.h
 */

#define HOOK_UID(func_name)         func_name ##_hook_UID
#define HOOK_REFERENCE(func_name)   func_name ##_hook_reference
#define HOOK_FUNCTION(func_name)    func_name ##_hook_function

/**
 * @brief Helper macro to create hooks
 *
 * @param type Return type of the function
 * @param func_name Original function's name
 * @param ... Arguments the function takes
 * @note Add brackets after the macro, contents of the brackets are the hook function's body
 */
#define DeclareHook(type, func_name, ...)           \
    static SceUID HOOK_UID(func_name);              \
    static tai_hook_ref_t HOOK_REFERENCE(func_name);\
    FAKE_VARIABLE(func_name);                       \
    type HOOK_FUNCTION(func_name) (__VA_ARGS__)

/**
 * @brief Helper macro to add hooks
 *
 * @param modID UID of the module the hooked function is located in
 * @param segment Segment in which the hooked function is located
 * @param offset Offset in segment where the hooked function is located
 * @param thumb 1 if Thumb code, 0 if ARM code
 * @param func_name Original function's name
 */
#define HookAtOffset(modID, segment, offset, thumb, func_name) \
    HOOK_UID(func_name) = taiHookFunctionOffset(&HOOK_REFERENCE(func_name), modID, segment, offset, thumb, HOOK_FUNCTION(func_name)); \
    if (HOOK_UID(func_name) < 0) LOG_ERROR("taiHookFunctionOffset returned 0x%08X hooking function '" #func_name "' !", HOOK_UID(func_name))

/**
 * @brief Helper macro to release hooks
 *
 * @param func_name Original function's name
 */
#define ReleaseHook(func_name)\
    if (HOOK_UID(func_name) > 0) taiHookRelease(HOOK_UID(func_name), HOOK_REFERENCE(func_name))

/**
 * @brief Get the address of a segement:offset location
 *
 * @param module_UID UID of the module in which the segement:offset should be resolved
 * @param segment Segment in which target is located (0-3)
 * @param offset Offset in chosen segment in which target is located
 * @param out_address Pointer to a variable that will recieve the resolved address on success (should be pointer-sized)
 * @return 0 on success, < 0 on error
 */
int Module_GetAddressForOffset(SceUID module_UID, unsigned segment, unsigned offset, void* out_address);

/**
 * @brief Wrapper for Module_GetAddressForOffset
 *
 * @param segment Segment in which target is located (0-3)
 * @param offset Offset in chosen segment in which target is located
 * @param out Pointer to a variable that will recieve the resolved address on success (should be pointer-sized)
 */
#define GetAddressForOffset(segment, offset, out)                                                                                                       \
    do {                                                                                                                                                \
        int __rsvd_name = Module_GetAddressForOffset(game_modId, segment, offset, out);                                                                \
        if (__rsvd_name < 0) LOG_ERROR("Module_GetAddressForOffset returned 0x%08X when getting address of (%u:0x%X).\n", __rsvd_name, segment, offset);\
        else println("Resolved (%u:0x%X) to 0x%08X successfully !\n", segment, offset, (uintptr_t)*out);                                                                                                                               \
    } while(0)
/**
 * @brief Wrapper for Module_GetAddressForOffset
 * 
 * @param segment Segment in which target function is located (0-3)
 * @param offset Offset in chosen segment in which target function is located
 * @param thumb 1 if target function runs in Thumb mode, 0 if it runs in ARM mode
 * @param out Pointer to a variable that will recieve the resolved address on success (should be pointer-sized)
 */
#define GetFunctionAddressFromOffset(segment, offset, thumb, out) GetAddressForOffset(segment, offset | thumb, out)
