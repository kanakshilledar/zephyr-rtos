# SPDX-License-Identifier: Apache-2.0

zephyr_library()

zephyr_library_sources(
  soc.c
  )

<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_PM
  power.c
  )

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library_include_directories(
  ${ZEPHYR_BASE}/kernel/include
  ${ZEPHYR_BASE}/arch/arm/include
  )

<<<<<<< HEAD
if(CONFIG_SOC_NRF52832)
  if(CONFIG_SOC_NRF52832_ALLOW_SPIM_DESPITE_PAN_58)
    if(CONFIG_SPI_0_NRF_SPIM OR CONFIG_SPI_1_NRF_SPIM OR CONFIG_SPI_2_NRF_SPIM)
      message(WARNING "Both SOC_NRF52832_ALLOW_SPIM_DESPITE_PAN_58 and an NRF SPIM driver are enabled, therefore PAN 58 will apply if RXD.MAXCNT == 1 and TXD.MAXCNT <= 1")
=======
if(CONFIG_SOC_NRF52832_ALLOW_SPIM_DESPITE_PAN_58 AND CONFIG_SPI_NRFX_SPIM)
  message(WARNING "Both SOC_NRF52832_ALLOW_SPIM_DESPITE_PAN_58 and an NRF SPIM driver are enabled, therefore PAN 58 will apply if RXD.MAXCNT == 1 and TXD.MAXCNT <= 1")
endif()

if(CONFIG_SOC_NRF52832)
  if(NOT CONFIG_NRF52_ANOMALY_109_WORKAROUND)
    if (CONFIG_NRFX_SPIS OR CONFIG_NRFX_SPIM OR CONFIG_NRFX_TWIM OR CONFIG_NRFX_PWM)
      message(WARNING "NRF52_ANOMALY_109_WORKAROUND disabled with SPIS, SPIM, TWIM or PWM enabled. This will occasionally cause the first byte transmitted to be incorrect")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
    endif()
  endif()
endif()
