#include <map>
#include <iostream>
#include <string>
using namespace std;

// type-define the map and multimap definition for easy readability
typedef map<int, string> MAP_INT_STRING;
typedef multimap<int, string> MMAP_INT_STRING;

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
  MAP_INT_STRING map_int_to_str;

  // Insert key-value pairs into the map using value_type
  map_int_to_str.insert(MAP_INT_STRING::value_type(3, "Three"));

  // Insert a pair using function make_pair
  map_int_to_str.insert(make_pair(-1, "Minus One"));

  // Insert a pair object directly
  map_int_to_str.insert(pair<int, string>(1000, "One Thousand"));

  // Use an array-like syntax for inserting key-value paris
  map_int_to_str[1000000] = "One Million";

  cout << "The map contains " << map_int_to_str.size();
  cout << " key-value pairs. They are: " << endl;
  display_contents(map_int_to_str);

  // instantiate a multimap that is a copy of a map
  MMAP_INT_STRING mmap_int_to_str(map_int_to_str.cbegin(), map_int_to_str.cend());

  // The insert function works the same way for multimap too
  // A multimap can store duplicates - insert a duplicates
  mmap_int_to_str.insert(make_pair(1000, "Thousand"));

  cout << endl << "The multimap contains " << mmap_int_to_str.size();
  cout << " key-avlue pairs. They are: " << endl;
  cout << "The elements in the multimap are: " << endl;
  display_contents(mmap_int_to_str);

  // The multimap can return number of pairs with same key
  cout << "The number of pairs in the multimap with 1000 as their key: "
    << mmap_int_to_str.count(1000) << endl;

  return 0;
}
