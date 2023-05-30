#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "new_stack.h"

struct _s_node{
    stack_elem elem;
    struct _s_node *next;
};

typedef struct _s_node * s_node;

struct _s_stack{
    s_node node;
    unsigned int size;
};

bool invrep(stack s){
    
    bool b = s->node == NULL || s->size > 0;
    return b;
}

stack stack_empty(){
    stack new_stack = malloc(sizeof(struct _s_stack));
    new_stack->node = NULL;
    new_stack->size = 0;
    assert(invrep(new_stack));
    return new_stack;
}

stack stack_push(stack s, stack_elem e){
    assert(invrep(s));
    s_node new_node = NULL;
    
    new_node = malloc(sizeof(struct _s_node));
    new_node->elem = e;
    new_node->next = s->node;    
    s->size = s->size + 1;
    s->node = new_node;
    assert(invrep(s));
    return s;
}

stack stack_pop(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    s_node p = NULL;
    p = s->node;
    s->node = s->node->next;
    s->size = s->size - 1;
    free(p);
    assert(invrep(s));
    return s;
}


unsigned int stack_size(stack s){
    assert(invrep(s));
    unsigned int size = s->size;
    assert(invrep(s));
    return size;
}

stack_elem stack_top(stack s){
    assert(invrep(s) && !stack_is_empty(s));
    stack_elem e = s->node->elem;
    assert(invrep(s));
    return e;
}

bool stack_is_empty(stack s){
    assert(invrep(s));
    bool is_empty;
    is_empty = s->size == 0;
    assert(invrep(s));
    return is_empty;
}

stack_elem *stack_to_array(stack s){
    stack_elem *array = NULL;
    s_node p = NULL;
    stack_elem e;
    unsigned int size = s->size;
    int i = s->node == NULL ? 0 : size - 1;
    p = s->node;
    
    if(size != 0){
        array = calloc(size, sizeof(stack_elem));
    
        while(p != NULL){
            e = p->elem;
            array[i] = e;
            p = p->next;
            i--;
        }
    
    }
    p = NULL;
    
    return array;
}


stack stack_destroy(stack s){
    assert(invrep(s));
    s_node p = NULL;
    p = s->node;
    
    while(p != NULL){
        s->node = s->node->next;
        free(p);
        p = s->node;
    }
    free(s);
    s = NULL;
    assert(s == NULL);
    return s;
}

