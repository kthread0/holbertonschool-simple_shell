#include "shell.h"
#include <linux/limits.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	FILE *stream;
	char *line = NULL;

	if (argc != 2) {
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	stream = exec(&line);
	if (stream == NULL) {
		perror("fopen");
		exit(EXIT_FAILURE);
	}

	free(line);
	fclose(stream);
	exit(EXIT_SUCCESS);
	return 0;
}
