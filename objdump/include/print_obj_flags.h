/*
** EPITECH PROJECT, 2018
** objdump
** File description:
** flags
*/

#ifndef PRINT_OBJ_FLAGS_H_
	#define PRINT_OBJ_FLAGS_H_

	#include <stdio.h>

typedef struct	s_obj_flags{
	int	sum;
	int	exec_p;
	int	dynamic;
	int	has_reloc;
	int	has_lineno;
	int	has_debug;
	int	has_syms;
	int	has_locals;
	int	wp_text;
	int	d_paged;
}		obj_flags_t;

inline static void carry_print_str(char *str, int *carry)
{
	printf((*carry ? ", %s" : "%s"), str);
	if (!*carry)
		*carry = 1;
}

#endif /* !PRINT_OBJ_FLAGS_H_ */
