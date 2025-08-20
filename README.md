# Holberton School Simple Shell

This is our final project for Holberton School's first trimester, written in C for Linux

> [!IMPORTANT]
> NOT meant for use

# Table of contents

1. [What?](#What?)
2. [Technicals](#Technicals)
4. [Usage](#Usage)


## What?

## Technicals

### Codebase overview

### File structure

```
./
├── AUTHORS
├── .cache/
│   └── clangd/
│       └── index/
│           ├── main.c.AD20CA1C3CD09EB2.idx
│           └── shell.h.675DC2756834FE34.idx
├── .clang-format
├── compile_commands.json
├── .gitignore
├── LICENSE
├── main.c
├── Makefile
├── man_1_simple_shell
├── pid.c
├── prompt.c
├── README.md
└── shell.h

4 directories, 14 files
```

### Functions defined (by file)

- main.c
  - int main(void)

- prompt.c
  - int prompt(char *line)

- pid.c
  - int get_pid(void)

- shell.h
  - int prompt(char *line); (prototype)
  - Macro: BUFFER_SIZE (4096) — currently unused

### Functions used (external/library calls), by file

- main.c
  - isatty(int fd)
  - fprintf(FILE *stream, const char *format, ...)
  - getline(char **lineptr, size_t *n, FILE *stream)
  - strcmp(const char *s1, const char *s2)
  - prompt(char *line)  [project-local]
  - free(void *ptr)

- prompt.c
  - strtok(char *restrict s, const char *restrict sep)
  - fork(void)
  - execvp(const char *file, char *const argv[])
  - fprintf(FILE *stream, const char *format, ...)
  - exit(int status)
  - wait(int *wstatus)

- pid.c
  - getpid(void)
  - printf(const char *format, ...)

- Header/platform symbols used
  - STDIN_FILENO (unistd.h)

### References (official documentation)

- POSIX getline: https://pubs.opengroup.org/onlinepubs/9699919799/functions/getline.html
- POSIX strtok: https://pubs.opengroup.org/onlinepubs/9699919799/functions/strtok.html
- POSIX isatty: https://pubs.opengroup.org/onlinepubs/9699919799/functions/isatty.html
- POSIX fork: https://pubs.opengroup.org/onlinepubs/9699919799/functions/fork.html
- POSIX execvp: https://pubs.opengroup.org/onlinepubs/9699919799/functions/exec.html
- POSIX wait/waitpid: https://pubs.opengroup.org/onlinepubs/9699919799/functions/wait.html
- POSIX getpid: https://pubs.opengroup.org/onlinepubs/9699919799/functions/getpid.html
- C fprintf/printf: https://en.cppreference.com/w/c/io/fprintf
- C exit: https://en.cppreference.com/w/c/program/exit


## Usage
You can execute something using our shell by doing the following:
```bash
./shell <file>
```
