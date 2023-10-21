# Copyright 2023 Nordic Semiconductor ASA
# SPDX-License-Identifier: Apache-2.0

zephyr_library()

<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_MFD_NPM6001 mfd_npm6001.c)
=======
zephyr_library_sources_ifdef(CONFIG_MFD_NCT38XX mfd_nct38xx.c)
zephyr_library_sources_ifdef(CONFIG_MFD_NPM1300 mfd_npm1300.c)
zephyr_library_sources_ifdef(CONFIG_MFD_NPM6001 mfd_npm6001.c)
zephyr_library_sources_ifdef(CONFIG_MFD_AXP192 mfd_axp192.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
