#include <iostream>
using namespace std;

int main()
{
  cout << "Enter two integers:" << endl;
  int num1 = 0, num2 = 0;
  cin >> num1;
  cin >> num2;

  bool is_equal = (num1 == num2);
  cout << "Result of equality test: " << is_equal << endl;

  bool is_unequal = (num1 != num2);
  cout << "Result of inequality test: " << is_unequal << endl;

  bool is_greter_than = (num1 > num2);
  cout << "Result of " << num1 << " > " << num2;
  cout << " test: " << is_greter_than << endl;

  bool is_less_than = (num1 < num2);
  cout << "Result of " << num1 << " < " << num2;
  cout << " test: " << is_less_than << endl;

  bool is_greater_than_equals = (num1 >= num2);
  cout << "Result of " << num1 << " >= " << num2;
  cout << " test: " << is_greater_than_equals << endl;

  bool is_less_than_equals = (num1 <= num2);
  cout << "Result of " << num1 << " <= " << num2;
  cout << " test: " << is_less_than_equals << endl;

  return 0;
}
