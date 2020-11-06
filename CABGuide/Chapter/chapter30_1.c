// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter30_1
// File chapter30_1.c

/* The program is a simple demonstration of the difference between global variables and local variables. */

#include <stdio.h>
int global1 = 10;

void prAgain();

int main(void)
{
  float local1;
  local1 = 9.0;

  printf("%d %.2f\n", global1, local1); // prints the 1st global and 1st local variable
  prAgain(); // calls our first function
  return 0;
}

float global2 = 19.0;

void prAgain()
{
  int local2 = 5;

  // Cannot print local1--it is local to main
  printf("%d %.2f %d\n", local2, global2, global1);
  return;
}
