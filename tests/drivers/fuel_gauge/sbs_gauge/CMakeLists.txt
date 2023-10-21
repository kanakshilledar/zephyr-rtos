# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(device)

<<<<<<< HEAD
FILE(GLOB app_sources src/test_sbs_gauge.c)
target_sources(app PRIVATE ${app_sources})
=======
target_sources(app PRIVATE src/test_sbs_gauge.c)
target_sources_ifndef(CONFIG_TEST_SBS_CUTOFF_EXTENSION app PRIVATE src/test_cutoff_disabled.c)
target_sources_ifdef(CONFIG_TEST_SBS_CUTOFF_EXTENSION app PRIVATE src/test_cutoff.c)

target_include_directories(app PRIVATE include)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
