gcc -fPIC -shared -I./include/ ./lib/add.c -o ./lib/libadd.so 

gcc main.c -o main -I./include/ -L ./lib/ -ladd 

export LD_LIBRARY_PATH=./lib:$LD_LIBRARY_PATH

./main 3 5

