#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  //int ages[] = {23, 43, 12, 89, 2};
  int *ages = malloc(5 * sizeof(int)); // allocate memory for 5 integers
  *ages = 23;
  *(ages + 1) = 43;
  *(ages + 2) = 12;
  *(ages + 3) = 89;
  *(ages + 4) = 2;

  //char *names[] = {"Alan", "Frank", "Mary", "John", "Lisa"};
  char **names = malloc(5 * sizeof(char *));
  *names = "Alan";
  *(names + 1) = "Frank";
  *(names + 2) = "Mary";
  *(names + 3) = "John";
  *(names + 4) = "Lisa";

  int i;
  // first way using indexing
  for (i = 0; i < 5; i++)
  {
    printf("%s is %d years old.\n", names[i], ages[i]);
  }

  printf("------\n");
  
  // second ways using pointers
  for (i = 4; i >= 0; i--)
  {
    printf("%s has %d years alive.\n", *(names + i), *(ages + i));
  }

  printf("------\n");

  // fourth way with pointers in a stupid complex way
  for (i = 0; i < 5; names++, ages++, i++)
  {
    printf("%s lived %d years so far.\n", *names, *ages);
  }

  return 0;
}
