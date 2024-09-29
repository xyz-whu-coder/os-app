#!/bin/bash

gcc -shared -o hello.so hello.c

gcc -o test_hello test_hello.c -ldl

./test_hello
