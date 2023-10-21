/*
 * Copyright (c) 2018 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/kernel.h>
#include <zephyr/spinlock.h>
#include <ksched.h>
<<<<<<< HEAD
#include <zephyr/timeout_q.h>
=======
#include <timeout_q.h>
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <zephyr/syscall_handler.h>
#include <zephyr/drivers/timer/system_timer.h>
#include <zephyr/sys_clock.h>

static uint64_t curr_tick;

static sys_dlist_t timeout_list = SYS_DLIST_STATIC_INIT(&timeout_list);

static struct k_spinlock timeout_lock;

#define MAX_WAIT (IS_ENABLED(CONFIG_SYSTEM_CLOCK_SLOPPY_IDLE) \
		  ? K_TICKS_FOREVER : INT_MAX)

<<<<<<< HEAD
/* Cycles left to process in the currently-executing sys_clock_announce() */
=======
/* Ticks left to process in the currently-executing sys_clock_announce() */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
static int announce_remaining;

#if defined(CONFIG_TIMER_READS_ITS_FREQUENCY_AT_RUNTIME)
int z_clock_hw_cycles_per_sec = CONFIG_SYS_CLOCK_HW_CYCLES_PER_SEC;

#ifdef CONFIG_USERSPACE
static inline int z_vrfy_sys_clock_hw_cycles_per_sec_runtime_get(void)
{
	return z_impl_sys_clock_hw_cycles_per_sec_runtime_get();
}
#include <syscalls/sys_clock_hw_cycles_per_sec_runtime_get_mrsh.c>
#endif /* CONFIG_USERSPACE */
#endif /* CONFIG_TIMER_READS_ITS_FREQUENCY_AT_RUNTIME */

static struct _timeout *first(void)
{
	sys_dnode_t *t = sys_dlist_peek_head(&timeout_list);

	return t == NULL ? NULL : CONTAINER_OF(t, struct _timeout, node);
}

static struct _timeout *next(struct _timeout *t)
{
	sys_dnode_t *n = sys_dlist_peek_next(&timeout_list, &t->node);

	return n == NULL ? NULL : CONTAINER_OF(n, struct _timeout, node);
}

static void remove_timeout(struct _timeout *t)
{
	if (next(t) != NULL) {
		next(t)->dticks += t->dticks;
	}

	sys_dlist_remove(&t->node);
}

static int32_t elapsed(void)
{
<<<<<<< HEAD
=======
	/* While sys_clock_announce() is executing, new relative timeouts will be
	 * scheduled relatively to the currently firing timeout's original tick
	 * value (=curr_tick) rather than relative to the current
	 * sys_clock_elapsed().
	 *
	 * This means that timeouts being scheduled from within timeout callbacks
	 * will be scheduled at well-defined offsets from the currently firing
	 * timeout.
	 *
	 * As a side effect, the same will happen if an ISR with higher priority
	 * preempts a timeout callback and schedules a timeout.
	 *
	 * The distinction is implemented by looking at announce_remaining which
	 * will be non-zero while sys_clock_announce() is executing and zero
	 * otherwise.
	 */
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return announce_remaining == 0 ? sys_clock_elapsed() : 0U;
}

static int32_t next_timeout(void)
{
	struct _timeout *to = first();
	int32_t ticks_elapsed = elapsed();
	int32_t ret;

	if ((to == NULL) ||
	    ((int64_t)(to->dticks - ticks_elapsed) > (int64_t)INT_MAX)) {
		ret = MAX_WAIT;
	} else {
		ret = MAX(0, to->dticks - ticks_elapsed);
	}

	return ret;
}

void z_add_timeout(struct _timeout *to, _timeout_func_t fn,
		   k_timeout_t timeout)
{
	if (K_TIMEOUT_EQ(timeout, K_FOREVER)) {
		return;
	}

#ifdef CONFIG_KERNEL_COHERENCE
	__ASSERT_NO_MSG(arch_mem_coherent(to));
#endif

	__ASSERT(!sys_dnode_is_linked(&to->node), "");
	to->fn = fn;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		struct _timeout *t;

		if (IS_ENABLED(CONFIG_TIMEOUT_64BIT) &&
		    Z_TICK_ABS(timeout.ticks) >= 0) {
			k_ticks_t ticks = Z_TICK_ABS(timeout.ticks) - curr_tick;

			to->dticks = MAX(1, ticks);
		} else {
			to->dticks = timeout.ticks + 1 + elapsed();
		}

		for (t = first(); t != NULL; t = next(t)) {
			if (t->dticks > to->dticks) {
				t->dticks -= to->dticks;
				sys_dlist_insert(&t->node, &to->node);
				break;
			}
			to->dticks -= t->dticks;
		}

		if (t == NULL) {
			sys_dlist_append(&timeout_list, &to->node);
		}

		if (to == first()) {
			sys_clock_set_timeout(next_timeout(), false);
		}
	}
}

int z_abort_timeout(struct _timeout *to)
{
	int ret = -EINVAL;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		if (sys_dnode_is_linked(&to->node)) {
			remove_timeout(to);
			ret = 0;
		}
	}

	return ret;
}

/* must be locked */
static k_ticks_t timeout_rem(const struct _timeout *timeout)
{
	k_ticks_t ticks = 0;

	if (z_is_inactive_timeout(timeout)) {
		return 0;
	}

	for (struct _timeout *t = first(); t != NULL; t = next(t)) {
		ticks += t->dticks;
		if (timeout == t) {
			break;
		}
	}

	return ticks - elapsed();
}

k_ticks_t z_timeout_remaining(const struct _timeout *timeout)
{
	k_ticks_t ticks = 0;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		ticks = timeout_rem(timeout);
	}

	return ticks;
}

k_ticks_t z_timeout_expires(const struct _timeout *timeout)
{
	k_ticks_t ticks = 0;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		ticks = curr_tick + timeout_rem(timeout);
	}

	return ticks;
}

int32_t z_get_next_timeout_expiry(void)
{
	int32_t ret = (int32_t) K_TICKS_FOREVER;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		ret = next_timeout();
	}
	return ret;
}

void sys_clock_announce(int32_t ticks)
{
	k_spinlock_key_t key = k_spin_lock(&timeout_lock);

	/* We release the lock around the callbacks below, so on SMP
	 * systems someone might be already running the loop.  Don't
	 * race (which will cause paralllel execution of "sequential"
	 * timeouts and confuse apps), just increment the tick count
	 * and return.
	 */
	if (IS_ENABLED(CONFIG_SMP) && (announce_remaining != 0)) {
		announce_remaining += ticks;
		k_spin_unlock(&timeout_lock, key);
		return;
	}

	announce_remaining = ticks;

<<<<<<< HEAD
	struct _timeout *t = first();
=======
	struct _timeout *t;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

	for (t = first();
	     (t != NULL) && (t->dticks <= announce_remaining);
	     t = first()) {
		int dt = t->dticks;

		curr_tick += dt;
		t->dticks = 0;
		remove_timeout(t);

		k_spin_unlock(&timeout_lock, key);
		t->fn(t);
		key = k_spin_lock(&timeout_lock);
		announce_remaining -= dt;
	}

	if (t != NULL) {
		t->dticks -= announce_remaining;
	}

	curr_tick += announce_remaining;
	announce_remaining = 0;

	sys_clock_set_timeout(next_timeout(), false);

	k_spin_unlock(&timeout_lock, key);

#ifdef CONFIG_TIMESLICING
	z_time_slice();
#endif
}

int64_t sys_clock_tick_get(void)
{
	uint64_t t = 0U;

<<<<<<< HEAD
	LOCKED(&timeout_lock) {
=======
	K_SPINLOCK(&timeout_lock) {
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
		t = curr_tick + elapsed();
	}
	return t;
}

uint32_t sys_clock_tick_get_32(void)
{
#ifdef CONFIG_TICKLESS_KERNEL
	return (uint32_t)sys_clock_tick_get();
#else
	return (uint32_t)curr_tick;
#endif
}

int64_t z_impl_k_uptime_ticks(void)
{
	return sys_clock_tick_get();
}

#ifdef CONFIG_USERSPACE
static inline int64_t z_vrfy_k_uptime_ticks(void)
{
	return z_impl_k_uptime_ticks();
}
#include <syscalls/k_uptime_ticks_mrsh.c>
#endif

<<<<<<< HEAD
void z_impl_k_busy_wait(uint32_t usec_to_wait)
{
	SYS_PORT_TRACING_FUNC_ENTER(k_thread, busy_wait, usec_to_wait);
	if (usec_to_wait == 0U) {
		SYS_PORT_TRACING_FUNC_EXIT(k_thread, busy_wait, usec_to_wait);
		return;
	}

#if !defined(CONFIG_ARCH_HAS_CUSTOM_BUSY_WAIT)
	uint32_t start_cycles = k_cycle_get_32();

	/* use 64-bit math to prevent overflow when multiplying */
	uint32_t cycles_to_wait = (uint32_t)(
		(uint64_t)usec_to_wait *
		(uint64_t)sys_clock_hw_cycles_per_sec() /
		(uint64_t)USEC_PER_SEC
	);

	for (;;) {
		uint32_t current_cycles = k_cycle_get_32();

		/* this handles the rollover on an unsigned 32-bit value */
		if ((current_cycles - start_cycles) >= cycles_to_wait) {
			break;
		}
	}
#else
	arch_busy_wait(usec_to_wait);
#endif /* CONFIG_ARCH_HAS_CUSTOM_BUSY_WAIT */
	SYS_PORT_TRACING_FUNC_EXIT(k_thread, busy_wait, usec_to_wait);
}

#ifdef CONFIG_USERSPACE
static inline void z_vrfy_k_busy_wait(uint32_t usec_to_wait)
{
	z_impl_k_busy_wait(usec_to_wait);
}
#include <syscalls/k_busy_wait_mrsh.c>
#endif /* CONFIG_USERSPACE */

/* Returns the uptime expiration (relative to an unlocked "now"!) of a
 * timeout object.  When used correctly, this should be called once,
 * synchronously with the user passing a new timeout value.  It should
 * not be used iteratively to adjust a timeout.
 */
uint64_t sys_clock_timeout_end_calc(k_timeout_t timeout)
{
	k_ticks_t dt;

	if (K_TIMEOUT_EQ(timeout, K_FOREVER)) {
		return UINT64_MAX;
	} else if (K_TIMEOUT_EQ(timeout, K_NO_WAIT)) {
		return sys_clock_tick_get();
	} else {

		dt = timeout.ticks;

		if (IS_ENABLED(CONFIG_TIMEOUT_64BIT) && Z_TICK_ABS(dt) >= 0) {
			return Z_TICK_ABS(dt);
		}
		return sys_clock_tick_get() + MAX(1, dt);
	}
=======
k_timepoint_t sys_timepoint_calc(k_timeout_t timeout)
{
	k_timepoint_t timepoint;

	if (K_TIMEOUT_EQ(timeout, K_FOREVER)) {
		timepoint.tick = UINT64_MAX;
	} else if (K_TIMEOUT_EQ(timeout, K_NO_WAIT)) {
		timepoint.tick = 0;
	} else {
		k_ticks_t dt = timeout.ticks;

		if (IS_ENABLED(CONFIG_TIMEOUT_64BIT) && Z_TICK_ABS(dt) >= 0) {
			timepoint.tick = Z_TICK_ABS(dt);
		} else {
			timepoint.tick = sys_clock_tick_get() + MAX(1, dt);
		}
	}

	return timepoint;
}

k_timeout_t sys_timepoint_timeout(k_timepoint_t timepoint)
{
	uint64_t now, remaining;

	if (timepoint.tick == UINT64_MAX) {
		return K_FOREVER;
	}
	if (timepoint.tick == 0) {
		return K_NO_WAIT;
	}

	now = sys_clock_tick_get();
	remaining = (timepoint.tick > now) ? (timepoint.tick - now) : 0;
	return K_TICKS(remaining);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

#ifdef CONFIG_ZTEST
void z_impl_sys_clock_tick_set(uint64_t tick)
{
	curr_tick = tick;
}

void z_vrfy_sys_clock_tick_set(uint64_t tick)
{
	z_impl_sys_clock_tick_set(tick);
}
#endif
