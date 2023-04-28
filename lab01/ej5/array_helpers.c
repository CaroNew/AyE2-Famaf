#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"

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
    	printf("\nError al leer tamaño\n\n");
    	exit(EXIT_FAILURE);
    }
    
    if(real_length > max ){
        printf("\nTamaño excede al máximo permitido\n\n");
        exit(EXIT_FAILURE);
    }
    
    /*if(real_length < -1){
        printf("el archivo esta vacío o es incorrecto\n");
        exit(EXIT_FAILURE);
    }*/
    
     
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
        printf("\nAlgo fallo al cerrar el archivo!\n\n");
        exit(EXIT_FAILURE);
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


mybool array_is_sorted(int a[], unsigned int length){
	mybool is_sorted = true;
    unsigned int i = 0;
    
    
    while(i < length-1 && is_sorted){
        is_sorted = a[i] <= a[i+1];
    	i++;
    }



	return is_sorted;
}





