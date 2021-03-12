#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string sample_str("Good day String! Today is beautiful!");
  cout << "Sample string is: " << endl << sample_str << endl << endl;

  // Find substring "day" - find() returns position
  size_t char_pos = sample_str.find("day", 0);

  // check if the substring was found...
  if (char_pos != string::npos)
  {
    cout << "First instance \"day\" at pos. " << char_pos << endl;
  }
  else
  {
    cout << "Substring not found." << endl;
  }

  cout << "Locating all instances of substring \"day\"" << endl;
  size_t sub_str_pos = sample_str.find("day", 0);

  while (sub_str_pos != string::npos)
  {
    cout << "\"day\" found at position " << sub_str_pos << endl;

    // Make find() search forward from the next character onwards
    size_t search_offset = sub_str_pos + 1;

    sub_str_pos = sample_str.find("day", search_offset);
  }

  return 0;
}
