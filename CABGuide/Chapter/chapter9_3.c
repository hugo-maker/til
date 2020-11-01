// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter9_3
// File chapter9_3.c

// This program calculates the average of four grades and also does some other basic math.

#include <stdio.h>

int main(void)
{
  int grade1,grade2,grade3,grade4;
  float averageGrade,gradeDelta,percentDiff;

  // The student got 88s on the first and third test, so a multiple assignment statement works.
  grade1 = grade3 = 88;
  grade2 = 79;

  // The user needs to enter the fourth grade
  printf("What did you get on the fourth test");
  printf(" (An integer between 0 and 100)?");
  scanf(" %d",&grade4);

  averageGrade = (grade1 + grade2 + grade3 + grade4) / 4;
  printf("Your average is %.1f.\n",averageGrade);

  gradeDelta = 95 - averageGrade;
  percentDiff = 100 * ((95 - averageGrade) / 95);
  printf("Your grade is %.1f points lower than the top grade in the Class (95)\n",gradeDelta);
  printf("You are %.1f percent behind that grade!\n\n\n",percentDiff);

  return 0;
}
