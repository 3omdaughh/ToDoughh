CC = gcc
CFLAGS = -Wall -g

SRC = src/main.c src/todo.c src/utils.c src/io.c
OBJ = $(SRC:.c=.o)

todo: $(SRC)
	$(CC) $(CFLAGS) -o todo $(SRC)

clean:
	rm -f todo *.o
