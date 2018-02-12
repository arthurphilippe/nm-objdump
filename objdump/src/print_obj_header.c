/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#include <stdio.h>
#include "nmobjdump.h"

static int print_has_syms(elf_t *elf, int carry)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_SYMTAB
			|| elf->sh_table[i].sh_type == SHT_DYNSYM) {
			printf(!carry ? "HAS_SYMS" : ", HAS_SYMS");
			return (1);
		}
		i += 1;
	}
	return (0);
}

static int print_d_paged(elf_t *elf, int carry)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_HASH
			|| elf->sh_table[i].sh_type == SHT_GNU_HASH) {
			printf(!carry ? "D_PAGED" : ", D_PAGED");
			return (1);
		}
		i += 1;
	}
	return (0);
}

static int print_type(elf_t *elf, int carry)
{
	if (elf->ehdr->e_type == ET_EXEC) {
		printf(!carry ? "EXEC_P" : ", EXEC_P");
		return (1);
	} else if (elf->ehdr->e_type == ET_DYN) {
		printf(!carry ? "DYNAMIC" : ", DYNAMIC");
		return (1);
	}
	return (0);
}

void print_obj_header(elf_t *elf, const char *file_name)
{
	int carry = 0;

	printf("\n%s:     file format ", file_name);
	if (elf->ehdr->e_ident[EI_CLASS] == 1)
		printf("%s\n", "elf32-i386");
	else
		printf("%s\n", "elf64-x86-64");
	printf("architecture: %s", get_target_arch(elf->ehdr->e_machine));
	if (elf->ehdr->e_ident[EI_CLASS] == 2)
		printf(":x86-64");
	printf("%s0x%08x:\n", ", flags ", elf->ehdr->e_type);
	carry = print_has_syms(elf, carry);
	carry = print_type(elf, carry);
	carry = print_d_paged(elf, carry);
	printf("\nstart address 0x%016x\n\n", (unsigned int) elf->ehdr->e_entry);
}
