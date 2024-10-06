#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *thread_start(void *arg)
{
    printf("子线程在运行\n");
    return 0;
}

int main()
{
    pthread_attr_t attr;
    pthread_t thread;

    // 请添加代码，设置新创建的线程为PTHREAD_CREATE_DETACHED，若失败则退出
   
    if (pthread_create(&thread, NULL, thread_start, NULL) == -1 ||
        pthread_attr_init(&attr) == -1 ||
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED) == -1
    )
    {
        fprintf(stderr, "fault!\n");
        return 1;
    }

    if (pthread_join(thread, NULL) == 0)
    {
        fprintf(stderr, "成功返回\n%s\n", strerror(errno));
    }
    else
    {
        fprintf(stderr, "返回失败\n");
        return 2;
    }
    sleep(1);

    return 0;
}
