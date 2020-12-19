#!/bin/bash

list_recursive ()
{
    local filepath=$1
    local indent=$2

    # インデント付きで、パス部分を除外してファイル名を表示
    echo "${indent}${filepath##*/}"

    if [ -d "$filepath" ]; then
        local filename
        for filename in $(ls "$filepath")
        do
            # インデントにスペースを追加して再帰呼び出し
            list_recursive "${filepath}/${filename}" "  $indent"
        done
    fi
}

list_recursive "$1" ""
