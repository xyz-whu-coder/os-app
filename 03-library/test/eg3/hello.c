// hello.c
#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

typedef struct {
    const char *module;
    int (*GetValue)(char *pszVal);
    int (*PrintfHello)();
} hello_ST_API;

int GetValue(char *pszVal) {
    int retval = -1;
    if (pszVal) {
        retval = sprintf(pszVal, "%s", "123456");
    }
    printf("%s, %d, pszVal = %s\n", __func__, __LINE__, pszVal);
    return retval;
}

int PrintfHello() {
    int retval = -1;
    printf("%s, %d, hello everyone\n", __FUNCTION__, __LINE__);
    return 0;
}

const hello_ST_API Hello = {
    .module = "hello", 
    .GetValue = GetValue,
    .PrintfHello = PrintfHello,
};

// gcc -shared -o hello.so hello.c
