#include <iostream>
using namespace std;

int main()
{
  cout << "Enter a number: ";
  int input_num = 0;
  cin >> input_num;

  int half_num = input_num >> 1;
  int quater_num = input_num >> 2;
  int double_num = input_num << 1;
  int quadruple_num = input_num << 2;

  cout << "Quarter: " << quater_num << endl;
  cout << "Half: " << half_num << endl;
  cout << "Double: " << double_num << endl;
  cout << "Quadruple: " << quadruple_num << endl;

  return 0;
}
