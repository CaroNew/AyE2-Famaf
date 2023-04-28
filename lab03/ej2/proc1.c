#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    //Completar aquí
    if(x >= 0) {
        y = x;
    }else{
        y = -x;
    }
}

int main(void) {
    int a=0, res=0;
    //Completar aquí
    a=-10;
    absolute(a, res);
    
    printf("%d\n", res);
    
    
    return EXIT_SUCCESS;
}
/* 
El valor mostrado por pantalla es 0 y no coincide con el valor
que devuelve en el lenguaje de teorico, que es 10;
*/
