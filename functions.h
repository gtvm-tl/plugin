/// Hook-related data.
// TODO put in build system somewhere
// #define VER_PATCHED_1_01

// Magic number for indicating hook function type in taiHEN.
#define IS_THUMB 1

/** User-facing function address definitions.
 *
 * We make a meagre attempt at abstracting over game version for convenience.
 * TODO: encode function signatures too, and a flag that indicates whether we
 * think the function is differs between versions (i.e. was updated). Actually,
 * that would be a lot more complex...
 *
 * From raehik's minimal understanding, PSV game updates are provided via whole
 * file replacements, at least for the eboot. The smallest code update will
 * likely shift all functions, including untouched ones. So for functions we
 * want to hook, we assign a symbol using any info gleaned from the decomp, then
 * attach a virtual memory address that corresponds to that function for the
 * given game version.
 *
 * TODO: this is wrong. taiHEN doesn't use vaddr, it uses offset from segment
 * start.
 */
#ifdef VER_PATCHED_1_01
    #define HOOK_FUNC_ELF_SEGMENT_INDEX 0
    #define HOOK_FUNC_ELF_SEGMENT_VADDR 0x81000000
    #define FUNC_VADDR_play_mp4  0x81051910
    #define FUNC_OFFSET_play_mp4 0x51910
#endif
#ifdef VER_UNPATCHED
    // we're not really interested in any version except the latest
#endif
