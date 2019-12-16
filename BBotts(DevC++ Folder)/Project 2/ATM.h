
//ATM.h
#include<iostream>
#include "Customer.h"
#include "Banker.h"

using namespace std;

// Function prototypes *********************************
double depositFunction(double account, double deposit);

double withdrawlFunction(double account, double withdrawl);

void depositMenu(Customer* cPTR);

void withdrawlMenu(Customer* cPTR);

void atmMenu(int security, Customer* cPTR);
