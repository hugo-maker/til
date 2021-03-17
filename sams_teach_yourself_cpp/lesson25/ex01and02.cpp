#include <bitset>
#include <iostream>

int main()
{
  using namespace std;

  bitset<4> four_bits1(9);

  cout << "four_bits1: " << four_bits1 << endl;

  bitset<4> four_bits2(2);

  cout << "Four_bits2: " <<four_bits2 << endl;

  bitset<4> add_result(four_bits1.to_ulong() + four_bits2.to_ulong());
  cout << "The result of the addition is: " << add_result << endl;

  add_result.flip();
  cout << "The result of the flip is: " << add_result << endl;

  return 0;
}
