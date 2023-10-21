/*
 * Copyright (c) 2018 Intel Corporation.
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <zephyr/ztest.h>

#define FATFS_MNTP	"/RAM:"
<<<<<<< HEAD
=======
#define TEST_ROOT	FATFS_MNTP"/"
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
#define TEST_FILE	FATFS_MNTP"/testfile.txt"
#define TEST_DIR	FATFS_MNTP"/testdir"
#define TEST_DIR_FILE	FATFS_MNTP"/testdir/testfile.txt"

extern const char test_str[];

void *test_mount(void);
void test_unmount(void *unused);
