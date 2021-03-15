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
  map<int, string> map_int_to_str;

  map_int_to_str.insert(make_pair(3, "Three"));
  map_int_to_str.insert(make_pair(45, "Forty Five"));
  map_int_to_str.insert(make_pair(-1, "Minus One"));
  map_int_to_str.insert(make_pair(1000, "Thousand"));

  cout << "The map contains " << map_int_to_str.size();
  cout << " key-value pairs. They are: " << endl;
  display_contents(map_int_to_str);

  cout << "Enter the key you wish to find: ";
  int key = 0;
  cin >> key;

  auto pair_found = map_int_to_str.find(key);
  if (pair_found != map_int_to_str.end())
  {
    cout << "Key " << pair_found->first << " points to Value: ";
    cout << pair_found->second << endl;
  }
  else
  {
    cout << "Sorry, pair with key " << key << " not in map" << endl;
  }

  return 0;
}
