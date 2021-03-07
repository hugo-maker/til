#include <iostream>
#include <string>
using namespace std;

class aggregate1
{
public:
  int num;
  double pi;
};

struct aggregate2
{
  char hello[6];
  int imp_years[3];
  string world;
};

int main()
{
  int my_nums[] = {9, 5, -1};
  aggregate1 a1{2017, 3.14};
  cout << "Pi is approximately: " << a1.pi << endl;

  aggregate2 a2{ {'h', 'e', 'l', 'l', 'o'}, {2011, 2014, 2017}, "world"};

  // Alternatively
  aggregate2 a2_2{'h', 'e', 'l', 'l', 'o', '\0', 2011, 2014, 2017, "world"};

  cout << a2.hello << ' ' << a2.world << endl;
  cout << "C++ standard update sceduled in: " << a2.imp_years[2] << endl;

  return 0;
}
