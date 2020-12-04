#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>
#include "dbg.h"

#define MAX_DATA 100

typedef enum EyeColor
{
  BLUE_EYES,
  GREEN_EYES,
  BROWN_EYES,
  BLACK_EYES,
  OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAME[] = { "Blue", "Green", "Brown", "Black", "Other"};

typedef struct Person
{
  long age;
  char first_name[MAX_DATA];
  char last_name[MAX_DATA];
  EyeColor eyes;
  double income;
} Person;

void my_scanf(char *dest, size_t len)
{
  size_t i;

  for (i = 0; i < len; i++)
  {
    scanf(" %c", &dest[i]);
  }

  dest[len] = '\0';
}

int main(int argc, char *argv[])
{
  Person you = {.age = 0};
  int i = 0;
  char *in = NULL;
  char buffer[32];
  char *endptr;

  /*printf("What is your First Name? ");
  in = fgets(you.first_name, MAX_DATA - 1, stdin);
  check(in != NULL, "Failed to read first name.");
  */

  printf("What is your First Name? ");
  my_scanf(you.first_name, MAX_DATA);

  printf("What is your Last Name? ");
  in = fgets(you.last_name, MAX_DATA - 1, stdin);
  check(in != NULL, "Failed to read last name.");

  // new version of get age
  //  '*' assignment-suppression character:
  // scanf() reads input as directed by the conversion specification, but discards the input.
  // [^\n] means "except for '\n'"
  printf("How old are you? ");
  // scanf("%*[^\n]"); discard to the last '\n'
  // scanf("%*c"); discard the last '\n'
  // Thus, with these two lines, clear the data of input stream
  // You can also use clear the data of input stream with
  // while(getchar() != '\n'){}
  int rc = scanf("%31[^\n]", buffer);
  check(rc = 1, "You have to enter only one number.");
  scanf("%*[^\n]");
  scanf("%*c");

  you.age = strtol(buffer, &endptr, 10);
  check(*endptr == '\0', "Invalid charcter found:%c:", *endptr);
  check(errno != ERANGE, "Out of range (%s)", you.age == LONG_MAX ? "Overflow" : "Underflow");
  // new version of get age END

  // new version of get eyes color
  printf("What color are your eyes:\n");
  for (i = 0; i <= OTHER_EYES; i++)
  {
    printf("%d) %s\n", i + 1, EYE_COLOR_NAME[i]);
  }
  printf("> ");

  rc = scanf("%31[^\n]", buffer);
  check(rc = 1, "You have to enter only one number.");
  while(getchar() != '\n') {}

  long eyes = -1;
  eyes = strtol(buffer, &endptr, 10);
  check(*endptr == '\0', "Invalid character found:%c:", *endptr);
  check(errno != ERANGE, "Out of range (%s)", you.age == LONG_MAX ? "Overflow" : "Underflow");

  you.eyes = eyes - 1;
  check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that is not an option.");
  // new version of get eyes color END

  // new version of get income
  printf("How much do you make an hour? ");
  rc = scanf("%31[^\n]", buffer);
  check(rc = 1, "You have to enter only one number.");
  scanf("%*[^\n]");
  scanf("%*c");

  you.income = strtod(buffer, &endptr);
  check(*endptr == '\0', "Invalid charcter found:%c:", *endptr);
  check(errno != ERANGE, "Out of range (%s)", you.income == LONG_MAX ? "Overflow" : "Underflow");

  printf("----- RESULTS -----\n");

  printf("First Name: %s", you.first_name);
  printf("Last Name: %s", you.last_name);
  printf("Age: %ld\n", you.age);
  printf("Eyes: %s\n", EYE_COLOR_NAME[you.eyes]);
  printf("Income: %lf\n", you.income);

  return 0;
error:
  return -1;
}
