/*
** op.c for  korewar
**
** Made by Astek
** Login   <astek@epitech.net>
**
** Started on  Mon Mar 30 11:14:31 2009 Astek
** Last update Sat Mar 10 23:27:56 2018 Marcon
*/

#include "op.h"

op_t    op_tab[] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", NULL},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", NULL},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", NULL},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", NULL},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", NULL},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
	"et (and  r1, r2, r3   r1&r2 -> r3", NULL},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
	"ou  (or   r1, r2, r3   r1 | r2 -> r3", NULL},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
	"ou (xor  r1, r2, r3   r1^r2 -> r3", NULL},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", NULL},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
	"load index", NULL},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
	"store index", NULL},
	{"fork", 1, {T_DIR}, 12, 800, "fork", NULL},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", NULL},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
	"long load index", NULL},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", NULL},
	{"aff", 1, {T_REG}, 16, 2, "aff", NULL},
	{0, 0, {0}, 0, 0, 0, NULL}
};
