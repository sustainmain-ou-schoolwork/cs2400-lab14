CFLAGS = -g -Wall -std=c++11
CC = g++

main: my_int.o lab14.o
	$(CC) $(CFLAGS) my_int.o lab14.o -o main

my_int.o: my_int.h my_int.cc
	$(CC) $(CFLAGS) -c my_int.cc

lab14.o: lab14.cc
	$(CC) $(CFLAGS) -c lab14.cc

clean:
	rm -f *.o main