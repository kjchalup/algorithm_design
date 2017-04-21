CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I/home/kchalupk/gsl/include
LFLAGS = -L/home/kchalupk/gsl/lib
LIBS = -lgsl -lgslcblas -lm

all: 	test_searches test_sorts

test_searches:
	$(CC) $(CFLAGS) $(INCLUDES) -o test_searches test_searches.c search.c $(LFLAGS) $(LIBS)

test_sorts:
	$(CC) $(CFLAGS) $(INCLUDES) -o test_sorts test_sorts.c sort.c $(LFLAGS) $(LIBS)
