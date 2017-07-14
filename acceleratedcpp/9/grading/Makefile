OBJS = build/Student_info.o build/grade.o build/fail.o build/utils.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c 
LFLAGS = -Wall $(DEBUG)

computegrades : $(OBJS) build/main_gradeall.o
	$(CC) $(LFLAGS) $(OBJS) build/main_gradeall.o -o bin/computegrades

build/main_gradeall.o : src/main_gradeall.cpp src/grade.h\
	src/Student_info.h src/fail.h
	$(CC) $(CFLAGS) src/main_gradeall.cpp -o build/main_gradeall.o

build/main_compareschemes.o : src/main_compareschemes.cpp src/grade.h\
	src/Student_info.h src/fail.h
	$(CC) $(CFLAGS) src/main_compareschemes.cpp -o build/main_compareschemes.o

build/Student_info.o : src/Student_info.cpp src/Student_info.h src/grade.h
	$(CC) $(CFLAGS) src/Student_info.cpp -o build/Student_info.o

build/fail.o : src/fail.cpp src/fail.h src/grade.h src/utils.h
	$(CC) $(CFLAGS) src/fail.cpp -o build/fail.o

build/utils.o : src/utils.cpp src/utils.h
	$(CC) $(CFLAGS) src/utils.cpp -o build/utils.o

build/grade.o : src/grade.cpp src/grade.h
	$(CC) $(CFLAGS) src/grade.cpp -o build/grade.o

clean :
	\rm *.o computegrades
