#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> nums_in_vec{25, 101, 2021, -50};

  auto even_num = find_if(nums_in_vec.cbegin(),
                          nums_in_vec.cend(),
                          [](const int & num){return ((num % 2) == 0); } );

  if (even_num != nums_in_vec.cend())
  {
    cout << "Even number in collection is: " << *even_num << endl;
  }

  return 0;
}
