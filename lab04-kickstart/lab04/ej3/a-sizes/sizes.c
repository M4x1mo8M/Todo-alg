#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);

    // bytes utilizados por cada uno de los campos
    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", 
           &messi.name, sizeof(messi.name),
           &messi.age, sizeof(messi.age),
           &messi.height, sizeof(messi.height),
           &messi, sizeof(messi));

    // direccion de memoria de cada uno de los campos
    printf("name-size  : %lu \n"
           "age-size   : %lu \n"
           "height-size: %lu \n"
           "data_t-size: %lu \n", 
           (void *)&messi.name,
           (void *)&messi.age,
           (void *)&messi.height,
           (void *)&messi);

    data_t *puntero = malloc(sizeof(data_t));
    if (puntero != NULL)  
    {
    strcpy(puntero->name, "Messi");
    puntero->age = 36;
    puntero->height = 169;
    free(puntero);
    }
    


    return EXIT_SUCCESS;
}
