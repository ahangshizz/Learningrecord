#include "Technician.h"
#include <iostream>
using namespace std;

Technician::Technician()
{
	cout << "请输入员工姓名" << endl;
	cin >> name;
	perhour = 100;
}
void Technician::getPay() {
	cout << "请输入员工工作时间" << endl;
	cin >> workhour;
	salary = this->workhour *perhour ;
}
void Technician::uplevel(int level) {
	if (level == 1) {
		perhour = 100;
	}
	else if (level == 2) {
		perhour = 200;
	}
}

Technician::~Technician()
{
	cout << "调用技术员析构函数" << endl;
}
