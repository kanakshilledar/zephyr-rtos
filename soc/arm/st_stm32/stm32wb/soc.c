/*
 * Copyright (c) 2018 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief System/hardware module for STM32WB processor
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/arch/cpu.h>
#include <zephyr/arch/arm/aarch32/cortex_m/cmsis.h>
#include <zephyr/arch/arm/aarch32/nmi.h>
#include <zephyr/logging/log.h>
#include <zephyr/irq.h>
=======
#include <zephyr/logging/log.h>

#include <cmsis_core.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#define LOG_LEVEL CONFIG_SOC_LOG_LEVEL
LOG_MODULE_REGISTER(soc);

/**
 * @brief Perform basic hardware initialization at boot.
 *
 * This needs to be run from the very beginning.
 * So the init priority has to be 0 (zero).
 *
 * @return 0
 */
static int stm32wb_init(void)
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
	/* At reset, system core clock is set to 4 MHz from MSI */
	SystemCoreClock = 4000000;

	/* Set C2 Power Mode to shutdown */
	/* It will be updated by C2 when required */
	LL_C2_PWR_SetPowerMode(LL_PWR_MODE_SHUTDOWN);

	return 0;
}

SYS_INIT(stm32wb_init, PRE_KERNEL_1, 0);
