#include <iostream>
#include "Admin.h"
#include "Banker.h"
#include "Customer.h"
#include "ATM.h"
#include "Audit.h"
using namespace std;

bankerMenu(Banker* bPTR, Customer* cPTR) {
	int choice = 0;
	while (choice != 3) {
		system("CLS");
		cout << "========== Banker: " << bPTR -> getAccountName() << " =========="
			 << "\n1. ATM"
			 << "\n2. Audit"
			 << "\n3. Sign Out" << endl;
		cin >> choice;
		switch (choice) {
			case 1:
				int cAN;
				cout << "Customer Account Number: ";
				cin >> cAN;
				if(cAN == 9)
				atmMenu(bPTR -> getSecurity(), cPTR);
				
				else{
					cout << "No Accounts with that ID Number." << endl;
					system("PAUSE");
					bankerMenu(bPTR, cPTR); //-------------------------------------------Recursion---------------------
				}
				break;
			case 2:
				auditMenu(bPTR -> getSecurity());
				break;
			case 3:
				system("CLS");
				cout << "Signing Out!" << endl;
				system("PAUSE");
				break;
		}
	}
}

int main(int argc, char** argv) {
//========================================================================== C U S T O M E R ==========================
	
	Customer* me = new Customer("a-mei-zhang", "iceIceBaby#C001", 9, "Mei-Ling", "Zhou", "2425 14th Street NW", 400.39, 14295.73, 24, 5, 1985);
	saveLogin(me -> getAccountName(), me -> getAccountPassword(), "yes"); // <-- The letter f makes the save files drop characters
	atmMenu(me -> getSecurity(), me);
	saveLogout(me -> getFullName());
	
//========================================================================== B A N K E R ==============================
	
	Banker* Elias = new Banker("HSchampions", "hardWork&Dedication#42", 42);
	saveLogin(Elias -> getAccountName(), "I'mDbest'", "no");
	saveLogin(Elias -> getAccountName(), "I'mBetterThanIwasYesterday", "no");
	saveLogin(Elias -> getAccountName(), Elias -> getAccountPassword(), "yes");
	bankerMenu(Elias, me);
	saveLogout(Elias -> getAccountName());

//========================================================================== A D M I N ================================

	Admin* admin = new Admin();
	saveLogin(admin -> getAccountName(), admin -> getAccountPassword(), "yes");
	auditMenu(admin -> getSecurity());
	saveLogout(admin -> getAccountName());
	return 0;
}
