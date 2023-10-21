/*
 * Copyright (c) 2019 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_ARCH_ARM_INCLUDE_OFFSETS_SHORT_ARCH_H_
#define ZEPHYR_ARCH_ARM_INCLUDE_OFFSETS_SHORT_ARCH_H_

<<<<<<< HEAD
#include <aarch32/offsets_short_arch.h>
=======
#include <offsets.h>

/* kernel */

/* nothing for now */

/* end - kernel */

/* threads */

#define _thread_offset_to_basepri \
	(___thread_t_arch_OFFSET + ___thread_arch_t_basepri_OFFSET)

#define _thread_offset_to_preempt_float \
	(___thread_t_arch_OFFSET + ___thread_arch_t_preempt_float_OFFSET)

#if defined(CONFIG_USERSPACE) || defined(CONFIG_FPU_SHARING)
#define _thread_offset_to_mode \
	(___thread_t_arch_OFFSET + ___thread_arch_t_mode_OFFSET)
#endif

#if defined(CONFIG_ARM_STORE_EXC_RETURN)
#define _thread_offset_to_mode_exc_return \
	(___thread_t_arch_OFFSET + ___thread_arch_t_mode_exc_return_OFFSET)
#endif

#ifdef CONFIG_USERSPACE
#define _thread_offset_to_priv_stack_start \
	(___thread_t_arch_OFFSET + ___thread_arch_t_priv_stack_start_OFFSET)

#if defined(CONFIG_CPU_AARCH32_CORTEX_R)
#define _thread_offset_to_priv_stack_end \
	(___thread_t_arch_OFFSET + ___thread_arch_t_priv_stack_end_OFFSET)

#define _thread_offset_to_sp_usr \
	(___thread_t_arch_OFFSET + ___thread_arch_t_sp_usr_OFFSET)
#endif
#endif

#if defined(CONFIG_THREAD_STACK_INFO)
#define _thread_offset_to_stack_info_start \
	(___thread_stack_info_t_start_OFFSET + ___thread_t_stack_info_OFFSET)
#endif


/* end - threads */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* ZEPHYR_ARCH_ARM_INCLUDE_OFFSETS_SHORT_ARCH_H_ */
