/*
 * Copyright (c) 2022 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define DT_DRV_COMPAT intel_adsp_hda_host_in

#include <zephyr/drivers/dma.h>
<<<<<<< HEAD
=======
#include <adsp_interrupt.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include "dma_intel_adsp_hda.h"

static const struct dma_driver_api intel_adsp_hda_dma_host_in_api = {
	.config = intel_adsp_hda_dma_host_in_config,
	.reload = intel_adsp_hda_dma_host_reload,
	.start = intel_adsp_hda_dma_start,
	.stop = intel_adsp_hda_dma_stop,
	.get_status = intel_adsp_hda_dma_status,
	.get_attribute = intel_adsp_hda_dma_get_attribute,
	.chan_filter = intel_adsp_hda_dma_chan_filter,
};

#define INTEL_ADSP_HDA_DMA_HOST_IN_INIT(inst)                                                      \
<<<<<<< HEAD
=======
	static void intel_adsp_hda_dma##inst##_irq_config(void);				   \
									                           \
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	static const struct intel_adsp_hda_dma_cfg intel_adsp_hda_dma##inst##_config = {           \
		.base = DT_INST_REG_ADDR(inst),                                                    \
		.regblock_size  = DT_INST_REG_SIZE(inst),					   \
		.dma_channels = DT_INST_PROP(inst, dma_channels),                                  \
<<<<<<< HEAD
		.direction = MEMORY_TO_HOST                                                        \
=======
		.direction = MEMORY_TO_HOST,                                                       \
		.irq_config = intel_adsp_hda_dma##inst##_irq_config				   \
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	};                                                                                         \
												   \
	static struct intel_adsp_hda_dma_data intel_adsp_hda_dma##inst##_data = {};                \
												   \
	PM_DEVICE_DT_INST_DEFINE(inst, intel_adsp_hda_dma_pm_action);				   \
												   \
	DEVICE_DT_INST_DEFINE(inst, &intel_adsp_hda_dma_init,					   \
			      PM_DEVICE_DT_INST_GET(inst),					   \
			      &intel_adsp_hda_dma##inst##_data,                                    \
			      &intel_adsp_hda_dma##inst##_config, POST_KERNEL,                     \
			      CONFIG_DMA_INIT_PRIORITY,                                            \
<<<<<<< HEAD
			      &intel_adsp_hda_dma_host_in_api);
=======
			      &intel_adsp_hda_dma_host_in_api);		\
									\
	static void intel_adsp_hda_dma##inst##_irq_config(void)		\
	{								\
		IRQ_CONNECT(DT_INST_IRQN(inst),			\
			    DT_INST_IRQ(inst, priority), intel_adsp_hda_dma_isr,	\
			    DEVICE_DT_INST_GET(inst),			\
			    DT_INST_IRQ(inst, sense));			\
		irq_enable(DT_INST_IRQN(inst));			\
		IF_ENABLED(CONFIG_SOC_SERIES_INTEL_ACE, (ACE_DINT[0].ie[ACE_INTL_HDAHIDMA] = 1;)) \
	}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

DT_INST_FOREACH_STATUS_OKAY(INTEL_ADSP_HDA_DMA_HOST_IN_INIT)
