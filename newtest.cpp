#include <iostream>
#include <string>
#include <cstring>
#include <map>

using namespace std;

int main() {

	multimap<string,string,int> users;

	users.insert(pair<string,string,int>("Dax","password",3));




	return 0;
}