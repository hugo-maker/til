#include <exception>
#include <iostream>
#include <string>
using namespace std;

class custom_exception : public std::exception
{
  string reason;
public:
  // constructor, needs reason
  custom_exception(const char * why) : reason(why) {}

  // redefining virtual function to return 'reason'
  virtual const char * what() const throw()
  {
    return reason.c_str();
  }
};

double divide(double dividend, double divisor)
{
  if (divisor == 0)
  {
    throw custom_exception("custom_exception: dividing by 0 is a crime");
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
  catch (exception & exp) // catch custom_exception, bad_alloc, etc
  {
    cout << exp.what() << endl;
    cout << "Sorry, can not continue!" << endl;
  }

  return 0;
}
