#include "shell.h"

/**
 * main - calls other functions
 * @argc: argument count
 * @argv: argument variables
 * Return: always 0
 */

int main(int argc, char *argv[])
{
	(void) argc;
	init_shell(argv);

	return (0);
}
