//User.h

#include <string>
using namespace std;

#ifndef USER_H
#define USER_H

class User {
	private:
		//encapsulated data members
		string accountName, accountPassword;
		int id, security;
	public:
		//constructors
		User();
		User(string, string, int);
		
		//mutators
		void setAccountName(string);
		void setAccountPassword(string);
		void setID(int);
		void setSecurity(int);
		
		//accessors
		string getAccountName() const;
		string getAccountPassword() const;
		int getID() const;
		int getSecurity() const;
		string getIDString() const;
		string getSecurityString() const;
		
		//polymorphic
		virtual string print() const;
};

#endif