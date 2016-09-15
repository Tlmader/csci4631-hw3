#
# Makefile for csci4631-hw3
#
# Author: Ted Mader
# Date: 2016-09-11
#

CC = clang
TARGETS = koch.exe

all: $(TARGETS)

koch.exe: point.o main.o
	$(CC) -o koch.exe point.o main.o -lstdc++ -framework OpenGL -framework GLUT

point.o: point.cpp
	$(CC) -c point.cpp

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o koch.exe
