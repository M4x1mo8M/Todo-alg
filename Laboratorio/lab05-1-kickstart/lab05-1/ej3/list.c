#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct  a_list{
    int data;
    struct a_list* next;
};

list list_create(void) {
    list l = malloc(sizeof(struct a_list));
    l->next = NULL;
    return l;
}

void list_destroy(list l) {
    struct a_list* current = l;
    struct a_list* next_node;
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

void addl(list l, int value) {
    struct a_list* new_node = malloc(sizeof(struct a_list));
    new_node->data = value;
    new_node->next = l->next;
    l->next = new_node;
}

bool list_is_empty(list l) {
    return l->next == NULL;
}

int head(list l) {
    if (l->next == NULL) {
        fprintf(stderr, "Error: Attempt to access head of an empty list.\n");
        exit(EXIT_FAILURE);
    }
    return l->next->data;
}

void tail(list l) {
    if (l->next != NULL) {
        struct a_list* first = l->next;
        l->next = first->next;
        free(first);
    }
}

void addr(list l, int value) {
    struct a_list* new_node = malloc(sizeof(struct a_list));
    new_node->data = value;
    new_node->next = NULL;

    if (l->next == NULL) {
        l->next = new_node;
    } else {
        struct a_list* current = l->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

int lenght(list l) {
    int count = 0;
    struct a_list* current = l->next;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void concat(list l1, list l2) {
    if (l1->next == NULL) {
        l1->next = l2->next;
    } else {
        struct a_list* current = l1->next;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = l2->next;
    }
}

int index(list l, int value) {
    int idx = 0;
    struct a_list* current = l->next;
    while (current != NULL) {
        if (current->data == value) {
            return idx;
        }
        current = current->next;
        idx++;
    }
    return -1; // Not found
}

void take(list l, int n) {
    if (n <= 0 || l->next == NULL) return;

    struct a_list* current = l->next;
    struct a_list* prev = l;

    for (int i = 0; i < n && current != NULL; i++) {
        prev = current;
        current = current->next;
    }

    prev->next = NULL;
}

void drop(list l, int n) {
    struct a_list *current = l->next, *next;
    for (int i = 0; i < n && current != NULL; i++) {
        next = current->next;
        free(current);
        current = next;
    }
    l->next = current;
}

list copy_list(list l) {
    list new_list = list_create();
    struct a_list* current = l->next;

    while (current != NULL) {
        addl(new_list, current->data);  // Agrega al principio
        current = current->next;
    }
    return new_list;
}

