/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main header
*/

#ifndef NMOBJDUMP_H_
	#define NMOBJDUMP_H_

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

typedef struct			s_elf_symbol {
	Elf64_Addr		contents;
	char			*name;
	char			type;
	struct s_elf_symbol	*next;
}				elf_symbol_t;

typedef struct		s_err_map {
	const int	code;
	const char	*f_str;
}			err_map_t;

int nm(const char *file_name, int display, const char *bin_name);
int set_map_ptr(void **map, const char *file_name);
int elf_set_fields(elf_t *elf, void *maped_file);
int elf_validate_format(elf_t *elf);
int elf_populate_32bits(elf_t *elf);
void symbol_list_pushback(elf_symbol_t **head, elf_symbol_t *symbol);
elf_symbol_t *new_node(Elf64_Addr contents, char *name, char type);
void symbol_list_destroy(elf_symbol_t *list);
void list_symbols_from_systab(elf_t *elf, Elf64_Shdr *sh_symtab,
				Elf64_Sym *symtab, elf_symbol_t **head);
elf_symbol_t *get_symbol_list(elf_t *elf);
int compare_and_swap_nodes(elf_symbol_t *node);
void print_list(elf_symbol_t *list, int is_32bits);
char type_symbol(elf_t *elf, Elf64_Sym *sym);
int symbol_cmp(elf_symbol_t *s1, elf_symbol_t *s2);

int nm_errors(int code, const char *bin_name, const char *file_name);

#endif /* !NMOBJDUMP_H_ */
