# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

<<<<<<< HEAD
set(DTC_OVERLAY_FILE "${CMAKE_CURRENT_SOURCE_DIR}/ens210.overlay")

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(ens210)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
