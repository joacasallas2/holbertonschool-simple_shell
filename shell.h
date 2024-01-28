#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

int get_pid(void);
int print_av(int ac, char *av[]);
char *read_line(void);
char **tokenizer(char *line_ptr, char *delim);
void free_array(char **array);
pid_t _exec(char **commands, char **env);
char *get_path_exec(char *commands, char **env);
char **path_dir(char **env);
char *get_path(char **env);
void print_array(char **array);

#endif
