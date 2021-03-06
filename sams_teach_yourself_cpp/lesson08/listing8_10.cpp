#include <iostream>
using namespace std;

void calc_area(const double * const ptr_pi, // const pointer to const data
                const double * const ptr_radius, // i.e. nochanges allowed
                double * const ptr_area) // can change data pointed to
{
  // chekc pointers for validity before using!
  if (ptr_pi && ptr_radius && ptr_area)
  {
    *ptr_area = (*ptr_pi) * (*ptr_radius) * (*ptr_radius);
  }
}

int main()
{
  const double pi = 3.1416;

  cout << "Enter radius of circle: ";
  double radius = 0;
  cin >> radius;

  double area = 0;
  calc_area(&pi, &radius, &area);

  cout << "Area is: " << area << endl;

  return 0;
}
