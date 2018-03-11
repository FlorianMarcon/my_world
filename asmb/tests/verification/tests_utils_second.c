/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_asm.h"
#include "my.h"
int	verification_name_and_comment(int fd);

Test(verification_name_and_comment, test5)
{
	int fd = open("data/data1.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name_and_comment(fd), 1);
		close(fd);
	}
}
Test(verification_name_and_comment, test6)
{
	int fd = open("data/data2.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name_and_comment(fd), 0);
		close(fd);
	}
}
Test(verification_name_and_comment, test7)
{
	int fd = open("data/data3.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name_and_comment(fd), 0);
		close(fd);
	}
}
Test(verification_name_and_comment, test8)
{
	int fd = open("../champion/flonflon.v.2.s", O_RDONLY);

	if (fd != -1) {
		cr_assert_eq(verification_name_and_comment(fd), 1);
		close(fd);
	}
}
