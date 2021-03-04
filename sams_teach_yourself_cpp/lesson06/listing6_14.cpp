#include <iostream>
using namespace std;

int main()
{
  const int ARRAY1_LEN = 3;
  const int ARRAY2_LEN = 2;

  int my_nums1[ARRAY1_LEN] = {35, -3, 0};
  int my_nums2[ARRAY2_LEN] = {20, -1};

  cout << "Multiplying each int in my_nums1 by each in my_nums2:" << endl;

  for (int index1 = 0; index1 < ARRAY1_LEN; ++index1)
  {
    for (int index2 = 0; index2 < ARRAY2_LEN; ++index2)
    {
      cout << my_nums1[index1] << " x " << my_nums2[index2] \
        << " = " << my_nums1[index1] * my_nums2[index2] << endl;
    }
  }

  return 0;
}
