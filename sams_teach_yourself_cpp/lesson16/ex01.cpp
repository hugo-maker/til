#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a word: ";
  string word;
  getline(cin, word);
  cout << endl;

  string word_copy = word;

  reverse(word_copy.begin(), word_copy.end());

  if (word == word_copy)
  {
    cout << "Your word is a palindrome!" << endl;
  }
  else
  {
    cout << "Your word before reverse: " << word << endl;
    cout << "Your word after reverse: " << word_copy << endl;
  }

  return 0;
}
