#
# Makefile for csci4631-hw3
#
# Author: Ted Mader
# Date: 2016-09-11
#

CC = gcc
TARGETS = main

all: $(TARGETS)

main: main.o
	$(CC) -o main.exe main.o -L"C:\MinGW\freeglut\lib" -lfreeglut -lopengl32 -Wl,--subsystem,windows -lstdc++

main.o: main.cpp
	$(CC) -c main.cpp -I"C:\MinGW\freeglut\include"

clean:
	rm -rf *.o main
