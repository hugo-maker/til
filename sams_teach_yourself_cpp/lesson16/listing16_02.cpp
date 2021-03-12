#include <string>
#include <iostream>

int main()
{
  using namespace std;
  string stl_string("Hello String!");

  // Access the contents of the string using array syntax
  cout << "Display elements in string using array-syntax: " << endl;
  for (size_t char_counter = 0; char_counter < stl_string.length(); ++char_counter)
  {
    cout << "Character[" << char_counter << "] is: ";
    cout << stl_string[char_counter] << endl;
  }
  cout << endl;

  // Access the contents of a string using iterators
  cout << "Display elements in string using iterators: " << endl;
  int char_offset = 0;
  for (auto char_locater = stl_string.cbegin(); char_locater != stl_string.cend(); ++char_locater)
  {
    cout << "Character[" << char_offset ++ <<  "] is: ";
    cout << *char_locater << endl;
  }
  cout << endl;

  // Access contents as a const char *
  cout << "The char * representation of the string is: ";
  cout << stl_string.c_str() << endl;

  return 0;
}
