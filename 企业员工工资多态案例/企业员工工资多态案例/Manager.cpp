#include "Manager.h"
#include <iostream>
using namespace std;
Manager::Manager()
{
	cout << "经理的构造函数" << endl;
	cout << "请输入经理的姓名" << endl;
	cin >> this->name;
	this->fixsalary = 8000;
}
void Manager::getPay() {
	salary = fixsalary;
}
void Manager::uplevel(int level) {
	if (level == 1) {
		this->fixsalary = 8000;
	}
	else if (level == 2) {
		this->fixsalary = 10000;
	}
}

Manager::~Manager()
{
	cout << "~Manager" << endl;
}
