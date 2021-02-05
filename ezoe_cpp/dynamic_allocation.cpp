// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct Logger
{
  std::string name;
  Logger(std::string name)
    : name(name)
  {
    std::cout << name << " is constructed.\n"s;
  }
  ~Logger()
  {
    std::cout << name << " is destructed.\n"s;
  }
};

template<typename T>
struct smart_ptr
{
  T * ptr;
  // コンストラクタで構築
  smart_ptr()
    : ptr(new T{})
  {}
  // デストラクタで破棄
  ~smart_ptr()
  {
    delete ptr;
  }

  T & operator *() const noexcept
  {
    return *ptr;
  }
};

int main()
{
  // 動的メモリ確保
  void * raw_ptr = ::operator new(sizeof(Logger));
  // 構築
  Logger * logger_ptr = new(raw_ptr) Logger{"Alice"s};
  // デストラクタ呼び出し
  logger_ptr->~Logger();
  // 破棄
  ::operator delete(raw_ptr);

  smart_ptr<int> ptr;
  *ptr = 123;
  std::cout << *ptr << "\n"s;
}
