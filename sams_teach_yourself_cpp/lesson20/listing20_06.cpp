#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

template <typename t1, typename t2>
void display_unordered_map(unordered_map<t1, t2> & cont)
{
  cout << "Unordered Map contains: " << endl;
  for (auto element = cont.cbegin();
      element != cont.end();
      ++element)
  {
    cout << element->first << " -> " << element->second << endl;
  }

  cout << "Number of pairs, size(): " << cont.size() << endl;
  cout << "Bucket count = " << cont.bucket_count() << endl;
  cout << "Current load factor: " << cont.load_factor() << endl;
  cout << "Max load factor = " << cont.max_load_factor() << endl;
}

int main()
{
  unordered_map<int, string> umap_int_to_str;
  umap_int_to_str.insert(make_pair(1, "One"));
  umap_int_to_str.insert(make_pair(45, "Forty Five"));
  umap_int_to_str.insert(make_pair(-2, "Minus Two"));
  umap_int_to_str.insert(make_pair(1000, "Thousand"));
  umap_int_to_str.insert(make_pair(-1000, "Minus One Thousand"));
  umap_int_to_str.insert(make_pair(100, "One Hundred"));
  umap_int_to_str.insert(make_pair(-100, "Minus One Hundred"));
  umap_int_to_str.insert(make_pair(12, "Twelve"));

  display_unordered_map<int, string>(umap_int_to_str);

  cout << "Inserting one more element" << endl;
  umap_int_to_str.insert(make_pair(300, "Three Hundred"));
  display_unordered_map<int, string>(umap_int_to_str);

  cout << "Enter key to find for: ";
  int key = 0;
  cin >> key;

  auto element = umap_int_to_str.find(key);
  if (element != umap_int_to_str.end())
  {
    cout << "Found! Key pairs with value " << element->second << endl;
  }
  else
  {
    cout << "Key has no corresponding pair value!" << endl;
  }

  return 0;
}
