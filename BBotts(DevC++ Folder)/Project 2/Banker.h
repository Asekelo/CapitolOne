//Banker.h

#include<iostream>
#include"User.h"
using namespace std;

#ifndef BANKER_H
#define BANKER_H

class Banker: public User{
	private:
		//encapsulated data members

	public:
		//constructors
		Banker();
		Banker(string, string, int);
		
		//mutators
		
		//accessors
		
		//polymorphic
		string print() const;
};

#endif
