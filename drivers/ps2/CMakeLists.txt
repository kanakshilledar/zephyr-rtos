# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/ps2.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources_ifdef(CONFIG_PS2_XEC		ps2_mchp_xec.c)
zephyr_library_sources_ifdef(CONFIG_USERSPACE           ps2_handlers.c)
zephyr_library_sources_ifdef(CONFIG_PS2_NPCX		ps2_npcx_channel.c)
zephyr_library_sources_ifdef(CONFIG_PS2_NPCX		ps2_npcx_controller.c)
