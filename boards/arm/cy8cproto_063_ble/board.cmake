#**************************************************************************
# Copyright (c) 2023 Cypress Semiconductor Corporation (an Infineon company) or
# an affiliate of Cypress Semiconductor Corporation.
# SPDX-Licence-Identifier: Apache-2.0
#***************************************************************************

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
<<<<<<< HEAD
=======

board_runner_args(pyocd "--target=cy8c6xx7_nosmif")
include(${ZEPHYR_BASE}/boards/common/pyocd.board.cmake)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
