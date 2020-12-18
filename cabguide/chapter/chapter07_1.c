// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter7_1
// File chapter7_1.c

// This is a sample program that lists three kids and their school supply needs, as well as cost to buy the supplies

#include <stdio.h>
#include <string.h>
#include "chapter7_1.h"

int main(void)
{
  int age;
  char childname[14] = "Thomas";

  printf("\n%s have %d kids.\n",FAMILY,KIDS);

  age = 11;
  printf("The oldest, %s, is %d.\n",childname,age);

  strcpy(childname,"Christopher");
  age = 6;
  printf("The middle boy, %s, is %d.\n",childname,age);

  age = 3;
  strcpy(childname,"Benjamin");
  printf("The youngest, %s, is %d.\n",childname,age);

  return 0;

}
