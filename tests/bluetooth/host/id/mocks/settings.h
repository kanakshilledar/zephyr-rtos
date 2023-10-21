/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/fff.h>
#include <zephyr/kernel.h>

/* List of fakes used by this unit tester */
<<<<<<< HEAD
#define SETTINGS_FFF_FAKES_LIST(FAKE) FAKE(bt_settings_save_id)

DECLARE_FAKE_VOID_FUNC(bt_settings_save_id);
=======
#define SETTINGS_FFF_FAKES_LIST(FAKE)                                                              \
	FAKE(bt_settings_store_id)                                                                 \
	FAKE(bt_settings_delete_id)                                                                \
	FAKE(bt_settings_store_irk)                                                                \
	FAKE(bt_settings_delete_irk)

DECLARE_FAKE_VOID_FUNC(bt_settings_store_id);
DECLARE_FAKE_VOID_FUNC(bt_settings_delete_id);
DECLARE_FAKE_VOID_FUNC(bt_settings_store_irk);
DECLARE_FAKE_VOID_FUNC(bt_settings_delete_irk);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
