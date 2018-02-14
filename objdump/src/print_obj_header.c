/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#include <stdio.h>
#include "nmobjdump.h"

static void print_obj_flags(elf_t *elf)
{
	int	sum[ET_NUM];
	char	*flags_str[ET_NUM];

	flags_str[ET_NONE] = "";
	sum[ET_NONE] = 0x0;
	flags_str[ET_REL] = "HAS_RELOC, HAS_SYMS";
	sum[ET_REL] = 0x11;
	flags_str[ET_EXEC] = "EXEC_P, HAS_SYMS, D_PAGED";
	sum[ET_EXEC] = 0x112;
	flags_str[ET_DYN] = "HAS_SYMS, DYNAMIC, D_PAGED";
	sum[ET_DYN] = 0x150;
	flags_str[ET_CORE] = "";
	sum[ET_CORE] = 0x0;
	if (elf->ehdr->e_type < ET_NUM) {
		printf(", flags 0x%08x:\n", sum[elf->ehdr->e_type]);
		printf("%s\n", flags_str[elf->ehdr->e_type]);
	}
}

void print_obj_header(elf_t *elf, const char *file_name)
{
	printf("\n%s:     file format ", file_name);
	if (elf->ehdr->e_ident[EI_CLASS] == 1)
		printf("%s\n", "elf32-i386");
	else
		printf("%s\n", "elf64-x86-64");
	printf("architecture: %s", get_target_arch(elf->ehdr->e_machine));
	if (elf->ehdr->e_ident[EI_CLASS] == 2)
		printf(":x86-64");
	print_obj_flags(elf);
	if (elf->ehdr->e_ident[EI_CLASS] == ELFCLASS64)
		printf("start address 0x%016x\n\n",
			(unsigned int) elf->ehdr->e_entry);
	else
		printf("start address 0x%08x\n\n",
			(unsigned int) elf->ehdr->e_entry);
}
