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
    List my_list = malloc(sizeof(Node));

    Node *a_node = my_list;
    for (size_t i = 2; i > 0; i--) {
        a_node->data = i * 10; // Asigna valores 0, 10, 20
        a_node->next = malloc(sizeof(Node)); // Reserva memoria para el siguiente nodo
        a_node = a_node->next; // Avanza al siguiente nodo   
    }
    a_node->data = 0; // Asigna el último valor como 0
    a_node->next = NULL; // Termina la lista con NULL
    return my_list; // Devuelve la cabeza de la lista
    
}

/**
 * @brief Agrega un elemento de ejemplo al final de la lista
 *
 * Precondicion: la lista xs no debe ser vacía
 */
void append_example(List xs) {
    Node *a_node = xs;

    while (a_node->next != NULL) {
        a_node = a_node->next; // Avanza al último nodo
    }

    a_node->next = malloc(sizeof(Node)); // Reserva memoria para el nuevo nodo
    a_node->next->data = 88; // Asigna el valor 88 al nuevo nodo
    a_node->next->next = NULL; // Termina la lista con NULL
    
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

    printf("Lista antes del append: ");

    show_list(my_list);

    append_example(my_list);

    printf("Lista después del append: ");

    show_list(my_list);

    return 0;
}
