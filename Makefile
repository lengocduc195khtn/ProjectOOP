CC = g++
EXEC_FILE = main
CFLAGS = -Wall -g -c
STD = -std=c++17

all: main.o 
	$(CC) $(STD) main.o -o $(EXEC_FILE)

main.o: main.cpp LIB.h
	$(CC) $(STD) $(CFLAGS) main.cpp

clean:
	rm -f *.o
	rm $(EXEC_FILE)