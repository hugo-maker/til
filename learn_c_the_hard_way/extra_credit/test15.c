#include <stdio.h>

int main(int argc, char **argv)
{
  // create two arrays we care about
  int ages[] = { 23, 43, 12, 89, 2 };
  // names is array of pointer to char
  char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s is %d years old.\n", names[i], ages[i]);
  }

  printf("------\n");

  /* set up the pointers to the start of the arrays */

  // cur_age is pointer to int pointed at /array named ages.
  // -> cur_age is pointer to int pointed at /the pointer to the first element of array named ages.
  // ->(more simply) cur_age is pointer to int. And set up the pointer to the start of the array named ages.
  int *cur_age = ages;
  // cur_name is pointer to pointer (which points to char). And set up the pointer(=cur_name) to the start of the array named names.
  char **cur_name = names;

  // second ways using pointers
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s has %d years alive.\n",*(cur_name + i), *(cur_age + i));
  }

  printf("------\n");

  // third way, pointers are just arrays
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s has %d years alive.\n", cur_name[i], cur_age[i]);
  }

  printf("------\n");

  // fourth way with pointers in a stupid complex way
  for (cur_name = &names[4], cur_age = &ages[4]; (cur_age - ages) >= 0; cur_name--, cur_age--)
  {
    printf("%s lived %d years so far.\n", *cur_name, *cur_age);
  }

  printf("------\n");

  for (i = 0; i < count; i++)
  {
    printf("The address of cur_name[%d]..%p, The address of cur_age[%d]..%p\n", i, &cur_name[i], i, &cur_age[i]);
  }

  return 0;
}
