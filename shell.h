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

/* Our own libaries */

/* Our functions */

int prompt(char *argv[]);

#endif /* SHELL_H */
