#include <iostream>
using namespace std;

int main()
{
  auto coin_flipped_heads = true;
  auto large_number = 2'500'000'000'000;

  cout << "coin_flipped_heads = " << coin_flipped_heads;
  cout << " , sizeof(coin_flipped_heads) = " << sizeof(coin_flipped_heads) << endl;
  cout << "large_number = " << large_number;
  cout << " , sizeof(large_number) = "  << sizeof(large_number) << endl;

  return 0;
}
