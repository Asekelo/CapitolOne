
//ATM.h
#include<iostream>
using namespace std;
#ifndef ATM_H
#define ATM_H

class ATM: public ATM{
	private:
		double deposit;
    double withdraw;
    double balance;
	public:
		ATM();
		void setDeposit(double);
    void setWithdraw(double);
    void setBalance(double);
		void print();	
	
};
#endif
