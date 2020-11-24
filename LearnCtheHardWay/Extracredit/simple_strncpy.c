// Very simple but safer function using original strncpy
#include <string.h>

void simple_strncpy(char *dest, char *src, int len)
{
  strncpy(dest, src, len);
  dest[len] = '\0';
}
