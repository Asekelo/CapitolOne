#include <iostream>
#include "Admin.h"
#include "Banker.h"
#include "Customer.h"
#include "ATM.h"
#include "Audit.h"
using namespace std;

int main(int argc, char** argv) {
	Customer* me = new Customer("bbotts", "bbotts", 9, "Barron", "Botts", "2425 14th Street NW", 400.39, 14295.73, 06, 11, 1996);
	atmMenu(me -> getSecurity(), me);
	saveLogin(me -> getAccountName(), me -> getAccountPassword(), "true");
	auditMenu(2);
	return 0;
}
