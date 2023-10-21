/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/fff.h>
<<<<<<< HEAD

/* List of fakes used by this unit tester */
#define SETTINGS_STORE_FFF_FAKES_LIST(FAKE)     \
		FAKE(settings_delete)					\
		FAKE(settings_save_one)					\

DECLARE_FAKE_VALUE_FUNC(int, settings_delete, const char *);
DECLARE_FAKE_VALUE_FUNC(int, settings_save_one, const char *, const void *, size_t);
=======
#include <zephyr/bluetooth/addr.h>

/* List of fakes used by this unit tester */
#define SETTINGS_STORE_FFF_FAKES_LIST(FAKE)                                                        \
	FAKE(bt_settings_store_keys)                                                               \
	FAKE(bt_settings_delete_keys)

DECLARE_FAKE_VALUE_FUNC(int, bt_settings_store_keys, uint8_t, struct bt_addr_le_t *, const void *,
			size_t);
DECLARE_FAKE_VALUE_FUNC(int, bt_settings_delete_keys, uint8_t, struct bt_addr_le_t *);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
