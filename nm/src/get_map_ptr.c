/*
** EPITECH PROJECT, 2018
** nm
** File description:
** map pointer
*/

#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdio.h>

int get_map_ptr(void **map, const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	struct stat sb;

	if (fd == -1 || fstat(fd, &sb) == -1) {
		perror(file_name);
		return (-1);
	}
	*map = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (*map == MAP_FAILED) {
		perror("mmap");
		return (-1);
	}
}
