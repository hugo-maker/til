#!/bin/bash

set -eu
FILENAME=${1:-"./extra_credit17_anotherAddress"}
DBNAME=${2:-"db.dat"}

expect -c"
set timeout 3

spawn \"${FILENAME}\" \"${DBNAME}\" c

expect \"MAX_ROWS: \"
send \"10\n\"

expect \"MAX_DATA: \"
send \"256\n\"

expect eof
"

"${FILENAME}" "${DBNAME}" s 1 8788811 zed zed@zedshaw.com
"${FILENAME}" "${DBNAME}" s 2 1234567 frank zed@zedshaw.com
"${FILENAME}" "${DBNAME}" s 3 9876543 joe zed@zedshaw.com
"${FILENAME}" "${DBNAME}" l
"${FILENAME}" "${DBNAME}" d 3
"${FILENAME}" "${DBNAME}" l
"${FILENAME}" "${DBNAME}" g 2
"${FILENAME}" "${DBNAME}" f zed
"${FILENAME}" "${DBNAME}" f frank
"${FILENAME}" "${DBNAME}" f joe
"${FILENAME}" "${DBNAME}" f 8788811
"${FILENAME}" "${DBNAME}" f 1234567
"${FILENAME}" "${DBNAME}" f 9876543
