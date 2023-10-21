# Copyright (c) 2019 Brett Witherspoon
#
# SPDX-License-Identifier: Apache-2.0

zephyr_sources(soc.c)
zephyr_sources(ccfg.c)

<<<<<<< HEAD
zephyr_library_sources_ifdef(CONFIG_PM    power.c)
zephyr_library_sources_ifdef(CONFIG_PM_DEVICE   power.c)
=======
if(CONFIG_PM OR CONFIG_PM_DEVICE OR CONFIG_POWEROFF)
  zephyr_library_sources(power.c)
endif()
zephyr_library_sources_ifdef(CONFIG_POWEROFF poweroff.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

zephyr_linker_sources_ifdef(CONFIG_HAS_TI_CCFG SECTIONS ccfg.ld)
