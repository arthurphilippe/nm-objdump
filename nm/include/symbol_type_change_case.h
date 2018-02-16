/*
** EPITECH PROJECT, 2018
** nm
** File description:
** case change for typing
*/

#ifndef SYMBOL_TYPE_CHANGE_CASE_H_
	#define SYMBOL_TYPE_CHANGE_CASE_H_

	#include "nmobjdump.h"

inline static char symbol_type_change_case(Elf64_Sym *sym, char c)
{
	return (ELF64_ST_BIND(sym->st_info) == STB_LOCAL ? c : c - 32);
}

#endif /* !SYMBOL_TYPE_CHANGE_CASE_H_ */
