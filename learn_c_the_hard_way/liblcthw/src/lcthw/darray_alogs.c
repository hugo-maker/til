// may need to install libbsd-dev to use heapsort and mergesort
// I think these two are not included in glibc
#include "lcthw/darray_alogs.h"
#include <stdlib.h>

int DArray_qsort(DArray * array, DArray_compare cmp)
{
  qsort(array->contents, DArray_count(array), sizeof(void *), cmp);
  return 0;
}

int DArray_heapsort(DArray * array, DArray_compare cmp)
{
  return heapsort(array->contents, DArray_count(array),
      sizeof(void *), cmp);
}

int DArray_mergesort(DArray * array, DArray_compare cmp)
{
  return mergesort(array->contents, DArray_count(array),
      sizeof(void *), cmp);
}
