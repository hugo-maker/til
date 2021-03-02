#include <iostream>
using namespace std;

int main()
{
  unsigned short u_short_value = 65535;
  cout << "Incrementing unsigned short " << u_short_value << " gives: ";
  cout << ++u_short_value << endl;

  short signed_short = 32767;
  cout << "Incrementing signed short " << signed_short << " gives: ";
  cout << ++signed_short << endl;

  return 0;
}
