#include <iostream>
using namespace std;

enum cardinal_directions
{
  North = 25,
  South,
  East,
  West
};

int main()
{
  cout << "Displaying directions and their symbolic values" << endl;
  cout << "North: " << North << endl;
  cout << "South: " << South << endl;
  cout << "East: " << East << endl;
  cout << "West: " << West << endl;

  cardinal_directions wind_direction = South;
  cout << "Variable wind_direction = " << wind_direction << endl;

  return 0;
}
