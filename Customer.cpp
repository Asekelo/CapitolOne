//Customer.cpp

#include"Customer.h"

Customer::Customer(){
	setAddress("pick one");
}
	setName("pick one");
}
void Customer::setAddress(string address)
{
	this ->address = address;
}
void Customer::setName(string name)
{
	this ->name = name;
}
void Customer::print(){
	cout <<"This Customer has this information:\n"
		<<"Name: "<<name<<"\n"
		<<"address: "<<address<<"\n"
		<<"ID = "<<ID<<endl;
}
