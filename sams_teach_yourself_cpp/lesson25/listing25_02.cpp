#include <bitset>
#include <string>
#include <iostream>

int main()
{
  using namespace std;
  bitset<8> input_bits;
  cout << "Enter a 8-bit sequence: ";

  cin >> input_bits;

  cout << "Num 1s you supplied: " << input_bits.count() << endl;
  cout << "Num 0s you supplied: ";
  cout << input_bits.size() - input_bits.count() << endl;

  bitset<8> input_flipped(input_bits);
  input_flipped.flip();

  cout << "Flippend version is: " << input_flipped << endl;

  cout << "Result of AND, OR and XOR between the two: " << endl;
  cout << input_bits << " & " << input_flipped << " = ";
  cout << (input_bits & input_flipped) << endl;

  cout << input_bits << " | " << input_flipped << " = ";
  cout << (input_bits | input_flipped) << endl;

  cout << input_bits << " ^ " << input_flipped << " = ";
  cout << (input_bits ^ input_flipped) << endl;

  return 0;
}
