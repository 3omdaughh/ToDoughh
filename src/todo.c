#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/todo.h"
#include "../include/llist.h"

llist_t todolist = LLIST_INIT;

struct todo_s *new_todo(const char *mesg)
{
	struct todo_s *t = malloc(sizeof(*t));
	t->mesg = strdup(mesg);
	t->completed = 0;
	t->priority = 5;
	t->note = NULL;
	static unsigned next_id = 1;
	t->id = next_id++;
	return t;
}

void todo_list_item(void *data)
{
	struct todo_s *t = data;
	printf("[%u] %s %s\n", t->id, t->completed ? "[x]" : "[ ]", t->mesg);
}

void todo_list(void)
{
	printf("Your ToDo List: \n");
	llist_for_each(&todolist, todo_list_item);
}

void todo_delete(unsigned id) 
{
	llist_item_t *cur = todolist.head;
	while(cur) 
	{
		struct todo_s *t = cur->data;
		if (t->id == id) 
		{
			if (cur->prev) cur->prev->next = cur->next;
			if (cur->next) cur->next->prev = cur->prev;
			if (cur == todolist.head) todolist.head = cur->next;
			if (cur == todolist.tail) todolist.tail = cur->prev;
			free(t->mesg);
			free(t);
			free(cur);
			printf("Deleted item %u\n", id);
			return;
		}
		cur = cur->next;
	}
	printf("No such ID.\n");
}

void todo_mark_done(unsigned id) 
{
	llist_item_t *cur = todolist.head;
	while (cur) 
	{
		struct todo_s *t = cur->data;
		if (t->id == id) 
		{
			t->completed = 1;
			printf("Marked done: %s\n", t->mesg);
			return;
		}
		cur = cur->next;
	}
	printf("No such ID.\n");
}
