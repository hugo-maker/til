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

int my_scanf(char *buffer, size_t *len)
{
  int in = scanf("%31[^\n]%zn%*[^\n]", buffer, len);
  check(in == 1, "Failed to read");
  scanf("%*c");

  return 0;
error:
  return 1;
}

int main(int argc, char *argv[])
{
  Person you = {.age = 0};
  int i = 0;
  size_t first_len = 0;
  size_t last_len = 0;
  size_t *pfirst_len = &first_len;
  size_t *plast_len = &last_len;
  char buffer[32];
  char *endptr;

  printf("What is your First Name? ");
  my_scanf(you.first_name, pfirst_len);

  printf("What is your Last Name? ");
  my_scanf(you.last_name, plast_len);

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

  printf("First Name: %s Length: %zu\n", you.first_name, *pfirst_len);
  printf("Last Name: %s Length: %zu\n", you.last_name, *plast_len);
  printf("Age: %ld\n", you.age);
  printf("Eyes: %s\n", EYE_COLOR_NAME[you.eyes]);
  printf("Income: %lf\n", you.income);

  return 0;
error:
  return -1;
}
