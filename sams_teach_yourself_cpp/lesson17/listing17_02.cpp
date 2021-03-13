#include <iostream>
#include <vector>
using namespace std;

int main()
{
  vector<int> integers;

  // Insert sample integers into the vector:
  integers.push_back(50);
  integers.push_back(1);
  integers.push_back(9876);
  integers.push_back(-1);

  cout << "The vector contains ";
  cout << integers.size() << " Elements" << endl;

  return 0;
}
