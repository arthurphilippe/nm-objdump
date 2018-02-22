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

inline static int symbol_is_from_section(Elf64_Sym *y, elf_t *e,
						const char *s)
{
	int r;

	r = !strcmp(&(e->sh_string_table)[e->sh_table[y->st_shndx].sh_name],
			s);
	return (r);
}

#endif /* !SYMBOL_IS_FROM_SECTION_H_ */
