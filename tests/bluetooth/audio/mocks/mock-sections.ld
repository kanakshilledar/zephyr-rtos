/*
 * Copyright 2023 Codecoup
 *
 * SPDX-License-Identifier: Apache-2.0
 */

SECTIONS
{
<<<<<<< HEAD
	bt_conn_cb_area : ALIGN(4)
=======
	data.bt_conn_cb_area : ALIGN(4)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	{
		_bt_conn_cb_list_start = .;
		KEEP(*(SORT_BY_NAME(._bt_conn_cb.static.*)))
		_bt_conn_cb_list_end = .;
	}
<<<<<<< HEAD
	bt_gatt_service_static_area : ALIGN(4)
=======
	data.bt_gatt_service_static_area : ALIGN(4)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	{
		_bt_gatt_service_static_list_start = .;
		KEEP(*(SORT_BY_NAME(._bt_gatt_service_static.static.*)))
		_bt_gatt_service_static_list_end = .;
	}
}
<<<<<<< HEAD
=======
INSERT AFTER .data;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
