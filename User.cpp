//User.cpp
#include"User.h"
User::User(){
	setName("");
	setAge(0);
}

void User::setaccountName(string n){
	accountName = n;
}
void User::setaccountPassword(string p){
	accountPassword = p;
}
void Person::setAge(int i){
ID = i;
}

void Person::print(){
	cout <<"This is a User!\n"<<endl;
}
