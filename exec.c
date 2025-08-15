#include "shell.h"

void exec(char **argv) {
	pid_t pid = fork();
	if (pid == -1) {
		printf("\nError: couldn't fork child process");
		return;
	} else if (pid == 0) {
		if (execvp(argv[0], argv) < 0) {
			printf("\nError: can't execute command");
		}
		exit(0);
	} else {
		/* Terminar proceso zombie */
		wait(&pid);
		return;
	}
}
