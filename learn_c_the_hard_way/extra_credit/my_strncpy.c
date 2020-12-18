// self-building strncpy()
#include <stddef.h>

char *my_strncpy(char *dest, const char *src, size_t len)
{
  // size_t is unsigned long int on 64bit OS.
  size_t i;

  for (i = 0; i < len && src[i]; i++) // if src[i] == '\0', loop ends.
  {
    dest[i] = src[i];
  }

  // fill the rest of destination with '\0'.
  for (; i < len; i++)
  {
    dest[i] = '\0';
  }

  return dest;
}
