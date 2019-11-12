//User.cpp

#include"User.h"
#include<string>
#include<sstream>
using namespace std;

//constructors
User::User(){
	setSecurity(0);
	setAccountName("");
	setAccountPassword("");
	setID(0);
}

User::User(string accountName, string accountPassword, int id) {
	setSecurity(0);
	setAccountName(accountName);
	setAccountPassword(accountPassword);
	setID(id);
}

//mutators
void User::setAccountName(string accountName){
	this -> accountName = accountName;
}

void User::setAccountPassword(string accountPassword){
	this -> accountPassword = accountPassword;
}

void User::setID(int id) {
	this -> id = id;
}

void User::setSecurity(int security) {
	this -> security = security;
}

//accessors
string User::getAccountName() const {
	return accountName;
}

string User::getAccountPassword() const {
	return accountPassword;
}

int User::getID() const {
	return id;
}

int User::getSecurity() const {
	return security;
}

string User::getSecurityString() const {
	stringstream secure;
	secure << security;
	return secure.str();
}

string User::getIDString() const {
	stringstream iD;
	iD << id;
	return iD.str();
}

//polymorphic
string User::print() const{
	string message = "ID: " + getIDString() + "\nUsername: " + getAccountName() + "\nPassword: " + getAccountPassword() + "\n";
	return message;
}