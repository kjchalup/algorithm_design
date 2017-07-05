CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all : wc unique

wc : wc.o read.o
	$(CC) $(LFLAGS) read.o wc.o -o wc

wc.o : wc.cpp read.h
	$(CC) $(CFLAGS) wc.cpp

unique : unique.o read.o
	$(CC) $(LFLAGS) read.o unique.o -o unique

unique.o : unique.cpp read.h
	$(CC) $(CFLAGS) unique.cpp

read.o : read.h
	$(CC) $(CFLAGS) read.cpp

clean :
	\rm *.o wc unique
