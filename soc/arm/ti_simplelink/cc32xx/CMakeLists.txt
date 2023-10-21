# SPDX-License-Identifier: Apache-2.0

zephyr_sources(soc.c)
<<<<<<< HEAD
=======
zephyr_include_directories(.)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

if (DEFINED CONFIG_CC3220SF_DEBUG OR DEFINED CONFIG_CC3235SF_DEBUG)
  zephyr_linker_sources(ROM_START SORT_KEY 0 cc32xx_debug.ld)
endif()
