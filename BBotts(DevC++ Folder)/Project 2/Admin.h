//Admin.h

#include <string>
#include "User.h"
using namespace std;

#ifndef ADMIN_H
#define ADMIN_H

class Admin:public User {
	private:
		//encapsulated data members
		
	public:
		//constructors
		Admin();
		Admin(string, string, int); //password, id.
		
		//mutators
		
		//accessors
		
		//polymorphic
		string print()const;
};

#endif
