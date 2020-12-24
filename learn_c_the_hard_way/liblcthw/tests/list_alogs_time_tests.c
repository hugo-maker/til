#include "minunit.h"
#include <lcthw/list_alogs.h>
#include "lcthw/get_random_chars_array.h"
#include <assert.h>

List *create_words()
{
  int i = 0;
  List *words = List_create();
  check_mem(words);

  fill_values(values);

  for (i = 0; i < NUM_VALUES; i++)
  {
    List_push(words, values[i]);
  }

  return words;

error:
  return NULL;
}


int is_sorted(List *words)
{
  LIST_FOREACH(words, first, next, cur)
  {
    if (cur->next && strcmp(cur->value, cur->next->value) > 0)
    {
      debug("%s %s", (char *)cur->value, (char *)cur->next->value);
      return 0;
    }
  }

  return 1;
}

char *test_bubble_sort_time()
{
  List *words = create_words();

  // bubble sort on a list that needs sorting
  clock_t begin = clock();
  int rc = List_bubble_sort(words, (List_compare)strcmp);
  mu_assert(rc == 0, "Bubble sort failed.");
  mu_assert(is_sorted(words),
      "Words are not sorted after bubble sort.");
  clock_t end = clock();
  printf("bubble sort on list that needs sorting.: %f seconds\n",
      (double)(end - begin) / CLOCKS_PER_SEC);

  // bubble sort on an already sorted list
  begin = clock();
  rc = List_bubble_sort(words, (List_compare)strcmp);
  mu_assert(rc == 0, "Bubble sort of already sorted failed.");
  mu_assert(is_sorted(words),
      "Words should be sort if already bubble sorted.");
  end = clock();
  printf("bubble sort on already sorted list.: %f seconds\n",
      (double)(end - begin) / CLOCKS_PER_SEC);

  List_destroy(words);

  return NULL;
}

char *test_merge_sort_time()
{
  List *words = create_words();

  // merge sort on a list that needs sorting
  clock_t begin = clock();
  List *res = List_merge_sort(words, (List_compare)strcmp);
  mu_assert(is_sorted(res), "Words are not sorted after merge sort.");
  clock_t end = clock();
  printf("merge sort on list that needs sorting.: %f seconds\n",
      (double)(end - begin) / CLOCKS_PER_SEC);

  // merge sort on an already sorted list
  begin = clock();
  List *res2 = List_merge_sort(res, (List_compare)strcmp);
  mu_assert(is_sorted(res), "Should still be sorted after merge sort.");
  end = clock();
  printf("merge sort on already sorted list.: %f seconds\n",
      (double)(end - begin) / CLOCKS_PER_SEC);
  List_destroy(res2);
  List_destroy(res);

  List_destroy(words);
  return NULL;
}


char *all_tests()
{
  mu_suite_start();

  mu_run_test(test_bubble_sort_time);
  mu_run_test(test_merge_sort_time);

  return NULL;
}

RUN_TESTS(all_tests);
