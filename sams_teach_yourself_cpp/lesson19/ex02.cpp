#include <set>
#include <iostream>
#include <string>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto i_element = container.cbegin();
      i_element != container.cend();
      ++i_element)
  {
    cout << *i_element << endl;
  }
  cout << endl;
}

struct dictionary
{
  string word;
  string meaning;
  string display_as;

  dictionary(const string & word_init, const string & meaning_init)
  {
    word = word_init;
    meaning = meaning_init;
    display_as = (word + ": " + meaning);
  }

  bool operator == (const dictionary & dictionary_to_compare) const
  {
    return (dictionary_to_compare.word == this->word);
  }

  bool operator < (const dictionary & dictionary_to_compare) const
  {
    return (this->word < dictionary_to_compare.word);
  }

  operator const char * () const
  {
    return display_as.c_str();
  }
};

int main()
{
  multiset<dictionary> mset_dictionary;
  mset_dictionary.insert(dictionary("magnitude", 
        "The absolute or relative size, extent or importance of something."));
  mset_dictionary.insert(dictionary("duplicate", "Being the same as another;\
        identical, often having been copied from an original."));

  display_contents(mset_dictionary);

  cout << "Enter a word you wish to find the meaning off" << endl;
  string input;
  getline(cin, input);
  auto element = mset_dictionary.find(dictionary(input, ""));

  if (element != mset_dictionary.end())
  {
    cout << "Meaning is: " << (*element).meaning << endl;
  }
  else
  {
    cout << "Word not found" << endl;
  }

  return 0;
}
