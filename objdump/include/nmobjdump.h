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

int objdump(const char *file_name);
int set_map_ptr(void **map, const char *file_name);
int elf_validate_format(elf_t *elf);
int elf_set_fields(elf_t *elf, void *maped_file);
void print_obj_header(elf_t *elf, const char *file_name);
const char *get_target_arch(int machine);

extern const int RETURN_ERROR;
extern const int RETURN_OK;
extern const int EXIT_FAILURE;
extern const int EXIT_SUCCESS;

#endif /* !OBJDUMP_H_ */
