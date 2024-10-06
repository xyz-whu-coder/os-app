#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int tickNo;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *thread_start(void *arg)
{
    for (; tickNo < 30;)
    {
        // 请添加代码，使用线程互斥锁加锁
        pthread_mutex_lock(&mutex);
        printf("Child Get Tick%d\n", ++tickNo);

        // 请添加代码，解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }
    return 0;
}

int main()
{
    pthread_t tid;
    pthread_create(&tid, NULL, thread_start, NULL);

    for (; tickNo < 30;)
    {
        // 请添加代码，加锁
        pthread_mutex_lock(&mutex);
        printf("Main Get Tick%d\n", ++tickNo);

        // 请添加代码，解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);
    }

    // 请添加代码，销毁互斥锁
    pthread_mutex_destroy(&mutex);
    return 0;
}
