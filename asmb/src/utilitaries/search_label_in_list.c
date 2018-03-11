/*
** EPITECH PROJECT, 2017
** search_label_in_list
** File description:
** search_label_in_list
*/

#include "header_asm.h"

label_t	*search_label_in_list(analyse_file_t *an, char *str)
{
	linked_list_t *list = an->label;
	label_t *lab;

	while (list != NULL) {
		if (list->data != NULL) {
			lab = (label_t *)list->data;
			if (my_strcmp(lab->name, str) == 0)
				return (lab);
		}
		list = list->next;
	}
	return (NULL);
}
