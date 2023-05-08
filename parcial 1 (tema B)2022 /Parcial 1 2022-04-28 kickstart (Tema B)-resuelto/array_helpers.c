/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
* @brief returns true when reach last entry in flight table
* @return True when is the last entre of the flight table, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DeliveryTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: flight with %u %s arrived at %u:00", f.code, f.items_amount, f.type == 0 ? "boxes" : "letters", f.hour - 1);
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}


unsigned int extra_space_fee_cost (DeliveryTable a) {
  unsigned int fees = 0;
  unsigned int sum_box = 0;
  unsigned int sum_letter = 0;
      for(unsigned int j = 0; j <= FEE_CLOSE_HOUR; j++){
          sum_box += a[boxes][j].items_amount;
          sum_letter += a[letters][j].items_amount;
      }
      if(sum_box > MAX_ALLOWED_BOXES){
              sum_box -= MAX_ALLOWED_BOXES;
              fees = sum_box * BOX_PENALTY;
      }
      if(sum_letter > MAX_ALLOWED_LETTERS){
          sum_letter -= MAX_ALLOWED_LETTERS;
          
      }
  
      fees += sum_letter * LETTER_PENALTY;
  return fees;
}


void array_from_file(DeliveryTable array, const char *filepath) {
  FILE *file = NULL;
  unsigned int hour_b = 0;
  unsigned int hour_l = 0;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  int i = 0;
  while (!feof(file)) {
    int res = fscanf(file,"_%c_", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    Flight flight_boxes = flight_from_file(file, code, boxes);
    Flight flight_letters = flight_from_file(file, code, letters);
    
    hour_b = flight_boxes.hour;
    hour_l = flight_letters.hour;
    
    array[boxes][hour_b - 1] = flight_boxes;
    array[letters][hour_l - 1] = flight_letters;
    
    ++i;
  }
}
