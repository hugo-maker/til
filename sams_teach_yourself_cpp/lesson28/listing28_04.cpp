#include <iostream>
using namespace std;

struct structA
{
  structA() {cout << "structA constructor" << endl; }
  ~structA() {cout << "structA destructor" << endl; }
};

struct structB
{
  structB() {cout << "structB constructor" << endl; }
  ~structB() {cout << "structB destructor" << endl; }
};

void funcB() // throws
{
  cout << "In funcB" << endl;
  structA objA;
  structB objB;
  cout << "About to throw up!" << endl;
  throw "Throwing for the heck of it";
}

void funcA()
{
  try
  {
    cout << "In funcA" << endl;
    structA objA;
    structB objB;
    funcB();
    cout << "funcA: returning to caller" << endl;
  }
  catch (const char * exp)
  {
    cout << "funcA: caught exception: " << exp << endl;
    cout << "handled it, will not throw to caller" << endl;
    // throw; // uncomment this line to throw to main()
  }
}

int main()
{
  cout << "main(): started execution!" << endl;
  try
  {
    funcA();
  }
  catch (const char * exp)
  {
    cout << "Exception: " << exp << endl;
  }
  cout << "main(): exiting gracefully" << endl;
  return 0;
}
