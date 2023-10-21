# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(metairq_dispatch)

target_sources(app PRIVATE src/main.c src/msgdev.c)
<<<<<<< HEAD
=======

target_include_directories(app PRIVATE
  ${ZEPHYR_BASE}/kernel/include
  )
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
