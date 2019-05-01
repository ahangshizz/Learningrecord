#include "Employee.h"
#include <iostream>
#include <cstring>
using namespace std;
int Employee::starnum = 1000;
Employee::Employee()
{
	id = starnum;
	cout << "员工构造函数" << endl; 
	level = 1;
	starnum++;
}

void Employee::displaystatus() {
	cout << "员工姓名" << this->name << endl;
	cout << "员工工资" << this->salary << endl;
	cout << "员工编号" << this->id << endl;
	cout << "员工等级" << this->level << endl;
}
Employee::~Employee()
{
	cout << "~Employee" << endl;
}
