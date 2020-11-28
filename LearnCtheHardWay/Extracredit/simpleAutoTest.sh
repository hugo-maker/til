#!/bin/bash

set -eu
FILENAME=${1:-"./extra_credit17_global"}
DBNAME=${2:-"db.dat"}

valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" c 
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" s 1 zed zed@zedshaw.com
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" s 2 frank zed@zedshaw.com
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" s 3 joe zed@zedshaw.com
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" l
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" d 3
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" l
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" g 2
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" f zed
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" f frank
valgrind -q --leak-check=full "${FILENAME}" "${DBNAME}" f joe
