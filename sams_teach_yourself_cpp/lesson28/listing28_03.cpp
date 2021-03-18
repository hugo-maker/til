#include <iostream>
using namespace std;

double divide(double dividend, double divisor)
{
  if (divisor == 0)
  {
    throw "Dividing by 0 is a crime";
  }

  return (dividend / divisor);
}

int main()
{
  cout << "Enter dividend: ";
  double dividend = 0;
  cin >> dividend;
  cout << "Enter divisor: ";
  double divisor = 0;
  cin >> divisor;

  try
  {
    cout << "Result is: " << divide(dividend, divisor);
  }
  catch (const char * exp)
  {
    cout << "Exception: " << exp << endl;
    cout << "Sorry, can not continue!" << endl;
  }

  return 0;
}
