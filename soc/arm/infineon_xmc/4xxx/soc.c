/*
 * SPDX-License-Identifier: Apache-2.0
 *
 * Copyright (c) 2020 Linumiz
 * Author: Parthiban Nallathambi <parthiban@linumiz.com>
 *
 */

#include <xmc_scu.h>
#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <soc.h>

#ifdef CONFIG_SOC_XMC4500
#define PMU_FLASH_WS		(0x3U)
#elif CONFIG_SOC_XMC4700
#define PMU_FLASH_WS		(0x4U)
#endif

void z_arm_platform_init(void)
{
	uint32_t temp;

	/* unaligned trap bit is enabled on reset. disable it here and set later via */
	/* CONFIG_TRAP_UNALIGNED_ACCESS if needed. */
	SCB->CCR &= ~SCB_CCR_UNALIGN_TRP_Msk;

	/* setup flash wait state */
	temp = FLASH0->FCON;
	temp &= ~FLASH_FCON_WSPFLASH_Msk;
	temp |= PMU_FLASH_WS;
	FLASH0->FCON = temp;

<<<<<<< HEAD
	XMC_SCU_CLOCK_SetSleepConfig(XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FPLL);
=======
	XMC_SCU_CLOCK_SetSleepConfig(XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_SYSCLK_FPLL
#ifdef CONFIG_PWM_XMC4XXX_CCU4
				     | XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_ENABLE_CCU
#endif
#ifdef CONFIG_PWM_XMC4XXX_CCU8
				     | XMC_SCU_CLOCK_SLEEP_MODE_CONFIG_ENABLE_CCU
#endif
	);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	/* configure PLL & system clock */
	SystemCoreClockSetup();
}
