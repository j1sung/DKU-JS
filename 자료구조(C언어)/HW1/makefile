#
# makefile
#
CC=gcc -g
LIBS= -lstdc++

#
# all: hw
#
hw: main.o common.o arithmetic.o matrix.o
	gcc -o hw main.o common.o arithmetic.o matrix.o

#
main.o: main.c
	gcc -c main.c -o main.o

#
common.o: common.c common.h
	gcc -c common.c -o common.o

#
arithmetic.o: arithmetic.c arithmetic.h
	gcc -c arithmetic.c -o arithmetic.o

#
matrix.o: matrix.c matrix.h
	gcc -c matrix.c -o matrix.o

#
clean:
	rm hw.exe *.o
