OBJS = main.o median.o Student_info.o grade.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

computegrades : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o computegrades

main.o : main.cpp grade.h Student_info.h
	$(CC) $(CFLAGS) main.cpp

Student_info.o : Student_info.cpp Student_info.h median.h
	$(CC) $(CFLAGS) Student_info.cpp

median.o : median.cpp median.h
	$(CC) $(CFLAGS) median.cpp

grade.o : grade.cpp grade.h
	$(CC) $(CFLAGS) grade.cpp

clean :
	\rm *.o computegrades
