#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"

struct _s_stack{
    stack_elem elem;
    unsigned int size;
    struct _s_stack *next;
};
bool invrep(stack s){
    bool b = s != NULL && s->size != 0;
    return b;
}

stack stack_empty(){
    stack new_stack = NULL;
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    
    stack p = NULL;
    p = malloc(sizeof(struct _s_stack)); 
    p->elem = e;
    p->next = s;
    p->size = s == NULL ? 1 : s->size + 1;
    s = p;
    /*
    if(s == NULL){
        s = malloc(sizeof(struct _s_stack));
        s->elem = e;
        s->next = NULL;
        s->size = 1;
    }else{
        p = malloc(sizeof(struct _s_stack)); 
        p->elem = e;
        p->next = s;
        p->size = s->size + 1;
        s = p;
    }
    */
    
    
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s));
    stack p = NULL;
    p = s;
    s = s->next;
    free(p);
    p = NULL;
    return s;
}


unsigned int stack_size(stack s){
    assert(invrep(s));
    unsigned int size;
    size = s == NULL ? 0 : s->size;
    assert(invrep(s));
    return size;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    stack_elem e = s->elem;
    return e;
}

bool stack_is_empty(stack s){
    
    bool is_empty;
    is_empty = s == NULL;
    return is_empty;
}

stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    stack p = NULL;
    stack_elem e;
    unsigned int size = stack_size(s);
    int i = size - 1;
    p = s;
    /*If nmemb or size is 0, then calloc() returns
       either NULL, or a unique pointer value that can later  be  successfully
       passed to free().*/
    array = calloc(size, sizeof(stack_elem));
    
    while(p != NULL){
        e = p->elem;
        array[i] = e;
        p = p->next;
        i--;
    }
    p = NULL;
    
    return array;
}

stack stack_destroy(stack s){
    
    stack p = NULL;
    p = s;
    
    while(p != NULL){
        s = s->next;
        free(p);
        p = s;
    }

    assert(s == NULL);
    return s;
}
/*mi invariante esta basado en como
implemente la stack, tuve problemas
para encontrarlo gracias a eso, 
no tuve tiempo para cambiar y probar
otra implementación, pero la 
idea seria pedir memoria para la
stack vacia en stack_empty() y 
y comprobar en todas las funciones
que s->size no sea 0 si es vacia*/
