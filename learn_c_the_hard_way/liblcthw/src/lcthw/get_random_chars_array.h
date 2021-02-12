#ifndef lcthw_get_random_chars_array_h
#define lcthw_get_random_chars_array_h

#include <string.h>
#include <time.h>
#include <stdlib.h>

#define NUM_VALUES 5000

int my_rand(int min, int max);

char get_random_char_lower(void);

void get_random_chars_lower(int length, char *result);

void fill_values(char **values);

#endif 
