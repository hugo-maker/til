// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter13_2
// File chapter13_2.c

/* This program increases a counter from 1 to 5, printing updates and then counts it back down to 1.
 * However, it uses the increment and decrement operators */

#include <stdio.h>

int main(void)
{
  int ctr = 0;

  printf("Counter is at %d.\n",++ctr);
  printf("Counter is at %d.\n",++ctr);
  printf("Counter is at %d.\n",++ctr);
  printf("Counter is at %d.\n",++ctr);
  printf("Counter is at %d.\n",++ctr);

  printf("Counter is at %d.\n",--ctr);
  printf("Counter is at %d.\n",--ctr);
  printf("Counter is at %d.\n",--ctr);
  printf("Counter is at %d.\n",--ctr);

  return 0;
}
