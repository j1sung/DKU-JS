#
# makefile
#
CC=gcc -g
LIBS= -L C:/sd/MinGW/lib/gcc-lib/mingw32/3.2.3/ -lstdc++

all: gobhagi

gobhagi: multiply_array.o common.o
	$(CC) -o gobhagi multiply_array.o common.o

common.o: common.c common.h
	$(CC) -c common.c -o common.o  $(LIB)

multiply_array.o: multiply_array.c
	$(CC) -c multiply_array.c -o multiply_array.o $(LIB)

clean:
	del -f gobhagi.exe
	del -f *.o
