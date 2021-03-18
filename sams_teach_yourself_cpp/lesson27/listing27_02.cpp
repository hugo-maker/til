#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
  const double pi = (double)22.0 / 7;
  cout << "pi = " << pi << endl;

  cout << endl << "Setting precision to 7: " << endl;
  cout << setprecision(7);
  cout << "pi = " << pi << endl;
  cout << fixed << "Fixed pi = " << pi << endl;
  cout << scientific << "Scientific pi = " << pi << endl;

  cout << endl << "Setting precision to 10: " << endl;
  cout << setprecision(10);
  cout << "pi = " << pi << endl;
  cout << fixed << "Fixed pi = " << pi << endl;
  cout << scientific << "Scientific pi = " << pi << endl;

  cout << endl << "Enter a radius: ";
  double radius = 0.0;
  cin >> radius;
  cout << "Area of circle: " << pi * radius * radius << endl;

  return 0;
}
