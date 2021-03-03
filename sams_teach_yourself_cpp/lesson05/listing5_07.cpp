#include <iostream>
#include <bitset>
using namespace std;

int main()
{
  cout << "Enter a number (0 - 255): ";
  unsigned short input_num = 0;
  cin >> input_num;

  bitset<8> input_bits (input_num);
  cout << input_num << " in binary is " << input_bits << endl;

  bitset<8> bitwise_not = (~input_num);
  cout << "Logical NOT ~" << endl;
  cout << "~" << input_bits << " = " << bitwise_not << endl;

  cout << "Logical AND, & with 00001111" << endl;
  bitset<8> bitwise_and = (0x0F & input_num);
  cout << "00001111 & " << input_bits << " = " << bitwise_and << endl;

  cout << "Logical OR, | with 00001111" << endl;
  bitset<8> bitwise_or = (0x0F | input_num);
  cout << "00001111 | " << input_bits << " = " << bitwise_or << endl;

  cout << "Logical XOR, ^ with 00001111" << endl;
  bitset<8> bitwise_xor = (0x0F ^ input_num);
  cout << "00001111 ^ " << input_bits << " = " << bitwise_xor << endl;

  return 0;
}
