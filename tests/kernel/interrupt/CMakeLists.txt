# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(interrupt)

target_include_directories(app PRIVATE
  ${ZEPHYR_BASE}/kernel/include
  ${ZEPHYR_BASE}/arch/${ARCH}/include
  )

target_sources(app PRIVATE
    src/prevent_irq.c
    src/interrupt_offload.c
    src/nested_irq.c
    )

target_sources_ifdef(CONFIG_DYNAMIC_INTERRUPTS app PRIVATE src/dynamic_isr.c)
target_sources_ifdef(CONFIG_X86 app PRIVATE src/regular_isr.c)
<<<<<<< HEAD
=======
target_sources_ifdef(CONFIG_SHARED_INTERRUPTS app PRIVATE src/static_shared_irq.c)

if (CONFIG_SHARED_INTERRUPTS)
target_sources_ifdef(CONFIG_DYNAMIC_INTERRUPTS app PRIVATE src/dynamic_shared_irq.c)
endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
