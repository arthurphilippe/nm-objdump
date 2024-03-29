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
#include "nmobjdump.h"
#include "nm_errors.h"

/*
** Maps a file into memory and sets a pointer to it.
*/
int set_map_ptr(void **map, const char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	struct stat sb;

	if (fd == RETURN_ERROR || fstat(fd, &sb) == RETURN_ERROR) {
		perror(file_name);
		return (RETURN_ERROR);
	}
	*map = mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	close(fd);
	if (*map == MAP_FAILED) {
		perror("mmap");
		return (RETURN_ERROR);
	}
	return (sb.st_size);
}
