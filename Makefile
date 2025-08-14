CC = gcc
OPTIONS = -march=native -O2 -flto -Wall -Werror -Wextra -pedantic -std=gnu89 -pipe
FILES = $(wildcard *.c)

build: $(FILES)
	$(CC) $(OPTIONS) $(FILES) -o hsh

clean: 
	rm -v hsh
