#include <lcthw/list_alogs.h>
#include "lcthw/vl_get_random_chars_array.h"
#include "lcthw/dbg.h"
#include <math.h>
#include <stdio.h>

char **values;

List *create_words_vl(int num_values)
{
  int i = 0;
  List *words = List_create();
  check_mem(words);

  fill_values(values, num_values);

  for (i = 0; i < num_values; i++)
  {
    List_push(words, values[i]);
  }

  return words;

error:
  return NULL;
}

int main(void)
{
  values = (char **)malloc(sizeof(char *) * MAX_NUM);
  check_mem(values);
  FILE *gp;
  int num_values = 1000;
  int i = 0;
  const int count =  MAX_NUM / num_values;
  clock_t begin, end;
  double bubble_time[10], merge_time[10];
  int x[10];

  for (i = 0; i <  count; i++, num_values += 1000)
  {
    x[i] = num_values;

    // bubble sort
    List *words = create_words_vl(num_values);
    begin = clock();
    List_bubble_sort(words, (List_compare)strcmp);
    end = clock();
    bubble_time[i] = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("bubble sort on list which has %d elements.: %f seconds\n", 
        num_values, bubble_time[i]);
        

    List_destroy(words);

    // merge sort
    words = create_words_vl(num_values);
    begin = clock();
    List *res = List_merge_sort(words, (List_compare)strcmp);
    end = clock();
    merge_time[i] = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("merge sort on list which has %d elements.: %f seconds\n", 
        num_values, merge_time[i]);

    List_destroy(res);
    List_destroy(words);
  }

  gp = popen("gnuplot -persist", "w");
  fprintf(gp, "set xrange [1000:10000]\n");
  fprintf(gp, "set yrange [0.0000000:5.0000000]\n");
  fprintf(gp, "plot '-' with lines linetype 1 title \"Bubble Sort\",\
                    '-' with lines linetype 2 title \"Merge Sort\"\n");

  for (i = 0; i <  count; i++)
  {
    fprintf(gp, "%d\t%f\n", x[i], bubble_time[i]);
  }
  fprintf(gp, "e\n");

  for (int i = 0; i <  count; i++)
  {
    fprintf(gp, "%d\t%f\n", x[i], merge_time[i]);
  }
  fprintf(gp, "e\n");

  pclose(gp);

  free(values);
  return 0;

error:
  free(values);
  return 1;
}
