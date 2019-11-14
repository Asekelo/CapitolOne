//ATM.cpp
#include "ATM.h"

ATM::ATM(){
	setDeposit(0);
  setWithdraw(0);
  setBalance(0);
}
void Faculty::setDeposit(double deposit)
{
	this ->deposit = deposit;
}
void Faculty::setWithdraw(double withdraw)
{
	this ->withdraw = withdraw;
}
void Faculty::setBalance(double balance)
{
	this ->balance = balance;
}
void ATM::print(){
	cout <<"This transaction has this information:\n"
		<<"Withdraw amount: "<<withdraw<<"\n"
		<<"Deposit amount: "<<deposit<<"\n"
		<<"Balance amount = "<<balance<<endl;
}
