#ifndef _HELPERS_H
#define _HELPERS_H

#include <stdlib.h>
void dump(char a[], unsigned int length);

unsigned int data_from_file(const char *path, unsigned int indexes[],
                              char letters[], unsigned int max_size);
                              
void sort_letters(char sorted[], unsigned int indexes[], char letters[], 
                                                    unsigned int length);



#endif
