// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

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

  // イテレータのペアをとり、その参照する値で要素を初期化するコンストラクタ
  template <typename InputIterator>
  vector(InputIterator first, InputIterator last, const Allocator & = Allocator())
  {
    reserve(std::distance(first, last));
    for (auto i = first; i != last; ++i)
    {
      // error: invalid type argument of unary '*' (have 'int')
      push_back(*i);
    }
  }

  // リスト初期化(std::vector<int> v = {1,2,3}のような書き方)に対応するためのコンストラクタ
  vector(std::initializer_list<value_type> init, const Allocator & alloc = Allocator())
    : vector(std::begin(init), std::end(init), alloc)
  {}

  // コピー
  vector(const vector & r)
    // アロケータのコピー
    : alloc(traits::select_on_container_copy_construction(r.alloc))
  {
    // コピー元の要素数を保持できるだけのストレージを確保
    reverse(r.size());
    // コピー元の要素をコピー構築
    // destはコピー先, [src, last]はコピー元
    for (auto dest = first, src = r.begin(), last = r.end();
        src != last; ++dest, ++src)
    {
      construct(dest, *src);
    }
    last = first + r.size();
  }

  // コピー代入演算子
  vector & operator =(const vector & r)
  {
    // 1. 自分自身への代入なら何もしない
    if (this == &r)
    {
      return *this;
    }

    // 2. 要素数が同じならば
    if (size() == r.size())
    {
      // 要素ごとにコピー代入
      std::copy(r.begin(), r.end(), begin());
    }
    // 3. それ以外の場合で予約数が十分ならば
    else if (capacity() >= r.size())
    {
      // 有効な要素はコピー
      std::copy(r.begin(), r.begin() + r.size(), begin());
      // 残りはコピー構築
      for (auto src_iter = r.begin() + r.size(), src_end = r.end();
          src_iter != src_end; ++src_iter, ++last)
      {
        construct(last, *src_iter);
      }
    }
    // 4. それ以外の場合で予約数が不十分ならば
    else
    {
      // 要素をすべて破棄
      destory_all();
      // 予約
      reserve(r.size());
      // コピー構築
      for (auto src_iter = r.begin(), src_end = r.end(), dest_iter = begin();
          src_iter != src_end; ++src_iter, ++dest_iter, ++last)
      {
        construct(dest_iter, *src_iter);
      }
    }
    return *this;
  }

  // push_back
  void push_back(const_reference value)
  {
    if (size() + 1 > capacity())
    {
      auto c = size();
      if (c == 0)
      {
        c = 1;
      }
      else
      {
        c *= 2;
      }

      reserve(c);
    }
    construct(last, value);
    ++last;
  }

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
    // このままだとcompile error
    std::experimental::scope_exit e( [&]{traits::deallocate(alloc, old_first, old_capacity);});

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

  // shrink_to_fit vectorが予約しているメモリのサイズを実サイズに近づける
  // reserveの実装と似ている
  void shrink_to_fit()
  {
    if (size() == capacity())
    {
      return;
    }

    // 新しいストレージを確保
    auto ptr = allocate(size());
    // コピー
    auto current_size = size();
    for (auto raw_ptr = ptr, iter = begin(), iter_end = end(); iter != iter_end; ++iter, ++raw_ptr)
    {
      construct(raw_ptr, *iter);
    }
    // 破棄
    clear();
    deallocate();
    // 新しいストレージを使用
    first = ptr;
    last = ptr + current_size;
    reserved_last = last;
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
  std::array<int, 5> a {1,2,3,4,5};
  std::vector<int> b(std::begin(a), std::end(a));

  std::vector<int> c = {1,2,3};

  // vector<int> v(10, 1);
  // v[2] = 99;
  // v.resize(5);
}
