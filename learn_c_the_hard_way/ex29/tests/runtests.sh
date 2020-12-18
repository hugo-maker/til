#!/bin/sh

set -e

echo "Running unit tests:"

./tests/ex29_tests ./build/libex29.so print_a_message "hello there"
./tests/ex29_tests ./build/libex29.so uppercase "hello there"
./tests/ex29_tests ./build/libex29.so lowercase "HELLO tHeRe"
! ./tests/ex29_tests ./build/libex29.so fail_on_purpose "i fail"
! ./tests/ex29_tests ./build/libex29.so fail_on_purpose
! ./tests/ex29_tests ./build/libex29.so adfasfasdf asdfadff
! ./tests/ex29_tests ./build/libex.so adfasfasdf asdfadff

echo "All tests passed"
