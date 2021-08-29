#pragma once

typedef int (*t_FUN_8100b8ca) (uint32_t, uint32_t, uint32_t);
#define FUN_8100b8ca(...) ((t_FUN_8100b8ca)0x8100b8ca)(__VA_ARGS__)

typedef int (*t_FUN_81008824) (ushort);
#define FUN_81008824(...) ((t_FUN_81008824)0x81008824)(__VA_ARGS__)

typedef void (*t_FUN_81070b90) (int*, undefined4*);
#define FUN_81070b90(...) ((t_FUN_81070b90)0x81070b90)(__VA_ARGS__)

typedef void (*t_FUN_8100b8d6) (int, int, uint, uint);
#define FUN_8100b8d6(...) ((t_FUN_8100b8d6)0x8100b8d6)(__VA_ARGS__)

typedef undefined4 (*t_FUN_8100cb52) (void);
#define FUN_8100cb52(...) ((t_FUN_8100cb52)0x8100cb52)(__VA_ARGS__)

typedef undefined4 (*t_FUN_8100b986) (undefined4);
#define FUN_8100b986(...) ((t_FUN_8100b986)0x8100b986)(__VA_ARGS__)

typedef void (*t_FUN_8100cd64) (undefined4);
#define FUN_8100cd64(...) ((t_FUN_8100cd64)0x8100cd64)(__VA_ARGS__)

// TODO args don't line up
typedef undefined4 (*t_FUN_8100b952) (undefined4);
#define FUN_8100b952(...) ((t_FUN_8100b952)0x8100b952)(__VA_ARGS__)

typedef void (*t_FUN_8100c2de) (uint);
#define FUN_8100c2de(...) ((t_FUN_8100c2de)0x8100c2de)(__VA_ARGS__)

typedef void (*t_FUN_8100c588) (void);
#define FUN_8100c588(...) ((t_FUN_8100c588)0x8100c588)(__VA_ARGS__)

typedef void (*t_FUN_8100b9a6) (int, int);
#define FUN_8100b9a6(...) ((t_FUN_8100b9a6)0x8100b9a6)(__VA_ARGS__)

typedef undefined4 (*t_FUN_8100b9c4) (undefined4);
#define FUN_8100b9c4(...) ((t_FUN_8100b9c4)0x8100b9c4)(__VA_ARGS__)

typedef void (*t_FUN_81013278) (undefined4, undefined4);
#define FUN_81013278(...) ((t_FUN_81013278)0x81013278)(__VA_ARGS__)

// TODO totally borked, Ghidra is very wrong somewhere
typedef void (*t_FUN_8100c288) (float, float);
#define FUN_8100c288(...) ((t_FUN_8100c288)0x8100c288)(__VA_ARGS__)

// retyped using the SceGxm* function it wraps
typedef void (*t_FUN_8100c17a) (uint, void*);
#define FUN_8100c17a(...) ((t_FUN_8100c17a)0x8100c17a)(__VA_ARGS__)

typedef void (*t_FUN_8100c0fc) (int, uint);
#define FUN_8100c0fc(...) ((t_FUN_8100c0fc)0x8100c0fc)(__VA_ARGS__)

// TODO broken args...
typedef undefined4 (*t_FUN_8100cb66) (undefined4);
#define FUN_8100cb66(...) ((t_FUN_8100cb66)0x8100cb66)(__VA_ARGS__)

// TODO ugh...
typedef undefined4* (*t_FUN_81008766) (undefined4, undefined4, undefined4, undefined4, undefined4, undefined4, undefined4, undefined4, undefined4, undefined4);
#define FUN_81008766(...) ((t_FUN_81008766)0x81008766)(__VA_ARGS__)

/*
typedef void (*t_FUN_) (int, undefined4*);
#define FUN_(...) ((t_FUN_)0x)(__VA_ARGS__)
*/

#define DAT_8119cbec *(undefined *)0x8119cbec
#define DAT_8119d434 *(float *)0x8119d434
#define DAT_8119d438 *(float *)0x8119d438
#define DAT_8119d448 *(uint *)0x8119d448
#define DAT_8119d46c *(uint *)0x8119d46c
#define DAT_811f6628 *(undefined4 *)0x811f6628 // ?
#define DAT_8109afe8 *(char **)0x8109afe8

// TODO
#define ROUND(f) f
