# 20章複数のソースファイル
**実行環境Ubuntu20.04LTS コンパイラ gcc 9.3.0**

## 最小限の分割

### 複数ファイルを使うわけ

- プログラムの規模が大きくなってくると、どこにどのプログラムがあるのかわからなくなる
- 単一ファイルでは複数人での編集が不可能に近い

### ソースとヘッダーファイル

- ヘッダーファイル: 関数や変数の宣言のみが記述されたファイル。拡張子は.hにするのが慣習
- ソースファイル: プログラムが記述されたファイル。拡張子は.cにするのが慣習

### 最小限のヘッダーファイル

- ヘッダーファイルとソースファイルを作成
- メインで使うファイルに、インクルードする
- インクルード: #include疑似命令でヘッダーファイルを取り込むこと

**注**#include <header.h>と記述したときは，これらのディレクトリからヘッダーファイルを探すが，#include "header.h"と記述したときは カレントディレクトリをまず探し，その後でこれらのディレクトリから探す．

>参考 https://kaworu.jpn.org/c/gcc%E3%82%B3%E3%83%B3%E3%83%91%E3%82%A4%E3%83%A9%E3%81%AE%E4%BD%BF%E3%81%84%E6%96%B9

/usr/local/include にあるヘッダファイルを読み込みたい場合は、以下の通りです。
$ gcc -I /usr/local/include main.c

カレントディレクトリ にあるヘッダファイルを読み込みたい場合は、以下の通りです。
$ gcc -I . main.c

/usr/local/include とカレントディレクトリにあるヘッダファイルを読み込みたい場合は、以下の通りです。
$ gcc -I /usr/local/include -I . main.c


コンパイルに成功した際のコマンド
1. gcc -I . -o main main.c sum.c
1. gcc -I ~/CLang/ -o main main.c sum.c → 実行フィアルはmainになる
1. gcc -I ~/CLang/ main.c sum.c → 実行ファイルはa.outになる

## 分割の定石

### 変数の共有

- 普通にヘッダーファイル内でへんすうを宣言すると、宣言が重複しエラーとなる
- 宣言: コンパイラが変数や関数の名前を記憶する
- 定義: コンパイラが実際に変数や関数を作成する
- 普通の方法だと、宣言と定義が同時に行われる→ 同じ変数や関数が何回も作られると区別できなくなるため、エラーとなる

### extern宣言

- extern宣言: 宣言だけを行い、定義は行わない宣言方法
- 異なるソースファイルで変数を共有できる
- 変数の共有は便利だが、使いすぎるとファイルを分割した意味が薄れるため、注意
- 便利な機能は大体使いすぎ注意

### ヘッダーファイルの重複防止

- #ifndef~#endif疑似命令: ある記号が定義されていなかったときのみ、間に挟まれたプログラムをコンパイル
- extern宣言とコメントを組み合わせ、より良いヘッダーファイルを作成する
- 関数を説明するコメントはヘッダーファイルに記述すべき(ヘッダーファイルはその関数を利用するすべての人が読むが、ソースファイルはそうとも限らないため)