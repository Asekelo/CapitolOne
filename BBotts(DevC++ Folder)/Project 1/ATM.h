
//ATM.h
#include<iostream>
#include "Customer.h"
using namespace std;

double depositFunction(double account, double deposit) {
	double total = account + deposit;
	return total;
}

double withdrawlFunction(double account, double withdrawl) {
	if (withdrawl > account) {
		cout << "Cannot Overdraft!" << endl;
		return account;
	}
	double total = account - withdrawl;
	return total;
}

void depositMenu(Customer* cPTR) {
	int choice = 0;
	double deposit = 0.00;
	
	system("CLS");
	while (choice != 3) {
		cout << "========= Deposit =========="
			 << "\n1. Checking Account" 
			 << "\n2. Savings Account"
			 << "\n3. Sign Out" << endl;
		cin >> choice;
		switch (choice) {
			case 3:
			cout << "Returning to ATM" << endl;
			system("PAUSE");
			return;
		}
		system("CLS");
		cout << "========= Deposit =========="
			 << "\nAmount to deposit: ";
		cin >> deposit;
		if (deposit < 0.00) {
			system("CLS");
			deposit = 0.00;
			cout << "========= Deposit ==========\nDeposit amount cannot be negative!" << endl;
			system("PAUSE");
			depositMenu(cPTR);
		}
		switch (choice) {
			case 1:
				cPTR -> setChecking(depositFunction(cPTR -> getCheckingBalance(), deposit));
				break;
			case 2:
				cPTR -> setSaving(depositFunction(cPTR -> getSavingBalance(), deposit));
				break;
		}
		return;
	}
}

void withdrawlMenu(Customer* cPTR) {
	int choice = 0;
	double withdraw = 0.00;
	
	system("CLS");
	while (choice != 3) {
		cout << "========= Withdrawl =========="
			 << "\n1. Checking Account" 
			 << "\n2. Savings Account"
			 << "\n3. Back to ATM" << endl;
		cin >> choice;
		switch (choice) {
			case 3:
			cout << "Returning to ATM" << endl;
			system("PAUSE");
			return;
		}
		system("CLS");
		cout << "========= Withdrawl =========="
			 << "\nAmount to withdraw: ";
		cin >> withdraw;
		if (withdraw < 0.00) {
			system("CLS");
			withdraw = 0.00;
			cout << "========= Withdrawl ==========\nWithdrawl amount cannot be negative!" << endl;
			system("PAUSE");
			withdrawlMenu(cPTR);
		}
		switch (choice) {
			case 1:
				cPTR -> setChecking(withdrawlFunction(cPTR -> getCheckingBalance(), withdraw));
				break;
			case 2:
				cPTR -> setSaving(withdrawlFunction(cPTR -> getSavingBalance(), withdraw));
				break;
		}
		return;
	}
}

void atmMenu(int security, Customer* cPTR) {
	switch(security) {
		case 2:
			system("CLS");
			cout << "Admin cannot use ATM." << endl;
			system("PAUSE");
			return;
	}
	int choice = 0;
	while (choice != 4) {
		system("CLS");
		cout << "========== ATM ==========="
			 << "\n1. Deposit"
			 << "\n2. Withdrawl"
			 << "\n3. View Balances"
			 << "\n4. Exit" << endl;
		cin >> choice;
		system("CLS");
		switch (choice) {
			case 1:
				depositMenu(cPTR);
				break;
			case 2:
				withdrawlMenu(cPTR);
				break;
			case 3:
				cout << cPTR -> printAccounts();
				system("PAUSE");
				break;
			case 4:
				cout << "Signing Out." << endl;
				system("PAUSE");
				break;
			default:
				break;
		}
	}
}
