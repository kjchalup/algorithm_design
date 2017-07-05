OBJS = build/main.o build/charpic.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)

pictures : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/pictures

build/main.o : src/main.cpp src/charpic.h
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o

build/charpic.o : src/charpic.cpp src/charpic.h
	$(CC) $(CFLAGS) src/charpic.cpp -o build/charpic.o

clean :
	\rm build/* bin/*
