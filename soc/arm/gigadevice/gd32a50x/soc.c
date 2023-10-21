/*
 * Copyright (c) 2022 YuLong Yao <feilongphone@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/irq.h>
=======
#include <soc.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

/* initial ecc memory */
void z_arm_platform_init(void)
{
	register unsigned r0 __asm("r0") = DT_REG_ADDR(DT_CHOSEN(zephyr_sram));
	register unsigned r1 __asm("r1") =
		DT_REG_ADDR(DT_CHOSEN(zephyr_sram)) + DT_REG_SIZE(DT_CHOSEN(zephyr_sram));

	for (; r0 < r1; r0 += 4) {
		*(unsigned int *)r0 = 0;
	}
}

static int gd32a50x_soc_init(void)
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

SYS_INIT(gd32a50x_soc_init, PRE_KERNEL_1, 0);
