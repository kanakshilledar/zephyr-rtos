# Copyright (c) 2022 Bjarki Arge Andreasen
# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(rtc_api)

target_sources(app PRIVATE
	src/main.c
	src/test_time_incrementing.c
	src/test_time.c
<<<<<<< HEAD
=======
	src/test_y2k.c
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
)

if(DEFINED CONFIG_RTC_ALARM)
	target_sources(app PRIVATE
		src/test_alarm_callback.c
		src/test_alarm.c
	)
endif()

if(DEFINED CONFIG_RTC_UPDATE)
	target_sources(app PRIVATE
		src/test_update_callback.c
	)
endif()

if(DEFINED CONFIG_RTC_CALIBRATION)
	target_sources(app PRIVATE
		src/test_calibrate.c
	)
endif()

target_include_directories(app PRIVATE inc)
