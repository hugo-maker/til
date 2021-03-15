#include <map>
#include <string>
template <typename key_type>
struct reverse_sort
{
  bool operator () (const key_type & key1, const key_type & key2)
  {
    return (key1 > key2);
  }
};

int main()
{
  using namespace std;

  // map and multimap key of type int to value of type string
  map<int, string> map_int_to_str1;
  multimap<int, string> mmap_int_to_str1;

  // map and multimap constructed as a copy of another
  map<int, string> map_int_to_str2(map_int_to_str1);
  multimap<int, string> mmap_int_to_str2(mmap_int_to_str1);

  // map and multimap constructed given a part of another map or multimap
  map<int, string> map_int_to_str3(map_int_to_str1.cbegin(),
      map_int_to_str1.cend());

  multimap<int, string> mmap_int_to_str3(mmap_int_to_str1.cbegin(),
      mmap_int_to_str1.cend());

  // map and multimap with a predicate that inverses sort order
  map<int, string, reverse_sort<int>> map_int_to_str4(map_int_to_str1.cbegin(),
      map_int_to_str1.cend());

  multimap<int, string, reverse_sort<int>> mmap_int_to_str4(mmap_int_to_str1.cbegin(),
      mmap_int_to_str1.cend());

  return 0;
}
