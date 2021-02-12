#ifndef lcthw_List_h
#define lcthw_List_h

#include <stdlib.h>

struct ListNode;

// Structure for the contents, nodes with links between them.
typedef struct ListNode
{
    struct ListNode *next;
    struct ListNode *prev;
    void *value;
} ListNode;

// Outer structure, which is nothing more than a container for ListNode structs.
typedef struct List
{
    int count;
    ListNode *first;
    ListNode *last;
} List;

typedef int (*List_compare)(const void *a, const void *b);

// Just creates the main List struct.
List *List_create();
// Destorys a List and all of its elements.
void List_destroy(List *list);
// Frees only the values in each node(leave the nodes themselves).
void List_clear(List *list);
// Clears and destroys a list.
void List_clear_destroy(List *list);

// Returns the number of elements of the list, but doesn't remove it.
#define List_count(A) ((A)->count)
// Returns the first element of the list, but doesn't remove it.
#define List_first(A) ((A)->first != NULL ? (A)->first->value : NULL)
// Returns the last element of the list, but doesn't remove it.
#define List_last(A) ((A)->last != NULL ? (A)->last->value : NULL)

// Adds a new element to the end of the list
void List_push(List *list, void *value);
// Takes the last element off and returns it.
void *List_pop(List *list);

// Adds a new element to the front of the list.
void List_unshift(List *list, void *value);
// Takes the first element off and returns it.
void *List_shift(List *list);
// Does all the removal when you call List_pop or List_shift.
void *List_remove(List *list, ListNode *node);

int List_dump(List *list, const char *name);
int List_split(List *list, int count, List **p_left, List **p_right);

void List_insert_sorted(List *list, void *value, List_compare cmp);

// Iterates over the elements in the list.
// L = List, S = Start, M = Move?, V = Variable?
#define LIST_FOREACH(L, S, M, V) ListNode *_node = NULL;\
                                                    ListNode *V = NULL;\
for (V = _node = L->S; _node != NULL; V = _node = _node->M)

#endif
