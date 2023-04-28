#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
    unsigned int j = i;
    while(j > 0u && goes_before(a[j], a[j-1])){
        swap(a, j, j-1);
        j--;
    }
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
        assert(array_is_sorted(a, i));
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
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

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
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
