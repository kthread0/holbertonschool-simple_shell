#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 4096

/* Standard libraries */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/* Our own libaries */

/* Our functions */

void exec(char **argv);
int prompt(void);

#endif /* SHELL_H */
