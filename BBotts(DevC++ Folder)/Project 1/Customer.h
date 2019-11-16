//Customer.h

#include <iostream>
#include "User.h"
using namespace std;

#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer: public User{
	private:
		string fName, lName, address;
		double checking, saving;
		int birthDay, birthMonth, birthYear;
	
	public:
		//constructors
		Customer();
		Customer(string, string, int, string, string, string, double, double, int, int, int);
		
		//mutators
		void setFullName(string, string);
    	void setAddress(string);
    	void setChecking(double);
    	void setSaving(double);
    	void setBirthDate(int, int, int);
		
		//accessors
		string getFullName() const;
		string getAddress() const;
		double getCheckingBalance() const;
		double getSavingBalance() const;
		string getCheckingString() const;
		string getSavingString() const;
		int getBirthDay() const;
		int getBirthMonth() const;
		int getBirthYear() const;
		string getBirthDate() const;
		string printAccounts() const;
		
		//polymorphic
		string print() const;	
};
#endif
