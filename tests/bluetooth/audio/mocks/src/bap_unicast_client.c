/*
 * Copyright (c) 2023 Codecoup
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/bluetooth/audio/bap.h>

bool bt_bap_ep_is_unicast_client(const struct bt_bap_ep *ep)
{
	return false;
}

<<<<<<< HEAD
int bt_bap_unicast_client_config(struct bt_bap_stream *stream, const struct bt_codec *codec)
=======
int bt_bap_unicast_client_config(struct bt_bap_stream *stream,
				 const struct bt_audio_codec_cfg *codec_cfg)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

int bt_bap_unicast_client_qos(struct bt_conn *conn, struct bt_bap_unicast_group *group)
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

<<<<<<< HEAD
int bt_bap_unicast_client_enable(struct bt_bap_stream *stream, struct bt_codec_data *meta,
				 size_t meta_count)
=======
int bt_bap_unicast_client_enable(struct bt_bap_stream *stream, uint8_t meta[],
				 size_t meta_len)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

<<<<<<< HEAD
int bt_bap_unicast_client_metadata(struct bt_bap_stream *stream, struct bt_codec_data *meta,
				   size_t meta_count)
=======
int bt_bap_unicast_client_metadata(struct bt_bap_stream *stream, uint8_t meta[],
				   size_t meta_len)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

int bt_bap_unicast_client_disable(struct bt_bap_stream *stream)
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

int bt_bap_unicast_client_start(struct bt_bap_stream *stream)
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

int bt_bap_unicast_client_stop(struct bt_bap_stream *stream)
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}

int bt_bap_unicast_client_release(struct bt_bap_stream *stream)
{
	zassert_unreachable("Unexpected call to '%s()' occurred", __func__);
	return 0;
}
