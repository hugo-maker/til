// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter28_3
// File chapter28_3.c

/* The program opens the existing book info file from the first example of chapter 28, and a line to the end. */

#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

int main(void)
{
  fptr = fopen("/home/hibiki/CLang/bookInfo.txt","a");

  if (fptr == 0)
  {
    printf("Error opening the file! Sorry!\n");
    exit (1);
  }

  // Adds the line at the end
  fprintf(fptr,"\nMore books to come!\n");

  fclose(fptr);

  return 0;
}
