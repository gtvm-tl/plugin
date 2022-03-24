#pragma once

#include <taihen.h>

/**
 * @brief      Calls the next function in the chain
 *             with static type checking
 *
 * @param      this_func  The enclosing function
 * @param      hook  The hook continuing the call
 *
 * @return     Return value from the hook chain
 */
#define TAI_NEXT(this_func, hook, ...) ({ \
  struct _tai_hook_user *cur, *next; \
  cur = (struct _tai_hook_user *)(hook); \
  next = (struct _tai_hook_user *)cur->next; \
  (next == NULL) ? \
    ((__typeof__(&this_func))cur->old)(__VA_ARGS__) \
  : \
    ((__typeof__(&this_func))next->func)(__VA_ARGS__) \
  ; \
})
