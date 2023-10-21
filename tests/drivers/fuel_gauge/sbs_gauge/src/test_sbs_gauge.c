/*
 * Copyright 2022 Google LLC
 * Copyright 2023 Microsoft Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/device.h>
<<<<<<< HEAD
=======
#include <zephyr/drivers/emul.h>
#include <zephyr/drivers/emul_fuel_gauge.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/drivers/fuel_gauge.h>
#include <zephyr/drivers/i2c.h>
#include <zephyr/logging/log.h>
#include <zephyr/sys/byteorder.h>
#include <zephyr/sys/util.h>
#include <zephyr/ztest.h>
#include <zephyr/ztest_assert.h>

<<<<<<< HEAD
struct sbs_gauge_new_api_fixture {
	const struct device *dev;
	const struct fuel_gauge_driver_api *api;
};
=======
#include "test_sbs_gauge.h"
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

static void *sbs_gauge_new_api_setup(void)
{
	static ZTEST_DMEM struct sbs_gauge_new_api_fixture fixture;

	fixture.dev = DEVICE_DT_GET_ANY(sbs_sbs_gauge_new_api);
<<<<<<< HEAD
=======
	fixture.sbs_fuel_gauge = EMUL_DT_GET(DT_NODELABEL(smartbattery0));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	k_object_access_all_grant(fixture.dev);

	zassert_true(device_is_ready(fixture.dev), "Fuel Gauge not found");

	return &fixture;
}

<<<<<<< HEAD
ZTEST_USER_F(sbs_gauge_new_api, test_get_all_props_failed_returns_negative)
{
	struct fuel_gauge_get_property props[] = {
		{
			/* Invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
	};

	int ret = fuel_gauge_get_prop(fixture->dev, props, ARRAY_SIZE(props));

	zassert_equal(props[0].status, -ENOTSUP, "Getting bad property %d has a good status.",
		      props[0].property_type);

	zassert_true(ret < 0);
}

ZTEST_USER_F(sbs_gauge_new_api, test_get_some_props_failed_returns_failed_prop_count)
{
	struct fuel_gauge_get_property props[] = {
		{
			/* First invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
		{
			/* Second invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
		{
			/* Valid property */
			.property_type = FUEL_GAUGE_VOLTAGE,
		},

	};

	int ret = fuel_gauge_get_prop(fixture->dev, props, ARRAY_SIZE(props));

	zassert_equal(props[0].status, -ENOTSUP, "Getting bad property %d has a good status.",
		      props[0].property_type);

	zassert_equal(props[1].status, -ENOTSUP, "Getting bad property %d has a good status.",
		      props[1].property_type);

	zassert_ok(props[2].status, "Property %d getting %d has a bad status.", 2,
		   props[2].property_type);

	zassert_equal(ret, 2);
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_all_props_failed_returns_negative)
{
	struct fuel_gauge_set_property props[] = {
		{
			/* Invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
	};

	int ret = fuel_gauge_set_prop(fixture->dev, props, ARRAY_SIZE(props));

	zassert_equal(props[0].status, -ENOTSUP, "Setting bad property %d has a good status.",
		      props[0].property_type);

	zassert_true(ret < 0);
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_some_props_failed_returns_failed_prop_count)
{
	struct fuel_gauge_set_property props[] = {
		{
			/* First invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
		{
			/* Second invalid property */
			.property_type = FUEL_GAUGE_PROP_MAX,
		},
		{
			/* Valid property */
			.property_type = FUEL_GAUGE_SBS_MFR_ACCESS,
			/* Set Manufacturer's Access to arbitrary word */
			.value.sbs_mfr_access_word = 1,
		},

	};

	int ret = fuel_gauge_set_prop(fixture->dev, props, ARRAY_SIZE(props));

	zassert_equal(props[0].status, -ENOTSUP, "Setting bad property %d has a good status.",
		      props[0].property_type);

	zassert_equal(props[1].status, -ENOTSUP, "Setting bad property %d has a good status.",
		      props[1].property_type);

	zassert_ok(props[2].status, "Property %d setting %d has a bad status.", 2,
		   props[2].property_type);

	zassert_equal(ret, 2);
=======
ZTEST_USER_F(sbs_gauge_new_api, test_get_some_props_failed_returns_bad_status)
{
	fuel_gauge_prop_t prop_types[] = {
		/* First invalid property */
		FUEL_GAUGE_PROP_MAX,
		/* Second invalid property */
		FUEL_GAUGE_PROP_MAX,
		/* Valid property */
		FUEL_GAUGE_VOLTAGE,
	};
	union fuel_gauge_prop_val props[ARRAY_SIZE(prop_types)];

	int ret = fuel_gauge_get_props(fixture->dev, prop_types, props, ARRAY_SIZE(props));

	zassert_equal(ret, -ENOTSUP, "Getting bad property has a good status.");
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_all_props_failed_returns_err)
{
	fuel_gauge_prop_t prop_types[] = {
		/* Invalid property */
		FUEL_GAUGE_PROP_MAX,
	};
	union fuel_gauge_prop_val props[ARRAY_SIZE(prop_types)];

	int ret = fuel_gauge_set_props(fixture->dev, prop_types, props, ARRAY_SIZE(props));

	zassert_equal(ret, -ENOTSUP);
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_some_props_failed_returns_err)
{
	fuel_gauge_prop_t prop_types[] = {
		/* First invalid property */
		FUEL_GAUGE_PROP_MAX,
		/* Second invalid property */
		FUEL_GAUGE_PROP_MAX,
		/* Valid property */
		FUEL_GAUGE_SBS_MFR_ACCESS,
		/* Set Manufacturer's Access to arbitrary word */

	};

	union fuel_gauge_prop_val props[] = {
		/* First invalid property */
		{0},
		/* Second invalid property */
		{0},
		/* Valid property */
		/* Set Manufacturer's Access to arbitrary word */
		{.sbs_mfr_access_word = 1},
	};

	int ret = fuel_gauge_set_props(fixture->dev, prop_types, props, ARRAY_SIZE(props));

	zassert_equal(ret, -ENOTSUP);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_prop_can_be_get)
{
	uint16_t word = BIT(15) | BIT(0);
<<<<<<< HEAD
	struct fuel_gauge_set_property set_props[] = {
		{
			/* Valid property */
			.property_type = FUEL_GAUGE_SBS_MFR_ACCESS,
			/* Set Manufacturer's Access to 16 bit word */
			.value.sbs_mfr_access_word = word,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
			.value.sbs_remaining_capacity_alarm = word,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
			.value.sbs_remaining_time_alarm = word,
		},
		{
			.property_type = FUEL_GAUGE_SBS_MODE,
			.value.sbs_mode = word,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE,
			.value.sbs_at_rate = (int16_t)word,
		},
	};

	struct fuel_gauge_get_property get_props[] = {
		{
			.property_type = FUEL_GAUGE_SBS_MFR_ACCESS,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
		},
		{
			.property_type = FUEL_GAUGE_SBS_MODE,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE,
		},
	};

	zassert_ok(fuel_gauge_set_prop(fixture->dev, set_props, ARRAY_SIZE(set_props)));
	for (int i = 0; i < ARRAY_SIZE(set_props); i++) {
		zassert_ok(set_props[i].status, "Property %d writing %d has a bad status.", i,
			   set_props[i].property_type);
	}

	zassert_ok(fuel_gauge_get_prop(fixture->dev, get_props, ARRAY_SIZE(get_props)));
	for (int i = 0; i < ARRAY_SIZE(get_props); i++) {
		zassert_ok(get_props[i].status, "Property %d getting %d has a bad status.", i,
			   get_props[i].property_type);
	}

	zassert_equal(get_props[0].value.sbs_mfr_access_word, word);
	zassert_equal(get_props[1].value.sbs_remaining_capacity_alarm, word);
	zassert_equal(get_props[2].value.sbs_remaining_time_alarm, word);
	zassert_equal(get_props[3].value.sbs_mode, word);
	zassert_equal(get_props[4].value.sbs_at_rate, (int16_t)word);
=======

	fuel_gauge_prop_t prop_types[] = {
		FUEL_GAUGE_SBS_MFR_ACCESS,
		FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
		FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
		FUEL_GAUGE_SBS_MODE,
		FUEL_GAUGE_SBS_ATRATE,
	};

	union fuel_gauge_prop_val set_props[] = {
		{
			.sbs_mfr_access_word = word,
		},
		{
			.sbs_remaining_capacity_alarm = word,
		},
		{
			.sbs_remaining_time_alarm = word,
		},
		{
			.sbs_mode = word,
		},
		{
			.sbs_at_rate = (int16_t)word,
		},
	};

	union fuel_gauge_prop_val get_props[ARRAY_SIZE(prop_types)];

	zassert_ok(
		fuel_gauge_set_props(fixture->dev, prop_types, set_props, ARRAY_SIZE(set_props)));

	zassert_ok(
		fuel_gauge_get_props(fixture->dev, prop_types, get_props, ARRAY_SIZE(get_props)));

	zassert_equal(get_props[0].sbs_mfr_access_word, word);
	zassert_equal(get_props[1].sbs_remaining_capacity_alarm, word);
	zassert_equal(get_props[2].sbs_remaining_time_alarm, word);
	zassert_equal(get_props[3].sbs_mode, word);
	zassert_equal(get_props[4].sbs_at_rate, (int16_t)word);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

ZTEST_USER_F(sbs_gauge_new_api, test_get_props__returns_ok)
{
	/* Validate what props are supported by the driver */

<<<<<<< HEAD
	struct fuel_gauge_get_property props[] = {
		{
			.property_type = FUEL_GAUGE_VOLTAGE,
		},
		{
			.property_type = FUEL_GAUGE_CURRENT,
		},
		{
			.property_type = FUEL_GAUGE_AVG_CURRENT,
		},
		{
			.property_type = FUEL_GAUGE_TEMPERATURE,
		},
		{
			.property_type = FUEL_GAUGE_ABSOLUTE_STATE_OF_CHARGE,
		},
		{
			.property_type = FUEL_GAUGE_RELATIVE_STATE_OF_CHARGE,
		},
		{
			.property_type = FUEL_GAUGE_RUNTIME_TO_FULL,
		},
		{
			.property_type = FUEL_GAUGE_RUNTIME_TO_EMPTY,
		},
		{
			.property_type = FUEL_GAUGE_REMAINING_CAPACITY,
		},
		{
			.property_type = FUEL_GAUGE_FULL_CHARGE_CAPACITY,
		},
		{
			.property_type = FUEL_GAUGE_CYCLE_COUNT,
		},
		{
			.property_type = FUEL_GAUGE_SBS_MFR_ACCESS,
		},
		{
			.property_type = FUEL_GAUGE_SBS_MODE,
		},
		{
			.property_type = FUEL_GAUGE_CHARGE_CURRENT,
		},
		{
			.property_type = FUEL_GAUGE_CHARGE_VOLTAGE,
		},
		{
			.property_type = FUEL_GAUGE_STATUS,
		},
		{
			.property_type = FUEL_GAUGE_DESIGN_CAPACITY,
		},
		{
			.property_type = FUEL_GAUGE_DESIGN_VOLTAGE,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE_TIME_TO_FULL,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE_TIME_TO_EMPTY,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE_OK,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
		},
	};

	int ret = fuel_gauge_get_prop(fixture->dev, props, ARRAY_SIZE(props));

	for (int i = 0; i < ARRAY_SIZE(props); i++) {
		zassert_ok(props[i].status, "Property %d getting %d has a bad status.", i,
			   props[i].property_type);
	}

	zassert_ok(ret);
=======
	fuel_gauge_prop_t prop_types[] = {
		FUEL_GAUGE_VOLTAGE,
		FUEL_GAUGE_CURRENT,
		FUEL_GAUGE_AVG_CURRENT,
		FUEL_GAUGE_TEMPERATURE,
		FUEL_GAUGE_ABSOLUTE_STATE_OF_CHARGE,
		FUEL_GAUGE_RELATIVE_STATE_OF_CHARGE,
		FUEL_GAUGE_RUNTIME_TO_FULL,
		FUEL_GAUGE_RUNTIME_TO_EMPTY,
		FUEL_GAUGE_REMAINING_CAPACITY,
		FUEL_GAUGE_FULL_CHARGE_CAPACITY,
		FUEL_GAUGE_CYCLE_COUNT,
		FUEL_GAUGE_SBS_MFR_ACCESS,
		FUEL_GAUGE_SBS_MODE,
		FUEL_GAUGE_CHARGE_CURRENT,
		FUEL_GAUGE_CHARGE_VOLTAGE,
		FUEL_GAUGE_STATUS,
		FUEL_GAUGE_DESIGN_CAPACITY,
		FUEL_GAUGE_DESIGN_VOLTAGE,
		FUEL_GAUGE_SBS_ATRATE,
		FUEL_GAUGE_SBS_ATRATE_TIME_TO_FULL,
		FUEL_GAUGE_SBS_ATRATE_TIME_TO_EMPTY,
		FUEL_GAUGE_SBS_ATRATE_OK,
		FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
		FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
	};

	union fuel_gauge_prop_val props[ARRAY_SIZE(prop_types)];

	zassert_ok(fuel_gauge_get_props(fixture->dev, prop_types, props, ARRAY_SIZE(props)));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_props__returns_ok)
{
	/* Validate what props are supported by the driver */

<<<<<<< HEAD
	struct fuel_gauge_set_property props[] = {
		{
			.property_type = FUEL_GAUGE_SBS_MFR_ACCESS,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,
		},
		{
			.property_type = FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
		},
		{
			.property_type = FUEL_GAUGE_SBS_MODE,
		},
		{
			.property_type = FUEL_GAUGE_SBS_ATRATE,
		},
	};

	int ret = fuel_gauge_set_prop(fixture->dev, props, ARRAY_SIZE(props));

	for (int i = 0; i < ARRAY_SIZE(props); i++) {
		zassert_ok(props[i].status, "Property %d writing %d has a bad status.", i,
			   props[i].property_type);
	}

	zassert_ok(ret);
}


ZTEST_USER_F(sbs_gauge_new_api, test_get_buffer_props__returns_ok)
{
	/* Validate what properties are supported by the driver */
	struct fuel_gauge_get_buffer_property prop;
	struct sbs_gauge_manufacturer_name mfg_name;
	struct sbs_gauge_device_name dev_name;
	struct sbs_gauge_device_chemistry chem;
	int ret;

	prop.property_type = FUEL_GAUGE_MANUFACTURER_NAME;
	ret = fuel_gauge_get_buffer_prop(fixture->dev, &prop, &mfg_name, sizeof(mfg_name));
	zassert_ok(prop.status, "Property %d has a bad status.", prop.property_type);
	zassert_ok(ret);

	prop.property_type = FUEL_GAUGE_DEVICE_NAME;
	ret = fuel_gauge_get_buffer_prop(fixture->dev, &prop, &dev_name, sizeof(dev_name));
	zassert_ok(prop.status, "Property %d has a bad status.", prop.property_type);
	zassert_ok(ret);

	prop.property_type = FUEL_GAUGE_DEVICE_CHEMISTRY;
	ret = fuel_gauge_get_buffer_prop(fixture->dev, &prop, &chem, sizeof(chem));
	zassert_ok(prop.status, "Property %d has a bad status.", prop.property_type);
	zassert_ok(ret);
}

=======
	fuel_gauge_prop_t prop_types[] = {
		FUEL_GAUGE_SBS_MFR_ACCESS,
		FUEL_GAUGE_SBS_MODE,
		FUEL_GAUGE_SBS_ATRATE,
		FUEL_GAUGE_SBS_REMAINING_TIME_ALARM,
		FUEL_GAUGE_SBS_REMAINING_CAPACITY_ALARM,

	};
	union fuel_gauge_prop_val props[ARRAY_SIZE(prop_types)];

	zassert_ok(fuel_gauge_set_props(fixture->dev, prop_types, props, ARRAY_SIZE(props)));
}

ZTEST_USER_F(sbs_gauge_new_api, test_get_buffer_props__returns_ok)
{
	/* Validate what properties are supported by the driver */
	struct sbs_gauge_manufacturer_name mfg_name;
	struct sbs_gauge_device_name dev_name;
	struct sbs_gauge_device_chemistry chem;

	zassert_ok(fuel_gauge_get_buffer_prop(fixture->dev, FUEL_GAUGE_MANUFACTURER_NAME, &mfg_name,
					      sizeof(mfg_name)));

	zassert_ok(fuel_gauge_get_buffer_prop(fixture->dev, FUEL_GAUGE_DEVICE_NAME, &dev_name,
					      sizeof(dev_name)));

	zassert_ok(fuel_gauge_get_buffer_prop(fixture->dev, FUEL_GAUGE_DEVICE_CHEMISTRY, &chem,
					      sizeof(chem)));
}

ZTEST_USER_F(sbs_gauge_new_api, test_charging_5v_3a)
{
	/* Validate what props are supported by the driver */
	uint32_t expected_uV = 5000 * 1000;
	uint32_t expected_uA = 3000 * 1000;

	union fuel_gauge_prop_val voltage;
	union fuel_gauge_prop_val current;

	zassume_ok(emul_fuel_gauge_set_battery_charging(fixture->sbs_fuel_gauge, expected_uV,
							expected_uA));
	zassert_ok(fuel_gauge_get_prop(fixture->dev, FUEL_GAUGE_VOLTAGE, &voltage));
	zassert_ok(fuel_gauge_get_prop(fixture->dev, FUEL_GAUGE_CURRENT, &current));

	zassert_equal(voltage.voltage, expected_uV, "Got %d instead of %d", voltage, expected_uV);
	zassert_equal(current.current, expected_uA, "Got %d instead of %d", current, expected_uA);
}

ZTEST_USER_F(sbs_gauge_new_api, test_set_get_single_prop)
{
	/* Validate what props are supported by the driver */

	uint16_t test_value = 0x1001;

	union fuel_gauge_prop_val mfr_acc_set = {
		.sbs_mfr_access_word = test_value,
	};
	union fuel_gauge_prop_val mfr_acc_get;

	zassert_ok(fuel_gauge_set_prop(fixture->dev, FUEL_GAUGE_SBS_MFR_ACCESS, mfr_acc_set));
	zassert_ok(fuel_gauge_get_prop(fixture->dev, FUEL_GAUGE_SBS_MFR_ACCESS, &mfr_acc_get));
	zassert_equal(mfr_acc_get.sbs_mfr_access_word, test_value);
}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

ZTEST_SUITE(sbs_gauge_new_api, NULL, sbs_gauge_new_api_setup, NULL, NULL, NULL);
