// Absolude Beginner's Guide to C, 3rd Edition Kindle
// sample code of Chapter5 
// File chapter5_1.c

// This is a sample program that lists three kids and their school supply needs, as well as cost to buy the supplies
#include <stdio.h>

int main(void)
{
  // Set up the variables, as well as define a few
  char firstInitail,middleInitial;
  int number_of_pencils;
  int number_of_notebooks;
  float pencils = 0.25;
  float notebooks = 3.34;
  float lunchbox = 5.48;

  // The information for the first child
  firstInitail = 'J';
  middleInitial = 'R';

  number_of_pencils = 5;
  number_of_notebooks = 4;

  printf("%c%c needs %d pencils, %d notebooks, and 1 lunchbox\n",firstInitail,middleInitial,number_of_pencils,number_of_notebooks);
  printf("The total cost is $%.2f\n\n",number_of_pencils * pencils + number_of_notebooks * notebooks + lunchbox);

  // The information for the second child
  firstInitail = 'H';
  middleInitial = 'U';

  number_of_pencils = 7;
  number_of_notebooks = 2;

  printf("%c%c needs %d pencils, %d notebooks, and 1 lunchbox\n",firstInitail,middleInitial,number_of_pencils,number_of_notebooks);
  printf("The total cost is $%.2f\n\n",number_of_pencils * pencils + number_of_notebooks * notebooks + lunchbox);

  // The information for the third child
  firstInitail = 'S';
  middleInitial = 'A';

  number_of_pencils = 2;
  number_of_notebooks = 9;

  printf("%c%c needs %d pencils, %d notebooks, and 1 lunchbox\n",firstInitail,middleInitial,number_of_pencils,number_of_notebooks);
  printf("The total cost is $%.2f\n\n",number_of_pencils * pencils + number_of_notebooks * notebooks + lunchbox);

  return 0;
}
