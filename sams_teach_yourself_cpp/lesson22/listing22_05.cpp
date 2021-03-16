#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & input)
{
  for (auto element = input.cbegin();
      element != input.cend();
      ++element)
  {
    cout << *element << endl;
  }
  cout << endl;
}

int main()
{
  vector<string> names_in_vec{"jim", "Jack", "Sam", "Anna"};

  cout << "The names in vector in order of insertion: " << endl;
  display_contents(names_in_vec);

  cout << "Order after case sensitive sort: " << endl;
  sort(names_in_vec.begin(), names_in_vec.end());
  display_contents(names_in_vec);

  cout << "Order after sort ignoring case: " << endl;
  sort(names_in_vec.begin(), names_in_vec.end(),
      [](const string & str1, const string & str2) -> bool // lambda
      {
        string str1_lower_case;

        // Assgin space
        str1_lower_case.resize(str1.size());

        // Convert every character to the lower case
        transform(str1.begin(), str1.end(), str1_lower_case.begin(), ::tolower);

        string str2_lower_case;
        str2_lower_case.resize(str2.size());
        transform(str2.begin(), str2.end(), str2_lower_case.begin(), ::tolower);

        return (str1_lower_case < str2_lower_case);
      } // end of lambda
      ); // end of sort

  display_contents(names_in_vec);

  return 0;
}
