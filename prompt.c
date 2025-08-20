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
	/* Arreglo para almacenar los argumentos del comando */
	int i = 0;
	/* Contador para iterar sobre los argumentos */
	char *token;
	/* Puntero para almacenar cada segmento de la linea */

	token = strtok(line, " \n");
	/* Divide la linea en tokens separados por espacio */
	while (token != NULL && i < 9)
		/* Itera mientras haya tokens y espacio en el arreglo */
	{
		argv[i++] = token;
		/* Guarda cada token en argv */
		token = strtok(NULL, " \n");
		/* Obtiene el siguiente token en la linea */
	}
	argv[i] = NULL;
	/* Termina el arreglo con NULL como pide execvp */

	if (argv[0] == NULL)
		/* Si la línea esta vac�a, no hace nada */
		return (0);

	pid_t child_pid = fork(); /* Guarda el PID del hijo */

	if (child_pid == -1) /* Error al crear el proceso hijo */
	{
		perror("fork failed");
		return (1);
	}

	if (child_pid == 0) /* Proceso hijo */
	{
		execvp(argv[0], argv); /* Ejecuta el comando con sus argumentos */
		/* Si execvp falla */
		fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
		exit(127); /* Código de fallo si no se encontró el coman */
	}

	else /* Se ejecuta en el proceso padre */
	{
		int status;
		waitpid(child_pid, &status, 0);
		/* El padre espera al hijo y guarda el estado */

		if (WIFEXITED(status))
			return WEXITSTATUS(status);
		/* Devuelve el código de salida real del hijo */
	}

	return (0);
}
