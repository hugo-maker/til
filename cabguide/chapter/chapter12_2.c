// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter12_2
// File chapter12_2.c

/* This program asks for a last name, and if the user has a last name that starts with a letter between P and Q,
 * they will be sent to a special room for their tickets. */

#include <stdio.h>

int main(void)
{
  // set up an array for the last name and then get it from the user
  char name[25];
  printf("What is your last name? (Please capitalize the first letter!)\n ");
  scanf(" %s",name);

  if ((name[0] >= 'P') && (name[0] <= 'S'))
  {
    printf("You must go to room 2432 for your tickets.\n");
  }
  else
  {
    printf("You can get your tickets here.\n");
  }

  return 0;
}
