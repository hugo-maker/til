#include <iostream>
using namespace std;

struct temperature
{
  double kelvin;
  temperature(long double kelvin) : kelvin(kelvin) {}
};

temperature operator "" _C(long double celcius)
{
  return temperature(celcius + 273);
}

temperature operator "" _F(long double fahrenheit)
{
  return temperature((fahrenheit + 459.67) * 5 / 9);
}

int main()
{
  temperature k1 = 31.73_F;
  temperature k2 = 0.0_C;

  cout << "k1 is " << k1.kelvin << " kelvin" << endl;
  cout << "k2 is " << k2.kelvin << " kelvin" << endl;

  return 0;
}
