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
#include <unistd.h>
#include "errno.h"
#include "nmobjdump.h"

int set_map_ptr(void **map, const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	struct stat sb;

	if (fd == RETURN_ERROR || fstat(fd, &sb) == RETURN_ERROR) {
		if (errno == ENOENT)
			return (RETURN_ERR_STAT);
		else {
			perror(file_name);
			return (RETURN_ERROR);
		}
	}
	*map = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (*map == MAP_FAILED) {
		perror("mmap");
		return (RETURN_ERROR);
	}
	close(fd);
	return (sb.st_size);
}
