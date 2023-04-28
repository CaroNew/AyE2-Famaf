#include <stdio.h> /*borrar despues de probar*/
#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) {
    /*COMPLETAR*/
    unsigned int size = 0;
    
    while(*s != '\0'){
        s++;
        size++;
    }
    return size;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    //COMPLETAR
    int i = 0;
    bool equal = true;
    
   while(s1[i] != '\0' && s2[i] != '\0' && equal){
       equal = s1[i] == s2[i];
       i++;
   }
    
   equal = s1[i] == '\0' && s2[i] == '\0'; 
    
    return equal;
}
/*indica si la cadena guardada en s1 es menor o igual que la guardada en s2 en el sentido
del orden alfabético*/
bool fstring_less_eq(fixstring s1, fixstring s2) {
    //COMPLETAR
    
    int i = 0;
    bool less_eq = true;
     
    while(s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]){
       i++;
    }
    less_eq = s1[i] < s2[i];
   
    /*if(s1[i] != '\0' && s2[i] == '\0'){
        less_eq = s2[i] != '\0';
    }*/
    return less_eq;  
    
}



