CC=gcc


main: main.o
	$(CC) -g -Wall -o main main.o

main.o: main.c
	$(CC) -c main.c

.PHONY: clean

clean:
	rm -rf *.o main


