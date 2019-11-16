//Audit.h

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include "Banker.h"
#include "Admin.h"
#include "Customer.h"
using namespace std;

string tell() {
	time_t log;
	tm* clock;
	char message[20];
	
	time(&log);
	clock = localtime(&log);
	
	strftime(message, 20, "%m/%d/%Y %H:%M:%S", clock);
	return message;
}

void auditMenu(int security){
	switch (security) {
		case 0:
			system("CLS");
			cout << "You cannot use Audit." << endl;
			system("PAUSE");
			return;
	}
	cout << tell();
	int choice = 0;
}
