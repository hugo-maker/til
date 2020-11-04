// Absolute Beginner's Guide to C, 3rd Edition Kindle
// sample program from Chapter23_2
// File chapter23_2.c

/* This program searches a sorted list of customer IDs to get credit totals */

#include <stdio.h>

int main(void)
{
  int ctr; // Loop counter
  int idSearch; // Customer to look for the key
  int found = 0; // 1 (true) if customer is found

  /* Defines the 10 elements in each of the parallel arrays */
  int custID[10] = {234, 183, 994, 489, 543, 849, 643, 777, 110, 300};
  float custBal[10] = {0.00, 33.22, 289.00, 3.14, 123.19, 12.00, 98.03, 99.05, 222.22, 85.15};
  int tempID, inner, outer, didSwap, i; // For sorting
  float tempBal; //temp stands for temporary

  // First, sort the arrays by customer ID
  for (outer = 0; outer < 9; outer++)
  {
    didSwap = 0; // Become 1 (true) if list is not yet ordered
    for (inner = outer; inner < 10; inner++)
    {
      if (custID[inner] < custID[outer])
      {
        tempID = custID[inner];
        tempBal = custBal[inner];
        custID[inner] = custID[outer];
        custBal[inner] = custBal[outer];
        custID[outer] = tempID;
        custBal[outer] = tempBal;
        didSwap = 1;
      }
    }
    if (didSwap == 0)
    {
      break;
    }
  }

  /* Interact with the user looking to find a balance */
  printf("\n\n*** Customer Balance Lookup ***\n");
  printf("What is the customer number? ");
  scanf(" %d",&idSearch);

  // Now, look for the ID in the array
  for (ctr = 0; ctr < 10; ctr++)
  {
    if (idSearch == custID[ctr]) // Do they match?
    {
      found = 1; // Yes, match flag is set to true
      break; // No need to keep looking
    }
    if (custID[ctr] > idSearch) // No need to keep searching
    {
      break;
    }
  }

  // Once the loop has completed, the ID was either found (found = 1) or not
  
  if (found)
  {
    if (custBal[ctr] > 100)
    {
      printf("\n** That customer's balance is $%.2f.\n",custBal[ctr]);
      printf("No addtional credit.\n");
    }
    else
    {
      printf("\n**The customer's credit is good!\n");
    }
  }
  else
  {
    printf("** You have entered an incorrect customer ID.");
    printf("\n ID %3d was not found in the list.\n",idSearch);
  }

  return 0;
}
