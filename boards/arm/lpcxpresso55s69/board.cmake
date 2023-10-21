#
<<<<<<< HEAD
# Copyright (c) 2019, NXP
=======
# Copyright 2019, 2023 NXP
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#
# SPDX-License-Identifier: Apache-2.0
#


## DAP Link implementation in pyocd is underway,
## until then jlink can be used or copy image to storage

if(CONFIG_BOARD_LPCXPRESSO55S69_CPU0 OR CONFIG_SECOND_CORE_MCUX)
board_runner_args(jlink "--device=LPC55S69_M33_0")
<<<<<<< HEAD
=======
board_runner_args(linkserver  "--device=LPC55S69:LPCXpresso55S69")
board_runner_args(linkserver  "--override=/device/memory/0/flash-driver=LPC55xx_S.cfx")
board_runner_args(linkserver  "--override=/device/memory/0/location=0x10000000")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
elseif(CONFIG_BOARD_LPCXPRESSO55S69_CPU1)
board_runner_args(jlink "--device=LPC55S69_M33_1")
endif()

board_runner_args(pyocd "--target=lpc55s69")

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
<<<<<<< HEAD
=======
include(${ZEPHYR_BASE}/boards/common/linkserver.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
