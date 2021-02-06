// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T, typename Allocator = std::allocator<T>>
class vector
{
public:
// ネストされた型名
  using value_type = T;
  using pointer = T *;
  using const_pointer = const pointer;
  using reference = value_type &;
  using const_reference = const value_type &;
  using allocator_type = Allocator;

  // データ型
  using size_type = std::size_t;
  using difference_type = std::ptrdiff_t;

  // イテレータのエイリアス宣言
  using iterator = pointer;
  using const_iterator = const_pointer;
  using reverse_iterator = std::reverse_iterator<iterator>;
  using const_reverse_iterator = std::reverse_iterator<const_iterator>;
  
// コンストラクタ

  // アロケータをとるコンストラクタ
  vector(const allocator_type & alloc) noexcept
    : alloc(alloc)
  {}

  // 他のコンストラクタ
  // アロケータをとるコンストラクタにまずデリゲート(委任)

  // デフォルトコンストラクタ(何もしない)
  vector()
    : vector(allocator_type())
  {}

  // 要素数をとるコンストラクタ
  vector(size_type size, 
      const allocator_type & alloc = allocator_type())
    : vector(alloc)
  {/* 実装 */}

  // 要素数と初期値をとるコンストラクタ
  vector(size_type size, const_reference value, 
      const allocator_type & alloc = allocator_type())
    : vector(alloc)
  {/* 実装 */}

  // デストラクタ(ヘルパー関数を用いて実装)
  ~vector()
  {
    // 1. 要素を末尾から先頭に向かう順番で破壊
    clear();
    // 2. 生のメモリーを解放する
    deallocate();
  }

  // コピー
  vector(const vector & x);
  vector & operator =(const vector & x);

  // push_back
  void push_back(const T & x);

  // 容量確認
  size_type size() const noexcept
  {
    return end() - begin();
  }

  bool empty() const noexcept
  {
    return size() == 0;
  }

  size_type capacity() const noexcept
  {
    return reserved_last - first;
  }

  // reserve
  void reserve(size_type sz)
  {
    // すでに指定された要素以上に予約されているなら何もしない
    if (sz <= capacity())
    {
      return;
    }

    // 動的メモリ確保する
    auto ptr = allocate(sz);

    // 古いストレージの情報を保存
    auto old_first = first;
    auto old_last = last;
    auto old_capacity = capacity();

    // 新しいストレージに差し替え
    first = ptr;
    last = first;
    reserved_last = first + sz;

    // 例外安全のため、関数を抜けるときに古いストレージを破棄する
    // std::scope_exitはc++20規格
    std::scope_exit e( [&]{traits::deallocate(alloc, old_first, old_capacity);});

    // 古いストレージから新しいストレージに要素をコピー構築
    // 実際にはムーブ構築
    for (auto old_iter = old_first; old_iter != old_last; ++old_iter, ++last)
    {
      // ムーブセマンティクスの理解が必須
      construct(last, std::move(*old_iter));
    }

    // 新しいストレージへのコピーが完了したため、古いストレージの値は破棄
    for (auto riter = reverse_iterator(old_last), rend = reverse_iterator(old_first);
        riter != rend; ++riter)
    {
      destroy(&*riter);
    }

    // scope_exitによって自動的にストレージが破棄される
  }

  // resize
  void resize(size_type sz)
  {
    if (sz < size())
    {
      auto diff = size() - sz;
      destory_until(rbegin() + diff);
      last = first + sz;
    }
    else if (sz > size())
    {
      reserve(sz);
      for (; last != reserved_last; ++last)
      {
        construct(last);
      }
    }
  }
  void resize(size_type sz, const_reference value)
  {
    if (sz < size())
    {
      auto diff = size() - sz;
      destory_until(rbegin() + diff);
      last = first + sz;
    }
    else if (sz > size())
    {
      reserve(sz);
      for (; last != reserved_last; ++last)
      {
        construct(last, value);
      }
    }
  }

// 要素アクセス

  // operator []
  reference operator [](size_type i)
  {
    return first[i];
  }
  const_reference operator [](size_type i) const
  {
    return first[i];
  }

  // at (例外を投げるoperator [])
  reference at(size_type i)
  {
    if (i >= size())
    {
      throw std::out_of_range("index is out of range.");
    }
    return first[i];
  }
  const_reference at(size_type i) const
  {
    if (i >= size())
    {
      throw std::out_of_range("index is out of range.");
    }
    return first[i];
  }

  // front/back
  reference front()
  {
    return first;
  }
  const_reference front() const
  {
    return first;
  }
  reference back()
  {
    return last - 1;
  }
  const_reference back() const
  {
    return last - 1;
  }

  // data
  pointer data() noexcept
  {
    return first;
  }
  const_pointer data() const noexcept
  {
    return first;
  }


// イテレータアクセス

  // begin/end
  iterator begin() noexcept
  {
    return first;
  }
  iterator end() noexcept
  {
    return last;
  }
  iterator begin() const noexcept
  {
    return first;
  }
  iterator end() const noexcept
  {
    return last;
  }

  // cbegin/cend
  const_iterator cbegin() const noexcept
  {
    return first;
  }
  const_iterator cend() const noexcept
  {
    return last;
  }

  // rbegin/rend
  reverse_iterator rbegin() noexcept
  {
    return reverse_iterator{last};
  }
  reverse_iterator rend() noexcept
  {
    return reverse_iterator{first};
  }
  reverse_iterator rbegin() const noexcept
  {
    return reverse_iterator{last};
  }
  reverse_iterator rend() const noexcept
  {
    return reverse_iterator{first};
  }
  
  // crbegin/crend
  const_reverse_iterator crbegin() const noexcept
  {
    return const_reverse_iterator{last};
  }
  const_reverse_iterator crend() const noexcept
  {
    return const_reverse_iterator{first};
  }

private:

// データメンバー
  // 先頭要素へのポインタ
  pointer first;
  // 最後の要素の一つ前方のポインタ
  pointer last;
  // 確保したストレージの終端
  pointer reserved_last;
  // アロケータの値
  allocator_type alloc;

// ヘルパー関数

  // allocator_traits のエイリアス宣言
  using traits = std::allocator_traits<allocator_type>;

  /* いらない
  template <typename Allocator>
  void f(Allocator & alloc)
  {
    traits::allocate(alloc, 1);
  }
  */ 

  // allocate/deallocate
  pointer allocate(size_type n)
  {
    return traits::allocate(alloc, n);
  }
  void deallocate()
  {
    traits::deallocate(alloc, first, capacity());
  }

  // construct
  void construct(pointer ptr)
  {
    traits::construct(alloc, ptr);
  }
  void construct(pointer ptr, const_reference value)
  {
    traits::construct(alloc, ptr, value);
  }
  // constructムーブ用
  void construct(pointer ptr, value_type && value)
  {
    traits::construct(alloc, ptr, std::move(value));
  }
  // destroy
  void destroy(pointer ptr)
  {
    traits::destroy(alloc, ptr);
  }
  // destory_until
  void destory_until(reverse_iterator rend)
  {
    for (auto riter = rbegin(); riter != rend; ++riter, --last)
    {
      destroy(&*riter);
    }
  }

  // clear
  void clear() noexcept
  {
    destory_until(rend());
  }
};

int main()
{
  vector<int> v(10, 1);
  v[2] = 99;
  v.resize(5);
}
