/*
 * Copyright (c) 2021 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <soc.h>
#include <zephyr/init.h>

#include <stm32u5xx_ll_utils.h>
#include <stm32u5xx_ll_bus.h>
#include <stm32u5xx_ll_cortex.h>
#include <stm32u5xx_ll_pwr.h>
#include <stm32u5xx_ll_rcc.h>
#include <stm32u5xx_ll_system.h>
#include <clock_control/clock_stm32_ll_common.h>

#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(soc, CONFIG_SOC_LOG_LEVEL);

/* select MSI as wake-up system clock if configured, HSI otherwise */
#if STM32_SYSCLK_SRC_MSI
#define RCC_STOP_WAKEUPCLOCK_SELECTED LL_RCC_STOP_WAKEUPCLOCK_MSI
#else
#define RCC_STOP_WAKEUPCLOCK_SELECTED LL_RCC_STOP_WAKEUPCLOCK_HSI
#endif

void set_mode_stop(uint8_t substate_id)
{
	/* ensure the proper wake-up system clock */
	LL_RCC_SetClkAfterWakeFromStop(RCC_STOP_WAKEUPCLOCK_SELECTED);

	switch (substate_id) {
	case 1: /* enter STOP0 mode */
		LL_PWR_SetPowerMode(LL_PWR_STOP0_MODE);
		break;
	case 2: /* enter STOP1 mode */
		LL_PWR_SetPowerMode(LL_PWR_STOP1_MODE);
		break;
	case 3: /* enter STOP2 mode */
		LL_PWR_SetPowerMode(LL_PWR_STOP2_MODE);
		break;
	default:
		LOG_DBG("Unsupported power state substate-id %u", substate_id);
		break;
	}
}

void set_mode_standby(uint8_t substate_id)
{
	ARG_UNUSED(substate_id);
	/* Select standby mode */
	LL_PWR_SetPowerMode(LL_PWR_STANDBY_MODE);
}

<<<<<<< HEAD
void set_mode_shutdown(uint8_t substate_id)
{
	ARG_UNUSED(substate_id);
	/* Select shutdown mode */
	LL_PWR_SetPowerMode(LL_PWR_SHUTDOWN_MODE);
}

/* Invoke Low Power/System Off specific Tasks */
__weak void pm_state_set(enum pm_state state, uint8_t substate_id)
=======
/* Invoke Low Power/System Off specific Tasks */
void pm_state_set(enum pm_state state, uint8_t substate_id)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	switch (state) {
	case PM_STATE_SUSPEND_TO_IDLE:
		set_mode_stop(substate_id);
		break;
	case PM_STATE_STANDBY:
		/* To be tested */
		set_mode_standby(substate_id);
		break;
<<<<<<< HEAD
	case PM_STATE_SOFT_OFF:
		set_mode_shutdown(substate_id);
		break;
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	default:
		LOG_DBG("Unsupported power state %u", state);
		return;
	}

	/* Set SLEEPDEEP bit of Cortex System Control Register */
	LL_LPM_EnableDeepSleep();

	/* Select mode entry : WFE or WFI and enter the CPU selected mode */
	k_cpu_idle();
}

/* Handle SOC specific activity after Low Power Mode Exit */
<<<<<<< HEAD
__weak void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
=======
void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	switch (state) {
	case PM_STATE_SUSPEND_TO_IDLE:
		if (substate_id <= 3) {
			LL_LPM_DisableSleepOnExit();
			LL_LPM_EnableSleep();
		} else {
			LOG_DBG("Unsupported power substate-id %u",
							substate_id);
		}
	case PM_STATE_STANDBY:
		/* To be tested */
		LL_LPM_EnableSleep();
<<<<<<< HEAD
	case PM_STATE_SOFT_OFF:
		/* We should not get there */
		__fallthrough;
	case PM_STATE_ACTIVE:
		__fallthrough;
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	case PM_STATE_SUSPEND_TO_RAM:
		__fallthrough;
	case PM_STATE_SUSPEND_TO_DISK:
		__fallthrough;
	default:
		LOG_DBG("Unsupported power state %u", state);
		break;
	}
	/* need to restore the clock */
	stm32_clock_control_init(NULL);

	/*
	 * System is now in active mode.
	 * Reenable interrupts which were disabled
	 * when OS started idling code.
	 */
	irq_unlock(0);
}

/* Initialize STM32 Power */
static int stm32_power_init(void)
{

	/* enable Power clock */
	LL_AHB3_GRP1_EnableClock(LL_AHB3_GRP1_PERIPH_PWR);

<<<<<<< HEAD
#ifdef CONFIG_DEBUG
	/* Enable the Debug Module during all and any Low power mode */
	LL_DBGMCU_EnableDBGStopMode();
#endif /* CONFIG_DEBUG */

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return 0;
}

SYS_INIT(stm32_power_init, PRE_KERNEL_1, CONFIG_KERNEL_INIT_PRIORITY_DEFAULT);
