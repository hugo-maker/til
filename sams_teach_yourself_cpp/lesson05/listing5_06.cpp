#include <iostream>
using namespace std;

int main()
{
  cout << "Answer questions with 0 or 1" << endl;
  cout << "Is there a discount on your favorite car? ";
  bool on_discount = false;
  cin >> on_discount;

  cout << "Did you get a fantastic bonus? ";
  bool fantastic_bonus = false;
  cin >> fantastic_bonus;

  if (on_discount || fantastic_bonus)
  {
    cout << "Congratulations, you can buy that car!" << endl;
  }
  else
  {
    cout << "Sorry, waiting a while is a good idea" << endl;
  }

  if (!on_discount)
  {
    cout << "Car not on discount" << endl;
  }

  return 0;
}
