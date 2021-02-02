// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++17 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

template <typename T>
struct iota_iterator
{
  // イテレータ同士の距離を表現する型
  using difference_type = std::ptrdiff_t;
  // 要素の型
  using value_type = T;
  using reference = T &;
  using pointer = T *;
  using iterator_category = std::forward_iterator_tag;
  // 値を保持する
  T value;

  // コンストラクタ
  iota_iterator(T value = 0)
    : value(value)
  {}

  // その他のコード
};

int main()
{
  // i(0)
  iota_iterator<int> i;
  // iota_iterator<int>
  iota_iterator first(0), last(10);

  // lastにiをコピー
  i = last;
}
