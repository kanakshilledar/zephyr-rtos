/*
 * Copyright (c) 2022 Nordic Semiconductor
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include "bstests.h"

extern struct bst_test_list *test_main_collision_install(struct bst_test_list *tests);
extern struct bst_test_list *test_main_autoconnect_install(struct bst_test_list *tests);
extern struct bst_test_list *test_main_reconfigure_install(struct bst_test_list *tests);
<<<<<<< HEAD
=======
extern struct bst_test_list *test_main_lowres_install(struct bst_test_list *tests);
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

bst_test_install_t test_installers[] = {
	test_main_collision_install,
	test_main_autoconnect_install,
	test_main_reconfigure_install,
<<<<<<< HEAD
=======
	test_main_lowres_install,
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
	NULL,
};

int main(void)
{
	bst_main();
	return 0;
}
