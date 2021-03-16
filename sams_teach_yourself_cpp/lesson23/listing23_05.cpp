#include <algorithm>
#include <vector>
#include <list>
#include <iostream>
#include <ctime>
using namespace std;

int main()
{
  srand(time(NULL));

  vector<int> nums_in_vec(5);
  generate(nums_in_vec.begin(), nums_in_vec.end(), rand);

  cout << "Elements in the vector are: ";
  for (size_t index = 0; index < nums_in_vec.size(); ++index)
  {
    cout << nums_in_vec[index] << " ";
  }
  cout << endl;

  list<int> nums_in_list(5);
  generate_n(nums_in_list.begin(), 3, rand);

  cout << "Elements in the list are: ";
  for (auto element = nums_in_list.begin();
      element != nums_in_list.end();
      ++element)
  {
    cout << *element << ' ';
  }
  cout << endl;

  return 0;
}
