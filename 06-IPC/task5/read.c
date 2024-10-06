#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define FIFO_NAME "/tmp/my_fifo"

int main(int argc, char *argv[])
{
    int pipe_fd;
    int res;
    char buffer[4096];
    int bytes_read = 0;
    memset(buffer, '\0', sizeof(buffer));
    printf("Process %d opening FIFO O_RDONLY\n", getpid());
    // 请添加代码，使用open函数打开有名（FIFO_NAME）管道进行读取
    pipe_fd = open(FIFO_NAME, O_RDONLY);
    printf("process read:the file's descriptor is %d\n", pipe_fd);
    if (pipe_fd != -1)
    {

        // 请添加代码，使用read函数,从管道读取数据到buffer
        bytes_read = read(pipe_fd, buffer, 4096);

        printf("the read data is %s\n", buffer);
        close(pipe_fd);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
    exit(EXIT_SUCCESS);
}
