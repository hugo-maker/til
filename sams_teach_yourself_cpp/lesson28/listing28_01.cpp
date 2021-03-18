#include <iostream>
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
  catch (...)
  {
    cout << "Exception occured. Got to end, sorry!" << endl;
  }

  return 0;
}
