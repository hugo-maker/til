/*
 * getppid() 親プロセスのプロセスIDを取得するシステムコールの無限ループ
 * $ ./ppidloop &
 * $ sar -P ALL 1 1
 * $ kill <プロセスID>
 */
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  for (;;)
    getppid();
}
