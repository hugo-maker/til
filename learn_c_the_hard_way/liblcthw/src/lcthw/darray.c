#include "lcthw/darray.h"
#include "lcthw/dbg.h"

// ex17.c may help to write this program
DArray *DArray_create(size_t element_size, size_t initial_max)
{
  DArray *array = calloc(1, sizeof(DArray));

  array->end = 0;
  array->max = initial_max;
  array->element_size = element_size;
  array->expand_rate = DEFAULT_EXPAND_RATE;
  array->contents = calloc(1, 
      sizeof(array->element_size) * array->max);

  return array;
}

int DArray_expand(DArray *array)
{
  array->max = array->max + array->expand_rate;
  array = realloc(array, sizeof(array->element_size) * array->max);

  return 0;
}

int DArray_contract(DArray *array)
{
  if (array->max < array_expand_rate)
  {
    array->max = array->expand_rate + 1;
  }
  else
  {
    array->max = array->max - array->expand_rate;
  }

  array = realloc(array, sizeof(array->element_size) * array->max);

  return 0;
}

void *DArray_pop(DArray *array)
{
}
