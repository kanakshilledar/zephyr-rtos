/*
 * Copyright 2023 NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
<<<<<<< HEAD
#include <zephyr/arch/arm/aarch32/cortex_a_r/cmsis.h>
=======
#include <cmsis_core.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/sys/barrier.h>

void z_arm_platform_init(void)
{
	if (IS_ENABLED(CONFIG_ICACHE)) {
		if (!(__get_SCTLR() & SCTLR_I_Msk)) {
			L1C_InvalidateICacheAll();
			__set_SCTLR(__get_SCTLR() | SCTLR_I_Msk);
			barrier_isync_fence_full();
		}
	}

	if (IS_ENABLED(CONFIG_DCACHE)) {
		if (!(__get_SCTLR() & SCTLR_C_Msk)) {
			L1C_InvalidateDCacheAll();
			__set_SCTLR(__get_SCTLR() | SCTLR_C_Msk);
			barrier_dsync_fence_full();
		}
	}
}
