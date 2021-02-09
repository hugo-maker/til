// コンパイル時に all.h(コンパイル済みヘッダーファイルはall.h.gch) をインクルードする必要あり
// g++ -std=c++20 -Wall --pedantic-error -include all.h <ソースファイル名> -o <実行ファイル名>

// byte表示用の関数
void print(std::byte x)
{
  std::cout << static_cast<unsigned int>(x);
}

int main()
{
  // 上位バイトに1
  // 下位バイトに2
  std::uint16_t value = 0b00000001'00000010;

  // 2バイトの配列
  std::byte rep[2];

  // バイト列をコピー
  std::memcpy(rep, &value, 2);


  // 上位バイト
  print(rep[0]);
  // 下位バイト
  print(rep[1]);

  // 8進数でA
  std::cout << '\101';
  // 16進数でA
  std::cout << '\x41';

  // 生文字列リテラル
  std::string s = R"(
  'は単一引用符
  "は二重引用符
  \nは改行文字
  )";
  std::cout << s;

  // basic_stringのイテレータ
  auto s1 = "hello"s;
  for (auto i = s1.begin(); i != s1.end(); ++i)
  {
    std::cout << *i;
  }

// 部分文字列の検索
  auto text = "quick brown fox jumps over the lazy dog."s;
  auto word = "fox"s;

  auto i = std::search(std::begin(text), std::end(text), std::begin(word), std::end(word));

  if (i != std::end(text))
  {
    std::cout << "fox found!\n"sv;
  }
  else
  {
    std::cout << "no fox...\n"sv;
  }

  // find
  auto fox = text.find("fox"sv);
  std::cout << fox;
  auto dog = text.find("dog"sv);
  std::cout << dog;
  auto index = text.find("abc"sv);
  if (index != std::string::npos)
  {
    std::cout << "found.";
  }
  else
  {
    std::cout << "not found.";
  }

  // rfind
  auto words = "word word word"s;
  auto first = words.find("word"sv);
  std::cout << first;
  auto last = words.rfind("word"sv);
  std::cout << last;

  // starts_with
  auto string = "aa bb cc"s;
  std::cout << std::boolalpha;
  bool b1 = string.starts_with("a"sv);
  bool b2 = string.starts_with("aa"sv);
  bool b3 = string.starts_with("aa "sv);
  std::cout << b1 << b2 << b3 << std::endl;
  bool b4 = string.starts_with("b"sv);
  bool b5 = string.starts_with("aaa"sv);
  std::cout << b4 << b5 << std::endl;

// その他の関数

  std::string s_other;
  s_other.size();
  s_other.resize(10);
  s_other.clear();

  // 文字列の挿入

  auto cat = "cat"s;
  cat.insert(0, "long "sv);
  std::cout << cat << std::endl;

  cat.insert(cat.size(), " is loong."sv);
  std::cout << cat << std::endl;

  cat.insert(cat.find("cat"sv), "fat "sv);
  std::cout << cat << std::endl;

  // 部分文字列の削除
  auto delete_word = "long "sv;
  cat.erase(0, delete_word.size());
  std::cout << cat << std::endl;

  auto delete_words = " is loong"sv;
  cat.erase(cat.find(delete_words), delete_words.size());
  std::cout << cat << std::endl;

  // 文字列を先頭から末尾まで削除 clear()と同義
  cat.erase(0, cat.size());
  bool is_empty = cat.empty();
  if (is_empty)
  {
    std::cout << "cat is empty." << std::endl;
  }

  // 部分文字列の置換
  auto sample = "ugly dog"s;
  auto ugly = "ugly"sv;
  auto old = "old"sv;
  sample.replace(sample.find(ugly), ugly.size(), old);
  std::cout << sample << std::endl;

// basic_string_viewの操作

  // remove_prefix(i)
  std::string_view sample_text = "quick brown fox jumps over the lazy dog.";
  sample_text.remove_prefix("quick "sv.size());
  std::cout << sample_text << std::endl;
  sample_text.remove_prefix("brown "sv.size());
  std::cout << sample_text << std::endl;

  // remove_suffix(i)
  sample_text.remove_suffix(" dog."sv.size());
  std::cout << sample_text << std::endl;
  sample_text.remove_suffix(" lazy"sv.size());
  std::cout << sample_text << std::endl;
}
