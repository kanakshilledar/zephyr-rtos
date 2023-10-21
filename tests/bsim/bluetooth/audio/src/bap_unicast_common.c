/*
 * Copyright (c) 2021-2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "common.h"
#include "bap_unicast_common.h"

void print_hex(const uint8_t *ptr, size_t len)
{
	while (len-- != 0) {
		printk("%02x", *ptr++);
	}
}

<<<<<<< HEAD
void print_codec(const struct bt_codec *codec)
{
	printk("codec 0x%02x cid 0x%04x vid 0x%04x count %u\n",
	       codec->id, codec->cid, codec->vid, codec->data_count);

	for (uint8_t i = 0; i < codec->data_count; i++) {
		printk("data #%u: type 0x%02x len %u\n",
		       i, codec->data[i].data.type,
		       codec->data[i].data.data_len);
		print_hex(codec->data[i].data.data,
			  codec->data[i].data.data_len -
				sizeof(codec->data[i].data.type));
		printk("\n");
	}

	for (uint8_t i = 0; i < codec->meta_count; i++) {
		printk("meta #%u: type 0x%02x len %u\n",
		       i, codec->meta[i].data.type,
		       codec->meta[i].data.data_len);
		print_hex(codec->meta[i].data.data,
			  codec->meta[i].data.data_len -
				sizeof(codec->meta[i].data.type));
		printk("\n");
	}
}

void print_qos(const struct bt_codec_qos *qos)
=======
struct print_ltv_info {
	const char *str;
	size_t cnt;
};

static bool print_ltv_elem(struct bt_data *data, void *user_data)
{
	struct print_ltv_info *ltv_info = user_data;

	printk("%s #%zu: type 0x%02x value_len %u", ltv_info->str, ltv_info->cnt, data->type,
	       data->data_len);
	print_hex(data->data, data->data_len);
	printk("\n");

	ltv_info->cnt++;

	return true;
}

static void print_ltv_array(const char *str, const uint8_t *ltv_data, size_t ltv_data_len)
{
	struct print_ltv_info ltv_info = {
		.str = str,
		.cnt = 0U,
	};

	bt_audio_data_parse(ltv_data, ltv_data_len, print_ltv_elem, &ltv_info);
}

void print_codec_cap(const struct bt_audio_codec_cap *codec_cap)
{
	printk("codec_cap ID 0x%02x cid 0x%04x vid 0x%04x count %u\n", codec_cap->id,
	       codec_cap->cid, codec_cap->vid, codec_cap->data_len);

	if (codec_cap->id == BT_HCI_CODING_FORMAT_LC3) {
		print_ltv_array("data", codec_cap->data, codec_cap->data_len);
	} else { /* If not LC3, we cannot assume it's LTV */
		printk("data: ");
		print_hex(codec_cap->data, codec_cap->data_len);
		printk("\n");
	}

	print_ltv_array("meta", codec_cap->meta, codec_cap->meta_len);
}

void print_codec_cfg(const struct bt_audio_codec_cfg *codec_cfg)
{
	printk("codec_cfg ID 0x%02x cid 0x%04x vid 0x%04x count %u\n", codec_cfg->id,
	       codec_cfg->cid, codec_cfg->vid, codec_cfg->data_len);

	if (codec_cfg->id == BT_HCI_CODING_FORMAT_LC3) {
		print_ltv_array("data", codec_cfg->data, codec_cfg->data_len);
	} else { /* If not LC3, we cannot assume it's LTV */
		printk("data: ");
		print_hex(codec_cfg->data, codec_cfg->data_len);
		printk("\n");
	}

	print_ltv_array("meta", codec_cfg->meta, codec_cfg->meta_len);
}

void print_qos(const struct bt_audio_codec_qos *qos)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	printk("QoS: interval %u framing 0x%02x phy 0x%02x sdu %u "
	       "rtn %u latency %u pd %u\n",
	       qos->interval, qos->framing, qos->phy, qos->sdu,
	       qos->rtn, qos->latency, qos->pd);
}
