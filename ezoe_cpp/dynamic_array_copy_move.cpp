// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// 雛形
struct X
{
  // コピーコンストラクタ
  X(const X &);
  // コピー代入演算子
  X & operator =(const X &);

  // ムーブコンストラクタ
  X(X &&);
  // ムーブ代入演算子
  X & operator =(X &&);
};

template <typename T>
class dynamic_array
{
private:
  T * first;
  T * last;
public:
  dynamic_array(std::size_t size = 0)
    : first(new T[size]), last(first + size)
  {}
  ~dynamic_array()
  {
    delete[] first;
    std::cout << "destructor"s << std::endl;
  }

  // コピーコンストラクタ
  dynamic_array(const dynamic_array & r)
    : first(new T[r.size()]), last(first + r.size())
  {
    std::copy(r.begin(), r.end(), begin());
    std::cout << "copy constructor"s << std::endl;
  }

  T & operator [](std::size_t i) const noexcept
  {
    return first[i];
  }
  std::size_t size() const noexcept
  {
    return last - first;
  }
  T * begin() const noexcept
  {
    return first;
  }
  T * end() const noexcept
  {
    return last;
  }

  // コピー代入演算子
  dynamic_array & operator =(const dynamic_array & r)
  {
    // 自分自身への代入でない かつ サイズが異なる場合
    if (this != &r && size() != r.size())
    {
      // コピー先が所有しているメモリの解放
      delete first;
      // コピー元と同サイズの動的メモリ確保
      first = new T[r.size()];
      last = first + r.size();
      // コピー元の値をコピー
      std::copy(r.begin(), r.end(), begin());
    }
    return *this;
  }

  // ムーブコンストラクタ
  dynamic_array(dynamic_array && r)
    // ムーブ先へ所有権の移動
    : first(r.first), last(r.last)
  {
    // ムーブ元の所有権の放棄
    r.first = nullptr;
    r.last = nullptr;
    std::cout << "move constructor"s << std::endl;
  }

  // ムーブ代入演算子
  dynamic_array & operator =(dynamic_array && r)
  {
    // ムーブ先のストレージの解放
    delete first;

    // ムーブ先へ所有権の移動
    first = r.first;
    last = r.last;
    // ムーブ元の所有権の放棄
    r.first = nullptr;
    r.last = nullptr;

    return *this;
  }
};

int main()
{
  dynamic_array<int> a(5);
  dynamic_array<int> b = a;
  std::for_each(b.begin(), b.end(), [&b] (auto i) {std::cout << b[i] << "\n"s;});

  dynamic_array<int> v(10);
  dynamic_array<int> w = std::move(v);
}
