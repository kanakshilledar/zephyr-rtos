/*
 * Copyright (c) 2019 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdlib.h>
#include <zephyr/kernel.h>

void _exit(int status)
{
	printk("exit\n");
	while (1) {
<<<<<<< HEAD
=======
		Z_SPIN_DELAY(100);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
}
