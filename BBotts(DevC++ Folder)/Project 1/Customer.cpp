//Customer.cpp

#include "Customer.h"
#include <sstream>
using namespace std;

//constructors
Customer::Customer() 
{
	setAccountName("user");
	setAccountPassword("password");
	setID(0);
	setFullName("No", "Name");
	setAddress("0000 No Address");
	setChecking(0.00);
	setSaving(0.00);
	setSecurity(0);
	setBirthDate(0, 0 , 0000);
}

Customer::Customer(string accountName, string accountPassword, int id, string fName, string lName, string address, double checking, double saving, int birthDay, int birthMonth, int birthYear)
{
	setAccountName(accountName);
	setAccountPassword(accountPassword);
	setID(id);
	setFullName(fName, lName);
	setAddress(address);
	setChecking(checking);
	setSaving(saving);
	setSecurity(0);
	setBirthDate(birthDay, birthMonth, birthYear);
}

//mutators
void Customer::setAddress(string address)
{
	this -> address = address;
}

void Customer::setFullName(string fName, string lName)
{
	this -> fName = fName;
	this -> lName = lName;
}

void Customer::setChecking(double checking) {
	this -> checking = checking;
}

void Customer::setSaving(double saving) {
	this -> saving = saving;
}

void Customer::setBirthDate(int birthDay, int birthMonth, int birthYear)
{
	this -> birthDay = birthDay;
	this -> birthMonth = birthMonth;
	this -> birthYear = birthYear;
}

//accessors
string Customer::getFullName() const 
{
	string message = fName + " " + lName;
	return message;
}

string Customer::getAddress() const 
{
	return address;
}

double Customer::getCheckingBalance() const
{
	return checking;
}

double Customer::getSavingBalance() const
{
	return saving;
}

string Customer::getCheckingString() const
{
	stringstream check;
	check << checking;
	return check.str();
}

string Customer::getSavingString() const 
{
	stringstream save;
	save << saving;
	return save.str();
}

int Customer::getBirthDay() const
{
	return birthDay;
}

int Customer::getBirthMonth() const
{
	return birthMonth;
}

int Customer::getBirthYear() const
{
	return birthYear;
}

string Customer::getBirthDate() const
{
	stringstream day, month, year;
	day << birthDay;
	month << birthMonth;
	year << birthYear;
	string dob = month.str() + "/" + day.str() + "/" + year.str();
	return dob;
}

//polymorphic
string Customer::print() const
{
	string message = User::print() + "Name: " + getFullName() + "\nAddress: " + address + "\nChecking Account Balance: " + getCheckingString() + "\nSaving Account Balance: " + getSavingString() + "\nDOB: " + getBirthDate();
	return message;
}
