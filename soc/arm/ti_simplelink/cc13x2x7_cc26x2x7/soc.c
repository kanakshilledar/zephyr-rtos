/*
 * Copyright (c) 2022 Vaishnav Achath
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>

#include <driverlib/setup.h>

<<<<<<< HEAD
static int ti_cc13x2_cc26x2_init(void)
=======
static int ti_cc13x7_cc26x7_init(void)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{

	/* Performs necessary trim of the device. */
	SetupTrimDevice();

	return 0;
}

<<<<<<< HEAD
SYS_INIT(ti_cc13x2_cc26x2_init, PRE_KERNEL_1, 0);
=======
SYS_INIT(ti_cc13x7_cc26x7_init, PRE_KERNEL_1, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
