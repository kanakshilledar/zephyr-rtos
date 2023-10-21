#
<<<<<<< HEAD
# Copyright (c) 2018, NXP
=======
# Copyright 2018, 2023 NXP
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#
# SPDX-License-Identifier: Apache-2.0
#

board_runner_args(pyocd "--target=mimxrt1064")
board_runner_args(jlink "--device=MIMXRT1064")
<<<<<<< HEAD

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
=======
board_runner_args(linkserver  "--device=MIMXRT1064xxxxA:EVK-MIMXRT1064")

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/linkserver.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
