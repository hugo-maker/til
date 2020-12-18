// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter11_1
// File chapter11_1.c

/* This program asks the user for their birth year and calculates how old they will be in the current year. 
(it also checks to make sure a future year has not been entered.) It then tells the user if they were born in a leap year. */

#include <stdio.h>
#define CURRENTYEAR 2020

int main(void)
{
  int yearBorn, age;
  printf("What year were you born?\n");
  scanf(" %d",&yearBorn);

  /* This if statement can do some data validation, making sure the year makes sense. 
   * The statements will only execute if the year is after the current year. */

  if (yearBorn > CURRENTYEAR)
  {
    printf("Are you sure? You haven't been born yet?\n");
    printf("Want to try again with a different year?\n");
    printf("What year were you born?\n");
    scanf(" %d",&yearBorn);
  }

  age = CURRENTYEAR - yearBorn;

  printf("\nSo this year you will turn %d on your birthday!\n",age);

  /* The second if statement uses the modulus operator to test if the year of birth was a Leap year. 
   * Again, only if it is will teh code execute */

  if ((yearBorn % 4) == 0)
  {
    printf("\nYou were born in a Leap Year--cool!\n");
  }

  return 0;
}
