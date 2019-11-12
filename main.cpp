#include <iostream>
#include "Admin.h"
#include "Banker.h"
#include "Customer.h"
using namespace std;

int main(int argc, char** argv) {
	Customer me("bbotts", "bbotts", 9, "Barron", "Botts", "2425 14th Street NW", 400.39, 14295.73, 06, 11, 1996);
	cout << me.print();
	return 0;
}