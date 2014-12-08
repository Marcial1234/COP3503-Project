/*
  File: validation.h
  Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
  Submitted: December 8, 2014
*/

#include "database.h"
#include "employee.h"
#include "priv.h"
#include "hash.h"
#include "crypt.h"
#include "perf.h"
#include "gendepend.h"

using namespace std;

#pragma once

void SpitOutStupidity();
bool ValidateRange(long long int, long long int);
long long int RecursivelyValitate(long long int);
bool ValidateRange(string, vector<string>&);
string RecursivelyValitate(vector<string>&);

void printMainMenu();
void printGenericMenu(vector<string>&, string);