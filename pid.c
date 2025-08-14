#include "shell.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int get_pid(void) {
	pid_t pid;

	pid = getpid();
	printf("%u\n", pid);
	return (0);
}
