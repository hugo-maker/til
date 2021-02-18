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

  // OK case
  mu_assert(bassignblk(string2, test_str, length) == BSTR_OK,
      "Should return BSTR_OK.");
  mu_assert(blength(string2) == length, "Length do not much.");

  return NULL;
}

char * test_bdestroy()
{
  bstring test_bstr = bfromcstr("test string");
  bstring null_bstr = bfromcstr(NULL);
  // invalid bstring
  mu_assert(bdestroy(NULL) == BSTR_ERR,
      "Passing NULL, should return BSTR_ERR.");
  mu_assert(bdestroy(null_bstr) == BSTR_ERR,
      "Passing null-data bstring, should return BSTR_ERR.");

  // OK case
  mu_assert(bdestroy(test_bstr) == BSTR_OK,
      "should return BSTR_OK.");

  return NULL;
}

char * test_bconcat()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b0 = bfromcstr("one two three");
  bstring b1 = bfromcstr("four five six");

  int after_concat_length = blength(b0) + blength(b1);

  // invalid destination or source
  mu_assert(bconcat(NULL, b0) == BSTR_ERR,
      "Passing NULL destination, should return BSTR_ERR.");
  mu_assert(bconcat(null_bstr, b0) == BSTR_ERR,
      "Passing null-data destination, should return BSTR_ERR.");
  mu_assert(bconcat(b0, NULL) == BSTR_ERR,
      "Passing NULL source, should return BSTR_ERR.");
  mu_assert(bconcat(b0, null_bstr) == BSTR_ERR,
      "Passing null-data source, should return BSTR_ERR.");

  // OK case
  mu_assert(bconcat(b0, b1) == BSTR_OK, "should return BSTR_OK.");

  mu_assert(blength(b0) == after_concat_length,
      "Length do not match.");

  return NULL;
}

char * test_bstricmp()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b0 = bfromcstr("Abc");
  bstring b1 = bfromcstr("abCD");
  bstring b2 = bfromcstr("aBcd");

  // invalid bstring
  mu_assert(bstricmp(NULL, b1) == SHRT_MIN, "Should return SHRT_MIN.");
  mu_assert(bstricmp(b0, NULL) == SHRT_MIN, "Should return SHRT_MIN.");

  // ?
  mu_assert(bstricmp(null_bstr, b1) == SHRT_MIN, "Should return SHRT_MIN.");
  mu_assert(bstricmp(b0, null_bstr) == SHRT_MIN, "Should return SHRT_MIN.");

  // two bstring are equal
  mu_assert(bstricmp(b1, b2) == BSTR_OK, "Should return BSTR_OK.");

  // two bstring are different
  mu_assert(bstricmp(b0, b1) == - (char) downcase(b1->data[b0->slen]),
      "Do not expected return value.");
  mu_assert(bstricmp(b1, b0) == (char) downcase(b1->data[b0->slen]),
      "Do not expected return value.");
    
  // first extra character is '\0'

  return NULL;
}

char * test_biseq()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b0 = bfromcstr("abc");
  bstring b1 = bfromcstr("abc");
  bstring b2 = bfromcstr("\0");
  // invalid bstring
  mu_assert(biseq(NULL, b0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(biseq(b0, NULL) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(biseq(null_bstr, b0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(biseq(b0, null_bstr) == BSTR_ERR, "Should return BSTR_ERR.");
  // equal
  mu_assert(biseq(b0, b1) == 1, "These strings are the same.");
  // differ
  mu_assert(biseq(b0, b2) == 0, "These strings differ.");

  return NULL;
}

char * test_binstr()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b1 = bfromcstr("onetwothree");
  bstring b2 = bfromcstr("two");
  bstring b3 = bfromcstr("\0");


  // invalid bstring
  mu_assert(binstr(NULL, 0, b2) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(binstr(null_bstr, 0, b2) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(binstr(b1, 0, NULL) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(binstr(b1, 0, null_bstr) == BSTR_ERR, "Should return BSTR_ERR.");

  // case b1->slen == pos
  int pos = b1->slen;
  mu_assert(binstr(b1, pos, b3) == pos, "Do not expected return value.");
  mu_assert(binstr(b1, pos, b2) == BSTR_ERR, "Should return BSTR_ERR.");

  // invalid pos
  mu_assert(binstr(b1, pos + 1, b2) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(binstr(b1, -1, b2) == BSTR_ERR, "Should return BSTR_ERR.");
  int wrong_pos = b1->slen - b2->slen + 2;
  mu_assert(binstr(b1, wrong_pos, b2) == BSTR_ERR, "No space to find such a string.");

  // case b2->slen == 0
  mu_assert(binstr(b1, 1, b3) == 1, "Do not expected return value.");

  // OK case
  mu_assert(binstr(b1, 0, b2) == 3, "Do not expected return value.");

  return NULL;
}

char * test_bfindreplace()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b1 = bfromcstr("onetwothree");
  bstring find = bfromcstr("two");
  bstring replace = bfromcstr("2");

  mu_assert(bfindreplace(NULL, find, replace, 0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(bfindreplace(b1, NULL, replace, 0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(bfindreplace(b1, find, NULL, 0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(bfindreplace(null_bstr, find, replace, 0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(bfindreplace(b1, null_bstr, replace, 0) == BSTR_ERR, "Should return BSTR_ERR.");
  mu_assert(bfindreplace(b1, find, null_bstr, 0) == BSTR_ERR, "Should return BSTR_ERR.");

  mu_assert(bfindreplace(b1, find, replace, 0) == BSTR_OK, "Should return BSTR_OK.");
  return NULL;
}

char * test_bsplit()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b1 = bfromcstr("onetwothree");
  // invalid bstring
  mu_assert(bsplit(NULL, 'a') == NULL, "Passing NULL as bstring, return NULL.");
  mu_assert(bsplit(null_bstr, 'a') == NULL, "Passing null-string, return NULL.");

  // case splitChar is '\0'
  struct bstrList * zero_divided_bstrList = bsplit(b1, '\0');
  bstring b2 = *(zero_divided_bstrList->entry);
  mu_assert(bstricmp(b1, b2) == 0, "Do not match length.");

  struct bstrList * b1_strList = bsplit(b1, 't');
  bstring b3 = *(b1_strList->entry);
  mu_assert(bstricmp(b1, b3) > 0, "Do not expected return value.");

  return NULL;
}

char * test_bformat()
{
  bstring null_bstr = bfromcstr(NULL);
  bstring b1 = bfromcstr("onetwothree");

  mu_assert(bformat(NULL) == NULL, "Passing NULL, should return NULL.");

  null_bstr = bformat("%s", test_str);
  mu_assert(blength(null_bstr) == (int)strlen(test_str), "Do not match length.");

  b1 = bformat("%s", test_str);
  mu_assert(blength(b1) == (int)strlen(test_str), "Do not match length.");

  return NULL;
}

char * test_bdata_bchar()
{

  bstring null_bstr = bfromcstr(NULL);
  bstring b1 = bfromcstr("onetwothree");

  mu_assert(bdata(null_bstr) == NULL, "Wrong data from null_bstr.");
  mu_assert(bdata(b1) == (char *)(b1->data), "Wrong data from b1.");

  mu_assert(bchar(null_bstr, 0) == 0, "Unexpected return value.");
  mu_assert(bchar(b1, 100) == '\0', "Unexpected return value.");
  mu_assert(bchar(b1, 4) == b1->data[4], "Unexpected return value.");

  return NULL;
}

char * all_tests()
{
  mu_suite_start();

  mu_run_test(test_bfromcstr);
  mu_run_test(test_blk2bstr);
  mu_run_test(test_bstrcpy);
  mu_run_test(test_bassign);
  mu_run_test(test_bassigncstr);
  mu_run_test(test_bassignblk);
  mu_run_test(test_bdestroy);
  mu_run_test(test_bconcat);
  mu_run_test(test_bstricmp);
  mu_run_test(test_biseq);
  mu_run_test(test_binstr);
  mu_run_test(test_bfindreplace);
  mu_run_test(test_bsplit);
  mu_run_test(test_bformat);
  mu_run_test(test_bdata_bchar);

  return NULL;
}

RUN_TESTS(all_tests);
