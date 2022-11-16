#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

/* global environment variable */
extern char **environ;

int execute(char *args[], char *argv[]);
char **split_line(char *string);
char *read_line(void);
void init_shell(char *argv[]);
int _strcmp(char *str1, char *str2);
int check_command(char **args, char *argv[0]);

/* builtins */
int sh_exit(char **args);
int sh_env(char **args);
int sh_cd(char **args);
int sh_num_builtins(void);

/* string array to call builtin commands */
static char *builtin_str[] = {"exit", "env", "cd"};
/**
 * builtin_func - pointer to builtin function
 * @char**: command string
 *
 * @builtin_func: executes builtin call
 */
static int (*builtin_func[])(char **) = {
	&sh_exit,
	&sh_env,
	&sh_cd
};

#endif /* SHELL_H */
