OBJS = build/grammar.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)

all : generate

generate : $(OBJS) src/grammar.h src/main.cpp
	$(CC) $(LFLAGS) $(OBJS) src/main.cpp -o bin/generate

build/grammar.o : src/grammar.cpp src/grammar.h
	$(CC) $(CFLAGS) src/grammar.cpp -o build/grammar.o

test : test/test_grammar
	
test/test_grammar : src/grammar.h build/grammar.o
	$(CC) $(LFLAGS) build/grammar.o test/test_grammar.cpp -o test/test_grammar
	test/test_grammar

clean :
	\rm build/* bin/* test/*.o
