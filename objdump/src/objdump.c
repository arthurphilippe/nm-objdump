/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** launch
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include "nmobjdump.h"
#include "section_is_to_print.h"

static void dump_mapped_object(elf_t *elf)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (section_is_to_print(elf, i)) {
			printf("Contents of section %s:\n",
				&elf->sh_string_table[
					elf->sh_table[i].sh_name]);
			dump_section_contents(&elf->sh_table[i],
						elf->addr
						+ elf->sh_table[i].sh_offset);
		}
		i += 1;
	}
}

int objdump(const char *file_name, const char *bin_name)
{
	void *map;
	int size = set_map_ptr(&map, file_name);
	int err;
	elf_t elf;

	if (size < RETURN_OK)
		return (nm_errors(size, bin_name, file_name));
	if ((err = elf_set_fields(&elf, map)) != RETURN_OK)
		return (nm_errors(err, bin_name, file_name));
	print_obj_header(&elf, file_name);
	dump_mapped_object(&elf);
	if (elf.ehdr->e_ident[EI_CLASS] == ELFCLASS32) {
		free(elf.ehdr);
		free(elf.sh_table);
	}
	munmap(elf.addr, size);
	return (0);
}
