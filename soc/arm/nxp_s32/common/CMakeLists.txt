<<<<<<< HEAD
# Copyright 2022 NXP
=======
# Copyright 2022-2023 NXP
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
# SPDX-License-Identifier: Apache-2.0

zephyr_include_directories(.)
zephyr_sources(osif.c)
<<<<<<< HEAD
=======
zephyr_sources_ifdef(CONFIG_SOC_SERIES_S32K3_M7 power_soc.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
