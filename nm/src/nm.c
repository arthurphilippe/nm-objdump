/*
** EPITECH PROJECT, 2018
** nm
** File description:
** nm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include "nmobjdump.h"
#include "nm_errors.h"

void display(elf_t *elf, const char *file_name)
{
	elf_symbol_t *list = get_symbol_list(elf);

	if (list) {
		if (file_name)
			printf("\n%s:\n", file_name);
		if (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS32)
			print_list32(list);
		else
			print_list64(list);
		symbol_list_destroy(list);
	}
}

int nm(const char *file_name, int display_file_name, const char *bin_name)
{
	void *map;
	int size = set_map_ptr(&map, file_name);
	int err;
	elf_t elf;

	if (size < RETURN_OK)
		return (nm_errors(size, bin_name, file_name));
	if ((err = elf_set_fields(&elf, map)) != RETURN_OK)
		return (nm_errors(err, bin_name, file_name));
	if (!elf.string_table || !elf.sh_string_table)
		return (nm_errors(RETURN_ERR_NO_SYMS, bin_name, file_name));
	display(&elf, (display_file_name) ? file_name : NULL);
	if (elf.ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
		free(elf.ehdr);
		free(elf.sh_table);
	}
	munmap(elf.addr, size);
	return (0);
}
