#include <set>
#include <iostream>
using namespace std;

int main()
{
  set<int> set_ints{43, 78, -1, 124};

  // Display contents of the set to the screen
  for (auto element = set_ints.cbegin();
      element != set_ints.end();
      ++element)
  {
    cout << *element << endl;
  }

  // Try finding an element
  auto element_found = set_ints.find(-1);

  // Check if found...
  if (element_found != set_ints.end())
  {
    cout << "Element " << *element_found << " found!" << endl;
  }
  else
  {
    cout << "Element not found in set!" << endl;
  }

  // finding another
  auto another_find = set_ints.find(12345);

  // Check if found...
  if (another_find != set_ints.end())
  {
    cout << "Element " << *another_find << " found!" << endl;
  }
  else
  {
    cout << "Element 12345 not found in set!" << endl;
  }

  return 0;
}
