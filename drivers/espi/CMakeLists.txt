# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/espi.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_ESPI_XEC		espi_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_NPCX		espi_npcx.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_NPCX		host_subs_npcx.c)
zephyr_library_sources_ifdef(CONFIG_USERSPACE		espi_handlers.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_EMUL		espi_emul.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_SAF_XEC	espi_saf_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_XEC_V2		espi_mchp_xec_v2.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_XEC_V2		espi_mchp_xec_host_v2.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_IT8XXX2	espi_it8xxx2.c)
zephyr_library_sources_ifdef(CONFIG_ESPI_SAF_XEC_V2	espi_saf_mchp_xec_v2.c)
