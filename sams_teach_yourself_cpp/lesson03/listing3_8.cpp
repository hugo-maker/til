#include <iostream>
constexpr double get_pi() {return 22.0 / 7;}
constexpr double twice_pi() {return 2 * get_pi();}

int main()
{
  using namespace std;
  const double pi = 22.0 / 7;

  cout << "constant pi contains value " << pi << endl;
  cout << "constexpr get_pi() returns value " << get_pi() << endl;
  cout << "constexpr twice_pi() returns value " << twice_pi() << endl;

  return 0;
}
