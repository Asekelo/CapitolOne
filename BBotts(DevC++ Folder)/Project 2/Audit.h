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

// Function prototypes *********************************
string tell();

void saveLogin(string uName, string pWord, string success);

void history();

void logins();

void auditMenu(int security);
