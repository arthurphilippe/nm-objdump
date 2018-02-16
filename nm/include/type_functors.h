/*
** EPITECH PROJECT, 2018
** nm
** File description:
** functors
*/

#ifndef TYPE_FUNCTORS_H_
	#define TYPE_FUNCTORS_H_

	#include "nmobjdump.h"

char type_functor_common(elf_t *elf, Elf64_Sym *sym);
char type_functor_undef(elf_t *elf, Elf64_Sym *sym);
char type_functor_debug(elf_t *elf, Elf64_Sym *sym);
char type_functor_uninit(elf_t *elf, Elf64_Sym *sym);
char type_functor_text(elf_t *elf, Elf64_Sym *sym);
char type_functor_absolute(elf_t *elf, Elf64_Sym *sym);
char type_functor_rom(elf_t *elf, Elf64_Sym *sym);
char type_functor_init(elf_t *elf, Elf64_Sym *sym);
char type_functor_weak(elf_t *elf, Elf64_Sym *sym);

#endif /* !TYPE_FUNCTORS_H_ */
