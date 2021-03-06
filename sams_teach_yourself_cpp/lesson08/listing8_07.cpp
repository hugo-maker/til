#include <iostream>
using namespace std;

int main()
{
  // Request for memory space for an int
  int * points_to_an_age = new int;

  // Use the allocated memory to store a number
  cout << "Enter your dog's age: ";
  cin >> *points_to_an_age;

  // Use indirection operator* to access value
  cout << "Age " << *points_to_an_age << " is stored at " << hex << points_to_an_age << endl;

  delete points_to_an_age; //release memory

  return 0;
}
