/*
 * Copyright (c) 2019 Lexmark International, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
<<<<<<< HEAD
#include <zephyr/init.h>
#include <zephyr/arch/arm/aarch32/cortex_a_r/cmsis.h>

/**
 *
 * @brief Perform basic hardware initialization
 *
 * @return 0
 */

static int soc_init(void)
{

	/* Install default handler that simply resets the CPU
	 * if configured in the kernel, NOP otherwise
	 */
	NMI_INIT();
	return 0;
}

SYS_INIT(soc_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
=======

#include <cmsis_core.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

void z_arm_platform_init(void)
{
	/*
	 * Use normal exception vectors address range (0x0-0x1C).
	 */
	unsigned int sctlr = __get_SCTLR();

	sctlr &= ~SCTLR_V_Msk;
	__set_SCTLR(sctlr);
}
