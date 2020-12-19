#!/bin/bash

usage()
{
    # シェルスクリプトのファイル名を取得
    local script_name=$(basename "$0")

    # ヒアドキュメントでヘルプを表示
    cat << END
Usage: $script_name PATTERN [PATH] [NAME_PATTERN]
Find file in current directory recursively, and print lines which match PATTERN.

    PATH find file in PATH directory, instead of current directory
    NAME_PATTERN specify name pattern to find file

Examples:
    $script_name return
    $script_name return ~'*.txt'
END
}

if [ "$#" -eq 0 ]; then
    usage
    exit 1
fi

pattern=$1
start=$2
name=$3

# 第2引数が空ならば、デフォルト値としてカレントディレクトリを設定
if [ -z "$start" ]; then
    start='.'
fi

# 第3引数が空ならば、デフォルト値として'*'を設定
if [ -z "$name" ]; then
    name='*'
fi

# 検索ディレクトリが存在しない場合は、エラーメッセージを表示して終了
if [ ! -d "$start" ]; then
    echo "$0: ${start}: No such directory" 1>&2
    exit 2
fi

# -n マッチした行番号を表示 -H 引数にファイルが1つしか指定されなかった場合でも、マッチした行の前にファイル名を表示
find "$start" -type f -name "$name" | xargs grep -nH "$pattern"
