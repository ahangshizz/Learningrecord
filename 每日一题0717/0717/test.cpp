#include <iostream>
using namespace std;

class A {
public:
	A() {
		printf("A");
	}
	~A() {
		printf("deA");
	}
};
class B {
public:
	B() {
		printf("B");
	}
	~B() {
		printf("deB");
	}
};
class C :public A, public B {
public:
	C() {
		printf("C");
	}
	~C() {
		printf("deC");
	}
};

int main() {


	A* a = new C();
	delete a;

	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}