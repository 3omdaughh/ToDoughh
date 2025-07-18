CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lncurses

SRC=src/main.c src/ui.c src/todo.c
INC=-Iinclude

ToDoughh: $(SRC)
	$(CC) $(CFLAGS) -o ToDoughh $(SRC) $(LDFLAGS) $(INC)

clean:
	rm -f ToDoughh *.o
