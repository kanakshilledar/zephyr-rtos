/*
 * Copyright 2022 Meta
 *
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
=======
#include <zephyr/kernel.h>

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#include <thrift/concurrency/Mutex.h>

namespace apache
{
namespace thrift
{
namespace concurrency
{

<<<<<<< HEAD
Mutex::Mutex()
{
=======
class Mutex::impl
{
public:
	k_spinlock_key_t key;
	struct k_spinlock lock;
};

Mutex::Mutex()
{
	impl_ = std::make_shared<Mutex::impl>();
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

void Mutex::lock() const
{
<<<<<<< HEAD
=======
	while (!trylock()) {
		k_msleep(1);
	}
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

bool Mutex::trylock() const
{
<<<<<<< HEAD
	return false;
=======
	return k_spin_trylock(&impl_->lock, &impl_->key) == 0;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

bool Mutex::timedlock(int64_t milliseconds) const
{
<<<<<<< HEAD
=======
	k_timepoint_t end = sys_timepoint_calc(K_MSEC(milliseconds));

	do {
		if (trylock()) {
			return true;
		}
		k_msleep(5);
	} while(!sys_timepoint_expired(end));

>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	return false;
}

void Mutex::unlock() const
{
<<<<<<< HEAD
=======
	k_spin_unlock(&impl_->lock, impl_->key);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}

void *Mutex::getUnderlyingImpl() const
{
<<<<<<< HEAD
	return nullptr;
=======
	return &impl_->lock;
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
}
} // namespace concurrency
} // namespace thrift
} // namespace apache
