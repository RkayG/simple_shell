#include "shell.h"

/**
 * sh_num_builtins - gets the length of builtin_str
 * Return: length
 */
int sh_num_builtins(void)
{
	return (sizeof(builtin_str) / sizeof(char *));
}
/**
 * sh_exit - exits shell upon 'exit' call
 * @args: command arguments
 * Return: 0
 */
int sh_exit(char **args)
{
	exit(0);
}
/**
 * sh_env - prints env upon 'env' call
 * @args: command arguments
 * Return: 1
 */
int sh_env(char **args)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (1);
}
/**
 * sh_cd - changes cwd upon 'cd' call
 * @args: commad arguments
 * Return: 1
 */
int sh_cd(char **args)
{
	char *home;

	if (!args[1])
	{
		home = getenv("HOME");
		chdir(home);
	}
	else
	{
		if (chdir(args[1]) != 0)
			perror("Error :");
	}
	return (1);
}

