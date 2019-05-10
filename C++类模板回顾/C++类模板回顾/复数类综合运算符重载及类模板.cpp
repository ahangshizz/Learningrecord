#include <iostream>
using namespace std;


template <typename T>
class Complex {
	//友元函数,友元函数不能滥用
	friend 	ostream& operator<<(ostream& os, Complex c3) {
		os << c3.a << "+" << c3.b << "i" << endl;
		return os;
	}
public:
	Complex(T a, T b) {
		this->a = a;
		this->b = b;
	}
	void Print() {
		cout << "a:" << a << endl;
		cout << "b:" << b << endl;
	}
	//重载+号运算符
	Complex operator+(Complex& c2) {
		Complex tem(a + c2.a, b + c2.b);
		return tem;
	}
private:
	T a;
	T b;
};
//除了左移<<>>其余的操作符重载都要放在类的内部,友元函数不能滥用
//重载左移运算符
//ostream& operator<<(ostream& os, Complex<int> c3) {
//	os << c3.a << "+"<<c3.b << "i"<<endl; 
//	return os;
//}
int main() {
	Complex<int> c1(1, 2);
	Complex<int> c2(3, 4);
	Complex<int> c3 = c1 + c2;
	cout << c3 << endl;
	system("pause");
	return 0;
}