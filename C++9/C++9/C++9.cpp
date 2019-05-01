#include <iostream>
using namespace std;
#if 0
//多态案例编写
class Shape{
public:
	virtual void show() = 0;
	virtual double getarea() = 0;
	virtual ~Shape() {
		cout << "析构了抽象类" << endl;
		//do nothing
	}
};
class Square :public Shape{
public:
	Square(double a) {
		this->a = a;
	}
	virtual void show() {
		cout << "这是一个正方形" << endl;
	}
	virtual double getarea() {
		return this->a*this->a;
	}
	virtual ~Square() {
		cout << "析构正方形" << endl;
	}
private:
	double a;
};
class Circle :public Shape{
public:
	Circle(double r) {
		this->r = r;
	}
	virtual void show() {
		cout << "这是一个圆形" << endl;
	}
	virtual double getarea() {
		return this->r*this->r*3.14;
	}
	virtual ~Circle() {
		cout << "析构了园型" << endl;
	}
private:
	double r;
};
int main() {
	Shape* array[2] = { 0 };
	for (int i = 0; i < 2; ++i) {
		if (i == 0) {
			double r;
			cout << "请输入园的半径:";
			cin >> r;
			array[i] = new Circle(r);
		}
		else {
			double a;
			cout << "请输入正方形的半径:";
			cin >> a;
			array[1] = new Square(a);
		}
	}
	for (int i = 0; i < 2; ++i) {
		array[i]->show();
		cout<<array[i]->getarea()<<endl;
		delete array[i];
	}
	return 0;
}
#endif
#if 0
//函数指针

int func(int a, int b) {
	cout << "func" << endl;
	return 0;
}
//方法一
typedef int(FUNC)(int,int);
//方法二
typedef int(*FUNC_p)(int, int);
int main() {
	//方法一
	FUNC* fp = NULL;//方法一通过类型名定义指针
	fp = func;
	(*fp)(10, 20);
	//方法二
	FUNC_p fp2 = NULL;
	fp2 = func;
	fp2(100,200);
	//方法三//最常用写法,直接定义指针
	int(*fp3)(int , int ) = NULL;
	fp3 = func;
	fp3(100, 200);
	return 0;
}
#endif
#if 0
//用函数指针实现一个函数接口
int func1(int a, int b) {
	cout<<"1999 写的业务"<<endl;
	return 0;
}
int func2(int a, int b) {
	cout << "1999 写的业务" << endl;
	return 0;
}
int func3(int a, int b) {
	cout << "1999 写的业务" << endl;
	return 0;
}
int func4(int a, int b) {
	cout << "2019 写的业务" << endl;
	return 0;
}
//把这种名字不同,参数相同的函数写成一个接口,类似于多态,在下面可以直接调用
void function(int(*fp)(int, int), int a, int b) {
	cout << "固定业务1" << endl;
	cout << "固定业务2" << endl;
	fp(a,b);
	cout << "固定业务4" << endl;
}
int main() {
	function(func1, 10, 20);
	function(func2, 100, 200);
	function(func3, 1000, 2000);
	function(func4, 10000, 20000);
	return 0;
}
#endif

