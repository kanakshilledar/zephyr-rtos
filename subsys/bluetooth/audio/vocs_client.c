/*  Bluetooth VOCS - Volume Offset Control Service - Client */

/*
 * Copyright (c) 2021-2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/types.h>

#include <zephyr/device.h>
#include <zephyr/init.h>
#include <zephyr/sys/check.h>

#include <zephyr/bluetooth/bluetooth.h>
#include <zephyr/bluetooth/l2cap.h>
#include <zephyr/bluetooth/conn.h>
#include <zephyr/bluetooth/gatt.h>
#include <zephyr/bluetooth/audio/audio.h>
#include <zephyr/bluetooth/audio/vocs.h>

#include "vocs_internal.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(bt_vocs_client, CONFIG_BT_VOCS_CLIENT_LOG_LEVEL);

<<<<<<< HEAD
static struct bt_vocs vocs_insts[CONFIG_BT_MAX_CONN * CONFIG_BT_VOCS_CLIENT_MAX_INSTANCE_COUNT];

static struct bt_vocs *lookup_vocs_by_handle(struct bt_conn *conn, uint16_t handle)
=======
static struct bt_vocs_client insts[CONFIG_BT_MAX_CONN * CONFIG_BT_VOCS_CLIENT_MAX_INSTANCE_COUNT];

static struct bt_vocs_client *lookup_vocs_by_handle(struct bt_conn *conn, uint16_t handle)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	__ASSERT(handle != 0, "Handle cannot be 0");
	__ASSERT(conn, "Conn cannot be NULL");

<<<<<<< HEAD
	for (int i = 0; i < ARRAY_SIZE(vocs_insts); i++) {
		if (vocs_insts[i].cli.conn == conn &&
		    vocs_insts[i].cli.active &&
		    vocs_insts[i].cli.start_handle <= handle &&
		    vocs_insts[i].cli.end_handle >= handle) {
			return &vocs_insts[i];
=======
	for (int i = 0; i < ARRAY_SIZE(insts); i++) {
		if (insts[i].conn == conn &&
		    insts[i].active &&
		    insts[i].start_handle <= handle &&
		    insts[i].end_handle >= handle) {
			return &insts[i];
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	LOG_DBG("Could not find VOCS instance with handle 0x%04x", handle);
	return NULL;
}

uint8_t vocs_client_notify_handler(struct bt_conn *conn, struct bt_gatt_subscribe_params *params,
				   const void *data, uint16_t length)
{
	uint16_t handle = params->value_handle;
<<<<<<< HEAD
	struct bt_vocs *inst;
=======
	struct bt_vocs_client *inst;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (conn == NULL) {
		return BT_GATT_ITER_CONTINUE;
	}

	inst = lookup_vocs_by_handle(conn, handle);

	if (!inst) {
		LOG_DBG("Instance not found");
		return BT_GATT_ITER_STOP;
	}

	if (!data || !length) {
		return BT_GATT_ITER_CONTINUE;
	}

<<<<<<< HEAD
	if (handle == inst->cli.state_handle) {
		if (length == sizeof(inst->cli.state)) {
			memcpy(&inst->cli.state, data, length);
			LOG_DBG("Inst %p: Offset %d, counter %u", inst, inst->cli.state.offset,
				inst->cli.state.change_counter);
			if (inst->cli.cb && inst->cli.cb->state) {
				inst->cli.cb->state(inst, 0, inst->cli.state.offset);
=======
	if (handle == inst->state_handle) {
		if (length == sizeof(inst->state)) {
			memcpy(&inst->state, data, length);
			LOG_DBG("Inst %p: Offset %d, counter %u", inst, inst->state.offset,
				inst->state.change_counter);
			if (inst->cb && inst->cb->state) {
				inst->cb->state(&inst->vocs, 0, inst->state.offset);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			}
		} else {
			LOG_DBG("Invalid state length %u", length);
		}
<<<<<<< HEAD
	} else if (handle == inst->cli.desc_handle) {
=======
	} else if (handle == inst->desc_handle) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		char desc[MIN(BT_L2CAP_RX_MTU, BT_ATT_MAX_ATTRIBUTE_LEN) + 1];

		/* Truncate if too large */

		if (length > sizeof(desc) - 1) {
			LOG_DBG("Description truncated from %u to %zu octets", length,
				sizeof(desc) - 1);
		}
		length = MIN(sizeof(desc) - 1, length);

		memcpy(desc, data, length);
		desc[length] = '\0';
		LOG_DBG("Inst %p: Output description: %s", inst, desc);
<<<<<<< HEAD
		if (inst->cli.cb && inst->cli.cb->description) {
			inst->cli.cb->description(inst, 0, desc);
		}
	} else if (handle == inst->cli.location_handle) {
		if (length == sizeof(inst->cli.location)) {
			memcpy(&inst->cli.location, data, length);
			LOG_DBG("Inst %p: Location %u", inst, inst->cli.location);
			if (inst->cli.cb && inst->cli.cb->location) {
				inst->cli.cb->location(inst, 0, inst->cli.location);
=======
		if (inst->cb && inst->cb->description) {
			inst->cb->description(&inst->vocs, 0, desc);
		}
	} else if (handle == inst->location_handle) {
		if (length == sizeof(inst->location)) {
			memcpy(&inst->location, data, length);
			LOG_DBG("Inst %p: Location %u", inst, inst->location);
			if (inst->cb && inst->cb->location) {
				inst->cb->location(&inst->vocs, 0, inst->location);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			}
		} else {
			LOG_DBG("Invalid location length %u", length);
		}
	}

	return BT_GATT_ITER_CONTINUE;
}

static uint8_t vocs_client_read_offset_state_cb(struct bt_conn *conn, uint8_t err,
						struct bt_gatt_read_params *params,
						const void *data, uint16_t length)
{
	int cb_err = err;
<<<<<<< HEAD
	struct bt_vocs *inst = lookup_vocs_by_handle(conn, params->single.handle);
=======
	struct bt_vocs_client *inst = lookup_vocs_by_handle(conn, params->single.handle);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	memset(params, 0, sizeof(*params));

	if (!inst) {
		LOG_DBG("Instance not found");
		return BT_GATT_ITER_STOP;
	}

	LOG_DBG("Inst %p: err: 0x%02X", inst, err);
<<<<<<< HEAD
	inst->cli.busy = false;
=======
	inst->busy = false;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (cb_err) {
		LOG_DBG("Offset state read failed: %d", err);
	} else if (data) {
<<<<<<< HEAD
		if (length == sizeof(inst->cli.state)) {
			memcpy(&inst->cli.state, data, length);
			LOG_DBG("Offset %d, counter %u", inst->cli.state.offset,
				inst->cli.state.change_counter);
		} else {
			LOG_DBG("Invalid length %u (expected %zu)", length,
				sizeof(inst->cli.state));
=======
		if (length == sizeof(inst->state)) {
			memcpy(&inst->state, data, length);
			LOG_DBG("Offset %d, counter %u", inst->state.offset,
				inst->state.change_counter);
		} else {
			LOG_DBG("Invalid length %u (expected %zu)", length,
				sizeof(inst->state));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			cb_err = BT_ATT_ERR_INVALID_ATTRIBUTE_LEN;
		}
	} else {
		LOG_DBG("Invalid state");
		cb_err = BT_ATT_ERR_UNLIKELY;
	}

<<<<<<< HEAD
	if (inst->cli.cb && inst->cli.cb->state) {
		inst->cli.cb->state(inst, cb_err,
				    cb_err ? 0 : inst->cli.state.offset);
=======
	if (inst->cb && inst->cb->state) {
		inst->cb->state(&inst->vocs, cb_err, cb_err ? 0 : inst->state.offset);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return BT_GATT_ITER_STOP;
}

static uint8_t vocs_client_read_location_cb(struct bt_conn *conn, uint8_t err,
					    struct bt_gatt_read_params *params,
					    const void *data, uint16_t length)
{
	int cb_err = err;
<<<<<<< HEAD
	struct bt_vocs *inst = lookup_vocs_by_handle(conn, params->single.handle);
=======
	struct bt_vocs_client *inst = lookup_vocs_by_handle(conn, params->single.handle);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	memset(params, 0, sizeof(*params));

	if (!inst) {
		LOG_DBG("Instance not found");
		return BT_GATT_ITER_STOP;
	}

	LOG_DBG("Inst %p: err: 0x%02X", inst, err);
<<<<<<< HEAD
	inst->cli.busy = false;
=======
	inst->busy = false;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (cb_err) {
		LOG_DBG("Offset state read failed: %d", err);
	} else if (data) {
<<<<<<< HEAD
		if (length == sizeof(inst->cli.location)) {
			memcpy(&inst->cli.location, data, length);
			LOG_DBG("Location %u", inst->cli.location);
		} else {
			LOG_DBG("Invalid length %u (expected %zu)", length,
				sizeof(inst->cli.location));
=======
		if (length == sizeof(inst->location)) {
			memcpy(&inst->location, data, length);
			LOG_DBG("Location %u", inst->location);
		} else {
			LOG_DBG("Invalid length %u (expected %zu)", length,
				sizeof(inst->location));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			cb_err = BT_ATT_ERR_INVALID_ATTRIBUTE_LEN;
		}
	} else {
		LOG_DBG("Invalid location");
		cb_err = BT_ATT_ERR_UNLIKELY;
	}

<<<<<<< HEAD
	if (inst->cli.cb && inst->cli.cb->location) {
		inst->cli.cb->location(inst, cb_err,
				       cb_err ? 0 : inst->cli.location);
=======
	if (inst->cb && inst->cb->location) {
		inst->cb->location(&inst->vocs, cb_err, cb_err ? 0 : inst->location);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return BT_GATT_ITER_STOP;
}

static uint8_t internal_read_volume_offset_state_cb(struct bt_conn *conn, uint8_t err,
						    struct bt_gatt_read_params *params,
						    const void *data, uint16_t length)
{
	int cb_err = err;
<<<<<<< HEAD
	struct bt_vocs *inst = lookup_vocs_by_handle(conn, params->single.handle);
=======
	struct bt_vocs_client *inst = lookup_vocs_by_handle(conn, params->single.handle);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	memset(params, 0, sizeof(*params));

	if (!inst) {
		LOG_ERR("Instance not found");
		return BT_GATT_ITER_STOP;
	}

	if (err) {
		LOG_WRN("Volume offset state read failed: %d", err);
		cb_err = BT_ATT_ERR_UNLIKELY;
	} else if (data) {
<<<<<<< HEAD
		if (length == sizeof(inst->cli.state)) {
			int write_err;

			memcpy(&inst->cli.state, data, length);
			LOG_DBG("Offset %d, counter %u", inst->cli.state.offset,
				inst->cli.state.change_counter);

			/* clear busy flag to reuse function */
			inst->cli.busy = false;
			write_err = bt_vocs_client_state_set(inst, inst->cli.cp.offset);
=======
		if (length == sizeof(inst->state)) {
			int write_err;

			memcpy(&inst->state, data, length);
			LOG_DBG("Offset %d, counter %u", inst->state.offset,
				inst->state.change_counter);

			/* clear busy flag to reuse function */
			inst->busy = false;
			write_err = bt_vocs_client_state_set(inst, inst->cp.offset);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			if (write_err) {
				cb_err = BT_ATT_ERR_UNLIKELY;
			}
		} else {
			LOG_DBG("Invalid length %u (expected %zu)", length,
<<<<<<< HEAD
				sizeof(inst->cli.state));
=======
				sizeof(inst->state));
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			cb_err = BT_ATT_ERR_UNLIKELY;
		}
	} else {
		LOG_DBG("Invalid (empty) offset state read");
		cb_err = BT_ATT_ERR_UNLIKELY;
	}

	if (cb_err) {
<<<<<<< HEAD
		inst->cli.busy = false;

		if (inst->cli.cb && inst->cli.cb->set_offset) {
			inst->cli.cb->set_offset(inst, err);
=======
		inst->busy = false;

		if (inst->cb && inst->cb->set_offset) {
			inst->cb->set_offset(&inst->vocs, err);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	return BT_GATT_ITER_STOP;
}

static void vocs_client_write_vocs_cp_cb(struct bt_conn *conn, uint8_t err,
					 struct bt_gatt_write_params *params)
{
	int cb_err = err;
<<<<<<< HEAD
	struct bt_vocs *inst = lookup_vocs_by_handle(conn, params->handle);
=======
	struct bt_vocs_client *inst = lookup_vocs_by_handle(conn, params->handle);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	memset(params, 0, sizeof(*params));

	if (!inst) {
		LOG_DBG("Instance not found");
		return;
	}

	LOG_DBG("Inst %p: err: 0x%02X", inst, err);

	/* If the change counter is out of data when a write was attempted from the application,
	 * we automatically initiate a read to get the newest state and try again. Once the
	 * change counter has been read, we restart the applications write request. If it fails
	 * the second time, we return an error to the application.
	 */
<<<<<<< HEAD
	if (cb_err == BT_VOCS_ERR_INVALID_COUNTER && inst->cli.cp_retried) {
		cb_err = BT_ATT_ERR_UNLIKELY;
	} else if (cb_err == BT_VOCS_ERR_INVALID_COUNTER && inst->cli.state_handle) {
		LOG_DBG("Invalid change counter. Reading volume offset state from server.");

		inst->cli.read_params.func = internal_read_volume_offset_state_cb;
		inst->cli.read_params.handle_count = 1;
		inst->cli.read_params.single.handle = inst->cli.state_handle;

		cb_err = bt_gatt_read(conn, &inst->cli.read_params);
		if (cb_err) {
			LOG_WRN("Could not read Volume offset state: %d", cb_err);
		} else {
			inst->cli.cp_retried = true;
=======
	if (cb_err == BT_VOCS_ERR_INVALID_COUNTER && inst->cp_retried) {
		cb_err = BT_ATT_ERR_UNLIKELY;
	} else if (cb_err == BT_VOCS_ERR_INVALID_COUNTER && inst->state_handle) {
		LOG_DBG("Invalid change counter. Reading volume offset state from server.");

		inst->read_params.func = internal_read_volume_offset_state_cb;
		inst->read_params.handle_count = 1;
		inst->read_params.single.handle = inst->state_handle;

		cb_err = bt_gatt_read(conn, &inst->read_params);
		if (cb_err) {
			LOG_WRN("Could not read Volume offset state: %d", cb_err);
		} else {
			inst->cp_retried = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			/* Wait for read callback */
			return;
		}
	}

<<<<<<< HEAD
	inst->cli.busy = false;
	inst->cli.cp_retried = false;

	if (inst->cli.cb && inst->cli.cb->set_offset) {
		inst->cli.cb->set_offset(inst, cb_err);
=======
	inst->busy = false;
	inst->cp_retried = false;

	if (inst->cb && inst->cb->set_offset) {
		inst->cb->set_offset(&inst->vocs, cb_err);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
}

static uint8_t vocs_client_read_output_desc_cb(struct bt_conn *conn, uint8_t err,
					       struct bt_gatt_read_params *params,
					       const void *data, uint16_t length)
{
	int cb_err = err;
<<<<<<< HEAD
	struct bt_vocs *inst = lookup_vocs_by_handle(conn, params->single.handle);
=======
	struct bt_vocs_client *inst = lookup_vocs_by_handle(conn, params->single.handle);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	char desc[MIN(BT_L2CAP_RX_MTU, BT_ATT_MAX_ATTRIBUTE_LEN) + 1];

	memset(params, 0, sizeof(*params));

	if (!inst) {
		LOG_DBG("Instance not found");
		return BT_GATT_ITER_STOP;
	}

	LOG_DBG("Inst %p: err: 0x%02X", inst, err);
<<<<<<< HEAD
	inst->cli.busy = false;
=======
	inst->busy = false;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (cb_err) {
		LOG_DBG("Description read failed: %d", err);
	} else {
		if (data) {
			LOG_HEXDUMP_DBG(data, length, "Output description read");

			if (length > sizeof(desc) - 1) {
				LOG_DBG("Description truncated from %u to %zu octets", length,
					sizeof(desc) - 1);
			}
			length = MIN(sizeof(desc) - 1, length);

			/* TODO: Handle long reads */
			memcpy(desc, data, length);
		}
		desc[length] = '\0';
		LOG_DBG("Output description: %s", desc);
	}

<<<<<<< HEAD
	if (inst->cli.cb && inst->cli.cb->description) {
		inst->cli.cb->description(inst, cb_err, cb_err ? NULL : desc);
=======
	if (inst->cb && inst->cb->description) {
		inst->cb->description(&inst->vocs, cb_err, cb_err ? NULL : desc);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return BT_GATT_ITER_STOP;
}

<<<<<<< HEAD
static bool valid_inst_discovered(struct bt_vocs *inst)
{
	return inst->cli.state_handle &&
		inst->cli.control_handle &&
		inst->cli.location_handle &&
		inst->cli.desc_handle;
=======
static bool valid_inst_discovered(struct bt_vocs_client *inst)
{
	return inst->state_handle &&
		inst->control_handle &&
		inst->location_handle &&
		inst->desc_handle;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

static uint8_t vocs_discover_func(struct bt_conn *conn, const struct bt_gatt_attr *attr,
				  struct bt_gatt_discover_params *params)
{
<<<<<<< HEAD
	struct bt_vocs_client *client_inst = CONTAINER_OF(params,
							  struct bt_vocs_client,
							  discover_params);
	struct bt_vocs *inst = CONTAINER_OF(client_inst, struct bt_vocs, cli);

	if (!attr) {
		LOG_DBG("Discovery complete for VOCS %p", inst);
		inst->cli.busy = false;
		(void)memset(params, 0, sizeof(*params));

		if (inst->cli.cb && inst->cli.cb->discover) {
			int err = valid_inst_discovered(inst) ? 0 : -ENOENT;

			inst->cli.cb->discover(inst, err);
=======
	struct bt_vocs_client *inst = CONTAINER_OF(params, struct bt_vocs_client, discover_params);

	if (!attr) {
		LOG_DBG("Discovery complete for VOCS %p", inst);
		inst->busy = false;
		(void)memset(params, 0, sizeof(*params));

		if (inst->cb && inst->cb->discover) {
			int err = valid_inst_discovered(inst) ? 0 : -ENOENT;

			inst->cb->discover(&inst->vocs, err);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}

		return BT_GATT_ITER_STOP;
	}

	LOG_DBG("[ATTRIBUTE] handle 0x%04X", attr->handle);

	if (params->type == BT_GATT_DISCOVER_CHARACTERISTIC) {
		struct bt_gatt_subscribe_params *sub_params = NULL;
		struct bt_gatt_chrc *chrc;

		chrc = (struct bt_gatt_chrc *)attr->user_data;
<<<<<<< HEAD
		if (inst->cli.start_handle == 0) {
			inst->cli.start_handle = chrc->value_handle;
		}
		inst->cli.end_handle = chrc->value_handle;

		if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_STATE)) {
			LOG_DBG("Volume offset state");
			inst->cli.state_handle = chrc->value_handle;
			sub_params = &inst->cli.state_sub_params;
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_LOCATION)) {
			LOG_DBG("Location");
			inst->cli.location_handle = chrc->value_handle;
			if (chrc->properties & BT_GATT_CHRC_NOTIFY) {
				sub_params = &inst->cli.location_sub_params;
			}
			if (chrc->properties & BT_GATT_CHRC_WRITE_WITHOUT_RESP) {
				inst->cli.location_writable = true;
			}
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_CONTROL)) {
			LOG_DBG("Control point");
			inst->cli.control_handle = chrc->value_handle;
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_DESCRIPTION)) {
			LOG_DBG("Description");
			inst->cli.desc_handle = chrc->value_handle;
			if (chrc->properties & BT_GATT_CHRC_NOTIFY) {
				sub_params = &inst->cli.desc_sub_params;
			}
			if (chrc->properties & BT_GATT_CHRC_WRITE_WITHOUT_RESP) {
				inst->cli.desc_writable = true;
=======
		if (inst->start_handle == 0) {
			inst->start_handle = chrc->value_handle;
		}
		inst->end_handle = chrc->value_handle;

		if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_STATE)) {
			LOG_DBG("Volume offset state");
			inst->state_handle = chrc->value_handle;
			sub_params = &inst->state_sub_params;
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_LOCATION)) {
			LOG_DBG("Location");
			inst->location_handle = chrc->value_handle;
			if (chrc->properties & BT_GATT_CHRC_NOTIFY) {
				sub_params = &inst->location_sub_params;
			}
			if (chrc->properties & BT_GATT_CHRC_WRITE_WITHOUT_RESP) {
				inst->location_writable = true;
			}
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_CONTROL)) {
			LOG_DBG("Control point");
			inst->control_handle = chrc->value_handle;
		} else if (!bt_uuid_cmp(chrc->uuid, BT_UUID_VOCS_DESCRIPTION)) {
			LOG_DBG("Description");
			inst->desc_handle = chrc->value_handle;
			if (chrc->properties & BT_GATT_CHRC_NOTIFY) {
				sub_params = &inst->desc_sub_params;
			}
			if (chrc->properties & BT_GATT_CHRC_WRITE_WITHOUT_RESP) {
				inst->desc_writable = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			}
		}

		if (sub_params) {
			int err;

			sub_params->value = BT_GATT_CCC_NOTIFY;
			sub_params->value_handle = chrc->value_handle;
			/*
			 * TODO: Don't assume that CCC is at handle + 2;
			 * do proper discovery;
			 */
			sub_params->ccc_handle = attr->handle + 2;
			sub_params->notify = vocs_client_notify_handler;
			err = bt_gatt_subscribe(conn, sub_params);
			if (err) {
				LOG_WRN("Could not subscribe to handle %u", sub_params->ccc_handle);
			}
		}
	}

	return BT_GATT_ITER_CONTINUE;
}

<<<<<<< HEAD
int bt_vocs_client_state_get(struct bt_vocs *inst)
=======
int bt_vocs_client_state_get(struct bt_vocs_client *inst)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int err;

	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.state_handle) {
=======
	if (!inst->state_handle) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Handle not set");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (inst->cli.busy) {
=======
	if (inst->busy) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Handle not set");
		return -EBUSY;
	}

<<<<<<< HEAD
	inst->cli.read_params.func = vocs_client_read_offset_state_cb;
	inst->cli.read_params.handle_count = 1;
	inst->cli.read_params.single.handle = inst->cli.state_handle;
	inst->cli.read_params.single.offset = 0U;

	err = bt_gatt_read(inst->cli.conn, &inst->cli.read_params);
	if (!err) {
		inst->cli.busy = true;
=======
	inst->read_params.func = vocs_client_read_offset_state_cb;
	inst->read_params.handle_count = 1;
	inst->read_params.single.handle = inst->state_handle;
	inst->read_params.single.offset = 0U;

	err = bt_gatt_read(inst->conn, &inst->read_params);
	if (!err) {
		inst->busy = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return err;
}

<<<<<<< HEAD
int bt_vocs_client_location_set(struct bt_vocs *inst, uint32_t location)
{

=======
int bt_vocs_client_location_set(struct bt_vocs_client *inst, uint32_t location)
{
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

	CHECKIF(location == BT_AUDIO_LOCATION_PROHIBITED || location > BT_AUDIO_LOCATION_ANY) {
		LOG_DBG("Invalid location 0x%08X", location);
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.location_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->cli.busy) {
		return -EBUSY;
	} else if (!inst->cli.location_writable) {
=======
	if (!inst->location_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->busy) {
		return -EBUSY;
	} else if (!inst->location_writable) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Location is not writable on peer service instance");
		return -EPERM;
	}

<<<<<<< HEAD
	return bt_gatt_write_without_response(inst->cli.conn,
					      inst->cli.location_handle,
=======
	return bt_gatt_write_without_response(inst->conn,
					      inst->location_handle,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
					      &location, sizeof(location),
					      false);
}

<<<<<<< HEAD
int bt_vocs_client_location_get(struct bt_vocs *inst)
=======
int bt_vocs_client_location_get(struct bt_vocs_client *inst)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int err;

	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.location_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->cli.busy) {
		return -EBUSY;
	}

	inst->cli.read_params.func = vocs_client_read_location_cb;
	inst->cli.read_params.handle_count = 1;
	inst->cli.read_params.single.handle = inst->cli.location_handle;
	inst->cli.read_params.single.offset = 0U;

	err = bt_gatt_read(inst->cli.conn, &inst->cli.read_params);
	if (!err) {
		inst->cli.busy = true;
=======
	if (!inst->location_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->busy) {
		return -EBUSY;
	}

	inst->read_params.func = vocs_client_read_location_cb;
	inst->read_params.handle_count = 1;
	inst->read_params.single.handle = inst->location_handle;
	inst->read_params.single.offset = 0U;

	err = bt_gatt_read(inst->conn, &inst->read_params);
	if (!err) {
		inst->busy = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return err;
}

<<<<<<< HEAD
int bt_vocs_client_state_set(struct bt_vocs *inst, int16_t offset)
=======
int bt_vocs_client_state_set(struct bt_vocs_client *inst, int16_t offset)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int err;

	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

	CHECKIF(!IN_RANGE(offset, BT_VOCS_MIN_OFFSET, BT_VOCS_MAX_OFFSET)) {
		LOG_DBG("Invalid offset: %d", offset);
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.control_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->cli.busy) {
		return -EBUSY;
	}

	inst->cli.cp.opcode = BT_VOCS_OPCODE_SET_OFFSET;
	inst->cli.cp.counter = inst->cli.state.change_counter;
	inst->cli.cp.offset = offset;

	inst->cli.write_params.offset = 0;
	inst->cli.write_params.data = &inst->cli.cp;
	inst->cli.write_params.length = sizeof(inst->cli.cp);
	inst->cli.write_params.handle = inst->cli.control_handle;
	inst->cli.write_params.func = vocs_client_write_vocs_cp_cb;

	err = bt_gatt_write(inst->cli.conn, &inst->cli.write_params);
	if (!err) {
		inst->cli.busy = true;
=======
	if (!inst->control_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->busy) {
		return -EBUSY;
	}

	inst->cp.opcode = BT_VOCS_OPCODE_SET_OFFSET;
	inst->cp.counter = inst->state.change_counter;
	inst->cp.offset = offset;

	inst->write_params.offset = 0;
	inst->write_params.data = &inst->cp;
	inst->write_params.length = sizeof(inst->cp);
	inst->write_params.handle = inst->control_handle;
	inst->write_params.func = vocs_client_write_vocs_cp_cb;

	err = bt_gatt_write(inst->conn, &inst->write_params);
	if (!err) {
		inst->busy = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return err;
}

<<<<<<< HEAD
int bt_vocs_client_description_get(struct bt_vocs *inst)
=======
int bt_vocs_client_description_get(struct bt_vocs_client *inst)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int err;

	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.desc_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->cli.busy) {
		return -EBUSY;
	}

	inst->cli.read_params.func = vocs_client_read_output_desc_cb;
	inst->cli.read_params.handle_count = 1;
	inst->cli.read_params.single.handle = inst->cli.desc_handle;
	inst->cli.read_params.single.offset = 0U;

	err = bt_gatt_read(inst->cli.conn, &inst->cli.read_params);
	if (!err) {
		inst->cli.busy = true;
=======
	if (!inst->desc_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->busy) {
		return -EBUSY;
	}

	inst->read_params.func = vocs_client_read_output_desc_cb;
	inst->read_params.handle_count = 1;
	inst->read_params.single.handle = inst->desc_handle;
	inst->read_params.single.offset = 0U;

	err = bt_gatt_read(inst->conn, &inst->read_params);
	if (!err) {
		inst->busy = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return err;
}

<<<<<<< HEAD
int bt_vocs_client_description_set(struct bt_vocs *inst,
=======
int bt_vocs_client_description_set(struct bt_vocs_client *inst,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
				   const char *description)
{
	CHECKIF(!inst) {
		LOG_DBG("NULL instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(inst->cli.conn == NULL) {
=======
	CHECKIF(inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("NULL conn");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!inst->cli.desc_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->cli.busy) {
		return -EBUSY;
	} else if (!inst->cli.desc_writable) {
=======
	if (!inst->desc_handle) {
		LOG_DBG("Handle not set");
		return -EINVAL;
	} else if (inst->busy) {
		return -EBUSY;
	} else if (!inst->desc_writable) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Description is not writable on peer service instance");
		return -EPERM;
	}

<<<<<<< HEAD
	return bt_gatt_write_without_response(inst->cli.conn,
					      inst->cli.desc_handle,
=======
	return bt_gatt_write_without_response(inst->conn,
					      inst->desc_handle,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
					      description,
					      strlen(description), false);
}

struct bt_vocs *bt_vocs_client_free_instance_get(void)
{
<<<<<<< HEAD
	for (int i = 0; i < ARRAY_SIZE(vocs_insts); i++) {
		if (!vocs_insts[i].cli.active) {
			vocs_insts[i].client_instance = true;
			vocs_insts[i].cli.active = true;
			return &vocs_insts[i];
=======
	for (int i = 0; i < ARRAY_SIZE(insts); i++) {
		if (!insts[i].active) {
			insts[i].vocs.client_instance = true;
			insts[i].active = true;
			return &insts[i].vocs;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	return NULL;
}

int bt_vocs_client_conn_get(const struct bt_vocs *vocs, struct bt_conn **conn)
{
<<<<<<< HEAD
=======
	struct bt_vocs_client *inst;

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	CHECKIF(vocs == NULL) {
		LOG_DBG("NULL vocs pointer");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (!vocs->client_instance) {
=======
	CHECKIF(!vocs->client_instance) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("vocs pointer shall be client instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (vocs->cli.conn == NULL) {
=======
	inst = CONTAINER_OF(vocs, struct bt_vocs_client, vocs);

	if (inst->conn == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("vocs pointer not associated with a connection. "
		       "Do discovery first");
		return -ENOTCONN;
	}

<<<<<<< HEAD
	*conn = vocs->cli.conn;
	return 0;
}

static void vocs_client_reset(struct bt_vocs *inst)
{
	memset(&inst->cli.state, 0, sizeof(inst->cli.state));
	inst->cli.location_writable = 0;
	inst->cli.location = 0;
	inst->cli.desc_writable = 0;
	inst->cli.start_handle = 0;
	inst->cli.end_handle = 0;
	inst->cli.state_handle = 0;
	inst->cli.location_handle = 0;
	inst->cli.control_handle = 0;
	inst->cli.desc_handle = 0;

	if (inst->cli.conn != NULL) {
		struct bt_conn *conn = inst->cli.conn;
=======
	*conn = inst->conn;
	return 0;
}

static void vocs_client_reset(struct bt_vocs_client *inst)
{
	memset(&inst->state, 0, sizeof(inst->state));
	inst->location_writable = 0;
	inst->location = 0;
	inst->desc_writable = 0;
	inst->start_handle = 0;
	inst->end_handle = 0;
	inst->state_handle = 0;
	inst->location_handle = 0;
	inst->control_handle = 0;
	inst->desc_handle = 0;

	if (inst->conn != NULL) {
		struct bt_conn *conn = inst->conn;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

		/* It's okay if these fail. In case of disconnect, we can't
		 * unsubscribe and they will just fail.
		 * In case that we reset due to another call of the discover
		 * function, we will unsubscribe (regardless of bonding state)
		 * to accommodate the new discovery values.
		 */
<<<<<<< HEAD
		(void)bt_gatt_unsubscribe(conn, &inst->cli.state_sub_params);
		(void)bt_gatt_unsubscribe(conn, &inst->cli.location_sub_params);
		(void)bt_gatt_unsubscribe(conn, &inst->cli.desc_sub_params);

		bt_conn_unref(conn);
		inst->cli.conn = NULL;
	}
}

int bt_vocs_discover(struct bt_conn *conn, struct bt_vocs *inst,
		     const struct bt_vocs_discover_param *param)
{
	int err = 0;

	CHECKIF(!inst || !conn || !param) {
		LOG_DBG("%s cannot be NULL", inst == NULL   ? "inst"
=======
		(void)bt_gatt_unsubscribe(conn, &inst->state_sub_params);
		(void)bt_gatt_unsubscribe(conn, &inst->location_sub_params);
		(void)bt_gatt_unsubscribe(conn, &inst->desc_sub_params);

		bt_conn_unref(conn);
		inst->conn = NULL;
	}
}

int bt_vocs_discover(struct bt_conn *conn, struct bt_vocs *vocs,
		     const struct bt_vocs_discover_param *param)
{
	struct bt_vocs_client *inst;
	int err = 0;

	CHECKIF(!vocs || !conn || !param) {
		LOG_DBG("%s cannot be NULL", vocs == NULL   ? "vocs"
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
					     : conn == NULL ? "conn"
							    : "param");
		return -EINVAL;
	}

<<<<<<< HEAD
=======
	CHECKIF(!vocs->client_instance) {
		LOG_DBG("vocs pointer shall be client instance");
		return -EINVAL;
	}

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	CHECKIF(param->end_handle < param->start_handle) {
		LOG_DBG("start_handle (%u) shall be less than end_handle (%u)", param->start_handle,
			param->end_handle);
		return -EINVAL;
	}

<<<<<<< HEAD
	CHECKIF(!inst->cli.active) {
=======
	inst = CONTAINER_OF(vocs, struct bt_vocs_client, vocs);

	CHECKIF(!inst->active) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Inactive instance");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (inst->cli.busy) {
=======
	if (inst->busy) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("Instance is busy");
		return -EBUSY;
	}

	vocs_client_reset(inst);

<<<<<<< HEAD
	inst->cli.conn = bt_conn_ref(conn);
	inst->cli.discover_params.start_handle = param->start_handle;
	inst->cli.discover_params.end_handle = param->end_handle;
	inst->cli.discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;
	inst->cli.discover_params.func = vocs_discover_func;

	err = bt_gatt_discover(conn, &inst->cli.discover_params);
	if (err) {
		LOG_DBG("Discover failed (err %d)", err);
	} else {
		inst->cli.busy = true;
=======
	inst->conn = bt_conn_ref(conn);
	inst->discover_params.start_handle = param->start_handle;
	inst->discover_params.end_handle = param->end_handle;
	inst->discover_params.type = BT_GATT_DISCOVER_CHARACTERISTIC;
	inst->discover_params.func = vocs_discover_func;

	err = bt_gatt_discover(conn, &inst->discover_params);
	if (err) {
		LOG_DBG("Discover failed (err %d)", err);
	} else {
		inst->busy = true;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	return err;
}

<<<<<<< HEAD
void bt_vocs_client_cb_register(struct bt_vocs *inst, struct bt_vocs_cb *cb)
{
	CHECKIF(!inst) {
=======
void bt_vocs_client_cb_register(struct bt_vocs *vocs, struct bt_vocs_cb *cb)
{
	struct bt_vocs_client *inst;

	CHECKIF(!vocs) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		LOG_DBG("inst cannot be NULL");
		return;
	}

<<<<<<< HEAD
	inst->cli.cb = cb;
=======
	CHECKIF(!vocs->client_instance) {
		LOG_DBG("vocs pointer shall be client instance");
		return;
	}

	inst = CONTAINER_OF(vocs, struct bt_vocs_client, vocs);

	inst->cb = cb;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
