#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string sentence("Good day String! Today is beautiful!");
  cout << "Sample string is: " << endl << sentence << endl << endl;

  cout << "Locating all instances of character 'a'" << endl;
  size_t char_pos = sentence.find('a', 0);

  while (char_pos != string::npos)
  {
    cout << "'a' found at position " << char_pos << endl;

    size_t search_offset = char_pos + 1;

    char_pos = sentence.find('a', search_offset);
  }

  return 0;
}
