#请添加代码，使用 gcc 编译器编译 main.c 文件；指定输出文件名为 main，链接动态加载库（libdl.so），用于在运行时加载共享库。

gcc -o main main.c -ldl

./main 3 5 ../task4/lib/libadd.so
