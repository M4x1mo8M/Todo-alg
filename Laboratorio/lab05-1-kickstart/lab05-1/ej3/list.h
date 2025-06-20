#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdlib.h>

typedef struct a_list * list;

list list_create(void);

void list_destroy(list l);

void addl(list l, int value);

bool list_is_empty(list l);

int head(list l);

void tail(list l);

void addr(list l, int value);

int lenght(list l);

void concat(list l1, list l2);

int index(list l, int value);

void take(list l, int n);

void drop(list l, int n);

list copy_list(list l);

#endif // List_H//