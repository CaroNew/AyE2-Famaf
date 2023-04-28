#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int *y) {
    //Completar aquí
    if(x >= 0){
        *y = x;
    }else{
        *y = -x;
    }
}

int main(void) {
    int a=0, res=0;  // No modificar esta declaración
    //Completar aquí
    a = -10;
    absolute(a, &res);
    
    printf("%d\n", res);
    return EXIT_SUCCESS;
}
/*
Para pensar:
1. El parámetro int *y de absolute() es de tipo in, de tipo out o de tipo in/out
2. ¿Qué tipo de parámetros tiene disponibles C para sus funciones?
+ Parámetros in
+ Parámetros out
+ Parámetros in/out
1. El parametro *y es del tipo in, 

2. Al parecer, todos los parámetros son de tipo in. 

*/
