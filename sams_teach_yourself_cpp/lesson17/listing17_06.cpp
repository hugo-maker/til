#include <iostream>
#include <vector>
using namespace std;

template <typename t>
void display_vector(const vector<t> & input_vec)
{
  for (auto element = input_vec.cbegin();
      element != input_vec.cend();
      ++element)
  {
    cout << *element << ' ';
  }

  cout << endl;
}

int main()
{
  vector<int> integers;

  // Insert sample integers into the vector
  integers.push_back(50);
  integers.push_back(1);
  integers.push_back(987);
  integers.push_back(1001);

  cout << "Vector contains " << integers.size() << " elements: ";
  display_vector(integers);

  // Erase one element at the end
  integers.pop_back();

  cout << "After a call to pop_back()" << endl;
  cout << "Vector contains " << integers.size() << " elements: ";
  display_vector(integers);

  return 0;
}
