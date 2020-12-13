#include "lcthw/list.h"
#include "lcthw/dbg.h"

List *List_create()
{
  return calloc(1, sizeof(List));
}

void List_destroy(List *list)
{
  check(list != NULL, "Invalid list.");
  LIST_FOREACH(list, first, next, cur)
  {
    if (cur->prev)
    {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);

error:
  return;
}

void List_clear(List *list)
{
  check(list != NULL, "Invalid list.");
  LIST_FOREACH(list, first, next, cur)
  {
    free(cur->value);
  }

error:
  return;
}

void List_clear_destroy(List *list)
{
  //List_clear(list);
  //List_destroy(list);

  check(list != NULL, "Invalid list.");
  LIST_FOREACH(list, first, next, cur)
  {
    free(cur->value);
    if (cur->prev)
    {
      free(cur->prev);
    }
  }

  free(list->last);
  free(list);

error:
  return;
}

void List_push(List *list, void *value)
{
  check(list != NULL, "Invalid list.");
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->last == NULL)
  {
    list->first = node;
    list->last = node;
  }
  else
  {
    list->last->next = node;
    node->prev = list->last;
    list->last = node;
  }

  list->count++;

error:
  return;
}

void *List_pop(List *list)
{
  check(list != NULL, "Invalid list.");
  ListNode *node = list->last;
  return node != NULL ? List_remove(list, node) : NULL;

error:
  return NULL;
}

void List_unshift(List *list, void *value)
{
  check(list != NULL, "Invalid list.");
  ListNode *node = calloc(1, sizeof(ListNode));
  check_mem(node);

  node->value = value;

  if (list->first == NULL)
  {
    list->first = node;
    list->last = node;
  }
  else
  {
    node->next = list->first;
    list->first->prev = node;
    list->first = node;
  }

  list->count++;

error:
  return;
}

void *List_shift(List *list)
{
  check(list != NULL, "Invalid list.");
  ListNode *node = list->first;
  return node != NULL ? List_remove(list, node) : NULL;

error:
  return NULL;
}

void *List_remove(List *list, ListNode *node)
{
  void *result = NULL;

  check(list != NULL, "Invalid list.");
  check(list->first && list->last, "List is empty.");
  check(node, "node can't be NULL.");

  if (node == list->first && node == list->last)
  {
    list->first = NULL;
    list->last = NULL;
  }
  else if (node == list->first)
  {
    list->first = node->next;
    check(list->first != NULL,
        "Invalid list, somehow got a first that is NULL.");
    list->first->prev = NULL;
  }
  else if (node == list->last)
  {
    list->last = node->prev;
    check(list->last != NULL, 
        "Invalid list, somehow got a next that is NULL.");
    list->last->next = NULL;
  }
  else
  {
    ListNode *after = node->next;
    ListNode *before = node->prev;
    after->prev = before;
    before->next = after;
  }

  list->count--;
  result = node->value;
  free(node);

error:
  return result;
}

/*
 * Takes a list and a count.
 * list = List 
 * count = number of items that should be in the left list
 * left = List pointer that will be assigned to left list
 * right = List pointer that will be assigned to right list
 */

/*
 * Original list is modified to create split lists.
 * Once the split is complete, Old list will be  empty.
 */

int List_split(List *list, int count, List **p_left, List **p_right)
{
  check(list != NULL, "Invalid list.");
  check(count > 0, "Split count must be positive.");

  int size = List_count(list);
  check(count <= size,
      "Split count (%d) graeter than List size (%d)", count, size);

  *p_left = List_create();
  *p_right = List_create();

  // maybe need to check List_create succeeded or not.

  List *left = *p_left;
  List *right = *p_right;

  int i = 0;
  while (i++ < count)
  {
    List_push(left, List_shift(list));
  }

  i = 0;
  while (i++ < size - count)
  {
    List_push(right, List_shift(list));
  }

  return 0;

error:
  return 1;
}

int List_dump(List *list, const char *name)
{
  check(list != NULL, "Invalid list.");

  int i = 1;
  LIST_FOREACH(list, first, next, cur)
  {
    check(cur != NULL, "Cannnot print NULL ListNode.");
    printf("List(%s) Node(%d): %s\n", name, i++, cur->value);
  }

  return 0;

error:
  return 1;
}
