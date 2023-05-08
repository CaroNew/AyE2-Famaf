#include <stdio.h>



int main(void){

    int *p=NULL;
    int a=55;
    p = &a;
    printf("La dirección de memoria de p es: %p \n", (void *) &p);
    printf("La dirección de memoria apuntada por p es: %p \n", (void *) p);
    printf("La dirección de memoria de a es: %p \n", (void *) &a);
    /* El casteo a void, es decir: la conversión a tipo void, la realizo por que
     el compilador gcc me dijo que %p esperaba un puntero (void *), y lo que le
      estaba pasando era (int *), supongo que es por que una dirección de
      memoria no debería tener un tipo espefico, pero esas son suposiciones mias
      */




    return 0;
}

