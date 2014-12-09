#pragma once
/*
  File: validation.h
  Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
  Submitted: December 8, 2014
*/

#include "gendepend.h"

void SpitOutStupidity();
bool ValidateRange(long long int, long long int);
long long int RecursivelyValidate(long long int);
bool ValidateRange(std::string, std::vector<std::string>&);
std::string RecursivelyValidate(std::vector<std::string>&);

void printMainMenu(int);
void printGenericMenu(std::string, std::vector<std::string> &);
