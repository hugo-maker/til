#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class compare_string_no_case
{
public:
  bool operator () (const string & str1, const string & str2) const
  {
    string str1_lower_case;

    // Assign space
    str1_lower_case.resize(str1.size());

    // Convert every character to the lower case
    transform(str1.begin(), str1.end(), str1_lower_case.begin(), ::tolower);

    string str2_lower_case;
    str2_lower_case.resize(str2.size());
    transform(str2.begin(), str2.end(), str2_lower_case.begin(), ::tolower);

    return (str1_lower_case < str2_lower_case);
  }
};

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << endl;
  }
}

int main()
{
  // Define a vector of string to hold names
  vector<string> names;

  // Insert some sample names into the vector
  names.push_back("jim");
  names.push_back("Jack");
  names.push_back("Sam");
  names.push_back("Andy");

  cout << "The names in vector in order of insertion: " << endl;
  display_contents(names);

  cout << "Names after sorting using default std::less<>: " << endl;
  sort(names.begin(), names.end());
  display_contents(names);

  cout << "Names after sorting using predicate that ignores case: " << endl;
  sort(names.begin(), names.end(), compare_string_no_case());
  display_contents(names);

  return 0;
}
