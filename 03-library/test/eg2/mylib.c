// 动态库 mylib.c—>mylib.so
#include <stdio.h>
#include <stdlib.h>

// 申明结构体类型
typedef struct __test
{
    int i;
    void (*echo_fun)(struct __test *p);
} Test;

// 申明注册函数原型
void __register(Test *p);
static void __printf(Test *p)
{
    printf("i = %d\n", p->i);
}

// 动态库申请一个全局变量空间。这种 ".成员"的赋值方式为 c99 标准
static Test config = {
    .i = 0,
    .echo_fun = __printf,
};

// 加载动态库的自动初始化函数
// // 所以编译的时候加上的-nostartfiles参数大概就是让这个成为dlopen时自动运行的函数

void _init(void)
{
    printf("init\n");
    __register(&config); // 调用主程序的注册函数
}

void _fini(void)
{
    printf("close library\n");
}