#include "shell.h"
#include <stdio.h>

int main(void) {
	char *lineptr = NULL;
	size_t n = 0;
	ssize_t input = 0;

	while (1) {
		input = getline(&lineptr, &n, stdin);
		prompt((char **)input);
	}
	return 0;
}
