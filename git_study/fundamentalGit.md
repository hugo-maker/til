# udemy:はじめてのGitとGitHub

## Gitはバージョン管理システム
- どのファイルを
- 誰が
- いつ
- なんのために
変更したかを記録する

## GitHubはGitリポジトリのホスティングサービス
- Gitで管理しているファイルとファイルの変更履歴をオンライン上で預かってくれるサービス
- 複数人での開発をサポートしてくれる機能がある

## Gitの一連の作業
1. ファイルの変更をステージングエリアへ追加
1. ローカルリポジトリにコミットする
1. リモートリポジトリにプッシュする

## gitcommand簡易チートシート
- git init ローカルリポジトリの新規作成
- git add [filename] ステージングエリアへの変更追加
- git add . 変更があったすべてのファイルをステージングエリアへ追加
- git commit (-option) 変更をローカルリポジトリに記録
- git status Gitリポジトリの現在の状況を確認
- git log 変更履歴の確認
- git diff ファイルの変更差分の確認
- git remote add origin {url} リモートリポジトリの登録(url部分には、GitHubからコピペしてきたリポジトリのurlを貼り付け)
- git push origin main ローカルリポジトリの内容をリモートリポジトリ(この場合mainリポジトリ)へ送信する
- git branch -m master main ローカルリポジトリのデフォルトネームをmasterからmainに変更
- git remote set-url origin {git@github.com:自分のリポジトリ名} sshで通信するようにする(毎回ユーザ名とパスワードを聞かれなくなる)
