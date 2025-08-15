#include "shell.h"

int prompt(char *argv[]) {
	char *in = NULL;
	/* printf("$ "); */

	execvp(in, argv);

	if (fork() == 0) {
		perror("execvp failed");
		exit(EXIT_FAILURE);
	} else {
		wait(NULL);
	}

	return (0);
}
