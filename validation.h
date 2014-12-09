#pragma once
/*
  File: validation.h
  Authors: Marcial Abrahantes, Ernie Chu, David Frick, Dax Gerts
  Submitted: December 8, 2014
*/

#include "gendepend.h"

// This clears the cin buffer
static void ClearCin();

// This print the invalid string and calls ClearCin
static void SpitOutStupidity();

// Returns true as long as max > input && input >= 0
static bool ValidateRange(long long int input, long long int max);

// Returns the input of a number ONLY LOWER than the passed max/upper limit.
static long long int RecursivelyValidate(long long int input);

/*	Menu generator. Generates the following:
	[action description/instructions/placeholder]
		[i]: vector[i]
		...
	Example:
	printGenericMenu("Do you know your name?", { "No", "Yes" });
	=>
	Do you know your name?
		0. No
		1. Yes*/
static void printGenericMenu(std::string placeHolder, std::vector<std::string> &);