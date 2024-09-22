CC=gcc


main: main.o hello.o
	$(CC) -g -Wall -o main main.o hello.o

main.o: main.c
	$(CC) -c main.c
	
hello.o: hello.c
	$(CC) -c hello.c

.PHONY: clean

clean:
	rm -rf *.o main


