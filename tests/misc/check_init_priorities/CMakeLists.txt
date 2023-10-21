# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

set(output_file ${PROJECT_BINARY_DIR}/check_init_priorities_output.txt)

<<<<<<< HEAD
add_custom_target(
	check_init_priorities_output
	COMMENT "Running check_init_priorities.py"
	COMMAND ${PYTHON_EXECUTABLE} ${ZEPHYR_BASE}/scripts/build/check_init_priorities.py
	  --verbose
	  --build-dir ${PROJECT_BINARY_DIR}/..
=======
add_custom_command(
	COMMENT "Running check_init_priorities.py"
	OUTPUT ${output_file}
	DEPENDS ${BYPRODUCT_KERNEL_ELF_NAME}
	COMMAND ${PYTHON_EXECUTABLE} ${ZEPHYR_BASE}/scripts/build/check_init_priorities.py
	  --verbose
	  --elf-file=${ZEPHYR_BINARY_DIR}/${KERNEL_ELF_NAME}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	  --output ${output_file}
	  --always-succeed
	COMMAND ${PYTHON_EXECUTABLE} ${APPLICATION_SOURCE_DIR}/validate_check_init_priorities_output.py
	  ${output_file}
<<<<<<< HEAD
	DEPENDS zephyr_pre0
)
add_dependencies(zephyr_pre1 check_init_priorities_output)
=======
)

add_custom_target(check_init_priorities_output ALL DEPENDS ${output_file})
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

project(check_init_priorities)

target_sources(app PRIVATE src/main.c)
