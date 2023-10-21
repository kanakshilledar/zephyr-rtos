# SPDX-License-Identifier: Apache-2.0

# See root CMakeLists.txt for description and expectations of these macros

macro(toolchain_ld_cpp)

<<<<<<< HEAD
  zephyr_link_libraries(
    -lstdc++
  )
=======
  if(NOT CONFIG_EXTERNAL_MODULE_LIBCPP)
    zephyr_link_libraries(
      -lstdc++
    )
  endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

endmacro()
