#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

int main(void){

   stack new_stack = stack_empty();
   
   new_stack = stack_push(new_stack, 1);
   new_stack = stack_push(new_stack, 2);
   new_stack = stack_push(new_stack, 3);
   new_stack = stack_push(new_stack, 4);
   new_stack = stack_push(new_stack, 5);
   
   unsigned int size = stack_size(new_stack);
   
   printf("cantidad de elementos en la pila: %u\n", size);
   
   bool is_empty = stack_is_empty(new_stack);
   
   printf("es vacia?: \n");
   
   is_empty ? printf("True\n") : printf("False\n");
  
   stack_elem elem = stack_top(new_stack);
   
   printf("al tope de la pila: %d\n", elem);
   
   new_stack = stack_pop(new_stack);
   size = stack_size(new_stack);
   printf("cantidad de elementos en la pila: %u\n", size);
   new_stack = stack_pop(new_stack);
   size = stack_size(new_stack);
   printf("cantidad de elementos en la pila: %u\n", size);
   new_stack = stack_pop(new_stack);
   size = stack_size(new_stack);
   printf("cantidad de elementos en la pila: %u\n", size);
   new_stack = stack_pop(new_stack);
   size = stack_size(new_stack);
   printf("cantidad de elementos en la pila: %u\n", size);
   new_stack = stack_pop(new_stack);
   size = stack_size(new_stack);
   printf("cantidad de elementos en la pila: %u\n", size);
   new_stack = stack_destroy(new_stack);
   
   printf("-----------------------------------------------\n");
   printf("prueba stack_pop() funciona para pilas de tamaño 1 \n");
   
   stack nwstk = stack_empty();
   nwstk = stack_push(nwstk, 1);
   size = stack_size(nwstk);
   printf("cantidad de elementos en la pila: %u\n", size);
   nwstk = stack_pop(nwstk);
   
   size = stack_size(nwstk);
   printf("cantidad de elementos en la pila: %u\n", size);

   is_empty = stack_is_empty(nwstk);
   
   printf("es vacia?: \n");
   
   is_empty ? printf("True\n") : printf("False\n");
    
   nwstk = stack_push(nwstk, 2);
   size = stack_size(nwstk);
   printf("cantidad de elementos en la pila: %u\n", size);
   nwstk = stack_destroy(nwstk);
   printf("-----------------------------------------------\n");
   printf("stack to array funciona como deberia funcionar?\n");
   stack new = stack_empty();
   
   for(int i = 1; i <= 5; i++){
       new = stack_push(new, i);
   }
   size = stack_size(new);
   printf("cantidad de elementos en la pila: %u\n", size);
   elem = stack_top(new);
   
   printf("al tope de la pila: %d\n", elem);
   
   stack_elem *array = stack_to_array(new);
   
   for(int i = 0; i < 5; i++){
       printf("elemento en la posicion %d: %d\n", i, array[i]); 
   }
   free(array);
   
   new = stack_destroy(new);
   //.............array is null..................
   stack n = stack_empty();
   
   stack_elem *array1 = stack_to_array(n);
   
   array1 == NULL ? printf("NULL\n") : printf("not NULL\n");
   
   free(array1);
   n = stack_destroy(n);
    return 0;
}
