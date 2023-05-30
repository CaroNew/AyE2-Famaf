#include <stdlib.h>
#include <assert.h>
#include "stack.h"

#define CAPACITY 10

struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
};

bool invrep(stack s){
    bool b = s != NULL && (s->elems == NULL || 
                           s->capacity >= s->size);
    return b;
}
stack stack_empty(){
    stack new_stack = malloc(sizeof(struct _s_stack));
    new_stack->elems = NULL;
    new_stack->size = 0;
    new_stack->capacity = 0;
    assert(invrep(new_stack));
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    if(s->elems == NULL){
        s->elems = calloc(CAPACITY, sizeof(stack_elem));
        s->capacity = CAPACITY;
        s->elems[s->size] = e;
        ++s->size;
    }else{
        if(s->size == s->capacity){
            unsigned int re_capacity = 2 * s->capacity;
            s->elems = realloc(s->elems, re_capacity * sizeof(stack_elem));
            s->capacity = re_capacity;
        }
            
        s->elems[s->size] = e;
        ++s->size;
    }
    assert(invrep(s) && s->size > 0);
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    s->size--;
    assert(invrep(s));
    return s;
}

unsigned int stack_size(stack s){
    unsigned int size = s->size;
    return size;
}

stack_elem stack_top(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    stack_elem e = s->elems[s->size-1];
    assert(invrep(s));
    return e;
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    bool is_empty = s->size == 0;
    assert(invrep(s));
    return is_empty;
}

stack_elem *stack_to_array(stack s){
    assert(invrep(s));
    stack_elem *array = NULL;
    stack_elem e;
    unsigned int size = s->size;
    unsigned int i = 0;
    
    if(size != 0){
        array = calloc(size, sizeof(stack_elem));
    
        while(i < size){
            e = s->elems[i];
            array[i] = e;
            i++;
        }
    }
    return array;
}


stack stack_destroy(stack s){
    assert(invrep(s));
    free(s->elems);
    free(s);
    s=NULL;
    assert(s == NULL);
    return s;
}
/* me resulto dificil hayar el invariante, ya que tengo que 
controlar que s->size == 0 si s->elems == NULL, pero por
la forma de implementacion sin reallocs, s->size puede ser
cero sin que s->elems == NULL*/
