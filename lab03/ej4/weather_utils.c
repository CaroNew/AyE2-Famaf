#include <stdio.h>
#include <stdbool.h>

#include "array_helpers.h"
#include "weather_utils.h"



int min_temp_hist(WeatherTable weather){
    int min_m = weather[0][0][0]._min_temp;
    
    for(unsigned int year = 0; year < YEARS; year++){
        for(unsigned int month = 0; month < MONTHS; month++){
            for(unsigned int day = 0; day < DAYS; day++){
                if(weather[year][month][day]._min_temp < min_m){
                    min_m = weather[year][month][day]._min_temp;
                }
            }
        }   
    }


    return min_m;
}

void proc_max_anual(WeatherTable a, int output[YEARS]) {
    int max_t = 0; 
    for (unsigned int year = 0; year < YEARS; year++) {
        for(unsigned int month = 0; month < MONTHS; month ++){
            for(unsigned int day = 0; day < DAYS; day++){
                if(a[year][month][day]._max_temp > max_t){
                    max_t = a[year][month][day]._max_temp;
                }
            }
        }
        output[year + 1980] = max_t;
        max_t = 0;
        // la mayor temperatura máxima del año 'year' + 1980
    }
}


void proc_max_pres_m(WeatherTable a, unsigned int output[YEARS]){
    
    for (unsigned int year = 0; year < YEARS; year++) {
        unsigned int maxperday = 0; 
        unsigned int maxpermonth = 0;
        for(unsigned int month = 0; month < MONTHS; month ++){
            for(unsigned int day = 0; day < DAYS; day++){
                if(a[year][month][day]._rainfall >= maxperday){
                    maxperday = a[year][month][day]._rainfall;
                }
            }
            if(maxperday > maxpermonth){
                maxpermonth = maxperday;
                output[year + 1980] = month+1;
            }
        }
    }
}
