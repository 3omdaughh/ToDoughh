#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/io.h"
#include "todo.c"

int main(int argc, char *argv[]) 
{
	todo_load_from_file("todo.txt"); /* ← LOAD from diski */

	if (argc < 2) 
	{
		printf("Usage: ./todo [list | add \"msg\" | done ID | del ID]\n");
		return 1;
	}

	if (!strcmp(argv[1], "list")) todo_list();
	else if (!strcmp(argv[1], "add") && argc >= 3) todo_add(argv[2]);
	else if (!strcmp(argv[1], "del") && argc >= 3) todo_delete((unsigned)atoi(argv[2]));
	else if (!strcmp(argv[1], "done") && argc >= 3) todo_mark_done((unsigned)atoi(argv[2]));
	else printf("Unknown command.\n");

	todo_save_to_file("todo.txt"); /* ← SAVE back to disk */
	return 0;
}
