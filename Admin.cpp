//Admin.cpp

#include "Admin.h"
#include "User.h"
using namespace std;

//constructors
Admin::Admin() {
	setAccountPassword("addAdmin");
	setAccountName("administrator");
	setSecurity(2);
	setID(0);
}

Admin::Admin(string accountName, string accountPassword, int id) {
	setAccountPassword(accountPassword);
	setID(id);
	setAccountName(accountName);
	setSecurity(2);
}

//polymorphic
string Admin::print() const {
	string message = User::print() + "Security Level: " + getSecurityString() + "\n";
	return message;
}