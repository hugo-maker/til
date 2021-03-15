#include <map>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << element->first << " -> " << element->second << endl;
  }
  cout << endl;
}

struct pred_ignore_case
{
  bool operator () (const string & str1, const string & str2) const
  {
    string str1_no_case(str1), str2_no_case(str2);
    transform(str1.begin(), str1.end(), str1_no_case.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2_no_case.begin(), ::tolower);

    return(str1_no_case < str2_no_case);
  }
};

typedef map<string, string> DIR_WITH_CASE;
typedef map<string, string, pred_ignore_case> DIR_NOCASE;

int main()
{
  // Case-sensitive directorycase of string-key plays no role
  DIR_WITH_CASE dir_with_case;

  dir_with_case.insert(make_pair("John", "2345764"));
  dir_with_case.insert(make_pair("JOHN", "2345764"));
  dir_with_case.insert(make_pair("Sara", "42367236"));
  dir_with_case.insert(make_pair("Jack", "323435348"));

  cout << "Displaying contents of the case_sensitive map:" << endl;
  display_contents(dir_with_case);

  // Case-insensitive mapase of string-key affects insertion & search
  DIR_NOCASE dir_no_case(dir_with_case.begin(), dir_with_case.end());

  cout << "Displaying contents of the case-insensitive map:" << endl;
  display_contents(dir_no_case);

  // Search for a name in the two maps and display result
  cout << "Please enter a name to search" << endl << "> ";
  string name;
  cin >> name;

  auto pair_with_case = dir_with_case.find(name);
  if (pair_with_case != dir_with_case.end())
  {
    cout << "Num in case-sens. dir: " << pair_with_case->second << endl;
  }
  else
  {
    cout << "Num not found in case-sensitive dir" << endl;
  }

  auto pair_no_case = dir_no_case.find(name);
  if (pair_no_case != dir_no_case.end())
  {
    cout << "Num found in CI dir: " << pair_no_case->second << endl;
  }
  else
  {
    cout << "Num not found in the case-insensitive directory" << endl;
  }

  return 0;
}
