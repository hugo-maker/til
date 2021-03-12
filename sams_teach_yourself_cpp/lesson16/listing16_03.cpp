#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string sample_str1("Hello");
  string sample_str2(" String!");

  // concatenate
  sample_str1 += sample_str2;
  cout << sample_str1 << endl << endl;

  string sample_str3(" Fun is not needing to use pointer!");
  sample_str1.append(sample_str3);
  cout << sample_str1 << endl << endl;

  const char * const_cstyle_string = " You however still can!";
  sample_str1.append(const_cstyle_string);
  cout << sample_str1 << endl;

  return 0;
}
