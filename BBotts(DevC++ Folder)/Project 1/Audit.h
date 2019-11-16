//Audit.h

#include <string>
#include <iostream>
#include <ctime>
#include <sstream>
#include <fstream>
using namespace std;

#ifndef AUDIT_H
#define AUDIT_H

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

void saveLogout(string uName) {
	ofstream master, logout;
	char key = 'l';
	logout.open("loginAttempts.txt", ios::app);
	master.open("history.txt", ios::app);
	string message = tell() + "\tU: " + uName + "\t<-- Logged Out\n";
	string encrypt = "";
	
	for (int i = 0; i < message.length(); i++) {
		encrypt += message[i] ^ key;
	}
	
	logout << encrypt;
	master << encrypt;
	logout.close();
	master.close();
}

void saveTransaction(string id, string account, string result) {
	ofstream master, trans;
	char key = 'l';
	trans.open("transactions.txt", ios::app);
	master.open("history.txt", ios::app);
	string message = tell() + "\tID: " + id + "\tAccount Type: " + account + "\tResulting Balance: " + result + "\n";
	string encrypt = "";
	
	for (int i = 0; i < message.length(); i++) {
		encrypt += message[i] ^ key;
	}
	
	trans << encrypt;
	master << encrypt;
	trans.close();
	master.close();
}

void history() {
	system("CLS");
	string decrypt = "";
	string line = "";
	ifstream master ("history.txt");
	if (master.is_open()) {
		char key = 'l';
		while (getline(master, line, '\n')) {
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
		while (getline(login, line, '\n')) {
			for(int i = 0; i < line.length(); i++) {
				decrypt += line[i] ^ key;
			}
			cout << decrypt << endl;
		}
	}
	else {
		cout << "Unable to find Logins file!" << endl;
	}
	login.close();
	system("PAUSE");
}

void trans() {
	system("CLS");
	string decrypt = "";
	string line = "";
	ifstream trans ("transactions.txt");
	if (trans.is_open()) {
		char key = 'l';
		while (getline(trans, line, '\n')) {
			for(int i = 0; i < line.length(); i++) {
				decrypt += line[i] ^ key;
			}
			cout << decrypt << endl;
		}
	}
	else {
		cout << "Unable to find transactions file!" << endl;
	}
	trans.close();
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
			 << "\n2. View Logins"
			 << "\n3. View Transactions"
			 << "\n-1. EXIT" << endl;
		cin >> choice;
			switch (choice) {
				case 1:
					history();
					break;
				case 2:
					logins();
					break;
				case 3:
					trans();
					break;
				case -1:
					system("CLS");
					cout << "Exiting Audit." << endl;
					system("PAUSE");
					return;
			}
	}
}

#endif
