/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

	#include <elf.h>

typedef struct		s_elf {
	char		*addr;
	Elf64_Ehdr	*ehdr;
	Elf64_Shdr	*sh_table;
	char		*sh_string_table;
	char		*string_table;
}			elf_t;

typedef struct		s_elf_symbol {
	Elf64_Addr	contents;
	char		*name;
	char		type;
}			elf_symbol_t;

extern const int RETURN_ERROR;
extern const int RETURN_OK;
extern const int EXIT_FAILURE;
extern const int EXIT_SUCCESS;


#endif /* !OBJDUMP_H_ */
