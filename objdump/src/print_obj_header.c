/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#include <stdio.h>
#include "nmobjdump.h"

const int HAS_RELOC = 0x01;
const int EXEC_P = 0x02;
const int HAS_LINENO = 0x04;
const int HAS_DEBUG = 0x08;
const int HAS_SYMS = 0x10;
const int HAS_LOCALS = 0x20;
const int DYNAMIC = 0x40;
const int WP_TEXT = 0x80;
const int D_PAGED = 0x100;

static int print_has_syms(elf_t *elf, int carry, int *flags)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_SYMTAB
			|| elf->sh_table[i].sh_type == SHT_DYNSYM) {
			*flags += HAS_SYMS;
			if (carry == -1)
				return (1);
			printf(!carry ? "HAS_SYMS" : ", HAS_SYMS");
			return (1);
		}
		i += 1;
	}
	return (0);
}

static int print_d_paged(elf_t *elf, int carry, int *flags)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_HASH
			|| elf->sh_table[i].sh_type == SHT_GNU_HASH) {
			*flags += D_PAGED;
			if (carry == -1)
				return (1);
			printf(!carry ? "D_PAGED" : ", D_PAGED");
			return (1);
		}
		i += 1;
	}
	return (0);
}

static int print_type(elf_t *elf, int carry, int *flags)
{
	if (elf->ehdr->e_type == ET_EXEC) {
		*flags += EXEC_P;
		if (carry == -1)
			return (1);
		printf(!carry ? "EXEC_P" : ", EXEC_P");
		return (1);
	} else if (elf->ehdr->e_type == ET_DYN) {
		*flags += DYNAMIC;
		if (carry == -1)
			return (1);
		printf(!carry ? "DYNAMIC" : ", DYNAMIC");
		return (1);
	}
	return (0);
}

void print_obj_header(elf_t *elf, const char *file_name)
{
	int carry = 0;
	int flags = 0;

	printf("\n%s:     file format ", file_name);
	if (elf->ehdr->e_ident[EI_CLASS] == 1)
		printf("%s\n", "elf32-i386");
	else
		printf("%s\n", "elf64-x86-64");
	printf("architecture: %s", get_target_arch(elf->ehdr->e_machine));
	if (elf->ehdr->e_ident[EI_CLASS] == 2)
		printf(":x86-64");
	print_has_syms(elf, -1, &flags);
	print_type(elf, -1, &flags);
	print_d_paged(elf, -1, &flags);
	printf("%s0x%08x:\n", ", flags ", flags);
	carry = print_has_syms(elf, carry, &flags);
	carry = print_type(elf, carry, &flags);
	carry = print_d_paged(elf, carry, &flags);
	printf("\nstart address 0x%016x\n\n", (unsigned int) elf->ehdr->e_entry);
}
