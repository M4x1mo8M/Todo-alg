#include "reverse.h"
#include <stdio.h>

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de invertir
 * el orden de los elementos de `l`
 *
 */
list reverse(list l) {
    list q = empty();
    for(int i = 0; i < length(l); i++) {
        q = addl(index(l,i),q);
    }
    return q;
}