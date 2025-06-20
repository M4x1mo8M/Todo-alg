#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Estructura interna del nodo
struct _list {
    elem data;
    struct _list* next;
};

list empty(void) {
    list l = malloc(sizeof(struct _list));
    if (l == NULL) {
        fprintf(stderr, "Error: No memory for list.\n");
        exit(EXIT_FAILURE);
    }
    l->next = NULL;
    return l;
}

void destroy_list(list l) {
    struct _list* current = l;
    struct _list* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

list addl(elem e, list l) {
    struct _list* new_node = malloc(sizeof(struct _list));
    if (new_node == NULL) {
        fprintf(stderr, "Error: No memory for new node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = e;
    new_node->next = l->next;
    l->next = new_node;
    return l;
}

bool is_empty(list l) {
    return l->next == NULL;
}

elem head(list l) {
    if (is_empty(l)) {
        fprintf(stderr, "Error: head called on empty list.\n");
        exit(EXIT_FAILURE);
    }
    return l->next->data;
}

list tail(list l) {
    if (!is_empty(l)) {
        struct _list* first = l->next;
        l->next = first->next;
        free(first);
    }
    return l;
}

list addr(list l, elem e) {
    struct _list* new_node = malloc(sizeof(struct _list));
    if (new_node == NULL) {
        fprintf(stderr, "Error: No memory for new node.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = e;
    new_node->next = NULL;

    if (l->next == NULL) {
        l->next = new_node;
    } else {
        struct _list* current = l->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    return l;
}

int length(list l) {
    int count = 0;
    struct _list* current = l->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

list concat(list l, list l0) {
    if (l->next == NULL) {
        l->next = l0->next;
    } else {
        struct _list* current = l->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = l0->next;
    }
    return l;
}

elem index(list l, int n) {
    struct _list* current = l->next;
    int i = 0;
    while (current != NULL) {
        if (i == n) {
            return current->data;
        }
        current = current->next;
        i++;
    }
    fprintf(stderr, "Error: Index out of bounds in get_at.\n");
    exit(EXIT_FAILURE);
}




list take(list l, int n) {
    if (n <= 0 || l->next == NULL) return l;

    struct _list* current = l->next;
    struct _list* prev = l;

    for (int i = 0; i < n && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    // Libera el resto
    while (current != NULL) {
        struct _list* tmp = current;
        current = current->next;
        free(tmp);
    }

    prev->next = NULL;
    return l;
}

list drop(list l, int n) {
    struct _list* current = l->next;
    struct _list* next;

    for (int i = 0; i < n && current != NULL; i++) {
        next = current->next;
        free(current);
        current = next;
    }

    l->next = current;
    return l;
}

list copy_list(list l) {
    list new_list = empty();
    struct _list* current = l->next;
    while (current != NULL) {
        addr(new_list, current->data);
        current = current->next;
    }
    return new_list;
}
