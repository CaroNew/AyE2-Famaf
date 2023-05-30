#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    /* COMPLETAR*/
    struct s_node *first;
    unsigned int size;
};

struct s_node {
    /*COMPLETAR*/
    pqueue_elem elem;
    unsigned int priority; 
    struct s_node * next;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = NULL;
    
    /*COMPLETAR*/
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
    //assert(e==e && priority == priority); BORRAR ESTE ASSERT
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    /*COMPLETAR*/
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    /*COMPLETAR*/
    bool b = q != NULL && (b = q->first == NULL 
                                || q->size > 0);
    
    if(q->size > 1){
        struct s_node *node = NULL;
        struct s_node *previous = NULL;
        node = q->first;
        while(node->next != NULL){
            previous = node;
            node = node->next;
            b = b && previous->priority <= node->priority;
        }
        previous = NULL;
        node = NULL;
    }
    
    return b;
}

pqueue pqueue_empty(void) {
    pqueue q=NULL;
    /*COMPLETAR*/
    q = malloc(sizeof(struct s_pqueue));
    q->first = NULL;
    q->size = 0;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);

    if (q->first == NULL || priority < q->first->priority) {
        new_node->next = q->first;
        q->first = new_node;
    } else {
        struct s_node *actual = q->first;
        while (actual->next != NULL && actual->next->priority <= priority) {
            actual = actual->next;
        }
        new_node->next = actual->next;
        actual->next = new_node;
    }
    ++q->size;
    /*COMPLETAR*/
    /*if(q->first == NULL || priority < q->first->priority){
          new_node->next = q->first;
          q->first = new_node;
           
      }else{
         struct s_node *p = NULL;
         struct s_node *previous = NULL;
         p = q->first;
         while(p->next != NULL && p->priority <= priority){
             previous = p;
             p = p->next;
        }
        if(priority < p->priority){
            previous->next = new_node;
            new_node->next = p;
        }else if(priority == p->priority){
            p->next = new_node;
        }else{
            new_node->next = p->next;
            p->next = new_node;
        }
        p = NULL;
        previous = NULL;
    }
    ++q->size;
    */
    
    
    assert(invrep(q) && !pqueue_is_empty(q));
    return q;
}

bool pqueue_is_empty(pqueue q) {
    /* COMPLETAR*/
    bool is_empty = q->size == 0;
    assert(invrep(q));
    return is_empty;
}



pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    pqueue_elem peek = q->first->elem;
    /*COMPLETAR*/
    
    assert(invrep(q));
    return peek;
}

unsigned int pqueue_peek_priority(pqueue q) {
    /* COMPLETAR*/
    unsigned int peek_priority = q->first->priority;
    assert(invrep(q));
    return peek_priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    unsigned int size=0;
    /*COMPLETAR*/
    size = q->size;

    return size;
}

pqueue pqueue_dequeue(pqueue q) {
    /* COMPLETAR*/
    struct s_node *node = NULL;
    node = q->first;
    q->first = q->first->next;
    --q->size;
    node = destroy_node(node);
    node = NULL;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *node = NULL;
    struct s_node *killme = NULL;
    node = q->first;
   
    while(node != NULL){
        killme = node;
        node = node->next;
        killme = destroy_node(killme);
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}
