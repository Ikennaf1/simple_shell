#ifndef _HSH_
#define _HSH_

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>

int _putchar(char c);
void hsh_running();
void hsh_runnings();
int cmd_exists(char *cmd);
char **hsh_split_cmd(char *cmd);
int hsh_execute(char *path, char *buf, char **args);
char *_strdup(char *str);
unsigned int _strlen(char *s);
int _feof(int fd);
int read_chars(char *buf);
void set_path(char *path, char **args, char *buf);
void set_paths(char *path, char **args, char *buf);
int file_exists(char *filename, char *path);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
int is_built_in(char *cmd);
void run_built_in(char *cmd, char **args, char *buf, char *path);

/**
 * struct bi - Struct bi
 *
 * @cmd: The command
 * @func: Associated function
 */
typedef struct bi
{
	char *cmd;
	int (*func)(void);
} bi_t;

int env(void);
int _exit_(void);
int get_cmd_func(char *cmd);

#endif /* _HSH_ */
