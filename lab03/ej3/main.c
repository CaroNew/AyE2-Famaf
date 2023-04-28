#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"

#define MAX_SIZE 1000

static char* control_path(int argc, char* argv[]){
    char *s = NULL;
    
    if(argc != 2){
        printf("Wrong number of arguments! \n"
        "use: <name_program> file_name.in\n");
        exit(EXIT_FAILURE);        
    }
    s = argv[1];  
    
    return s;
}

int main(int argc, char* argv[]) {
    //FILE *file;
    char* filepath = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    /* -- completar -- */
    /*checks if the filepath is correct*/
    filepath = control_path(argc, argv);
    /*returns the length of the file*/
    length = data_from_file(filepath, indexes, letters, MAX_SIZE);
    /*sort the letters*/
    sort_letters(sorted, indexes, letters, length);
    /*print the phrase*/
    dump(sorted, length);

    return EXIT_SUCCESS;
}

