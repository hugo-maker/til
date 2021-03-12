#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  // A dynamic array of integers
  vector <int> int_array;

  // Insert sample integers into the array
  int_array.push_back(50);
  int_array.push_back(2991);
  int_array.push_back(23);
  int_array.push_back(9999);

  cout << "The contents of the vector are: " << endl;

  // Walk the vector and reak values using an iterator
  vector <int>::iterator arr_iterator = int_array.begin();

  while (arr_iterator != int_array.end())
  {
    // Write the value to the screen
    cout << *arr_iterator << endl;

    // Increment the iterator to access the next element
    ++arr_iterator;
  }

  // Find an element (say 2991) using the 'find' algorithm
  vector <int>::iterator el_found = find(int_array.begin(), int_array.end(), 2991);

  // check if value was found
  if (el_found != int_array.end())
  {
    // Determine position of element using std::distance
    int el_pos = distance(int_array.begin(), el_found);
    cout << "Value " << *el_found;
    cout << " found in the vector at position: " << el_pos << endl;
  }

  return 0;
}
