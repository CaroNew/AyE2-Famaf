/*
  @file weather.c
  @brief Implements weather mesuarement structure and methods
*/
#include <stdlib.h>
#include "weather.h"

static const int AMOUNT_OF_WEATHER_VARS = 6 ;

Weather weather_from_file(FILE* file)
{
    Weather weather;
    /* Completar aqui */
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    /*EXPECTED_WEATHER_FILE_FORMAT = "%d %d %d %u %u %u" es un constante
    que hace que se vea mas bonito jeje*/
    int res = fscanf(file, EXPECTED_WEATHER_FILE_FORMAT, &weather._average_temp,
                                         &weather._max_temp, &weather._min_temp,
                                         &weather._pressure, &weather._moisture,
                                         &weather._rainfall);
    /* AMOUNT_OF_WEATHER_VARS = 6 puedo usar esa constante*/
    if(res != AMOUNT_OF_WEATHER_VARS){
        fprintf(stderr, "Invalid array.\n");
        exit(EXIT_FAILURE);
    }
    
    
    return weather;
}

void weather_to_file(FILE* file, Weather weather)
{
    fprintf(file, EXPECTED_WEATHER_FILE_FORMAT, weather._average_temp, 
            weather._max_temp, weather._min_temp, weather._pressure, weather._moisture, weather._rainfall);
}
