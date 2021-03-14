#include <set>

// used as a template parameter in set / multiset instantiation
template <typename t>
struct sort_descending
{
  bool operator () (const t & lhs, const t & rhs) const
  {
    return (lhs > rhs);
  }
};

int main()
{
  using namespace std;

  // a simple set or multiset of integers (using default sort predicate)
  set<int> set_ints1;
  multiset<int> mset_ints1;

  // set and multiset instantiated given a user-defined sort predicate
  set<int, sort_descending<int>> set_ints2;
  multiset<int, sort_descending<int>> mset_ints2;

  // creating one set from another, or part of another container
  set<int> set_ints3(set_ints1);
  multiset<int> mset_ints3(set_ints1.cbegin(), set_ints1.cend());

  return 0;
}
