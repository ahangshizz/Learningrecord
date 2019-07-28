#include <iostream>
using namespace std;

long long Fibonacci(unsigned n) {
	int result[2] = { 0,1 };
	if(n<2) {
		return result[n];
	}
	long long fibone = 1;
	long long fibtwo = 0;
	long long fibn = 0;
	for (unsigned int i = 2; i <= n; ++i) {
		fibn = fibone + fibtwo;
		fibtwo = fibone;
		fibone = fibn;
	}
	return fibn;
}
int main() {
	Fibonacci(9);
	system("pause");
	return 0;
}