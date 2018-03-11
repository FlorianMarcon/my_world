/*
** EPITECH PROJECT, 2017
** instruction_is_valid
** File description:
** instruction_is_valid
*/

#include <criterion/criterion.h>
#include <stdio.h>
#include "my.h"

void	delete_commentary(char *str);
void	delete_inutile_space(char **str);
int	syntax_instruction_is_valid(char **msg);

Test(delete_commentary, test1)
{
	char str[] = "live r1,%:live,r2#salut ca va?";

	delete_commentary(str);
	cr_assert_str_eq(str, "live r1,%:live,r2");
}
Test(delete_commentary, test2)
{
	char str[] = "live r1,%:live,r2		 #salut ca va?";

	delete_commentary(str);
	cr_assert_str_eq(str, "live r1,%:live,r2");
	delete_commentary(str);
	cr_assert_str_eq(str, "live r1,%:live,r2");
}

Test(delete_inutile_space, test1)
{
	char str[] = "		live";
	char *msg = my_strcat(str, "\0");

	delete_inutile_space(&msg);
	cr_assert_str_eq(msg, "live");
	delete_inutile_space(&msg);
	cr_assert_str_eq(msg, "live");
}

Test(syntax_instruction_is_valid, test1)
{
	char str[] = "	live r1";
	char str2[] = "		#salut ca va ?";
	char *msg = my_strcat(str, "\0");
	char **tab = malloc(sizeof(*tab));

	cr_assert_eq(syntax_instruction_is_valid(&msg), 1);
	cr_assert_str_eq(msg, "live r1");
	cr_assert_eq(syntax_instruction_is_valid(NULL), -1);
	msg = my_strcat(str2, "\0");
	cr_assert_eq(syntax_instruction_is_valid(&msg), 0);
	*tab = NULL;
	cr_assert_eq(syntax_instruction_is_valid(tab), -1);
}
