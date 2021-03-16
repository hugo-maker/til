#include <algorithm>
#include <vector>
#include <list>
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
  vector<int> nums_in_vec{2021, 0, -1, 42, 10101, 25, 9, 9, 9};
  list<int> nums_in_list{-1, 42, 10101};

  cout << "The contents of the sample vector are: " << endl;
  display_contents(nums_in_vec);

  cout << "The contents of the sample list are: " << endl;
  display_contents(nums_in_list);

  cout << "search() for the contents of list in vector:" << endl;
  auto range = search(nums_in_vec.cbegin(), // start range to search in
                      nums_in_vec.cend(), // end range to search in
                      nums_in_list.cbegin(), // start range to search for
                      nums_in_list.cend()); // end range to search for

  // check if search found a match
  if (range != nums_in_vec.end())
  {
    cout << "Sequence in list found in vector at position: ";
    cout << distance(nums_in_vec.cbegin(), range) << endl;
  }

  cout << "Searching {9, 9, 9} in vector using search_n(): " << endl;
  auto partial_range = search_n(nums_in_vec.cbegin(), // start range 
                      nums_in_vec.cend(), // end range 
                      3, // count of item to be searched for
                      9); // item to search for

  if (partial_range!= nums_in_vec.end())
  {
    cout << "Sequence {9, 9, 9} found in vector at position: ";
    cout << distance(nums_in_vec.cbegin(), partial_range) << endl;
  }

  return 0;
}
