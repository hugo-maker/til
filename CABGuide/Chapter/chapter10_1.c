// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter10_1
// File chapter10_1.c

// This program increases a counter from 1 to 5, printing updates and then counts it back down to 1.

#include <stdio.h>

int main(void)
{
  int ctr = 0;

  ctr = ctr + 1; // increases counter to 1
  printf("Counter is at %d.\n",ctr);
  ctr = ctr + 1; // increases counter to 2
  printf("Counter is at %d.\n",ctr);
  ctr = ctr + 1; // increases counter to 3
  printf("Counter is at %d.\n",ctr);
  ctr = ctr + 1; // increases counter to 4
  printf("Counter is at %d.\n",ctr);
  ctr = ctr + 1; // increases counter to 5
  printf("Counter is at %d.\n",ctr);
  ctr = ctr - 1; // decreases counter to 4
  printf("Counter is at %d.\n",ctr);
  ctr = ctr - 1; // decreases counter to 3
  printf("Counter is at %d.\n",ctr);
  ctr = ctr - 1; // decreases counter to 2
  printf("Counter is at %d.\n",ctr);
  ctr = ctr - 1; // decreases counter to 1
  printf("Counter is at %d.\n",ctr);

  return 0;
  
}
