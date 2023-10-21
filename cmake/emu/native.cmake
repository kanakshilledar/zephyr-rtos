# SPDX-License-Identifier: Apache-2.0

add_custom_target(run_native
  COMMAND
  ${APPLICATION_BINARY_DIR}/zephyr/${KERNEL_EXE_NAME}
<<<<<<< HEAD
  DEPENDS ${logical_target_for_zephyr_elf}
=======
  DEPENDS
    ${logical_target_for_zephyr_elf}
    $<$<TARGET_EXISTS:native_runner_executable>:native_runner_executable>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
  WORKING_DIRECTORY ${APPLICATION_BINARY_DIR}
  USES_TERMINAL
  )
