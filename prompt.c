#include "shell.h"

/**
 * prompt - procesa la li≠nea de entada,
 * crea un proceso hijo y ejecuta el comando ingresado.
 *
 * @line: li≠nea de entrada del usuario(cadena de caracteres).
 *
 * Return: 0 en caso de e©xto
 */
int prompt(char *line)
{
	char *argv[10]; /* Arreglo para almacenar los argumentos del comando */
	int i = 0;
	char *token;

	/* Dividir la l√≠nea en tokens separados por espacio */
	token = strtok(line, " \n");
	while (token != NULL && i < 9)
	{
		argv[i++] = token;       /* Guardar cada token en argv */
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL; /* Terminar el arreglo con NULL como pide execvp */

	/* Crear un proceso hijo para ejecutar el comando */
	if (fork() == 0)
	{
		/* Proceso hijo: ejecutar el comando con sus argumentos */
		execvp(argv[0], argv);

		/* Si execvp falla, se muestra un error y termina el hijo */
		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* Proceso padre: esperar a que termine el hijo */
		wait(NULL);
	}

	return (0);
}
