/*
** EPITECH PROJECT, 2018
** nmobjump
** File description:
** list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nmobjdump.h"

/*
** Swaps nodes if they are not ordered.
*/
int compare_and_swap_nodes(elf_symbol_t *node)
{
	char *tmp;
	Elf64_Addr tmp_contents;
	char tmp_type;

	if (symbol_cmp(node, node->next) > 0) {
		tmp = node->name;
		node->name = node->next->name;
		node->next->name = tmp;
		tmp_contents = node->contents;
		node->contents = node->next->contents;
		node->next->contents = tmp_contents;
		tmp_type = node->type;
		node->type = node->next->type;
		node->next->type = tmp_type;
		return (1);
	}
	return (0);
}

/*
** Creates a symbol node.
*/
elf_symbol_t *new_node(Elf64_Addr contents, char *name, char type)
{
	elf_symbol_t *new = malloc(sizeof(elf_symbol_t));

	if (!new) {
		perror("memory");
		return (NULL);
	}
	new->contents = contents;
	new->name = name;
	new->type = type;
	new->next = NULL;
	return (new);
}

/*
** Adds a symbol to the tail of the list.
*/
void symbol_list_pushback(elf_symbol_t **head, elf_symbol_t *symbol)
{
	elf_symbol_t *curr;

	if (!symbol)
		return;
	if (!*head) {
		*head = symbol;
		return;
	}
	curr = *head;
	while (curr->next)
		curr = curr->next;
	curr->next = symbol;
}

/*
** Frees the entiered list; recursivly.
*/
void symbol_list_destroy(elf_symbol_t *list)
{
	if (list->next)
		symbol_list_destroy(list->next);
	free(list);
}
