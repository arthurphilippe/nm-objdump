/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#include <stdio.h>
#include "nmobjdump.h"

const char *EM_UKN = "unkownow arch";

void print_obj_header(elf_t *elf, const char *file_name)
{
	printf("%s    file format ", file_name);
	if (elf->ehdr->e_ident[EI_CLASS] == 1)
		printf("%s\n", "elf32-i386");
	else
		printf("%s\n", "elf64-x86-64");
	printf("architecture: %s", get_target_arch(elf->ehdr->e_machine));
	if (elf->ehdr->e_ident[EI_CLASS] == 2)
		printf(":x86-64 ");
	printf("%s%x\n\n", "flags: ", elf->ehdr->e_type);
	printf("start adress Ox%x016x\n\n", (unsigned int) elf->ehdr->e_entry);
}
