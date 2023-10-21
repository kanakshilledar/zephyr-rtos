/*  Bluetooth Audio Unicast Server */

/*
 * Copyright (c) 2021-2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/audio/audio.h>
#include <zephyr/bluetooth/audio/bap.h>

<<<<<<< HEAD
int bt_bap_unicast_server_reconfig(struct bt_bap_stream *stream, const struct bt_codec *codec);
int bt_bap_unicast_server_start(struct bt_bap_stream *stream);
int bt_bap_unicast_server_metadata(struct bt_bap_stream *stream, struct bt_codec_data meta[],
				   size_t meta_count);
=======
int bt_bap_unicast_server_reconfig(struct bt_bap_stream *stream,
				   const struct bt_audio_codec_cfg *codec_cfg);
int bt_bap_unicast_server_start(struct bt_bap_stream *stream);
int bt_bap_unicast_server_metadata(struct bt_bap_stream *stream, const uint8_t meta[],
				   size_t meta_len);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
int bt_bap_unicast_server_disable(struct bt_bap_stream *stream);
int bt_bap_unicast_server_release(struct bt_bap_stream *stream);
