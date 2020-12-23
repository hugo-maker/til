# Pythonプログラムのシステムコール呼び出しの様子を確認するためのサンプル
# $ strace -o hello.py.log python3 ./hello.py
# $ less -N hello.py.log (行数が700行以上になるため、catではなくlessを使用)
print("hello world")
