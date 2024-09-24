#include <stdlib.h>
#include <unistd.h>
#include "stdio.h"

int main()
{
    int count = 1;
    int child;

    // 请添加代码，创建一个子进程，返回值给child
    child = fork();
    if (child == 0)
    {
        // 子进程过程
        int i;
        for (i = 0; i < 20; i++)
        {
            // 请添加代码，使子进程睡眠1秒
            sleep(1);
            printf("This is son, his count is: %d. and his pid is: %d\n", i, getpid());
        }
        // 请添加代码，使子进程退出
        exit(0);
    }
    else
    {
        // 请添加代码，使父进程睡眠3秒
        sleep(3);
        printf("This is father, his count is: %d, his pid is: %d\n", count, getpid());
    }
}
