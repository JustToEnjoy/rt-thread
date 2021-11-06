/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-05-18     Jesven       first version
 */

#ifndef  LWP_ARCH_H__
#define  LWP_ARCH_H__

#include <lwp.h>

#ifdef ARCH_ARM_MMU

#define USER_VADDR_TOP    0x0001000000000000UL
#define USER_HEAP_VEND    0x0000ffffB0000000UL
#define USER_HEAP_VADDR   0x0000ffff80000000UL
#define USER_STACK_VSTART 0x0000ffff70000000UL
#define USER_STACK_VEND   USER_HEAP_VADDR
#define LDSO_LOAD_VADDR   0x60000000UL
#define USER_VADDR_START  0x00200000UL
#define USER_LOAD_VADDR   USER_VADDR_START

#ifdef __cplusplus
extern "C" {
#endif

int arch_user_space_init(struct rt_lwp *lwp);
void arch_user_space_vtable_free(struct rt_lwp *lwp);
void *arch_kernel_mmu_table_get(void);
void arch_kuser_init(rt_mmu_info *mmu_info, void *vectors);
int arch_expand_user_stack(void *addr);

unsigned long ffz(unsigned long x);

#ifdef __cplusplus
}
#endif

#endif

#endif  /*LWP_ARCH_H__*/
