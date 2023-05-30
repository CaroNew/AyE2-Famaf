#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"



/*
* Calcula la longitud de la cadena apuntada
* por str
*/
size_t string_length(const char *str){
    size_t size = 0;
    unsigned int i = 0;
    while(*str){
        str++;
        i++;
    }
    size = i;
    
    return size;
}
/*
* Elimina las ocurrencias del char c de la cadena
+ si las hubiera
*/

char *string_filter(const char *str, char c){
    size_t size = string_length(str);
    char *result = calloc(size, sizeof(char));  
    int i = 0;
    
    while(*str){
        if(*str != c){
            result[i] = *str;
            i++;
        }
        str++;
    }
    
    
    return result;
}

