/*
 * Copyright (c) 2016 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/**
 * @file
 * @brief System/hardware module for Nordic Semiconductor nRF52 family processor
 *
 * This module provides routines to initialize and support board-level hardware
 * for the Nordic Semiconductor nRF52 family processor.
 */

#include <zephyr/kernel.h>
#include <zephyr/init.h>
<<<<<<< HEAD
#include <zephyr/arch/arm/aarch32/cortex_m/cmsis.h>
#include <zephyr/arch/arm/aarch32/nmi.h>
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <hal/nrf_power.h>
#include <soc/nrfx_coredep.h>
#include <zephyr/logging/log.h>

<<<<<<< HEAD
=======
#include <cmsis_core.h>

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define LOG_LEVEL CONFIG_SOC_LOG_LEVEL
LOG_MODULE_REGISTER(soc);

#ifdef CONFIG_NRF_STORE_REBOOT_TYPE_GPREGRET
/* Overrides the weak ARM implementation:
 * Set general purpose retention register and reboot
 * This is deprecated and has been replaced with the boot mode retention
 * subsystem
 */
void sys_arch_reboot(int type)
{
	nrf_power_gpregret_set(NRF_POWER, (uint8_t)type);
	NVIC_SystemReset();
}
#endif

static int nordicsemi_nrf52_init(void)
{
<<<<<<< HEAD
	uint32_t key;


	key = irq_lock();

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#ifdef CONFIG_NRF_ENABLE_ICACHE
	/* Enable the instruction cache */
	NRF_NVMC->ICACHECNF = NVMC_ICACHECNF_CACHEEN_Msk;
#endif

#if defined(CONFIG_SOC_DCDC_NRF52X)
	nrf_power_dcdcen_set(NRF_POWER, true);
#endif
#if NRF_POWER_HAS_DCDCEN_VDDH && defined(CONFIG_SOC_DCDC_NRF52X_HV)
	nrf_power_dcdcen_vddh_set(NRF_POWER, true);
#endif

<<<<<<< HEAD
	/* Install default handler that simply resets the CPU
	* if configured in the kernel, NOP otherwise
	*/
	NMI_INIT();

	irq_unlock(key);

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return 0;
}

void arch_busy_wait(uint32_t time_us)
{
	nrfx_coredep_delay_us(time_us);
}

SYS_INIT(nordicsemi_nrf52_init, PRE_KERNEL_1, 0);
