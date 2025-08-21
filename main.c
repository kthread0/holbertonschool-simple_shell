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
	/* Puntero para almacenar la linea leida del usuario */
	size_t n = 0;
	/* Variable para el tamaño del buffer de lineptr */
	ssize_t input;
	/* Variable para almacenar el numero de caracter leido */
	int last_status = 0;


	while (1)
		/* Bucle infinito para mantener el shell activo */
	{
		if (isatty(STDIN_FILENO))
			/* Verifica si la entrada estandar es un terminal*/
			fprintf(stderr, "Stranger Strings> "); 
		/* Prompt en stderr*/
		input = getline(&lineptr, &n, stdin);
		/* Lee la linea de entrada del usuario */

		if (input == -1)
			/* Verifica si hubo error o fin de archivo (EOF) al leer */
			break;
		/* EOF o error */

		if (lineptr[input - 1] == '\n')
			/* Eliminar salto de linea al final */
			lineptr[input - 1] = '\0';
		/* Reemplaza el salto de linea al final por un nulo */

		if (strcmp(lineptr, "exit") == 0)
		/* verifica si el comando ingresado es "exit" */
		{
			free(lineptr);
			/* libera la memoria asignada a lineptr */
			exit(last_status);
			/* termina el programa devolviendo el ultimo estado */
		}
		if (lineptr[0] == '\0')
			/* Comprueba si la linea esta vacia (primer caracter nulo) */
			continue;
		/* Salta a la siguiente iteracion del bucle */

		last_status = prompt(lineptr);
		/* Llamamos a prompt con la linea que el usuario escribe */
	}

	free(lineptr);
	/* Libera la memoria asignada a 'lineptr' */
	return (0);
}
