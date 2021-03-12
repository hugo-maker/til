#include <string>
#include <iostream>
#include <algorithm>

int main()
{
  using namespace std;
  cout << "Enter a string: " << endl;
  cout << "> ";

  string input;
  getline(cin, input);
  cout << endl;

  for (size_t i = 0; i < input.length(); i += 2)
  {
    input[i] = toupper(input[i]);
  }

  cout << "The string converted to upper case is: " << endl;
  cout << input << endl << endl;

  return 0;
}
