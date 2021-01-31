// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct Object
{
  std::string name;

  // コンストラクタ
  Object(std::string const &name) : name(name)
  {
    std::cout << name << " is constructed.\n"s;
  }

  // デストラクタ
  ~Object()
  {
    std::cout << name << " is destructed.\n"s;
  }
};

void f()
{
  Object obj("f"s);
  throw 0;
}

void g()
{
  Object obj("g"s);
  f();
}

int main()
{
  Object obj("main"s);

  try
  {
    g();
  }
  catch(int e)
  {
    std::cout << "caught.\n"s;
  }
}
