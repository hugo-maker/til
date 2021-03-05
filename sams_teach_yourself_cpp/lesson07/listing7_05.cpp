#include <iostream>
using namespace std;

int get_fib_number(int fib_index)
{
  if (fib_index < 2)
  {
    return fib_index;
  }
  else
  {
    return get_fib_number(fib_index - 1) + get_fib_number(fib_index - 2);
  }
}

int main()
{
  cout << "Enter 0-based index of desired Fibonacci Number: ";
  int index = 0;
  cin >> index;

  cout << "Fibonacci number is: " << get_fib_number(index) << endl;
}
