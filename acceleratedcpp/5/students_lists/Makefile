OBJS = build/main.o build/median.o build/Student_info.o\
	   build/grade.o build/fail.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)

computegrades : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o bin/computegrades

build/main.o : src/main.cpp src/grade.h src/Student_info.h\
	src/fail.h src/itertype.h
	$(CC) $(CFLAGS) src/main.cpp -o build/main.o

build/Student_info.o : src/Student_info.cpp src/Student_info.h src/median.h
	$(CC) $(CFLAGS) src/Student_info.cpp -o build/Student_info.o

build/fail.o : src/fail.cpp src/fail.h src/grade.h src/itertype.h
	$(CC) $(CFLAGS) src/fail.cpp -o build/fail.o

build/median.o : src/median.cpp src/median.h
	$(CC) $(CFLAGS) src/median.cpp -o build/median.o

build/grade.o : src/grade.cpp src/grade.h
	$(CC) $(CFLAGS) src/grade.cpp -o build/grade.o

test : build/median.o src/median.h
	$(CC) $(LFLAGS) build/median.o tests/median.cpp -o tests/test_median
	tests/test_median

clean :
	\rm *.o computegrades
