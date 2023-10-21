# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/ptp_clock.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_PTP_CLOCK ptp_clock.c)
