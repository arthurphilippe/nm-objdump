/*
** EPITECH PROJECT, 2018
** nm
** File description:
** pritnable
*/

#ifndef SYMBOL_IS_PRINTABLE_H_
	#define SYMBOL_IS_PRINTABLE_H_

	#include "nmobjdump.h"

inline static int symbol_is_printable(elf_t *elf, Elf64_Sym *st)
{
	return (elf->string_table[st->st_name]
		&& ELF64_ST_TYPE(st->st_info) != STT_FILE);
}

#endif /* !SYMBOL_IS_PRINTABLE_H_ */
