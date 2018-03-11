/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <criterion/criterion.h>
#include "header_asm.h"
#include "my.h"

Test(get_next_instruction, test1)
{
	int fd = open("../champion/flonflon.v.2.s", O_RDONLY);
	char *str = NULL;

	if (fd == -1)
		return;
	str = get_next_instruction(fd);
	cr_assert_neq(str, NULL);
	cr_assert_str_eq(str, ".name \"flonflon V2\"");
	close(fd);
}
