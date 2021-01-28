// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct IntLike
{
  int data;

  IntLike(int data = 0)
    : data(data)
  {}

  IntLike operator +(IntLike const & right)
  {
    return IntLike {data + right.data};
  }
};

IntLike &operator ++(IntLike &obj)
{
  ++obj.data;
  return obj;
}

IntLike &operator --(IntLike &obj)
{
  --obj.data;
  return obj;
}

IntLike operator ++(IntLike &obj, int)
{
  auto temp = obj;
  ++obj.data;
  return temp;
}

IntLike operator --(IntLike &obj, int)
{
  auto temp = obj;
  --obj.data;
  return temp;
}

int main()
{
  IntLike a(1);
  IntLike b(3);

  ++++a;
  --b;

  a--;
  a++;
  b--;

  IntLike c = a + b;
  std::cout << c.data << "\n"s;
  
  c = a.operator +(b);
  std::cout << c.data << "\n"s;
}
