/*
 * Copyright (c) 2018 Intel Corporation
<<<<<<< HEAD
=======
 * Copyright (c) 2023 Nordic Semiconductor ASA
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef ZEPHYR_INCLUDE_USB_BOS_H_
#define ZEPHYR_INCLUDE_USB_BOS_H_

<<<<<<< HEAD
#if defined(CONFIG_USB_DEVICE_BOS)
#define USB_DEVICE_BOS_DESC_DEFINE_HDR \
	static __in_section(usb, bos_desc_area, 0) __aligned(1) __used
#define USB_DEVICE_BOS_DESC_DEFINE_CAP \
	static __in_section(usb, bos_desc_area, 1) __aligned(1) __used

#define USB_BOS_CAPABILITY_EXTENSION	0x02
#define USB_BOS_CAPABILITY_PLATFORM	0x05

/* BOS Capability Descriptor */
=======
#include <stdint.h>

/**
 * @brief USB Binary Device Object Store support
 * @defgroup usb_bos USB BOS support
 * @ingroup usb
 * @{
 */

/**
 * @brief Helper macro to place the BOS compatibility descriptor
 *        in the right memory section.
 */
#define USB_DEVICE_BOS_DESC_DEFINE_CAP \
	static __in_section(usb, bos_desc_area, 1) __aligned(1) __used

/** Device capability type codes */
enum usb_bos_capability_types {
	USB_BOS_CAPABILITY_EXTENSION = 0x02,
	USB_BOS_CAPABILITY_PLATFORM = 0x05,
};

/** BOS USB 2.0 extension capability descriptor */
struct usb_bos_capability_lpm {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDevCapabilityType;
	uint32_t bmAttributes;
} __packed;

/** BOS platform capability descriptor */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
struct usb_bos_platform_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDevCapabilityType;
	uint8_t bReserved;
	uint8_t PlatformCapabilityUUID[16];
} __packed;

<<<<<<< HEAD
/* BOS Descriptor */
struct usb_bos_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t wTotalLength;
	uint8_t bNumDeviceCaps;
} __packed;

/* BOS Capability webusb */
=======
/** WebUSB specific part of platform capability descriptor */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
struct usb_bos_capability_webusb {
	uint16_t bcdVersion;
	uint8_t bVendorCode;
	uint8_t iLandingPage;
} __packed;

<<<<<<< HEAD
/* BOS Capability MS OS Descriptors version 2 */
=======
/** Microsoft OS 2.0 descriptor specific part of platform capability descriptor */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
struct usb_bos_capability_msos {
	uint32_t dwWindowsVersion;
	uint16_t wMSOSDescriptorSetTotalLength;
	uint8_t bMS_VendorCode;
	uint8_t bAltEnumCode;
} __packed;

<<<<<<< HEAD
struct usb_bos_capability_lpm {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint8_t bDevCapabilityType;
	uint32_t bmAttributes;
} __packed;

size_t usb_bos_get_length(void);
void usb_bos_fix_total_length(void);
void usb_bos_register_cap(struct usb_bos_platform_descriptor *hdr);
const void *usb_bos_get_header(void);
=======
/**
 * @brief Register BOS capability descriptor
 *
 * This function should be used by the application to register BOS capability
 * descriptors before the USB device stack is enabled.
 *
 * @param[in] hdr Pointer to BOS capability descriptor
 */
void usb_bos_register_cap(struct usb_bos_platform_descriptor *hdr);

/**
 * @cond INTERNAL_HIDDEN
 * Internally used functions
 */

/* BOS Descriptor (root descriptor) */
struct usb_bos_descriptor {
	uint8_t bLength;
	uint8_t bDescriptorType;
	uint16_t wTotalLength;
	uint8_t bNumDeviceCaps;
} __packed;

#define USB_DEVICE_BOS_DESC_DEFINE_HDR \
	static __in_section(usb, bos_desc_area, 0) __aligned(1) __used

size_t usb_bos_get_length(void);

void usb_bos_fix_total_length(void);

const void *usb_bos_get_header(void);

#if defined(CONFIG_USB_DEVICE_BOS)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
int usb_handle_bos(struct usb_setup_packet *setup, int32_t *len, uint8_t **data);
#else
#define usb_handle_bos(x, y, z)		-ENOTSUP
#endif
<<<<<<< HEAD
=======
/** @endcond */

/**
 * @}
 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#endif	/* ZEPHYR_INCLUDE_USB_BOS_H_ */
