/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
** print_symbols
*/

#include <stdio.h>
#include "nmobjdump.h"

/*
** Prints the symbols using 32 bits format.
*/
void print_list32(elf_symbol_t *list)
{
	while (list) {
		if (list->type != 'w' && list->type != 'U') {
			printf("%08lx %c %s\n", list->contents, list->type,
				list->name);
		}
		else
			printf("         %c %s\n", list->type,
				list->name);
		list = list->next;
	}
}

/*
** Prints the symbols using 64 bits format.
*/
void print_list64(elf_symbol_t *list)
{
	while (list) {
		if (list->type != 'w' && list->type != 'U')
			printf("%016lx %c %s\n", list->contents, list->type,
				list->name);
		else
			printf("                 %c %s\n", list->type,
				list->name);
		list = list->next;
	}
}
