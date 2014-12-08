#HRSys makefile

#Compiler settings
CC = g++
CFLAGS = -g -Wall -std=c++0x -o HRSys.exe

default: HRSys

#state object files to build executable

HRSys: main.cpp 
	$(CC) $(CFLAGS) main.cpp

clean:
	-rm *.exe

