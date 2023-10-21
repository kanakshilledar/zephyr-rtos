# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(events_api)

FILE(GLOB app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})
<<<<<<< HEAD
=======

target_include_directories(app PRIVATE
  ${ZEPHYR_BASE}/kernel/include
  )
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
