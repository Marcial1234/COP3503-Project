/*
  File: validation.h
  Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
  Submitted: December 8, 2014
*/

#include "gendepend.h"

#ifndef VALIDATION_H
#define VALIDATION_H

void SpitOutStupidity();
bool ValidateRange(long long int, long long int);
long long int RecursivelyValitate(long long int);
bool ValidateRange(std::string, std::vector<std::string>&);
std::string RecursivelyValitate(std::vector<std::string>&);

void printMainMenu();
void printGenericMenu(std::string, std::vector<std::string> &);

#endif
