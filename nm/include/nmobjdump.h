/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main header
*/

#ifndef NMOBJDUMP_H_
	#define NMOBJDUMP_H_

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

int nm(const char *file_name);
int set_map_ptr(void **map, const char *file_name);
int elf_set_fields(elf_t *elf, void *maped_file);
int elf_validate_format(elf_t *elf);
int elf_populate_32bits(elf_t *elf);

extern const int RETURN_ERROR;
extern const int RETURN_OK;
extern const int FAILURE;
extern const int SUCCESS;

#endif /* !NMOBJDUMP_H_ */
