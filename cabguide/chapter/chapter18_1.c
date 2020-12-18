// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter18_1
// File chapter18_1.c

// This program is nothing more than a simple demonstration of the putchar() function. 

// putchar() is defined in stdio.h, but string.h is needed for the strlen() function

#include <stdio.h>
#include <string.h>

int main(void)
{
  int i;
  char msg[] = "C is fun";

  for (i = 0;i < strlen(msg);i++)
  {
    putchar(msg[i]); // Output a single character
  }
  putchar('\n'); // One line break after the loop is done.

  return (0);
}
