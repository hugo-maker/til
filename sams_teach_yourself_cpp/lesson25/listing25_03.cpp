#include <vector>

int main()
{
  using namespace std;

  vector<bool> bool_flags1;

  vector<bool> bool_flags2(10, true);

  vector<bool> bool_flags2_copy(bool_flags2);

  return 0;
}
