#HRSys makefile

#Compiler settings
CC = g++
CFLAGS = -g -Wall -std=c++0x

default: HRSys

#state object files to build executable

HRSys: main.cpp database.o priv.o crypt.o employee.o hash.o perf.o validation.o
	$(CC) $(CFLAGS) main.cpp database.o priv.o crypt.o employee.o hash.o perf.o validation.o

#source files for validation.o

validation.o: validation.cpp validation.h database.h priv.h crypt.h hash.h perf.h employee.h validation.h
	$(CC) $(CFLAGS) -c validation.cpp

#source files for database.o

database.o: database.cpp database.h priv.h crypt.h hash.h perf.h employee.h validation.h
	$(CC) $(CFLAGS) database.cpp 

#source files for priv.o

priv.o: priv.cpp priv.o
	$(CC) $(CFLAGS) priv.cpp

#source files for crypt.o

crypt.o: crypt.cpp crypt.h 
	$(CC) $(CFLAGS) crypt.cpp

#source files for employee.o

employee.o: employee.cpp employee.h
	$(CC) $(CFLAGS) employee.cpp

#source files for hash.o

hash.o: hash.cpp hash.h
	$(CC) $(CFLAGS) hash.cpp

#source files for perform.o

perf.o: perf.cpp perform.h
	$(CC) $(CFLAGS) perf.cpp


#to remove executable and allow for rebuild,

remove:$(RM) main *.o *~
