#include <iostream>
#include <vector>
using namespace std;

/*
int main() {
	vector<int> arr;
	int n = 10
		;

	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			arr.push_back(i);
			if (n / i != i)
				arr.push_back(n / i);
		}
	}
	return 0;
}
*/

/*
int Function(unsigned int n) {

	n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
	n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
	n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
	n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
	n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);

	return n;
}

int main() {
	int count = Function(197);
	return 0;
}
*/


class A {
public:
	A() { p(); }
	virtual void p() {
		printf("A");
	}
	virtual ~A() {
		p();
	}
};
class B :public A {
public:
	B() {
		p();
	}
	void p() {
		printf("B");
	}
	~B() {
		p();
	}
};

int main() {
	A* a = new B();
	delete a;
	return 0;
}