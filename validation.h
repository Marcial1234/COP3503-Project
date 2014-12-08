#pragma once
/*
  File: validation.h
  Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
  Submitted: December 8, 2014
*/

#include "gendepend.h"

void SpitOutStupidity();
bool ValidateRange(long long int, long long int);
long long int RecursivelyValitate(long long int);
bool ValidateRange(std::string, std::vector<std::string>&);
std::string RecursivelyValitate(std::vector<std::string>&);

void printMainMenu(int);
void printGenericMenu(std::string, std::vector<std::string> &);
