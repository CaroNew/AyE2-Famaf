#ifndef _WEATHER_UTILS_C
#define _WEATHER_UTILS_C
#include <stdbool.h>


/*Una función que obtenga la menor temperatura mínima histórica 
registrada en la ciudad de Córdoba según los datos del arreglo.*/
int min_temp_hist(WeatherTable weather);


void proc_max_anual(WeatherTable a, int output[YEARS]);

/*Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en que se registró la mayor cantidad mensual de precipitaciones.
*/
void proc_max_pres_m(WeatherTable a, unsigned int output[YEARS]);

#endif
