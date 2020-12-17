# Chapter 8 

- setコマンドとshoptコマンドで指定するオプションは異なる
- シェル変数とは: bash内部で使用される変数。設定することでシェルの機能のカスタマイズが可能。
- 環境変数とは: 外部コマンドからも値を参照できるように設定した変数(LANGなど)。
- ~/.bash\_profileと~/.bashrc: 前者はログイン時に一度だけ読み込まれ、後者はbashを起動する度に読み込まれる。基本的にbashrcに方に設定を書いておけばOK。
- bashrcをいじる際は、設定をおこなうシェル以外にもう一つシェルを開いておくこと(誤った記述によりログインできなくなった際などに復旧が可能)。

# Chapter 9

- ls -l で示される先頭の一文字: ファイルタイプを指す。- = 通常ファイル d = directory l = シンボリックリンク
- ファイルの削除の可否はディレクトリのパーミッションに依存し、ファイル自体のパーミッションは関係がない。

chmodについて
- change file mode bits
- シンボルモードは相対的な指定方法。パーミッションの一部のみ変更したい場合に便利。
- 数値モードは絶対的な指定方法。

- suコマンド: 一時的に別のユーザになるためのコマンド。
- Ubuntuではsudo -i でrootユーザになれる。
- visudoコマンド: /etc/sudoersを編集。Ubuntu20.04LTSではデフォルトでVimでなくnanoが起動した。
→$ sudo update alternatives --set editor /usr/bin/vim.basic で変更。
  $ sudo update alternatives --config editor で確認。
