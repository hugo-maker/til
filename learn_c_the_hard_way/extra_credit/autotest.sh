#!/bin/bash

set -eu
FILENAME=${1:-"./extra_credit17_global"}
DBNAME=${2:-"db.dat"}

expect -c"
set timeout 5

spawn valgrind --leak-check=full -s \"${FILENAME}\" \"${DBNAME}\" c

expect \"MAX_ROWS: \"
send \"10\n\"

expect \"MAX_DATA: \"
send \"256\n\"

expect eof
"

valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" s 1 8788811 zed zed@zedshaw.com
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" s 2 1234567 frank zed@zedshaw.com
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" s 3 9876543 joe zed@zedshaw.com
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" l
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" d 3
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" l
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" g 2
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f zed
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f frank
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f joe
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f 8788811
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f 1234567
valgrind -q --leak-check=full -s "${FILENAME}" "${DBNAME}" f 9876543
