/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#include <stdio.h>
#include "nmobjdump.h"

const char *EM_X86_64_NAME = "i386:x86-64";
const char *EM_X86_NAME = "i386:x86";
const char *EM_UKN = "unkownow arch";

void print_obj_header(elf_t *elf, const char *file_name)
{
	printf("%s    file format ", file_name);
	if (elf->ehdr->e_ident[EI_CLASS] == 1)
		printf("%s\n", "elf32-x86");
	else
		printf("%s\n", "elf64-x86-64");
	printf("architecture: ");
	if (elf->ehdr->e_machine == EM_X86_64)
		printf("%s, ", EM_X86_64_NAME);
	else if (elf->ehdr->e_machine == 0x03)
		printf("%s, ", EM_X86_NAME);
	else
		printf("%s, ", EM_UKN);
	printf("%s%x\n\n", "flags: ", elf->ehdr->e_flags);
}
