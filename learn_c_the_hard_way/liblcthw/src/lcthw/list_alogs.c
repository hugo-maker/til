#include "lcthw/list_alogs.h"
#include "lcthw/dbg.h"

inline void ListNode_swap(ListNode *a, ListNode *b)
{
  void *temp = a->value;
  a->value = b->value;
  b->value = temp;
}

/*
int List_bubble_sort(List *list, List_compare cmp)
{
  int sorted = 1;
  
  if (List_count(list) <= 1)
  {
    return 0; // already sorted
  }

  do
  {
    sorted = 1;
    LIST_FOREACH(list, first, next, cur)
    for (cur = list->first; cur != NULL; cur = cur->next)
    {
      if (cur->next)
      {
        if (cmp(cur->value, cur->next->value) > 0)
        {
          ListNode_swap(cur, cur->next);
          sorted = 0;
        }
      }
    }
  } while (!sorted);

  return 0;
}
*/

/*
for(i=0;i<data_count-1;i++)
{
  for(j=data_count-1;j>i;j--)
  {
    p = head;
    for(k=0,p=head;k<j-1;k++)
    {
      back = p;	//1つ前のノードをbackに格納
      p = p->next; //比較先のノードをpに格納
      
      //backとpを絶対値に関して比較
      if(fabs(p->data)<fabs(back->data))
      {
        tmp = p->data;
        p->data = back->data;
        back->data = tmp;
      }
    }
  }
}
*/


int List_bubble_sort(List *list, List_compare cmp)
{
  int i = 0;
  int j = 0;
  int k = 0;

  struct ListNode *cur;
  cur = list->first;

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
      cur = list->first;
      for (k = 0, cur = list->first; k < j- 1; k++)
      {
        if (cur->next)
        {
          if (cmp(cur->value, cur->next->value) > 0)
          {
            ListNode_swap(cur, cur->next);
            sorted = 0;
          }
        }
      }
    }
    if (sorted)
    {
      break;
    }
  }

  return 0;
}

inline List *List_merge(List *left, List *right, List_compare cmp)
{
  List *result = List_create();
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
}

List *List_merge_sort(List *list, List_compare cmp)
{
  if (List_count(list) <= 1)
  {
    return list;
  }

  List *left;
  List *right;
  int middle = List_count(list) / 2;

  List_split(list, middle, &left, &right);

  left = List_merge_sort(left, cmp);
  right = List_merge_sort(right, cmp);

  List *merged = List_merge(left, right, cmp);

  List_destroy(left);
  List_destroy(right);

  return merged;
}
