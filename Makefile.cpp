# HRSys makefile
# Dax Gerts, Marcial Abrahantes, Ernie Chu, David Frick, William Russotto

##set compiler
CC = g++
CFLAGS = -g –Wall

##set first target entry
default: HRSys

##state object files to build executable
HRSys: database.o io.o priv.o crypt.o employee.o hash.o perform.o
$(CC)	$(CFLAGS) –o HRSys.cpp database.cpp io.cpp priv.cpp crypt.cpp employee.cpp hash.cpp perform.cpp

##source files for database.o
database.o: database.cpp database.h HRSys.h 
$(CC)	$(CFLAGS) –c database.cpp

##source files for io.o
io.o: io.cpp io.h HRSys.h
$(CC)	$(CFLAGS) –c io.cpp

##source files for priv.o
priv.o: priv.cpp priv.o HRSys.h
$(CC)	$(CFLAGS) –c priv.cpp

##source files for crypt.o
crypt.o: crypt.cpp crypt.h HRSys.h
$(CC)	$(CFLAGS) –c crypt.cpp

##source files for employee.o
employee.o: employee.cpp employee.h HRSys.h
$(CC)	$(CFLAGS) –c employee.cpp

##source files for hash.o
hash.o: hash.cpp hash.h HRSys.h
$(CC)	$(CFLAGS) –c hash.cpp

##source files for perform.o
perform.o: perform.cpp perform.h HRSys.h
$(CC)	$(CFLAGS) –c perform.cpp

#to remove executable and allow for rebuild, type ‘make remove’
remove:$(RM) HRSys *.o *~
