/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** launch
*/

#include <string.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>
#include "nmobjdump.h"
#include "section_is_to_print.h"
#include "print_byte.h"

const int FAILURE = 1;
const int SUCCESS = 0;
const int RETURN_ERROR = -1;
const int RETURN_OK = 0;

static int dump_sub_line(char *buffer, size_t tot_off,
				Elf64_Shdr *shdr, char *section)
{
	size_t i = 0;

	while (i < 4 && tot_off + i < shdr->sh_size) {
		buffer[i] = print_byte(section[tot_off + i]);
		i += 1;
	}
	return (i);
}

static void fill_out_empty_space(size_t printed)
{
	size_t nb_block = (16 - printed) / 4;
	size_t nb_char = (16 - printed) * 2;
	char *spaces_str = "                                        ";

	fflush(stdout);
	write(1, spaces_str, nb_char + nb_block);
}

static void dump_section_contents(Elf64_Shdr *shdr, char *section)
{
	char translated_buff[17];
	size_t section_idx = 0;
	size_t i = 0;

	translated_buff[16] = 0;
	while (section_idx < shdr->sh_size) {
		printf(" %04x", (unsigned int) (shdr->sh_addr + section_idx));
		memset(translated_buff, ' ', 16);
		i = 0;
		while (i < 16 && section_idx + i < shdr->sh_size) {
			printf(" ");
			i += dump_sub_line(&translated_buff[i], i + section_idx,
						shdr, section);
		}
		if (i != 16)
			fill_out_empty_space(i);
		printf("  %s\n", translated_buff);
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
	print_obj_header(&elf, file_name);
	dump_mapped_object(&elf);
	return (0);
}
