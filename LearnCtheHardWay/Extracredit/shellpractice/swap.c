#include <stdio.h>

int main()
{
  int fd1 = 1;
  int fd2 = 2;

  printf("fd1 = %d, fd2 = %d\n", fd1, fd2);

  int fd3 = fd1;
  fd1 = fd2;
  fd2 = fd3;

  printf("fd1 = %d, fd2 = %d\n", fd1, fd2);

  return 0;
}
