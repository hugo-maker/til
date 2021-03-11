template <typename t>
class everything_but_int
{
public:
  everything_but_int()
  {
    static_assert(sizeof(t) != sizeof(int), "No int please!");
  }
};

int main()
{
  everything_but_int<int> test;
  return 0;
}
