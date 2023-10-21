/*
 * Copyright (c) 2018 qianfan Zhao <qianfanguijin@163.com>
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief System/hardware module for stm32f2 processor
 */

#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <soc.h>
<<<<<<< HEAD
#include <zephyr/arch/cpu.h>
#include <zephyr/arch/arm/aarch32/cortex_m/cmsis.h>
#include <zephyr/arch/arm/aarch32/nmi.h>
#include <stm32_ll_system.h>
#include <zephyr/linker/linker-defs.h>
#include <zephyr/irq.h>
#include <string.h>

=======
#include <stm32_ll_system.h>
#include <zephyr/linker/linker-defs.h>
#include <string.h>

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
static int stm32f2_init(void)
{
<<<<<<< HEAD
	uint32_t key;


=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	/* Enable ART Flash cache accelerator for both Instruction and Data */
	LL_FLASH_EnableInstCache();
	LL_FLASH_EnableDataCache();

<<<<<<< HEAD
	key = irq_lock();

	/* Install default handler that simply resets the CPU
	 * if configured in the kernel, NOP otherwise
	 */
	NMI_INIT();

	irq_unlock(key);

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	/* Update CMSIS SystemCoreClock variable (HCLK) */
	/* At reset, system core clock is set to 16 MHz from HSI */
	SystemCoreClock = 16000000;

	return 0;
}

SYS_INIT(stm32f2_init, PRE_KERNEL_1, 0);
