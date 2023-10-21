/*
 * Copyright (c) 2020 Jefferson Lee.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/init.h>
#include <zephyr/drivers/gpio.h>

static int board_init(void)
{

	int res;
	static const struct gpio_dt_spec pull_up =
		GPIO_DT_SPEC_GET(DT_PATH(zephyr_user), pull_up_gpios);
	static const struct gpio_dt_spec user_led =
		GPIO_DT_SPEC_GET(DT_ALIAS(led4), gpios);

<<<<<<< HEAD
	if (!device_is_ready(pull_up.port)) {
		return -ENODEV;
	}

	if (!device_is_ready(user_led.port)) {
=======
	if (!gpio_is_ready_dt(&pull_up)) {
		return -ENODEV;
	}

	if (!gpio_is_ready_dt(&user_led)) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		return -ENODEV;
	}

	res = gpio_pin_configure_dt(&pull_up, GPIO_OUTPUT_HIGH);
	if (res) {
		return res;
	}

	return gpio_pin_configure_dt(&user_led, GPIO_OUTPUT_INACTIVE);
}

SYS_INIT(board_init, POST_KERNEL, CONFIG_KERNEL_INIT_PRIORITY_DEVICE);
