#include <set>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << ' ';
  }
  cout << endl;
}

typedef multiset<int> MSETINT;

int main()
{
  MSETINT mset_ints{43, 78, 78, -1, 124};

  cout << "multiset contains " << mset_ints.size() << " elements: ";
  display_contents(mset_ints);

  cout << "Enter a number to erase from the set: ";
  int input = 0;
  cin >> input;

  cout << "Erasing " << mset_ints.count(input);
  cout << " instances of value " << input << endl;

  mset_ints.erase(input);

  cout << "multiset now contains " << mset_ints.size() << " elements: ";
  display_contents(mset_ints);

  return 0;
}
