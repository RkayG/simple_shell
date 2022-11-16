#include "shell.h"

/**
 * split_line - splits a string
 * @string: string to be split
 * Return: an array string bits
 */
char **split_line(char *string)
{
	char *delim = " \t\r\n";
	int buffsize = 64, i = 0;
	char **tokens = malloc(buffsize * sizeof(char *));
	char *token;
	/* check malloc */
	if (!tokens)
	{
		return (NULL);
		exit(98);
	}

	token = strtok(string, delim);

	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		if (i > buffsize)
		{
			buffsize += 64;
			tokens = realloc(tokens, buffsize);
			if (!tokens)
			{
				return (NULL);
				exit(98);
			}
		}
		token = strtok(NULL, delim);
	}
	tokens[i] = NULL;

	return (tokens);
}
