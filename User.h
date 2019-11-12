//User.h

#include<string>
using namespace std;

#ifndef USER_H
#define USER_H

class User
{
	protected:
		int id, security;
		string accountName, accountPassword;
		
	public:
		//constructors
		User();
		User(string, string, int);
	
		//mutators
		void setaccountName(string);
    		void setaccountPassword(string);
		void setID(int);
	
		//accessors
		string getUserName();
		string getPassWord();
		int getid();
		int getSecurity();
	
		//polymorphic
		virtual string print();
};

#endif
