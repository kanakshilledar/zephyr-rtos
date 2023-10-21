/*
 * Copyright (c) 2017 Oticon A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef _POSIX_CORE_BOARD_PROVIDED_IF_H
#define _POSIX_CORE_BOARD_PROVIDED_IF_H

<<<<<<< HEAD
#include "zephyr/types.h"
=======
#include <zephyr/types.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

/*
 * This file lists the functions the posix "inf_clock" soc
 * expect the the board to provide
 *
 * All functions listed here must be provided by the implementation of the board
 *
 * See soc_irq.h for more
 */

#ifdef __cplusplus
extern "C" {
#endif

void posix_irq_handler(void);
void posix_exit(int exit_code);
uint64_t posix_get_hw_cycle(void);
void posix_cpu_hold(uint32_t usec_to_waste);

#ifdef __cplusplus
}
#endif

#endif /* _POSIX_CORE_BOARD_PROVIDED_IF_H */
