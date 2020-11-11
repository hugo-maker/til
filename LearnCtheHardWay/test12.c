#include <stdio.h>

int main(int argc, char *argv[])
{
  int areas[] = { 10, 12, 13, 14, 20 };
  char name[] = "Zed";
  char full_name[] = { 'Z', 'e', 'd', ' ', 'A', '.', ' ', 'S', 'h', 'a', 'w', '\0'};

  areas[0] = 100;
  printf("The size of an int: %ld\n", sizeof(int));
  printf("The size of areas (int[]): %ld\n", sizeof(areas));
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);

  name[2] = 'n';
  printf("The size of a char: %ld\n", sizeof(char));
  printf("The size of a name: %ld\n", sizeof(name));
  printf("The number of a chars: %ld\n", sizeof(name) / sizeof(char));

  full_name[12] = 'H';
  printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
  printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));

  //full_name[12] = 'X';

  printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

  return 0;
}
