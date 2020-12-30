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

void iterative_merge(ListNode *start1, ListNode *end1,
    ListNode *start2, ListNode *end2, List_compare cmp) 
{ 
  check_mem(start1);
  check_mem(end1);
  check_mem(start2);
  check_mem(end2);
	// Making sure that first node of second list is higher. 
	ListNode *temp = NULL; 

  printf("-----Before swap-----\n");
  printf("start1 before swap: %s : %p\n", (char *)start1->value, start1->value);
  printf("start2 before swap: %s : %p\n", (char *)start2->value, start2->value);
  printf("end1 before swap: %s : %p\n", (char *)end1->value, end1->value);
  printf("end2 before swap: %s : %p\n", (char *)end2->value, end2->value);
  printf("-----Before swap-----\n");
  putchar('\n');

  printf("-----Cmp-----\n");
  void *tmp;

	if (cmp(start1->value, start2->value) > 0)
  { 
    int result = cmp(start1->value, start2->value);
    printf("strcmp(start1->value, start2->value) returns %d\n",
        result);
		//ListNode_swap(start1, start2);
		//ListNode_swap(end1, end2);
    tmp = start1->value;
    printf("tmp: %s %p\n", (char *)tmp, tmp);
    start1->value = start2->value;
    printf("start1: %s %p\n", (char *)start1->value, start1->value);
    start2->value = tmp;
    printf("start2: %s %p\n", (char *)start2->value, start2->value);
	} 
  
  // Separate the cmp part. But still can't work correctly.
  if (cmp(end1->value, end2->value) > 0)
  {
    tmp = end1->value;
    printf("tmp: %s %p\n", (char *)tmp, tmp);
    end1->value = end2->value;
    printf("end1: %s %p\n", (char *)end1->value, end1->value);
    end2->value = tmp;
    printf("end2: %s %p\n", (char *)end2->value, end2->value);
  }
 
  printf("-----Cmp-----\n");
  putchar('\n');

  printf("-----After swap-----\n");
  printf("start1 after swap: %s : %p\n", (char *)start1->value, start1->value);
  printf("start2 after swap: %s : %p\n", (char *)start2->value, start2->value);
  printf("end1 after swap: %s : %p\n", (char *)end1->value, end1->value);
  printf("end2 after swap: %s : %p\n", (char *)end2->value, end2->value);
  printf("-----After swap-----\n");
  putchar('\n');

	// Merging remaining nodes 
  printf("-----Merging remaining nodes-----\n");
  ListNode *astart = start1;
  ListNode *aend = end1;
  ListNode *bstart = start2;
  ListNode *bend = end2;
  // below line is necessary?
  // we can access list2->last->next or bend->next
  ListNode *bendnext = end2->next;

	while (astart != aend && bstart != bendnext) 
  { 
    if (cmp(astart->next->value, bstart->value) > 0)
    { 
			temp = bstart->next; 
			bstart->next = astart->next; 
			astart->next = bstart; 
			bstart = temp; 
		} 
		astart = astart->next; 
	} 
  if (cmp(astart->value, aend->value) == 0)
  {
    astart->next = bstart; 
  }
	else
  {
    end2->value = end1->value;
  }
  printf("-----Merging remaining nodes-----\n");
  putchar('\n');

  printf("-----End of iterative_merge-----\n");
  printf("astart: %s\n", (char *)astart->value);
  printf("aend: %s\n", (char *)aend->value);
  if (bstart)
  {
    printf("bstart: %s\n", (char *)bstart->value);
  }
  printf("bend: %s\n", (char *)bend->value);
  if (bendnext)
  {
    printf("bend->next: %s\n", (char *)bendnext->value);
  }
  printf("end1: %s\n", (char *)end1->value);
  printf("end2: %s\n", (char *)end2->value);
  if (bendnext)
  {
    printf("bend->next: %s\n", (char *)bendnext->value);
  }
  printf("-----End of iterative_merge-----\n");
  putchar('\n');

error:
  return;
} 

List *iterative_merge_sort(List *list) 
{ 
  check(list != NULL, "Invalid list.");
  check(list->first != NULL, "Don't have first elements.");

  ListNode *start1 = NULL;
  ListNode *end1 = NULL;
  ListNode *start2 = NULL;
  ListNode *end2 = NULL;
  // below line is necessary?
  ListNode *prevend = NULL;

  int length = List_count(list);

	for (int gap = 1; gap < length; gap = gap * 2)
  { 
		start1 = list->first;
		while (start1) 
    { 
			// If this is first iteration 
			int is_first_sorted = 0; 
      // Can use comparison operator here?
			if (start1 == list->first) 
      {
				is_first_sorted = 1; 
      }

			// First part for merging 
      printf("-----First part for merging-----\n");
			int counter = gap; 
			end1 = start1; 
			while (--counter && end1->next) 
      {
				end1 = end1->next; 
        printf("counter: %d\tend1: %s\n", counter, (char *)end1->value);
      }
      printf("-----First part for merging-----\n");
      putchar('\n');

			// Second part for merging 
      printf("-----Second part for merging-----\n");
			start2 = end1->next; 
			if (!start2) 
      {
				break; 
      }
			counter = gap; 
			end2 = start2; 
			while (--counter && end2->next) 
      {
				end2 = end2->next; 
        printf("counter: %d\tend2: %s\n", counter, (char *)end2->value);
      }
      printf("-----Second part for merging(if this line is not printed, start2 == NULL)-----\n");
      putchar('\n');

			// To store for next iteration. 
			ListNode *temp = end2->next; 

			// Merging two parts. 
      printf("-----Passing to iterative_merge-----\n");
      printf("gap :%d\n", gap);
      printf("start1 passing to iterative_merge: %s : %p\n", (char *)start1->value, start1->value);
      printf("start2 passing to iterative_merge: %s : %p\n", (char *)start2->value, start2->value);
      printf("end1 passing to iterative_merge: %s : %p\n", (char *)end1->value, end1->value);
      printf("end2 passing to iterative_merge: %s : %p\n", (char *)end2->value, end2->value);
      printf("-----Passing to iterative_merge-----\n");
      putchar('\n');
			iterative_merge(start1, end1, start2, end2, (List_compare)strcmp); 

			// Update head for first iteration, else append after previous list 
			if (is_first_sorted) 
      {
				list->first = start1; 
      }
			else
      {
				prevend->next = start1; 
      }

			prevend = end2; 
			start1 = temp; 
		} 
		prevend->next = start1; 
    printf("-----Return from iterative_merge-----\n");
    if (prevend)
    {
      printf("prevend: %s\n", (char *)prevend->value);
    }
    if (start1)
    {
      printf("start1: %s\n", (char *)start1->value);
    }
    if (prevend->next)
    {
      printf("prevend->next: %s\n", (char *)prevend->next->value);
    }
    printf("gap :%d\n", gap);
    List_dump(list, "words after iterative merge");
    printf("-----Return from iterative_merge-----\n");
    putchar('\n');
	} 

  return list;
error:
  return NULL;
} 
