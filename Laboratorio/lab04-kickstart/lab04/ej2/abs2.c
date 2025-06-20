#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x < 0) {
        *y = -x; // Asignación a través de un puntero, modifica la variable res en main
    } else {
        *y = x; // Asignación a través de un puntero, modifica la variable res en main
    }
    // No es necesario retornar nada, ya que se modifica res directamente
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    a = -10;
    absolute(a, &res);
    // supongamos que print() muestra el valor de una variable //
    printf("%d",res);

    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

