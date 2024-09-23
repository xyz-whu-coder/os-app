gcc -fPIC -shared -I./include/ ./lib/add.c -o ./lib/libadd.so 

gcc -Wl,-rpath=./lib/ main.c -o main -I./include/ -L ./lib/ -ladd 

./main 3 5

