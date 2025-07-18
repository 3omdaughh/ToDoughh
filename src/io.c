#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/todo.h"
#include "../include/llist.h"
#include "../include/utils.h"
#include "../include/io.h"

/* External reference from todo.c */

extern llist_t todolist;

void todo_save_to_file (const char *filename)
{
	FILE *f = fopen(filename, "w");
	if (!f)
	{
		perror("fopen (save)");
		return;
	}

	for (llist_item_t *i = todolist.head; i; i = i->next)
	{
		struct todo_s *t = i->data;
		fprintf(f, "%u|%d|%d|%s\n",
		t->id,
		t->priority,
		t->completed,
		t->mesg);
	}

	fclose(f);
}

void todo_load_from_file (const char *filename)
{
	FILE *f = fopen(filename, "r");
	if (!f) return; /* File might not exist yet - skip loading */

	char line[512];
	while (fgets(line, sizeof(line), f))
	{
		struct todo_s *t = malloc(sizeof(*t));
		t->note = NULL;
		char *msg_start = strchr(line, '|');
		if (!msg_start) continue;
		*msg_start++ = '\0';

		t->id = (unsigned)atoi(line);

		char *priority = strchr(msg_start, '|');
		if(!priority) continue;
		*priority++ = '\0';

		char *done = strchr(priority, '|');
		if (!done) continue;
		*done++ = '\0';

		t->priority = atoi(msg_start);
		t->completed = atoi(priority);
		t->mesg = mem_strdup(done);
		t->mesg[strcspn(t->mesg, "\n")] = '\0'; /* remove newline*/

		llist_add(&todolist, t);
	}

	fclose(f);
}
