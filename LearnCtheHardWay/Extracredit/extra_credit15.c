#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int i = 0;

  // go through each string in argv
  // Skipping argv[0] because argv[0] is the ./ex13 itself
  for (i = 1; i < argc; i++)
  {
    printf("arg %d: %s\n", i, argv[i]);
  }

  char **states = malloc(4 * sizeof(char *));
  *states = "California";
  *(states + 1) = "Oregon";
  *(states + 2) = "Washington";
  *(states + 3) = "Texas";
  

  int num_states = 4;

  for (i = 0; i < num_states; i++)
  {
    printf("state %d: %s\n", i, states[i]);
  }

  return 0;
}
