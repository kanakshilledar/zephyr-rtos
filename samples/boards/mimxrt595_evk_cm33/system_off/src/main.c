/*
 * Copyright 2022, NXP
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
<<<<<<< HEAD
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/counter.h>
#include <zephyr/pm/pm.h>
#include <zephyr/pm/policy.h>

#define BUSY_WAIT_S 2U
#define SLEEP_S 2U
#define SOFT_OFF_S 10U

#define RTC_NODE DT_NODELABEL(rtc)
#if !DT_NODE_HAS_STATUS(RTC_NODE, okay)
#error "Unsupported board: rtc node is not enabled"
#endif

#define RTC_CHANNEL_ID 0

static const struct device *const rtc_dev = DEVICE_DT_GET(RTC_NODE);
=======

#include <zephyr/drivers/counter.h>
#include <zephyr/sys/poweroff.h>
#include <zephyr/sys_clock.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

int main(void)
{
	int ret;
<<<<<<< HEAD

	printk("\n%s system off demo\n", CONFIG_BOARD);

	uint32_t sleep_ticks = counter_us_to_ticks(rtc_dev, SOFT_OFF_S * 1000ULL * 1000ULL);

	counter_start(rtc_dev);

	if (sleep_ticks == 0) {
		/* counter_us_to_ticks will round down the number of ticks to the nearest int. */
		/* Ensure at least one tick is used in the RTC */
		sleep_ticks++;
	}
	const struct counter_alarm_cfg alarm_cfg = {
		.ticks = sleep_ticks,
		.flags = 0,
	};

	ret = counter_set_channel_alarm(rtc_dev, RTC_CHANNEL_ID, &alarm_cfg);
	if (ret != 0) {
		printk("Could not rtc alarm.\n");
		return 0;
	}
	printk("RTC Alarm set for %llu seconds to wake from soft-off.\n",
	       counter_ticks_to_us(rtc_dev, alarm_cfg.ticks) / (1000ULL * 1000ULL));
	printk("Entering system off");

	pm_state_force(0u, &(struct pm_state_info){ PM_STATE_SOFT_OFF, 0, 0 });

	/* Now we need to go sleep. This will let the idle thread runs and
	 * the pm subsystem will use the forced state.
	 */
	k_sleep(K_SECONDS(SLEEP_S));

	printk("ERROR: System off failed\n");
	while (true) {
		/* spin to avoid fall-off behavior */
	}
=======
	const struct device *dev = DEVICE_DT_GET(DT_NODELABEL(rtc));
	struct counter_alarm_cfg alarm_cfg = { 0 };

	if (!device_is_ready(dev)) {
		printf("Counter device not ready\n");
		return 0;
	}

	ret = counter_start(dev);
	if (ret < 0) {
		printf("Could not start counter (%d)\n", ret);
		return 0;
	}

	alarm_cfg.ticks = counter_us_to_ticks(dev, 10 * USEC_PER_SEC);

	ret = counter_set_channel_alarm(dev, 0, &alarm_cfg);
	if (ret < 0) {
		printf("Could not set counter channel alarm (%d)\n", ret);
		return 0;
	}

	printf("Wake-up alarm set for 10 seconds\n");
	printf("Powering off\n");

	sys_poweroff();

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return 0;
}
