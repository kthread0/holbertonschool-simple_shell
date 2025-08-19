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
	char *lineptr = NULL; /* Puntero para almacenar la linea leida del usuario */
	size_t n = 0; /* Variable para el tamaÃo del buffer de lineptr */
	ssize_t input; /* Variable para almacenar el numero de caracter leido */



	while (1) /* Bucle infinito para mantener el shell activo */
	{
			printf("Stranger Strings> "); /* Prompt */
		
		input = getline(&lineptr, &n, stdin); /* Lee la linea de entrada del usuario */

		if (input == -1) /* Verifica si hubo error o fin de archivo (EOF) al leer */
			break; /* EOF o error */

		if (lineptr[input - 1] == '\n') /* Eliminar salto de linea al final */
			lineptr[input - 1] = '\0'; /* Reemplaza el salto de linea al final por un nulo */

		if (strcmp(lineptr, "exit") == 0) /* Compara si la entrada es "exit" */
			break; /* Sale del bucle si el usuario escribio "exit" */

		if (lineptr[0] == '\0') /* Comprueba si la linea esta vacia (primer caracter nulo) */
			continue; /* Salta a la siguiente iteracion del bucle */

		prompt(lineptr); /* Llamamos a prompt con la linea que el usuario escribe */
	}

	free(lineptr); /* Libera la memoria asignada a 'lineptr' */
	return (0);
}
