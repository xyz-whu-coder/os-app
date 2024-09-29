#!/bin/bash

gcc -rdynamic -o foo foo.c -ldl

./foo
