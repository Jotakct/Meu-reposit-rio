CC = gcc
CFLAGS = -Wall -Wextra -std=c11

all: main

main: main.c team.c teamvec.c team.h teamvec.h
	$(CC) $(CFLAGS) main.c team.c teamvec.c -o main

clean:
	rm -f main
