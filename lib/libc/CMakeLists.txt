# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(
  ${ZEPHYR_BASE}/include/zephyr/sys/libc-hooks.h
)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
add_subdirectory_ifdef(CONFIG_ARCMWDT_LIBC      arcmwdt)
add_subdirectory_ifdef(CONFIG_ARMCLANG_STD_LIBC armstdc)
add_subdirectory_ifdef(CONFIG_MINIMAL_LIBC      minimal)
add_subdirectory_ifdef(CONFIG_NEWLIB_LIBC       newlib)
add_subdirectory_ifdef(CONFIG_PICOLIBC          picolibc)

add_subdirectory(common)
