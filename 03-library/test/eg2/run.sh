#!/bin/bash

# Compile the dynamic library
gcc -shared -fPIC -nostartfiles -o mylib.so mylib.c

# Compile the main program
gcc test.c -ldl -rdynamic -o test

./test