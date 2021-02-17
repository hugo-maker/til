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
  mu_assert(blk2bstr(NULL, 1) == NULL, "Passing NULL, should return NULL.");
  mu_assert(blk2bstr(test_str, -1) == NULL, "Passing nagative length, should return NULL.");

  int length = strlen(test_str);
  bstring string = blk2bstr(test_str, length);
  mu_assert(string != NULL, "Recieved NULL from real string.");
  mu_assert(blength(string) == length, "Length do not match.");

  return NULL;
}

char * test_bstrcpy()
{
  bstring test_bstr = bfromcstr("test string");

  mu_assert(bstrcpy(NULL) == NULL, "Passing NULL, should return NULL.");

  bstring new_string = bstrcpy(test_bstr);
  mu_assert(new_string != NULL, "Recieved NULL from real string.");
  mu_assert(blength(new_string) == blength(test_bstr),
      "Length do not match.");

  return NULL;
}

char * test_bassign()
{
  bstring string0 = bfromcstr(NULL);
  bstring string1 = bfromcstr("one two three");
  bstring string2 = bfromcstr("two four six");

  // int bassign(bstring a, const_bstring b);
  // invalid b
  mu_assert(bassign(string1, NULL) == BSTR_ERR, "Passing NULL, should return BSTR_ERR.");
  mu_assert(bassign(string1, string0) == BSTR_ERR, 
      "Passing string whose data is NULL, should return BSTR_ERR(-1).");
  // invalid a
  mu_assert(bassign(NULL, string1) == BSTR_ERR, "Assgining to NULL, should return BSTR_ERR.");
  mu_assert(bassign(string0, string1) == BSTR_ERR,
      "Assigning to string whose data is NULL, should return BSTR_ERR.");

  // OK case
  mu_assert(bassign(string1, string2) == BSTR_OK, "Should return BSTR_OK.");
  mu_assert(blength(string1) == blength(string2), "Length do not much.");

  return NULL;
}

char * test_bassigncstr()
{
  bstring string0 = bfromcstr(NULL);
  bstring string1 = bfromcstr("one two three");

  // invalid destination
  mu_assert(bassign(NULL, string1) == BSTR_ERR, "Assgining to NULL, should return BSTR_ERR.");
  mu_assert(bassign(string0, string1) == BSTR_ERR,
      "Assigning to string whose data is NULL, should return BSTR_ERR.");

  // OK case
  mu_assert(bassigncstr(string1, test_str) == BSTR_OK, "Should return BSTR_OK.");
  mu_assert(blength(string1) == (int)strlen(test_str), "Length do not much.");

  return NULL;
}

char * test_bassignblk()
{
  bstring string0 = bfromcstr(NULL);
  char str_max[INT_MAX];
  bstring string1 = bfromcstr("one");
  bstring string2 = bfromcstr("one two three");

  int length = (int)strlen(test_str);
  // invalid destination
  mu_assert(bassignblk(NULL, test_str, length) == BSTR_ERR,
      "Assgining to NULL, should return BSTR_ERR.");
  mu_assert(bassignblk(string0, test_str, length) == BSTR_ERR,
      "Assigning to string whose data is NULL, should return BSTR_ERR.");

  // invalid source
  mu_assert(bassignblk(string1, NULL, 0) == BSTR_ERR,
      "Source is NULL, should return BSTR_ERR.");
  mu_assert(bassignblk(string1, str_max, INT_MAX) == BSTR_ERR,
      "Source is too long, should return BSTR_ERR.");
  mu_assert(bassignblk(string2, test_str, length) == BSTR_OK,
      "Should return BSTR_OK.");
  mu_assert(blength(string2) == length, "Length do not much.");

  return NULL;
}

/*
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
*/

char * all_tests()
{
  mu_suite_start();

  mu_run_test(test_bfromcstr);
  mu_run_test(test_blk2bstr);
  mu_run_test(test_bstrcpy);
  mu_run_test(test_bassign);
  mu_run_test(test_bassigncstr);
  mu_run_test(test_bassignblk);

  return NULL;
}

RUN_TESTS(all_tests);
