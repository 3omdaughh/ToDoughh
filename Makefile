CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lncurses

SRC=src/main.c src/ui.c src/todo.c
INC=-Iinclude

todo: $(SRC)
	$(CC) $(CFLAGS) -o todo $(SRC) $(LDFLAGS) $(INC)

clean:
	rm -f todo *.o
