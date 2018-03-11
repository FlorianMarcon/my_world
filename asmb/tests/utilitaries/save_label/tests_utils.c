/*
** EPITECH PROJECT, 2017
** test
** File description:
** test
*/

#include <criterion/criterion.h>
#include "my.h"
#include "header_asm.h"
int	save_label(analyse_file_t *an, char *label);

Test(save_label, test1)
{
	analyse_file_t an = {.count = 0};
	label_t *l = NULL;

	cr_assert_eq(save_label(&an, "live:"), 1);
	cr_assert_neq(an.label, NULL);
	cr_assert_neq(an.label->data, NULL);
	cr_assert_eq(an.label->next, NULL);
	l =(label_t *)(an.label->data);
	cr_assert_str_eq(l->name, "live");
	cr_assert_eq(l->position, 0);
	cr_assert_eq(save_label(&an, "second:"), 1);
	l =(label_t *)(an.label->next->data);
	cr_assert_str_eq(l->name, "second");
	cr_assert_eq(l->position, 0);

}
