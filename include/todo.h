#ifndef TODO_H
#define TODO_H

/* ToDo Item Definition. */

struct todo_s
{
	unsigned id;
	char *mesg, *note;
	int completed, priority;
};

void todo_add(const char *mesg);
void todo_delete(unsigned id);
void todo_list(void);
void todo_mark_down(unsigned id);

#endif
