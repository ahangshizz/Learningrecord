#include <iostream>
using namespace std;



class Person {
public:
	Person() {
		cout << "对象构建" << endl;
	}
	~Person() {
		cout << "对象析构" << endl;
	}
};
int divide(int x, int y) {
	//当异常抛出时,函数里面的类对象自动被析构
	Person p1, p2;
	if (y == 0) {
		throw y;
	}
	return x / y;
}

void test01() {
	try {
		divide(10, 0);
	}
	catch (int e){
		cout << "异常捕获" << endl;
	}
}
int main() {
	test01();


	
	cout<<"hello....."<<endl;
	system("pause");
	return 0;
}