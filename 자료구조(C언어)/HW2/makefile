#
# makefile
#
CC=gcc -g
LIBS= -lstdc++

#
# all: hw
#
hw: main.o common.o sort.o
	gcc -o hw main.o common.o sort.o

#
main.o: main.c
	gcc -c main.c -o main.o

#
common.o: common.c common.h
	gcc -c common.c -o common.o

#
sort.o: sort.c sort.h
	gcc -c sort.c -o sort.o

#
clean:
	rm hw.exe *.o