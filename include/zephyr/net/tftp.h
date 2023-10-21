/*
 * Copyright (c) 2020 InnBlue
 *
 * SPDX-License-Identifier: Apache-2.0
 */

/** @file tftp.h
 *
<<<<<<< HEAD
 *  @brief Zephyr TFTP Implementation
=======
 * @defgroup tftp_client TFTP Client library
 * @ingroup networking
 * @{
 * @brief TFTP Client Implementation
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 */

#ifndef ZEPHYR_INCLUDE_NET_TFTP_H_
#define ZEPHYR_INCLUDE_NET_TFTP_H_

#include <zephyr/kernel.h>
#include <zephyr/net/socket.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * RFC1350: the file is sent in fixed length blocks of 512 bytes.
 * Each data packet contains one block of data, and must be acknowledged
 * by an acknowledgment packet before the next packet can be sent.
 * A data packet of less than 512 bytes signals termination of a transfer.
 */
#define TFTP_BLOCK_SIZE          512

/**
 * RFC1350: For non-request TFTP message, the header contains 2-byte operation
 * code plus 2-byte block number or error code.
 */
#define TFTP_HEADER_SIZE         4

<<<<<<< HEAD
/* Maximum amount of data that can be sent or received */
#define TFTPC_MAX_BUF_SIZE       (TFTP_BLOCK_SIZE + TFTP_HEADER_SIZE)

/* TFTP Client Error codes. */
#define TFTPC_SUCCESS             0
#define TFTPC_DUPLICATE_DATA     -1
#define TFTPC_BUFFER_OVERFLOW    -2
#define TFTPC_UNKNOWN_FAILURE    -3
#define TFTPC_REMOTE_ERROR       -4
#define TFTPC_RETRIES_EXHAUSTED  -5
=======
/** Maximum amount of data that can be sent or received */
#define TFTPC_MAX_BUF_SIZE       (TFTP_BLOCK_SIZE + TFTP_HEADER_SIZE)

/**
 * @name TFTP client error codes.
 * @{
 */
#define TFTPC_SUCCESS             0 /**< Success. */
#define TFTPC_DUPLICATE_DATA     -1 /**< Duplicate data received. */
#define TFTPC_BUFFER_OVERFLOW    -2 /**< User buffer is too small. */
#define TFTPC_UNKNOWN_FAILURE    -3 /**< Unknown failure. */
#define TFTPC_REMOTE_ERROR       -4 /**< Remote server error. */
#define TFTPC_RETRIES_EXHAUSTED  -5 /**< Retries exhausted. */
/**
 * @}
 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

/**
 * @brief TFTP Asynchronous Events notified to the application from the module
 *        through the callback registered by the application.
 */
enum tftp_evt_type {
<<<<<<< HEAD
	/** DATA event when data is received from remote server.
=======
	/**
	 * DATA event when data is received from remote server.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	 *
	 * @note DATA event structure contains payload data and size.
	 */
	TFTP_EVT_DATA,

<<<<<<< HEAD
	/** ERROR event when error is received from remote server.
=======
	/**
	 * ERROR event when error is received from remote server.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	 *
	 * @note ERROR event structure contains error code and message.
	 */
	TFTP_EVT_ERROR
};

/** @brief Parameters for data event. */
struct tftp_data_param {
	uint8_t *data_ptr;         /**< Pointer to binary data. */
	uint32_t len;              /**< Length of binary data. */
};

/** @brief Parameters for error event. */
struct tftp_error_param {
	char *msg;                 /**< Error message. */
	int code;                  /**< Error code. */
};

/**
 * @brief Defines event parameters notified along with asynchronous events
 *        to the application.
 */
union tftp_evt_param {
	/** Parameters accompanying TFTP_EVT_DATA event. */
	struct tftp_data_param data;

	/** Parameters accompanying TFTP_EVT_ERROR event. */
	struct tftp_error_param error;
};

/** @brief Defines TFTP asynchronous event notified to the application. */
struct tftp_evt {
	/** Identifies the event. */
	enum tftp_evt_type type;

	/** Contains parameters (if any) accompanying the event. */
	union tftp_evt_param param;
};

/**
 * @typedef tftp_callback_t
 *
 * @brief TFTP event notification callback registered by the application.
 *
 * @param[in] evt Event description along with result and associated
 *                parameters (if any).
 */
typedef void (*tftp_callback_t)(const struct tftp_evt *evt);

/**
 * @brief TFTP client definition to maintain information relevant to the
 *        client.
 *
 * @note Application must initialize `server` and `callback` before calling
 *       GET or PUT API with the `tftpc` structure.
 */
struct tftpc {
	/** Socket address pointing to the remote TFTP server */
	struct sockaddr server;

	/** Event notification callback. No notification if NULL */
	tftp_callback_t callback;

	/** Buffer for internal usage */
	uint8_t tftp_buf[TFTPC_MAX_BUF_SIZE];
};

<<<<<<< HEAD
/* @brief This function gets data from a "file" on the remote server.
=======
/**
 * @brief This function gets data from a "file" on the remote server.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @param client      Client information of type @ref tftpc.
 * @param remote_file Name of the remote file to get.
 * @param mode        TFTP Client "mode" setting.
 *
<<<<<<< HEAD
 * @return The size of data being received if the operation completed successfully.
 *         TFTPC_BUFFER_OVERFLOW if the file is larger than the user buffer.
 *         TFTPC_REMOTE_ERROR if the server failed to process our request.
 *         TFTPC_RETRIES_EXHAUSTED if the client timed out waiting for server.
 *         -EINVAL if `client` is NULL.
=======
 * @retval The size of data being received if the operation completed successfully.
 * @retval TFTPC_BUFFER_OVERFLOW if the file is larger than the user buffer.
 * @retval TFTPC_REMOTE_ERROR if the server failed to process our request.
 * @retval TFTPC_RETRIES_EXHAUSTED if the client timed out waiting for server.
 * @retval -EINVAL if `client` is NULL.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @note This function blocks until the transfer is completed or network error happens. The
 *       integrity of the `client` structure must be ensured until the function returns.
 */
int tftp_get(struct tftpc *client,
	     const char *remote_file, const char *mode);

<<<<<<< HEAD
/* @brief This function puts data to a "file" on the remote server.
=======
/**
 * @brief This function puts data to a "file" on the remote server.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @param client      Client information of type @ref tftpc.
 * @param remote_file Name of the remote file to put.
 * @param mode        TFTP Client "mode" setting.
 * @param user_buf    Data buffer containing the data to put.
 * @param user_buf_size Length of the data to put.
 *
<<<<<<< HEAD
 * @return The size of data being sent if the operation completed successfully.
 *         TFTPC_REMOTE_ERROR if the server failed to process our request.
 *         TFTPC_RETRIES_EXHAUSTED if the client timed out waiting for server.
 *         -EINVAL if `client` or `user_buf` is NULL or if `user_buf_size` is zero.
=======
 * @retval The size of data being sent if the operation completed successfully.
 * @retval TFTPC_REMOTE_ERROR if the server failed to process our request.
 * @retval TFTPC_RETRIES_EXHAUSTED if the client timed out waiting for server.
 * @retval -EINVAL if `client` or `user_buf` is NULL or if `user_buf_size` is zero.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 *
 * @note This function blocks until the transfer is completed or network error happens. The
 *       integrity of the `client` structure must be ensured until the function returns.
 */
int tftp_put(struct tftpc *client,
	     const char *remote_file, const char *mode,
	     const uint8_t *user_buf, uint32_t user_buf_size);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_NET_TFTP_H_ */
<<<<<<< HEAD
=======

/** @} */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
