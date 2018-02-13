/*
** EPITECH PROJECT, 2018
** nmobjdump
** File description:
** flags
*/

#include <stdio.h>
#include "nmobjdump.h"
#include "print_obj_flags.h"

// UNUSED SOURCE FILE

const int EXEC_P = 0x02;
const int DYNAMIC = 0x40;
const int HAS_RELOC = 0x01;
const int HAS_LINENO = 0x04;
const int HAS_DEBUG = 0x08;
const int HAS_SYMS = 0x10;
const int HAS_LOCALS = 0x20;
const int WP_TEXT = 0x80;
const int D_PAGED = 0x100;

const char *STR_EXEC_P = "EXEC_P";
const char *STR_DYNAMIC = "DYNAMIC";
const char *STR_HAS_RELOC = "HAS_RELOC";
const char *STR_HAS_LINENO = "HAS_LINENO";
const char *STR_HAS_DEBUG = "HAS_DEBUG";
const char *STR_HAS_SYMS = "HAS_SYMS";
const char *STR_HAS_LOCALS = "HAS_LOCALS";
const char *STR_WP_TEXT = "WP_TEXT";
const char *STR_D_PAGED = "D_PAGED";

char const * STR_TAB_FLAGS[] = {
	"EXEC_P",
	"DYNAMIC",
	"HAS_RELOC",
	"HAS_LINENO",
	"HAS_DEBUG",
};

static int set_has_syms(elf_t *elf, obj_flags_t *flags)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_SYMTAB
			|| elf->sh_table[i].sh_type == SHT_DYNSYM) {
			flags->has_syms = 1;
			flags->sum += HAS_SYMS;
			return;
		}
		i += 1;
	}
}

static int set_d_paged(elf_t *elf, obj_flags_t *flags)
{
	size_t i = 0;

	while (i < elf->ehdr->e_shnum) {
		if (elf->sh_table[i].sh_type == SHT_HASH
			|| elf->sh_table[i].sh_type == SHT_GNU_HASH) {
			flags->d_paged = 1;
			flags->sum += D_PAGED;
			return;
		}
		i += 1;
	}
}

static int set_type(elf_t *elf, obj_flags_t *flags)
{
	switch (elf->ehdr->e_type) {
		case ET_EXEC:
			flags->exec_p = 1;
			flags->sum += EXEC_P;
			break;
		case ET_DYN:
			flags->dynamic = 1;
			flags->sum += DYNAMIC;
			break;
		default:
			break;
	}
}

void set_obj_flags(elf_t *elf, obj_flags_t *flags)
{
	set_has_syms(elf, flags);
	set_d_paged(elf, flags);
	set_type(elf, flags);
}
