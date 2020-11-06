// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter31_2
// File chapter31_2.c

/* The program demonstrates passing an array to a function. */

#include <stdio.h>
#include <string.h>

void change();

int main(void)
{
  char name[15] = "William Livius";
  change(name);
  printf("Back in main(), the name is now %s.\n", name);

  return 0;
}

/*****************************************************************************/

void change(char name[15])
{
  // Change the string stored at the address pointed to by name
  strcpy(name, "Someoneelse");
  return;
}
