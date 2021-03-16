#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int main()
{
  // Initialize a sample vector with 3 elements
  vector<int> nums_in_vec(3);

  // fill all elements in the container with value 9
  fill(nums_in_vec.begin(), nums_in_vec.end(), 9);

  // Increase the size of the vector to hold 6 elements
  nums_in_vec.resize(6);

  // fill the three elements starting at offset position 3 with value -9
  fill_n(nums_in_vec.begin() + 3, 3, -9);

  cout << "Contents of the vector are: " << endl;
  for (size_t index = 0; index < nums_in_vec.size(); ++index)
  {
    cout << "Element[" << index << "] = ";
    cout << nums_in_vec[index] << endl;
  }

  return 0;
}
