#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int main(void) {
    char user_input[MAX_LENGTH];
    //char *user_input;
    
    printf("Ingrese su nombre y apellido: ");
    /*scanf("%s", user_input);*/
    /*scanf no toma nada despues del espacio, no limita la cantidad de 
     caracteres leídos.*/
    /*char *fgets(char *s, int size, FILE *stream);*/
    fgets(user_input, MAX_LENGTH, stdin);
    size_t size = strlen(user_input);
    user_input[size-1]= '\0';
    
    printf("Te damos la bienvenida %s a este maravilloso programa!\n", user_input);

    return EXIT_SUCCESS;
}

