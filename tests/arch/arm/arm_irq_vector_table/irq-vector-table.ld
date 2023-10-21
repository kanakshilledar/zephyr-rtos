/* SPDX-License-Identifier: Apache-2.0 */

KEEP(*(_IRQ_VECTOR_TABLE_SECTION_SYMS))

/*
 * Some ARM platforms require this symbol to be placed after the IRQ vector
 * table (like STM32F0). The symbol defined here is overriding the one in
<<<<<<< HEAD
 * arch/arm/core/aarch32/vector_table.ld when the IRQ vector table is enabled.
=======
 * arch/arm/core/vector_table.ld when the IRQ vector table is enabled.
>>>>>>> 01478ffa5f76283e4556b4b7585875d50d82484d
 */
_vector_end = .;
