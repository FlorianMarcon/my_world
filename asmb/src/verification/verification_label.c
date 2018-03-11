/*
** EPITECH PROJECT, 2017
** verification_label
** File description:
** verification_label
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"

int	verify_label_is_present(linked_list_t *list, char *lab)
{
	label_t *node;

	if (is_label_variable(lab) == 0)
		return (1);
	lab = &lab[2];
	while (list != NULL) {
		node = (label_t *)list->data;
		if (my_strcmp(node->name, lab) == 0)
			return (1);
		list = list->next;
	}
	my_printf("ERROR LABEL \"%s\" is not present\n", lab);
	return (0);
}
int	verification_label(char *path, analyse_file_t *an)
{
	int fd = open(path, O_RDONLY);
	char *str = NULL;
	char **tab;
	char **arg;

	if (fd == -1)
		return (0);
	while ((str = get_next_instruction(fd)) != NULL) {
		tab = parsing_str(str, ' ' | '\t');
		arg = parsing_str(str, SEPARATOR_CHAR);
		for (unsigned int i = 0; arg[i] != NULL; i++) {
			if (verify_label_is_present(an->label, arg[i]) == 0)
				return (0);
		}
		free(arg);
		free(tab);
	}
	return (1);
}
