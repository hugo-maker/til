/*
 * プロセスが発行するシステムコールを確認するためのサンプル
 * $ strace -o hello.log ./hello
 * $ cat -n hello.log
 */
#include <stdio.h>

int main(void)
{
  puts("hello world");
  return 0;
}
