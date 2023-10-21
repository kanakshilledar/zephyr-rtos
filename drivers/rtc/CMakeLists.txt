# Copyright (c) 2022 Bjarki Arge Andreasen
# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USERSPACE rtc_handlers.c)
zephyr_library_sources_ifdef(CONFIG_RTC_EMUL rtc_emul.c)
zephyr_library_sources_ifdef(CONFIG_RTC_PCF8523 rtc_pcf8523.c)
zephyr_library_sources_ifdef(CONFIG_RTC_MOTOROLA_MC146818 rtc_mc146818.c)
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/rtc.h)

zephyr_library()

zephyr_library_sources_ifdef(CONFIG_RTC_AM1805 rtc_am1805.c)
zephyr_library_sources_ifdef(CONFIG_USERSPACE rtc_handlers.c)
zephyr_library_sources_ifdef(CONFIG_RTC_EMUL rtc_emul.c)
zephyr_library_sources_ifdef(CONFIG_RTC_PCF8523 rtc_pcf8523.c)
zephyr_library_sources_ifdef(CONFIG_RTC_PCF8563 rtc_pcf8563.c)
zephyr_library_sources_ifdef(CONFIG_RTC_MOTOROLA_MC146818 rtc_mc146818.c)
zephyr_library_sources_ifdef(CONFIG_RTC_STM32 rtc_ll_stm32.c)
zephyr_library_sources_ifdef(CONFIG_RTC_SHELL rtc_shell.c)
zephyr_library_sources_ifdef(CONFIG_RTC_FAKE rtc_fake.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
