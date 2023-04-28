#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
/* no implementes partition, ya está implementado en sort_helpers.o
       (no se puede leer, pero en sort_helpers.h vas a encontrar información
        para saber cómo usarlo)
    */

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
 /* needs implementation */
    unsigned int piv = 0u;
    if (izq < der){
        piv = partition(a, izq, der);
        assert(izq <= piv && piv <= der); 
        quick_sort_rec(a, izq, (piv == 0u) ? piv : piv-1);
        quick_sort_rec(a, piv+1, der);
    }
    
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

