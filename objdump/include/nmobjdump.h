/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** header
*/

#ifndef OBJDUMP_H_
	#define OBJDUMP_H_

	#include <elf.h>
	#define FAILURE 1
	#define SUCCESS 0
	#define RETURN_OK 0
	#define RETURN_ERROR -1
	#define DEFAULT_FILE_NAME "a.out"
	#define DISPLAY_NAME 1
	#define DONT_DISPLAY_NAME 0

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

typedef struct		s_err_map {
	const int	code;
	const char	*f_str;
}			err_map_t;

int objdump(const char *file_name, const char *bin_name);
int set_map_ptr(void **map, const char *file_name);
int elf_validate_format(elf_t *elf);
int elf_set_fields(elf_t *elf, void *maped_file);
void print_obj_header(elf_t *elf, const char *file_name);
const char *get_target_arch(int machine);
int elf_populate_32bits(elf_t *elf);
int nm_errors(int code, const char *bin_name, const char *file_name);
void dump_section_contents(Elf64_Shdr *shdr, char *section);

#endif /* !OBJDUMP_H_ */
