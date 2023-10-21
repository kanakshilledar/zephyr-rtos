/*
 * Copyright (c) 2021 ITE Corporation. All Rights Reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/pm/pm.h>
#include <soc.h>

/* Handle when enter deep doze mode. */
static void ite_power_soc_deep_doze(void)
{
	/* Enter deep doze mode */
	riscv_idle(CHIP_PLL_DEEP_DOZE, MSTATUS_IEN);
}

/* Invoke Low Power/System Off specific Tasks */
<<<<<<< HEAD
__weak void pm_state_set(enum pm_state state, uint8_t substate_id)
=======
void pm_state_set(enum pm_state state, uint8_t substate_id)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	ARG_UNUSED(substate_id);

	switch (state) {
	/* Deep doze mode */
	case PM_STATE_STANDBY:
		ite_power_soc_deep_doze();
		break;
	default:
		break;
	}
}

/* Handle SOC specific activity after Low Power Mode Exit */
<<<<<<< HEAD
__weak void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
=======
void pm_state_exit_post_ops(enum pm_state state, uint8_t substate_id)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	ARG_UNUSED(state);
	ARG_UNUSED(substate_id);
}
