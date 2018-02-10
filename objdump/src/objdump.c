/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** launch
*/

#include <stdio.h>
#include <stddef.h>
#include "nmobjdump.h"
#include <string.h>

const int EXIT_FAILURE = 1;
const int EXIT_SUCCESS = 0;
const int RETURN_ERROR = -1;
const int RETURN_OK = 0;

static void dump_mapped_object(elf_t *elf)
{
	size_t i = 0;
	void *curr_section = (char *) elf->addr + elf->sh_table[i].sh_offset;

	while (i < elf->ehdr->e_shentsize
		&& curr_section != elf->sh_string_table
		&& strcmp(&elf->sh_string_table[elf->sh_table[i].sh_name],
				".strtab")) {
		if (elf->sh_table[i].sh_type != SHT_SYMTAB
			&& elf->sh_table[i].sh_type != SHT_NOBITS
			&& elf->sh_string_table[elf->sh_table[i].sh_name]) {
			printf("Contents of section %s:\n",
			&elf->sh_string_table[elf->sh_table[i].sh_name]);
		}
		curr_section = (char *) elf->addr + elf->sh_table[i].sh_offset;
		i += 1;
	}
}

int objdump(const char *file_name)
{
	void *map;
	int size;
	elf_t elf;

	size = set_map_ptr(&map, file_name);
	if (size == RETURN_ERROR)
		return (RETURN_ERROR);
	if (elf_set_fields(&elf, map) != 0)
		return (RETURN_ERROR);
	dump_mapped_object(&elf);
	return (0);
}
