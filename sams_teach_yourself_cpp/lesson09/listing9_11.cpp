#include <iostream>
using namespace std;

class monster_db
{
private:
  ~monster_db() {}; // private destructor prevents instances on stack

public:
  static void destroy_instance(monster_db * p_instance)
  {
    delete p_instance; // member can invoke private destructor
  }

  void do_something() {} // sample empty member method
};

int main()
{
  monster_db * my_db = new monster_db(); // on heap
  my_db->do_something();

  // uncomment next line to see compile error
  // delete my_db; // private destructor cannot be invoked

  // use static member to release memory
  monster_db::destroy_instance(my_db);

  return 0;
}
