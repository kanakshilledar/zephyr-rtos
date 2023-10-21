# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(bsim_test_host)


target_sources(app PRIVATE
  src/common.c
  src/main_collision.c
  src/main_autoconnect.c
  src/main_reconfigure.c
<<<<<<< HEAD
=======
  src/main_lowres.c
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
  src/main.c
)


zephyr_include_directories(
  ${BSIM_COMPONENTS_PATH}/libUtilv1/src/
  ${BSIM_COMPONENTS_PATH}/libPhyComv1/src/
  )
