/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "op.h"
#include "header_asm.h"
int	is_indirect(char *str);
int	which_variable(char *str);

Test(is_indirect, test1)
{
	cr_assert_eq(is_indirect("435"), 1);
	cr_assert_eq(is_indirect("-435"), 1);
	cr_assert_eq(is_indirect(":label"), 1);
	cr_assert_eq(is_indirect("label"), 0);
	cr_assert_eq(is_indirect(NULL), 0);
}

Test(which_variable, test1)
{
	cr_assert_eq(which_variable("435"), T_IND);
	cr_assert_eq(which_variable("%435"), T_DIR);
	cr_assert_eq(which_variable("r1"), T_REG);
	cr_assert_eq(which_variable("%:labe"), T_DIR);
	cr_assert_eq(which_variable("%labe"), 0);
}

Test(is_label_variable, test1)
{
	cr_assert_eq(is_label_variable("%:live"), 1);
	cr_assert_eq(is_label_variable("%live:"), 0);
	cr_assert_eq(is_label_variable(":live"), 0);
}
