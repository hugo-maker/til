// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter8_1
// File chapter8_1.c

// This is a sample program that asks users for some basic data and pronts it on screen to show what was entered

#include <stdio.h>

int main(void)
{
  // Set up the variables that scanf() will fill
  char firstInitial;
  char lastInitial;
  int age;
  int favorite_number;
  
  printf("What letter does your first name begin with?\n");
  scanf(" %c",&firstInitial);

  printf("What letter does your last name begin with?\n");
  scanf(" %c",&lastInitial);

  printf("How old are you?\n");
  scanf(" %d",&age);

  printf("What is your favorite number (integer only)?\n");
  scanf(" %d",&favorite_number);

  printf("\nYour initials are %c.%c. and you are %d years old",firstInitial,lastInitial,age);
  printf("\nYour favorite number is %d.\n\n",favorite_number);

  return 0;
}
