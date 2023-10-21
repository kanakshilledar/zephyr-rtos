/*
 * Copyright (c) 2022 Rodrigo Peixoto <rodrigopex@gmail.com>
 * SPDX-License-Identifier: Apache-2.0
 */
#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/zbus/zbus.h>

LOG_MODULE_DECLARE(zbus, CONFIG_ZBUS_LOG_LEVEL);

<<<<<<< HEAD
K_MEM_SLAB_DEFINE_STATIC(_zbus_runtime_obs_pool, sizeof(struct zbus_observer_node),
			 CONFIG_ZBUS_RUNTIME_OBSERVERS_POOL_SIZE, 4);

struct k_mem_slab *zbus_runtime_obs_pool(void)
{
	return &_zbus_runtime_obs_pool;
}

=======
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
int zbus_chan_add_obs(const struct zbus_channel *chan, const struct zbus_observer *obs,
		      k_timeout_t timeout)
{
	int err;
	struct zbus_observer_node *obs_nd, *tmp;
<<<<<<< HEAD
	uint64_t end_ticks = sys_clock_timeout_end_calc(timeout);
=======
	struct zbus_channel_observation *observation;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	_ZBUS_ASSERT(!k_is_in_isr(), "ISR blocked");
	_ZBUS_ASSERT(chan != NULL, "chan is required");
	_ZBUS_ASSERT(obs != NULL, "obs is required");

<<<<<<< HEAD
	/* Check if the observer is already a static observer */
	for (const struct zbus_observer *const *static_obs = chan->observers; *static_obs != NULL;
	     ++static_obs) {
		if (*static_obs == obs) {
			return -EEXIST;
		}
	}

	err = k_mutex_lock(chan->mutex, timeout);
=======
	err = k_mutex_lock(&chan->data->mutex, timeout);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (err) {
		return err;
	}

<<<<<<< HEAD
	/* Check if the observer is already a runtime observer */
	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(chan->runtime_observers, obs_nd, tmp, node) {
		if (obs_nd->obs == obs) {
			k_mutex_unlock(chan->mutex);
=======
	for (int16_t i = chan->data->observers_start_idx, limit = chan->data->observers_end_idx;
	     i < limit; ++i) {
		STRUCT_SECTION_GET(zbus_channel_observation, i, &observation);

		__ASSERT(observation != NULL, "observation must be not NULL");

		if (observation->obs == obs) {
			k_mutex_unlock(&chan->data->mutex);

			return -EEXIST;
		}
	}

	/* Check if the observer is already a runtime observer */
	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(&chan->data->observers, obs_nd, tmp, node) {
		if (obs_nd->obs == obs) {
			k_mutex_unlock(&chan->data->mutex);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

			return -EALREADY;
		}
	}

<<<<<<< HEAD
	err = k_mem_slab_alloc(&_zbus_runtime_obs_pool, (void **)&obs_nd,
			       _zbus_timeout_remainder(end_ticks));

	if (err) {
		LOG_ERR("Could not allocate memory on runtime observers pool\n");

		k_mutex_unlock(chan->mutex);

		return err;
	}

	obs_nd->obs = obs;

	sys_slist_append(chan->runtime_observers, &obs_nd->node);

	k_mutex_unlock(chan->mutex);
=======
	struct zbus_observer_node *new_obs_nd = k_malloc(sizeof(struct zbus_observer_node));

	if (new_obs_nd == NULL) {
		LOG_ERR("Could not allocate observer node the heap is full!");

		k_mutex_unlock(&chan->data->mutex);

		return -ENOMEM;
	}

	new_obs_nd->obs = obs;

	sys_slist_append(&chan->data->observers, &new_obs_nd->node);

	k_mutex_unlock(&chan->data->mutex);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return 0;
}

int zbus_chan_rm_obs(const struct zbus_channel *chan, const struct zbus_observer *obs,
		     k_timeout_t timeout)
{
	int err;
	struct zbus_observer_node *obs_nd, *tmp;
	struct zbus_observer_node *prev_obs_nd = NULL;

	_ZBUS_ASSERT(!k_is_in_isr(), "ISR blocked");
	_ZBUS_ASSERT(chan != NULL, "chan is required");
	_ZBUS_ASSERT(obs != NULL, "obs is required");

<<<<<<< HEAD
	err = k_mutex_lock(chan->mutex, timeout);
=======
	err = k_mutex_lock(&chan->data->mutex, timeout);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	if (err) {
		return err;
	}

<<<<<<< HEAD
	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(chan->runtime_observers, obs_nd, tmp, node) {
		if (obs_nd->obs == obs) {
			sys_slist_remove(chan->runtime_observers, &prev_obs_nd->node,
					 &obs_nd->node);

			k_mem_slab_free(&_zbus_runtime_obs_pool, (void **)&obs_nd);

			k_mutex_unlock(chan->mutex);
=======
	SYS_SLIST_FOR_EACH_CONTAINER_SAFE(&chan->data->observers, obs_nd, tmp, node) {
		if (obs_nd->obs == obs) {
			sys_slist_remove(&chan->data->observers, &prev_obs_nd->node, &obs_nd->node);

			k_free(obs_nd);

			k_mutex_unlock(&chan->data->mutex);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

			return 0;
		}

		prev_obs_nd = obs_nd;
	}

<<<<<<< HEAD
	k_mutex_unlock(chan->mutex);
=======
	k_mutex_unlock(&chan->data->mutex);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	return -ENODATA;
}
