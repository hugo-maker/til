// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

class Integer
{
  int * ptr;
public:
  // 暗黙の型変換を禁止
  // これが60行目のコンパイルエラーの原因?
  // explicit Integer(int value = 0)
  Integer(int value = 0)
    : ptr(new int(value))
  {}
  ~Integer()
  {
    delete ptr;
  }

  // copy
  Integer(const Integer & r)
    : ptr(new int(*r.ptr))
  {}
  Integer & operator =(const Integer & r)
  {
    if (this != &r)
    {
      * ptr = *r.ptr;
    }
    return *this;
  }

  // move
  Integer(Integer && r)
    : ptr(r.ptr)
  {
    r.ptr = nullptr;
  }
  Integer operator =(Integer && r)
  {
    delete ptr;
    ptr = r.ptr;
    r.ptr = nullptr;
    return *this;
  }

  // 複合代入演算子
  Integer & operator +=(const Integer & r)
  {
    *ptr += *r.ptr;
    return *this;
  }
  Integer & operator -=(const Integer & r)
  {
    *ptr -= *r.ptr;
    return *this;
  }

  // 単項演算子
  // lvalue version
  // auto result = (-*ptr) はcompile error
  Integer operator -() const &
  {
    auto result = (-*ptr);
    return result;
  }
  // rvalue version
  Integer operator -() &&
  {
    auto result = std::move(*this);
    *result.ptr = -*result.ptr;
    return result;
  }

  // 二項演算子
  /*
  // ムーブしない実装
  // メンバー関数として実装しているため、第一引数は*this, 第二引数が関数の引数r
  Integer operator +(const Integer & r) const
  {
    return Integer(*ptr + *r.ptr);
  }
  */

  // ムーブする実装
  // 第一引数がlvalue, 第二引数がlvalue
  Integer operator +(const Integer & r) const &
  {
    return Integer(*ptr + *r.ptr);
  }
  // 第一引数がrvalue, 第二引数がlvalue
  Integer operator +(const Integer & r) &&
  {
    auto result = std::move(*this);
    result += r;
    return result;
  }
  // 第一引数がlvalue, 第二引数がrvalue
  Integer operator +(Integer && r) const &
  {
    auto result = std::move(r);
    result += *this;
    return result;
  }
  // 第一引数がrvalue, 第二引数がrvalue
  Integer operator +(Integer && r) &&
  {
    auto result = std::move(*this);
    result += r;
    return result;
  }
};

int main()
{
  Integer a(10);
  auto b = a + a + a;
  b = a;
  b += a;
  b -= a;
  b = -b;
  b = -(a + a + a);
}
