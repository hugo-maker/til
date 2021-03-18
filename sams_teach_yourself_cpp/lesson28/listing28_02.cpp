#include <iostream>
#include <exception>
using namespace std;

int main()
{
  cout << "Enter number of integers you wish to reserve: ";
  try
  {
    int input = 0;
    cin >> input;

    // Request memory space and then return it
    int * num_array = new int[input];
    delete[] num_array;
  }
  catch (std::bad_alloc & exp)
  {
    cout << "Exception encountered: " << exp.what() << endl;
    cout << "Got to end, sorry!" << endl;
  }
  catch (...)
  {
    cout << "Exception encountered. Got to end, sorry!" << endl;
  }

  return 0;
}
