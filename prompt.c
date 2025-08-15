#include "shell.h"

int main(int ac, char **av) {

	char *prompt = "(Stranger Strings)";
	char *lineptr;
	size_t n = 0;

	(void)ac; (void)av;

	printf("%s", prompt);
	getline(&lineptr, &n, stdin);
	
	free(lineptr);
	return (0);
}
