/*
 * Copyright (c) 2021, Teslabs Engineering S.L.
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/irq.h>

static int gd32f4xx_soc_init(void)
{
	uint32_t key;


	key = irq_lock();

	SystemInit();
	NMI_INIT();

	irq_unlock(key);
=======
#include <soc.h>

static int gd32f4xx_soc_init(void)
{
	SystemInit();
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return 0;
}

SYS_INIT(gd32f4xx_soc_init, PRE_KERNEL_1, 0);
