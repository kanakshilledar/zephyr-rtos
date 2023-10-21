/*
 * Copyright (c) 2019 Oticon A/S
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/util.h>

uint8_t u8_to_dec(char *buf, uint8_t buflen, uint8_t value)
{
	uint8_t divisor = 100;
	uint8_t num_digits = 0;
	uint8_t digit;

<<<<<<< HEAD
	while (buflen > 0 && divisor > 0) {
		digit = value / divisor;
		if (digit != 0 || divisor == 1 || num_digits != 0) {
			*buf = (char)digit + '0';
=======
	while ((buflen > 0) && (divisor > 0)) {
		digit = value / divisor;
		if ((digit != 0) || (divisor == 1) || (num_digits != 0)) {
			*buf = digit + (char)'0';
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			buf++;
			buflen--;
			num_digits++;
		}

		value -= digit * divisor;
		divisor /= 10;
	}

<<<<<<< HEAD
	if (buflen) {
=======
	if (buflen != 0) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		*buf = '\0';
	}

	return num_digits;
}
