#
# Makefile for csci4631-hw3
#
# Author: Ted Mader
# Date: 2016-09-11
#

CC = clang
TARGETS = main.exe

all: $(TARGETS)

main.exe: main.o
	$(CC) -o main.exe main.o -lstdc++ -framework OpenGL -framework GLUT

main.o: main.cpp
	$(CC) -c main.cpp

clean:
	rm -rf *.o main.exe
