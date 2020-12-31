# Chapter 1

- デバイスドライバ: デバイスを操作する処理をまとめたプログラム。プロセスからデバイスにアクセスする際に仲介役となる。
- LinuxのようなOSなしだと、各プロセスが各自でデバイスを操作するためのコードを書かなくてはならなくなる。
- CPUには、カーネルモードとユーザモードの2つのモードがある。
- カーネル: カーネルモードで動作するOSの核となる処理をまとめたプログラム。
- システムコール: プロセスがカーネル提供の機能を用いる際に発行される、カーネルへの依頼の仲介となる処理。

# Chapter 2

- いかなるプログラミング言語で記述されたプログラムも、カーネルに処理を依頼する必要がある際は、最終的にはシステムコールを発行する。
- システムコールは高級言語から直接呼び出すことはできない→アーキテクチャ依存のアセンブリコードを用いて呼び出す。
- ラッパー関数: OSによって提供されている、内部的にシステムコールを呼び出すだけの関数群。