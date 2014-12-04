#include <iostream>
#include <cstring>
#include <string>

#include "HRSys_h"

using namespace std;

int main() {
	Database database = new Database();
	database.pullFiles();


	Priv priv = new Priv();
	priv.login();
	int tempauth = priv.getAuth();

	while(bool stop == false) {
		if(tempauth >= 3) {
			menu.getMenuOptions(3);
		}
		if(tempauth >= 2) {
			menu.getMenuOptions(2);
		}
		if(tempauth >= 1) {
			menu.getMenuOptions(1);
		}
	}	

	newdatabase.pushFiles();
	return 0;
}