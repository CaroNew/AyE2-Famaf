#include <assert.h>
#include "pair.h"
#include <stdlib.h>


struct s_pair_t {
    int fst;
    int snd;
};

pair_t pair_new(int x, int y){
    pair_t new = malloc(sizeof(struct s_pair_t));
    new->fst = x;
    new->snd = y;
    return new;
}
/*PRE: {p --> (x, y)}*/
int pair_first(pair_t p){
    int one = p->fst;
    assert(p->fst == one);
    return one;
}

/*PRE: {p --> (x, y)}*/
int pair_second(pair_t p){
    int two = p->snd;
    assert(p->snd == two);
    return two;
}

pair_t pair_swapped(pair_t p){
    pair_t swapped = malloc(sizeof(struct s_pair_t));
    swapped->fst = p->snd;
    swapped->snd = p->fst;
    assert(swapped->fst == p->snd && swapped->snd == p->fst);
    return swapped;
}


pair_t pair_destroy(pair_t p){
    free(p);
    p=NULL;
    return p;
}

