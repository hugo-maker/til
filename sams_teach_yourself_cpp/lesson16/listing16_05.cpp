#include <string>
#include <algorithm>
#include <iostream>

int main()
{
  using namespace std;

  string sample_str("Hello String! Wake up to a beautiful day!");
  cout << "The original sample string is: " << endl;
  cout << sample_str << endl << endl;

  // Delete characters given position and count
  cout << "Truncating the second sentence: " << endl;
  sample_str.erase(13, 28);
  cout << sample_str << endl << endl;

  // Find characters 'S' using find() algorithm
  string::iterator i_char_S = find(sample_str.begin(), sample_str.end(), 'S');

  // if character found, 'erase' to deletes a character
  cout << "Erasing character 'S' from the sample string:" << endl;
  if (i_char_S != sample_str.end())
  {
    sample_str.erase(i_char_S);
  }
  cout << sample_str << endl << endl;

  // Erase a range of characters using an overloaded version of erase()
  cout << "Erasing a range between begin() and end():" << endl;
  sample_str.erase(sample_str.begin(), sample_str.end());

  // Verify the length after the erase() operation above
  if (sample_str.length() == 0)
  {
    cout << "The string is empty" << endl;
  }

  return 0;
}
