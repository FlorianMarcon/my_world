/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "header_asm.h"
#include "my.h"
linked_list_t	*create_list_test(void);

Test(search_label_in_list, test1)
{
	analyse_file_t an = {.label = create_list_test()};

	cr_assert_neq(search_label_in_list(&an, "live"), NULL);
	cr_assert_eq(search_label_in_list(&an, "malicoumsalam"), NULL);
}
