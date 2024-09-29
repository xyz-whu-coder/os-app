// test_hello.c
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <dlfcn.h>

typedef struct {
    const char *module;
    int (*GetValue)(char *pszVal);
    int (*PrintfHello)();
} hello_ST_API;

int main(int argc, char **argv) {
    hello_ST_API *hello;
    int i = 0;
    void *handle;
    char psValue[20] = {0};

    handle = dlopen("./hello.so", RTLD_LAZY);
    if (!handle) {
        printf("%s, %d, NULL == handle\n", __FUNCTION__, __LINE__);
        return -1;
    }
    dlerror();
    hello = dlsym(handle, "Hello");
    if (!hello) {
        printf("%s, %d, NULL == hello\n", __FUNCTION__, __LINE__);
        return -1;
    }
    if (hello && hello->PrintfHello) {
        i = hello->PrintfHello(); // PrintfHello, 24, hello everyone
    }
    printf("%s, %d, i = %d\n", __FUNCTION__, __LINE__, i); // main, 34, i = 0
    if (hello && hello->GetValue) {
        i = hello->GetValue(psValue); // GetValue, 18, pszVal = 123456
    }
    if (hello && hello->module) {
        printf("%s, %d, module == %s\n", __FUNCTION__, __LINE__, hello->module); // main, 39, module == hello
    }
    dlclose(handle);
    return 0;
}

// gcc -o test_hello test_hello.c -ldl
