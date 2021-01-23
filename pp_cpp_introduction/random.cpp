#include <iostream>
#include <random>

int main()
{
  std::random_device random_device;
  std::mt19937 engine(random_device());
  std::uniform_int_distribution<> dist(1, 6);

  for (int i = 0; i < 10; ++i)
  {
    std::cout << dist(engine) << std::endl;
  }
}
