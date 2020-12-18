#include "lcthw/list_alogs.h"
#include "lcthw/dbg.h"

/*
procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n-1 inclusive do
            // if this pair is out of order
            if A[i-1] > A[i] then
                // swap them and remember something changed
                swap(A[i-1], A[i])
                swapped := true
            end if
        end for
    until not swapped
end procedure
*/

typedef int (*List_compare)(const void *a, const void *b);

int is_sorted(List *list)
{
  LIST_FOREACH(list, first, next, cur)
  {
    if (cur->next && strcmp(cur->value, cur->next->value) > 0)
    {
      debug("%s %s", (char *)cur->value, (char *)cur->next->value);
      return 0;
    }
  }

  return 1;
}

int List_bubble_sort(List *list, List_compare cmp)
{
  check(list != NULL, "Invalid list.");
  // see ex18
  void *temp = NULL;
  int i = 0;
  int j = 0;
  int count = List_count(list);
  check(count != 0, "list doesn't have any elements.");

  for (i = 0; i < count; i++)
  {
    if (is_sorted(list) == 0)
    {
      break;
    }

    for (j = 0; j < count - 1; j++)
    {
      if (cmp(list[j], list[j + 1]) > 0)
      {
        temp = list[j + 1];
        list[j + 1] = list[j];
        list[j] = temp;
      }
    }
  }

  return 0;

error:
  return 1;
}