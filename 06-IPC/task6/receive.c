#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <unistd.h>

struct msg_st
{
    long int msg_type;
    char text[BUFSIZ];
};

int main()
{
    int running = 1;
    int msgid = -1;
    struct msg_st data;
    long int msgtype = 0; // 注意1

    // 请添加代码，使用msgget建立消息队列
    msgid = msgget((key_t)0x1111, IPC_CREAT | 0666);
    if (msgid == -1)
    {
        fprintf(stderr, "msgget failed with error: %d\n", errno);
        exit(EXIT_FAILURE);
    }
    // 请添加代码，使用msgrcv函数从队列接收信息
    while (running)
    {
        if (msgrcv(msgid, (void *)&data, BUFSIZ, msgtype, 0) == -1)
        {
            fprintf(stderr, "msgrcv failed with errno: %d\n", errno);
            exit(EXIT_FAILURE);
        }
        printf("You wrote: %s\n", data.text);
        // 遇到end结束
        if (strncmp(data.text, "end", 3) == 0)
            running = 0;
    }
    // 请添加代码，使用msgctl函数删除消息队列
    if (msgctl(msgid, IPC_RMID, NULL) == -1)
    {
        fprintf(stderr, "msgctl(IPC_RMID) failed\n");
        exit(EXIT_FAILURE);
    }
    exit(EXIT_SUCCESS);
}
