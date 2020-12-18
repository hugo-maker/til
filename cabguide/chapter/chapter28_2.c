// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter28_2
// File chapter28_2.c

/* The program takes the book info file from the first example of chapter 28; also each line from the file and outputs it to the screen. */

#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

int main(void)
{
  char fileLine[100]; // Will hold each line of input
  fptr = fopen("/home/hibiki/CLang/bookInfo.txt","r");

  if (fptr != 0)
  {
    while (!feof(fptr))
    {
      fgets(fileLine, 100, fptr);
      if (!feof(fptr))
      {
        puts(fileLine);
      }
    }
  }
  else
  {
    printf("\nError opening file.\n");
  }
  fclose(fptr);
  return 0;
}
