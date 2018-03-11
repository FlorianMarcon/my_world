/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"

Test(integer_little_to_big_endian, test1)
{
	int var = 15;
	int memory = var;
	char *varr;
	char *memm = (char *)(&memory);

	integer_little_to_big_endian(&var);
	varr = (char *)(&var);
	cr_assert_neq(var, memory);
	cr_assert_eq(varr[0], memm[3]);
	cr_assert_eq(varr[1], memm[2]);
	cr_assert_eq(varr[2], memm[1]);
	cr_assert_eq(varr[3], memm[0]);
}
Test(short_little_to_big_endian, test1)
{
	short var = 15;
	short memory = var;
	char *varr;
	char *memm = (char *)(&memory);

	short_little_to_big_endian(&var);
	varr = (char *)(&var);
	cr_assert_neq(var, memory);
	cr_assert_eq(varr[0], memm[1]);
	cr_assert_eq(varr[1], memm[0]);
}
