// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter27_1
// File chapter27_1.c

/* This program gets the bookInfo suructure by including bookInfo.h and asks the user to fill in three structures and then print them. */

// First include the file with the structure definition
#include "chapter27_1.h"
#include <stdio.h>

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
  
  // Print a header line and then loop through and print the infomation
  printf("\n\nHere is the collection of books: \n");
  
  for (ctr = 0; ctr < 3; ctr++)
  {
    printf("#%d: %s by %s",(ctr + 1), books[ctr].title, books[ctr].author);
    printf("\nIt is %d pages and costs $%.2f",books[ctr].pages, books[ctr].price);
    printf("\n\n");
  }

  return 0;
}
