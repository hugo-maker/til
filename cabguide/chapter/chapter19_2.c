// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter19_2
// File chapter19_2.c

/* This program asks a user for their hometown and the two-letter abbreviation of their home state.
 * It then uses string concatenation to build a new string with both town and state and prints it using puts. */

// stdio.h is needed for puts() and gets()
// string.h is needed for strcat()

#include <stdio.h>
#include <string.h>

int main(void)
{
  char city[15];
  // 2 chars for the state abbrev. and one for the null zero
  char st[3];
  char fullLocation[18] = "";

  puts("What town do you live in? ");
  fgets(city,15,stdin);

  puts("What state do you live in? (2-letter abbreviation)");
  fgets(st,3,stdin);

  // Concatnates the strings
  strcat(fullLocation,city);
  strcat(fullLocation,", "); // Adds a comma and space between the city and the state abbreviation
  strcat(fullLocation,st);

  puts("\nYou live in ");
  puts(fullLocation);

  return 0;
}
