# HRSys makefile
# Dax Gerts, Marcial Abrahantes, Ernie Chu, David Frick

##set compiler
CC = g++
CFLAGS = -g –Wall

##set first target entry
all: HRSys

##state object files to build executable
main: database.o io.o priv.o crypt.o employee.o hash.o perform.o
$(CC)	$(CFLAGS) –o main.cpp database.cpp io.cpp priv.cpp crypt.cpp employee.cpp hash.cpp perform.cpp

##source files for database.o
database.o: database.cpp database.h main.h 
$(CC)	$(CFLAGS) –c database.cpp

##source files for io.o
io.o: io.cpp io.h main.h
$(CC)	$(CFLAGS) –c io.cpp

##source files for priv.o
priv.o: priv.cpp priv.o main.h
$(CC)	$(CFLAGS) –c priv.cpp

##source files for crypt.o
crypt.o: crypt.cpp crypt.h main.h
$(CC)	$(CFLAGS) –c crypt.cpp

##source files for employee.o
employee.o: employee.cpp employee.h main.h
$(CC)	$(CFLAGS) –c employee.cpp

##source files for hash.o
hash.o: hash.cpp hash.h main.h
$(CC)	$(CFLAGS) –c hash.cpp

##source files for perform.o
perform.o: perform.cpp perform.h main.h
$(CC)	$(CFLAGS) –c perform.cpp

#to remove executable and allow for rebuild, type ‘make remove’
remove:$(RM) main *.o *~
