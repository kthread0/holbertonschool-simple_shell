#include "shell.h"

/**
 * get_pid - this functions calls for the pid and prints in the console
 *
 * Return: Always 0.
 */
int get_pid(void)
{
	pid_t pid;

	pid = getpid();
	printf("%u\n", pid);
	return (0);
}
