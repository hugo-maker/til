# 16章 異なる型の変数をまとめる:構造体

## まとめてデータを扱いたい場合

- 構造体: 複数の異なる型をまとめて作られた型のこと 
- 構造体の型宣言: struct 構造体タグ名
- 構造体の型の変数宣言: struct 構造体タグ名 構造体の型の変数(=構造体変数)
- 例: struct student data;
- 構造体タグは関数よりも先に宣言する(それ以降のすべての関数で使えるようになるため,global変数と同じ考え方かな?)

## 構造体の使い方

- 構造体変数名.要素名: 構造体の持つ一つの要素にアクセスする
- 構造体変数自体を変数として扱える(全要素を一括して代入したりできて便利)
- 構造体の簡潔な宣言 typedef 新しい型の形 新しい型名 この方法で宣言された型を**構造体型**と呼ぶ
- 最も簡潔な構造体型の宣言: typedef struct {} 新しい型名;

## 構造体の引数

- 構造体型の引数を使い、一度に複数の情報を渡すことができる
- 構造体の中に配列が含まれる場合、配列の中身もコピーされて渡される→ 中身を変更しても、呼び出し元の変数には影響なし

## 構造体とポインタ

### 構造体型のポインタ変数の作成

- 宣言の方法などは同じ
- * で通常変数モードに切り替えられる(ただし、.のほうが優先されるため、()をつけて、(\*構造体ポインタ変数名).要素名 と書く)
- 構造体ポインタ変数名->要素名 でもOK

### 構造体型へのポインタ引数を持つ関数の作成

普通に渡すことのできる構造体をポインタ変数として渡す理由
- 関数内で値を変更できるようにするため
- 関数呼び出しの高速化のため(構造体を普通に渡すと中身がすべてコピーされるため、構造体の中に大きな配列があった場合、時間がかかる)
- 一般的には構造体はポインタ変数を使って受け渡しすることが多い

## 構造体の配列

- 構造体変数の配列の宣言例: student data[10];
- 構造体の配列の要素へのアクセス例: data[1].year = 3; strcpy(data[1].name,"MARIO");