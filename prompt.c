#include "shell.h"

/**
 * prompt - procesa la linea de entrada,
 * crea un proceso hijo y ejecuta el comando ingresado.
 *
 * @line: linea de entrada del usuario (cadena de caracteres).
 *
 * Return: 0 en caso de exito.
 */
int prompt(char *line)
{
	char *argv[10]; /* Arreglo para almacenar los argumentos del comando */
	int i = 0; /* Contador para iterar sobre los argumentos */
	char *token; /* Puntero para almacenar cada segmento de la linea */

	token = strtok(line, " \n"); /* Divide la linea en tokens separados por espacio */
	while (token != NULL && i < 9) /* Itera mientras haya tokens y espacio en el arreglo */
	{
		argv[i++] = token; /* Guarda cada token en argv */
		token = strtok(NULL, " \n"); /* Obtiene el siguiente token en la linea */
	}
	argv[i] = NULL; /* Termina el arreglo con NULL como pide execvp */
	if (argv[0] == NULL) /* Si la lÃ­nea esta vacÃa, no hace nada */
		return (0);

	if (fork() == 0) /* Crea un proceso hijo para ejecutar el comando */
	{
		execvp(argv[0], argv); /* Proceso hijo: ejecuta el comando con sus argumentos */

		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]); /* Si falla, se muestra un error y termina el hijo */
		exit(127); /* Termina el proceso hijo con un codigo de fallo */
	}
	else /* Se ejecuta en el proceso padre */
	{
		wait(NULL); /* El padre espera a que el proceso hijo termine */
	}

	return (0);
}
