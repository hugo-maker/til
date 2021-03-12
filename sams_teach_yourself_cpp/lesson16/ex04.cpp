#include <string>
#include <iostream>

int main()
{
  using namespace std;

  string object1("I");
  string object2("Love");
  string object3("STL");
  string object4("String.");
  string space(" ");

  string sentence = object1 + space + object2 + space + object3 + space + object4;
  cout << sentence << endl;

  return 0;
}
