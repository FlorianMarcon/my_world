/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"
#include "my.h"
int	verify_file_name(char *path);

Test(verify_file_name, test1)
{
	cr_assert_neq(verify_file_name("data/file.s"), -1);
	cr_assert_neq(verify_file_name("data/file.s"), -1);
	cr_assert_eq(verify_file_name("data/bad_file.sadez"), -1);
	cr_assert_eq(verify_file_name("data/bad_file_2.saas"), -1);
	cr_assert_eq(verify_file_name(".s"), -1);
}
