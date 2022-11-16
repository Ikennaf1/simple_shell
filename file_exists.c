#include "shell.h"

/**
 * file_exists - Checkes if file exists
 * @filename: Given file name
 * @path: Given file path
 * Return: 1 or 0
 */
int file_exists(char *filename, char *path)
{
	struct dirent *parent_directory;
	DIR *p_dir;

	if (filename == NULL || path == NULL)
		return (-1);

	p_dir = opendir(path);
	if (p_dir == NULL)
	{
		printf("Cannot open directory %s\n", path);
		return (-1);
	}

	while ((parent_directory = readdir(p_dir)) != NULL)
	{
		if (_strcmp(parent_directory->d_name, filename) == 0)
			return (1);
	}
	closedir(p_dir);
	return (0);
}
