/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "nmobjdump.h"

const int FAILURE = 1;
const int SUCCESS = 0;
const int RETURN_ERROR = -1;
const int RETURN_OK = 0;

void display(elf_t *elf)
{
	elf_symbol_t *list = get_symbol_list(elf);

	if (list) {
		print_list(list, (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32));
		symbol_list_destroy(list);
	}
}

int nm(const char *file_name)
{
	void *map;
	int size;
	elf_t elf;

	memset(&elf, 0, sizeof(elf_t));
	size = set_map_ptr(&map, file_name);
	if (size == RETURN_ERROR)
		return (RETURN_ERROR);
	if (elf_set_fields(&elf, map) != 0)
		return (RETURN_ERROR);
	if (!elf.string_table || !elf.sh_string_table)
		return (RETURN_OK);
	display(&elf);
	if (elf.ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
		free(elf.ehdr);
		free(elf.sh_table);
	}
	munmap(elf.addr, size);
	return (0);
}
