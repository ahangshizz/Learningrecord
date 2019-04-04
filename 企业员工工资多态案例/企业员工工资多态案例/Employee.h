#pragma once
#include <iostream>
#include <string>
class Employee {
public:
	virtual void getPay() = 0;
	virtual void uplevel(int level) = 0;
	void displaystatus();
	Employee();
	~Employee();
protected:
	char name[1024];
	int id;
	double salary;
	int level;
	static int starnum;
};
