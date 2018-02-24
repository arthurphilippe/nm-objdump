/*
** EPITECH PROJECT, 2018
** PSU_2017_nmobjdump
** File description:
** dump_setion_contents.
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "nmobjdump.h"
#include "print_byte.h"

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

static void print_line_offset(Elf64_Shdr *shdr, int section_idx)
{
	if (shdr->sh_addr + shdr->sh_size < 0xffff)
		printf(" %04x", (unsigned int) (shdr->sh_addr +
			section_idx));
	else
		printf(" %05x", (unsigned int) (shdr->sh_addr +
			section_idx));
}

void dump_section_contents(Elf64_Shdr *shdr, char *section)
{
	char translated_buff[17];
	size_t section_idx = 0;
	size_t i = 0;

	translated_buff[16] = 0;
	while (section_idx < shdr->sh_size) {
		print_line_offset(shdr, section_idx);
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
