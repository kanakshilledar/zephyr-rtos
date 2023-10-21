/*
 * Copyright (c) 2022 Microchip Technology Inc. and its subsidiaries.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef _MEC_GPIO_H
#define _MEC_GPIO_H

#include <stdint.h>
#include <stddef.h>

<<<<<<< HEAD
=======
#define MCHP_XEC_PINCTRL_REG_IDX(pin) ((pin >> 5) * 32 + (pin & 0x1f))

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
/** @brief All GPIO register as arrays of registers */
struct gpio_regs {
	volatile uint32_t  CTRL[174];
	uint32_t  RESERVED[18];
	volatile uint32_t  PARIN[6];
	uint32_t  RESERVED1[26];
	volatile uint32_t  PAROUT[6];
	uint32_t  RESERVED2[20];
	volatile uint32_t  LOCK[6];
	uint32_t  RESERVED3[64];
	volatile uint32_t  CTRL2[174];
};

#endif	/* #ifndef _MEC_GPIO_H */
