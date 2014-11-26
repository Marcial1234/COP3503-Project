#include <iostream>
#include <cstring>
#include <string>

#include "HRSys_h"

using namespace std;

int main() {
	Priv sec = new Priv();
	sec.login();

	// Things like "users" and other important data need to be written and printed to files everytime this program closes.
	// Ernie: I suspect this will make use of the built-in file class and one or more data structures (vectors, etc.).

	return 0;
}