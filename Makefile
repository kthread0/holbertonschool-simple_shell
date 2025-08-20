CC = gcc
OPTIONS = -march=native -Og -flto -Wall -Werror -Wextra -pedantic -std=gnu89 -g3 -ggdb3 -pipe
FILES = $(wildcard *.c)

build: $(FILES)
	$(CC) $(OPTIONS) $(FILES) -o shell

clean:
	rm -v shell
