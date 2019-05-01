#pragma once
#include "Employee.h"
class Technician : public Employee {
public:
	virtual void getPay();
	virtual void uplevel(int level);
	Technician();
	~Technician();
private:
	int workhour;
	int perhour;
};

