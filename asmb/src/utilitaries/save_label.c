/*
** EPITECH PROJECT, 2017
** save_label
** File description:
** save_label
*/

#include <stdlib.h>
#include "my.h"
#include "header_asm.h"
char	*my_strndup(char *str, int n);

int	save_label(analyse_file_t *an, char *label)
{
	label_t *l = malloc(sizeof(*l));

	if (l == NULL)
		return (0);
	l->name = my_strndup(label, my_strlen(label) - 1);
	l->position = an->count;
	if (an->label == NULL) {
		if ((an->label = malloc(sizeof(linked_list_t))) == NULL) {
			free(l);
			return (0);
		}
		an->label->next = NULL;
		an->label->data = l;
	} else {
		create_node(an->label, l);
	}
	return (1);
}
