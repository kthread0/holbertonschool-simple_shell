#ifndef SHELL_H
#define SHELL_H

/* Librerías estándar */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Variable global de entorno */
extern char **environ;

/* -------- Prototipos -------- */

/* prompt.c */
int token_input(char *line, char **argv);
char *find_command(char *cmd);
int execute_child(char *cmd_path, char **argv);
int prompt(char *line);

/* get_pid.c */
int get_pid(void);

#endif /* SHELL_H */
