#include "shell.h"

int prompt(void) {
	int ac = 0;
	char **av = 0;

	char *ps1 = "(Stranger Strings) $ ";
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;

	(void)ac;
	(void)av;

	while (1) {
		printf("%s", ps1);
		nchars_read = getline(&lineptr, &n, stdin);

		if (nchars_read == -1) {
			printf("Exit \n");
			return (-1);
		}

		printf("%s", lineptr);
	}

	free(lineptr);

	return (0);
}
