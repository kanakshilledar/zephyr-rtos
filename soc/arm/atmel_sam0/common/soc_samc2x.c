/*
 * Copyright (c) 2022 Kamil Serwus
<<<<<<< HEAD
=======
 * Copyright (c) 2023 Gerson Fernando Budke <nandojve@gmail.com>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief Atmel SAMC MCU series initialization code
 */

<<<<<<< HEAD
#include <zephyr/arch/cpu.h>
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/kernel.h>
#include <soc.h>

static void flash_waitstates_init(void)
{
	/* One wait state at 48 MHz. */
	NVMCTRL->CTRLB.bit.RWS = NVMCTRL_CTRLB_RWS_HALF_Val;
}

static void osc48m_init(void)
{
	/* Turn off the prescaler */
	OSCCTRL->OSC48MDIV.bit.DIV = 0;
	while (OSCCTRL->OSC48MSYNCBUSY.bit.OSC48MDIV) {
	}
	while (!OSCCTRL->STATUS.bit.OSC48MRDY) {
	}
}

static void mclk_init(void)
{
	MCLK->CPUDIV.reg = MCLK_CPUDIV_CPUDIV_DIV1_Val;
}

static void gclks_init(void)
{
	GCLK->GENCTRL[0].reg = GCLK_GENCTRL_SRC(GCLK_GENCTRL_SRC_OSC48M)
			     | GCLK_GENCTRL_DIV(1)
			     | GCLK_GENCTRL_GENEN;
}

<<<<<<< HEAD
static int atmel_samc_init(void)
{
	uint32_t key;


	key = irq_lock();

=======
void z_arm_platform_init(void)
{
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	flash_waitstates_init();
	osc48m_init();
	mclk_init();
	gclks_init();
<<<<<<< HEAD

	/* Install default handler that simply resets the CPU
	 * if configured in the kernel, NOP otherwise
	 */
	NMI_INIT();

	irq_unlock(key);

	return 0;
}

SYS_INIT(atmel_samc_init, PRE_KERNEL_1, 0);
=======
}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
