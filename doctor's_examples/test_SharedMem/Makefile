# Default C compiler
CC = gcc
# Default C compiler options.
CFLAGS = -Wall -g
# Default Linker
LK = gcc

### Rules.#################################################
# Default target: build everything.
all: server.out client.out

server.out: server.o
	$(LK) -o $@  $<

client.out: client.o
	$(LK) -o $@  $<

%.o:%.c shrmem.h
main.o: main.c
	$(CC) -c $(CFLAGS) $<

# Clean up build products.
clean:
	rm -f *.o *.out
