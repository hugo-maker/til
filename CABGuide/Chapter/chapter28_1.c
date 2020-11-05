// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter28_1
// File chapter28_1.c

/* The program takes the book info program from chapter27 and writes the info to a file named bookinfo.txt. */

// First include the file with the structure definition
#include "chapter27_1.h"
#include <stdio.h>
#include <stdlib.h>
FILE * fptr;

int main(void)
{
  int ctr;
  struct bookInfo books[3]; // Array of three structure variables 

  // Get the information about each book from the user
  for (ctr = 0; ctr < 3; ctr++)
  {
    printf("What is the name of the book #%d?\n",(ctr + 1));
    fgets(books[ctr].title, sizeof(books[ctr].title), stdin);
    puts("Who is the author? ");
    fgets(books[ctr].author, sizeof(books[ctr].author), stdin);
    puts("How much did the book cost? ");
    scanf(" $%f",&books[ctr].price);
    puts("How many pages in the book? ");
    scanf(" %d",&books[ctr].pages);
    getchar(); // Clears last newline for next loop
  }

  // Rremember when typing your filename path to double up the backslashes or C will think you are putting in a conversion character
  fptr = fopen("/home/hibiki/CLang/bookInfo.txt","w");

  // Test to ensure that the file opened
  if (fptr == 0)
  {
    printf("Error--file could not be opened.\n");
    exit (1);
  }
  
  // Print a header line and then loop through and print the infomation to your file, but this time printout will be in your file and not on the screen.
  fprintf(fptr,"\n\nHere is the collection of books: \n");
  
  for (ctr = 0; ctr < 3; ctr++)
  {
    fprintf(fptr,"#%d: %s by %s",(ctr + 1), books[ctr].title, books[ctr].author);
    fprintf(fptr,"\nIt is %d pages and costs $%.2f",books[ctr].pages, books[ctr].price);
    fprintf(fptr,"\n\n");
  }

  fclose(fptr); // Always close your files
  return 0;
}
