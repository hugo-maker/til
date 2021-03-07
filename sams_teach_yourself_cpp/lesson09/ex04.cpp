#include <iostream>
using namespace std;

class circle
{
private:
  const double pi;
  double radius;

public:
  circle(double circles_radius)
    : radius(circles_radius), pi(3.1416) {}

  double get_area()
  {
    return pi * radius * radius;
  }

  double get_circumference()
  {
    return pi * 2 * radius;
  }
};

int main()
{
  cout << "Enter a radius: ";
  double radius = 0;
  cin >> radius;

  circle my_circle(radius);

  cout << "area = " << my_circle.get_area() << endl;
  cout << "circumference = " << my_circle.get_circumference() << endl;

  return 0;
}
