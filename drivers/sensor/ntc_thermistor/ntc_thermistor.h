/*
 * Copyright (c) 2023 Google LLC
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef NTC_THERMISTOR_H
#define NTC_THERMISTOR_H

#include <zephyr/types.h>

struct ntc_compensation {
	const int32_t temp_c;
	const uint32_t ohm;
};

struct ntc_type {
	const struct ntc_compensation *comp;
	int n_comp;
<<<<<<< HEAD
	int (*ohm_cmp)(const void *key, const void *element);
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
};

struct ntc_config {
	bool connected_positive;
<<<<<<< HEAD
	uint32_t r25_ohm;
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	uint32_t pullup_uv;
	uint32_t pullup_ohm;
	uint32_t pulldown_ohm;
	struct ntc_type type;
};

/**
<<<<<<< HEAD
 * @brief Helper comparison function for bsearch for specific
 * ntc_type
 *
 * Ohms are sorted in descending order, perform comparison to find
 * interval indexes where key falls between
 *
 * @param type: Pointer to ntc_type table info
 * @param key: Key value bsearch is looking for
 * @param element: Array element bsearch is searching
 */
int ntc_compensation_compare_ohm(const struct ntc_type *type, const void *key, const void *element);

/**
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 * @brief Converts ohm to temperature in milli centigrade
 *
 * @param type: Pointer to ntc_type table info
 * @param ohm: Read resistance of NTC thermistor
 *
 * @return temperature in milli centigrade
 */
int32_t ntc_get_temp_mc(const struct ntc_type *type, unsigned int ohm);

/**
 * @brief Calculate the resistance read from NTC Thermistor
 *
 * @param cfg: NTC Thermistor configuration
<<<<<<< HEAD
 * @param max_adc: Max ADC value
 * @param raw_adc: Raw ADC value read
 *
 * @return resistance from raw ADC value
 */
uint32_t ntc_get_ohm_of_thermistor(const struct ntc_config *cfg, uint32_t max_adc, int16_t raw_adc);
=======
 * @sample_mv: Measured voltage in mV
 *
 * @return Thermistor resistance
 */
uint32_t ntc_get_ohm_of_thermistor(const struct ntc_config *cfg, int sample_mv);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif /* NTC_THERMISTOR_H */
