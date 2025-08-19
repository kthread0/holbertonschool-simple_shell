#include "shell.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Entry point of shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t input;

	while (1)
	{
		printf("Stranger Strings> "); /* Prompt */
		input = getline(&lineptr, &n, stdin);

		if (input == -1)
			break;

		if (lineptr[input - 1] == '\n')
			lineptr[input - 1] = '\0';

		if (strcmp(lineptr, "exit") == 0)
			break;

		if (lineptr[0] == '\0')
			continue;

		prompt(lineptr);
	}

	free(lineptr);
	return (0);
}
