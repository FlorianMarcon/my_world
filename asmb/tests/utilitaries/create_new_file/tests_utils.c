/*
** EPITECH PROJECT, 2017
** tests_utils_second
** File description:
** tests_utils_second
*/

#include <criterion/criterion.h>
#include "header_asm.h"
#include "op.h"
int	create_new_file(char *path_old);
fd_t	*open_create_file(char *path);
char	*create_name_new_file(char *path_old);
int	field_header(header_t *h);

Test(create_new_file, test1)
{
	char *str = malloc(sizeof(char) * 4);

	str[0] = 'a';
	str[1] = '.';
	str[2] = 's';
	str[3] = '\0';
	cr_assert_eq(create_new_file(NULL), -1);
	cr_assert_neq(create_new_file(str), -1);
}
Test(create_name_new_file, test1)
{
	char *str = malloc(sizeof(char) * 4);
	char *new = NULL;

	str[0] = 'a';
	str[1] = '.';
	str[2] = 's';
	str[3] = '\0';
	new = create_name_new_file(str);
	cr_assert_str_eq(new, "a.cor");
}

Test(create_name_new_file, test2)
{
	char *str = malloc(sizeof(char) * 6);
	char *new = NULL;

	str[0] = 'a';
	str[1] = '/';
	str[2] = 'b';
	str[3] = '.';
	str[4] = 's';
	str[5] = '\0';
	new = create_name_new_file(str);

	cr_assert_str_eq(new, "b.cor");
}
