#include <iostream>
using namespace std;

// Declare a function
int demoConsoleOutput();

int main()
{
  // Call i.e. invoke the function
  demoConsoleOutput();

  return 0;
}

// Define i.e. implement the previously declared function
int demoConsoleOutput()
{
  cout << "Performing subtraction 10 - 5 = " << 10 - 5 << endl;
  cout << "Performing multiplication 10 * 5 = " << 10 * 5 << endl;

  return 0;
}
