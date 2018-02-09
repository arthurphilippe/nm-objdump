/*
** EPITECH PROJECT, 2018
** nm
** File description:
** main header
*/

#ifndef NM_H_
	#define NM_H_

int nm(const char *file_name);
int set_map_ptr(void **map, const char *file_name);

extern const int RETURN_ERROR;
extern const int EXIT_FAILURE;
extern const int EXIT_SUCCESS;

#endif /* !NM_H_ */
