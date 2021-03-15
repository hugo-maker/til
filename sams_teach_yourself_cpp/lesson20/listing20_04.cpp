#include <map>
#include <iostream>
#include <string>
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

int main()
{
  multimap<int, string> mmap_int_to_str;

  mmap_int_to_str.insert(make_pair(3, "Three"));
  mmap_int_to_str.insert(make_pair(45, "Forty Five"));
  mmap_int_to_str.insert(make_pair(-1, "Minus One"));
  mmap_int_to_str.insert(make_pair(1000, "Thousand"));

  // Insert duplicates into the multimap
  mmap_int_to_str.insert(make_pair(-1, "Minus One"));
  mmap_int_to_str.insert(make_pair(1000, "Thousand"));

  cout << "The multimap contains " << mmap_int_to_str.size();
  cout << " key-value pairss. " << "They are: " << endl;
  display_contents(mmap_int_to_str);

  // Erasing an element with key as -1 from the multimap
  auto num_pairs_erased = mmap_int_to_str.erase(-1);
  cout << "Erased " << num_pairs_erased << " pairs with -1 as key." << endl;

  // Erase an element given an iterator from the multimap
  auto pair = mmap_int_to_str.find(45);
  if (pair != mmap_int_to_str.end())
  {
    mmap_int_to_str.erase(pair);
    cout << "Erased a pair with 45 as key using an iterator" << endl;
  }

  // Erase a range from the multimap...
  cout << "Erasing the range of pairs with 1000 as key." << endl;
  mmap_int_to_str.erase(mmap_int_to_str.lower_bound(1000), mmap_int_to_str.upper_bound(1000));

  cout << "The multimap now contains" << mmap_int_to_str.size();
  cout << " key-value pairss. " << "They are: " << endl;
  display_contents(mmap_int_to_str);

  return 0;
}
