#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4

struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

bool greater(int a, int b){
    bool is_greater = a >= b;
    return is_greater;
}

bool lower(int a, int b){
    bool is_lower = a <= b;
    return is_lower;
}

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data res;
   
    unsigned int i = 0;
    bool is_greater = true;
    bool is_lower = true;
    bool is_in = false;
    

    while(i < length){

        if(!is_in){
            is_in = arr[i] == value;
            res.where = i;
        } 

        if(is_greater){
            is_greater = greater(value, arr[i]);
        }
        if(is_lower){
            is_lower = lower(value, arr[i]);
        }

        
        i++;
    }
    
    res.is_upperbound = is_greater;
    res.is_lowerbound = is_lower;
    res.exists = is_in;
    if(!res.exists){
       res.where = 0;
    }
    return res;
}

int main(void) {
    
    int array[ARRAY_SIZE];
    int value = 0;

    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("Ingrese un entero: ");
        scanf("%d", &array[i]);
    }
    
    printf("Ingrese el valor a verificar: ");
    scanf("%d", &value);
    
    
    struct bound_data result = check_bound(value, array, ARRAY_SIZE);
    
    printf("Es cota superior: %d\n", result.is_upperbound); 
    printf("Es cota inferior: %d\n", result.is_lowerbound); 
       
    if(result.exists){
    
        if(result.is_upperbound){
            printf("Es maximo\n");
        }else if(result.is_lowerbound){
            printf("Es minimo\n");
        }

        printf("Posición en el arreglo: %u\n", result.where); 
    }else{
        printf("No existe en el arreglo\n");
    }
    return EXIT_SUCCESS;
}



