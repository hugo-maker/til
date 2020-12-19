#!/bin/bash

# 日記データの保存用ディレクトリ
directory="${HOME}/diary"

# データ保存用ディレクトリが存在しない場合は作成
if [ ! -d "$directory" ]; then
    mkdir "$directory"
fi

# 日記ファイルパスの組み立て
diaryfile="${directory}/$(date '+%Y-%m-%d').txt"

# 日記ファイルが存在しない場合は(今日初めて書くなら)、先頭に日付を挿入
if [ ! -e "$diaryfile" ]; then
    date '+%Y/%m/%d' > "$diaryfile"
fi

vim "$diaryfile"
