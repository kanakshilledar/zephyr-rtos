# SPDX-License-Identifier: Apache-2.0

set(SUPPORTED_EMU_PLATFORMS qemu)

<<<<<<< HEAD
set(QEMU_CPU_TYPE_${ARCH} sample_controller)

set(QEMU_FLAGS_${ARCH}
	-machine sim -semihosting -nographic -cpu sample_controller
  )
=======
if(CONFIG_BOARD_QEMU_XTENSA)
  set(QEMU_CPU_TYPE_${ARCH} sample_controller)

  set(QEMU_FLAGS_${ARCH}
    -machine sim -semihosting -nographic -cpu sample_controller
  )
elseif(CONFIG_BOARD_QEMU_XTENSA_MMU)
  set(QEMU_CPU_TYPE_${ARCH} dc233c)

  set(QEMU_FLAGS_${ARCH}
    -machine sim -semihosting -nographic -cpu dc233c
  )
endif()
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

# TODO: Support debug
# board_set_debugger_ifnset(qemu)
# debugserver: QEMU_EXTRA_FLAGS += -s -S
# debugserver: qemu
