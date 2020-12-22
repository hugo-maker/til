#include "lcthw/list_alogs.h"
#include "lcthw/dbg.h"

inline void ListNode_swap(ListNode *a, ListNode *b)
{
  check_mem(a);
  check_mem(b);
  void *temp = a->value;
  a->value = b->value;
  b->value = temp;

error:
  return;
}

int List_bubble_sort(List *list, List_compare cmp)
{
  check(list != NULL, "Invalid list.");
  int i = 0;
  int j = 0;

  struct ListNode *cur;

  int count = List_count(list);
  if (count <= 1)
  {
    return 0; // already sorted
  }

  int sorted = 1;
  for (i = 0; i < count - 1; i++)
  {
    sorted = 1;
    for (j = count - 1; j > i; j--)
    {
      for (cur = list->first; cur->next != NULL; cur = cur->next)
      {
        if (cmp(cur->value, cur->next->value) > 0)
        {
          ListNode_swap(cur, cur->next);
          sorted = 0;
        }
      }
    }
    if (sorted)
    {
      break;
    }
  }

  return 0;

error:
  return 1;
}

inline List *List_merge(List *left, List *right, List_compare cmp)
{
  check(left != NULL, "Invalid list.");
  check(right != NULL, "Invalid list.");

  List *result = List_create();
  check(result != NULL, "List_create failed.");

  void *val = NULL;

  while (List_count(left) > 0 || List_count(right) > 0)
  {
    if (List_count(left) > 0 && List_count(right) > 0)
    {
      if (cmp(List_first(left), List_first(right)) <= 0)
      {
        val = List_shift(left);
      }
      else
      {
        val = List_shift(right);
      }

      List_push(result, val);
    }
    else if (List_count(left) > 0)
    {
      val = List_shift(left);
      List_push(result, val);
    }
    else if (List_count(right) > 0)
    {
      val = List_shift(right);
      List_push(result, val);
    }
  }

  return result;

error:
  return NULL;
}

List *List_merge_sort(List *list, List_compare cmp)
{
  check(list != NULL, "Invalid list.");
  if (List_count(list) <= 1)
  {
    return list;
  }

  List *left;
  List *right;
  int middle = List_count(list) / 2;

  List_split(list, middle, &left, &right);

  left = List_merge_sort(left, cmp);
  check(left != NULL, "List_merge_sort for left failed.");

  right = List_merge_sort(right, cmp);
  check(right != NULL, "List_merge_sort for right failed.");

  List *merged = List_merge(left, right, cmp);

  List_destroy(left);
  List_destroy(right);

  return merged;

error:
  return NULL;
}
