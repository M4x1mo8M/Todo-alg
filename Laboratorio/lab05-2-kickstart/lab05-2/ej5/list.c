#include "list.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

struct _list {
    elem elems[MAX_LENGTH];
    int size;
};

list empty(void) {
    list l = malloc(sizeof(struct _list));
    if (l == NULL) {
        fprintf(stderr, "Error: no memory for list.\n");
        exit(EXIT_FAILURE);
    }
    l->size = 0;
    return l;
}

list addl(elem e, list l) {
    if (l->size >= MAX_LENGTH) {
        fprintf(stderr, "Error: list is full.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = l->size; i > 0; --i) {
        l->elems[i] = l->elems[i - 1];
    }
    l->elems[0] = e;
    l->size++;
    return l;
}

bool is_empty(list l) {
    return l->size == 0;
}

elem head(list l) {
    if (is_empty(l)) {
        fprintf(stderr, "Error: head on empty list.\n");
        exit(EXIT_FAILURE);
    }
    return l->elems[0];
}

list tail(list l) {
    if (is_empty(l)) return l;
    for (int i = 0; i < l->size - 1; ++i) {
        l->elems[i] = l->elems[i + 1];
    }
    l->size--;
    return l;
}

list addr(list l, elem e) {
    if (l->size >= MAX_LENGTH) {
        fprintf(stderr, "Error: list is full.\n");
        exit(EXIT_FAILURE);
    }
    l->elems[l->size] = e;
    l->size++;
    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0) {
    if (l->size + l0->size > MAX_LENGTH) {
        fprintf(stderr, "Error: concatenation would overflow list.\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < l0->size; ++i) {
        l->elems[l->size + i] = l0->elems[i];
    }
    l->size += l0->size;
    return l;
}

elem index(list l, int n) {
    if (n < 0 || n >= l->size) {
        fprintf(stderr, "Error: index out of bounds.\n");
        exit(EXIT_FAILURE);
    }
    return l->elems[n];
}

list take(list l, int n) {
    if (n < 0) n = 0;
    if (n < l->size) {
        l->size = n;
    }
    return l;
}

list drop(list l, int n) {
    if (n < 0) n = 0;
    if (n >= l->size) {
        l->size = 0;
    } else {
        for (int i = 0; i < l->size - n; ++i) {
            l->elems[i] = l->elems[i + n];
        }
        l->size -= n;
    }
    return l;
}

list copy_list(list l) {
    list new_list = empty();
    new_list->size = l->size;
    for (int i = 0; i < l->size; ++i) {
        new_list->elems[i] = l->elems[i];
    }
    return new_list;
}

void destroy_list(list l) {
    free(l);
}


