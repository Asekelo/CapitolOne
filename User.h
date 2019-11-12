//User.h
#include<iostream>
#include<string>
using namespace std;
#ifndef USER_H
#define USER_H
class Person
{
	protected:
		int ID;
		string accountName;
    string accountPassword;
		
	public:
		User();
		void setaccountName(string);
    void setaccountPassword(string);
		void setID(int);
		virtual void print() ;
};

#endif
