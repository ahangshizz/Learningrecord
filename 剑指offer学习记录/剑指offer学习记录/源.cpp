#include <iostream>
using namespace std;

class A {
public:
	int value;
public:
	A(int n) :value(n) {};
	
	/*程序直接报错
	原因在于当实参传递给实参时需要进行值拷贝,这样就会陷入无休止的复制拷贝
	A(A other) {
		this->value = other.value;
	}
	*/
};



class Student {
private:
	char* name;
public:
	Student(char* str) :name(str) {};
	Student(const Student& s) {};
	Student& operator=(const Student& s) {
		if (this == &s) {
			return *this;
		}
		delete[] name;
		name = new char[strlen(s.name)+1];
		strcpy(name, s.name);
		return *this;
	}
};