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
//类模板做函数参数必须告诉c++编译器,这个类的类型,不然编译器不知道分配多少内存
void UseA(A<int> &a) {
	cout << "我是使用模板类的函数" << endl;
}
int main() {

	A<int> a1(11), a2(22), a3(33);
	a1.Print();
	a2.Print();
	a3.Print();
	system("pause");
	return 0;
}