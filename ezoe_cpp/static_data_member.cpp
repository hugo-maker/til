// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

struct S
{
  // 非staticメンバー
  void member_function(){}

  // staticメンバー
  static void static_member_function(){}

  // staticデータメンバーの宣言
  static int static_data_member;
};

// staticデータメンバーの定義
int S::static_data_member;

int main()
{
  S s;
  // オブジェクトが必要
  s.member_function();
  // オブジェクトが不要
  S::static_member_function();
  // オブジェクトを付けて呼び出すこともできる
  s.static_member_function();

  S::static_data_member = 123;
}
