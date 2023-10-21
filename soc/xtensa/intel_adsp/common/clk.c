/*
 * Copyright (c) 2022 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <errno.h>

#include <zephyr/device.h>
#include <zephyr/kernel.h>
#include <zephyr/spinlock.h>
<<<<<<< HEAD
=======
#include <zephyr/sys/util.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#include <adsp_clk.h>
#include <adsp_shim.h>

<<<<<<< HEAD
static struct adsp_clock_info platform_clocks[CONFIG_MP_MAX_NUM_CPUS];
static struct k_spinlock lock;

int adsp_clock_freq_enc[] = ADSP_CLOCK_FREQ_ENC;
int adsp_clock_freq_mask[] = ADSP_CLOCK_FREQ_MASK;
=======
static struct adsp_cpu_clock_info platform_cpu_clocks[CONFIG_MP_MAX_NUM_CPUS];
static struct k_spinlock lock;

int adsp_clock_freq_enc[] = ADSP_CPU_CLOCK_FREQ_ENC;
int adsp_clock_freq_mask[] = ADSP_CPU_CLOCK_FREQ_MASK;

#define HW_CLK_CHANGE_TIMEOUT_USEC 10000
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

static void select_cpu_clock_hw(uint32_t freq_idx)
{
	uint32_t enc = adsp_clock_freq_enc[freq_idx];
<<<<<<< HEAD
=======

#ifdef CONFIG_SOC_SERIES_INTEL_ACE
	uint32_t clk_ctl = ADSP_CLKCTL;

	clk_ctl &= ~ADSP_CLKCTL_OSC_SOURCE_MASK;
	clk_ctl |= (enc & ADSP_CLKCTL_OSC_SOURCE_MASK);

	ADSP_CLKCTL = clk_ctl;
#else
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	uint32_t status_mask = adsp_clock_freq_mask[freq_idx];

	/* Request clock */
	ADSP_CLKCTL |= enc;

	/* Wait for requested clock to be on */
<<<<<<< HEAD
	while ((ADSP_CLKCTL & status_mask) != status_mask) {
		k_busy_wait(10);
=======
	if (!WAIT_FOR((ADSP_CLKCTL & status_mask) == status_mask,
		      HW_CLK_CHANGE_TIMEOUT_USEC, k_busy_wait(1))) {
		k_panic();
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	/* Switch to requested clock */
	ADSP_CLKCTL = (ADSP_CLKCTL & ~ADSP_CLKCTL_OSC_SOURCE_MASK) |
			    enc;

	/* Release other clocks */
	ADSP_CLKCTL &= ~ADSP_CLKCTL_OSC_REQUEST_MASK | enc;
<<<<<<< HEAD
}

int adsp_clock_set_freq(uint32_t freq_idx)
=======
#endif
}

int adsp_clock_set_cpu_freq(uint32_t freq_idx)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	k_spinlock_key_t k;
	int i;

<<<<<<< HEAD
	if (freq_idx >= ADSP_CLOCK_FREQ_LEN) {
=======
	if (freq_idx >= ADSP_CPU_CLOCK_FREQ_LEN) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		return -EINVAL;
	}

	k = k_spin_lock(&lock);

	select_cpu_clock_hw(freq_idx);

	unsigned int num_cpus = arch_num_cpus();

	for (i = 0; i < num_cpus; i++) {
<<<<<<< HEAD
		platform_clocks[i].current_freq = freq_idx;
=======
		platform_cpu_clocks[i].current_freq = freq_idx;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	k_spin_unlock(&lock, k);

	return 0;
}

<<<<<<< HEAD
struct adsp_clock_info *adsp_clocks_get(void)
{
	return platform_clocks;
=======
struct adsp_cpu_clock_info *adsp_cpu_clocks_get(void)
{
	return platform_cpu_clocks;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

void adsp_clock_init(void)
{
<<<<<<< HEAD
	uint32_t platform_lowest_freq_idx = ADSP_CLOCK_FREQ_LOWEST;
=======
	uint32_t platform_lowest_freq_idx = ADSP_CPU_CLOCK_FREQ_LOWEST;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	int i;

#ifdef ADSP_CLOCK_HAS_WOVCRO
#ifdef CONFIG_SOC_SERIES_INTEL_ACE
	ACE_DfPMCCU.dfclkctl |= ACE_CLKCTL_WOVCRO;
	if (ACE_DfPMCCU.dfclkctl & ACE_CLKCTL_WOVCRO) {
		ACE_DfPMCCU.dfclkctl = ACE_DfPMCCU.dfclkctl & ~ACE_CLKCTL_WOVCRO;
	} else {
<<<<<<< HEAD
		platform_lowest_freq_idx = ADSP_CLOCK_FREQ_LPRO;
=======
		platform_lowest_freq_idx = ADSP_CPU_CLOCK_FREQ_IPLL;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
#else
	CAVS_SHIM.clkctl |= CAVS_CLKCTL_WOVCRO;
	if (CAVS_SHIM.clkctl & CAVS_CLKCTL_WOVCRO) {
		CAVS_SHIM.clkctl = CAVS_SHIM.clkctl & ~CAVS_CLKCTL_WOVCRO;
	} else {
<<<<<<< HEAD
		platform_lowest_freq_idx = ADSP_CLOCK_FREQ_LPRO;
=======
		platform_lowest_freq_idx = ADSP_CPU_CLOCK_FREQ_LPRO;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
#endif /* CONFIG_SOC_SERIES_INTEL_ACE */
#endif /* ADSP_CLOCK_HAS_WOVCRO */

	unsigned int num_cpus = arch_num_cpus();

	for (i = 0; i < num_cpus; i++) {
<<<<<<< HEAD
		platform_clocks[i].default_freq = ADSP_CLOCK_FREQ_DEFAULT;
		platform_clocks[i].current_freq = ADSP_CLOCK_FREQ_DEFAULT;
		platform_clocks[i].lowest_freq = platform_lowest_freq_idx;
	}
}
=======
		platform_cpu_clocks[i].default_freq = ADSP_CPU_CLOCK_FREQ_DEFAULT;
		platform_cpu_clocks[i].current_freq = ADSP_CPU_CLOCK_FREQ_DEFAULT;
		platform_cpu_clocks[i].lowest_freq = platform_lowest_freq_idx;
	}
}

struct adsp_clock_source_desc adsp_clk_src_info[ADSP_CLOCK_SOURCE_COUNT] = {
#ifndef CONFIG_DAI_DMIC_HW_IOCLK
	[ADSP_CLOCK_SOURCE_XTAL_OSC] = { DT_PROP(DT_NODELABEL(sysclk), clock_frequency) },
#else
	/* Temporarily use the values from the configuration until set xtal frequency via ipc
	 * support is added.
	 */
	[ADSP_CLOCK_SOURCE_XTAL_OSC] = { CONFIG_DAI_DMIC_HW_IOCLK },
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(audioclk), okay)
	[ADSP_CLOCK_SOURCE_AUDIO_CARDINAL] = { DT_PROP(DT_NODELABEL(audioclk), clock_frequency) },
#endif
#if DT_NODE_HAS_STATUS(DT_NODELABEL(pllclk), okay)
	[ADSP_CLOCK_SOURCE_AUDIO_PLL_FIXED] = { DT_PROP(DT_NODELABEL(pllclk), clock_frequency) },
#endif
	[ADSP_CLOCK_SOURCE_MLCK_INPUT] = { 0 },
#ifdef ADSP_CLOCK_HAS_WOVCRO
	[ADSP_CLOCK_SOURCE_WOV_RING_OSC] = { DT_PROP(DT_NODELABEL(sysclk), clock_frequency) },
#endif
};

bool adsp_clock_source_is_supported(int source)
{
	if (source < 0 || source >= ADSP_CLOCK_SOURCE_COUNT) {
		return false;
	}

	return !!adsp_clk_src_info[source].frequency;
}

uint32_t adsp_clock_source_frequency(int source)
{
	if (source < 0 || source >= ADSP_CLOCK_SOURCE_COUNT) {
		return 0;
	}

	return adsp_clk_src_info[source].frequency;
}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
