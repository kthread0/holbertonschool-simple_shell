#include "shell.h"

/**
 * exec_command - ejecuta un comando usando execvp y
 * maneja PATH vacio.
 * @argv: array de strings que representa los argumentos
 * del comando.
 *
 * Si PATH esta vacio y el comando no tiene '/', imprime
 * error y sale.
 */
static void exec_command(char **argv)
{
	char *path = getenv("PATH");

	if ((!path || path[0] == '\0') && strchr(argv[0], '/') == NULL)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		exit(127);
	}

	execvp(argv[0], argv);
	fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
	exit(127);
}

/**
 * prompt - procesa la linea de entrada,
 * crea un proceso hijo y ejecuta el comando ingresado.
 * @line: linea de entrada del usuario.
 *
 * Return: 0 en caso de exito.
 */
int prompt(char *line)
{
	char *argv[10], *token;
	int i = 0, status;
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
		exec_command(argv);

	waitpid(child_pid, &status, 0);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 0);
}
