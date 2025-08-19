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
	char *argv[10];
	int i = 0;
	char *token;

	token = strtok(line, " \n");
	while (token != NULL && i < 9)
	{
		argv[i++] = token;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;
	if (fork() == 0)
	{
		execvp(argv[0], argv);

		perror("execvp failed");
		exit(EXIT_FAILURE);
	}
	else
	{
		wait(NULL);
	}

	return (0);
}
