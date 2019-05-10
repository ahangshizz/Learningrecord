#include <iostream>
using namespace std;

template <typename T>
class A {
public:
	A(T a) {
		this->a = a;
	}
	void Print() {
		cout << "a=" << a << endl;
	}
private:
	T a;
};
//类模板的继承
//从模板类派生普通类
class B :public A<int> {
public:
	B(int a, int b) :A<int>(a) {
		this->b = b;
	}
	void Print() {
		cout << "b:" << b << endl;
	}
public:
	int b;
};
//模板类派生模板类
template <typename T>
class C :public A<T> {
public:
	C(T a, T c) :A<T>(a) {
		this->c = c;
	}
	void PrintC() {
		cout << "c:" << c << endl;
	}
protected:
	T c;
};
//类模板做函数参数必须告诉c++编译器,这个类的类型,不然编译器不知道分配多少内存
void UseA(A<int> &a) {
	cout << "我是使用模板类的函数" << endl;
}
int main() {

	//模板类的调用
	A<int> a1(11), a2(22), a3(33);
	a1.Print();
	a2.Print();
	a3.Print();
	//模板类派生普通类的调用
	B b1(1,2);
	b1.Print();
	UseA(a1);
	//模板类派生模板类的调用
	C<int> c1(10, 20);
	c1.PrintC();
	system("pause");
	return 0;
}