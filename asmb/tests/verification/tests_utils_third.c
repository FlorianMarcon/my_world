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
#include <stdlib.h>
#include "header_asm.h"

Test(count_file_and_save_label, test1)
{
	analyse_file_t *an = count_file_and_save_label("data/flonflon.v.2.s");

	cr_assert_neq(an, NULL);
	cr_assert(an->count > 0);
	cr_assert_neq(an->label, NULL);
}

Test(count_file_and_save_label, test2)
{
	cr_assert_eq(count_file_and_save_label("data/bad_champion.s"), NULL);
}

Test(count_file_and_save_label, test3)
{
	cr_assert_eq(count_file_and_save_label("data/bad_champion_two.s"), NULL);
}
