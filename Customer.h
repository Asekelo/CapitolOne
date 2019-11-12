//Customer.h
#include<iostream>
#include"User.h"
using namespace std;
#ifndef CUSTOMER_H
#define CUSTOMER_H

class Customer: public User{
	private:
		string name;
    string address;
	public:
		Student();
		void setName(string);
    void setAddress(string);
		void print();	
	
};
#endif
