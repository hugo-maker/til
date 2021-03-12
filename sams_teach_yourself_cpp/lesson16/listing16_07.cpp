#include <string>
#include <iostream>
#include <algorithm>

int main()
{
  using namespace std;

  cout << "Please enter a string for case-convertion:" << endl;
  cout << "> ";

  string in_str;
  getline(cin, in_str);
  cout << endl;

  transform(in_str.begin(), in_str.end(), in_str.begin(), ::toupper);
  cout << "The string converted to upper case is: " << endl;
  cout << in_str << endl << endl;

  transform(in_str.begin(), in_str.end(), in_str.begin(), ::tolower);
  cout << "The string converted to lower case is: " << endl;
  cout << in_str << endl << endl;
  
  return 0;
}
