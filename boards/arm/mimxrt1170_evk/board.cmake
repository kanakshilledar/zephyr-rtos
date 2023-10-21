#
# Copyright (c) 2021, NXP
#
# SPDX-License-Identifier: Apache-2.0
#

if(CONFIG_SOC_MIMXRT1176_CM7 OR CONFIG_SECOND_CORE_MCUX)
<<<<<<< HEAD
board_runner_args(pyocd "--target=mimxrt1170_cm7")
board_runner_args(jlink "--device=MIMXRT1176xxxA_M7" "--reset-after-load")
elseif(CONFIG_SOC_MIMXRT1176_CM4)
board_runner_args(pyocd "--target=mimxrt1170_cm4")
# Note: Please use JLINK above V7.50 (Only support run cm4 image when debugging due to default boot core on board is cm7 core)
board_runner_args(jlink "--device=MIMXRT1176xxxA_M4")
=======
 board_runner_args(pyocd "--target=mimxrt1170_cm7")
 board_runner_args(jlink "--device=MIMXRT1176xxxA_M7" "--reset-after-load")

 if(CONFIG_BOARD_MIMXRT1170_EVK_CM7)
  board_runner_args(linkserver  "--device=MIMXRT1176xxxxx:MIMXRT1170-EVK")
 elseif(CONFIG_BOARD_MIMXRT1170_EVKB_CM7)
  board_runner_args(linkserver "--device=MIMXRT1176xxxxx:MIMXRT1170-EVKB")
 endif()

 board_runner_args(linkserver "--core=cm7")
elseif(CONFIG_SOC_MIMXRT1176_CM4)
 board_runner_args(pyocd "--target=mimxrt1170_cm4")
 # Note: Please use JLINK above V7.50 (Only support run cm4 image when debugging due to default boot core on board is cm7 core)
 board_runner_args(jlink "--device=MIMXRT1176xxxA_M4")
 if(CONFIG_BOARD_MIMXRT1170_EVK_CM4)
  board_runner_args(linkserver "--device=MIMXRT1176xxxxx:MIMXRT1170-EVK")
 elseif(CONFIG_BOARD_MIMXRT1170_EVKB_CM4)
  board_runner_args(linkserver "--device=MIMXRT1176xxxxx:MIMXRT1170-EVKB")
 endif()
 board_runner_args(linkserver "--core=cm4")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
endif()

include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
<<<<<<< HEAD
=======
include(${ZEPHYR_BASE}/boards/common/linkserver.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
