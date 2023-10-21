# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
zephyr_library()
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_HD44780		auxdisplay_hd44780.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_ITRON		auxdisplay_itron.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_JHD1313		auxdisplay_jhd1313.c)
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/auxdisplay.h)

zephyr_library()
zephyr_library_sources_ifdef(CONFIG_USERSPACE			auxdisplay_handlers.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_HD44780		auxdisplay_hd44780.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_ITRON		auxdisplay_itron.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_JHD1313		auxdisplay_jhd1313.c)
zephyr_library_sources_ifdef(CONFIG_AUXDISPLAY_PT6314		auxdisplay_pt6314.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
