/*
 * Copyright (c) 2023 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include <zephyr/logging/log.h>
LOG_MODULE_DECLARE(net_coap, CONFIG_COAP_LOG_LEVEL);

#include <zephyr/net/socket.h>

#include <zephyr/net/coap.h>
#include <zephyr/net/coap_client.h>

#define COAP_VERSION 1
<<<<<<< HEAD
#define COAP_PATH_ELEM_DELIM '/'
#define COAP_PATH_ELEM_QUERY '?'
#define COAP_PATH_ELEM_AMP '&'
#define COAP_SEPARATE_TIMEOUT 6000
=======
#define COAP_SEPARATE_TIMEOUT 6000
#define COAP_PERIODIC_TIMEOUT 500
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define DEFAULT_RETRY_AMOUNT 5
#define BLOCK1_OPTION_SIZE 4
#define PAYLOAD_MARKER_SIZE 1

<<<<<<< HEAD
static int coap_client_schedule_poll(struct coap_client *client, int sock,
				     struct coap_client_request *req)
{
	client->fd = sock;
	client->coap_request = req;

	k_sem_give(&client->coap_client_recv_sem);
	atomic_set(&client->coap_client_recv_active, 1);

	return 0;
}
=======
static struct coap_client *clients[CONFIG_COAP_CLIENT_MAX_INSTANCES];
static int num_clients;
static K_SEM_DEFINE(coap_client_recv_sem, 0, 1);
static atomic_t coap_client_recv_active;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

static int send_request(int sock, const void *buf, size_t len, int flags,
			const struct sockaddr *dest_addr, socklen_t addrlen)
{
	if (addrlen == 0) {
<<<<<<< HEAD
		return sendto(sock, buf, len, flags, NULL, 0);
	} else {
		return sendto(sock, buf, len, flags, dest_addr, addrlen);
=======
		return zsock_sendto(sock, buf, len, flags, NULL, 0);
	} else {
		return zsock_sendto(sock, buf, len, flags, dest_addr, addrlen);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}
}

static int receive(int sock, void *buf, size_t max_len, int flags,
		   struct sockaddr *src_addr, socklen_t *addrlen)
{
	if (*addrlen == 0) {
<<<<<<< HEAD
		return recvfrom(sock, buf, max_len, flags, NULL, NULL);
	} else {
		return recvfrom(sock, buf, max_len, flags, src_addr, addrlen);
	}
}

static void reset_block_contexts(struct coap_client *client)
{
	client->recv_blk_ctx.block_size = 0;
	client->recv_blk_ctx.total_size = 0;
	client->recv_blk_ctx.current = 0;

	client->send_blk_ctx.block_size = 0;
	client->send_blk_ctx.total_size = 0;
	client->send_blk_ctx.current = 0;
}

static int coap_client_init_path_options(struct coap_packet *pckt, const char *path)
{
	int ret = 0;
	int path_start, path_end;
	int path_length;
	bool contains_query = false;
	int i;

	path_start = 0;
	path_end = 0;
	path_length = strlen(path);
	for (i = 0; i < path_length; i++) {
		path_end = i;
		if (path[i] == COAP_PATH_ELEM_DELIM) {
			/* Guard for preceding delimiters */
			if (path_start < path_end) {
				ret = coap_packet_append_option(pckt, COAP_OPTION_URI_PATH,
								path + path_start,
								path_end - path_start);
				if (ret < 0) {
					LOG_ERR("Failed to append path to CoAP message");
					goto out;
				}
			}
			/* Check if there is a new path after delimiter,
			 * if not, point to the end of string to not add
			 * new option after this
			 */
			if (path_length > i + 1) {
				path_start = i + 1;
			} else {
				path_start = path_length;
			}
		} else if (path[i] == COAP_PATH_ELEM_QUERY) {
			/* Guard for preceding delimiters */
			if (path_start < path_end) {
				ret = coap_packet_append_option(pckt, COAP_OPTION_URI_PATH,
								path + path_start,
								path_end - path_start);
				if (ret < 0) {
					LOG_ERR("Failed to append path to CoAP message");
					goto out;
				}
			}
			/* Rest of the path is query */
			contains_query = true;
			if (path_length > i + 1) {
				path_start = i + 1;
			} else {
				path_start = path_length;
			}
			break;
		}
	}

	if (contains_query) {
		for (i = path_start; i < path_length; i++) {
			path_end = i;
			if (path[i] == COAP_PATH_ELEM_AMP || path[i] == COAP_PATH_ELEM_QUERY) {
				/* Guard for preceding delimiters */
				if (path_start < path_end) {
					ret = coap_packet_append_option(pckt, COAP_OPTION_URI_QUERY,
									path + path_start,
									path_end - path_start);
					if (ret < 0) {
						LOG_ERR("Failed to append path to CoAP message");
						goto out;
					}
				}
				/* Check if there is a new query option after delimiter,
				 * if not, point to the end of string to not add
				 * new option after this
				 */
				if (path_length > i + 1) {
					path_start = i + 1;
				} else {
					path_start = path_length;
				}
			}
		}
	}

	if (path_start < path_end) {
		if (contains_query) {
			ret = coap_packet_append_option(pckt, COAP_OPTION_URI_QUERY,
							path + path_start,
							path_end - path_start + 1);
		} else {
			ret = coap_packet_append_option(pckt, COAP_OPTION_URI_PATH,
							path + path_start,
							path_end - path_start + 1);
		}
		if (ret < 0) {
			LOG_ERR("Failed to append path to CoAP message");
			goto out;
		}
	}

out:
	return ret;
=======
		return zsock_recvfrom(sock, buf, max_len, flags, NULL, NULL);
	} else {
		return zsock_recvfrom(sock, buf, max_len, flags, src_addr, addrlen);
	}
}

static void reset_block_contexts(struct coap_client_internal_request *request)
{
	request->recv_blk_ctx.block_size = 0;
	request->recv_blk_ctx.total_size = 0;
	request->recv_blk_ctx.current = 0;

	request->send_blk_ctx.block_size = 0;
	request->send_blk_ctx.total_size = 0;
	request->send_blk_ctx.current = 0;
}

static void reset_internal_request(struct coap_client_internal_request *request)
{
	request->offset = 0;
	request->last_id = 0;
	request->retry_count = 0;
	reset_block_contexts(request);
}

static int coap_client_schedule_poll(struct coap_client *client, int sock,
				     struct coap_client_request *req,
				     struct coap_client_internal_request *internal_req)
{
	client->fd = sock;
	memcpy(&internal_req->coap_request, req, sizeof(struct coap_client_request));
	internal_req->request_ongoing = true;

	if (!coap_client_recv_active) {
		k_sem_give(&coap_client_recv_sem);
	}
	atomic_set(&coap_client_recv_active, 1);

	return 0;
}

bool has_ongoing_request(struct coap_client *client)
{
	for (int i = 0; i < CONFIG_COAP_CLIENT_MAX_REQUESTS; i++) {
		if (client->requests[i].request_ongoing == true) {
			return true;
		}
	}

	return false;
}

struct coap_client_internal_request *get_free_request(struct coap_client *client)
{
	for (int i = 0; i < CONFIG_COAP_CLIENT_MAX_REQUESTS; i++) {
		if (client->requests[i].request_ongoing == false) {
			return &client->requests[i];
		}
	}

	return NULL;
}

static bool has_ongoing_requests(void)
{
	bool has_requests = false;

	for (int i = 0; i < num_clients; i++) {
		has_requests |= has_ongoing_request(clients[i]);
	}

	return has_requests;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

static enum coap_block_size coap_client_default_block_size(void)
{
	switch (CONFIG_COAP_CLIENT_BLOCK_SIZE) {
	case 16:
		return COAP_BLOCK_16;
	case 32:
		return COAP_BLOCK_32;
	case 64:
		return COAP_BLOCK_64;
	case 128:
		return COAP_BLOCK_128;
	case 256:
		return COAP_BLOCK_256;
	case 512:
		return COAP_BLOCK_512;
	case 1024:
		return COAP_BLOCK_1024;
	}

	return COAP_BLOCK_256;
}

static int coap_client_init_request(struct coap_client *client,
<<<<<<< HEAD
				    struct coap_client_request *req)
=======
				    struct coap_client_request *req,
				    struct coap_client_internal_request *internal_req,
				    bool reconstruct)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	int ret = 0;
	int i;

	memset(client->send_buf, 0, sizeof(client->send_buf));
<<<<<<< HEAD
	ret = coap_packet_init(&client->request, client->send_buf, MAX_COAP_MSG_LEN, 1,
			       req->confirmable ? COAP_TYPE_CON : COAP_TYPE_NON_CON,
			       COAP_TOKEN_MAX_LEN, coap_next_token(), req->method,
			       coap_next_id());
=======

	if (!reconstruct) {
		uint8_t *token = coap_next_token();

		internal_req->last_id = coap_next_id();
		internal_req->request_tkl = COAP_TOKEN_MAX_LEN & 0xf;
		memcpy(internal_req->request_token, token, internal_req->request_tkl);
	}

	ret = coap_packet_init(&internal_req->request, client->send_buf, MAX_COAP_MSG_LEN,
			       1, req->confirmable ? COAP_TYPE_CON : COAP_TYPE_NON_CON,
			       COAP_TOKEN_MAX_LEN, internal_req->request_token, req->method,
			       internal_req->last_id);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (ret < 0) {
		LOG_ERR("Failed to init CoAP message %d", ret);
		goto out;
	}

<<<<<<< HEAD
	ret = coap_client_init_path_options(&client->request, req->path);
=======
	ret = coap_packet_set_path(&internal_req->request, req->path);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (ret < 0) {
		LOG_ERR("Failed to parse path to options %d", ret);
		goto out;
	}

<<<<<<< HEAD
	ret = coap_append_option_int(&client->request, COAP_OPTION_CONTENT_FORMAT, req->fmt);

	if (ret < 0) {
		LOG_ERR("Failed to append content format option");
		goto out;
	}

	/* Blockwise receive ongoing, request next block. */
	if (client->recv_blk_ctx.current > 0) {
		ret = coap_append_block2_option(&client->request, &client->recv_blk_ctx);
=======
	/* Add content format option only if there is a payload */
	if (req->payload) {
		ret = coap_append_option_int(&internal_req->request,
					     COAP_OPTION_CONTENT_FORMAT, req->fmt);

		if (ret < 0) {
			LOG_ERR("Failed to append content format option");
			goto out;
		}
	}

	/* Blockwise receive ongoing, request next block. */
	if (internal_req->recv_blk_ctx.current > 0) {
		ret = coap_append_block2_option(&internal_req->request,
						&internal_req->recv_blk_ctx);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

		if (ret < 0) {
			LOG_ERR("Failed to append block 2 option");
			goto out;
		}
	}

	/* Add extra options if any */
	for (i = 0; i < req->num_options; i++) {
<<<<<<< HEAD
		ret = coap_packet_append_option(&client->request, req->options[i].code,
=======
		ret = coap_packet_append_option(&internal_req->request, req->options[i].code,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
						req->options[i].value, req->options[i].len);

		if (ret < 0) {
			LOG_ERR("Failed to append %d option", req->options[i].code);
			goto out;
		}
	}

	if (req->payload) {
		uint16_t payload_len;
		uint16_t offset;

		/* Blockwise send ongoing, add block1 */
<<<<<<< HEAD
		if (client->send_blk_ctx.total_size > 0 ||
		   (req->len > CONFIG_COAP_CLIENT_MESSAGE_SIZE)) {

			if (client->send_blk_ctx.total_size == 0) {
				coap_block_transfer_init(&client->send_blk_ctx,
							 coap_client_default_block_size(),
							 req->len);
			}
			ret = coap_append_block1_option(&client->request, &client->send_blk_ctx);
=======
		if (internal_req->send_blk_ctx.total_size > 0 ||
		   (req->len > CONFIG_COAP_CLIENT_MESSAGE_SIZE)) {

			if (internal_req->send_blk_ctx.total_size == 0) {
				coap_block_transfer_init(&internal_req->send_blk_ctx,
							 coap_client_default_block_size(),
							 req->len);
			}
			ret = coap_append_block1_option(&internal_req->request,
							&internal_req->send_blk_ctx);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

			if (ret < 0) {
				LOG_ERR("Failed to append block1 option");
				goto out;
			}
		}

<<<<<<< HEAD
		ret = coap_packet_append_payload_marker(&client->request);
=======
		ret = coap_packet_append_payload_marker(&internal_req->request);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

		if (ret < 0) {
			LOG_ERR("Failed to append payload marker to CoAP message");
			goto out;
		}

<<<<<<< HEAD
		if (client->send_blk_ctx.total_size > 0) {
			uint16_t block_in_bytes =
				coap_block_size_to_bytes(client->send_blk_ctx.block_size);

			payload_len = client->send_blk_ctx.total_size -
				      client->send_blk_ctx.current;
			if (payload_len > block_in_bytes) {
				payload_len = block_in_bytes;
			}
			offset = client->send_blk_ctx.current;
=======
		if (internal_req->send_blk_ctx.total_size > 0) {
			uint16_t block_in_bytes =
				coap_block_size_to_bytes(internal_req->send_blk_ctx.block_size);

			payload_len = internal_req->send_blk_ctx.total_size -
				      internal_req->send_blk_ctx.current;
			if (payload_len > block_in_bytes) {
				payload_len = block_in_bytes;
			}
			offset = internal_req->send_blk_ctx.current;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		} else {
			payload_len = req->len;
			offset = 0;
		}

<<<<<<< HEAD
		ret = coap_packet_append_payload(&client->request, req->payload + offset,
=======
		ret = coap_packet_append_payload(&internal_req->request, req->payload + offset,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
						 payload_len);

		if (ret < 0) {
			LOG_ERR("Failed to append payload to CoAP message");
			goto out;
		}

<<<<<<< HEAD
		if (client->send_blk_ctx.total_size > 0) {
			coap_next_block(&client->request, &client->send_blk_ctx);
		}
	}
	client->request_tkl = coap_header_get_token(&client->request, client->request_token);
=======
		if (internal_req->send_blk_ctx.total_size > 0) {
			coap_next_block(&internal_req->request, &internal_req->send_blk_ctx);
		}
	}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
out:
	return ret;
}

<<<<<<< HEAD

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
int coap_client_req(struct coap_client *client, int sock, const struct sockaddr *addr,
		    struct coap_client_request *req, int retries)
{
	int ret;

<<<<<<< HEAD
	if (client->coap_client_recv_active) {
=======
	struct coap_client_internal_request *internal_req = get_free_request(client);

	if (internal_req == NULL) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		return -EAGAIN;
	}

	if (sock < 0 || req == NULL || req->path == NULL) {
		return -EINVAL;
	}

<<<<<<< HEAD
	if (addr != NULL) {
		memcpy(&client->address, addr, sizeof(*addr));
		client->socklen = sizeof(client->address);
	} else {
		memset(&client->address, 0, sizeof(client->address));
		client->socklen = 0;
	}

	if (retries == -1) {
		client->retry_count = DEFAULT_RETRY_AMOUNT;
	} else {
		client->retry_count = retries;
	}

	ret = coap_client_init_request(client, req);
	if (ret < 0) {
		LOG_ERR("Failed to initialize coap request");
		return ret;
	}

	ret = coap_client_schedule_poll(client, sock, req);
	if (ret < 0) {
		LOG_ERR("Failed to schedule polling");
		goto out;
	}

	ret = coap_pending_init(&client->pending, &client->request, &client->address,
				client->retry_count);

	if (ret < 0) {
		LOG_ERR("Failed to initialize pending struct");
		goto out;
	}

	coap_pending_cycle(&client->pending);

	ret = send_request(sock, client->request.data, client->request.offset, 0, &client->address,
			   client->socklen);
=======
	/* Don't allow changing to a different socket if there is already request ongoing. */
	if (client->fd != sock && has_ongoing_request(client)) {
		return -EALREADY;
	}

	/* Don't allow changing to a different address if there is already request ongoing. */
	if (addr != NULL) {
		if (memcmp(&client->address, addr, sizeof(*addr)) != 0) {
			if (has_ongoing_request(client)) {
				LOG_WRN("Can't change to a different socket, request ongoing.");
				return -EALREADY;
			}

			memcpy(&client->address, addr, sizeof(*addr));
			client->socklen = sizeof(client->address);
		}
	} else {
		if (client->socklen != 0) {
			if (has_ongoing_request(client)) {
				LOG_WRN("Can't change to a different socket, request ongoing.");
				return -EALREADY;
			}

			memset(&client->address, 0, sizeof(client->address));
			client->socklen = 0;
		}
	}

	reset_internal_request(internal_req);

	if (k_mutex_lock(&client->send_mutex, K_NO_WAIT)) {
		return -EAGAIN;
	}

	ret = coap_client_init_request(client, req, internal_req, false);
	if (ret < 0) {
		LOG_ERR("Failed to initialize coap request");
		k_mutex_unlock(&client->send_mutex);
		goto out;
	}

	ret = coap_client_schedule_poll(client, sock, req, internal_req);
	if (ret < 0) {
		LOG_ERR("Failed to schedule polling");
		k_mutex_unlock(&client->send_mutex);
		goto out;
	}

	/* only TYPE_CON messages need pending tracking */
	if (coap_header_get_type(&internal_req->request) == COAP_TYPE_CON) {
		if (retries == -1) {
			internal_req->retry_count = DEFAULT_RETRY_AMOUNT;
		} else {
			internal_req->retry_count = retries;
		}

		ret = coap_pending_init(&internal_req->pending, &internal_req->request,
					&client->address, internal_req->retry_count);

		if (ret < 0) {
			LOG_ERR("Failed to initialize pending struct");
			k_mutex_unlock(&client->send_mutex);
			goto out;
		}

		coap_pending_cycle(&internal_req->pending);
	}

	ret = send_request(sock, internal_req->request.data, internal_req->request.offset, 0,
			  &client->address, client->socklen);

	k_mutex_unlock(&client->send_mutex);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	if (ret < 0) {
		LOG_ERR("Transmission failed: %d", errno);
	} else {
		/* Do not return the number of bytes sent */
		ret = 0;
	}
out:
	return ret;
}

<<<<<<< HEAD
static int handle_poll(struct coap_client *client)
{
	int ret = 0;

	while (1) {
		struct pollfd fds;

		fds.fd = client->fd;
		fds.events = POLLIN;
		fds.revents = 0;
		/* rfc7252#section-5.2.2, use separate timeout value for a separate response */
		if (client->pending.timeout != 0) {
			ret = poll(&fds, 1, client->pending.timeout);
		} else {
			ret = poll(&fds, 1, COAP_SEPARATE_TIMEOUT);
		}

		if (ret < 0) {
			LOG_ERR("Error in poll:%d", errno);
			errno = 0;
			return ret;
		} else if (ret == 0) {
			if (client->pending.timeout != 0 && coap_pending_cycle(&client->pending)) {
				LOG_ERR("Timeout in poll, retrying send");
				ret = send_request(client->fd, client->request.data,
						   client->request.offset, 0, &client->address,
						   client->socklen);
				if (ret < 0) {
					LOG_ERR("Transmission failed: %d", errno);
					ret = -errno;
					break;
				}
			} else {
				/* No more retries left, don't retry */
				LOG_ERR("Timeout in poll, no more retries");
				ret = -EFAULT;
				break;
			}
		} else {
			if (fds.revents & POLLERR) {
				LOG_ERR("Error in poll");
				ret = -EIO;
				break;
			}

			if (fds.revents & POLLHUP) {
				LOG_ERR("Error in poll: POLLHUP");
				ret = -ECONNRESET;
				break;
			}

			if (fds.revents & POLLNVAL) {
				LOG_ERR("Error in poll: POLLNVAL - fd not open");
				ret = -EINVAL;
				break;
			}

			if (!(fds.revents & POLLIN)) {
				LOG_ERR("Unknown poll error");
				ret = -EINVAL;
				break;
			}

			ret = 0;
			break;
=======
static void report_callback_error(struct coap_client_internal_request *internal_req, int error_code)
{
	if (internal_req->coap_request.cb) {
		internal_req->coap_request.cb(error_code, 0, NULL, 0, true,
					      internal_req->coap_request.user_data);
	}
}

static bool timeout_expired(struct coap_client_internal_request *internal_req)
{
	if (internal_req->pending.timeout == 0) {
		return false;
	}

	return (internal_req->request_ongoing &&
		internal_req->pending.timeout <= (k_uptime_get() - internal_req->pending.t0));
}

static int resend_request(struct coap_client *client,
			  struct coap_client_internal_request *internal_req)
{
	int ret = 0;

	if (internal_req->pending.timeout != 0 && coap_pending_cycle(&internal_req->pending)) {
		LOG_ERR("Timeout in poll, retrying send");

		/* Reset send block context as it was updated in previous init from packet */
		if (internal_req->send_blk_ctx.total_size > 0) {
			internal_req->send_blk_ctx.current = internal_req->offset;
		}
		k_mutex_lock(&client->send_mutex, K_FOREVER);
		ret = coap_client_init_request(client, &internal_req->coap_request,
					       internal_req, true);
		if (ret < 0) {
			LOG_ERR("Error re-creating CoAP request");
		} else {
			ret = send_request(client->fd, internal_req->request.data,
					   internal_req->request.offset, 0, &client->address,
					   client->socklen);
			if (ret > 0) {
				ret = 0;
			} else {
				LOG_ERR("Failed to resend request, %d", ret);
			}
		}
		k_mutex_unlock(&client->send_mutex);
	} else {
		LOG_ERR("Timeout in poll, no more retries left");
		ret = -ETIMEDOUT;
		report_callback_error(internal_req, ret);
		internal_req->request_ongoing = false;
	}

	return ret;
}

static int coap_client_resend_handler(void)
{
	int ret = 0;

	for (int i = 0; i < num_clients; i++) {
		for (int j = 0; j < CONFIG_COAP_CLIENT_MAX_REQUESTS; j++) {
			if (timeout_expired(&clients[i]->requests[j])) {
				ret = resend_request(clients[i], &clients[i]->requests[j]);
			}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	return ret;
}

<<<<<<< HEAD
static bool token_compare(struct coap_client *client, const struct coap_packet *resp)
=======
static int handle_poll(void)
{
	int ret = 0;

	while (1) {
		struct zsock_pollfd fds[CONFIG_COAP_CLIENT_MAX_INSTANCES] = {0};
		int nfds = 0;

		/* Use periodic timeouts */
		for (int i = 0; i < num_clients; i++) {
			fds[i].fd = clients[i]->fd;
			fds[i].events = ZSOCK_POLLIN;
			fds[i].revents = 0;
			nfds++;
		}

		ret = zsock_poll(fds, nfds, COAP_PERIODIC_TIMEOUT);

		if (ret < 0) {
			LOG_ERR("Error in poll:%d", errno);
			errno = 0;
			return ret;
		} else if (ret == 0) {
			/* Resend all the expired pending messages */
			ret = coap_client_resend_handler();

			if (ret < 0) {
				LOG_ERR("Error resending request: %d", ret);
			}

			if (!has_ongoing_requests()) {
				return ret;
			}

		} else {
			for (int i = 0; i < nfds; i++) {
				if (fds[i].revents & ZSOCK_POLLERR) {
					LOG_ERR("Error in poll for socket %d", fds[i].fd);
				}
				if (fds[i].revents & ZSOCK_POLLHUP) {
					LOG_ERR("Error in poll: POLLHUP for socket %d", fds[i].fd);
				}
				if (fds[i].revents & ZSOCK_POLLNVAL) {
					LOG_ERR("Error in poll: POLLNVAL - fd %d not open",
						fds[i].fd);
				}
				if (fds[i].revents & ZSOCK_POLLIN) {
					clients[i]->response_ready = true;
				}
			}

			return 0;
		}
	}

	return ret;
}

static bool token_compare(struct coap_client_internal_request *internal_req,
			  const struct coap_packet *resp)
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
{
	uint8_t response_token[COAP_TOKEN_MAX_LEN];
	uint8_t response_tkl;

	response_tkl = coap_header_get_token(resp, response_token);

<<<<<<< HEAD
	if (client->request_tkl != response_tkl) {
		return false;
	}

	return memcmp(&client->request_token, &response_token, response_tkl) == 0;
=======
	if (internal_req->request_tkl != response_tkl) {
		return false;
	}

	return memcmp(&internal_req->request_token, &response_token, response_tkl) == 0;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

static int recv_response(struct coap_client *client, struct coap_packet *response)
{
	int len;
	int ret;

	memset(client->recv_buf, 0, sizeof(client->recv_buf));
<<<<<<< HEAD
	len = receive(client->fd, client->recv_buf, sizeof(client->recv_buf), MSG_DONTWAIT,
=======
	len = receive(client->fd, client->recv_buf, sizeof(client->recv_buf), ZSOCK_MSG_DONTWAIT,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		      &client->address, &client->socklen);

	if (len < 0) {
		LOG_ERR("Error reading response: %d", errno);
		return -EINVAL;
	} else if (len == 0) {
		LOG_ERR("Zero length recv");
		return -EINVAL;
	}

	LOG_DBG("Received %d bytes", len);

	ret = coap_packet_parse(response, client->recv_buf, len, NULL, 0);
	if (ret < 0) {
		LOG_ERR("Invalid data received");
		return ret;
	}

	return ret;
}

<<<<<<< HEAD
static void report_callback_error(struct coap_client *client, int error_code)
{
	if (client->coap_request->cb) {
		client->coap_request->cb(error_code, 0, NULL, 0, true,
					 client->coap_request->user_data);
	}
}

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
static int send_ack(struct coap_client *client, const struct coap_packet *req,
		    uint8_t response_code)
{
	int ret;
<<<<<<< HEAD

	ret = coap_ack_init(&client->request, req, client->send_buf, MAX_COAP_MSG_LEN,
			    response_code);
=======
	struct coap_packet ack;

	ret = coap_ack_init(&ack, req, client->send_buf, MAX_COAP_MSG_LEN, response_code);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (ret < 0) {
		LOG_ERR("Failed to initialize CoAP ACK-message");
		return ret;
	}

<<<<<<< HEAD
	ret = send_request(client->fd, client->request.data, client->request.offset, 0,
			   &client->address, client->socklen);
=======
	ret = send_request(client->fd, ack.data, ack.offset, 0, &client->address, client->socklen);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (ret < 0) {
		LOG_ERR("Error sending a CoAP ACK-message");
		return ret;
	}

	return 0;
}

<<<<<<< HEAD
static int send_reset(struct coap_client *client, const struct coap_packet *req,
		      uint8_t response_code)
{
	int ret;
	uint16_t id;
	uint8_t token[COAP_TOKEN_MAX_LEN];
	uint8_t tkl;

	id = coap_header_get_id(req);
	tkl = response_code ? coap_header_get_token(req, token) : 0;
	ret = coap_packet_init(&client->request, client->send_buf, MAX_COAP_MSG_LEN, COAP_VERSION,
			       COAP_TYPE_RESET, tkl, token, response_code, id);

	if (ret < 0) {
		LOG_ERR("Error creating CoAP reset message");
		return ret;
	}

	ret = send_request(client->fd, client->request.data, client->request.offset, 0,
			   &client->address, client->socklen);
	if (ret < 0) {
		LOG_ERR("Error sending CoAP reset message");
		return ret;
	}

	return 0;
=======
struct coap_client_internal_request *get_request_with_id(struct coap_client *client,
							 uint16_t message_id)
{
	for (int i = 0; i < CONFIG_COAP_CLIENT_MAX_REQUESTS; i++) {
		if (client->requests[i].request_ongoing == true &&
		    client->requests[i].pending.id == message_id) {
			return &client->requests[i];
		}
	}

	return NULL;
}

struct coap_client_internal_request *get_request_with_token(struct coap_client *client,
							    const struct coap_packet *resp)
{

	uint8_t response_token[COAP_TOKEN_MAX_LEN];
	uint8_t response_tkl;

	response_tkl = coap_header_get_token(resp, response_token);

	for (int i = 0; i < CONFIG_COAP_CLIENT_MAX_REQUESTS; i++) {
		if (client->requests[i].request_ongoing) {
			if (client->requests[i].request_tkl != response_tkl) {
				continue;
			}
			if (memcmp(&client->requests[i].request_token, &response_token,
			    response_tkl) == 0) {
				return &client->requests[i];
			}
		}
	}

	return NULL;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

static int handle_response(struct coap_client *client, const struct coap_packet *response)
{
	int ret = 0;
	int response_type;
	int block_option;
	int block_num;
	bool blockwise_transfer = false;
	bool last_block = false;
<<<<<<< HEAD
=======
	struct coap_client_internal_request *internal_req;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	/* Handle different types, ACK might be separate or piggybacked
	 * CON and NCON contains a separate response, CON needs an empty response
	 * CON request results as ACK and possibly separate CON or NCON response
	 * NCON request results only as a separate CON or NCON message as there is no ACK
	 * With RESET, just drop gloves and call the callback.
	 */
	response_type = coap_header_get_type(response);

<<<<<<< HEAD
	/* Reset and Ack need to match the message ID with request */
	if ((response_type == COAP_TYPE_ACK || response_type == COAP_TYPE_RESET) &&
	     coap_header_get_id(response) != client->pending.id)  {
		LOG_ERR("Unexpected ACK or Reset");
		return -EFAULT;
	} else if (response_type == COAP_TYPE_RESET) {
		coap_pending_clear(&client->pending);
=======
	internal_req = get_request_with_token(client, response);
	/* Reset and Ack need to match the message ID with request */
	if ((response_type == COAP_TYPE_ACK || response_type == COAP_TYPE_RESET) &&
	     internal_req == NULL)  {
		LOG_ERR("Unexpected ACK or Reset");
		return -EFAULT;
	} else if (response_type == COAP_TYPE_RESET) {
		coap_pending_clear(&internal_req->pending);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	/* CON, NON_CON and piggybacked ACK need to match the token with original request */
	uint16_t payload_len;
	uint8_t response_code = coap_header_get_code(response);
	const uint8_t *payload = coap_packet_get_payload(response, &payload_len);

<<<<<<< HEAD
	/* Separate response */
	if (payload_len == 0 && response_type == COAP_TYPE_ACK &&
	    response_code == COAP_CODE_EMPTY) {
		/* Clear the pending, poll uses now the separate timeout for the response. */
		coap_pending_clear(&client->pending);
		return 1;
	}

	/* Check for tokens */
	if (!token_compare(client, response)) {
		LOG_ERR("Not matching tokens, respond with reset");
		ret = send_reset(client, response, COAP_RESPONSE_CODE_NOT_FOUND);
=======
	/* Separate response coming */
	if (payload_len == 0 && response_type == COAP_TYPE_ACK &&
	    response_code == COAP_CODE_EMPTY) {
		internal_req->pending.t0 = k_uptime_get();
		internal_req->pending.timeout = internal_req->pending.t0 + COAP_SEPARATE_TIMEOUT;
		internal_req->pending.retries = 0;
		return 1;
	}

	if (internal_req == NULL || !token_compare(internal_req, response)) {
		LOG_WRN("Not matching tokens");
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		return 1;
	}

	/* Send ack for CON */
	if (response_type == COAP_TYPE_CON) {
		/* CON response is always a separate response, respond with empty ACK. */
		ret = send_ack(client, response, COAP_CODE_EMPTY);
		if (ret < 0) {
			goto fail;
		}
	}

<<<<<<< HEAD
	if (client->pending.timeout != 0) {
		coap_pending_clear(&client->pending);
=======
	if (internal_req->pending.timeout != 0) {
		coap_pending_clear(&internal_req->pending);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	}

	/* Check if block2 exists */
	block_option = coap_get_option_int(response, COAP_OPTION_BLOCK2);
	if (block_option > 0) {
		blockwise_transfer = true;
		last_block = !GET_MORE(block_option);
		block_num = GET_BLOCK_NUM(block_option);

		if (block_num == 0) {
<<<<<<< HEAD
			coap_block_transfer_init(&client->recv_blk_ctx,
						 coap_client_default_block_size(),
						 0);
			client->offset = 0;
		}

		ret = coap_update_from_block(response, &client->recv_blk_ctx);
		if (ret < 0) {
			LOG_ERR("Error updating block context");
		}
		coap_next_block(response, &client->recv_blk_ctx);
	} else {
		client->offset = 0;
=======
			coap_block_transfer_init(&internal_req->recv_blk_ctx,
						 coap_client_default_block_size(),
						 0);
			internal_req->offset = 0;
		}

		ret = coap_update_from_block(response, &internal_req->recv_blk_ctx);
		if (ret < 0) {
			LOG_ERR("Error updating block context");
		}
		coap_next_block(response, &internal_req->recv_blk_ctx);
	} else {
		internal_req->offset = 0;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		last_block = true;
	}

	/* Check if this was a response to last blockwise send */
<<<<<<< HEAD
	if (client->send_blk_ctx.total_size > 0) {
		blockwise_transfer = true;
		if (client->send_blk_ctx.total_size == client->send_blk_ctx.current) {
=======
	if (internal_req->send_blk_ctx.total_size > 0) {
		blockwise_transfer = true;
		internal_req->offset = internal_req->send_blk_ctx.current;
		if (internal_req->send_blk_ctx.total_size == internal_req->send_blk_ctx.current) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
			last_block = true;
		} else {
			last_block = false;
		}
	}

	/* Call user callback */
<<<<<<< HEAD
	if (client->coap_request->cb) {
		client->coap_request->cb(response_code, client->offset, payload, payload_len,
					 last_block, client->coap_request->user_data);

		/* Update the offset for next callback in a blockwise transfer */
		if (blockwise_transfer) {
			client->offset += payload_len;
=======
	if (internal_req->coap_request.cb) {
		internal_req->coap_request.cb(response_code, internal_req->offset, payload,
					      payload_len, last_block,
					      internal_req->coap_request.user_data);

		/* Update the offset for next callback in a blockwise transfer */
		if (blockwise_transfer) {
			internal_req->offset += payload_len;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}

	/* If this wasn't last block, send the next request */
	if (blockwise_transfer && !last_block) {
<<<<<<< HEAD
		ret = coap_client_init_request(client, client->coap_request);

		if (ret < 0) {
			LOG_ERR("Error creating a CoAP request");
			goto fail;
		}

		if (client->pending.timeout != 0) {
			LOG_ERR("Previous pending hasn't arrived");
			goto fail;
		}

		ret = coap_pending_init(&client->pending, &client->request, &client->address,
					client->retry_count);
		if (ret < 0) {
			LOG_ERR("Error creating pending");
			goto fail;
		}
		coap_pending_cycle(&client->pending);

		ret = send_request(client->fd, client->request.data, client->request.offset, 0,
				   &client->address, client->socklen);
=======
		k_mutex_lock(&client->send_mutex, K_FOREVER);
		ret = coap_client_init_request(client, &internal_req->coap_request, internal_req,
					       false);

		if (ret < 0) {
			LOG_ERR("Error creating a CoAP request");
			k_mutex_unlock(&client->send_mutex);
			goto fail;
		}

		ret = coap_pending_init(&internal_req->pending, &internal_req->request,
					&client->address, internal_req->retry_count);
		if (ret < 0) {
			LOG_ERR("Error creating pending");
			k_mutex_unlock(&client->send_mutex);
			goto fail;
		}
		coap_pending_cycle(&internal_req->pending);

		ret = send_request(client->fd, internal_req->request.data,
				   internal_req->request.offset, 0, &client->address,
				   client->socklen);
		k_mutex_unlock(&client->send_mutex);

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		if (ret < 0) {
			LOG_ERR("Error sending a CoAP request");
			goto fail;
		} else {
			return 1;
		}
	}
fail:
<<<<<<< HEAD
=======
	client->response_ready = false;
	internal_req->request_ongoing = false;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return ret;
}

void coap_client_recv(void *coap_cl, void *a, void *b)
{
	int ret;
<<<<<<< HEAD
	struct coap_client *const client = coap_cl;

	reset_block_contexts(client);
	k_sem_take(&client->coap_client_recv_sem, K_FOREVER);
	while (true) {
		struct coap_packet response;

		atomic_set(&client->coap_client_recv_active, 1);
		ret = handle_poll(client);
		if (ret < 0) {
			/* Error in polling, clear pending. */
			LOG_ERR("Error in poll");
			coap_pending_clear(&client->pending);
			report_callback_error(client, ret);
			goto idle;
		}

		ret = recv_response(client, &response);
		if (ret < 0) {
			LOG_ERR("Error receiving response");
			report_callback_error(client, ret);
			goto idle;
		}

		ret = handle_response(client, &response);
		if (ret < 0) {
			LOG_ERR("Error handling respnse");
			report_callback_error(client, ret);
			goto idle;
		}

		/* There are more messages coming for the original request */
		if (ret > 0) {
			continue;
		} else {
idle:
			reset_block_contexts(client);
			atomic_set(&client->coap_client_recv_active, 0);
			k_sem_take(&client->coap_client_recv_sem, K_FOREVER);
=======

	k_sem_take(&coap_client_recv_sem, K_FOREVER);
	while (true) {
		atomic_set(&coap_client_recv_active, 1);
		ret = handle_poll();
		if (ret < 0) {
			/* Error in polling */
			LOG_ERR("Error in poll");
			goto idle;
		}

		for (int i = 0; i < num_clients; i++) {
			if (clients[i]->response_ready) {
				struct coap_packet response;

				ret = recv_response(clients[i], &response);
				if (ret < 0) {
					LOG_ERR("Error receiving response");
					clients[i]->response_ready = false;
					continue;
				}

				ret = handle_response(clients[i], &response);
				if (ret < 0) {
					LOG_ERR("Error handling response");
				}

				clients[i]->response_ready = false;
			}
		}

		/* There are more messages coming */
		if (has_ongoing_requests()) {
			continue;
		} else {
idle:
			atomic_set(&coap_client_recv_active, 0);
			k_sem_take(&coap_client_recv_sem, K_FOREVER);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		}
	}
}

int coap_client_init(struct coap_client *client, const char *info)
{
	if (client == NULL) {
		return -EINVAL;
	}

<<<<<<< HEAD
	client->fd = -1;
	k_sem_init(&client->coap_client_recv_sem, 0, 1);

	client->tid =
		k_thread_create(&client->thread, client->coap_thread_stack,
				K_THREAD_STACK_SIZEOF(client->coap_thread_stack),
				coap_client_recv, client, NULL, NULL,
				CONFIG_COAP_CLIENT_THREAD_PRIORITY, 0, K_NO_WAIT);

	if (IS_ENABLED(CONFIG_THREAD_NAME)) {
		if (info != NULL) {
			k_thread_name_set(client->tid, info);
		} else {
			k_thread_name_set(client->tid, "coap_client");
		}
	}

	return 0;
}
=======
	if (num_clients >= CONFIG_COAP_CLIENT_MAX_INSTANCES) {
		return -ENOSPC;
	}

	k_mutex_init(&client->send_mutex);

	clients[num_clients] = client;
	num_clients++;

	return 0;
}


K_THREAD_DEFINE(coap_client_recv_thread, CONFIG_COAP_CLIENT_STACK_SIZE,
		coap_client_recv, NULL, NULL, NULL,
		CONFIG_COAP_CLIENT_THREAD_PRIORITY, 0, 0);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
