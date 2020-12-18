// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter31_1
// File chapter31_1.c

/* The program demonstrate passing a variable to a function by value. */

#include <stdio.h>

void half(int i);
int main(void)
{
  int i;

  printf("Please enter an integer... ");
  scanf(" %d", &i);

  // Now call the half function, passing the value of i
  half(i);
  // Show that the function did not alter i's value
  printf("In main(), i is still %d.\n", i);

  return 0;
}

/*****************************************************************************************************/

/* Sometimes putting dividers like the one above is a nice break between your different functions. */

void half(int i) // Recieves the value of i
{
  i = i / 2;
  printf("Your value halved is %d.\n", i);
  return; // Return to main
}
