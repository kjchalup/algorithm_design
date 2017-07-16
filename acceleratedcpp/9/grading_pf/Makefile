OBJS = build/Student_info.o build/grade.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

computegrades : $(OBJS) build/main_gradeall.o
	$(CC) $(LFLAGS) $(OBJS) build/main_gradeall.o -o bin/computegrades

build/main_gradeall.o : src/main_gradeall.cpp src/grade.h\
	src/Student_info.h
	$(CC) $(CFLAGS) src/main_gradeall.cpp -o build/main_gradeall.o

build/Student_info.o : src/Student_info.cpp src/Student_info.h src/grade.h
	$(CC) $(CFLAGS) src/Student_info.cpp -o build/Student_info.o

build/grade.o : src/grade.cpp src/grade.h
	$(CC) $(CFLAGS) src/grade.cpp -o build/grade.o

clean :
	\rm build/* bin/computegrades
