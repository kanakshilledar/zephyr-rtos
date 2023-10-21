/*
 * Copyright (c) 2019 Linaro Limited
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#ifndef ZEPHYR_INCLUDE_POSIX_SYS_IOCTL_H_
#define ZEPHYR_INCLUDE_POSIX_SYS_IOCTL_H_

<<<<<<< HEAD
#define FIONBIO 0x5421
#define FIONREAD 0x541B
=======
#include <zephyr/sys/fdtable.h>

#define FIONBIO ZFD_IOCTL_FIONBIO
#define FIONREAD ZFD_IOCTL_FIONREAD
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

#ifdef __cplusplus
extern "C" {
#endif

int ioctl(int fd, unsigned long request, ...);

#ifdef __cplusplus
}
#endif

#endif /* ZEPHYR_INCLUDE_POSIX_SYS_IOCTL_H_ */
