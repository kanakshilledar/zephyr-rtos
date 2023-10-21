/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/* nRF51 and nRF52 Series IRQ mapping*/
#if defined(CONFIG_SOC_SERIES_NRF51X) || defined(CONFIG_SOC_COMPATIBLE_NRF52X)

#define HAL_SWI_RADIO_IRQ  SWI4_IRQn
#define HAL_SWI_WORKER_IRQ RTC0_IRQn

#if !defined(CONFIG_BT_CTLR_LOW_LAT) && \
	(CONFIG_BT_CTLR_ULL_HIGH_PRIO == CONFIG_BT_CTLR_ULL_LOW_PRIO)
#define HAL_SWI_JOB_IRQ    HAL_SWI_WORKER_IRQ
#else
#define HAL_SWI_JOB_IRQ    SWI5_IRQn
#endif

/* nRF53 Series IRQ mapping */
<<<<<<< HEAD
#elif defined(CONFIG_SOC_SERIES_NRF53X)

/* nRF53 Series Engineering D and Revision 1 IRQ mapping */
#if defined(CONFIG_SOC_NRF5340_CPUNET)
=======
#elif defined(CONFIG_SOC_COMPATIBLE_NRF53X)

/* nRF53 Series Engineering D and Revision 1 IRQ mapping */
#if defined(CONFIG_SOC_COMPATIBLE_NRF5340_CPUNET)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#define HAL_SWI_RADIO_IRQ  SWI2_IRQn
#define HAL_SWI_WORKER_IRQ RTC0_IRQn

#if !defined(CONFIG_BT_CTLR_LOW_LAT) && \
	(CONFIG_BT_CTLR_ULL_HIGH_PRIO == CONFIG_BT_CTLR_ULL_LOW_PRIO)
#define HAL_SWI_JOB_IRQ    HAL_SWI_WORKER_IRQ
#else
#define HAL_SWI_JOB_IRQ    SWI3_IRQn
#endif

<<<<<<< HEAD
#endif /* CONFIG_SOC_NRF5340_CPUNET */

#endif /* CONFIG_SOC_SERIES_NRF53X */
=======
#endif /* CONFIG_SOC_COMPATIBLE_NRF5340_CPUNET */

#endif /* CONFIG_SOC_COMPATIBLE_NRF53X */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

static inline void hal_swi_init(void)
{
	/* No platform-specific initialization required. */
}

static inline void hal_swi_lll_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_RADIO_IRQ);
}

static inline void hal_swi_worker_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_WORKER_IRQ);
}

static inline void hal_swi_job_pend(void)
{
	NVIC_SetPendingIRQ(HAL_SWI_JOB_IRQ);
}
