#ifndef lcthw_List_alogs_h
#define lcthw_List_alogs_h

#include "lcthw/list.h"

typedef int (*List_compare)(const void *a, const void *b);

int List_bubble_sort(List *list, List_compare cmp);
List *List_merge_sort(List *list, List_compare cmp);
List *iterative_merge_sort(List *list);

#endif
