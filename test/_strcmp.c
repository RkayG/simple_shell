#include "shell.h"

/**
 * _strcmp - compares two strings
 * @str1: first string
 * @str2: second string
 * Return: 0 if strings are equal; otherwise number greater than 0 if unequal
 */

int _strcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			break;
	/* move to next characters */
		str1++;
		str2++;
	}
	/* return difference after converting char* to unsigned char* */
	return (*(const unsigned char *)str1 - *(const unsigned char *)str2);
}

