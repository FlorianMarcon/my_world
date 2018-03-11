/*
** EPITECH PROJECT, 2017
** count_file_and_save_label
** File description:
** count_file_and_save_label
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "header_asm.h"
#include "my.h"
#include "op.h"
char	**parsing_str(char *str, char separator);
int	save_label(analyse_file_t *an, char *label);
int	is_label(char *str);

int	loop_save_label(char *str, analyse_file_t *an)
{
	char **tab = parsing_str(str, ' ' | '\t');
	char **re_tab = tab;

	if (is_label(tab[0])) {
		save_label(an, tab[0]);
		tab = &tab[1];
	}
	if (tab[0] == NULL) {
		an->count += 0;
	} else if (verification_instruction(tab) == 1) {
		an->count += size_instruction(tab);
	} else {
		free(re_tab);
		return (0);
	}
	free(re_tab);
	return (1);
}
analyse_file_t	*count_file_and_save_label(char *path)
{
	int fd = open(path, O_RDONLY);
	analyse_file_t *an = NULL;
	char *str = NULL;

	if (fd == -1 || verification_name_and_comment(fd) == 0)
		return (NULL);
	if ((an = malloc(sizeof(*an))) == NULL)
		return (NULL);
	an->label = NULL;
	an->count = 0;
	while ((str = get_next_instruction(fd)) != NULL) {
		if (loop_save_label(str, an) == 0) {
//			free(str);
			free(an);
			close(fd);
			return (NULL);
		}
//		free(str);
	}
	close(fd);
	return (an);
}
