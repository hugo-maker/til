// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h decimal_to_binary.cpp -o decimal_to_binary
int convert(int n);

int solve(int n);

int input()
{
  std::cout << "> ";
  int x {};
  std::cin >> x;
  return x;
}

void output(int binary)
{
  std::cout << binary << "\n"s;
}

int convert(int n)
{
  if (n > 0)
  {
    return solve(n);
  }
  else
  {
    return -solve(-n);
  }
}

int solve(int n)
{
  if (n <= 1)
  {
    return n;
  }
  else
  {
    return n % 10 + 2 * solve(n / 10);
  }
}

int main()
{
  while (true)
  {
    auto decimal = input();
    auto binary = convert(decimal);
    output(binary);
  }
}
