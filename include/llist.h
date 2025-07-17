#ifndef LLIST_H
#define LLIST_H

#include <stdlib.h>

#define LLIST_INIT {NULL, NULL, 0}

typedef struct llist_item 
{
	struct llist_item *next;
	struct llist_item *prev;
	void *data;
} llist_item_t;

typedef struct 
{
	llist_item_t *head;
	llist_item_t *tail;
	int size;
} llist_t;

static inline void llist_init (llist_t *l)
{
	l->head = l->tail = NULL;
	l->size = 0;
}

static inline void llist_add (llist_t *l, void *data)
{
	llist_item_t *item = malloc (sizeof(*item));
	item->data = data;
	item->next = NULL;
	item->prev = l->tail;

	if (l->tail) l->tail->next = item;
	else l->head = item;

	l->tail = item;
	l->size++;
}

static inline void llist_for_each (const llist_t *l, void (*cb) (void *))
{
	for (llist_item_t *i = l->head; i; i = i->next) cb(i->data);
}

#endif
