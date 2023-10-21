/*
 * Copyright (c) 2012-2014 Wind River Systems, Inc.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
#include <zephyr/kernel.h>

int main(void)
{
	printk("Hello World! %s\n", CONFIG_BOARD);
=======
#include <stdio.h>

int main(void)
{
	printf("Hello World! %s\n", CONFIG_BOARD);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return 0;
}
