#include <iostream>
#include "Employee.h"
#include "Manager.h"
#include "Technician.h"
#include <string>
using namespace std;


int main() {
	Employee* pp = new Technician;
	pp->uplevel(1);
	pp->getPay();
	pp->displaystatus();
	delete pp;
	Employee* pp2 = new Manager;
	pp2->uplevel(1);
	pp2->getPay();
	pp2->displaystatus();
	delete pp2;
	return 0;
}