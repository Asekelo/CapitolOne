//Banker.cpp

#include"Banker.h"

Banker::Banker()
{
	setSecurity(1);
	setAccountName("");
	setAccountPassword("");
	setID(0);
}

Banker::Banker(string accountName, string accountPassword, int id)
{
	setSecurity(1);
	setAccountName(accountName);
	setAccountPassword(accountPassword);
	setID(id);
}

string Banker::print() const 
{
	string message = User::print() + "Security Level: " + getSecurityString() + "\n";
	return message;
}
