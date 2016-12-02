#
# Makefile for csci4631-hw3
#
# Author: Ted Mader
# Date: 2016-09-11
#

CC = g++
CFLAGS = -std=c++0x
OFLAGS = -lglu32 -lfreeglut -lopengl32 -Wl,--subsystem,windows
TARGETS = koch.exe

all: $(TARGETS)

koch.exe: point.o main.o
	$(CC) -o koch.exe point.o main.o $(OFLAGS)

point.o: point.cpp
	$(CC) -c point.cpp $(CFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm -rf *.o *.exe
