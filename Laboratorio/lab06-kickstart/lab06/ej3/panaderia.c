#include "panaderia.h"

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int panaderia(int monto[], int costo_harina[], int n, int H){
       int tabla[n+1][H+1];
       for(int i=0; i<=n; i++){
              tabla[i][0] = 0;
       }
       for(int j=1; j<=H; j++){
              tabla[0][j] = 0;
       }
       for(int i=1; i<=n; i++){
              for(int j=1; j<=H; j++){
                     if(costo_harina[i-1] > j){
                            tabla[i][j] = tabla[i-1][j];
                     }
                     else{
                            tabla[i][j] = MAX(tabla[i-1][j],monto[i-1] + tabla[i-1][j-costo_harina[i-1]]);
                     }
              }
       }
       return tabla[n][H];
}
