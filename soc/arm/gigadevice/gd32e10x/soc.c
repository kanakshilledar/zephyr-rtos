/*
 * Copyright (c) 2021 YuLong Yao <feilongphone@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/irq.h>
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <soc.h>

static int gd32e10x_soc_init(void)
{
<<<<<<< HEAD
	uint32_t key;


	key = irq_lock();

	SystemInit();
	NMI_INIT();

	irq_unlock(key);
=======
	SystemInit();
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return 0;
}

SYS_INIT(gd32e10x_soc_init, PRE_KERNEL_1, 0);
