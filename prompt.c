#include "shell.h"

/**
 * token_input - separa la linea en tokens y llena argv
 * @line: linea de entrada
 * @argv: arreglo de punteros a tokens
 *
 * Return: numero de tokens encontrados
 */
int token_input(char *line, char **argv)
{
	char *token;
	int i = 0;

	token = strtok(line, " \n");
	while (token != NULL && i < 9)
	{
		argv[i++] = token;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	return (i);
}

/**
 * prompt - procesa la linea de entrada,
 * crea un proceso hijo y ejecuta el comando ingresado.
 * @line: linea de entrada del usuario (cadena de caracteres).
 *
 * Return: 0 en caso de exito.
 */
int prompt(char *line)
{
	char *argv[10];
	int argc, status;
	pid_t child_pid;

	argc = token_input(line, argv);
	if (argc == 0)
		return (0);

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		return (1);
	}

	if (child_pid == 0)
	{
		execvp(argv[0], argv);
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		exit(127);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}
