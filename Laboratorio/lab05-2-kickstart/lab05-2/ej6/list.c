#include <stdlib.h>

#include "list.h"

#define MAX_LENGTH 1000

struct _list {
    elem a[MAX_LENGTH];
    int start;
    int size;
};

static int real_index(list l, int i) {
    return (l->start + i) % MAX_LENGTH;
}

list empty(void) {
    list l = malloc(sizeof(struct _list));
    l->start = 0;
    l->size = 0;
    return l;
}

list addl(elem e, list l) {
    l->start = (l->start - 1 + MAX_LENGTH) % MAX_LENGTH;
    l->a[l->start] = e;
    l->size++;
    return l;
}

bool is_empty(list l) {
    return l->size == 0;
}

elem head(list l) {
    return l->a[l->start];
}

list tail(list l) {
    if (!is_empty(l)) {
        l->start = (l->start + 1) % MAX_LENGTH;
        l->size--;
    }
    return l;
}

list addr(list l, elem e) {
    int idx = real_index(l, l->size);
    l->a[idx] = e;
    l->size++;
    return l;
}

int length(list l) {
    return l->size;
}

list concat(list l, list l0) {
    for (int i = 0; i < l0->size; ++i) {
        elem e = l0->a[(l0->start + i) % MAX_LENGTH];
        addr(l, e);
    }
    return l;
}

elem index(list l, int n) {
    return l->a[real_index(l, n)];
}

list take(list l, int n) {
    if (n < l->size) {
        l->size = n;
    }
    return l;
}

list drop(list l, int n) {
    if (n >= l->size) {
        l->size = 0;
        l->start = 0; // optional reset
    } else {
        l->start = (l->start + n) % MAX_LENGTH;
        l->size -= n;
    }
    return l;
}

list copy_list(list l) {
    list new_list = empty();
    new_list->size = l->size;
    for (int i = 0; i < l->size; ++i) {
        new_list->a[i] = l->a[real_index(l, i)];
    }
    new_list->start = 0;
    return new_list;
}

void destroy_list(list l) {
    free(l);
}
