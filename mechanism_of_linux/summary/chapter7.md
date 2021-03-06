# Chapter 7

ファイルシステム
- ファイルシステムとは: どこにどんなデータがあり、どこが空き領域かを管理するしくみ。
- ディレクトリとは: Linuxのファイルシステムにおいて、カテゴリごとにファイルを格納するための特殊なファイル。
- Linuxでは複数のファイルシステムを扱うことができる。
- ファイルシステムの種類によらず、統一的なインターフェース(システムコールの発行)でアクセスできる。

クォータ
- クォータとは: 用途ごとに使用できるファイルシステムの容量を制限する機能。
- ユーザクォータ: ファイルの所有者となるユーザごとに容量を制限。
- ディレクトリクォータorプロジェクトクォータ: 特定のディレクトリごとに容量を制限。
- サブボリュームクォータ: ファイルシステム内のサブボリュームという単位ごとに容量を制限。

ファイルシステム不整合
- 強制的に電源が落ちるなどして、ファイルシステム不整合が発生すると、ファイルシステムがそれを検出する。
- マウント時に検出した場合は、ファイルシステムをマウントできなくなる。
- アクセス中に検出した場合は、読み出し専用モードで再マウントするか、最悪システムがパニックする。
- 予防に使われる技術には、主にジャーナリングとコピーオンライトなどがある。
- 復旧用コマンドも用意されてはいるものの、あまり有用とは言えないため、定期的にバックアップをとっておくことが最善の対策となる。

ジャーナリング
- ジャーナリングとは: ファイルシステム内にジャーナル領域という特殊な領域を用意し、ジャーナル領域を介して処理を行うことで、不整合を防止する。
- ジャーナル領域とは: ユーザには認識できないメタデータ。
手順
- 更新に必要なアトミックな処理(一連の不可分な処理)の一覧(=ジャーナルログ)を一旦ジャーナル領域に書き出す。
- ジャーナル領域の内容に基づき、実際にファイルシステムの内容を更新する。

ファイルの種類
- キャラクタデバイス: ファイルの読み出し書き出し可、シーク不可。代表例は、端末、キーボード、マウスなど。
- ブロックデバイス: ファイルの読み書き可、ランダムアクセス可。代表例は、HDDやSDDなどのストレージデバイス。
