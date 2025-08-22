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
 * find_command - busca la ruta completa de un comando en PATH
 * @cmd: comando (argv[0])
 *
 * Return: ruta completa (malloc) o NULL si no se encontro
 */
char *find_command(char *cmd)
{
	char *path, *dup, *dir, *full_path;
	size_t len;

	if (strchr(cmd, '/'))
		return (strdup(cmd));

	path = getenv("PATH");
	if (!path || path[0] == '\0')
		return (NULL);

	dup = strdup(path);
	if (!dup)
		return (NULL);

	dir = strtok(dup, ":");
	while (dir)
	{
		len = strlen(dir) + strlen(cmd) + 2;
		full_path = malloc(len);
		if (full_path)
		{
			snprintf(full_path, len, "%s/%s", dir, cmd);
			if (access(full_path, X_OK) == 0)
			{
				free(dup);
				return (full_path);
			}
			free(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(dup);
	return (NULL);
}

/**
 * execute_child - ejecuta un comando en un proceso hijo
 * @cmd_path: ruta del comando
 * @argv: argumentos
 *
 * Return: status del proceso hijo
 */
int execute_child(char *cmd_path, char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork failed");
		free(cmd_path);
		return (1);
	}

	if (child_pid == 0)
	{
		execve(cmd_path, argv, environ);
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		free(cmd_path);
		exit(127);
	}
	else
	{
		waitpid(child_pid, &status, 0);
		free(cmd_path);

		if (WIFEXITED(status))
			return (WEXITSTATUS(status));
	}

	return (0);
}

/**
 * prompt - procesa la linea de entrada y ejecuta el comando
 * @line: linea de entrada del usuario (cadena de caracteres).
 *
 * Return: status del comando ejecutado
 */
int prompt(char *line)
{
	char *argv[10], *cmd_path;
	int argc;

	argc = token_input(line, argv);
	if (argc == 0)
		return (0);

	cmd_path = find_command(argv[0]);
	if (!cmd_path)
	{
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		return (127);
	}

	return (execute_child(cmd_path, argv));
}
