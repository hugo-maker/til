// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T>
class unique_ptr
{
  T * ptr = nullptr;
public:
  unique_ptr(){};
  explicit unique_ptr(T * ptr)
    : ptr(ptr){}
  ~unique_ptr()
  {
    delete ptr;
  }

  // コピーは禁止
  unique_ptr(const unique_ptr &) = delete;
  unique_ptr & operator =(const unique_ptr &) = delete;

  // ムーブ
  unique_ptr(unique_ptr && r)
    : ptr(r.ptr)
  {
    r.ptr = nullptr;
  }
  unique_ptr & operator =(unique_ptr && r)
  {
    delete ptr;
    ptr = r.ptr;
    r.ptr = nullptr;
  }

  T & operator *() noexcept 
  {
    return *ptr;
  }
  T * operator ->() noexcept
  {
    return ptr;
  }
  T * get() noexcept
  {
    return ptr;
  }
};

void old_outdated_ugly_function(int * ptr)
{
}

int main()
{
  auto p = std::make_unique<int>(0);
  *p = 123;
  std::cout << *p << "\n";

  auto v_ptr = std::make_unique<std::vector<int>>();
  v_ptr->push_back(0);

  auto ptr = std::make_unique<int>(0);
  old_outdated_ugly_function(ptr.get());

  auto q = std::move(p);
}
