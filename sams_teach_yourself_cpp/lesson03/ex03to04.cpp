#include <iostream>

constexpr double get_pi() {return 22.0 / 7;}

int main()
{
  using namespace std;

  cout << "Enter a radius: ";
  double radius = 0;
  cin >> radius;

  cout << "area = " << radius * radius * get_pi() << endl;
  cout << "circumference = " << radius * 2 * get_pi()  << endl;

  int area_integer = radius * radius * get_pi();
  int circumference_integer = radius * 2 * get_pi();
  cout << "area(integer) = " << area_integer << endl;
  cout << "circumference(integer) = " << circumference_integer << endl;
}
