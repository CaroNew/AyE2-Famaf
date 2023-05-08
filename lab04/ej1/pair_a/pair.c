#include <assert.h>
#include "pair.h"


pair_t pair_new(int x, int y){
    pair_t new_pair;
    new_pair.fst = x;
    new_pair.snd = y;
    return new_pair;
}

/*PRE: {p --> (x, y)}*/
int pair_first(pair_t p){
    int one = p.fst;
    assert(p.fst == one);
    return one;
}

/*PRE: {p --> (x, y)}*/
int pair_second(pair_t p){
    int two = p.snd;
    assert(p.snd == two);
    return two;
}
/*PRE: {p --> (x, y)}*/
pair_t pair_swapped(pair_t p){
    pair_t swapped;
    swapped.fst = p.snd;
    swapped.snd = p.fst;
    assert(swapped.fst == p.snd && swapped.snd == p.fst);
    return swapped;
}

pair_t pair_destroy(pair_t p){
    p.fst = 0;
    p.snd = 0;
    return p;
}
