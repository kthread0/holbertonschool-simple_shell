#include "shell.h"

int main(int ac, char **av) {

	char *prompt = "(Stranger Strings) $ ";
	char *lineptr;
	size_t n = 0;
	ssize_t nchars_read;

	(void)ac; (void)av;

	while (1) {
	printf("%s", prompt);
	nchars_read = getline(&lineptr, &n, stdin);
	
	if (nchars_read == -1) {
		printf("Exit \n");
		return (-1);
	}

	printf("%s", lineptr);

	free(lineptr);
	}
	return (0);
}
