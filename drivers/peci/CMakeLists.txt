# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/peci.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_PECI_XEC	peci_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_PECI_ITE_IT8XXX2	peci_ite_it8xxx2.c)
zephyr_library_sources_ifdef(CONFIG_PECI_NPCX	peci_npcx.c)
zephyr_library_sources_ifdef(CONFIG_USERSPACE   peci_handlers.c)
