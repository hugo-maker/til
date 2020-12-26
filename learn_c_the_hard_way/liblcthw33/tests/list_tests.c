#include "minunit.h"
#include "lcthw/list.h"
#include <assert.h>

static List *list = NULL;
char *test1 = "test1 data";
char *test2 = "test2 data";
char *test3 = "test3 data";


char *word1 = "a";
char *word2 = "ab";
char *word3 = "abc";
char *word4 = "a";


char *test_create()
{
  list = List_create();
  mu_assert(list != NULL, "Failed to create list.");

  return NULL;
}

char *test_destroy()
{
  List_clear_destroy(list);

  return NULL;
}

char *test_push_pop()
{
  List_push(list, test1);
  mu_assert(List_last(list) == test1, "Wrong last value.");

  List_push(list, test2);
  mu_assert(List_last(list) == test2, "Wrong last value.");

  List_push(list, test3);
  mu_assert(List_last(list) == test3, "Wrong last value.");
  mu_assert(List_count(list) == 3, "Wrong count on push.");

  char *val = List_pop(list);
  mu_assert(val == test3, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test2, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == test1, "Wrong value on pop.");
  mu_assert(List_count(list) == 0, "Wrong count after pop.");

  return NULL;
}

char *test_unshift()
{
  List_unshift(list, test1);
  mu_assert(List_first(list) == test1, "Wrong first value.");

  List_unshift(list, test2);
  mu_assert(List_first(list) == test2, "Wrong second value.");

  List_unshift(list, test3);
  mu_assert(List_first(list) == test3, "Wrong last value.");
  mu_assert(List_count(list) == 3, "Wrong count on unshift.");

  return NULL;
}

char *test_remove()
{
  // we only need to test the middle remove case
  // because push/shift already tests the other cases

  char *val = List_remove(list, list->first->next);
  mu_assert(val == test2, "Wrong removed element.");
  mu_assert(List_count(list) == 2, "Wrong count after remove.");
  mu_assert(List_first(list) == test3, "Wrong first after remove.");
  mu_assert(List_last(list) == test1, "Wrong last after remove.");

  return NULL;
}

char *test_shift()
{
  mu_assert(List_count(list) != 0, "Wrong count before shift.");

  char *val = List_shift(list);
  mu_assert(val == test3, "Wrong value on shift.");

  val = List_shift(list);
  mu_assert(val == test1, "Wrong value on shift.");
  mu_assert(List_count(list) == 0, "Wrong count after shift.");

  return NULL;
}

char *test_split()
{
  List *new_list = List_create();
  List_push(new_list, test1);
  List_push(new_list, test2);
  List_push(new_list, test3);

  mu_assert(List_count(new_list) == 3, "Wrong count on push.");

  List *left = NULL;
  List *right = NULL;

  int rc = List_split(new_list, 4, &left, &right);
  mu_assert(rc == 1, "Split must be failed with lnvalid count.");

  rc = List_split(new_list, 2, &left, &right);
  mu_assert(rc == 0, "Split failed unexpectedly.");

  mu_assert(left != NULL, "Left list still NULL.");
  mu_assert(right != NULL, "Right list still NULL.");

  debug("List_count(left): %d", List_count(left));
  debug("List_count(right): %d", List_count(right));

  mu_assert(List_count(left) == 2, "Left list has incorrect size.");
  mu_assert(List_count(right) == 1, "Right list has incorrect size.");

  mu_assert(List_first(left) == test1, "Left list first value incorrect.");
  mu_assert(List_last(left) == test2, "Left list last value incorrect.");

  mu_assert(List_first(right) == test3, "Right list first value incorrect.");
  mu_assert(List_last(right) == test3, "Right list last value incorrect.");

  List_destroy(new_list);
  List_destroy(left);
  List_destroy(right);

  return NULL;
}

char *test_dump()
{
  int rc = List_dump(list, "testlist");
  mu_assert(rc == 0, "Failed to dump list.");

  return NULL;
}


char *test_insert_sorted()
{
  List_insert_sorted(list, word1, (List_compare)strcmp);
  mu_assert(List_first(list) == word1, "Wrong first value.");
  mu_assert(List_last(list) == word1, "Wrong first value.");

  List_insert_sorted(list, word2, (List_compare)strcmp);
  mu_assert(List_last(list) == word2, "Wrong second value.");

  List_insert_sorted(list, word3, (List_compare)strcmp);
  mu_assert(List_last(list) == word3, "Wrong third value.");

  List_insert_sorted(list, word4, (List_compare)strcmp);
  mu_assert(List_first(list) == word1, "Wrong last value.");
  mu_assert(List_count(list) == 4, "Wrong count on push.");
  
  char *val = List_pop(list);
  mu_assert(val == word3, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == word2, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == word1, "Wrong value on pop.");

  val = List_pop(list);
  mu_assert(val == word4, "Wrong value on pop.");
  mu_assert(List_count(list) == 0, "Wrong count after pop.");

  return NULL;
}


char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_create);
  mu_run_test(test_push_pop);
  mu_run_test(test_insert_sorted);
  mu_run_test(test_unshift);
  mu_run_test(test_dump);
  mu_run_test(test_split);
  mu_run_test(test_remove);
  mu_run_test(test_shift);
  mu_run_test(test_destroy);

  return NULL;
}

RUN_TESTS(all_tests);
