#include <iostream>
#include <string>
using namespace std;

class president
{
private:
  president() {}; // private default constructor
  president(const president &); // private copy constructor
  const president & operator =(const president &); // assignment operator

  string name;

public:
  static president & get_instance()
  {
    // static objects are constructed only once
    static president only_instance;
    return only_instance;
  }

  string get_name()
  {
    return name;
  }

  void set_name(string input_name)
  {
    name = input_name;
  }
};

int main()
{
  president & only_president = president::get_instance();
  only_president.set_name("Abraham Lincoln");

  // uncomment lines to see how compile failures prohibit duplicates
  // president second; // cannot access constructor
  // president * third = new president(); //cannot access constructor
  // president fourth = only_president; // cannot access copy constructor
  // only_president = president::get_instance(); // cannot access operator =

  cout << "The name of the president is: ";
  cout << president::get_instance().get_name() << endl;

  return 0;
}
