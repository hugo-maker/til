// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter29_2
// File chapter29_2.c

/* The program opens the file created in the first program of the chapter and changes one of the letters to an *.
 * It then prints the new list with the altered list of letters. */

#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

int main(void)
{
  char letter;
  int i;

  fptr = fopen("/home/hibiki/CLang/letters.txt", "r+");

  if (fptr == 0)
  {
    printf("There was an error while opening the file.\n");
    exit(1);
  }

  printf("Which # letter would you want to change (1-26)? ");
  scanf(" %d", &i);

  // Seeks that position from the beginning of the file 
  fseek(fptr, (i - 1), SEEK_SET); // Subtract 1 from the position because array starts at 0

  // Write an * over letter in that position
  fputc('*', fptr);

  // Now jump back to the beginning of the array and print it out
  fseek(fptr, 0, SEEK_SET);
  printf("Here is the file now:\n");
  for (i = 0; i < 26; i++)
  {
    letter = fgetc(fptr);
    printf("The next letter is %c.\n", letter);
  }

  fclose(fptr);

  return 0;
}
