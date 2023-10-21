/*
 * Copyright (c) 2021 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */


#ifndef ZEPHYR_INCLUDE_DRIVERS_PCIE_PTM_H_
#define ZEPHYR_INCLUDE_DRIVERS_PCIE_PTM_H_

<<<<<<< HEAD
=======
/**
 * @brief PCIe Host PTM Interface
 * @defgroup pcie_host_ptm_interface PCIe Host PTM Interface
 * @ingroup pcie_host_interface
 * @{
 */

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <stddef.h>
#include <zephyr/types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Enable PTM on endpoint
 *
 * @param bdf the PCI(e) endpoint
 * @return true if that was successful, false otherwise
 */
bool pcie_ptm_enable(pcie_bdf_t bdf);

#ifdef __cplusplus
}
#endif

<<<<<<< HEAD
=======
/**
 * @}
 */

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#endif /* ZEPHYR_INCLUDE_DRIVERS_PCIE_PTM_H_ */
