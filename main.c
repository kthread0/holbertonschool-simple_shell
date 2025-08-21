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
	int last_status = 0;


	while (1)
	{
		if (isatty(STDIN_FILENO))
			fprintf(stderr, "Stranger Strings> "); 
		input = getline(&lineptr, &n, stdin);

		if (input == -1)
			break;

		if (lineptr[input - 1] == '\n')
			lineptr[input - 1] = '\0';

		if (strcmp(lineptr, "exit") == 0)
		{
			free(lineptr);
			exit(last_status);

		}
		if (lineptr[0] == '\0')
			continue;

		last_status = prompt(lineptr);
	}

	free(lineptr);
	return (0);
}
