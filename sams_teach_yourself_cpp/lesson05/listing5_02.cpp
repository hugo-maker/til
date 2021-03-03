#include <iostream>
using namespace std;

int main()
{
  int start_value = 101;
  cout << "Start value of integer being operated: " << start_value << endl;
  int postfix_increment = start_value++;
  cout << "Result of Postfix Increment = " << postfix_increment << endl;
  cout << "After Postfix Increment, start_value = " << start_value << endl;

  start_value = 101;
  int prefix_increment = ++start_value;
  cout << "Result of Prefix Increment = " << prefix_increment << endl;
  cout << "After Prefix Increment, start_value = " << start_value << endl;

  start_value = 101;
  int postfix_decrement = start_value--;
  cout << "Result of Postfix Decrement = " << postfix_decrement << endl;
  cout << "After Postfix Decrement, start_value = " << start_value << endl;

  start_value = 101;
  int prefix_decrement = --start_value;
  cout << "Result of Prefix Decrement = " << prefix_decrement << endl;
  cout << "After Prefix Decrement, start_value = " << start_value << endl;

  return 0;
}
