#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>


#include "data.h"

void print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %zu bytes\n"
           "age-size   : %zu bytes\n"
           "height-size: %zu bytes\n"
           "data_t-size: %zu bytes\n", 
           sizeof(messi.name),
           sizeof(messi.age),
           sizeof(messi.height), 
           sizeof(messi));

    printf("name-size  : %p dir\n"
           "age-size   : %p dir\n"
           "height-size: %p dir\n"
           "data_t-size: %p dir\n", 
           (void *)&messi.name,
           (void *)&messi.age,
           (void *)&messi.height, 
           (void *)&messi);

    data_t *p = malloc(sizeof(data_t));
    p->age = 30;
    p->height = 180;
    strcpy(p->name, "Leo Messi");
    print_data(*p);

    free(p);

    return EXIT_SUCCESS;
}
