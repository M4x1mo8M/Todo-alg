#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node *List;

/**
 * @brief Construye y devuelve una lista de ejemplo de 3 elementos
 */
List setup_example() {
    List p = malloc(sizeof(Node));
    p->data = 10;
    p->next = malloc(sizeof(Node));
    p->next->data = 20;
    p->next->next = malloc(sizeof(Node));
    p->next->next->data = 0;
    p->next->next->next = NULL; // Termina la lista con NULL
    return p;
}

void show_list(List xs) {
    printf("[ ");
    while (xs != NULL) {
        printf("%i, ", xs->data);
        xs = xs->next;
    }
    printf("]\n");
}

int main(void) {
    List my_list;

    my_list = setup_example();

    show_list(my_list);

    return 0;
}
