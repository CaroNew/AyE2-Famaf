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
    printf("%u\n", real_length);
   
    
     
    while(!feof(file)){
        fscanf(file, "%d", &array[i]);
    	i++;
    }  
    printf("%u\n", i); 
    
    
    int res = fclose(file);
    
    printf("%d\n", res);
    
    if(res != 0){
        printf("Algo fallo al cerrar el archivo\n");
    }
    
    return real_length;
    
}

unsigned int array_from_stdin(int array[],
                             unsigned int max_size) {
    unsigned int size = 0;
    unsigned int max = max_size;
    
    printf("ingrese el tamaño del arreglo\n");
    
    fscanf(stdin,"%u", &size);
    
    if(max < size || size <= 0){
        fprintf(stderr, "El tamaño solicitado no es posible\n");
        exit(EXIT_FAILURE);
    }
    
    for(unsigned int i = 0; i < size; i++){
        fscanf(stdin, "%d", &array[i]);
    }
    
    
    
    return size;
}                             
                             
                             



void array_dump(int a[], unsigned int length) {
    //your code here!!!
    
    printf("[");
    for(unsigned int i = 0; i < length; i++){
        
        if(i == length-1){
        	printf("%d]\n", a[i]);
        }else{
            printf("%d, ", a[i]);
        }
         
    }
}


int main(/*int argc, char *argv[]*/) {
    //char *filepath = NULL;

    /* parse the filepath given in command line arguments */
    //filepath = parse_filepath(argc, argv);
    
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];
    
    /* parse the file to fill the array and obtain the actual length */
    //unsigned int length = array_from_file(array, MAX_SIZE, filepath);
    unsigned int length = array_from_stdin(array, MAX_SIZE);
    /*dumping the array*/
    array_dump(array, length);
    
    return EXIT_SUCCESS;
}
