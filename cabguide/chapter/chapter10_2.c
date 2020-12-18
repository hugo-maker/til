// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter10_2
// File chapter10_2.c

// This program also increases a counter from 1 to 5, printing updates and then counts it back down to 1.
// However, it uses compound operators

#include <stdio.h>

int main(void)
{
  int ctr = 0;

  ctr += 1; // increases counter to 1
  printf("Counter is at %d.\n",ctr);
  ctr += 1; // increases counter to 2
  printf("Counter is at %d.\n",ctr);
  ctr += 1; // increases counter to 3
  printf("Counter is at %d.\n",ctr);
  ctr += 1; // increases counter to 4
  printf("Counter is at %d.\n",ctr);

  printf("Counter is at %d.\n",ctr += 1);

  ctr -= 1; // decreases counter to 4
  printf("Counter is at %d.\n",ctr);
  printf("Counter is at %d.\n",ctr -= 1);
  printf("Counter is at %d.\n",ctr -= 1);
  printf("Counter is at %d.\n",ctr -= 1);

  return 0;
}

