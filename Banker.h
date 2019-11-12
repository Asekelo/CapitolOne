
//Banker.h
#include<iostream>
#include"User.h"
using namespace std;
#ifndef BANKER_H
#define BANKER_H

class Banker: public User{
	private:
		double deposit;
    double withdraw;
	public:
		Banker();
		void setWithdraw(double);
    void setDeposit(double;
		void print();	
	
};
#endif
