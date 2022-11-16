#include "shell.h"
/**
 * execute - executes command arguments
 * @args: array of command arguments
 * @argv: executable filename - used for error
 * Return: 1 on success.
 */

int execute(char *args[], char *argv[0])
{
	pid_t cpid;
	int status = 1;

	cpid = fork();

	if (cpid == 0)
	{
		if (execve(args[0], args, NULL) < 0)
		{
			printf("%s: No such file or directory\n", argv[0]);
			exit(98);
		}
	}
	else if (cpid < 0)
	{
		printf("Error :\n");
	}
	else
	{
		waitpid(cpid, &status, WUNTRACED);
	}
	return (1);
}

/**
 *check_command - checks if a command is a builtin or a program
 * @args: command arguments
 * @argv: executable filename - just used for error
 * Return: a pointer to a builtin func if command is a builtin;
 * otherwise, the value of execute func is returned
 */
int check_command(char **args, char *argv[0])
{
	int i;

	if (args[0] == NULL)
		/* empty command */
		return (1);
	for (i = 0; i < sh_num_builtins(); i++)
	{
		if (_strcmp(args[0], builtin_str[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (execute(args, argv));
}

