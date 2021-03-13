#include <vector>
#include <iostream>
using namespace std;

void display_vector(const vector<int> & input_vec)
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
  // Instantiate a vector with 4 elements, each initialized to 90
  vector<int> integers(4, 90);

  cout << "The initial contents of the vector: ";
  display_vector(integers);

  // Insert 25 at the beginning
  integers.insert(integers.begin(), 25);

  // Insert 2 numbers of value 45 at the end
  integers.insert(integers.end(), 2, 45);

  cout << "Vector after inserting elements at beginning and end: ";
  display_vector(integers);

  // Another vector containing 2 elements of value 30
  vector<int> another(2, 30);

  // Insert two elements from another container in position[1]
  integers.insert(integers.begin() + 1,
      another.begin(), another.end());

  cout << "Vector after inserting contents from another vector: ";
  cout << "in the middle:" << endl;
  display_vector(integers);

  return 0;
}
