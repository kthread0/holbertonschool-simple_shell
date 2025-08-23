#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 4096

/* Standard libraries */
#include <linux/limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function prototype */
int prompt(char *line);
int get_pid(void);

#endif /* SHELL_H */
