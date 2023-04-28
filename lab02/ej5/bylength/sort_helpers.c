#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "fixstring.h"

void swap(fixstring a[], unsigned int i, unsigned int j) {
    /*COMPLETAR*/
    fstring_swap(a[i],  a[j]);
    
}

bool goes_before(fixstring x, fixstring y) {
    /*COMPLETAR*/
    bool before = fstring_length(x) <= fstring_length(y);
    return before;
}

bool array_is_sorted(fixstring array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}

