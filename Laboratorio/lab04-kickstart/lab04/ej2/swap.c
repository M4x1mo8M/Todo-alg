#include <stdio.h>

void swap (int *x, int *y) {
    int temp; // Variable temporal para realizar el intercambio
    temp = *x; // Guardar el valor de x en temp
    *x = *y;   // Asignar el valor de y a x
    *y = temp; // Asignar el valor guardado en temp a y
}

int main(void) {
    int x,y;
    x = 6;
    y = 4;
    printf("%d,%d\n", x , y);
    swap(&x, &y);
    printf("%d,%d", x , y);
    return 0;

}
