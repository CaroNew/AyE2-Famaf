#include "array_helpers.h"
#include <stdio.h>
#include <stdlib.h>


unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
    //your code here!!!
    //your code here!!!
    unsigned int max = max_size;
    unsigned int real_length = 0;
    unsigned int i = 0;
    int stream_control;
    
    
    
    
    FILE *file = NULL;
    
    file = fopen(filepath, "r");
    /*si el file no se pudo abrir, devuelve NULL*/
    if(file == NULL){
        printf("\nError al abrir el archivo\n\n");
        exit(EXIT_FAILURE);
    }
    
    int result = fscanf(file,"%u", &real_length);
    
    if(result != 1){
    	printf("\nerror al leer tamaño\n\n");
    	exit(EXIT_FAILURE);
    }
    
    if(real_length > max ){
        printf("\nTamaño excede al máximo permitido\n\n");
        exit(EXIT_FAILURE);
    }
    
    while(!feof(file) && real_length > 0){
        int value;
        /*fscanf devuelve el numero de valores que han sido leidos*/
        stream_control = fscanf(file, "%d", &value);
        
        if(stream_control == 1){
            array[i] = value;
    	    i++;
    	}
    }  
    
    if(i != real_length){
        printf("\nATENCION!!!"
        "\nHay una diferencia entre la cantidad "
        "de elementos y los valores leidos\n\n");
        exit(EXIT_FAILURE);
        
    }

    
    
    int res = fclose(file);
    /*creo que esto no es necesario*/
    if(res != 0){
        printf("\nAlgo fallo al cerrar el archivo\n\n");
    }
    
    return real_length;
    
}




void array_dump(int a[], unsigned int length) {
    //your code here!!!
    printf("\n[");
    if(length != 0){
        for(unsigned int i = 0; i < length; i++){
            (i == length-1) ? printf("%d]\n\n", a[i]) : printf("%d, ", a[i]);
        }
    }else{
        printf(" ]\n\n");
    }
}
