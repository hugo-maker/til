// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter22_1
// File chapter22_1.c

/* This program takes an ID number from the user and then checks the ID against a list of customers in the database.
 * If the customer exists, it uses that array element to check their current balance, and warns the user if the balance is more than 100. */

#include <stdio.h>

int main(void)
{
  int ctr; // Loop counter
  int idSearch; // Custmer to look for the key
  int found = 0; // Will be 1 (true) if customer is found

  // Defines the 10 elements in the two parallel arrays
  int custID[10] = {123, 456, 789, 135, 579, 246, 680, 111, 222, 333};
  float custBal[10] = {123, 45.60, 78.90, 135, 5.79, 246, 680, 1.11, 22.20, 0.33};

  // Interact with the user looking for a balance.
  printf("\n\n*** Customer Balance Lookup ***\n");
  printf("What customer number do you need to check? ");
  scanf(" %d",&idSearch);

  // Search to see that the customer ID exists in the array
  for (ctr = 0; ctr < 10; ctr++)
  {
    if (idSearch == custID[ctr])
    {
      found = 1;
      break;
    }
  }

  if (found)
  {
    if (custBal[ctr] > 100.00)
    {
      printf("\n** That customer's balance is $%.2f.\n",custBal[ctr]);
      printf(" No additional credit.\n");
    }
    else
    {
      printf("\n** The customer's credit is good!\n");
    }
  }
  else
  {
    printf("** You must have typed an incorrect customer ID.");
    printf("\n ID %3d was not found in list.\n",idSearch);
  }

  return 0;
}
