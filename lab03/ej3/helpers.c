#include <stdlib.h>
#include <stdio.h>

void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[],
                              char letters[], unsigned int max_size){
    unsigned int length = 0;
    unsigned int size = max_size;
    int  i = 0;
    FILE *file;
    
    file = fopen(path, "r");
    
    if(file == NULL){
        printf("cannot open the file\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(file)){
       int res = fscanf(file, "%u -> *%c*\n", &indexes[i], &letters[i]);
       if(res != 2){
           printf("The number of arguments readed is wrong\n");
           exit(EXIT_FAILURE);
       }
        i++;
    }
    
    length = i;
    
    if(length > size){
        printf("size not allowed\n");
        exit(EXIT_FAILURE);
    
    }
    int control = fclose(file);
    if(control != 0){
        printf("cannot close the file\n");
        exit(EXIT_FAILURE);
    }                          
    return length;                             
}

void sort_letters(char sorted[], unsigned int indexes[], char letters[], 
                                                    unsigned int length){
    unsigned int size = length;
        
    for(unsigned int i = 0; i < size ; i++){
        unsigned int j = indexes[i];
        
        if(j > length){
            printf("index is too high\n");
            exit(EXIT_FAILURE);
        }
            sorted[j] = letters[i];
    }
    
}
