#include <unordered_set>
#include <iostream>
using namespace std;

template <typename t>
void display_contents(const t & container)
{
  cout << "Unordered set contains: ";
  for (auto element = container.cbegin();
      element != container.cend();
      ++element)
  {
    cout << *element << ' ';
  }
  cout << endl;

  cout << "Number of elements, size() = " << container.size() << endl;
  cout << "Bucket count = " << container.bucket_count() << endl;
  cout << "Max load factor = " << container.max_load_factor() << endl;
  cout << "Load factor: " << container.load_factor() << endl << endl;
}

int main()
{
  unordered_set<int> uset_int{1, -3, 2021, 300, 989, -1, -300, 9};
  display_contents(uset_int);
  uset_int.insert(999);
  display_contents(uset_int);

  cout << "Enter int you want to check for existence in set: ";
  int input = 0;
  cin >> input;
  auto element_found = uset_int.find(input);

  if (element_found != uset_int.end())
  {
    cout << *element_found << " found in set" << endl;
  }
  else
  {
    cout << input << " not available in set" << endl;
  }

  return 0;
}
