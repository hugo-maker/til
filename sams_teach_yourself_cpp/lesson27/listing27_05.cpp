#include <iostream>
#include <string>
using namespace std;

int main()
{
  cout << "Enter a line: " << endl;
  char char_buf[10] = {0};
  cin.get(char_buf, 9);
  cout << "char_buf: " << char_buf << endl;

  return 0;
}
