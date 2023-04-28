#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    //your code here!!!
    unsigned int max = max_size;
    unsigned int real_length = 0;
    unsigned int i = 0;
    
    
    
    
    FILE *file;
    
    file = fopen(filepath, "r");
    
    if(file == NULL){
        printf("Error al abrir el archivo\n");
        exit(EXIT_FAILURE);
    }
    
    int result = fscanf(file,"%u", &real_length);
    
    if(result != 1){
    	printf("error al leer tamaño\n");
    	exit(EXIT_FAILURE);
    }
    
    if(real_length > max ){
        printf("Tamaño excede al máximo permitido\n");
        exit(EXIT_FAILURE);
    }
    
     
    while(i < real_length){
        int res = fscanf(file, "%d", &array[i]);
    	i++;
    	if(res == -1){
    	    printf("\nFallo de almacenamiento en array!\n\n");
    	    exit(EXIT_FAILURE);
    	}
    }   
    
     
    int res = fclose(file);
    
    if(res != 0){
        printf("Algo fallo al cerrar el archivo\n");
    }
    
    return real_length;
    
}




void array_dump(int a[], unsigned int length) {
    //your code here!!!
    
    printf("\n[");
    if(length == 0){
        printf(" ]\n\n");
    }else{
        for(unsigned int i = 0; i < length; i++){
            if(i == length-1){
        	    printf("%d]\n\n", a[i]);
            }else{
                printf("%d, ", a[i]);
            }
         }
    }
}


bool array_is_sorted(int a[], unsigned int length){
	bool is_sorted = true;
    unsigned int i = 0;
    
    
    while(i < length-1 && is_sorted){
        is_sorted = a[i] <= a[i+1];
    	i++;
    }



	return is_sorted;
}
/*Dado un array a[] y dos índices i, j debe intercambiar los valores de dichas
posiciones.*/

void array_swap(int a[], unsigned int i, unsigned int j){
    int aux;
    
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
    
}





