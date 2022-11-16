#include "shell.h"

/**
 * read_line - reads charactera from stdout
 *
 * Return: input string
 */

char *read_line(void)
{
	char *buffer;
	char *string;
	size_t bufsize = 1024;
	int length;
	int i = 0;

	buffer = malloc(bufsize * sizeof(char));
	/* check if malloc was successful */
	if (!buffer)
	{
		return (NULL);
		exit(98);
	}
	length = getline(&buffer, &bufsize, stdin);
	/* exit with ctrl+D */
	if (length < 0)
	{
		printf("\n");
		exit(98);
	}

	string = malloc((length) * sizeof(char));
	/* check malloc */
	if (!string)
	{
		return (NULL);
		exit(99);
	}
	/* copy buffer to string, removing new line */
	for (i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
	{
		string[i] = buffer[i];
	}

	free(buffer);
	return (string);
}

