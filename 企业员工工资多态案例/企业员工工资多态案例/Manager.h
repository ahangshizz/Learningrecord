#pragma once
#include "Employee.h"
class Manager :public Employee {
public:
	virtual void getPay();
	virtual void uplevel(int level);
	Manager();
	~Manager();
private:
	double fixsalary;//经理的固定工资
};

