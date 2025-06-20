#include "remove.h"

/**
 * @brief Devuelve en UNA NUEVA lista el resultado de eliminar todas las
 * ocurrencias de `e` en `l`
 *
 */
list remove_elem(list l, elem e) {
    list q = empty();
    int i = 0;
    while (i < length(l)){
        if (index(l, i) != e) {
            q = addr(q,index(l,i));
        }
        i++;
    }
    return q;
}
