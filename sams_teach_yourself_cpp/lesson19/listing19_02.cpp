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

int main()
{
  set<int> set_ints{202, 151, -999, -1};
  set_ints.insert(-1);
  cout << "Contents of the set: " << endl;
  display_contents(set_ints);

  multiset<int> mset_ints;
  mset_ints.insert(set_ints.begin(), set_ints.end());
  mset_ints.insert(-1);
  cout << "Contents of the set: " << endl;
  display_contents(mset_ints);

  cout << "Number of instance of '-1' in the multiset are: '";
  cout << mset_ints.count(-1) << "'" << endl;

  return 0;
}
