/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main header
*/

#ifndef NM_H_
	#define NM_H_

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
int set_elf_fields(elf_t *elf, void *maped_file);
int elf_validate_format(elf_t *elf);

extern const int RETURN_ERROR;
extern const int EXIT_FAILURE;
extern const int EXIT_SUCCESS;

#endif /* !NM_H_ */
