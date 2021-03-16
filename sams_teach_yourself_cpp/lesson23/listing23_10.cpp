#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

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
  vector<string> vec_names{"John", "jack", "sean", "Anna"};

  // insert a duplicate
  vec_names.push_back("jack");
  cout << "The initial contents of the vector are: " << endl;
  display_contents(vec_names);

  cout << "The sorted vector contains names in the order: " << endl;
  sort(vec_names.begin(), vec_names.end());
  display_contents(vec_names);

  cout << "Searching for \"John\" using 'binary_search': " << endl;
  bool element_found = binary_search(vec_names.begin(), vec_names.end(), "John");

  if (element_found)
  {
    cout << "Result: \"John\" was found in the vector!" << endl;
  }
  else
  {
    cout << "Element not found " << endl;
  }

  // Erase adjacent duplicates
  auto new_end = unique(vec_names.begin(), vec_names.end());
  vec_names.erase(new_end, vec_names.end());

  cout << "The contents of the vector after using 'unique': " << endl;
  display_contents(vec_names);

  return 0;
}
