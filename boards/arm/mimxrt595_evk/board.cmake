#
<<<<<<< HEAD
# Copyright (c) 2022, NXP
=======
# Copyright 2022-2023 NXP
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#
# SPDX-License-Identifier: Apache-2.0
#

board_runner_args(jlink "--device=MIMXRT595S_M33" "--reset-after-load")
<<<<<<< HEAD

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
=======
board_runner_args(linkserver  "--device=MIMXRT595S:EVK-MIMXRT595")
board_runner_args(linkserver  "--override=/device/memory/5/flash-driver=MIMXRT500_SFDP_MXIC_OSPI_S.cfx")
board_runner_args(linkserver  "--override=/device/memory/5/location=0x18000000")



include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/linkserver.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
