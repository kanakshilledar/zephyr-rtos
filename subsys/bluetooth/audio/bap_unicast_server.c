/*  Bluetooth Audio Unicast Server */

/*
 * Copyright (c) 2021-2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/sys/check.h>

#include <zephyr/bluetooth/audio/audio.h>
#include <zephyr/bluetooth/audio/bap.h>

#include "bap_iso.h"
#include "pacs_internal.h"
#include "bap_endpoint.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(bt_bap_unicast_server, CONFIG_BT_BAP_UNICAST_SERVER_LOG_LEVEL);

static const struct bt_bap_unicast_server_cb *unicast_server_cb;

int bt_bap_unicast_server_register_cb(const struct bt_bap_unicast_server_cb *cb)
{
	int err;

	CHECKIF(cb == NULL) {
		LOG_DBG("cb is NULL");
		return -EINVAL;
	}

	if (unicast_server_cb != NULL) {
		LOG_DBG("callback structure already registered");
		return -EALREADY;
	}

	err = bt_ascs_init(cb);
	if (err != 0) {
		return err;
	}

	unicast_server_cb = cb;

	return 0;
}

int bt_bap_unicast_server_unregister_cb(const struct bt_bap_unicast_server_cb *cb)
{
	CHECKIF(cb == NULL) {
		LOG_DBG("cb is NULL");
		return -EINVAL;
	}

	if (unicast_server_cb != cb) {
		LOG_DBG("callback structure not registered");
		return -EINVAL;
	}

	bt_ascs_cleanup();
	unicast_server_cb = NULL;

	return 0;
}

<<<<<<< HEAD
int bt_bap_unicast_server_reconfig(struct bt_bap_stream *stream, const struct bt_codec *codec)
=======
int bt_bap_unicast_server_reconfig(struct bt_bap_stream *stream,
				   const struct bt_audio_codec_cfg *codec_cfg)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	struct bt_bap_ep *ep;
	struct bt_bap_ascs_rsp rsp = BT_BAP_ASCS_RSP(BT_BAP_ASCS_RSP_CODE_SUCCESS,
						     BT_BAP_ASCS_REASON_NONE);
	int err;

	ep = stream->ep;

	if (unicast_server_cb != NULL &&
		unicast_server_cb->reconfig != NULL) {
<<<<<<< HEAD
		err = unicast_server_cb->reconfig(stream, ep->dir, codec,
						  &ep->qos_pref, &rsp);
=======
		err = unicast_server_cb->reconfig(stream, ep->dir, codec_cfg, &ep->qos_pref, &rsp);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	} else {
		err = -ENOTSUP;
	}

	if (err != 0) {
		return err;
	}

<<<<<<< HEAD
	(void)memcpy(&ep->codec, &codec, sizeof(codec));

	ascs_ep_set_state(ep, BT_BAP_EP_STATE_CODEC_CONFIGURED);

	return 0;
=======
	(void)memcpy(&ep->codec_cfg, codec_cfg, sizeof(*codec_cfg));

	return ascs_ep_set_state(ep, BT_BAP_EP_STATE_CODEC_CONFIGURED);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

int bt_bap_unicast_server_start(struct bt_bap_stream *stream)
{
	struct bt_bap_ep *ep = stream->ep;

	if (ep->dir != BT_AUDIO_DIR_SINK) {
		LOG_DBG("Invalid operation for stream %p with dir %u",
			stream, ep->dir);

		return -EINVAL;
	}

	/* If ISO is connected to go streaming state,
	 * else wait for ISO to be connected
	 */
	if (ep->iso->chan.state == BT_ISO_STATE_CONNECTED) {
<<<<<<< HEAD
		ascs_ep_set_state(ep, BT_BAP_EP_STATE_STREAMING);
	} else {
		ep->receiver_ready = true;
	}

	return 0;
}

int bt_bap_unicast_server_metadata(struct bt_bap_stream *stream, struct bt_codec_data meta[],
				   size_t meta_count)
=======
		return ascs_ep_set_state(ep, BT_BAP_EP_STATE_STREAMING);
	}

	ep->receiver_ready = true;

	return 0;
}

int bt_bap_unicast_server_metadata(struct bt_bap_stream *stream, const uint8_t meta[],
				   size_t meta_len)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	struct bt_bap_ep *ep;
	struct bt_bap_ascs_rsp rsp = BT_BAP_ASCS_RSP(BT_BAP_ASCS_RSP_CODE_SUCCESS,
						     BT_BAP_ASCS_REASON_NONE);
	int err;

<<<<<<< HEAD

	if (unicast_server_cb != NULL && unicast_server_cb->metadata != NULL) {
		err = unicast_server_cb->metadata(stream, meta, meta_count, &rsp);
=======
	if (meta_len > sizeof(ep->codec_cfg.meta)) {
		return -ENOMEM;
	}

	if (unicast_server_cb != NULL && unicast_server_cb->metadata != NULL) {
		err = unicast_server_cb->metadata(stream, meta, meta_len, &rsp);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	} else {
		err = -ENOTSUP;
	}

<<<<<<< HEAD
	ep = stream->ep;
	for (size_t i = 0U; i < meta_count; i++) {
		(void)memcpy(&ep->codec.meta[i], &meta[i],
			     sizeof(ep->codec.meta[i]));
	}
=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (err) {
		LOG_ERR("Metadata failed: err %d, code %u, reason %u", err, rsp.code, rsp.reason);
		return err;
	}

<<<<<<< HEAD
	/* Set the state to the same state to trigger the notifications */
	ascs_ep_set_state(ep, ep->status.state);

	return 0;
=======
	ep = stream->ep;
	(void)memcpy(ep->codec_cfg.meta, meta, meta_len);

	/* Set the state to the same state to trigger the notifications */
	return ascs_ep_set_state(ep, ep->status.state);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

int bt_bap_unicast_server_disable(struct bt_bap_stream *stream)
{
<<<<<<< HEAD
	struct bt_bap_ep *ep;
	struct bt_bap_ascs_rsp rsp = BT_BAP_ASCS_RSP(BT_BAP_ASCS_RSP_CODE_SUCCESS,
						     BT_BAP_ASCS_REASON_NONE);
	int err;

	if (unicast_server_cb != NULL && unicast_server_cb->disable != NULL) {
		err = unicast_server_cb->disable(stream, &rsp);
	} else {
		err = -ENOTSUP;
	}

	if (err != 0) {
		LOG_ERR("Disable failed: err %d, code %u, reason %u", err, rsp.code, rsp.reason);
		return err;
	}

	ep = stream->ep;

	/* The ASE state machine goes into different states from this operation
	 * based on whether it is a source or a sink ASE.
	 */
	if (ep->dir == BT_AUDIO_DIR_SOURCE) {
		ascs_ep_set_state(ep, BT_BAP_EP_STATE_DISABLING);
	} else {
		ascs_ep_set_state(ep, BT_BAP_EP_STATE_QOS_CONFIGURED);
	}

	return 0;
=======
	return bt_ascs_disable_ase(stream->ep);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

int bt_bap_unicast_server_release(struct bt_bap_stream *stream)
{
<<<<<<< HEAD
	struct bt_bap_ascs_rsp rsp = BT_BAP_ASCS_RSP(BT_BAP_ASCS_RSP_CODE_SUCCESS,
						     BT_BAP_ASCS_REASON_NONE);
	int err;

	if (unicast_server_cb != NULL && unicast_server_cb->release != NULL) {
		err = unicast_server_cb->release(stream, &rsp);
	} else {
		err = -ENOTSUP;
	}

	if (err != 0) {
		LOG_ERR("Release failed: err %d, code %u, reason %u", err, rsp.code, rsp.reason);
		return err;
	}

	/* ase_process will set the state to IDLE after sending the
	 * notification, finalizing the release
	 */
	ascs_ep_set_state(stream->ep, BT_BAP_EP_STATE_RELEASING);

	return 0;
}

int bt_bap_unicast_server_config_ase(struct bt_conn *conn, struct bt_bap_stream *stream,
				     struct bt_codec *codec,
				     const struct bt_codec_qos_pref *qos_pref)
{
	return bt_ascs_config_ase(conn, stream, codec, qos_pref);
=======
	return bt_ascs_release_ase(stream->ep);
}

int bt_bap_unicast_server_config_ase(struct bt_conn *conn, struct bt_bap_stream *stream,
				     struct bt_audio_codec_cfg *codec_cfg,
				     const struct bt_audio_codec_qos_pref *qos_pref)
{
	return bt_ascs_config_ase(conn, stream, codec_cfg, qos_pref);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

void bt_bap_unicast_server_foreach_ep(struct bt_conn *conn, bt_bap_ep_func_t func, void *user_data)
{
	bt_ascs_foreach_ep(conn, func, user_data);
}
