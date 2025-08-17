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
			break; /* EOF o error */

		/* Eliminar salto de li­nea al finl */
		if (lineptr[input - 1] == '\n')
			lineptr[input - 1] = '\0';

		/* Salir si el usuario escribe "exit" */
		if (strcmp(lineptr, "exit") == 0)
			break;

		/* Ignorar li­neas acias */
		if (lineptr[0] == '\0')
			continue;

		/* Llamamos a prompt con la li­nea que el usuario escrie */
		prompt(lineptr);
	}

	free(lineptr);
	return (0);
}
