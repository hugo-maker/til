#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "dbg.h"

int print_a_message(const char *msg)
{
  printf("A STRING: %s\n", msg);

  return 0;
}

int uppercase(const char *msg)
{
  int i = 0;
  int len = 0;

  // BUG: \0 termination problems
  len = strlen(msg);
  for (i = 0; i <= len; i++)
  {
    printf("%c", toupper(msg[i]));
  }
  putchar('\n');

  return  0;
}

int lowercase(const char *msg)
{
  int i = 0;
  int len = 0;

  // BUG: \0 termination problems
  len = strlen(msg);
  for (i = 0; i <= len; i++)
  {
    printf("%c", tolower(msg[i]));
  }
  putchar('\n');

  return  0;
}

int fail_on_purpose(const char *msg)
{
  printf("A STRING: %s\n", msg);
  return 1;
}
