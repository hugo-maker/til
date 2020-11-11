#include <stdio.h>
#include <ctype.h>
#include <string.h>

// forward declarations
int can_print_it(char ch);
void print_letters(int length, char arg[]);

void print_arguments(int argc, char *argv[])
{
  int i = 0;
  int length;

  for (i = 1; i < argc; i++)
  {
    length = strlen(argv[i]);
    print_letters(length, argv[i]);
  }
}

void print_letters(int length, char arg[])
{
  int i = 0;

  for (i = 0; i < length; i++)
  {
    char ch = arg[i];
    printf("'%c' == %d ", ch, ch);
  }

  printf("\n");
}

int main(int argc, char *argv[])
{
  print_arguments(argc, argv);

  return 0;
}
