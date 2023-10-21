/*
 * Copyright (c) 2019 Carlo Caione <ccaione@baylibre.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */
<<<<<<< HEAD
=======
/**
 * @file
 * @brief Private kernel definitions (ARM)
 *
 * This file contains private kernel function definitions and various
 * other definitions for the 32-bit ARM Cortex-A/R/M processor architecture
 * family.
 *
 * This file is also included by assembly language files which must #define
 * _ASMLANGUAGE before including this header file.  Note that kernel
 * assembly source files obtains structure offset values via "absolute symbols"
 * in the offsets.o module.
 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#ifndef ZEPHYR_ARCH_ARM_INCLUDE_KERNEL_ARCH_FUNC_H_
#define ZEPHYR_ARCH_ARM_INCLUDE_KERNEL_ARCH_FUNC_H_

<<<<<<< HEAD
#include <aarch32/kernel_arch_func.h>
=======
#include <kernel_arch_data.h>

#if defined(CONFIG_CPU_CORTEX_M)
#include <cortex_m/kernel_arch_func.h>
#else
#include <cortex_a_r/kernel_arch_func.h>
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* ZEPHYR_ARCH_ARM_INCLUDE_KERNEL_ARCH_FUNC_H_ */
