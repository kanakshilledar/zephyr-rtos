/**
 * @file
 * @brief Internal Header for Bluetooth Volume Control Service (VCS).
 *
 * Copyright (c) 2020 Bose Corporation
 * Copyright (c) 2020-2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_BLUETOOTH_AUDIO_VCP_INTERNAL_
#define ZEPHYR_INCLUDE_BLUETOOTH_AUDIO_VCP_INTERNAL_

/* VCS opcodes */
#define BT_VCP_OPCODE_REL_VOL_DOWN                      0x00
#define BT_VCP_OPCODE_REL_VOL_UP                        0x01
#define BT_VCP_OPCODE_UNMUTE_REL_VOL_DOWN               0x02
#define BT_VCP_OPCODE_UNMUTE_REL_VOL_UP                 0x03
#define BT_VCP_OPCODE_SET_ABS_VOL                       0x04
#define BT_VCP_OPCODE_UNMUTE                            0x05
#define BT_VCP_OPCODE_MUTE                              0x06

struct vcs_state {
	uint8_t volume;
	uint8_t mute;
	uint8_t change_counter;
} __packed;

struct vcs_control {
	uint8_t opcode;
	uint8_t counter;
} __packed;

struct vcs_control_vol {
	struct vcs_control cp;
	uint8_t volume;
} __packed;

<<<<<<< HEAD
=======
struct bt_vcp_vol_ctlr {
	struct vcs_state state;
	uint8_t flags;

	uint16_t start_handle;
	uint16_t end_handle;
	uint16_t state_handle;
	uint16_t control_handle;
	uint16_t flag_handle;
	struct bt_gatt_subscribe_params state_sub_params;
	struct bt_gatt_discover_params state_sub_disc_params;
	struct bt_gatt_subscribe_params flag_sub_params;
	struct bt_gatt_discover_params flag_sub_disc_params;
	bool cp_retried;

	bool busy;
	struct vcs_control_vol cp_val;
	struct bt_gatt_write_params write_params;
	struct bt_gatt_read_params read_params;
	struct bt_gatt_discover_params discover_params;
	struct bt_uuid_16 uuid;
	struct bt_conn *conn;

	uint8_t vocs_inst_cnt;
	struct bt_vocs *vocs[CONFIG_BT_VOCS_CLIENT_MAX_INSTANCE_COUNT];
	uint8_t aics_inst_cnt;
	struct bt_aics *aics[CONFIG_BT_AICS_CLIENT_MAX_INSTANCE_COUNT];
};

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#endif /* ZEPHYR_INCLUDE_BLUETOOTH_AUDIO_VCP_INTERNAL_*/
