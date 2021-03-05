#include <iostream>
using namespace std;
const double pi = 3.14159265;

void query_and_calculate()
{
  cout << "Enter radius: ";
  double radius = 0;
  cin >> radius;

  cout << "Area: " << pi * radius * radius << endl;

  cout << "Do you wish to calculate circumference (y/n)? ";
  char calc_circum = 'n';
  cin >> calc_circum;

  if (calc_circum == 'n')
  {
    return;
  }

  cout << "Circumference: " << 2 * pi * radius << endl;
  return;
}

int main()
{
  query_and_calculate();

  return 0;
}
