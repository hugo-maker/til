#include "lcthw/list_alogs.h"
#include "lcthw/dbg.h"

procedure bubbleSort(A : list of sortable items)
    n := length(A)
    repeat
        swapped := false
        for i := 1 to n-1 inclusive do
            /* if this pair is out of order */
            if A[i-1] > A[i] then
                /* swap them and remember something changed */
                swap(A[i-1], A[i])
                swapped := true
            end if
        end for
    until not swapped
end procedure



typedef int (*List_compare)(const char *s1, const char *s2);

int List_bubble_sort(List *list, List_compare cmp)
{
  // see ex18
  int temp = 0;
  int i = 0;
  int j = 0;
  int count = List_count(list);

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
}
