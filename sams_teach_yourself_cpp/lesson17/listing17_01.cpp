#include <vector>

int main()
{
  // vector of integers
  std::vector<int> integers;

  // vector initialized using C++11 list initialization
  std::vector<int> init_vector{202, 2017, -1};

  // Instantiate a vector with 10 elements (it can still grow)
  std::vector<int> ten_elemetns(10);

  // Instantiate a vector with 10 elements, each initialized to 90
  std::vector<int> ten_elem_init(10, 90);

  // Initialize vector to the contents of another
  std::vector<int> copy_vector(ten_elem_init);

  // Vector initialized to 5 elements from another using iterators
  std::vector<int> partial_copy(ten_elemetns.cbegin(), ten_elemetns.cbegin() + 5);

  return 0;
}
