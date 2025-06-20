#include "intercalate.h"
#include <stdio.h>

/**
 * @brief Devuelve en UNA NUEVA lista con el resultado de intercalar el
 * elemento `e` entre todos los elementos de `l`
 *
 */
list intercalate(list l, elem e) {
    list q = empty();
    for(int i = 0; i < length(l); i++){
		if(i > 0){
			q = addr(q,e);
		}
        q = addr(q,index(l,i));
    }
    return q;
}
