#include "shell.h"

/**
 * parse_line - separa la linea de entrada en argumentos.
 * @line: linea de entrada.
 * @argv: array donde guardar los tokens.
 */
void parse_line(char *line, char **argv)
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
}

/**
 * exec_command - ejecuta un comando con manejo de PATH.
 * @argv: argumentos del comando.
 */
void exec_command(char **argv)
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
 * Return: 0 en caso de exito o el exit status del
 * comando.
 */
int prompt(char *line)
{
	char *argv[10];
	int status;
	pid_t child_pid;

	parse_line(line, argv);

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
