/*
 * Copyright (c) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */
<<<<<<< HEAD
#include <zephyr/device.h>
=======
#include <zephyr/init.h>
#include <zephyr/linker/section_tags.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

extern void power_init(void);
extern void adsp_clock_init(void);

#if CONFIG_MP_MAX_NUM_CPUS > 1
extern void soc_mp_init(void);
#endif

static __imr int soc_init(void)
{
	power_init();

#ifdef CONFIG_ADSP_CLOCK
	adsp_clock_init();
#endif

#if CONFIG_MP_MAX_NUM_CPUS > 1
	soc_mp_init();
#endif

	return 0;
}

SYS_INIT(soc_init, PRE_KERNEL_1, 99);
