/*
 * Copyright (c) 2022 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_USBD_DESC_H
#define ZEPHYR_INCLUDE_USBD_DESC_H

#include <zephyr/usb/usbd.h>

/**
 * @brief Get common USB descriptor
 *
<<<<<<< HEAD
 * Get descriptor from internal descrptor list.
=======
 * Get descriptor from internal descriptor list.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @param[in] ctx    Pointer to USB device support context
 * @param[in] type   Descriptor type (bDescriptorType)
 * @param[in] idx    Descriptor index
 *
 * @return pointer to descriptor or NULL if not found.
 */
void *usbd_get_descriptor(struct usbd_contex *uds_ctx,
			  const uint8_t type, const uint8_t idx);

/**
 * @brief Remove all descriptors from an USB device context
 *
 * This removes all loose descriptors like string descriptors.
 * Descriptors like configuration, or interface are not touched
 * by this.
 *
 * @param[in] uds_ctx Pointer to device context
 *
 * @return 0 on success, other values on fail.
 */
int usbd_desc_remove_all(struct usbd_contex *const uds_ctx);

#endif /* ZEPHYR_INCLUDE_USBD_DESC_H */
