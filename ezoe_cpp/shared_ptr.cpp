// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T>
class shared_ptr
{
  T * ptr = nullptr;
  std::size_t * count = nullptr;

  void release()
  {
    if (count == nullptr)
    {
      return;
    }

    --*count;
    if (*count == 0)
    {
      delete ptr;
      ptr = nullptr;
      delete count;
      count = nullptr;
    }
  }

public:
  shared_ptr() {}
  explicit shared_ptr(T * ptr)
    : ptr(ptr), count(new std::size_t(1))
  {}
  ~shared_ptr()
  {
    release();
  }

  shared_ptr(const shared_ptr & r)
    : ptr(r.ptr), count(r.count)
  {
    ++*count;
  }
  shared_ptr & operator =(const shared_ptr & r)
  {
    if (this == &r)
    {
      return *this;
    }

    release();
    ptr = r.ptr;
    count = r.count;
    ++*count;
  }

  shared_ptr(shared_ptr && r)
    : ptr(r.ptr), count(r.count)
  {
    r.ptr = nullptr;
    r.count = nullptr;
  }

  shared_ptr & operator =(shared_ptr && r)
  {
    release();
    ptr = r.ptr;
    count = r.count;
    r.ptr = nullptr;
    r.count = nullptr;
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

std::shared_ptr<int> last_ptr;

bool is_equal_to_last_ptr(std::shared_ptr<int> ptr)
{
  if (last_ptr == nullptr)
  {
    last_ptr = ptr;
  }

  bool b = *last_ptr == *ptr;
  last_ptr = ptr;
  return b;
}

int main()
{
  auto p1 = std::make_shared<int>(1);
  auto p2 = std::make_shared<int>(2);

  std::cout << std::boolalpha;

  // true
  bool b1 = is_equal_to_last_ptr(p1);
  std::cout << b1 << std::endl;

  // false
  bool b2 = is_equal_to_last_ptr(p2);
  std::cout << b2 << std::endl;

  *p2 = 1;
  bool b3 = is_equal_to_last_ptr(p1);
  std::cout << b3 << std::endl;
}
