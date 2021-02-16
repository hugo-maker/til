#include "minunit.h"
#include "lcthw/bstrlib.c"
#include "lcthw/dbg.h"

char * test_str = "A string";

char * test_bfromcstr()
{
  mu_assert(bfromcstr(NULL) == NULL, "Passing NULL, should return NULL.");

  bstring string = bfromcstr(test_str);
  mu_assert(string != NULL, "Recieved NULL from real string.");
  mu_assert(blength(string) == (int)strlen(test_str),
      "Length do not match.");

  return NULL;
}

char * test_blk2bstr()
{
}

char * test_bstrcpy()
{
}

char * test_bassigncstr()
{
}

char * test_bassignblk()
{
}

char * test_bestory()
{
}

char * test_bconcat()
{
}

char * test_bstricmp()
{
}

char * test_biseq()
{
}

char * test_binstr()
{
}

char * test_findreplace()
{
}

char * test_bsplit()
{
}

char * test_bformat()
{
}

char * test_bdata()
{
}

char * test_bchar()
{
}

char * all_tests()
{
  mu_suite_start();

  mu_run_test();
}

RUN_TESTS(all_tests);
