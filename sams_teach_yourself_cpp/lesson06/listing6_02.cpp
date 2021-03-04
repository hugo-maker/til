#include <iostream>
#include <string.h>
#include <string>
using namespace std;
int main()
{
  cout << "Enter a line of text: " << endl;
  string user_input;
  getline(cin, user_input);

  char copy_input[20] = {'\0'};
  if (user_input.length() < 20) // check bounds
  {
    strcpy(copy_input, user_input.c_str());
    cout << "copy_input contains: " << copy_input << endl;
  }
  else
  {
    cout << "Bounds exceeded: won't copy!" << endl;
  }

  return 0;
}
