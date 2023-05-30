#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *string_clone(const char *str, size_t length) {
    /*char clone[length + 1];*/
    char *clone = calloc(length, sizeof(char));
    /*char *output = clone; aca no se hace una copia, si no que output se le asigna la direccion de memoria de clone y no a la cadena de caracteres a la que apunta clone*/
    for (size_t i=0; i<length; i++) {
        clone[i] = str[i];
    }
    clone[length] = '\0';
    return clone;
}


int main(void) {
    char *original=""
         "______ time ago in a galaxy far, far away...\n\n\n"
         "         _______..___________.     ___      .______             \n"
         "        /       ||           |    /   \\     |   _  \\          \n"
         "       |   (----``---|  |----`   /  ^  \\    |  |_)  |          \n"
         "        \\   \\        |  |       /  /_\\  \\   |      /        \n"
         "    .----)   |       |  |      /  _____  \\  |  |\\  \\----.    \n"
         "    |_______/        |__|     /__/     \\__\\ | _| `._____|     \n"
         "                                                                \n"
         "____    __    ____      ___      .______           _______.     \n"
         "\\   \\  /  \\  /   /     /   \\     |   _  \\         /       |\n"
         " \\   \\/    \\/   /     /  ^  \\    |  |_)  |       |   (----` \n"
         "  \\            /     /  /_\\  \\   |      /         \\   \\    \n"
         "   \\    /\\    /     /  _____  \\  |  |\\  \\----..----)   |   \n"
         "    \\__/  \\__/     /__/     \\__\\ | _| `._____||_______/     \n"
         "\n\n\n"
         "                     Episode IV \n\n"
         "                     A NEW HOPE \n\n"
         "                     It is a period of civil war. Rebel\n"
         "spaceships, striking from a hidden base, have won their\n"
         "first victory against the evil Galactic Empire. During the\n"
         "battle, Rebel spies managed to steal secret plans to the\n"
         "Empire’s ultimate weapon, the DEATH STAR, an armored space\n"
         "station with enough power to destroy an entire planet.\n"
         "Pursued by the Empire’s sinister agents, Princess Leia\n"
         "races home aboard her starship, custodian of the stolen\n"
         "plans that can save her people and restore freedom to the\n"
         "galaxy...\n";
    char *copy=NULL;
    size_t size = strlen(original);
    copy = string_clone(original, size);
    //copy = string_clone(original, sizeof(original)/ sizeof(char) - 1);
    printf("Original: %s\n", original);
    copy[0] = 'A';
    copy[1] = ' ';
    copy[2] = 'l';
    copy[3] = 'o';
    copy[4] = 'n';
    copy[5] = 'g';
    printf("Copia   : %s\n", copy);
    free(copy); /*valgrid me dijo que hiciera esto :P */
    
    

    /*error devuelto por gcc: "error: division ‘sizeof (char *) / sizeof (char)’ does
     not compute the number of array elements [-Werror=sizeof-pointer-div]".
    
    desmenuzando el problema y tratando de enteder que se esta haciendo:
    -sizeof() es una funcion que determina el tamaño de un tipo de dato en
    bytes.
    
    Lo que supongo que se está intentado hacer en sizeof(original)/sizeof(char) - 1
    es determinar la cantidad de chars (menos uno por el '\0') que tiene el 
    char *original
    
    copy = string_clone(original, sizeof(original)/ sizeof(char) - 1);
    
    lo que supongo que hace sizeof es devolver el tamaño del puntero original
    y no el tamaño de la cadena de caracteres a la que apunta 
    y por eso el error.
    
    
    */


    return EXIT_SUCCESS;
}

