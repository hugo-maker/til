// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter19_1
// File chapter19_1.c

/* This program asks a user for a usename and a password. IT tests whether their password has an uppercase letter, lowercase letter, nad a digit.
 * If it does, the program congratulates their selection. 
 * If not, it suggests they might want to consider a password with more variety for the sake of security. */

// stdio.h is needed for printf() and scanf()
// string.h is needed for strlen()
// ctype.h is needed for isdigit, isupper, and islower
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  int i;
  int hasUpper, hasLower, hasDigit, hasSymbol;
  char user[25], password[25];

  // Initialize all three test variables to 0 i.e. false
  hasUpper = hasLower = hasDigit = hasSymbol =  0;

  printf("What is your usename? ");
  scanf(" %s",user);

  printf("Please create a password: ");
  scanf(" %s",password);

  // This loop goes through each character of the password and tests whether it is a digit, uppercase, then lowercase letter.
  for (i = 0; i < strlen(password); i++)
  {
    if (isdigit(password[i]))
    {
      hasDigit = 1;
      continue;
    }
    if (isupper(password[i]))
    {
      hasUpper = 1;
      continue;
    }
    if (islower(password[i]))
    {
      hasLower = 1;
    }
    else
    {
      hasSymbol = 1;
    }
  }

  // The if portion will only execute if all three variables below are 1, and the variables will only equal 1 if the appropriate characters were each found.
  if ((hasDigit) && (hasUpper) && (hasLower) && (hasSymbol))
  {
    printf("\n\nExcellent work, %s,\nYour password has upper and lowercase letters and a number and a symbol.\n",user);
  }
  else
  {
    printf("\n\nYou should consider a new password, %s,\nOne that uses upper and lowercase letters and a number and a symbol.\n",user);
  }

  return 0;
}
