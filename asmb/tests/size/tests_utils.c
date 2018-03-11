/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
int	size_function(char *str);
int	size_argument(char *str);
int	size_instruction(char **tab);

Test(size_function, test1)
{
	cr_assert_eq(size_function("live"), 1);
	cr_assert_eq(size_function("zjmp"), 1);
	cr_assert_eq(size_function("fork"), 1);
	cr_assert_eq(size_function("lfork"), 1);
	cr_assert_eq(size_function("ld"), 2);
}

Test(size_argument, test1)
{
	cr_assert_eq(size_argument("r1,r2,r3"), 3);
	cr_assert_eq(size_argument("r1,%2,2"), 7);
}

Test(size_instruction, test1)
{
	char *tab[] = {"live", "r1,%2,2", NULL};

	cr_assert_eq(size_instruction(tab), 8);
}
