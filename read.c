#include "shell.h"

char *read_line(void) {
	char *line = NULL;
	size_t buffer_size = 0;

	if (getline(&line, &buffer_size, stdin) == -1) {
		if (feof(stdin)) {
			execve(); // TODO: implementar function de ejecucion
			exit(EXIT_SUCCESS);
		} else {
			perror("error");
			exit(EXIT_FAILURE);
		}
	}

	return line;
}
