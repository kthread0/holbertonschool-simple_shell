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
	int status;
	pid_t child_pid;

	token = strtok(line, " \n");
	while (token != NULL && i < 9)
	{
		argv[i++] = token;
		token = strtok(NULL, " \n");
	}
	argv[i] = NULL;

	if (argv[0] == NULL)
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
			return WEXITSTATUS(status);
	}

	return (0);
}
