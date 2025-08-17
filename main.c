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

		/* Eliminar salto de línea al fina */
		if (lineptr[input - 1] == '\n')
			lineptr[input - 1] = '\0';

		/* Salir si el usuario escribe "exit" */
		if (strcmp(lineptr, "exit") == 0)
			break;

		/* Ignorar líneas vacía*/
		if (lineptr[0] == '\0')
			continue;

		/* Llamamos a prompt con la línea que el usuario escribi�*/
		prompt(lineptr);
	}

	free(lineptr);
	return (0);
}
