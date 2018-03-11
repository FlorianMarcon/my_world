/*
** EPITECH PROJECT, 2017
** header_corewar
** File description:
** header_corewar
*/

#include "my.h"
#include <stdbool.h>
#include "op.h"

#ifndef COREWAR_
#define COREWAR_

#define QUART_MEMORY MEM_SIZE / 4

typedef struct corewar {
	linked_list_t *champion;
	int cycle_to_die;
	int cycle_delta;
	int nb_champion;
	int nbr_live;
	char memory[MEM_SIZE];
}corewar_t;

typedef struct champion {
	int pc;
	int r[REG_NUMBER];
	int carry;
	bool alive;
	int action_cycle;
	int life_cycle;

	// caractéristique
	char name[PROG_NAME_LENGTH + 1];
	int champion_number;
	char programme[MEM_SIZE / 6];
	int prog_size;
}champion_t;

int	corewar(int nb_champion, char **path);

// create_corewar

corewar_t	*create_corewar(int nb_champion, char **path);

int	fill_header(FILE *file, champion_t *champ, int nb);

int	fill_program(FILE *file, champion_t *champ);

linked_list_t	*create_list_champion(int nb_champion, char **path);

champion_t	*create_champion(int number, char *path);

// game

int	action_champion(corewar_t *core, champion_t *ch);

int	loop_game(corewar_t *core);

int	get_last_champion(corewar_t *core);

// utilitaries

void	integer_little_to_big_endian(int *nb);

void	short_little_to_big_endian(short *nb);

linked_list_t	*create_list(void *data);

void	destroy_list(linked_list_t *list);

int	*decoding_byte(char encode);

int	bite_correspondance(char var);

void	insert_program_in_core(corewar_t *core);

int	get_opcode_byte(champion_t *ch, corewar_t *core);

int	get_size_instruction(corewar_t *core, champion_t *ch);

int	get_size_argu_by_encoding_byte(corewar_t *core, champion_t *ch);

int	load_integer_variable(char *str);

short	load_short_variable(char *str);

int	load_value(corewar_t *core, champion_t *ch, int t, int var);

int	sti_instruction(corewar_t *core, champion_t *ch);

// ERROR MSG

#define MSG_NOT_FOUND_FILE "Not found file"

// instructions

int	live_instruction(corewar_t *core, champion_t *ch);

int	ld_instruction(corewar_t *core, champion_t *ch);

int	st_instruction(corewar_t *core, champion_t *ch);

int	add_instruction(corewar_t *core, champion_t *ch);

int	sub_instruction(corewar_t *core, champion_t *ch);

int	zjmp_instruction(corewar_t *core, champion_t *ch);

int	and_instruction(corewar_t *core, champion_t *ch);

int	or_instruction(corewar_t *core, champion_t *ch);

int	xor_instruction(corewar_t *core, champion_t *ch);

int	lld_instruction(corewar_t *core, champion_t *ch);

int	fork_instruction(corewar_t *core, champion_t *ch);

#endif
