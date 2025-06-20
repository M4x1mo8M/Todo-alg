#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    if (x < 0) {
        y = -x; // Asignación local, no afecta a la variable res en main
    } else {
        y = x; // Asignación local, no afecta a la variable res en main
    }
    // Aquí se debería retornar el valor absoluto o usar un puntero para modificar res
    // return y; // Esto sería lo correcto si se quisiera retornar el valor absoluto
}

int main(void) {
    int a=0, res=0;
    a = -10;
    absolute(a, res);
    // supongamos que print() muestra el valor de una variable //
    printf("%d",res);
    // esta última asignación es análoga a `return EXIT_SUCCESS;` //
    res = 0;

    return EXIT_SUCCESS;
}

