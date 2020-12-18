#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "my_strncpy.h"

void test00(char *dest, size_t dest_len, const char *src, size_t len, const char *function_name, char *func(char *, const char *, size_t))
{
  /*
   * #include <string.h>
   * void *memset(void *s, int c, size_t n); ※ c accepts char too
   * initialize dest by filling the dest with '*' as long as dest_len
   */
  memset(dest, '*', dest_len);

  /* execute the function passed by as an argument */ 
  char *p = func(dest, src, len);

  printf("%s(%p, \")", function_name, (void *)dest);

  /*
   * isprint(): checks for any printable character including space.
   * check if each character is printable or not.
   * then show the result
   */
  for (size_t i = 0; i < strlen(src); i++)
  {
    if (isprint(src[i]))
    {
      printf("%c", src[i]);
    }
    else if (src[i] == '\n')
    {
      printf("\\n");
    }
  }

  printf("\", %zu) = %p\n", len, p); // zu is format specifier for size_t

  for (size_t i = 0; i < dest_len; i++)
  {
    printf("%02x ", (unsigned char)dest[i]); // if you want to print the result in decimal, use %03u
  }

  for (size_t i = 0; i < dest_len; i++)
  {
    printf("%c", isprint(dest[i]) ? dest[i] : '.');
  }

  putchar('\n');
}

void test0(const char *str, size_t src_len)
{
  char dest[20];

  /* compare original strncpy() with my_strncpy() */
  test00(dest, sizeof(dest), str, src_len, "strncpy", strncpy);
  test00(dest, sizeof(dest), str, src_len, "my_strncpy", my_strncpy);
  putchar('\n');
}

void test(const char *src)
{
  test0(src, 0);
  test0(src, 1);
  test0(src, 5);
  test0(src, 19);

  size_t src_len = strlen(src);

  /* make test cases depending on the numbers of character */
  if (src_len > 2)
  {
    test0(src, src_len - 1);
  }

  if (src_len > 1)
  {
    test0(src, src_len);
  }

  if (src_len < 20)
  {
    test0(src, src_len + 1);
  }
}

int main(void)
{
  test("");
  test(",.;:;");
  test("hello world");
  test("12345");
  test("\n");
  test("\0");
  test("12fj3j4f");
  test("aaa\0aaa");

  return 0;
}
