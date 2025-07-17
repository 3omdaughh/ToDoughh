#ifndef TODO_H
#define TODO_H

void todo_init();
void todo_add(const char *task);
void todo_delete(int index);
const char* todo_get(int index);
int todo_count();
void todo_save();

#endif
