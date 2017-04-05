CC = gcc
CFLAGS = -Wall -g
INCLUDES = -I/home/kchalupk/gsl/include
LFLAGS = -L/home/kchalupk/gsl/lib
LIBS = -lgsl -lgslcblas -lm
SRCS = ex1_26.c ../utils/utils.c ../utils/mathutils.c
OBJS = $(SRCS:.c=.o)
MAIN = a.out
.PHONY: depend clean

all: 	$(MAIN)
	@echo Compilation finished.

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^

# DO NOT DELETE THIS LINE -- make depend needs it
