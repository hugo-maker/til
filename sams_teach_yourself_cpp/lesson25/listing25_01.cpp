#include <bitset>
#include <iostream>
#include <string>

int main()
{
  using namespace std;

  bitset<4> four_bits; // 4 bits initialized to 0000
  cout << "Initial contents of four_bits: " << four_bits << endl;

  bitset<5> five_bits("10101");
  cout << "Initial contents of five_bits: " << five_bits << endl;

  bitset<6> six_bits(0b100001); // C++14 binary literal
  cout << "Initial contents of six_bits: " << six_bits << endl;

  bitset<8> eight_bits(255); // 8 bis initialized to long int 255
  cout << "Initial contents of eight_bits: " << eight_bits << endl;

  // instantiate one bitset as a copy of another
  bitset<8> eight_bits_copy(eight_bits);

  return 0;
}
