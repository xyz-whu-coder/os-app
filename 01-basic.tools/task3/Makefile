CC=gcc

hello: hello.o ./src/myfun.o
	$(CC) -g -Wall -o hello hello.o ./src/myfun.o

hello.o: hello.c ./include/headfile.h
	$(CC) -c hello.c -I ./include/

./src/myfun.o: ./src/myfun.c
	cd src && $(MAKE)

.PHONY: clean

clean:
	rm -rf ./*.o hello
	cd src && $(MAKE) clean

