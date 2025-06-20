#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

void absolute(int x, int *y) {
    if (x >= 0)
    {
        *y = x;
    }
    else
    {
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    // --- No se deben declarar variables nuevas ---

    a = -10;  // No modificar esta línea
    absolute(a, &res);  // Cambiar la llamada a absolute() para que use el puntero
    printf("%d \n", res);  // No modificar esta línea
    assert(res >= 0 && (res == a || res == -a));
    return EXIT_SUCCESS;
}

