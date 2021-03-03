#include <iostream>
using namespace std;

int main()
{
  cout << "Use boolean values(0 / 1) to answer the questions" << endl;
  cout << "Is it raining? ";
  bool is_raining = false;
  cin >> is_raining;

  cout << "Do you have buses on the streets? ";
  bool buses_ply = false;
  cin >> buses_ply;

  // Conditional statement usess logical AND and NOT
  if (is_raining && !buses_ply)
  {
    cout << "You cannot go to work" << endl;
  }
  else
  {
    cout << "You can go to work" << endl;
  }

  if (is_raining && buses_ply)
  {
    cout << "Take an umbrella" << endl;
  }

  if (!is_raining && buses_ply)
  {
    cout << "Enjoy the sun and have a nice day" << endl;
  }

  return 0;
}
