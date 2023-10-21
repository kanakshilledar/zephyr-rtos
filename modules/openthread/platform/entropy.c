/*
 * Copyright (c) 2019 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
<<<<<<< HEAD
#include <string.h>
#include <zephyr/drivers/entropy.h>
=======
#include <zephyr/random/random.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/logging/log.h>

#include <openthread/platform/entropy.h>

<<<<<<< HEAD
#include "platform-zephyr.h"

LOG_MODULE_REGISTER(net_otPlat_entropy, CONFIG_OPENTHREAD_L2_LOG_LEVEL);

#if !defined(CONFIG_ENTROPY_HAS_DRIVER)
#error OpenThread requires an entropy source for a TRNG
#endif

static const struct device *const dev = DEVICE_DT_GET(DT_CHOSEN(zephyr_entropy));

=======
LOG_MODULE_REGISTER(net_otPlat_entropy, CONFIG_OPENTHREAD_L2_LOG_LEVEL);

#if !defined(CONFIG_CSPRNG_ENABLED)
#error OpenThread requires an entropy source for a TRNG
#endif

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
otError otPlatEntropyGet(uint8_t *aOutput, uint16_t aOutputLength)
{
	int err;

	if ((aOutput == NULL) || (aOutputLength == 0)) {
		return OT_ERROR_INVALID_ARGS;
	}

<<<<<<< HEAD
	if (!device_is_ready(dev)) {
		LOG_ERR("Entropy device not ready");
		return OT_ERROR_FAILED;
	}

	err = entropy_get_entropy(dev, aOutput, aOutputLength);
=======
	err = sys_csrand_get(aOutput, aOutputLength);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (err != 0) {
		LOG_ERR("Failed to obtain entropy, err %d", err);
		return OT_ERROR_FAILED;
	}

	return OT_ERROR_NONE;
}
