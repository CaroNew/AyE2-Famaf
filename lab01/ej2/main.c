/* First, the standard lib includes, alphabetically ordered */
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Loads an array given in a file in disk and prints it on the screen."
           "\n\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;
    // Program takes exactly two arguments
    // (the program's name itself and the input-filepath)
    bool valid_args_count = (argc == 2);

    if (!valid_args_count) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int array_from_file(int array[],
                             unsigned int max_size,
                             const char *filepath) {
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
    
    if(res != 0){
        printf("\nAlgo fallo al cerrar el archivo\n\n");
    }
    
    return real_length;
    
}

unsigned int array_from_stdin(int array[],
                             unsigned int max_size) {
    
    unsigned int size_max = max_size;
    unsigned int actual_size = 0;
    unsigned int i = 0;
    int res = 0;
    
    printf("\nIngrese solo enteros:\n\n");
    
    while(res != EOF){
        int value;
        res = fscanf(stdin,"%d", &value);
        
        if(res == 0){
            printf("\nDebe ingresar un entero!!!\n\n");
            exit(EXIT_FAILURE);
        }
        
        if(res != EOF){
            array[i] = value;
            i++;
            
            if(i >= size_max){
                printf("\nTamaño no permitido!!!\n\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    
    actual_size = i;
    
    return actual_size;
}                       

void array_dump(int a[], unsigned int length) {
    //your code here!!!
    
    printf("\n[");
    if(length != 0){
        for(unsigned int i = 0; i < length; i++){
            if(i == length-1){
        	    printf("%d]\n\n", a[i]);
            }else{
                printf("%d, ", a[i]);
            }
        }
    }else{
        printf(" ]\n\n");
    }
}


int main(/*int argc, char *argv[]*/) {
    //char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    //filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
