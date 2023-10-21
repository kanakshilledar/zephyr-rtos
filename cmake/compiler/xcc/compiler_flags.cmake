# SPDX-License-Identifier: Apache-2.0

include(${ZEPHYR_BASE}/cmake/compiler/gcc/compiler_flags.cmake)

# XCC is based on GCC 4.2 which has a somewhat pedantic take on the
# fact that linkage semantics differed between C99 and GNU at the
# time.  Suppress the warning, it's the best we can do given that
# it's a legacy compiler.
check_set_compiler_property(APPEND PROPERTY warning_base "-fgnu89-inline")

set_compiler_property(PROPERTY warning_error_misra_sane)

# XCC does not support -fno-pic and -fno-pie
set_compiler_property(PROPERTY no_position_independent "")
<<<<<<< HEAD
=======

# Remove after testing that -Wshadow works
set_compiler_property(PROPERTY warning_shadow_variables)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
