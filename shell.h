#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 4096

/* Standard libraries */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Our own libaries */

/* Our functions */

int get_pid(void);
int shell_loop(void);
char *read_line(void);

#endif /* SHELL_H */
