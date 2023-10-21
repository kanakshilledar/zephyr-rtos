# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/mbox.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_USERSPACE   mbox_handlers.c)
zephyr_library_sources_ifdef(CONFIG_MBOX_NRFX_IPC   mbox_nrfx_ipc.c)
zephyr_library_sources_ifdef(CONFIG_MBOX_NXP_S32_MRU   mbox_nxp_s32_mru.c)
<<<<<<< HEAD
=======
zephyr_library_sources_ifdef(CONFIG_MBOX_NXP_IMX_MU   mbox_nxp_imx_mu.c)
zephyr_library_sources_ifdef(CONFIG_MBOX_ANDES_PLIC_SW   mbox_andes_plic_sw.c)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
