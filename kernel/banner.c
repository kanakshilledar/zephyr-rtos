/*
 * Copyright (c) 2020 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
#include <zephyr/device.h>
#include <version.h>

#if defined(CONFIG_BOOT_DELAY) && (CONFIG_BOOT_DELAY > 0)
#define DELAY_STR STRINGIFY(CONFIG_BOOT_DELAY)
#define BANNER_POSTFIX " (delayed boot " DELAY_STR "ms)"
#else
#define BANNER_POSTFIX ""
#endif

<<<<<<< HEAD
=======
#ifndef BANNER_VERSION
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#ifdef BUILD_VERSION
#define BANNER_VERSION STRINGIFY(BUILD_VERSION)
#else
#define BANNER_VERSION KERNEL_VERSION_STRING
#endif
<<<<<<< HEAD
=======
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

void boot_banner(void)
{
#if defined(CONFIG_BOOT_DELAY) && (CONFIG_BOOT_DELAY > 0)
	printk("***** delaying boot " DELAY_STR "ms (per build configuration) *****\n");
	k_busy_wait(CONFIG_BOOT_DELAY * USEC_PER_MSEC);
#endif /* defined(CONFIG_BOOT_DELAY) && (CONFIG_BOOT_DELAY > 0) */

<<<<<<< HEAD
#if CONFIG_BOOT_BANNER
	printk("*** Booting Zephyr OS build " BANNER_VERSION BANNER_POSTFIX " ***\n");
=======
#ifdef CONFIG_BOOT_BANNER
	printk("*** " CONFIG_BOOT_BANNER_STRING " " BANNER_VERSION BANNER_POSTFIX " ***\n");
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#endif /* CONFIG_BOOT_BANNER */
}
