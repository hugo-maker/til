// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter13_1
// File chapter13_1.c

// This program asks a number from 1 to 100 and tells then whether or not their choice is equally divisible by 2 through 9.

#include <stdio.h>

int main(void)
{
  // Define the integer to hold the user's guess and then get it from the user
  int numPick;
  printf("Pick an integer between 1 and 100 (The higher the better!)\n");
  scanf(" %d",&numPick);

  printf("%d %s divisible by 2.",numPick,(numPick % 2 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 3.",numPick,(numPick % 3 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 4.",numPick,(numPick % 4 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 5.",numPick,(numPick % 5 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 6.",numPick,(numPick % 6 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 7.",numPick,(numPick % 7 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 8.",numPick,(numPick % 8 == 0) ? ("is") : ("is not"));
  printf("\n%d %s divisible by 9.\n",numPick,(numPick % 9 == 0) ? ("is") : ("is not"));

  return 0;
}
