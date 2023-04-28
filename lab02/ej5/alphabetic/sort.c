#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"
#include "fixstring.h"


static unsigned int partition(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int piv = izq;
    unsigned int i = izq + 1;
    unsigned int j = der;
    
    while(i <= j){
        if(goes_before(a[i], a[piv])){
            i= i+1;
        }else if(goes_before(a[piv], a[j])){
            j=j-1;
        }else if(!goes_before(a[i], a[piv]) && !goes_before(a[piv], a[j])){
            swap(a, i, j);
            i++;
            j--;
        }
    }
    swap(a, piv, j);
    piv = j;
    
    return piv;
}

static void quick_sort_rec(fixstring a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
    unsigned int piv = 0u;
    if (izq < der){
        piv = partition(a, izq, der);
        assert(izq <= piv && piv <= der); 
        quick_sort_rec(a, izq, (piv == 0u) ? piv : piv-1);
        quick_sort_rec(a, piv+1, der);
    }
}

void quick_sort(fixstring a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}


