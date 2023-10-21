# Copyright (c) 2022 Intel Corporation
#
# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/drivers/i3c.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()

zephyr_library_sources(
  i3c_ccc.c
  i3c_common.c
)

zephyr_library_sources_ifdef(
  CONFIG_USERSPACE
  i3c_handlers.c
)

zephyr_library_sources_ifdef(
  CONFIG_I3C_IBI_WORKQUEUE
  i3c_ibi_workq.c
)

zephyr_library_sources_ifdef(
  CONFIG_I3C_MCUX
  i3c_mcux.c
)

zephyr_library_sources_ifdef(
  CONFIG_I3C_CADENCE
  i3c_cdns.c
)
