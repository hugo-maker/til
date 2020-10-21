#include <stdio.h>

int main(void)
{
  char firstname[256];
  char lastname[256];
  char fullname[512];

  printf("Your firstname? :");
  scanf("%s", firstname);
  printf("Your lastname? :");
  scanf("%s", lastname);

  sprintf(fullname, "%s%s\n", firstname, lastname);
  printf("Your name is %s", fullname);
  return 0;
}
