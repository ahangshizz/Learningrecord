#include <iostream>
using namespace std;

class A {
public:
	A(int a, int b) {
		this->a = a;
		this->b = b;
	}
	~A() {
		cout << "我是析构函数,我被调用了" << endl;
	}
private:
	int a;
	int b;
};

void mydevide() {
	A a1(10, 20);
	A a2(1, 2);
	throw 1;
}
int main() {

	try
	{
		mydevide();
	}
	catch (int e)
	{
		cout << "发生异常" << endl;
	}
	catch (...)
	{
		cout << "发生未知类型异常" << endl;
	}
	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}