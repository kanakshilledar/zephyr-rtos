# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/smbus.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_SMBUS_SHELL		smbus_shell.c)
zephyr_library_sources_ifdef(CONFIG_SMBUS_INTEL_PCH	intel_pch_smbus.c)

zephyr_library_sources_ifdef(CONFIG_USERSPACE		smbus_handlers.c)
