#ifndef lcthw_vl_get_random_chars_array_h
#define lcthw_vl_get_random_chars_array_h

#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_NUM 10000

char **values;

int my_rand(int min, int max);

char get_random_char_lower(void);

void get_random_chars_lower(int length, char *result);

void fill_values(char **values, int num_values);

#endif 
