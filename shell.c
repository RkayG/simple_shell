#include "shell.h"

/**
 * init_shell - initializes shell prompt
 * @argv: argument variables
 */
void init_shell(char *argv[])
{
	while(1)
	{
		printf("($) ");
		char *string = read_line();
		char **args = split_line(string);

		check_command(args, argv);

		free(string);
		free(args);
	}
}

