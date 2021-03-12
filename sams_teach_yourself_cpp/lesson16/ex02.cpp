#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a sentence: ";
  string input_sentence;
  getline(cin, input_sentence);
  cout << endl;

  cout << "Your sentence is: " << endl << input_sentence << endl << endl;

  size_t vowels_pos = input_sentence.find_first_of("aeiou", 0);
  unsigned int vowels_num = 0;
  while (vowels_pos != string::npos)
  {
    if (vowels_pos != string::npos)
    {
      ++vowels_num;
    }
    size_t search_offset = vowels_pos + 1;

    vowels_pos = input_sentence.find_first_of("aeiou", search_offset);
  }
  cout << "The number of vowels in your sentence = ";
  cout << vowels_num << endl;

  return 0;
}
