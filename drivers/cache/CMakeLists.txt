# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
zephyr_syscall_header(${ZEPHYR_BASE}/include/zephyr/cache.h)

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
zephyr_library()
zephyr_library_property(ALLOW_EMPTY TRUE)

zephyr_library_sources_ifdef(CONFIG_CACHE_ASPEED	cache_aspeed.c)
zephyr_library_sources_ifdef(CONFIG_USERSPACE		cache_handlers.c)
