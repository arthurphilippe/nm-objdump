/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** launch
*/

#include <stdio.h>
#include <stddef.h>
#include "nmobjdump.h"
#include "section_is_to_print.h"
#include "print_byte.h"
#include <string.h>

const int EXIT_FAILURE = 1;
const int EXIT_SUCCESS = 0;
const int RETURN_ERROR = -1;
const int RETURN_OK = 0;

static int dump_sub_line(char *buffer, size_t tot_off,
				Elf64_Shdr *shdr, char *section)
{
	size_t i = 0;

	while (i < 4 && tot_off + i < shdr->sh_size) {
		buffer[i] = section[tot_off + i];
		i += 1;
	}
	return (i);
}

static void dump_section_contents(Elf64_Shdr *shdr, char *section)
{
	char translated_buff[17];
	size_t section_idx = 0;
	size_t i = 0;

	while (section_idx < shdr->sh_size) {
		printf(" %04x", (unsigned int) (shdr->sh_addr + section_idx));
		i = 0;
		while (i < 16 && section_idx + i < shdr->sh_size) {
			printf(" ");
			i += dump_sub_line(&translated_buff[i], i + section_idx,
						shdr, section);
		}
		translated_buff[16] = 0;
		printf(" %s\n", translated_buff);
		section_idx += i;
	}
}

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
