# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
board_runner_args(blackmagicprobe "--connect-rst")
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
board_runner_args(jlink "--device=STM32F103RB" "--speed=4000")

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
include(${ZEPHYR_BASE}/boards/common/jlink.board.cmake)
<<<<<<< HEAD
=======
include(${ZEPHYR_BASE}/boards/common/blackmagicprobe.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
