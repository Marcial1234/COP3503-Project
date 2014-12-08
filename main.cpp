#include "gendepend.h"
#include "database.h"
#include "database.cpp"
#include "validation.h"
#include "validation.cpp"
#include "employee.h"
#include "employee.cpp"
#include "hash.h"
#include "hash.cpp"
#include "perf.h"
#include "perf.cpp"
#include "priv.h"
#include "priv.cpp"
#include "crypt.h"
#include "crypt.cpp"

using namespace std;


int main() {

	Database database = *(new Database());
	
	Priv priv = *(new Priv());
	priv.login();
	
	int tempAuth = stoi(priv.getAuth());

	bool stop = false;

	while (stop == true) {

		if (tempAuth >= 3) {
			//menu.getMenuOptions(3);
		}

		if (tempAuth >= 2) {
			//menu.getMenuOptions(2);
		}

		if (tempAuth >= 1) {
			//menu.getMenuOptions(1);
		}
	}	

	//database.pushUserRecords();
	return 0;
}
