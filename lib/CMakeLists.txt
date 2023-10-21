# SPDX-License-Identifier: Apache-2.0

<<<<<<< HEAD
=======
# FIXME: SHADOW_VARS: Remove this once we have enabled -Wshadow globally.
add_compile_options($<TARGET_PROPERTY:compiler,warning_shadow_variables>)

add_subdirectory(crc)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
if(NOT CONFIG_EXTERNAL_LIBC)
add_subdirectory(libc)
add_subdirectory(posix)
endif()
add_subdirectory_ifdef(CONFIG_CPP                  cpp)
add_subdirectory(hash)
add_subdirectory(os)
add_subdirectory_ifdef(CONFIG_SMF smf)
add_subdirectory_ifdef(CONFIG_OPENAMP              open-amp)
<<<<<<< HEAD
=======
add_subdirectory_ifdef(CONFIG_ACPI acpi)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
