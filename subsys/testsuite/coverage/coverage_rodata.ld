/*
 * Copyright (c) 2019 Intel Corporation
 * SPDX-License-Identifier: Apache-2.0
 */

<<<<<<< HEAD
. = ALIGN(4);
=======
#ifdef CONFIG_64BIT
. = ALIGN(8);
#else
. = ALIGN(4);
#endif
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d

PROVIDE_HIDDEN (__init_array_start = .);
KEEP (*(SORT(.init_array.*)))
KEEP (*(.init_array*))
PROVIDE_HIDDEN (__init_array_end = .);
