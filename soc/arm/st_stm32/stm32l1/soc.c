/*
 * Copyright (c) 2019 Linaro Ltd.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief System/hardware module for STM32L1 processor
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/arch/cpu.h>
#include <zephyr/arch/arm/aarch32/cortex_m/cmsis.h>
#include <zephyr/arch/arm/aarch32/nmi.h>
#include <zephyr/irq.h>
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/linker/linker-defs.h>
#include <string.h>
#include <stm32_ll_bus.h>
#include <stm32_ll_pwr.h>

<<<<<<< HEAD
=======
#include <cmsis_core.h>

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
/**
 * @brief Perform basic hardware initialization at boot.
 *
 * This needs to be run from the very beginning.
 * So the init priority has to be 0 (zero).
 *
 * @return 0
 */
static int stm32l1_init(void)
{
<<<<<<< HEAD
	uint32_t key;


	key = irq_lock();

	/* Install default handler that simply resets the CPU
	 * if configured in the kernel, NOP otherwise
	 */
	NMI_INIT();

	irq_unlock(key);

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	/* Update CMSIS SystemCoreClock variable (HCLK) */
	/* At reset, system core clock is set to 2.1 MHz from MSI */
	SystemCoreClock = 2097000;

	/* Default Voltage scaling range selection (range2)
	 * doesn't allow to configure Max frequency
	 * switch to range1 to match any frequency
	 */
	LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);
	LL_PWR_SetRegulVoltageScaling(LL_PWR_REGU_VOLTAGE_SCALE1);

	return 0;
}

SYS_INIT(stm32l1_init, PRE_KERNEL_1, 0);
