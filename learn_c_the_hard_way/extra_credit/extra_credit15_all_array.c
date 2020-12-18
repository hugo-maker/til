#include <stdio.h>

int main(int argc, char *argv[])
{
  // create two arrays we care about
  int ages[] = { 23, 43, 12, 89, 2 };
  // names is array of pointer to char
  char names[][6] = {"Alan", "Frank", "Mary", "John", "Lisa"};

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for (i = count - 1; i >= 0; i--)
  {
    printf("%s is %d years old.\n", names[i], ages[i]);
  }

  return 0;
}
