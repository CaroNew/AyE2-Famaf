#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "stack.h"



struct _s_stack{
    stack_elem elem;
    struct _s_stack *next;
};

bool invrep(stack s){
    bool b = s == NULL;
    if(!b){
        b = stack_size(s) > 0;
    }
    return b;
}

stack stack_empty(){
    stack new_stack = NULL;
    assert(invrep(new_stack));
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    stack p = NULL;
    p = malloc(sizeof(struct _s_stack));
    p->elem = e; 
    p->next = s;
   /* if(s != NULL){
        p->next = s;
    }else{
        p->next = NULL;
    }*/
    s=p;
    
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
    assert(invrep(s));
    return s;
}


unsigned int stack_size(stack s){
    unsigned int size;
    stack p = NULL;
    size = 0;
    p = s;
    
    while(p != NULL){
        p = p->next;
        ++size;
    }
    p=NULL;
    assert(s == NULL || size > 0); 
    return size;
}

stack_elem stack_top(stack s){
    assert(invrep(s));
    stack_elem e = s->elem;
    return e;
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    bool is_empty;
    is_empty = s == NULL;
    assert(invrep(s));
    return is_empty;
}

stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    stack p = NULL;
    stack_elem e;
    unsigned int size = stack_size(s);
    int i = s == NULL ? 0 : size - 1;
    p = s;
    /*If nmemb or size is 0, then calloc() returns
       either NULL, or a unique pointer value that can later  be  successfully
       passed to free().*/
    if(size > 0){
        array = calloc(size, sizeof(stack_elem));
    
        while(p != NULL){
            e = p->elem;
            array[i] = e;
            p = p->next;
            i--;
        }
    }
    p = NULL;
    assert(s != NULL || array == NULL);
    return array;
}

stack stack_destroy(stack s){
    assert(invrep(s));
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


