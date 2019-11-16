//Audit.h

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
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

void saveLogin(string uName, string pWord, string success) {
	ofstream master, login;
	char key = 'l';
	login.open("loginAttempts.txt", ios::app);
	master.open("history.txt", ios::app);
	string message = tell() + "\tU: " + uName + "\tP: " + pWord + "\tS: " + success + "\n";
	string encrypt = "";
	
	for (int i = 0; i < message.length(); i++) {
		encrypt += message[i] ^ key;
	}
	
	login << encrypt;
	master << encrypt;
	login.close();
	master.close();
}

void history() {
	system("CLS");
	string decrypt = "";
	string line = "";
	ifstream master ("history.txt");
	if (master.is_open()) {
		char key = 'l';
		while (getline(master, line)) {
			for(int i = 0; i < line.length(); i++) {
				decrypt += line[i] ^ key;
			}
			cout << decrypt << endl;
		}
	}
	else {
		cout << "Unable to find history file!" << endl;
	}
	master.close();
	system("PAUSE");
}

void logins() {
	system("CLS");
	string decrypt = "";
	string line = "";
	ifstream login ("loginAttempts.txt");
	if (login.is_open()) {
		char key = 'l';
		while (getline(login, line)) {
			for(int i = 0; i < line.length(); i++) {
				decrypt += line[i] ^ key;
			}
			cout << decrypt << endl;
		}
	}
	else {
		cout << "Unable to find login attempts file!" << endl;
	}
	login.close();
	system("PAUSE");
}

void auditMenu(int security){
	switch (security) {
		case 0:
			system("CLS");
			cout << "You cannot use Audit." << endl;
			system("PAUSE");
			return;
	}
	int choice = 0;
	while (choice != -1) {
		system("CLS");
		cout << "========== Audit =========="
			 << "\n1. View History"
			 << "\n2. View Login Attempts"
			 << "\n-1. EXIT" << endl;
		cin >> choice;
			switch (choice) {
				case 1:
					history();
					break;
				case 2:
					logins();
					break;
				case -1:
					system("CLS");
					cout << "Exiting Audit." << endl;
					system("PAUSE");
					return;
			}
	}
}
