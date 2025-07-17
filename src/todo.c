#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TODO 100

static char* todos[MAX_TODO];
static int count = 0;

void todo_init() {
    FILE *f = fopen("data/todo.txt", "r");
    if (!f) return;

    char buf[256];
    while (fgets(buf, sizeof(buf), f)) {
        buf[strcspn(buf, "\n")] = 0;
        todos[count++] = strdup(buf);
    }
    fclose(f);
}

void todo_add(const char *task) {
    if (count < MAX_TODO)
        todos[count++] = strdup(task);
}

void todo_delete(int index) {
    if (index < 0 || index >= count) return;
    free(todos[index]);
    for (int i = index; i < count - 1; ++i)
        todos[i] = todos[i + 1];
    count--;
}

const char* todo_get(int index) {
    if (index < 0 || index >= count) return "";
    return todos[index];
}

int todo_count() {
    return count;
}

void todo_save() {
    FILE *f = fopen("data/todo.txt", "w");
    for (int i = 0; i < count; ++i)
        fprintf(f, "%s\n", todos[i]);
    fclose(f);
}
