/*
** EPITECH PROJECT, 2018
** nm
** File description:
** section
*/

#ifndef SYMBOL_IS_FROM_SECTION_H_
	#define SYMBOL_IS_FROM_SECTION_H_

	#include "nmobjdump.h"
	#include "string.h"

inline static int symbol_is_from_section(Elf64_Sym *sym, elf_t *elf,
						const char *s)
{
	return (!strcmp(&(elf->sh_string_table)
			[elf->sh_table[sym->st_shndx].sh_name], s));
}

#endif /* !SYMBOL_IS_FROM_SECTION_H_ */
