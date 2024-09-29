// test.c
#include <stdlib.h>
#include <dlfcn.h>
#include <stdio.h>

typedef struct __test
{
    int i;
    void (*echo_fun)(struct __test *p);
} Test;

void __register(Test *p)
{
    p->i = 1;
    p->echo_fun(p);
}

int main(void)
{
    void *handle = NULL;
    char *myso = "./mylib.so";

    if ((handle = dlopen(myso, RTLD_NOW)) == NULL)
    {
        printf("dlopen - %sn", dlerror());
        exit(-1);
    }
    // dlclose(handle);
    return 0;
}