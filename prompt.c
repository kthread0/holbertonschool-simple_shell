#include "shell.h"

/**
 * exec_command - ejecuta un comando usando execvp.
 * @argv: array de strings con los argumentos del comando.
 */
static void exec_command(char **argv)
{
	execvp(argv[0], argv);
	fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
	exit(127);
}

/**
 * command_exists - verifica si un comando existe en
 * PATH o como ruta absoluta.
 * @cmd: comando ingresado.
 *
 * Return: 1 si existe, 0 si no existe.
 */
int command_exists(const char *cmd)
{
	char *path, *token, *copy;
	char fullpath[PATH_MAX];

	if (strchr(cmd, '/') != NULL)
		return (access(cmd, X_OK) == 0);

	path = getenv("PATH");
	if (!path || path[0] == '\0')
		return (0);

	copy = strdup(path);
	if (!copy)
		return (0);

	token = strtok(copy, ":");
	while (token != NULL)
	{
		snprintf(fullpath, sizeof(fullpath), "%s/%s", token, cmd);
		if (access(fullpath, X_OK) == 0)
		{
			free(copy);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(copy);
	return (0);
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

	if (!command_exists(argv[0]))
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}

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
