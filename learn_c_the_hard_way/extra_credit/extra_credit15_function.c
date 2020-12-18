#include <stdio.h>

int ages[] = { 23, 43, 12, 89, 2 };
char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
int i;
int count;

void print_1(int ages[], char *names[], int count);
void print_2(int *cur_age, char **cur_name, int count);
void print_3(int *cur_age, char **cur_name, int count);
void print_4(int *cur_age, char **cur_name, int count);
void print_5(int *cur_age, char **cur_name, int count);

int main(int argc, char **argv)
{
  count = sizeof(ages) / sizeof(int);

  print_1(ages, names, count);

  int *cur_age = ages;
  char **cur_name = names;

  print_2(cur_age, cur_name, count);
  
  print_3(cur_age, cur_name, count);

  print_4(cur_age, cur_name, count);

  print_5(cur_age, cur_name, count);
  
  return 0;
}

/**************************************************************************************************************************/
void print_1(int ages[], char *names[], int count)
{
  for (i = 0; i < count; i++)
  {
    printf("%s is %d years old.\n", names[i], ages[i]);
  }
  printf("------\n");
}

void print_2(int *cur_age, char **cur_name, int count)
{
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s has %d years alive.\n",*(cur_name + i), *(cur_age + i));
  }
  printf("------\n");
}

void print_3(int *cur_age, char **cur_name, int count)
{
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s has %d years alive.\n", cur_name[i], cur_age[i]);
  }
  printf("------\n");
}

void print_4(int *cur_age, char **cur_name, int count)
{
  for (cur_name = &names[count - 1], cur_age = &ages[count - 1]; (cur_age - ages) >= 0; cur_name--, cur_age--)
  {
    printf("%s lived %d years so far.\n", *cur_name, *cur_age);
  }
  printf("------\n");
}

void print_5(int *cur_age, char **cur_name, int count)
{
  for (i = 0; i < count; i++)
  {
    printf("The address of cur_name[%d]..%p, The address of cur_age[%d]..%p\n", i, &cur_name[i], i, &cur_age[i]);
  }
  printf("------\n");
}
